#define NDEBUG
/*
    SPDX-License-Identifier: Apache-2.0
    Copyright 2023 CMMC Authors
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
        http://www.apache.org/licenses/LICENSE-2.0
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <algorithm>
#include <cassert>
#include "../../cmmc/Analysis/CallGraphSCC.hpp"
#include "../../cmmc/Analysis/DominateAnalysis.hpp"
#include "../../cmmc/Analysis/IntegerRangeAnalysis.hpp"
#include "../../cmmc/Analysis/PointerAlignmentAnalysis.hpp"
#include "../../cmmc/CodeGen/CodeGenUtils.hpp"
#include "../../cmmc/CodeGen/ISelInfo.hpp"
#include "../../cmmc/CodeGen/InstInfo.hpp"
#include "../../cmmc/CodeGen/Lowering.hpp"
#include "../../cmmc/CodeGen/MIR.hpp"
#include "../../cmmc/CodeGen/MIRCFGAnalysis.hpp"
#include "../../cmmc/CodeGen/RegisterAllocator.hpp"
#include "../../cmmc/CodeGen/Target.hpp"
#include "../../cmmc/Config.hpp"
#include "../../cmmc/IR/Block.hpp"
#include "../../cmmc/IR/ConstantValue.hpp"
#include "../../cmmc/IR/Function.hpp"
#include "../../cmmc/IR/GlobalValue.hpp"
#include "../../cmmc/IR/GlobalVariable.hpp"
#include "../../cmmc/IR/Instruction.hpp"
#include "../../cmmc/IR/Type.hpp"
#include "../../cmmc/IR/Value.hpp"
#include "../../cmmc/Support/Bits.hpp"
#include "../../cmmc/Support/Diagnostics.hpp"
#include "../../cmmc/Support/Dispatch.hpp"
#include "../../cmmc/Support/Graph.hpp"
#include "../../cmmc/Support/Options.hpp"
#include "../../cmmc/Support/Profiler.hpp"
#include "../../cmmc/Transforms/Hyperparameters.hpp"
#include "../../cmmc/Transforms/Util/PatternMatch.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <memory>
#include <optional>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

CMMC_MIR_NAMESPACE_BEGIN

Flag debugISel;

CMMC_INIT_OPTIONS_BEGIN
debugISel.setName("debug-isel", 'I')
    .setDesc(
        "disable all codegen optimizations to debug "
        "lowering/ISel/RA/SA/Legalization");
CMMC_INIT_OPTIONS_END

static OperandType getOperandType(const Type* type, OperandType ptrType) {
    if (type->isPointer()) {
        return ptrType;
    }
    if (type->isInteger()) {
        switch (type->as<IntegerType>()->getBitwidth()) {
            case 1:
                return OperandType::Bool;
            case 8:
                return OperandType::Int8;
            case 16:
                return OperandType::Int16;
            case 32:
                return OperandType::Int32;
            case 64:
                return OperandType::Int64;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    if (type->isFloatingPoint()) {
        if (type->as<FloatingPointType>()->getFixedSize() == sizeof(float)) {
            return OperandType::Float32;
        }
        reportNotImplemented(CMMC_LOCATION());
    }
    reportUnreachable(CMMC_LOCATION());
}
LoweringContext::LoweringContext(
    MIRModule& module,
    CodeGenContext& codeGenCtx,
    std::unordered_map<Block*, MIRBasicBlock*>& blockMap,
    std::unordered_map<GlobalValue*, MIRGlobal*>& globalMap,
    FloatingPointConstantPool& fpConstantPool,
    std::unordered_map<Value*, MIROperand>& valueMap,
    const PointerAlignmentAnalysisResult& alignment)
    : mModule{module},
      mDataLayout{module.getTarget().getDataLayout()},
      mCodeGenCtx{codeGenCtx},
      mBlockMap{blockMap},
      mGlobalMap{globalMap},
      mFPConstantPool{fpConstantPool},
      mValueMap{valueMap},
      mPointerAlignment{alignment},
      mCurrentBasicBlock{nullptr} {
    const auto ptrSize = module.getTarget().getDataLayout().getPointerSize();
    if (ptrSize == 4)
        mPtrType = OperandType::Int32;
    else if (ptrSize == 8)
        mPtrType = OperandType::Int64;
    else
        reportUnreachable(CMMC_LOCATION());
}
MIRModule& LoweringContext::getModule() const noexcept {
    return mModule;
}
MIRBasicBlock* LoweringContext::mapBlock(Block* block) const {
    return mBlockMap.at(block);
}
MIROperand FloatingPointConstantPool::getFPConstant(
    class LoweringContext& ctx,
    const ConstantFloatingPoint* val) {
    assert(val->getType()->as<FloatingPointType>()->getFixedSize() ==
           sizeof(float));
    const auto fpVal = static_cast<float>(val->getValue());
    uint32_t rep;
    memcpy(&rep, &fpVal, sizeof(float));  // TODO: endianness?
    const auto it = mFloatingPointConstant.find(rep);
    uint32_t offset;
    if (it != mFloatingPointConstant.cend()) {
        offset = it->second;
    } else {
        if (!mFloatingPointConstantPool) {
            auto storage = makeUnique<MIRDataStorage>(
                String::get("__cmmc_fp_constant_pool"),
                MIRDataStorage::Storage{}, true);
            mFloatingPointConstantPool = storage.get();
            auto pool = makeUnique<MIRGlobal>(Linkage::Internal, sizeof(float),
                                              std::move(storage));
            ctx.getModule().globals().push_back(std::move(pool));
        }
        offset = mFloatingPointConstant[rep] =
            mFloatingPointConstantPool->appendWord(rep) * sizeof(float);
    }

    const auto ptrType = ctx.getPtrType();
    const auto base = ctx.newVReg(ptrType);
    ctx.emitInst(
        MIRInst{InstLoadGlobalAddress}.setOperand<0>(base).setOperand<1>(
            MIROperand::asReloc(mFloatingPointConstantPool)));
    const auto addr = ctx.newVReg(ptrType);
    ctx.emitInst(
        MIRInst{InstAdd}.setOperand<0>(addr).setOperand<1>(base).setOperand<2>(
            MIROperand::asImm(offset, ptrType)));
    const auto dst = ctx.newVReg(val->getType());
    ctx.emitInst(
        MIRInst{InstLoad}.setOperand<0>(dst).setOperand<1>(addr).setOperand<2>(
            MIROperand::asImm(val->getType()->getAlignment(ctx.getDataLayout()),
                              OperandType::Special)));
    return dst;
}
MIROperand LoweringContext::mapOperand(Value* operand) {
    const auto iter = mValueMap.find(operand);
    if (iter != mValueMap.cend())
        return iter->second;
    if (operand->isGlobal()) {
        const auto ptr = newVReg(getPtrType());
        emitInst(
            MIRInst{InstLoadGlobalAddress}.setOperand<0>(ptr).setOperand<1>(
                MIROperand::asReloc(
                    mGlobalMap.at(operand->as<GlobalValue>())->reloc.get())));
        return ptr;
    }
    if (!operand->isConstant()) {
        operand->dump(reportError() << "undefined operand "sv, Noop{});
        reportUnreachable(CMMC_LOCATION());
    }
    // constant
    // NOTICE: loaded constant cannot be cached
    const auto operandType = getOperandType(operand->getType(), mPtrType);
    if (operand->getType()->isFloatingPoint()) {
        const auto fpv =
            operand->isUndefined()
                ? make<ConstantFloatingPoint>(operand->getType(), 0.0)
                : operand->as<ConstantFloatingPoint>();

        auto& blockCache = mFPLoadedConstantCache[getCurrentBasicBlock()];
        if (auto it = blockCache.find(fpv); it != blockCache.cend())
            return it->second;

        if (auto fp = mCodeGenCtx.iselInfo.materializeFPConstant(fpv, *this);
            !fp.isUnused())
            return blockCache[fpv] = fp;
        return blockCache[fpv] = mFPConstantPool.getFPConstant(*this, fpv);
    }
    // FIXME: detect undef by caller
    if (operand->isUndefined()) {
        return MIROperand::asImm(0, operandType);
    }
    return MIROperand::asImm(operand->as<ConstantInteger>()->getSignExtended(),
                             operandType);
}
void LoweringContext::setCurrentBasicBlock(MIRBasicBlock* block) noexcept {
    mCurrentBasicBlock = block;
}
MIRGlobal* LoweringContext::mapGlobal(GlobalValue* global) const {
    return mGlobalMap.at(global);
}
static String getBlockLabel(CodeGenContext& ctx) {
    return String::get("label").withID(static_cast<int32_t>(ctx.nextId()));
}
MIRBasicBlock* LoweringContext::addBlockAfter() {
    auto& blocks = mCurrentBasicBlock->getFunction()->blocks();
    auto iter = std::find_if(blocks.cbegin(), blocks.cend(), [&](auto& block) {
        return block.get() == mCurrentBasicBlock;
    });
    assert(iter != blocks.cend());
    const auto ret = blocks.insert(
        std::next(iter),
        makeUnique<MIRBasicBlock>(getBlockLabel(mCodeGenCtx),
                                  mCurrentBasicBlock->getFunction()));
    return ret->get();
}
void LoweringContext::addOperand(Value* value, MIROperand reg) {
    if (mValueMap.count(value))
        reportUnreachable(CMMC_LOCATION());
    mValueMap.emplace(value, reg);
}

static void lowerInst(Instruction* inst,
                      LoweringContext& ctx,
                      const PointerAlignmentAnalysisResult& alignment,
                      const IntegerRangeAnalysisResult& range,
                      const DominateAnalysisResult& dom);

static void lowerToMachineFunction(
    MIRFunction& mfunc,
    Function* func,
    CodeGenContext& codeGenCtx,
    MIRModule& machineModule,
    std::unordered_map<GlobalValue*, MIRGlobal*>& globalMap,
    FloatingPointConstantPool& fpConstantPool,
    AnalysisPassManager& analysis) {

    auto& alignment = analysis.get<PointerAlignmentAnalysis>(*func);
    auto& range = analysis.get<IntegerRangeAnalysis>(*func);
    auto& dom = analysis.get<DominateAnalysis>(*func);

    std::unordered_map<Block*, MIRBasicBlock*> blockMap;
    std::unordered_map<Value*, MIROperand> valueMap;
    std::unordered_map<Value*, MIROperand> storageMap;

    LoweringContext ctx{machineModule,  codeGenCtx, blockMap, globalMap,
                        fpConstantPool, valueMap,   alignment};

    auto& target = machineModule.getTarget();
    auto& dataLayout = target.getDataLayout();

    // map all blocks, and process phi
    for (auto block : dom.blocks()) {
        mfunc.blocks().push_back(makeUnique<MIRBasicBlock>(getBlockLabel(codeGenCtx), &mfunc));
        auto& mblock = mfunc.blocks().back();
        blockMap.emplace(block, mblock.get());
        for (auto& inst : block->instructions()) {
            if (inst.getInstID() == InstructionID::Phi) {
                auto vreg = ctx.newVReg(inst.getType());
                ctx.addOperand(&inst, vreg);
            }
        }
    }

    {
        auto& args = mfunc.args();
        for (auto arg : func->args()) {
            auto vreg = ctx.newVReg(arg->getType());
            ctx.addOperand(arg, vreg);
            args.push_back(vreg);
        }
        ctx.setCurrentBasicBlock(mfunc.blocks().front().get()); // dom tree root
        codeGenCtx.frameInfo.emitPrologue(mfunc, ctx);
    }

    {
        ctx.setCurrentBasicBlock(blockMap.at(func->entryBlock())); // entry
        for (auto& inst : func->entryBlock()->instructions()) {
            if (inst.getInstID() == InstructionID::Alloc) {
                // process all allocas
                const auto type = inst.getType()->as<PointerType>()->getPointee();
                const auto storage = mfunc.addStackObject(
                    codeGenCtx,
                    static_cast<uint32_t>(type->getSize(dataLayout)),                   // size
                    static_cast<uint32_t>(inst.as<StackAllocInst>()->getAlignment()),   // alignment
                    0,                                                                  // offset
                    StackObjectUsage::Local);                                           // usage
                storageMap.emplace(&inst, storage);
                const auto addr = ctx.newVReg(ctx.getPtrType());
                ctx.emitInst(MIRInst{InstLoadStackObjectAddr}
                                 .setOperand<0>(addr)
                                 .setOperand<1>(storage));
                ctx.addOperand(&inst, addr);
            } else
                break;
        }
    }

    for (auto block : dom.blocks()) {
        auto mblock = blockMap[block];
        ctx.setCurrentBasicBlock(mblock);
        for (auto& inst : block->instructions()) {
            if (!codeGenCtx.iselInfo.lowerInst(&inst, ctx)) // why?
                lowerInst(&inst, ctx, alignment, range, dom);
        }
    }

    /*
    if constexpr(Config::debug) {
        func->dump(std::cerr, Noop{});
        std::cerr << '\n';
        mfunc.dump(std::cerr, target);
    }
    */
}

