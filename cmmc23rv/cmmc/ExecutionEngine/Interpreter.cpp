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
#include <chrono>
#include <cmath>
#include "../../cmmc/CodeGen/DataLayout.hpp"
#include "../../cmmc/CodeGen/Target.hpp"
#include "../../cmmc/ExecutionEngine/Interpreter.hpp"
#include "../../cmmc/IR/Attachments.hpp"
#include "../../cmmc/IR/ConstantValue.hpp"
#include "../../cmmc/IR/Function.hpp"
#include "../../cmmc/IR/GlobalVariable.hpp"
#include "../../cmmc/IR/Instruction.hpp"
#include "../../cmmc/IR/Module.hpp"
#include "../../cmmc/IR/Type.hpp"
#include "../../cmmc/Support/Diagnostics.hpp"
#include "../../cmmc/Support/Dispatch.hpp"
#include "../../cmmc/Support/Options.hpp"
#include "../../cmmc/Support/Profiler.hpp"
#include <cstdint>
#include <cstring>
#include <deque>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

CMMC_NAMESPACE_BEGIN

static Flag step;  // NOLINT

CMMC_INIT_OPTIONS_BEGIN
step.setName("step", 'S').setDesc("run interpreter step-by-step");
CMMC_INIT_OPTIONS_END

enum class ByteState : uint8_t { Read = 1 << 0, Write = 1 << 1, None = 0 };

constexpr ByteState operator|(ByteState lhs, ByteState rhs) {
    return static_cast<ByteState>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}

constexpr ByteState operator|=(ByteState& lhs, ByteState rhs) {
    return lhs = lhs | rhs;
}

constexpr ByteState operator&(ByteState lhs, ByteState rhs) {
    return static_cast<ByteState>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}

constexpr ByteState operator&=(ByteState& lhs, ByteState rhs) {
    return lhs = lhs & rhs;
}

constexpr ByteState operator~(ByteState x) {
    return static_cast<ByteState>(~static_cast<uint8_t>(x));
}

constexpr bool hasTag(ByteState provided, ByteState required) {
    return (provided & required) == required;
}

using OperandStorage =
    std::variant<ConstantInteger, ConstantFloatingPoint, ConstantOffset*, uintptr_t, Function*, std::monostate>;

// Byte-level simulation
class MemoryContext final {
    using ByteStorage = std::pair<ByteState, std::byte>;
    static_assert(sizeof(ByteStorage) == 2);
    static_assert(sizeof(uintptr_t) == 8);

    static constexpr uint64_t globalOffset = 0xf000'0000'0000'0000;
    static constexpr uint64_t stackOffset = 0x1000'0000'0000'0000;
    static constexpr std::byte invalidByte{ 0xCC };
    static constexpr ByteStorage invalidByteStorage{ ByteState::None, invalidByte };

    size_t mBudget;
    const DataLayout& mDataLayout;
    bool mHasMemoryError = false;
    std::vector<ByteStorage> mGlobalStorage;
    std::unordered_map<GlobalVariable*, uintptr_t> mGlobalAlloc;
    std::vector<ByteStorage> mStackStorage;
    std::vector<std::pair<uintptr_t, uintptr_t>> mStackAlloc;  // [begin, end)
    std::unordered_set<uintptr_t> mPopedStackPtr;
    size_t mLoadMemFootprint = 0;
    size_t mStoreMemFootprint = 0;

    static void extendTo(std::vector<ByteStorage>& storage, size_t size) {
        storage.reserve(size);
        while(storage.size() < size)
            storage.push_back(invalidByteStorage);
    }
    static uintptr_t paddingTo(std::vector<ByteStorage>& storage, size_t base, size_t alignment) {
        const auto pos = (base / alignment + 1) * alignment;
        extendTo(storage, pos);
        for(size_t idx = base; idx != pos; ++idx) {
            storage[idx] = invalidByteStorage;
        }
        return pos;
    }
    static void setTag(std::vector<ByteStorage>& storage, size_t base, size_t size, ByteState tag) {
        extendTo(storage, base + size);
        for(size_t idx = 0; idx != size; ++idx)
            storage[base + idx].first = tag;
    }

