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
#include "../../cmmc/CodeGen/CodeGenUtils.hpp"
#include "../../cmmc/CodeGen/DataLayout.hpp"
#include "../../cmmc/CodeGen/ISelInfo.hpp"
#include "../../cmmc/CodeGen/InstInfo.hpp"
#include "../../cmmc/CodeGen/Lowering.hpp"
#include "../../cmmc/CodeGen/MIR.hpp"
#include "../../cmmc/CodeGen/Target.hpp"
#include "../../cmmc/IR/Block.hpp"
#include "../../cmmc/IR/ConstantValue.hpp"
#include "../../cmmc/IR/Type.hpp"
#include "../../cmmc/Support/Diagnostics.hpp"
#include "../../cmmc/Transforms/TransformPass.hpp"
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

CMMC_MIR_NAMESPACE_BEGIN

struct StackObjectInterval final {
    uint32_t begin;
    uint32_t end;
};

using Intervals = std::unordered_map<MIROperand, StackObjectInterval, MIROperandHasher>;
struct Slot final {
    uint32_t color;
    uint32_t end;

    bool operator<(const Slot& rhs) const noexcept {
        return end > rhs.end;
    }
};

static std::pair<uint32_t, std::unordered_map<MIROperand, uint32_t, MIROperandHasher>>
calcIntervalPartition(std::vector<std::pair<MIROperand, StackObjectInterval>>& intervals) {
    uint32_t colorCount = 0;
    std::unordered_map<MIROperand, uint32_t, MIROperandHasher> color;

    std::sort(intervals.begin(), intervals.end(),
              [](const auto& lhs, const auto& rhs) { return lhs.second.begin < rhs.second.begin; });

    std::priority_queue<Slot> slots;

    for(auto& [operand, interval] : intervals) {
        if(slots.empty() || slots.top().end > interval.begin) {
            // create new slot
            const auto col = colorCount++;
            slots.push({ col, interval.end });
            color.emplace(operand, col);
        } else {
            auto top = slots.top();
            color.emplace(operand, top.color);
            top.end = interval.end;
            slots.pop();
            slots.push(top);
        }
    }

    // std::cerr << "begin" << std::endl;

    // for(auto& [operand, interval] : intervals) {
    //     std::cerr << 'm' << operand.id << ' ' << interval.begin << '-' << interval.end << ' ' << color.at(operand) <<
    //     std::endl;
    // }

    // std::cerr << "end" << std::endl;

    return { colorCount, std::move(color) };
}