// TODO: move to runCodeGenPipeline?
static void lowerToMachineModule(MIRModule& machineModule,
                                 Module& module,
                                 AnalysisPassManager& analysis,
                                 OptimizationLevel optLevel) {
    auto& globals = machineModule.globals();
    const auto& dataLayout = module.getTarget().getDataLayout();

    std::unordered_map<GlobalValue*, MIRGlobal*> globalMap;
    FloatingPointConstantPool fpConstantPool;

    for (auto global : module.globals()) {
        if (global->isFunction()) {
            auto func = global->as<Function>();
            if (func->blocks().empty()) {
                String symbol = func->getSymbol();
                switch (func->getIntrinsic()) {
                    case Intrinsic::memcpy:
                        symbol = String::get("memcpy"sv);
                        break;
                    case Intrinsic::memset:
                        symbol = String::get("memset"sv);
                        break;
                    default:
                        break;
                }
                // SysY runtime alias
                if (symbol.prefix() == "starttime"sv) {
                    symbol = String::get("_sysy_starttime");
                } else if (symbol.prefix() == "stoptime"sv) {
                    symbol = String::get("_sysy_stoptime");
                }
                globals.push_back(makeUnique<MIRGlobal>(
                    func->getLinkage(), dataLayout.getCodeAlignment(),
                    makeUnique<MIRFunction>(symbol)));  // external symbol
            } else {
                globals.push_back(
                    makeUnique<MIRGlobal>(
                        func->getLinkage(), 
                        dataLayout.getCodeAlignment(),
                        makeUnique<MIRFunction>(func->getSymbol())
                        )
                    );
            }
        } else {
            const auto var = global->as<GlobalVariable>();
            const auto type = var->getType()->as<PointerType>()->getPointee();
            const auto alignment = var->getAlignment();
            const auto size = type->getSize(dataLayout);
            if (auto initialValue = var->initialValue()) {
                const auto readOnly = var->attr().hasAttr(GlobalVariableAttribute::ReadOnly);
                MIRDataStorage::Storage data;

                const auto expand = [&](auto&& self, Value* val) -> void {
                    const auto valType = val->getType();
                    if (valType->isArray()) {
                        const auto arrayType = valType->as<ArrayType>();
                        const auto& values = val->as<ConstantArray>()->values();
                        for (auto sub : values) {
                            self(self, sub);
                        }
                        const auto remCount =
                            arrayType->getElementCount() - values.size();
                        if (remCount) {
                            const auto remSize =
                                arrayType->getElementType()->getSize(
                                    dataLayout) *
                                remCount;
                            // zero
                            data.push_back(static_cast<size_t>(remSize));
                        }
                    } else if (valType->isInteger()) {
                        const auto value =
                            val->as<ConstantInteger>()->getZeroExtended();
                        if (valType->getFixedSize() == sizeof(uint32_t)) {
                            data.push_back(static_cast<uint32_t>(value));
                        } else if (valType->getFixedSize() == sizeof(uint8_t)) {
                            data.push_back(static_cast<std::byte>(value));
                        } else if (valType->getFixedSize() ==
                                   sizeof(uint16_t)) {
                            const auto val16 = static_cast<uint16_t>(value);
                            const auto lo = static_cast<std::byte>(val16),
                                       hi = static_cast<std::byte>(val16 >> 8);
                            if (dataLayout.getEndian() == Endian::Little) {
                                data.push_back(lo);
                                data.push_back(hi);
                            } else {
                                data.push_back(hi);
                                data.push_back(lo);
                            }
                        }
                    } else if (valType->isFloatingPoint()) {
                        const auto value =
                            val->as<ConstantFloatingPoint>()->getValue();
                        if (valType->getFixedSize() == sizeof(float)) {
                            const auto fpv = static_cast<float>(value);
                            const void* ptr = &fpv;
                            data.push_back(*static_cast<const uint32_t*>(ptr));
                        } else
                            reportNotImplemented(CMMC_LOCATION());
                    } else
                        reportUnreachable(CMMC_LOCATION());
                };
                expand(expand, initialValue);

                // data/rodata
                globals.emplace_back(makeUnique<MIRGlobal>(
                    global->getLinkage(), alignment,
                    makeUnique<MIRDataStorage>(global->getSymbol(),
                                               std::move(data), readOnly)));
            } else {
                // bss
                globals.emplace_back(makeUnique<MIRGlobal>(
                    global->getLinkage(), alignment,
                    makeUnique<MIRZeroStorage>(global->getSymbol(), size)));
            }
        }
        globalMap.emplace(global, globals.back().get());
    }

    auto& target = module.getTarget();

    {
        Stage stage{"Pre-lowering legalization"sv};
        target.transformModuleBeforeCodeGen(module, analysis);
        analysis.invalidateModule();
        // module.dump(std::cerr);
    }

    CodeGenContext ctx{target,
                       target.getScheduleModel(),
                       target.getDataLayout(),
                       target.getInstInfo(),
                       target.getISelInfo(),
                       target.getFrameInfo(),
                       target.getRegisterInfo(),
                       MIRFlags{}};

    auto dumpFunc = [&](const MIRFunction& func) { func.dump(std::cerr, ctx); };
    CMMC_UNUSED(dumpFunc);

    const auto& cgscc = analysis.get<CallGraphSCCAnalysis>();
    IPRAUsageCache infoIPRA;

    const auto hasCall = [&](MIRFunction& func) {
        for (auto& block : func.blocks())
            for (auto& inst : block->instructions()) {
                auto& info = ctx.instInfo.getInstInfo(inst);
                if (requireFlag(info.getInstFlag(), InstFlagCall))
                    return true;
            }
        return false;
    };

    for (auto func : cgscc.getOrder()) {
        ctx.flags = MIRFlags{};
        // func->dump(std::cerr, Noop{});

        const auto symbol = globalMap.at(func);
        if (func->blocks().empty()) {  // external
            if (ctx.registerInfo)
                target.addExternalFuncIPRAInfo(symbol->reloc.get(), infoIPRA);
            continue;
        }

        auto& mfunc = dynamic_cast<MIRFunction&>(*symbol->reloc);
        {
            // Stage 1: lower to Generic MIR
            Stage stage{"lower to generic insts"sv};
            lowerToMachineFunction(mfunc, func, ctx, machineModule, globalMap,
                                   fpConstantPool, analysis);
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }
        {
            // Stage 2: instruction selection
            Stage stage{"Instruction selection"sv};
            ISelContext iselCtx{ctx};
            iselCtx.runISel(mfunc);
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }
        // Stage 3: register coalescing
        // if (optLevel >= OptimizationLevel::O1 && !debugISel.get()) {
        //     Stage stage{"Register coalescing"sv};
        //     registerCoalescing(mfunc, ctx);
        //     // dumpFunc(mfunc);
        //     assert(mfunc.verify(std::cerr, ctx));
        // }

        // Stage 4: peephole opt
        // if (optLevel >= OptimizationLevel::O1 && !debugISel.get()) {
        //     Stage stage{"Peephole optimization"sv};
        //     // dumpFunc(mfunc);
        //     assert(mfunc.verify(std::cerr, ctx));
        //     while (genericPeepholeOpt(mfunc, ctx))
        //         ;
        //     // dumpFunc(mfunc);
        //     assert(mfunc.verify(std::cerr, ctx));
        // }

        // Pre-RA legalization
        {
            // Stage 6: Pre-RA legalization
            Stage stage{"Pre-RA legalization"sv};
            ctx.flags.inSSAForm = false;
            while (genericPeepholeOpt(mfunc, ctx))
                ;
            preRALegalizeFunc(mfunc, ctx);
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }
        // Stage 6: Pre-RA scheduling, minimize register pressure
        // if (ctx.registerInfo && optLevel >= OptimizationLevel::O2 && !debugISel.get()) {
        //     Stage stage{"Pre-RA scheduling"sv};
        //     preRASchedule(mfunc, ctx);
        //     // dumpFunc(mfunc);
        //     assert(mfunc.verify(std::cerr, ctx));
        // }
        // Stage 7: register allocation
        ctx.flags.preRA = false;
        if (ctx.registerInfo) {
            Stage stage{"Register allocation"sv};
            assignRegisters(mfunc, ctx, infoIPRA);  // vr -> GPR/FPR/Stack
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }
        // Stage 8: legalize stack objects, stack -> sp
        if (ctx.registerInfo) {
            Stage stage{"Stack object allocation"sv};
            allocateStackObjects(mfunc, ctx, hasCall(mfunc), optLevel);
            ctx.flags.postSA = true;
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }
        // Stage 5: ICF & Tail duplication
        if (optLevel >= OptimizationLevel::O2 && !debugISel.get()) {
            Stage stage{"ICF & Tail duplication"sv};
            while (genericPeepholeOpt(mfunc, ctx))
                ;
            // tail duplication as the small block inliner does in CMMC IR
            tailDuplication(mfunc, ctx);
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
            identicalCodeFolding(mfunc, ctx);
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
            while (genericPeepholeOpt(mfunc, ctx))
                ;
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }
        // Stage 9: post-RA scheduling, minimize cycles
        // TODO: after post legalization?
        if (ctx.registerInfo && optLevel >= OptimizationLevel::O3 &&
            !debugISel.get()) {
            Stage stage{"Post-RA scheduling"sv};
            postRASchedule(mfunc, ctx);
            while (genericPeepholeOpt(mfunc, ctx))
                ;
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }
        // Stage 10: code layout opt
        if (optLevel >= OptimizationLevel::O2 && !debugISel.get()) {
            Stage stage{"Code layout optimization"sv};
            simplifyCFGWithUniqueTerminator(mfunc, ctx);
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
            optimizeBlockLayout(mfunc, ctx);
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
            // block freq is unused
        }
        // Stage 12: remove unreachable block/continuous goto/unused
        // label/peephole
        {
            const auto cfg = calcCFG(mfunc, ctx);
            const auto freq = calcFreq(mfunc, cfg);

            for (auto& block : mfunc.blocks())
                block->setTripCount(freq.query(block.get()));
        }
        ctx.flags.endsWithTerminator = false;
        if (optLevel >= OptimizationLevel::O1 && !debugISel.get()) {
            Stage stage{"CFG Simplification"sv};
            simplifyCFG(mfunc, ctx);
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }

        {
            // Stage 13: post legalization
            Stage stage{"Post legalization"sv};
            postLegalizeFunc(mfunc, ctx);
            ctx.flags.postLegal = true;
            while (genericPeepholeOpt(mfunc, ctx))
                ;
            // dumpFunc(mfunc);
            assert(mfunc.verify(std::cerr, ctx));
        }

        // add to IPRA cache
        if (ctx.registerInfo)
            infoIPRA.add(ctx, symbol->reloc.get(), mfunc);

        if (!mfunc.verify(std::cerr, ctx)) {
            DiagnosticsContext::get()
                .attach<Reason>("codegen fatal")
                .reportFatal();
        }
    }
    assert(machineModule.verify(std::cerr, ctx));
}

