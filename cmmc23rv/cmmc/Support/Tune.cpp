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

#include "../../cmmc/Support/Options.hpp"
#include "../../cmmc/Support/Tune.hpp"
#include <sstream>
#include <unordered_map>

CMMC_NAMESPACE_BEGIN

static StringOpt tune;  // NOLINT
static auto& getTuneStorage() {
    static std::unordered_map<std::string, int32_t> storage;
    return storage;
}

CMMC_INIT_OPTIONS_BEGIN
tune.setName("tune", 'n').setDesc("Fine-tune hyperparameters");
CMMC_INIT_OPTIONS_END

static void parseTune(const std::string_view& str) {
    std::stringstream ss(str.data());
    auto& storage = getTuneStorage();
    std::string key;
    int32_t val;
    while(ss >> key) {
        ss >> val;
        storage[key] = val;
    }
}
void initTune(const std::string_view& name, const std::string_view& target) {
    if(!tune.get(false).empty()) {
        parseTune(tune.get());
        return;
    }

    CMMC_UNUSED(name);
    CMMC_UNUSED(target);
    // Tuning is illegal in the competition
    // if(target == "riscv") {
    //     const std::string_view table[][2] = {
    //         { "/01_mm",
    //           "loop_unswitch 1 loop_parallel 1 unroll_block_size 8 max_unroll_body_size 128 max_constant_hoist_count 9" },
    //         { "/conv", "prob_predict 1" },
    //         { "/brainfuck",
    //           "loop_unswitch 1 loop_parallel 0 loop_extract 0 loop_unroll 0 dyn_loop_unroll 0 max_constant_hoist_count 4" },
    //         { "/crypto",
    //           "loop_unswitch 0 loop_parallel 0 unroll_block_size 8 max_unroll_body_size 128 max_constant_hoist_count 6" },
    //         { "/sl", "loop_unswitch 1 loop_parallel 1 unroll_block_size 2 max_unroll_body_size 128 max_constant_hoist_count 3"
    //         }, { "/gameoflife", "loop_parallel 1 unroll_block_size 16 max_unroll_body_size 128 max_constant_hoist_count 6" }
    //     };
    //     for(auto& [key, value] : table) {
    //         if(key.empty())
    //             continue;

    //         if(name.find(key) != std::string_view::npos) {
    //             parseTune(value);
    //             return;
    //         }
    //     }
    // }
}

int32_t queryTuneOpt(const std::string_view& key, int32_t defaultValue) {
    auto& storage = getTuneStorage();
    auto it = storage.find(std::string{ key });
    if(it != storage.end()) {
        return it->second;
    }
    return defaultValue;
}

CMMC_NAMESPACE_END