    static void removeTag(std::vector<ByteStorage>& storage, size_t base, size_t size, ByteState tag) {
        extendTo(storage, base + size);
        for(size_t idx = 0; idx != size; ++idx)
            storage[base + idx].first &= ~tag;
    }
    void triggerMemoryError() {
        mHasMemoryError = true;
    }
    std::byte load(std::vector<ByteStorage>& storage, uintptr_t ptr) {
        ++mLoadMemFootprint;

        if(ptr < storage.size()) {
            const auto val = storage[ptr];
            if(hasTag(val.first, ByteState::Read))
                return val.second;
        }
        triggerMemoryError();
        return invalidByte;
    }
    void store(std::vector<ByteStorage>& storage, uintptr_t ptr, std::byte val) {
        ++mStoreMemFootprint;

        if(ptr < storage.size()) {
            auto& ref = storage[ptr];
            if(hasTag(ref.first, ByteState::Write)) {
                ref.second = val;
                return;
            }
        }
        triggerMemoryError();
    }

public:
    MemoryContext(size_t budget, const DataLayout& dataLayout) : mBudget{ budget }, mDataLayout{ dataLayout } {
        mStackAlloc.emplace_back(0U, 16U);  // start
    }
    bool isExceeded() const noexcept {
        return (mGlobalStorage.size() + mStackStorage.size()) * sizeof(ByteStorage) > mBudget;
    }
    bool hasException() const noexcept {
        return mHasMemoryError;
    }
    uintptr_t getGlobalVarAddress(GlobalVariable* var) {
        const auto iter = mGlobalAlloc.find(var);
        if(iter != mGlobalAlloc.cend())
            return iter->second;

        const auto oldStoreFootprint = mStoreMemFootprint;

        const auto storageType = var->getType()->as<PointerType>()->getPointee();
        const auto alignment = storageType->getAlignment(mDataLayout);
        const auto size = storageType->getSize(mDataLayout);
        const auto ptr = paddingTo(mGlobalStorage, mGlobalStorage.size(), alignment);
        setTag(mGlobalStorage, ptr, size, ByteState::Read | ByteState::Write);
        if(var->initialValue()) {
            // initialize with initialValue
            storeValue(ptr + globalOffset, var->initialValue(), var->initialValue()->getType());
        } else {
            // initialize with zero
            memReset(ptr + globalOffset, size, std::byte{ 0 });
        }
        if(var->attr().hasAttr(GlobalVariableAttribute::ReadOnly))
            removeTag(mGlobalStorage, ptr, size, ByteState::Write);
        assert(!mGlobalAlloc.count(var));
        mGlobalAlloc.emplace(var, ptr + globalOffset);

        mStoreMemFootprint = oldStoreFootprint;  // rollback counters

        return ptr + globalOffset;
    }
    uintptr_t stackPush(size_t size, size_t alignment) {
        assert(size >= 1);
        assert(!mStackAlloc.empty());
        const auto [beg, end] = mStackAlloc.back();
        CMMC_UNUSED(beg);
        const auto ptr = paddingTo(mStackStorage, end, alignment);
        setTag(mStackStorage, ptr, size, ByteState::Read | ByteState::Write);
        mStackAlloc.emplace_back(ptr, ptr + size);
        return ptr + stackOffset;
    }
    void stackPop(uintptr_t base) {
        base -= stackOffset;
        if(mStackAlloc.back().first == base) {
            const auto stackPopOne = [&] {
                const auto [begin, end] = mStackAlloc.back();
                setTag(mStackStorage, begin, end - begin, ByteState::None);
                mStackAlloc.pop_back();
            };
            stackPopOne();
            while(true) {
                auto iter = mPopedStackPtr.find(mStackAlloc.back().first);
                if(iter == mPopedStackPtr.cend())
                    return;
                stackPopOne();
                mPopedStackPtr.erase(iter);
            }
        } else {
            mPopedStackPtr.insert(base);
        }
    }

    std::byte load(uintptr_t ptr) {
        if(ptr >= globalOffset)
            return load(mGlobalStorage, ptr - globalOffset);

        return load(mStackStorage, ptr - stackOffset);
    }
    void store(uintptr_t ptr, std::byte val) {
        if(ptr >= globalOffset)
            return store(mGlobalStorage, ptr - globalOffset, val);

        return store(mStackStorage, ptr - stackOffset, val);
    }

    OperandStorage loadValue(uintptr_t ptr, const Type* type) {
        const auto alignment = type->getAlignment(mDataLayout);
        if(ptr % alignment != 0) {
            triggerMemoryError();
            return std::monostate{};
        }

        if(type->isInteger()) {
            static_assert(sizeof(uintmax_t) >= 8);
            uintmax_t val = 0;
            const auto base = reinterpret_cast<std::byte*>(&val);
            const auto size = type->getFixedSize();
            for(uint32_t idx = 0; idx < size; ++idx)
                base[idx] = load(ptr + idx);
            return ConstantInteger{ type, static_cast<intmax_t>(val), ExplicitConstruct{} };
        }
        if(type->isFloatingPoint()) {
            alignas(alignof(double)) std::array<std::byte, sizeof(double)> storage;
            const auto size = type->getFixedSize();
            for(uint32_t idx = 0; idx < size; ++idx)
                storage[idx] = load(ptr + idx);
            double val = 0.0;
            if(size == sizeof(float)) {
                val = *reinterpret_cast<float*>(storage.data());
            } else {
                val = *reinterpret_cast<double*>(storage.data());
            }
            return ConstantFloatingPoint{ type, val };
        }
        if(type->isPointer()) {
            uintptr_t val;
            const auto base = reinterpret_cast<std::byte*>(&val);
            for(uint32_t idx = 0; idx < sizeof(uintptr_t); ++idx)
                base[idx] = load(ptr + idx);
            return val;
        }
        reportNotImplemented(CMMC_LOCATION());
    }

    template <typename T>
    T loadValue(uintptr_t ptr) {
        const auto alignment = alignof(T);
        if(ptr % alignment != 0) {
            triggerMemoryError();
            return T{};
        }

        constexpr auto size = sizeof(T);
        if constexpr(std::is_integral_v<T>) {
            static_assert(sizeof(uintmax_t) >= 8);
            uintmax_t val = 0;
            const auto base = reinterpret_cast<std::byte*>(&val);

            for(uint32_t idx = 0; idx < size; ++idx)
                base[idx] = load(ptr + idx);
            return static_cast<T>(val);
        } else if constexpr(std::is_floating_point_v<T>) {
            alignas(alignof(double)) std::array<std::byte, sizeof(double)> storage;
            for(uint32_t idx = 0; idx < size; ++idx)
                storage[idx] = load(ptr + idx);
            return *reinterpret_cast<T*>(storage.data());
        } else {
            static_assert(FalseType<T>::value, "unsupported type");
        }
    }

    void memReset(uintptr_t ptr, size_t size, std::byte byte) {
        for(size_t idx = 0; idx < size; ++idx)
            store(ptr + idx, byte);
    }

    void memCopy(uintptr_t dest, uintptr_t src, size_t size) {
        for(size_t idx = 0; idx < size; ++idx)
            store(dest + idx, load(src + idx));
    }

