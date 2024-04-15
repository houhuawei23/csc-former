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
#include "../../cmmc/Config.hpp"
#include "../../cmmc/IR/Type.hpp"
#include "../../cmmc/Support/Arena.hpp"
#include <ostream>

CMMC_NAMESPACE_BEGIN

class Module;
class Block;
class Instruction;

class HighlightSelector {
public:
    virtual bool highlight(const Block* block) const noexcept = 0;
    virtual bool highlight(const Instruction* instruction) const noexcept = 0;
    virtual ~HighlightSelector() = default;
};

struct Noop final : public HighlightSelector {
    bool highlight(const Block*) const noexcept override {
        return false;
    }
    bool highlight(const Instruction*) const noexcept override {
        return false;
    }
};

enum class ValueRank { Constant, Global, Argument, Instruction };

class Value {
    const Type* mType;

public:
    static constexpr auto arenaSource = Arena::Source::IR;

    explicit Value(const Type* type);
    Value(const Value&) = default;
    Value(Value&&) = default;
    Value& operator=(const Value&) = default;
    Value& operator=(Value&&) = default;
    virtual ~Value() = default;

    [[nodiscard]] virtual ValueRank rank() const noexcept = 0;
    virtual void dump(std::ostream& out, const HighlightSelector& selector) const = 0;  // TODO: highlight?
    void dumpPrefix(std::ostream& out) const;
    virtual void dumpAsOperand(std::ostream& out) const;
    [[nodiscard]] const Type* getType() const noexcept {
        return mType;
    }
    void setType(const Type* type) noexcept {
        mType = type;
    }
    [[nodiscard]] bool isGlobal() const noexcept {
        return rank() == ValueRank::Global;
    }
    [[nodiscard]] bool isConstant() const noexcept {
        return rank() == ValueRank::Constant;
    }
    [[nodiscard]] virtual bool isUndefined() const noexcept {
        return false;
    }
    [[nodiscard]] bool isInstruction() const noexcept {
        return rank() == ValueRank::Instruction;
    }
    [[nodiscard]] bool isArgument() const noexcept {
        return rank() == ValueRank::Argument;
    }
    [[nodiscard]] virtual Block* getBlock() const noexcept {
        return nullptr;
    }

    template <typename T>
    T* as() {
        static_assert(std::is_base_of_v<Value, T>);
        const auto ptr = dynamic_cast<T*>(this);
        assert(ptr);
        return ptr;
    }

    template <typename T>
    [[nodiscard]] const T* as() const {
        static_assert(std::is_base_of_v<Value, T>);
        const auto ptr = dynamic_cast<const T*>(this);
        assert(ptr);
        return ptr;
    }

    template <typename T>
    [[nodiscard]] bool is() const {
        static_assert(std::is_base_of_v<Value, T>);
        return dynamic_cast<const T*>(this);
    }
};

CMMC_NAMESPACE_END