// coloring
static std::unordered_map<MIROperand, uint32_t, MIROperandHasher>
renameStackObjects(MIRFunction& func, OptimizationLevel optLevel, const CodeGenContext& ctx) {
    std::unordered_map<MIROperand, uint32_t, MIROperandHasher> mapping;  // same size & alignment

    // FIXME
    /*
    if(optLevel >= OptimizationLevel::O1) {
        const auto getStorageKey = [&](const MIROperand& op) {
            const auto type = ctx.registerInfo->getCanonicalizedRegisterType(op.type());
            const auto size = getOperandSize(type);
            const auto alignment = size;
            const auto key = static_cast<uint32_t>(size) * 1024 + static_cast<uint32_t>(alignment);
            return key;
        };

        // local reuse for spilled regs
        {
            std::unordered_set<MIROperand, MIROperandHasher> uniqueStackObjects;
            {
                std::unordered_map<MIROperand, MIRBasicBlock*, MIROperandHasher> ownerOfStackObjectsForSpilledRegs;
                for(auto& block : func.blocks()) {
                    for(auto& inst : block->instructions()) {
                        if(inst.opcode() == InstLoadRegFromStack || inst.opcode() == InstStoreRegToStack) {
                            const auto stackObject = inst.getOperand(1);

                            if(func.stackObjects().at(stackObject).usage == StackObjectUsage::RegSpill) {
                                if(auto iter = ownerOfStackObjectsForSpilledRegs.find(stackObject);
                                   iter != ownerOfStackObjectsForSpilledRegs.cend())
                                    iter->second = nullptr;
                                else {
                                    ownerOfStackObjectsForSpilledRegs.emplace(stackObject, block.get());
                                }
                            }
                        }
                    }
                }
                for(auto& [obj, owner] : ownerOfStackObjectsForSpilledRegs) {
                    if(owner) {
                        uniqueStackObjects.insert(obj);
                        // std::cerr << 'm' << obj.id << std::endl;
                    }
                }
            }

            uint32_t idx = 0;
            for(auto& [ref, stackObject] : func.stackObjects()) {
                assert(isStackObject(ref.reg()));
                const auto usage = stackObject.usage;
                if(usage != StackObjectUsage::Argument && usage != StackObjectUsage::CalleeArgument &&
                   usage != StackObjectUsage::RegSpill) {
                    mapping.emplace(ref, idx++);
                }
            }
            for(auto& block : func.blocks()) {
                auto& instructions = block->instructions();
                const StackObjectInterval initialInterval{ static_cast<uint32_t>(instructions.size()), 0 };

                Intervals intervals;
                uint32_t id = 0;
                auto updateInterval = [&](const MIROperand& obj) {
                    if(auto iter = intervals.find(obj); iter != intervals.cend()) {
                        auto& interval = iter->second;
                        interval.begin = std::min(interval.begin, id);
                        interval.end = std::max(interval.end, id + 1);
                    }
                };

                // save/restore
                for(auto& inst : instructions) {
                    if(inst.opcode() == InstLoadRegFromStack || inst.opcode() == InstStoreRegToStack) {
                        const auto stackObject = inst.getOperand(1);
                        if(mapping.count(stackObject))
                            continue;
                        if(!uniqueStackObjects.count(stackObject)) {
                            mapping.emplace(stackObject, idx++);
                        } else {
                            intervals.emplace(stackObject, initialInterval);
                        }
                        updateInterval(stackObject);
                    }
                    ++id;
                }

                // group by size & alignments
                std::unordered_map<uint32_t, std::vector<std::pair<MIROperand, StackObjectInterval>>> groups;
                for(auto& [obj, interval] : intervals) {
                    groups[getStorageKey(obj)].emplace_back(obj, interval);
                }

                for(auto& [key, groupedIntervals] : groups) {
                    CMMC_UNUSED(key);
                    auto [colorCount, color] = calcIntervalPartition(groupedIntervals);

                    for(auto& [obj, col] : color)
                        mapping.emplace(obj, idx + col);

                    idx += colorCount;
                }
            }
        }

        // global reuse: incremental graph coloring
        std::unordered_map<uint32_t, std::map<uint32_t, std::unordered_set<uint32_t>>> inferenceGraph;

        constexpr size_t maxGraphSize = 5000;

        for(auto& block : func.blocks()) {
            std::unordered_map<uint32_t, std::vector<uint32_t>> ids;
            std::unordered_set<uint32_t> proccessed;
            for(auto obj : block->usedStackObjects()) {
                if(stack.getType(obj)->isStackStorage())
                    continue;

                const auto id = mapping.at(obj);
                if(proccessed.count(id))
                    continue;

                ids[getStorageKey(obj)].push_back(id);
                proccessed.insert(id);
            }

            // build inference graph
            for(auto& [key, arr] : ids) {
                if(arr.size() > maxGraphSize)
                    return mapping;  // The inference graph is huge

                auto& graph = inferenceGraph[key];
                std::sort(arr.begin(), arr.end());
                for(uint32_t i = 0; i < arr.size(); ++i) {
                    auto& neighbours = graph[arr[i]];
                    for(uint32_t j = 0; j < i; ++j) {
                        neighbours.insert(arr[j]);  // high -> low
                    }
                }
            }
        }

        // calculate mex function
        std::unordered_map<uint32_t, uint32_t> remapping;
        uint32_t colorBase = 0;

        for(auto& [key, graph] : inferenceGraph) {
            std::unordered_map<uint32_t, uint32_t> color;
            uint32_t colorCount = 0;  // == maximum degrees + 1

            for(auto& [u, neighbours] : graph) {
                uint32_t current = 0;

                std::set<uint32_t> greater;
                const auto maxMex = static_cast<uint32_t>(neighbours.size());

                for(auto v : neighbours) {
                    const auto col = color.at(v);
                    if(col < current || col >= maxMex) {
                        continue;
                    }
                    if(col == current) {
                        ++current;
                        while(!greater.empty() && *greater.begin() == current) {
                            greater.erase(greater.begin());
                            ++current;
                        }
                    } else {
                        greater.insert(col);
                    }
                }

                color.emplace(u, current);
                colorCount = std::max(colorCount, current + 1);
            }

            for(auto [k, v] : color)
                remapping.emplace(k, v + colorBase);
            colorBase += colorCount;
        }


        std::unordered_map<MIROperand, uint32_t, MIROperandHasher> newMapping;
        for(auto& [obj, id] : mapping) {
            if(stack.getType(obj)->isStackStorage()) {
                newMapping.emplace(obj, colorBase++);
            } else {
                newMapping.emplace(obj, remapping.at(id));
            }
        }

        newMapping.swap(mapping);
    } else {
    */
    CMMC_UNUSED(optLevel);
    CMMC_UNUSED(ctx);
    CMMC_UNUSED(calcIntervalPartition);
    uint32_t idx = 0;
    for(auto& [ref, stackObject] : func.stackObjects()) {
        assert(isStackObject(ref.reg()));
        const auto usage = stackObject.usage;
        if(usage != StackObjectUsage::Argument && usage != StackObjectUsage::CalleeArgument) {
            mapping.emplace(ref, idx++);
        }
    }
    //}

    return mapping;
}

// Stack Layout
// ------------------------ <----- Last sp
// Locals & Spills
// ------------------------
// Return Address
// ------------------------
// Callee Arguments
// ------------------------ <----- Current sp