    void storeValue(uintptr_t ptr, ConstantValue* value, const Type* type) {
        const auto alignment = type->getAlignment(mDataLayout);
        if(ptr % alignment != 0) {
            triggerMemoryError();
            return;
        }

        if(type->isInteger()) {
            static_assert(sizeof(uintmax_t) >= 8);
            const uintmax_t val = value->as<ConstantInteger>()->getZeroExtended();
            const auto base = reinterpret_cast<const std::byte*>(&val);
            const auto size = type->getFixedSize();
            for(uint32_t idx = 0; idx < size; ++idx)
                store(ptr + idx, base[idx]);
        } else if(type->isFloatingPoint()) {
            const double val = value->as<ConstantFloatingPoint>()->getValue();
            alignas(alignof(double)) std::array<std::byte, sizeof(double)> storage;
            const auto size = type->getFixedSize();
            if(size == sizeof(float)) {
                *reinterpret_cast<float*>(storage.data()) = static_cast<float>(val);
            } else {
                *reinterpret_cast<double*>(storage.data()) = val;
            }

            for(uint32_t idx = 0; idx < size; ++idx)
                store(ptr + idx, storage[idx]);
        } else if(type->isPointer()) {
            const auto val = reinterpret_cast<uintptr_t>(value);
            const auto base = reinterpret_cast<const std::byte*>(&val);
            for(uint32_t idx = 0; idx < sizeof(uintptr_t); ++idx)
                store(ptr + idx, base[idx]);
        } else if(type->isArray()) {
            const auto arrType = type->as<ArrayType>();
            const auto subType = arrType->getElementType();
            const auto offset = subType->getSize(mDataLayout);
            const auto array = value->as<ConstantArray>();
            for(uint32_t idx = 0; idx < arrType->getElementCount(); ++idx) {
                const auto newPtr = ptr + idx * offset;
                if(idx >= array->values().size()) {
                    memReset(newPtr, offset, std::byte{ 0 });
                } else {
                    storeValue(newPtr, array->values()[idx], subType);
                }
            }
        } else
            reportNotImplemented(CMMC_LOCATION());
    }

    void storeValue(uintptr_t ptr, const OperandStorage& value, const Type* type) {
        std::visit(Overload{ [&](auto&&) { reportUnreachable(CMMC_LOCATION()); },  //
                             [&](const ConstantInteger& x) {
                                 const uintmax_t val = x.getZeroExtended();
                                 const auto base = reinterpret_cast<const std::byte*>(&val);
                                 const auto size = type->getFixedSize();
                                 for(uint32_t idx = 0; idx < size; ++idx)
                                     store(ptr + idx, base[idx]);
                             },
                             [&](const ConstantFloatingPoint& x) {
                                 const auto val = x.getValue();
                                 alignas(alignof(double)) std::array<std::byte, sizeof(double)> storage;
                                 const auto size = type->getFixedSize();
                                 if(size == sizeof(float)) {
                                     *reinterpret_cast<float*>(storage.data()) = static_cast<float>(val);
                                 } else {
                                     *reinterpret_cast<double*>(storage.data()) = val;
                                 }

                                 for(uint32_t idx = 0; idx < size; ++idx)
                                     store(ptr + idx, storage[idx]);
                             },
                             [&](uintptr_t val) {
                                 const auto base = reinterpret_cast<const std::byte*>(&val);
                                 for(uint32_t idx = 0; idx < sizeof(uintptr_t); ++idx)
                                     store(ptr + idx, base[idx]);
                             } },
                   value);
    }

    template <typename T>
    struct FalseType final {
        static constexpr bool value = false;
    };

    template <typename T>
    void storeValue(uintptr_t ptr, T value) {
        const auto alignment = alignof(T);
        if(ptr % alignment != 0) {
            triggerMemoryError();
            return;
        }

        const auto size = sizeof(T);
        if constexpr(std::is_integral_v<T>) {
            static_assert(sizeof(uintmax_t) >= 8);
            const auto val = static_cast<uintmax_t>(value);
            const auto base = reinterpret_cast<const std::byte*>(&val);
            for(uint32_t idx = 0; idx < size; ++idx)
                store(ptr + idx, base[idx]);
        } else if constexpr(std::is_floating_point_v<T>) {
            alignas(alignof(double)) std::array<std::byte, sizeof(double)> storage;
            *reinterpret_cast<T*>(storage.data()) = value;

            for(uint32_t idx = 0; idx < size; ++idx)
                store(ptr + idx, storage[idx]);
        } else {
            static_assert(FalseType<T>::value, "unsupported type");
        }
    }

    size_t getTotalLoad() const noexcept {
        return mLoadMemFootprint;
    }

    size_t getTotalStore() const noexcept {
        return mStoreMemFootprint;
    }
};

Interpreter::Interpreter(size_t timeBudget, size_t memBudget, size_t maxRecursiveDepth, bool dumpStatistics)
    : mTimeBudget{ timeBudget }, mMemBudget{ memBudget }, mMaxRecursiveDepth{ maxRecursiveDepth }, mDumpStatistics{
          dumpStatistics
      } {}

