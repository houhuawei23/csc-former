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

#include "../../../cmmc/IR/Block.hpp"
#include "../../../cmmc/IR/Instruction.hpp"
#include "../../../cmmc/Transforms/Compatibility/Compatibility.hpp"

CMMC_NAMESPACE_BEGIN

void canonicalizeBranchCompare(Function& func, AnalysisPassManager&) {
    // deGVN
    for(auto block : func.blocks()) {
        const auto terminator = block->getTerminator();
        if(terminator->getInstID() != InstructionID::ConditionalBranch)
            continue;
        const auto cond = terminator->getOperand(0);
        if(!cond->isArgument())
            continue;
        const auto root = cond;
        if(!root->is<CompareInst>())
            continue;
        const auto newInst = root->as<Instruction>()->clone();
        auto& instructions = block->instructions();
        newInst->insertBefore(block, std::prev(instructions.end()));
    }
}

CMMC_NAMESPACE_END
