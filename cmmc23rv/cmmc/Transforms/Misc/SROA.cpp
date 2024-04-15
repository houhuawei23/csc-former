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
#include "../../../cmmc/CodeGen/Target.hpp"
#include "../../../cmmc/IR/Block.hpp"
#include "../../../cmmc/IR/ConstantValue.hpp"
#include "../../../cmmc/IR/Function.hpp"
#include "../../../cmmc/IR/Instruction.hpp"
#include "../../../cmmc/IR/Type.hpp"
#include "../../../cmmc/Support/Diagnostics.hpp"
#include "../../../cmmc/Transforms/TransformPass.hpp"
#include "../../../cmmc/Transforms/Util/PatternMatch.hpp"
#include <cstdint>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

// TODO: Eliminate arrays like int[n][1][m] and structs like struct x{struct y{};};
CMMC_NAMESPACE_BEGIN

class SROA final : public TransformPass<Function> {
    static bool isUsedInbound(const Instruction* gep) {
        for(auto user : gep->users()) {
            switch(user->getInstID()) {
                case InstructionID::Load:
                case InstructionID::Store:
                case InstructionID::AtomicAdd:
                    break;
                case InstructionID::GetElementPtr: {
                    // unbounded
                    if(gep->getType()->as<PointerType>()->isPrimitive())
                        return false;
                    const auto arguments = user->arguments();
                    if(!cint_(0)(MatchContext<Value>{ arguments.front() }))
                        return false;
                    break;
                }
                default:
                    return false;
            }
        }
        return true;
    }
    static bool isIndexedByConstantIndices(const Instruction* inst, const Type* type, intmax_t bound) {
        if(type->isArray() && type->as<ArrayType>()->getElementCount() == 1)
            return true;
        if(type->isStruct() && type->as<StructType>()->fields().size() == 1)
            return true;
        for(auto user : inst->users())
            if(user->getInstID() == InstructionID::GetElementPtr) {
                auto arguments = user->arguments();
                if(arguments.size() < 2)
                    return false;
                if(!cint_(0)(MatchContext<Value>{ arguments.front() }))
                    return false;
                auto first = arguments.begin();
                ++first;
                const auto idx = *first;
                if(!idx->isConstant())
                    return false;
                if(idx->isUndefined())
                    return false;
                intmax_t idxInt = 0;
                if(int_(idxInt)(MatchContext<Value>{ idx }) && (idxInt < 0 || idxInt >= bound))
                    return false;
                if(!isUsedInbound(user))
                    return false;
            } else
                return false;
        return true;
    }

public:
    bool run(Function& func, AnalysisPassManager& analysis) const override {
        std::list<Instruction*> todo;

        for(auto& inst : func.entryBlock()->instructions()) {
            if(inst.getInstID() == InstructionID::Alloc && inst.getType()->as<PointerType>()->getPointee()->isAggregate()) {
                const auto type = inst.getType()->as<PointerType>()->getPointee();
                const auto bound = type->isArray() ? type->as<ArrayType>()->getElementCount() : 0;
                if(bound > 16U)
                    continue;
                bool usedByPhi = false;
                for(auto user : inst.users()) {
                    if(user->getInstID() == InstructionID::Phi) {
                        usedByPhi = true;
                        break;
                    }
                }
                if(usedByPhi)
                    continue;
                if(isIndexedByConstantIndices(&inst, type, bound))
                    todo.push_back(&inst);
            }
        }
        if(todo.empty())
            return false;

        auto& dataLayout = analysis.module().getTarget().getDataLayout();
        auto getAlignment = [&](const Type* t) {
            if(t->isAggregate())
                return dataLayout.getStorageAlignment();
            return t->getAlignment(dataLayout);
        };

        for(auto alloc : todo) {
            const auto type = alloc->getType()->as<PointerType>()->getPointee();
            std::vector<Instruction*> map;
            if(type->isArray()) {
                const auto arrType = type->as<ArrayType>();
                map.reserve(arrType->getElementCount());
                for(uint32_t idx = 0; idx < arrType->getElementCount(); ++idx) {
                    map.push_back(make<StackAllocInst>(arrType->getElementType(), getAlignment(arrType->getElementType())));
                }
            } else if(type->isStruct()) {
                const auto structType = type->as<StructType>();
                map.reserve(structType->fields().size());
                for(auto& field : structType->fields()) {
                    map.push_back(make<StackAllocInst>(field.type, getAlignment(field.type)));
                }
            } else
                reportUnreachable(CMMC_LOCATION());
            for(auto inst : map)
                inst->insertBefore(func.entryBlock(), func.entryBlock()->instructions().begin());
            for(auto user : alloc->users()) {
                if(user->getInstID() == InstructionID::GetElementPtr) {
                    auto& operands = user->mutableOperands();
                    const auto idx = std::next(operands.begin())->get()->value;
                    intmax_t idxInt = 0;
                    Value* sub = nullptr;
                    if(int_(idxInt)(MatchContext<Value>{ idx })) {
                        sub = map[static_cast<size_t>(idxInt)];
                    } else if(idx->is<ConstantOffset>()) {
                        sub = map[idx->as<ConstantOffset>()->index()];
                    } else {
                        // [1 * type]
                        sub = map[0];
                    }
                    operands.erase(std::next(operands.begin()));
                    operands.pop_back();
                    user->addOperand(sub);
                }
            }

            // [1 * type]
            auto& users = alloc->users();
            for(auto iter = users.begin(); iter != users.end();) {
                auto next = std::next(iter);
                auto ref = iter.ref();
                assert(ref->user->getInstID() != InstructionID::GetElementPtr);

                auto ptr = make<PtrCastInst>(map[0], alloc->getType());
                ptr->insertBefore(ref->user->getBlock(), ref->user->asIterator());
                ref->resetValue(ptr);

                iter = next;
            }
        }

        return true;
    }

    [[nodiscard]] std::string_view name() const noexcept override {
        return "SROA"sv;
    }
};

CMMC_TRANSFORM_PASS(SROA);

CMMC_NAMESPACE_END
