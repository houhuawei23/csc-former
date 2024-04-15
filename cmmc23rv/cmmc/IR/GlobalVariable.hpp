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
#include "../../cmmc/IR/Attribute.hpp"
#include "../../cmmc/IR/ConstantValue.hpp"
#include "../../cmmc/IR/GlobalValue.hpp"
#include "../../cmmc/IR/Type.hpp"
#include "../../cmmc/IR/Value.hpp"

CMMC_NAMESPACE_BEGIN

enum class GlobalVariableAttribute {
    ReadOnly = 1 << 0,
    Flexible = 1 << 1,
    InitOnce = 1 << 2,
    Transposed = 1 << 3,
};

class GlobalVariable final : public GlobalValue {
    ConstantValue* mStaticInitializedValue{ nullptr };
    size_t mAlignment;
    Attribute<GlobalVariableAttribute> mAttr;

public:
    GlobalVariable(String symbol, const Type* type, size_t alignment)
        : GlobalValue{ symbol, PointerType::get(type) }, mAlignment{ alignment } {}
    [[nodiscard]] size_t getAlignment() const noexcept {
        return mAlignment;
    }
    void setInitialValue(ConstantValue* value) noexcept {
        mStaticInitializedValue = value;
    }
    [[nodiscard]] ConstantValue* initialValue() const noexcept {
        return mStaticInitializedValue;
    }
    void dump(std::ostream& out, const HighlightSelector& selector) const override;
    auto& attr() noexcept {
        return mAttr;
    }
};

CMMC_NAMESPACE_END
