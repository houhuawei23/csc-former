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
#include "../../cmmc/IR/Function.hpp"
#include "../../cmmc/IR/Module.hpp"
#include "../../cmmc/Support/LabelAllocator.hpp"
#include <initializer_list>
#include <memory>
#include <ostream>
#include <string_view>

CMMC_NAMESPACE_BEGIN

// **Stateless** Transform Pass

template <typename Scope>
class TransformPass {
public:
    TransformPass() = default;
    virtual ~TransformPass();
    TransformPass(const TransformPass&) = delete;
    TransformPass& operator=(const TransformPass&) = delete;

    virtual bool run(Scope& item, AnalysisPassManager& analysis) const = 0;
    virtual String dump(std::ostream& out, String prev, LabelAllocator& allocator) const;
    [[nodiscard]] virtual std::string_view name() const noexcept = 0;
    [[nodiscard]] virtual bool isWrapper() const noexcept {
        return false;
    }
};

enum class OptimizationLevel { O0 = 0, O1 = 1, O2 = 2, O3 = 3 };

template <typename Scope>
class PassManager final : public TransformPass<Scope> {
    std::vector<std::shared_ptr<TransformPass<Scope>>> mPasses;

public:
    PassManager() = default;
    bool run(Scope& item, AnalysisPassManager& analysis) const override;
    std::optional<size_t> run(Scope& item, AnalysisPassManager& analysis, size_t lastStop) const;
    [[nodiscard]] std::string_view name() const noexcept override;
    void addPass(std::shared_ptr<TransformPass<Scope>> pass);
    static std::shared_ptr<PassManager> get(OptimizationLevel level);
    static void printOptPipeline(OptimizationLevel level);
    [[nodiscard]] bool isWrapper() const noexcept override {
        return true;
    }
    String dump(std::ostream& out, String prev, LabelAllocator& allocator) const override;
};

std::shared_ptr<TransformPass<Module>> createWrapper(std::shared_ptr<TransformPass<Function>> funcPass);

class PassRegistry final {
    std::unordered_map<std::string_view, std::shared_ptr<TransformPass<Function>>> mFunctionPasses;
    std::unordered_map<std::string_view, std::shared_ptr<TransformPass<Module>>> mModulePasses;

public:
    void registerPass(std::shared_ptr<TransformPass<Module>> pass);
    void registerPass(std::shared_ptr<TransformPass<Function>> pass);
    std::vector<std::shared_ptr<TransformPass<Module>>> collectModulePass(std::initializer_list<std::string_view> list) const;
    std::vector<std::shared_ptr<TransformPass<Function>>> collectFunctionPass(std::initializer_list<std::string_view> list) const;

    static PassRegistry& get();
};

// NOLINTNEXTLINE
#define CMMC_TRANSFORM_PASS(CLASS)                                   \
    static const int __pass_##CLASS = [] {                           \
        PassRegistry::get().registerPass(std::make_shared<CLASS>()); \
        return 0;                                                    \
    }()

CMMC_NAMESPACE_END