std::unique_ptr<MIRModule> lowerToMachineModule(Module& module,
                                                AnalysisPassManager& analysis,
                                                OptimizationLevel optLevel) {
    Stage stage{"lower to MIR"sv};

    auto& target = module.getTarget();
    auto machineModule = makeUnique<MIRModule>(target);
    lowerToMachineModule(*machineModule, module, analysis, optLevel);
    // machineModule->dump(std::cerr);
    return machineModule;
}

static void lower(BinaryInst* inst, LoweringContext& ctx) {
    const auto id = [instID = inst->getInstID()] {
        switch (instID) {
            case InstructionID::Add:
                return InstAdd;
            case InstructionID::Sub:
                return InstSub;
            case InstructionID::Mul:
                return InstMul;
            case InstructionID::UDiv:
                return InstUDiv;
            case InstructionID::URem:
                return InstURem;
            case InstructionID::And:
                return InstAnd;
            case InstructionID::Or:
                return InstOr;
            case InstructionID::Xor:
                return InstXor;
            case InstructionID::Shl:
                return InstShl;
            case InstructionID::LShr:
                return InstLShr;
            case InstructionID::AShr:
                return InstAShr;
            case InstructionID::SMin:
                return InstSMin;
            case InstructionID::SMax:
                return InstSMax;
            case InstructionID::FAdd:
                return InstFAdd;
            case InstructionID::FSub:
                return InstFSub;
            case InstructionID::FMul:
                return InstFMul;
            case InstructionID::FDiv:
                return InstFDiv;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }();
    const auto ret = ctx.newVReg(inst->getType());
    ctx.emitInst(MIRInst{id}
                     .setOperand<0>(ret)
                     .setOperand<1>(ctx.mapOperand(inst->getOperand(0)))
                     .setOperand<2>(ctx.mapOperand(inst->getOperand(1))));
    ctx.addOperand(inst, ret);
}
static void lowerSDivRem(BinaryInst* inst,
                         LoweringContext& ctx,
                         const IntegerRangeAnalysisResult& range,
                         const DominateAnalysisResult& dom) {
    const auto id = [instID = inst->getInstID()] {
        switch (instID) {
            case InstructionID::SDiv:
                return InstSDiv;
            case InstructionID::SRem:
                return InstSRem;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }();
    constexpr uint32_t depth = 5;
    const auto rangeLhs = range.query(inst->getOperand(0), dom, inst, depth);
    const auto rangeRhs = range.query(inst->getOperand(1), dom, inst, depth);
    const auto rangeResult = range.query(inst, dom, inst, depth);

    const auto ilog2Floor = [](intmax_t x) {
        if (x <= 1)
            return 0;
        return 63 - __builtin_clzll(static_cast<uint64_t>(x));
    };

    const auto log2Dividend = ilog2Floor(rangeLhs.abs().maxSignedValue());
    const auto log2Divisor = ilog2Floor(rangeLhs.abs().minSignedValue());

    const auto signDividend = rangeLhs.isNonNegative();
    const auto signDivisor = rangeRhs.isNonNegative();
    const auto signRes = rangeResult.isNonNegative();
    const auto signEncode = (signDividend ? 0b100 : 0) |
                            (signDivisor ? 0b010 : 0) | (signRes ? 0b001 : 0);

    const auto ret = ctx.newVReg(inst->getType());
    ctx.emitInst(
        MIRInst{id}
            .setOperand<0>(ret)
            .setOperand<1>(ctx.mapOperand(inst->getOperand(0)))
            .setOperand<2>(ctx.mapOperand(inst->getOperand(1)))
            .setOperand<3>(MIROperand::asImm(log2Dividend, OperandType::Int32))
            .setOperand<4>(MIROperand::asImm(log2Divisor, OperandType::Int32))
            .setOperand<5>(MIROperand::asImm(signEncode, OperandType::Int32)));
    ctx.addOperand(inst, ret);
}
static void lower(CompareInst* inst, LoweringContext& ctx) {
    const auto id = [instID = inst->getInstID()] {
        switch (instID) {
            case InstructionID::FCmp:
                return InstFCmp;
            case InstructionID::ICmp:
                return InstICmp;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }();

    const auto ret = ctx.newVReg(inst->getType());
    ctx.emitInst(MIRInst{id}
                     .setOperand<0>(ret)
                     .setOperand<1>(ctx.mapOperand(inst->getOperand(0)))
                     .setOperand<2>(ctx.mapOperand(inst->getOperand(1)))
                     .setOperand<3>(MIROperand::asImm(inst->getOp(),
                                                      OperandType::Special)));
    ctx.addOperand(inst, ret);
}
static void lower(UnaryInst* inst, LoweringContext& ctx) {
    const auto id = [instID = inst->getInstID()] {
        switch (instID) {
            case InstructionID::Neg:
                return InstNeg;
            case InstructionID::Abs:
                return InstAbs;
            case InstructionID::FNeg:
                return InstFNeg;
            case InstructionID::FAbs:
                return InstFAbs;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }();

    const auto ret = ctx.newVReg(inst->getType());
    ctx.emitInst(MIRInst{id}.setOperand<0>(ret).setOperand<1>(
        ctx.mapOperand(inst->getOperand(0))));
    ctx.addOperand(inst, ret);
}
static void lower(CastInst* inst, LoweringContext& ctx) {
    const auto src = ctx.mapOperand(inst->getOperand(0));
    const auto dst = ctx.newVReg(inst->getType());

    if (inst->getInstID() == InstructionID::UnsignedTrunc) {
        ctx.emitInst(MIRInst{InstAnd}
                         .setOperand<0>(dst)
                         .setOperand<1>(src)
                         .setOperand<2>(getTruncMask(dst.type(), src.type())));
    } else {
        const auto id = [instID = inst->getInstID()] {
            switch (instID) {
                case InstructionID::ZExt:
                    return InstZExt;
                case InstructionID::SExt:
                    return InstSExt;
                case InstructionID::Bitcast:
                    return InstCopy;
                case InstructionID::SignedTrunc:
                    return InstTrunc;
                case InstructionID::F2U:
                    return InstF2U;
                case InstructionID::F2S:
                    return InstF2S;
                case InstructionID::U2F:
                    return InstU2F;
                case InstructionID::S2F:
                    return InstS2F;
                case InstructionID::FCast:
                default:
                    reportUnreachable(CMMC_LOCATION());
            }
        }();
        ctx.emitInst(MIRInst{id}.setOperand<0>(dst).setOperand<1>(src));
    }

    ctx.addOperand(inst, dst);
}
static void lower(LoadInst* inst,
                  LoweringContext& ctx,
                  const PointerAlignmentAnalysisResult& alignment) {
    const auto ret = ctx.newVReg(inst->getType());
    const auto ptr = ctx.mapOperand(inst->getOperand(0));
    const auto align =
        alignment.lookup(inst->getOperand(0), ctx.getDataLayout());
    ctx.emitInst(
        MIRInst{InstLoad}.setOperand<0>(ret).setOperand<1>(ptr).setOperand<2>(
            MIROperand::asImm(align, OperandType::Special)));
    ctx.addOperand(inst, ret);
}
static void lower(StoreInst* inst,
                  LoweringContext& ctx,
                  const PointerAlignmentAnalysisResult& alignment) {
    const auto align =
        alignment.lookup(inst->getOperand(0), ctx.getDataLayout());
    ctx.emitInst(
        MIRInst{InstStore}
            .setOperand<0>(ctx.mapOperand(inst->getOperand(0)))
            .setOperand<1>(ctx.mapOperand(inst->getOperand(1)))
            .setOperand<2>(MIROperand::asImm(align, OperandType::Special)));
}
static void emitBranch(Block* dstBlock, Block* srcBlock, LoweringContext& ctx) {
    std::vector<MIROperand> dst;
    std::vector<MIROperand> src;

    for (auto& inst : dstBlock->instructions()) {
        if (inst.getInstID() == InstructionID::Phi) {
            const auto phi = inst.as<PhiInst>();
            const auto val = phi->incomings().at(srcBlock)->value;
            src.push_back(ctx.mapOperand(val));
            dst.push_back(ctx.mapOperand(phi));
        } else
            break;
    }

    if (!src.empty()) {
        std::unordered_set<MIROperand, MIROperandHasher> needStagingRegister;
        std::unordered_set<MIROperand, MIROperandHasher> dstSet(dst.begin(),
                                                                dst.end());
        for (auto op : src)
            if (dstSet.count(op))
                needStagingRegister.insert(op);

        // setup phi values
        // calcuates the best order and create temporary variables for args

        std::unordered_map<MIROperand, uint32_t, MIROperandHasher> nodeMap;
        for (uint32_t idx = 0; idx < dst.size(); ++idx)
            nodeMap.emplace(dst[idx], idx);

        Graph graph(dst.size());  // direct copy graph
        for (size_t idx = 0; idx < dst.size(); ++idx) {
            const auto arg = src[idx];
            if (auto iter = nodeMap.find(arg); iter != nodeMap.cend()) {
                // copy b to a -> a should be resetted before b
                graph[idx].push_back(iter->second);
            }
        }

        const auto [ccnt, col] = calcSCC(graph);
        std::vector<std::unordered_set<NodeIndex>> dag(ccnt);
        std::vector<std::vector<NodeIndex>> groups(ccnt);
        std::vector<uint32_t> in(ccnt);
        for (uint32_t u = 0; u < graph.size(); ++u) {
            const auto cu = col[u];
            groups[cu].push_back(u);
            for (auto v : graph[u]) {
                const auto cv = col[v];
                if (cu != cv && dag[cu].emplace(cv).second) {
                    ++in[cv];
                }
            }
        }

        std::queue<uint32_t> q;
        for (uint32_t u = 0; u < ccnt; ++u)
            if (in[u] == 0)
                q.push(u);
        std::vector<uint32_t> order;
        order.reserve(graph.size());
        while (!q.empty()) {
            const auto u = q.front();
            q.pop();

            const auto& group = groups[u];
            order.insert(order.end(), group.cbegin(), group.cend());

            for (auto v : dag[u]) {
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }

        assert(order.size() == dst.size());

        std::unordered_map<MIROperand, MIROperand, MIROperandHasher>
            dirtyRegRemapping;

        for (size_t i = 0; i < dst.size(); ++i) {
            const auto idx = order[i];
            MIROperand arg;
            if (auto iter = dirtyRegRemapping.find(src[idx]);
                iter != dirtyRegRemapping.cend()) {
                arg = iter->second;  // use copy
            } else
                arg = src[idx];
            const auto dstArg = dst[idx];

            if (arg == dstArg)
                continue;  // identical copy

            // create copy
            if (needStagingRegister.count(dst[idx])) {
                const auto intermediate = ctx.newVReg(src[idx].type());
                ctx.emitCopy(intermediate, dstArg);  // NOLINT
                dirtyRegRemapping.emplace(dst[idx], intermediate);
            }

            // apply reset
            ctx.emitCopy(dstArg, arg);
        }
    }
    const auto dstMBlock = ctx.mapBlock(dstBlock);
    ctx.emitInst(
        MIRInst{InstJump}.setOperand<0>(MIROperand::asReloc(dstMBlock)));
}
static void lower(BranchInst* inst, LoweringContext& ctx) {
    const auto srcBlock = inst->getBlock();
    const auto emitCondBranch = [&](const MIROperand& lhs,
                                    const MIROperand& rhs, uint32_t instID,
                                    CompareOp op, bool invertBlock) {
        // beqz %cond, else_label
        // then_label:
        // ...
        // else_label:
        // ...
        //

        const auto curBlock = ctx.getCurrentBasicBlock();

        const auto thenPrepareBlock = ctx.addBlockAfter();
        ctx.setCurrentBasicBlock(thenPrepareBlock);
        const auto elsePrepareBlock = ctx.addBlockAfter();
        ctx.setCurrentBasicBlock(curBlock);

        const auto cond = ctx.newVReg(inst->getOperand(0)->getType());
        ctx.emitInst(
            MIRInst{instID}
                .setOperand<0>(cond)
                .setOperand<1>(lhs)
                .setOperand<2>(rhs)
                .setOperand<3>(MIROperand::asImm(op, OperandType::Special)));
        ctx.emitInst(MIRInst{InstBranch}
                         .setOperand<0>(cond)
                         .setOperand<1>(MIROperand::asReloc(elsePrepareBlock))
                         .setOperand<2>(MIROperand::asProb(
                             invertBlock ? inst->getBranchProb()
                                         : 1.0 - inst->getBranchProb())));

        ctx.setCurrentBasicBlock(thenPrepareBlock);
        auto thenTarget = inst->getTrueTarget();
        auto elseTarget = inst->getFalseTarget();
        if (invertBlock)
            std::swap(thenTarget, elseTarget);

        emitBranch(thenTarget, srcBlock, ctx);

        ctx.setCurrentBasicBlock(elsePrepareBlock);
        emitBranch(elseTarget, srcBlock, ctx);
    };

    auto preferFallthroughWithFalseLabel = [&] {
        return inst->getBranchProb() >= 0.5;
    };

    if (inst->getInstID() == InstructionID::Branch) {
        emitBranch(inst->getTrueTarget(), srcBlock, ctx);
    } else if (auto condInst = dynamic_cast<CompareInst*>(inst->getOperand(0))) {
        const auto id = [instID = condInst->getInstID()] {
            switch (instID) {
                case InstructionID::ICmp:
                    return InstICmp;
                case InstructionID::FCmp:
                    return InstFCmp;
                default:
                    reportUnreachable(CMMC_LOCATION());
            }
        }();

        if (!preferFallthroughWithFalseLabel()) {
            emitCondBranch(ctx.mapOperand(condInst->getOperand(0)),
                           ctx.mapOperand(condInst->getOperand(1)), id,
                           getInvertedOp(condInst->getOp()), false);
        } else {
            emitCondBranch(ctx.mapOperand(condInst->getOperand(0)),
                           ctx.mapOperand(condInst->getOperand(1)), id,
                           condInst->getOp(), true);
        }
    } else {
        const auto cond = ctx.mapOperand(inst->getOperand(0));
        if (!preferFallthroughWithFalseLabel()) {
            // beqz %cond, false_label
            emitCondBranch(cond, MIROperand::asImm(0, cond.type()), InstICmp,
                           CompareOp::ICmpEqual, false);
        } else {
            // bnez %cond, true_label
            emitCondBranch(cond, MIROperand::asImm(0, cond.type()), InstICmp,
                           CompareOp::ICmpNotEqual, true);
        }
    }
}
static void lower(UnreachableInst*, LoweringContext& ctx) {
    ctx.emitInst(MIRInst{InstUnreachable});
}
static void lower(SelectInst* inst, LoweringContext& ctx) {
    const auto ret = ctx.newVReg(inst->getType());
    auto& target = ctx.getCodeGenContext().target;
    CompareOp cmp;
    Value *v1, *v2;
    // select x < 0, y, 0 -> (x >>> (bitwidth - 1)) & y
    if (target.isNativeSupported(InstructionID::And) &&
        target.isNativeSupported(InstructionID::AShr) &&
        select(icmp(cmp, any(v1), cint_(0)), any(v2),
               cint_(0))(MatchContext<Value>(inst)) &&
        cmp == CompareOp::ICmpSignedLessThan &&
        inst->getType()->getFixedSize() >= sizeof(int32_t)) {
        const auto mask = ctx.newVReg(inst->getType());
        const auto val = ctx.mapOperand(v1);
        const auto trueV = ctx.mapOperand(v2);
        ctx.emitInst(
            MIRInst{InstAShr}
                .setOperand<0>(mask)
                .setOperand<1>(val)
                .setOperand<2>(MIROperand::asImm(
                    inst->getType()->as<IntegerType>()->getBitwidth() - 1,
                    val.type())));
        ctx.emitInst(MIRInst{InstAnd}
                         .setOperand<0>(ret)
                         .setOperand<1>(trueV)
                         .setOperand<2>(mask));
    }
    // select x, y, 0 -> -x & y
    else if (target.isNativeSupported(InstructionID::And) &&
             !target.getOptHeuristic().disableSelectionOpt &&
             cuint_(0)(MatchContext<Value>(inst->getOperand(2)))) {
        const auto mask = ctx.newVReg(inst->getType());
        const auto cond = ctx.mapOperand(inst->getOperand(0));
        const auto trueV = ctx.mapOperand(inst->getOperand(1));
        ctx.emitInst(MIRInst{InstSub}
                         .setOperand<0>(mask)
                         .setOperand<1>(MIROperand::asImm(0, trueV.type()))
                         .setOperand<2>(cond));
        ctx.emitInst(MIRInst{InstAnd}
                         .setOperand<0>(ret)
                         .setOperand<1>(trueV)
                         .setOperand<2>(mask));
    } else {
        ctx.emitInst(MIRInst{InstSelect}
                         .setOperand<0>(ret)
                         .setOperand<1>(ctx.mapOperand(inst->getOperand(0)))
                         .setOperand<2>(ctx.mapOperand(inst->getOperand(1)))
                         .setOperand<3>(ctx.mapOperand(inst->getOperand(2))));
    }
    ctx.addOperand(inst, ret);
}
static void lower(GetElementPtrInst* inst, LoweringContext& ctx) {
    const auto [constantOffset, offsets] =
        inst->gatherOffsets(ctx.getDataLayout());
    const auto indexType =
        inst->operands().front()->getType();  // must be index type
    const auto base = ctx.mapOperand(inst->lastOperand());

    auto ptr = base;
    for (auto [size, index] : offsets) {
        const auto idx = ctx.mapOperand(index);
        const auto off = ctx.newVReg(indexType);
        if (size == 1) {
            ctx.emitCopy(off, idx);
        } else {
            ctx.emitInst(
                MIRInst{InstMul}
                    .setOperand<0>(off)
                    .setOperand<1>(idx)
                    .setOperand<2>(MIROperand::asImm(size, ctx.getPtrType())));
        }
        auto newPtr = ctx.newVReg(ctx.getPtrType());  // SSA form
        ctx.emitInst(MIRInst{InstAdd}
                         .setOperand<0>(newPtr)
                         .setOperand<1>(ptr)
                         .setOperand<2>(off));
        ptr = newPtr;
    }
    if (constantOffset != 0) {
        auto newPtr = ctx.newVReg(ctx.getPtrType());
        ctx.emitInst(MIRInst{InstAdd}
                         .setOperand<0>(newPtr)
                         .setOperand<1>(ptr)
                         .setOperand<2>(MIROperand::asImm(constantOffset,
                                                          ctx.getPtrType())));
        ptr = newPtr;
    }
    ctx.addOperand(inst, ptr);
}
static void lower(PtrAddInst* inst, LoweringContext& ctx) {
    const auto src = ctx.mapOperand(inst->getOperand(0));
    const auto ptr = ctx.newVReg(inst->getType());
    const auto offset =
        inst->getOperand(1)->as<ConstantInteger>()->getSignExtended();
    if (offset)
        ctx.emitInst(
            MIRInst{InstAdd}
                .setOperand<0>(ptr)
                .setOperand<1>(src)
                .setOperand<2>(MIROperand::asImm(offset, ctx.getPtrType())));
    else
        ctx.emitCopy(ptr, src);
    ctx.addOperand(inst, ptr);
}
static void emitCopy(Instruction* inst, LoweringContext& ctx) {
    auto vreg = ctx.newVReg(inst->getType());
    const auto src = ctx.mapOperand(inst->getOperand(0));
    ctx.emitCopy(vreg, src);
    ctx.addOperand(inst, vreg);
}
static void lower(PtrCastInst* inst, LoweringContext& ctx) {
    emitCopy(inst, ctx);
}
static void lower(PtrToIntInst* inst, LoweringContext& ctx) {
    emitCopy(inst, ctx);
}
static void lower(IntToPtrInst* inst, LoweringContext& ctx) {
    emitCopy(inst, ctx);
}
static void lower(ReturnInst* inst, LoweringContext& ctx) {
    ctx.getCodeGenContext().frameInfo.emitReturn(inst, ctx);
}
static void lower(FunctionCallInst* inst, LoweringContext& ctx) {
    ctx.getCodeGenContext().frameInfo.emitCall(inst, ctx);
}
static void lower(FunctionPtrInst* inst, LoweringContext& ctx) {
    const auto ptr = ctx.newVReg(ctx.getPtrType());
    ctx.emitInst(
        MIRInst{InstLoadGlobalAddress}.setOperand<0>(ptr).setOperand<1>(
            MIROperand::asReloc(
                ctx.mapGlobal(inst->getOperand(0)->as<Function>())
                    ->reloc.get())));
    ctx.addOperand(inst, ptr);
}
static void lower(SwitchInst* inst,
                  LoweringContext& ctx,
                  const IntegerRangeAnalysisResult& range,
                  const DominateAnalysisResult& dom) {
    const auto valRange = range.query(inst->getOperand(0), dom, inst, 5);
    auto jumpTable = std::make_unique<MIRJumpTable>(
        String::get("__cmmc_jumptable"sv)
            .withID(static_cast<int32_t>(ctx.getCodeGenContext().nextId())));
    auto& table = jumpTable->data();
    auto fillTable = [&](intmax_t base, intmax_t size, MIRBasicBlock* fill) {
        table.resize(static_cast<size_t>(size));
        for (intmax_t i = 0; i < size; ++i) {
            const auto key = base + i;
            if (auto iter = inst->edges().find(key);
                iter != inst->edges().cend()) {
                // no phi
                table[static_cast<size_t>(i)] = ctx.mapBlock(iter->second);
            } else {
                table[static_cast<size_t>(i)] = fill;
            }
        }
    };
    const auto defaultPrepare = ctx.addBlockAfter();
    const auto val = ctx.mapOperand(inst->getOperand(0));
    auto& iselInfo = ctx.getCodeGenContext().iselInfo;

    if (valRange.maxSignedValue() - valRange.minSignedValue() < 256) {
        // hole -> default label
        const auto base = valRange.minSignedValue();
        const auto size =
            valRange.maxSignedValue() - valRange.minSignedValue() + 1;
        fillTable(base, size, defaultPrepare);
        const auto offset = ctx.newVReg(val.type());
        if (base == 0)
            ctx.emitCopy(offset, val);
        else
            ctx.emitInst(
                MIRInst{InstSub}
                    .setOperand<0>(offset)
                    .setOperand<1>(val)
                    .setOperand<2>(MIROperand::asImm(base, val.type())));
        iselInfo.lowerIndirectJump(jumpTable.get(), offset, ctx);
    } else {
        // range check
        // hole -> default label
        const auto base = inst->edges().begin()->first;
        const auto size = inst->edges().rbegin()->first - base + 1;
        fillTable(base, size, defaultPrepare);
        // range check
        const auto offset = ctx.newVReg(val.type());
        if (base == 0)
            ctx.emitCopy(offset, val);
        else
            ctx.emitInst(
                MIRInst{InstSub}
                    .setOperand<0>(offset)
                    .setOperand<1>(val)
                    .setOperand<2>(MIROperand::asImm(base, val.type())));
        const auto cond = ctx.newVReg(OperandType::Bool);
        ctx.emitInst(MIRInst{InstICmp}
                         .setOperand<0>(cond)
                         .setOperand<1>(offset)
                         .setOperand<2>(MIROperand::asImm(size, offset.type()))
                         .setOperand<3>(MIROperand::asImm(
                             CompareOp::ICmpUnsignedGreaterEqual,
                             OperandType::Special)));
        ctx.emitInst(
            MIRInst{InstBranch}
                .setOperand<0>(cond)
                .setOperand<1>(MIROperand::asReloc(defaultPrepare))
                .setOperand<2>(MIROperand::asProb(
                    1.0 / static_cast<double>(inst->edges().size() + 1))));
        const auto switchBlock = ctx.addBlockAfter();
        ctx.setCurrentBasicBlock(switchBlock);
        // indirect jump
        iselInfo.lowerIndirectJump(jumpTable.get(), offset, ctx);
    }

    ctx.setCurrentBasicBlock(defaultPrepare);
    emitBranch(inst->defaultTarget(), inst->getBlock(), ctx);
    ctx.getModule().globals().push_back(std::make_unique<MIRGlobal>(
        Linkage::Internal, ctx.getDataLayout().getStorageAlignment(),
        std::move(jumpTable)));
}
static void lowerInst(Instruction* inst,
                      LoweringContext& ctx,
                      const PointerAlignmentAnalysisResult& alignment,
                      const IntegerRangeAnalysisResult& range,
                      const DominateAnalysisResult& dom) {
    switch (inst->getInstID()) {
        case InstructionID::Add:
        case InstructionID::Sub:
        case InstructionID::Mul:
        case InstructionID::UDiv:
        case InstructionID::URem:
        case InstructionID::And:
        case InstructionID::Or:
        case InstructionID::Xor:
        case InstructionID::Shl:
        case InstructionID::LShr:
        case InstructionID::AShr:
        case InstructionID::SMin:
        case InstructionID::SMax:
        case InstructionID::FAdd:
        case InstructionID::FSub:
        case InstructionID::FMul:
        case InstructionID::FDiv:
            lower(inst->as<BinaryInst>(), ctx);
            break;
        case InstructionID::SDiv:
        case InstructionID::SRem:
            lowerSDivRem(inst->as<BinaryInst>(), ctx, range, dom);
            break;
        case InstructionID::Neg:
        case InstructionID::Abs:
        case InstructionID::FNeg:
        case InstructionID::FAbs:
            lower(inst->as<UnaryInst>(), ctx);
            break;
        case InstructionID::ICmp:
        case InstructionID::FCmp:
            lower(inst->as<CompareInst>(), ctx);
            break;
        case InstructionID::Ret:
            lower(inst->as<ReturnInst>(), ctx);
            break;
        case InstructionID::Branch:
        case InstructionID::ConditionalBranch:
            lower(inst->as<BranchInst>(), ctx);
            break;
        case InstructionID::Unreachable:
            lower(inst->as<UnreachableInst>(), ctx);
            break;
        case InstructionID::Switch:
            lower(inst->as<SwitchInst>(), ctx, range, dom);
            break;
        case InstructionID::Load:
            lower(inst->as<LoadInst>(), ctx, alignment);
            break;
        case InstructionID::Store:
            lower(inst->as<StoreInst>(), ctx, alignment);
            break;
        case InstructionID::SExt:
        case InstructionID::ZExt:
        case InstructionID::SignedTrunc:
        case InstructionID::UnsignedTrunc:
        case InstructionID::Bitcast:
        case InstructionID::F2U:
        case InstructionID::F2S:
        case InstructionID::U2F:
        case InstructionID::S2F:
        case InstructionID::FCast:
            lower(inst->as<CastInst>(), ctx);
            break;
        case InstructionID::Alloc:
            break;
        case InstructionID::GetElementPtr:
            lower(inst->as<GetElementPtrInst>(), ctx);
            break;
        case InstructionID::PtrCast:
            lower(inst->as<PtrCastInst>(), ctx);
            break;
        case InstructionID::PtrToInt:
            lower(inst->as<PtrToIntInst>(), ctx);
            break;
        case InstructionID::IntToPtr:
            lower(inst->as<IntToPtrInst>(), ctx);
            break;
        case InstructionID::PtrAdd:
            lower(inst->as<PtrAddInst>(), ctx);
            break;
        case InstructionID::Select:
            lower(inst->as<SelectInst>(), ctx);
            break;
        case InstructionID::Call:
            lower(inst->as<FunctionCallInst>(), ctx);
            break;
        case InstructionID::Phi:  // noop
            break;
        case InstructionID::FunctionPtr:
            lower(inst->as<FunctionPtrInst>(), ctx);
            break;
        default:
            reportUnreachable(CMMC_LOCATION());
    }
}

MIROperand LoweringContext::newVReg(const Type* type) {
    return MIROperand::asVReg(mCodeGenCtx.nextId(), getOperandType(type, mPtrType));
}
MIROperand LoweringContext::newVReg(OperandType type) {
    return MIROperand::asVReg(mCodeGenCtx.nextId(), type);
}
void LoweringContext::emitInst(const MIRInst& inst) {
    auto& insts = mCurrentBasicBlock->instructions();
    insts.emplace_back(inst);
}

void LoweringContext::emitCopy(const MIROperand& dst, const MIROperand& src) {
    auto inst = MIRInst{
        selectCopyOpcode(dst, src)}
        .setOperand<0>(dst)
        .setOperand<1>(src);
    emitInst(inst);
    if constexpr (Config::debug) {
        auto& instInfo = mCodeGenCtx.instInfo.getInstInfo(inst);
        CMMC_UNUSED(instInfo);
        assert(instInfo.verify(inst, mCodeGenCtx));
    }
}
CMMC_MIR_NAMESPACE_END
