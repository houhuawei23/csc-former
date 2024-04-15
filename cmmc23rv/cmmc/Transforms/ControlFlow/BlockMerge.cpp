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

// func foo(int a, int b) -> int:
// entry(int a, int b):
//     int c = a + b;
//     br b1(c);
// b1(int c):
//     return c;
// ==>
// func foo(int a, int b) -> int:
// entry(int a, int b):
//     int c = a + b;
//     return c;

#include "../../../cmmc/Analysis/AnalysisPass.hpp"
#include "../../../cmmc/Analysis/DominateAnalysis.hpp"
#include "../../../cmmc/IR/Block.hpp"
#include "../../../cmmc/IR/Function.hpp"
#include "../../../cmmc/IR/Instruction.hpp"
#include "../../../cmmc/Transforms/TransformPass.hpp"
#include "../../../cmmc/Transforms/Util/BlockUtil.hpp"
#include "../../../cmmc/Transforms/Util/PatternMatch.hpp"
#include <cstdint>
#include <iostream>
#include <unordered_map>

CMMC_NAMESPACE_BEGIN

class BlockMerge final : public TransformPass<Function> {
public:
    bool run(Function& func, AnalysisPassManager& analysis) const override {
        const auto& dom = analysis.get<DominateAnalysis>(func);
        auto tryMerge = [&] {
            std::unordered_map<Block*, uint32_t> blockRef;
            for(auto& block : func.blocks()) {
                const auto inst = block->getTerminator();
                if(!inst->isBranch())
                    continue;
                if(inst->getInstID() == InstructionID::Switch) {
                    auto targets = inst->as<SwitchInst>()->getUniqueSuccessors();
                    for(auto target : targets)
                        ++blockRef[target];
                } else {
                    const auto branch = inst->as<BranchInst>();
                    ++blockRef[branch->getTrueTarget()];
                    if(branch->getFalseTarget() && branch->getTrueTarget() != branch->getFalseTarget())
                        ++blockRef[branch->getFalseTarget()];
                }
            }
            std::unordered_set<Block*> deferred;
            for(auto block : func.blocks()) {
                if(deferred.count(block))
                    continue;  // merged
                const auto terminator = block->getTerminator();
                if(terminator->getInstID() != InstructionID::Branch)
                    continue;
                const auto branch = terminator->as<BranchInst>();
                const auto target = branch->getTrueTarget();
                if(block == target)
                    continue;
                if(!dom.dominate(block, target))
                    continue;

                assert(blockRef[target] >= 1);
                if(blockRef.at(target) == 1) {
                    auto& instsB = target->instructions();
                    if(instsB.front()->getInstID() == InstructionID::Phi)
                        continue;

                    auto& instsA = block->instructions();
                    instsA.pop_back();

                    for(auto iter = instsB.begin(); iter != instsB.end();) {
                        auto next = std::next(iter);
                        iter->insertBefore(block, instsA.end());
                        iter = next;
                    }

                    const auto newTerminator = block->getTerminator();
                    if(newTerminator->isBranch()) {
                        if(newTerminator->getInstID() == InstructionID::Switch) {
                            const auto newSwitch = newTerminator->as<SwitchInst>();
                            auto targets = newSwitch->getUniqueSuccessors();
                            for(auto succ : targets)
                                retargetBlock(succ, target, block);  // NOLINT
                        } else {
                            const auto newBranch = newTerminator->as<BranchInst>();
                            retargetBlock(newBranch->getTrueTarget(), target, block);
                            if(newBranch->getFalseTarget() && newBranch->getTrueTarget() != newBranch->getFalseTarget())
                                retargetBlock(newBranch->getFalseTarget(), target, block);
                        }
                    }
                    deferred.insert(target);
                }
            }

            for(auto block : deferred)
                func.blocks().remove(block);
            return !deferred.empty();
        };

        bool modified = false;
        while(tryMerge())
            modified = true;
        return modified;
    }

    [[nodiscard]] std::string_view name() const noexcept override {
        return "BlockMerge"sv;
    }
};

CMMC_TRANSFORM_PASS(BlockMerge);

CMMC_NAMESPACE_END
