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

// internal int @a;
// internal func @foo() -> i32;
// func @main() -> i32 {
// ^entry():
//     ret i32 0;
// }
// =>
// func @main() -> i32 {
// ^entry():
//     ret i32 0;
// }

#include <algorithm>
#include "../../../cmmc/IR/Function.hpp"
#include "../../../cmmc/IR/Instruction.hpp"
#include "../../../cmmc/IR/Value.hpp"
#include "../../../cmmc/Transforms/TransformPass.hpp"
#include <cstdint>
#include <memory>
#include <queue>
#include <unordered_set>

CMMC_NAMESPACE_BEGIN

class GlobalEliminate final : public TransformPass<Module> {
public:
    bool run(Module& mod, AnalysisPassManager&) const override {
        std::unordered_set<Value*> unused;

        for(auto global : mod.globals())
            if(global->getLinkage() == Linkage::Internal)
                unused.insert(global);
        if(unused.empty())
            return false;

        auto color = [&](Function* func) {
            for(auto block : func->blocks()) {
                for(auto& inst : block->instructions()) {
                    for(auto operand : inst.operands())
                        if(operand->isGlobal()) {
                            unused.erase(operand);
                        }
                }
            }
        };

        std::unordered_set<Function*> colored;

        while(true) {
            bool modified = false;
            for(auto global : mod.globals()) {
                if(const auto func = dynamic_cast<Function*>(global)) {
                    if(colored.count(func) || unused.count(func))
                        continue;

                    color(func);
                    colored.insert(func);
                    modified = true;

                    if(unused.empty())
                        return false;
                }
            }
            if(!modified)
                break;
        }

        auto& globals = mod.globals();
        globals.erase(std::remove_if(globals.begin(), globals.end(), [&](GlobalValue* global) { return unused.count(global); }),
                      globals.end());
        DisableValueRefCheckScope scope{};
        // remove references
        for(auto global : unused) {
            std::destroy_at(global);
        }
        return !unused.empty();
    }

    [[nodiscard]] std::string_view name() const noexcept override {
        return "GlobalEliminate"sv;
    }
};

CMMC_TRANSFORM_PASS(GlobalEliminate);

CMMC_NAMESPACE_END
