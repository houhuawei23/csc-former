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

#pragma once
#include "../../cmmc/Analysis/AnalysisPass.hpp"
#include "../../cmmc/Analysis/SCEVExpr.hpp"
#include "../../cmmc/IR/Block.hpp"
#include "../../cmmc/IR/Function.hpp"
#include "../../cmmc/IR/Instruction.hpp"
#include <memory>
#include <ostream>

CMMC_NAMESPACE_BEGIN

class SCEVAnalysisResult final {
    mutable std::vector<std::unique_ptr<SCEV>> mPool;
    mutable std::unordered_map<Value*, SCEV*> mStorage;

public:
    SCEV* addSCEV(Value* val, std::unique_ptr<SCEV> scev) const;
    SCEV* query(Value* value) const;
    void dumpSystem(std::ostream& out) const;
};

class SCEVAnalysis final : public FuncAnalysisPassWrapper<SCEVAnalysis, SCEVAnalysisResult> {
public:
    static SCEVAnalysisResult run(Function& func, AnalysisPassManager& analysis);
};

CMMC_NAMESPACE_END