static void removeUnusedSpillStackObjects(MIRFunction& func) {
    std::unordered_set<MIROperand, MIROperandHasher> stackObjects;
    for(auto& [ref, stackObject] : func.stackObjects()) {
        assert(isStackObject(ref.reg()));
        if(stackObject.usage == StackObjectUsage::RegSpill)
            stackObjects.emplace(ref);
    }
    for(auto& block : func.blocks()) {
        for(auto& inst : block->instructions()) {
            if(inst.opcode() == InstLoadRegFromStack) {
                stackObjects.erase(inst.getOperand(1));
            }
        }
    }
    // remove dead store
    for(auto& block : func.blocks()) {
        block->instructions().remove_if(
            [&](auto& inst) { return inst.opcode() == InstStoreRegToStack && stackObjects.count(inst.getOperand(1)); });
    }
    for(auto object : stackObjects)
        func.stackObjects().erase(object);
}

void allocateStackObjects(MIRFunction& func, CodeGenContext& ctx, bool isNonLeafFunc, OptimizationLevel optLevel) {
    while(genericPeepholeOpt(func, ctx))
        ;
    // callee saved
    std::unordered_set<MIROperand, MIROperandHasher> overwrited;
    for(auto& block : func.blocks())
        forEachDefOperands(*block, ctx, [&](const MIROperand& op) {
            if(op.isUnused())
                return;
            if(op.isReg() && isISAReg(op.reg()) && ctx.frameInfo.isCalleeSaved(op)) {
                overwrited.insert(MIROperand::asISAReg(op.reg(), ctx.registerInfo->getCanonicalizedRegisterType(op.type())));
            }
        });
    const auto preAllocatedBase =
        ctx.frameInfo.insertPrologueEpilogue(func, overwrited, ctx, isNonLeafFunc, ctx.registerInfo->getReturnAddressRegister());
    removeUnusedSpillStackObjects(func);
    // func.dump(std::cerr, target);

    int32_t allocationBase = 0;
    const auto spAlignment = static_cast<int32_t>(ctx.frameInfo.getStackPointerAlignment(isNonLeafFunc));

    const auto alignTo = [&](int32_t alignment) {
        assert(alignment <= spAlignment);
        allocationBase = (allocationBase + alignment - 1) / alignment * alignment;
    };
    // callee arguments
    for(auto& [ref, stackObject] : func.stackObjects()) {
        assert(isStackObject(ref.reg()));
        if(stackObject.usage == StackObjectUsage::CalleeArgument) {
            allocationBase = std::max(allocationBase, stackObject.offset + static_cast<int32_t>(stackObject.size));
        }
    }

    alignTo(spAlignment);

    // locals
    // TODO: put frequently used locals in the bottom?
    {
        CMMC_UNUSED(renameStackObjects);
        CMMC_UNUSED(optLevel);
        // const auto mapping = renameStackObjects(func, optLevel, ctx);
        // std::unordered_map<uint32_t, int32_t> slots;

        // for(auto& [stackObject, color] : mapping) {
        //     auto& obj = func.stackObjects().at(stackObject);
        //     if(auto iter = slots.find(color); iter != slots.cend()) {
        //         obj.offset = iter->second;
        //     } else {
        //         alignTo(static_cast<int32_t>(obj.alignment));
        //         slots.emplace(color, allocationBase);
        //         obj.offset = allocationBase;
        //         allocationBase += static_cast<int32_t>(obj.size);
        //     }
        // }

        // callee-saved
        std::vector<MIROperand> calleeSaved;
        for(auto& [p, s] : func.stackObjects()) {
            if(s.usage == StackObjectUsage::CalleeSaved) {
                calleeSaved.push_back(p);
            }
        }
        std::sort(calleeSaved.begin(), calleeSaved.end(),
                  [&](const MIROperand& lhs, const MIROperand& rhs) { return lhs.reg() > rhs.reg(); });

        auto allocateFor = [&](StackObject& obj) {
            alignTo(static_cast<int32_t>(obj.alignment));
            obj.offset = allocationBase;
            allocationBase += static_cast<int32_t>(obj.size);
        };
        for(auto& obj : calleeSaved) {
            allocateFor(func.stackObjects().at(obj));
        }
        for(auto& [p, s] : func.stackObjects()) {
            if(s.usage == StackObjectUsage::Local || s.usage == StackObjectUsage::RegSpill)
                allocateFor(s);
        }
    }

    alignTo(spAlignment);
    const auto gap = (preAllocatedBase + spAlignment - 1) / spAlignment * spAlignment - preAllocatedBase;
    auto stackSize = allocationBase + gap;
    assert((stackSize + preAllocatedBase) % spAlignment == 0);
    for(auto& [ref, stackObject] : func.stackObjects()) {
        assert(isStackObject(ref.reg()));
        if(stackObject.usage == StackObjectUsage::Argument) {
            stackObject.offset += stackSize + preAllocatedBase;
        }
    }

    // prolog & epilog
    ctx.frameInfo.emitPostSAPrologue(*func.blocks().front(), ctx, stackSize);

    for(auto& block : func.blocks()) {
        const auto& terminator = block->instructions().back();
        auto& instInfo = ctx.instInfo.getInstInfo(terminator);
        if(requireFlag(instInfo.getInstFlag(), InstFlagReturn)) {
            ctx.frameInfo.emitPostSAEpilogue(*block, ctx, stackSize);
        }
    }
}

CMMC_MIR_NAMESPACE_END