std::variant<ConstantValue*, SimulationFailReason> Interpreter::execute(Module& module, Function& func,
                                                                        const std::vector<ConstantValue*>& arguments,
                                                                        SimulationIOContext* ioCtx) const {
    if(func.attr().hasAttr(FunctionAttribute::NoReturn))
        return SimulationFailReason::EnterNoreturnFunc;

    const auto& target = module.getTarget();
    const auto& dataLayout = target.getDataLayout();

    {
        const uint16_t endianTest = 0xAABB;
        const auto base = reinterpret_cast<const uint8_t*>(&endianTest);

        if(dataLayout.getEndian() != Endian::Little)
            return SimulationFailReason::UnsupportedTarget;

        if(!(base[0] == 0xBB && base[1] == 0xAA) || sizeof(uintptr_t) != 8) {
            return SimulationFailReason::UnsupportedHost;
        }
    }

    MemoryContext memCtx{ mMemBudget, dataLayout };

    const auto funcType = func.getType()->as<FunctionType>();
    if(funcType->getArgTypes().size() != arguments.size())
        DiagnosticsContext::get().attach<Reason>("argument count mismatch").reportFatal();
    for(uint32_t idx = 0; idx < arguments.size(); ++idx)
        if(!funcType->getArgTypes()[idx]->isSame(arguments[idx]->getType()))
            DiagnosticsContext::get()
                .attach<Reason>("argument type mismatch")
                .attach<TypeAttachment>("required", funcType->getArgTypes()[idx])
                .attach<TypeAttachment>("provided", arguments[idx]->getType())
                .reportFatal();

    const auto fromConstant = [](ConstantValue* val) -> OperandStorage {
        if(auto intVal = dynamic_cast<ConstantInteger*>(val)) {
            return *intVal;
        }
        if(auto fpVal = dynamic_cast<ConstantFloatingPoint*>(val)) {
            return *fpVal;
        }
        if(auto offset = dynamic_cast<ConstantOffset*>(val)) {
            return offset;
        }
        if(auto undefined = dynamic_cast<UndefinedValue*>(val)) {
            const auto type = undefined->getType();
            if(type->isInteger()) {
                return ConstantInteger{ type, 0x7CCC'CCCC'CCCC'CCCCLL, ExplicitConstruct{} };
            }
            if(type->isFloatingPoint()) {
                return ConstantFloatingPoint{ type, std::numeric_limits<double>::quiet_NaN() };
            }
            if(type->isPointer()) {
                return static_cast<uintptr_t>(0);
            }
            reportUnreachable(CMMC_LOCATION());
        } else
            reportUnreachable(CMMC_LOCATION());
    };

    const auto toConstant = [](const OperandStorage& val) -> ConstantValue* {
        ConstantValue* ret = nullptr;
        std::visit(Overload{
                       [&](auto&&) { reportUnreachable(CMMC_LOCATION()); },                                              //
                       [&](const ConstantInteger& x) { ret = ConstantInteger::get(x.getType(), x.getSignExtended()); },  //
                       [&](const ConstantFloatingPoint& x) { ret = make<ConstantFloatingPoint>(x); },                    //
                       [&](ConstantOffset* x) { ret = x; }                                                               //
                   },
                   val);
        return ret;
    };

    struct BlockContext final {
        Instruction* caller;
        Block* block;
        Block* predBlock;
        std::unordered_map<Value*, OperandStorage> operands;
        IntrusiveListIterator<Instruction> execIter;
        std::unordered_map<uintptr_t, Instruction*> stackAllocs;
        std::unordered_map<Instruction*, uintptr_t> cachedAllocs;
    };

    std::vector<BlockContext> execCtx;
    {
        if(func.blocks().empty())
            return SimulationFailReason::Undefined;

        BlockContext entry;
        entry.caller = nullptr;
        entry.block = func.entryBlock();
        entry.predBlock = nullptr;
        entry.execIter = entry.block->instructions().begin();
        for(uint32_t idx = 0; idx < arguments.size(); ++idx)
            entry.operands.emplace(func.getArg(idx), fromConstant(arguments[idx]));
        if(step.get()) {
            func.dump(std::cerr, Noop{});
            entry.block->dumpLabeled(std::cerr, Noop{});
        }

        execCtx.push_back(std::move(entry));
    }

    const auto start = Clock::now();

    // statistics
    size_t instructionCount = 0;
    size_t branchCount = 0;
    size_t callCount = 0;
    size_t loadCount = 0;
    size_t storeCount = 0;

    auto reportStatistics = [&] {
        auto& out = std::cerr;
        const auto end = Clock::now();
        out << R"({"time": )" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        out << R"(,"inst": )" << instructionCount;
        out << R"(,"branch": )" << branchCount;
        out << R"(,"call": )" << callCount;
        out << R"(,"load": )" << loadCount;
        out << R"(,"store": )" << storeCount;
        out << R"(,"load_bytes": )" << memCtx.getTotalLoad();
        out << R"(,"store_bytes": )" << memCtx.getTotalStore() << '}' << std::endl;
    };

    std::vector<OperandStorage> operands;
    while(true) {
        const auto current = Clock::now();
        if(std::chrono::duration_cast<std::chrono::nanoseconds>(current - start).count() >= static_cast<int64_t>(mTimeBudget))
            return SimulationFailReason::ExceedTimeLimit;
        if(memCtx.isExceeded())
            return SimulationFailReason::ExceedMemoryLimit;
        if(memCtx.hasException())
            return SimulationFailReason::MemoryError;

        auto& currentExecCtx = execCtx.back();
        auto iter = currentExecCtx.execIter;
        if(iter == currentExecCtx.block->instructions().end())
            return SimulationFailReason::UnknownError;

        const auto dumpValue = [&](const OperandStorage& val) {
            auto& out = std::cerr;
            std::visit(Overload{ [&](auto&&) { out << "unknown"sv; },                                   //
                                 [&](const ConstantInteger& x) { x.dump(out, Noop{}); },                //
                                 [&](const ConstantFloatingPoint& x) { x.dump(out, Noop{}); },          //
                                 [&](const ConstantOffset* x) { x->dump(out, Noop{}); },                //
                                 [&](const Function* x) { x->dumpAsOperand(out); },                     //
                                 [&](uintptr_t x) { out << "ptr "sv << std::hex << x << std::dec; } },  //
                       val);
        };
        const auto addValue = [&](Instruction& mappedInst, const OperandStorage& val) {
            currentExecCtx.operands.insert_or_assign(&mappedInst, val);
            if(step.get()) {
                auto& out = std::cerr;
                mappedInst.dump(out, Noop{});
                out << " -> "sv;
                dumpValue(val);
                out << '\n';
            }
        };
        auto buildOperand = [&](Value* operand) {
            if(operand->isConstant())
                operands.push_back(fromConstant(operand->as<ConstantValue>()));
            else if(operand->isGlobal()) {
                if(operand->getType()->isFunction()) {
                    operands.emplace_back(operand->as<Function>());
                } else {
                    operands.emplace_back(memCtx.getGlobalVarAddress(operand->as<GlobalVariable>()));
                }
            } else {
                operands.push_back(currentExecCtx.operands.at(operand));
            }
        };
        {
            std::unordered_map<Instruction*, OperandStorage> phiValue;
            while(iter->getInstID() == InstructionID::Phi) {
                buildOperand(iter->as<PhiInst>()->incomings().at(currentExecCtx.predBlock)->value);
                phiValue.emplace(iter.get(), operands.back());
                ++iter;
                assert(iter != currentExecCtx.block->instructions().end());
            }
            for(auto& [k, v] : phiValue)
                addValue(*k, v);
        }

        auto& inst = *iter;
        assert(inst.getInstID() != InstructionID::Phi);
        currentExecCtx.execIter = std::next(iter);
        ++instructionCount;

        operands.clear();

        operands.reserve(inst.operands().size());
        for(auto operand : inst.operands())
            buildOperand(operand);

        const auto getInt = [&](uint32_t idx) { return std::get<ConstantInteger>(operands[idx]).getSignExtended(); };
        const auto getUInt = [&](uint32_t idx) { return std::get<ConstantInteger>(operands[idx]).getZeroExtended(); };
        const auto getPtr = [&](uint32_t idx) { return std::get<uintptr_t>(operands[idx]); };
        const auto getFP = [&](uint32_t idx) { return std::get<ConstantFloatingPoint>(operands[idx]).getValue(); };

        const auto addInt = [&](intmax_t val) { addValue(inst, ConstantInteger{ inst.getType(), val, ExplicitConstruct{} }); };
        const auto addUInt = [&](uintmax_t val) {
            addValue(inst, ConstantInteger{ inst.getType(), static_cast<intmax_t>(val), ExplicitConstruct{} });
        };
        const auto addBoolean = [&](bool val) {
            addValue(inst, ConstantInteger{ inst.getType(), static_cast<intmax_t>(val), ExplicitConstruct{} });
        };
        const auto addPtr = [&](uintptr_t val) { addValue(inst, val); };
        const auto addFP = [&](double val) { addValue(inst, ConstantFloatingPoint{ inst.getType(), val }); };

        const auto doCompare = [&](CompareOp cmp, intmax_t lhs, intmax_t rhs) {
            if(step.get()) {
                auto& out = std::cerr;
                out << "compare "sv;
                std::cerr << lhs;
                out << ' ' << enumName(cmp) << ' ';
                std::cerr << rhs;
                out << '\n';
            }
            switch(cmp) {
                case CompareOp::ICmpEqual:
                    return lhs == rhs;
                case CompareOp::ICmpNotEqual:
                    return lhs != rhs;
                case CompareOp::ICmpSignedLessThan:
                    return lhs < rhs;
                case CompareOp::ICmpSignedLessEqual:
                    return lhs <= rhs;
                case CompareOp::ICmpSignedGreaterThan:
                    return lhs > rhs;
                case CompareOp::ICmpSignedGreaterEqual:
                    return lhs >= rhs;
                case CompareOp::ICmpUnsignedLessThan:
                    return static_cast<uintmax_t>(lhs) < static_cast<uintmax_t>(rhs);
                case CompareOp::ICmpUnsignedLessEqual:
                    return static_cast<uintmax_t>(lhs) <= static_cast<uintmax_t>(rhs);
                case CompareOp::ICmpUnsignedGreaterThan:
                    return static_cast<uintmax_t>(lhs) > static_cast<uintmax_t>(rhs);
                case CompareOp::ICmpUnsignedGreaterEqual:
                    return static_cast<uintmax_t>(lhs) >= static_cast<uintmax_t>(rhs);
                default:
                    reportUnreachable(CMMC_LOCATION());
            }
        };

        const auto doCompareFP = [&](CompareOp cmp, double lhs, double rhs) {
            if(step.get()) {
                auto& out = std::cerr;
                out << "compare "sv;
                std::cerr << lhs;
                out << ' ' << enumName(cmp) << ' ';
                std::cerr << rhs;
                out << '\n';
            }
            switch(cmp) {
                case CompareOp::FCmpOrderedEqual:
                    return lhs == rhs;
                case CompareOp::FCmpOrderedLessThan:
                    return lhs < rhs;
                case CompareOp::FCmpOrderedLessEqual:
                    return lhs <= rhs;
                case CompareOp::FCmpOrderedGreaterThan:
                    return lhs > rhs;
                case CompareOp::FCmpOrderedGreaterEqual:
                    return lhs >= rhs;
                case CompareOp::FCmpUnorderedNotEqual:
                    return lhs != rhs;
                case CompareOp::FCmpUnorderedLessThan:
                    return !(lhs >= rhs);
                case CompareOp::FCmpUnorderedLessEqual:
                    return !(lhs > rhs);
                case CompareOp::FCmpUnorderedGreaterThan:
                    return !(lhs <= rhs);
                case CompareOp::FCmpUnorderedGreaterEqual:
                    return !(lhs < rhs);
                default:
                    reportUnreachable(CMMC_LOCATION());
            }
        };

        switch(inst.getInstID()) {
            case InstructionID::Ret: {
                const auto caller = currentExecCtx.caller;
                for(auto [base, alloc] : currentExecCtx.stackAllocs) {
                    CMMC_UNUSED(alloc);
                    memCtx.stackPop(base);
                }

                execCtx.pop_back();
                if(execCtx.empty()) {
                    if(mDumpStatistics)
                        reportStatistics();
                    return operands.empty() ? nullptr : toConstant(operands[0]);
                }
                if(!operands.empty()) {
                    if(step.get()) {
                        std::cerr << "Ret "sv;
                        dumpValue(operands[0]);
                        std::cerr << "->"sv;
                        caller->dumpAsOperand(std::cerr);
                        std::cerr << '\n';
                    }
                    execCtx.back().operands.insert_or_assign(caller, operands[0]);
                }

                break;
            };
            case InstructionID::Branch:
            case InstructionID::ConditionalBranch: {
                ++branchCount;
                auto branch = inst.as<BranchInst>();

                Block* targetBlock = nullptr;
                if(inst.getInstID() == InstructionID::Branch) {
                    targetBlock = branch->getTrueTarget();
                } else if(getUInt(0)) {
                    targetBlock = branch->getTrueTarget();
                } else {
                    targetBlock = branch->getFalseTarget();
                }

                currentExecCtx.predBlock = currentExecCtx.block;
                currentExecCtx.block = targetBlock;
                currentExecCtx.execIter = targetBlock->instructions().begin();
                if(step.get()) {
                    currentExecCtx.block->dumpLabeled(std::cerr, Noop{});
                }
                break;
            }
            case InstructionID::Unreachable:
                return SimulationFailReason::Unreachable;
            case InstructionID::Switch: {
                ++branchCount;
                auto switchInst = inst.as<SwitchInst>();

                Block* targetBlock = switchInst->defaultTarget();
                const auto val = getInt(0);
                if(auto it = switchInst->edges().find(val); it != switchInst->edges().end()) {
                    targetBlock = it->second;
                }

                currentExecCtx.predBlock = currentExecCtx.block;
                currentExecCtx.block = targetBlock;
                currentExecCtx.execIter = targetBlock->instructions().begin();
                if(step.get()) {
                    currentExecCtx.block->dumpLabeled(std::cerr, Noop{});
                }
                break;
            }
            case InstructionID::Load: {
                ++loadCount;

                const auto ptr = getPtr(0);
                addValue(inst, memCtx.loadValue(ptr, inst.getType()));
                break;
            }
            case InstructionID::Store: {
                ++storeCount;

                const auto ptr = getPtr(0);
                memCtx.storeValue(ptr, operands[1], inst.getOperand(1)->getType());
                if(step.get()) {
                    auto& out = std::cerr;
                    inst.dump(out, Noop{});
                    out << " : "sv;
                    dumpValue(operands[1]);
                    out << " -> "sv;
                    dumpValue(operands[0]);
                    out << '\n';
                }
                break;
            }
            case InstructionID::Add: {
                addInt(getInt(0) + getInt(1));
                break;
            }
            case InstructionID::Sub: {
                addInt(getInt(0) - getInt(1));
                break;
            }
            case InstructionID::Mul: {
                addInt(getInt(0) * getInt(1));
                break;
            }
            case InstructionID::SDiv: {
                const auto val = getInt(1);
                if(!val)
                    return SimulationFailReason::DividedByZero;
                addInt(getInt(0) / val);
                break;
            }
            case InstructionID::UDiv: {
                const auto val = getUInt(1);
                if(!val)
                    return SimulationFailReason::DividedByZero;
                addUInt(getUInt(0) / val);
                break;
            }
            case InstructionID::SRem: {
                const auto val = getInt(1);
                if(!val)
                    return SimulationFailReason::DividedByZero;
                addInt(getInt(0) % val);
                break;
            }
            case InstructionID::URem: {
                const auto val = getUInt(1);
                if(!val)
                    return SimulationFailReason::DividedByZero;
                addUInt(getUInt(0) % val);
                break;
            }
            case InstructionID::Neg: {
                addInt(-getInt(0));
                break;
            }
            case InstructionID::Abs: {
                addInt(std::abs(getInt(0)));
                break;
            }
            case InstructionID::And: {
                addUInt(getUInt(0) & getUInt(1));
                break;
            }
            case InstructionID::Or: {
                addUInt(getUInt(0) | getUInt(1));
                break;
            }
            case InstructionID::Xor: {
                addUInt(getUInt(0) ^ getUInt(1));
                break;
            }
            case InstructionID::Shl: {
                addUInt(getUInt(0) << getUInt(1));
                break;
            }
            case InstructionID::LShr: {
                addUInt(getUInt(0) >> getUInt(1));
                break;
            }
            case InstructionID::AShr: {
                addInt(getInt(0) >> getInt(1));
                break;
            }
            case InstructionID::SMin: {
                addInt(std::min(getInt(0), getInt(1)));
                break;
            }
            case InstructionID::SMax: {
                addInt(std::max(getInt(0), getInt(1)));
                break;
            }
            case InstructionID::FAdd: {
                addFP(getFP(0) + getFP(1));
                break;
            }
            case InstructionID::FSub: {
                addFP(getFP(0) - getFP(1));
                break;
            }
            case InstructionID::FMul: {
                addFP(getFP(0) * getFP(1));
                break;
            }
            case InstructionID::FDiv: {
                addFP(getFP(0) / getFP(1));
                break;
            }
            case InstructionID::FNeg: {
                addFP(-getFP(0));
                break;
            }
            case InstructionID::FAbs: {
                addFP(std::fabs(getFP(0)));
                break;
            }
            case InstructionID::FFma: {
                addFP(fma(getFP(0), getFP(1), getFP(2)));
                break;
            }
            case InstructionID::ICmp: {
                addBoolean(doCompare(inst.as<CompareInst>()->getOp(), getInt(0), getInt(1)));
                break;
            }
            case InstructionID::FCmp: {
                addBoolean(doCompareFP(inst.as<CompareInst>()->getOp(), getFP(0), getFP(1)));
                break;
            }
            case InstructionID::SExt:
            case InstructionID::SignedTrunc: {
                addInt(getInt(0));
                --instructionCount;
                break;
            }
            case InstructionID::ZExt:
            case InstructionID::UnsignedTrunc: {
                addUInt(getUInt(0));
                --instructionCount;
                break;
            }
            case InstructionID::Bitcast: {
                const auto f32 = FloatingPointType::get(true);
                const auto i32 = IntegerType::get(32);
                if(inst.getType()->isSame(i32) && inst.getOperand(0)->getType()->isSame(f32)) {
                    const auto val = static_cast<float>(getFP(0));
                    int32_t ival;
                    memcpy(&ival, &val, sizeof(int32_t));
                    addInt(ival);
                } else
                    reportNotImplemented(CMMC_LOCATION());
                break;
            }
            case InstructionID::F2U: {
                addUInt(static_cast<uintmax_t>(getFP(0)));
                break;
            }
            case InstructionID::F2S: {
                addInt(static_cast<intmax_t>(getFP(0)));
                break;
            }
            case InstructionID::U2F: {
                addFP(static_cast<double>(getUInt(0)));
                break;
            }
            case InstructionID::S2F: {
                addFP(static_cast<double>(getInt(0)));
                break;
            }
            case InstructionID::FCast: {
                addFP(getFP(0));
                break;
            }
            case InstructionID::Alloc: {
                if(auto it = currentExecCtx.cachedAllocs.find(&inst); it != currentExecCtx.cachedAllocs.cend()) {
                    // allocas in loop --> reuse
                    addPtr(it->second);
                } else {
                    const auto type = inst.getType()->as<PointerType>()->getPointee();
                    const auto ptr = memCtx.stackPush(type->getSize(dataLayout), type->getAlignment(dataLayout));
                    addPtr(ptr);
                    assert(!currentExecCtx.stackAllocs.count(ptr));
                    currentExecCtx.stackAllocs.emplace(ptr, &inst);
                    currentExecCtx.cachedAllocs.emplace(&inst, ptr);
                }
                --instructionCount;
                break;
            }
            case InstructionID::GetElementPtr: {
                auto basePtr = getPtr(static_cast<uint32_t>(operands.size() - 1U));
                const auto oldPtr = basePtr;
                auto baseType = inst.lastOperand()->getType();
                for(uint32_t idx = 0; idx + 1 < operands.size(); ++idx) {
                    const auto operand = inst.getOperand(idx);
                    const auto type = operand->getType();
                    if(type->isInteger()) {
                        if(baseType->isPointer()) {
                            baseType = baseType->as<PointerType>()->getPointee();
                        } else if(baseType->isArray()) {
                            baseType = baseType->as<ArrayType>()->getElementType();
                        } else
                            reportUnreachable(CMMC_LOCATION());
                        basePtr = static_cast<uintptr_t>(static_cast<intptr_t>(basePtr) +
                                                         static_cast<intptr_t>(getInt(idx)) *
                                                             static_cast<intptr_t>(baseType->getSize(dataLayout)));
                    } else if(auto offset = dynamic_cast<ConstantOffset*>(operand)) {
                        const auto structType = baseType->as<StructType>();
                        baseType = structType->getFieldType(offset);
                        basePtr += structType->getFieldOffset(offset, dataLayout);
                    }
                }

                addPtr(basePtr);
                if(oldPtr == basePtr)
                    --instructionCount;
                break;
            }
            case InstructionID::PtrCast: {
                addValue(inst, operands[0]);
                --instructionCount;
                break;
            }
            case InstructionID::PtrToInt: {
                if(dataLayout.getPointerSize() != sizeof(uintptr_t))
                    return SimulationFailReason::UnsupportedTarget;
                addUInt(getPtr(0));
                --instructionCount;
                break;
            }
            case InstructionID::IntToPtr: {
                if(dataLayout.getPointerSize() != sizeof(uintptr_t))
                    return SimulationFailReason::UnsupportedTarget;
                addPtr(getUInt(0));
                --instructionCount;
                break;
            }
            case InstructionID::Select: {
                addValue(inst, getUInt(0) ? operands[1] : operands[2]);
                break;
            }
            case InstructionID::Call: {
                ++callCount;
                if(execCtx.size() >= mMaxRecursiveDepth)
                    return SimulationFailReason::ExceedMaxRecursiveDepth;

                const auto callee = std::get<Function*>(operands.back());
                if(callee->attr().hasAttr(FunctionAttribute::NoReturn))
                    return SimulationFailReason::EnterNoreturnFunc;
                operands.pop_back();

                switch(callee->getIntrinsic()) {
                    case Intrinsic::none: {
                        if(callee->blocks().empty()) {
                            // runtime func
                            const auto symbol = callee->getSymbol().prefix();
                            if(symbol == "cmmcCacheLookup"sv) {
                                const auto base = getPtr(0);
                                memCtx.storeValue(base + 12, static_cast<int32_t>(0));
                                addPtr(base);
                                break;
                            }

                            if(!ioCtx)
                                return SimulationFailReason::RuntimeError;

                            if(symbol == "read"sv || symbol == "getint"sv) {
                                int x = 0;
                                ioCtx->stdinStream.get("%d", x);
                                addInt(x);
                            } else if(symbol == "write"sv || symbol == "putint"sv) {
                                const auto x = static_cast<int>(getInt(0));
                                ioCtx->stdoutStream.put("%d", x);
                                if(symbol == "write"sv)
                                    ioCtx->stdoutStream.putch(' ');
                            } else if(symbol == "getch"sv) {
                                char ch = 0;
                                ioCtx->stdinStream.get("%c", ch);
                                addInt(ch);
                            } else if(symbol == "putch"sv) {
                                const auto ch = static_cast<int>(getInt(0));
                                ioCtx->stdoutStream.put("%c", ch);
                            } else if(symbol == "getarray"sv) {
                                int size = 0;
                                ioCtx->stdinStream.get("%d", size);

                                const auto ptr = getPtr(0);
                                for(int idx = 0; idx < size; ++idx) {
                                    int val = 0;
                                    ioCtx->stdinStream.get("%d", val);
                                    memCtx.storeValue(ptr + static_cast<uint32_t>(idx) * sizeof(int), val);
                                }

                                addUInt(static_cast<uintmax_t>(size));
                            } else if(symbol == "putarray"sv) {
                                const auto size = static_cast<int>(getUInt(0));
                                const auto ptr = getPtr(1);

                                ioCtx->stdoutStream.put("%d:", size);
                                for(int idx = 0; idx < size; ++idx) {
                                    const auto val = memCtx.loadValue<int>(ptr + static_cast<uint32_t>(idx) * sizeof(int));
                                    ioCtx->stdoutStream.put(" %d", val);
                                }
                                ioCtx->stdoutStream.put("\n");
                            } else if(symbol == "getfloat"sv) {
                                float val = 0.0F;
                                ioCtx->stdinStream.get("%a", val);
                                addFP(val);
                            } else if(symbol == "putfloat"sv) {
                                const auto val = static_cast<float>(getFP(0));
                                ioCtx->stdoutStream.put("%a", val);
                            } else if(symbol == "getfarray"sv) {
                                int size = 0;
                                ioCtx->stdinStream.get("%d", size);

                                const auto ptr = getPtr(0);
                                for(int idx = 0; idx < size; ++idx) {
                                    float val = 0.0F;
                                    ioCtx->stdinStream.get("%a", val);
                                    memCtx.storeValue(ptr + static_cast<uint32_t>(idx) * sizeof(float), val);
                                }

                                addUInt(static_cast<uintmax_t>(size));
                            } else if(symbol == "putfarray"sv) {
                                const auto size = static_cast<int>(getUInt(0));
                                const auto ptr = getPtr(1);

                                ioCtx->stdoutStream.put("%d:", size);
                                for(int idx = 0; idx < size; ++idx) {
                                    const auto val = memCtx.loadValue<float>(ptr + static_cast<uint32_t>(idx) * sizeof(float));
                                    ioCtx->stdoutStream.put(" %a", val);
                                }
                                ioCtx->stdoutStream.put("\n");
                            } else if(symbol == "starttime"sv) {
                                // ignore
                            } else if(symbol == "stoptime"sv) {
                                // ignore
                            } else
                                reportUnreachable(CMMC_LOCATION());
                        } else {
                            BlockContext blockCtx;
                            blockCtx.caller = &inst;
                            blockCtx.block = callee->entryBlock();
                            blockCtx.predBlock = nullptr;

                            for(uint32_t idx = 0; idx < callee->args().size(); ++idx)
                                blockCtx.operands.emplace(callee->getArg(idx), operands[idx]);

                            blockCtx.execIter = blockCtx.block->instructions().begin();
                            if(step.get()) {
                                std::cerr << "Call ";
                                callee->dumpAsOperand(std::cerr);
                                std::cerr << " with";
                                for(uint32_t idx = 0; idx < callee->args().size(); ++idx) {
                                    auto param = callee->getArg(idx);
                                    auto& arg = operands[idx];
                                    std::cerr << ' ';
                                    param->dumpAsOperand(std::cerr);
                                    std::cerr << "->"sv;
                                    dumpValue(arg);
                                }
                                std::cerr << '\n';
                                callee->dump(std::cerr, Noop{});
                                blockCtx.block->dumpLabeled(std::cerr, Noop{});
                            }
                            execCtx.push_back(std::move(blockCtx));
                        }
                        break;
                    }
                    case Intrinsic::memset: {
                        const auto ptr = getPtr(0);
                        const auto size =
                            getUInt(1) * inst.getOperand(0)->getType()->as<PointerType>()->getPointee()->getFixedSize();
                        memCtx.memReset(ptr, size, static_cast<std::byte>(0));
                        break;
                    }
                    case Intrinsic::memcpy: {
                        const auto dest = getPtr(0);
                        const auto src = getPtr(1);
                        const auto size = getUInt(2);
                        memCtx.memCopy(dest, src, size);
                        break;
                    }
                    default:
                        reportNotImplemented(CMMC_LOCATION());
                }

                break;
            }
            default:
                reportNotImplemented(CMMC_LOCATION());
                break;
        }

        /*
        if(step.get()) {
            std::cin.get();
        }
        */
    }
}

OutputStream::OutputStream(const std::string& path) {
    mFile = fopen(path.c_str(), "w");  // NOLINT
    if(!mFile)
        DiagnosticsContext::get().attach<Reason>("Failed to open output file").reportFatal();
}

OutputStream::~OutputStream() {
    fclose(mFile);  // NOLINT
}

InputStream::InputStream(const std::string& path) {
    mFile = fopen(path.c_str(), "r");  // NOLINT
    if(!mFile)
        DiagnosticsContext::get().attach<Reason>("Failed to open input file").reportFatal();
}

InputStream::~InputStream() {
    fclose(mFile);  // NOLINT
}

CMMC_NAMESPACE_END
