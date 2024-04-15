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

// S:
//   cbr cond, A, B
// A:
//   xxx
//   br B
// B:
//   val = phi [A, v1], [S, v2], ...
// ->
// S:
//   br A
// A:
//   xxx
//   t = select cond, v1, v2
//   br B
// B:
//   val = phi [A, t], ...

#include "../../../cmmc/Analysis/AnalysisPass.hpp"
#include "../../../cmmc/Analysis/CFGAnalysis.hpp"
#include "../../../cmmc/CodeGen/Target.hpp"
#include "../../../cmmc/IR/ConstantValue.hpp"
#include "../../../cmmc/IR/Function.hpp"
#include "../../../cmmc/IR/IRBuilder.hpp"
#include "../../../cmmc/IR/Instruction.hpp"
#include "../../../cmmc/Transforms/TransformPass.hpp"
#include "../../../cmmc/Transforms/Util/PatternMatch.hpp"
#include <cstdint>
#include <iterator>
#include <unordered_map>

CMMC_NAMESPACE_BEGIN

constexpr size_t inlineInstThreshold = 4;
constexpr size_t inlineLoadThreshold = 1;

class Branch2Select final : public TransformPass<Function> {
    static bool canFold(Block& block) {
        if(block.instructions().size() > inlineInstThreshold)
            return false;
        if(block.getTerminator()->getInstID() != InstructionID::Branch)
            return false;
        if(block.getTerminator()->as<BranchInst>()->getTrueTarget() == &block)
            return false;

        // TODO: check by costs of instructions
        size_t loadCount = 0;
        for(auto& inst : block.instructions()) {
            switch(inst.getInstID()) {
                case InstructionID::Phi:
                case InstructionID::Store:
                case InstructionID::AtomicAdd:
                case InstructionID::Call:
                // It is not safe to speculate division, since SIGFPE may be raised.
                case InstructionID::SDiv:
                case InstructionID::UDiv:
                case InstructionID::SRem:
                case InstructionID::URem:
                    return false;
                case InstructionID::Load: {
                    const auto addr = inst.getOperand(0);
                    if(addr->isGlobal() || addr->is<StackAllocInst>()) {
                        if(++loadCount > inlineLoadThreshold)
                            return false;
                    } else
                        return false;
                } break;
                default:
                    break;
            }
        }
        return true;
    }

public:
    bool run(Function& func, AnalysisPassManager& analysis) const override {
        if(!analysis.module().getTarget().isNativeSupported(InstructionID::Select))
            return false;
        auto& cfg = analysis.get<CFGAnalysis>(func);

        bool modified = false;
        for(auto block : func.blocks()) {
            if(!canFold(*block))
                continue;

            const auto blockA = block;
            auto& predBlockA = cfg.predecessors(blockA);
            if(predBlockA.size() != 1)
                continue;
            const auto blockS = predBlockA[0];
            if(blockS->getTerminator()->getInstID() != InstructionID::ConditionalBranch)
                continue;
            auto terminatorBlockS = blockS->getTerminator()->as<BranchInst>();
            auto trueTarget = terminatorBlockS->getTrueTarget();
            auto falseTarget = terminatorBlockS->getFalseTarget();
            const auto blockB = blockA->getTerminator()->as<BranchInst>()->getTrueTarget();
            if(!((trueTarget == blockA && falseTarget == blockB) || (trueTarget == blockB && falseTarget == blockA)))
                continue;
            if(trueTarget == blockB)
                trueTarget = blockS;
            else
                falseTarget = blockS;

            auto& instsBlockB = blockB->instructions();
            if(instsBlockB.front()->getInstID() != InstructionID::Phi)
                continue;

            for(auto iter = instsBlockB.begin(); iter != instsBlockB.end();) {
                auto next = std::next(iter);

                if(iter->getInstID() == InstructionID::Phi) {
                    auto phi = iter->as<PhiInst>();
                    auto select = make<SelectInst>(terminatorBlockS->getOperand(0), phi->incomings().at(trueTarget)->value,
                                                   phi->incomings().at(falseTarget)->value);

                    select->insertBefore(blockA, std::prev(blockA->instructions().end()));
                    phi->removeSource(falseTarget);
                    phi->removeSource(trueTarget);
                    phi->addIncoming(blockA, select);
                } else
                    break;

                iter = next;
            }

            auto& instsBlockS = blockS->instructions();
            instsBlockS.pop_back();
            auto newTermiantor = make<BranchInst>(blockA);
            newTermiantor->insertBefore(blockS, instsBlockS.end());

            modified = true;
        }

        return modified;
    }

    [[nodiscard]] std::string_view name() const noexcept override {
        return "Branch2Select"sv;
    }
};

CMMC_TRANSFORM_PASS(Branch2Select);

CMMC_NAMESPACE_END
