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
#include "../../cmmc/CodeGen/MIR.hpp"
#include "../../cmmc/CodeGen/Target.hpp"
#include "../../cmmc/Support/Diagnostics.hpp"
#include "../../cmmc/Support/Dispatch.hpp"
#include "../../cmmc/Support/Graph.hpp"
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

CMMC_MIR_NAMESPACE_BEGIN

void registerCoalescing(MIRFunction& func, CodeGenContext& ctx) {
    while(genericPeepholeOpt(func, ctx))
        ;
    // func.dump(std::cerr, ctx);
}

CMMC_MIR_NAMESPACE_END
