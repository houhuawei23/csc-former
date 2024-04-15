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
#include <array>
#include <cassert>
#include "../../cmmc/IR/GlobalValue.hpp"
#include "../../cmmc/IR/Instruction.hpp"
#include <cstddef>
#include <cstdint>
#include <limits>
#include <list>
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

#define CMMC_MIR_NAMESPACE_BEGIN namespace cmmc::mir {
#define CMMC_MIR_NAMESPACE_END }

CMMC_MIR_NAMESPACE_BEGIN

struct CodeGenContext;

class MIRRelocable {
    String mSymbol;

public:
    explicit MIRRelocable(String sym) : mSymbol{ sym } {}
    virtual ~MIRRelocable() = default;
    [[nodiscard]] String symbol() const {
        return mSymbol;
    }
    virtual bool verify(std::ostream& out, const CodeGenContext& ctx) const = 0;
    void dumpAsTarget(std::ostream& out) const;
    virtual void dump(std::ostream& out, const CodeGenContext& ctx) const = 0;
    [[nodiscard]] virtual bool isFunc() const noexcept {
        return false;
    }
};

constexpr uint32_t virtualRegBegin = 0b0101U << 28;
constexpr uint32_t stackObjectBegin = 0b1010U << 28;
constexpr uint32_t invalidReg = 0b1100U << 28;
constexpr bool isISAReg(uint32_t x) {
    return x < virtualRegBegin;
}
constexpr bool isVirtualReg(uint32_t x) {
    return (x & virtualRegBegin) == virtualRegBegin;
}
constexpr bool isStackObject(uint32_t x) {
    return (x & stackObjectBegin) == stackObjectBegin;
}

enum class OperandType : uint32_t {
    Bool,
    Int8,
    Int16,
    Int32,
    Int64,
    Float32,
    Special,
    // %hi/%lo for relocatable addresses
    HighBits,
    LowBits,
    // ARM condition field
    CondField,
    // ARM rlist
    RegList,
    RegListVFP,
    // ARM shift type
    ShiftType,
    LoadStoreShamt,
};

constexpr bool isIntegerType(OperandType type) {
    return type <= OperandType::Int64;
}
constexpr bool isFPType(OperandType type) {
    return type == OperandType::Float32;
}

constexpr uint32_t getOperandSize(const OperandType type) {
    switch(type) {
        case OperandType::Int8:
            return 1;
        case OperandType::Int16:
            return 2;
        case OperandType::Int32:
            return 4;
        case OperandType::Int64:
            return 8;
        case OperandType::Float32:
            return 4;
        default:
            return 0;  // unsupported
    }
}

enum MIRRegisterFlag : uint32_t {
    RegisterFlagNone = 0,
    RegisterFlagDead = 1 << 1,
};

struct MIRRegister final {
    uint32_t reg;
    MIRRegisterFlag flag = RegisterFlagNone;

    bool operator==(const MIRRegister& rhs) const noexcept {
        return reg == rhs.reg;
    }
    bool operator!=(const MIRRegister& rhs) const noexcept {
        return reg != rhs.reg;
    }
};

CMMC_MIR_NAMESPACE_END

namespace std {
    template <>
    struct hash<cmmc::mir::MIRRegister> {
        size_t operator()(const cmmc::mir::MIRRegister& reg) const noexcept {
            return hash<uint32_t>{}(reg.reg);
        }
    };
}  // namespace std

CMMC_MIR_NAMESPACE_BEGIN

class MIROperand final {
    std::variant<std::monostate, MIRRegister, intmax_t, MIRRelocable*, double> mOperand{ std::monostate{} };
    OperandType mType = OperandType::Special;

public:
    constexpr MIROperand() = default;
    template <typename T>
    constexpr MIROperand(T x, OperandType type) : mOperand{ x }, mType{ type } {}
    [[nodiscard]] constexpr const auto& getStorage() const noexcept {
        return mOperand;
    }
    bool operator==(const MIROperand& rhs) const {
        return mOperand == rhs.mOperand;
    }
    bool operator!=(const MIROperand& rhs) const {
        return mOperand != rhs.mOperand;
    }
    [[nodiscard]] constexpr OperandType type() const noexcept {
        return mType;
    }
    [[nodiscard]] size_t hash() const {
        return std::hash<std::decay_t<decltype(mOperand)>>{}(mOperand);
    }
    [[nodiscard]] constexpr intmax_t imm() const {
        return std::get<intmax_t>(mOperand);
    }
    [[nodiscard]] constexpr bool isImm() const {
        return std::holds_alternative<intmax_t>(mOperand);
    }
    template <typename T>
    [[nodiscard]] constexpr static MIROperand asImm(T val, OperandType type) {
        static_assert(std::is_integral_v<T> || std::is_enum_v<T>);
        return MIROperand{ static_cast<intmax_t>(val), type };
    }
    [[nodiscard]] constexpr static MIROperand asISAReg(uint32_t reg, OperandType type) {
        assert(isISAReg(reg));
        return MIROperand{ MIRRegister{ reg }, type };
    }
    [[nodiscard]] constexpr static MIROperand asVReg(uint32_t reg, OperandType type) {
        return MIROperand{ MIRRegister{ reg + virtualRegBegin }, type };
    }
    [[nodiscard]] constexpr static MIROperand asStackObject(uint32_t reg, OperandType type) {
        return MIROperand{ MIRRegister{ reg + stackObjectBegin }, type };
    }
    [[nodiscard]] constexpr static MIROperand asInvalidReg() {
        return MIROperand{ MIRRegister{ invalidReg }, OperandType::Special };
    }
    [[nodiscard]] constexpr static MIROperand asReloc(MIRRelocable* val) {
        return MIROperand{ val, OperandType::Special };
    }
    [[nodiscard]] constexpr static MIROperand asProb(double val) {
        return MIROperand{ val, OperandType::Special };
    }
    [[nodiscard]] constexpr uint32_t reg() const {
        return std::get<MIRRegister>(mOperand).reg;
    }
    [[nodiscard]] MIRRegisterFlag& regFlag() {
        return std::get<MIRRegister>(mOperand).flag;
    }
    [[nodiscard]] MIRRegisterFlag regFlag() const {
        return std::get<MIRRegister>(mOperand).flag;
    }
    [[nodiscard]] constexpr bool isReg() const {
        return std::holds_alternative<MIRRegister>(mOperand);
    }
    [[nodiscard]] constexpr MIRRelocable* reloc() const {
        return std::get<MIRRelocable*>(mOperand);
    }
    [[nodiscard]] constexpr bool isReloc() const {
        return std::holds_alternative<MIRRelocable*>(mOperand);
    }
    [[nodiscard]] constexpr double prob() const {
        return std::get<double>(mOperand);
    }
    [[nodiscard]] constexpr bool isProb() const {
        return std::holds_alternative<double>(mOperand);
    }
    [[nodiscard]] constexpr bool isUnused() const {
        return std::holds_alternative<std::monostate>(mOperand);
    }
};
struct MIROperandHasher final {
    size_t operator()(const MIROperand& operand) const {
        return operand.hash();
    }
};
enum MIRGenericInst : uint32_t {
    // control-flow
    InstJump,    // reloc
    InstBranch,  // cond, reloc, prob
    InstUnreachable,
    // Memory
    InstLoad,
    InstStore, // 4
    // Arithmetic
    InstAdd,
    InstSub,
    InstMul,
    InstUDiv,
    InstURem,
    // Bitwise
    InstAnd,
    InstOr,
    InstXor,
    InstShl,
    InstLShr,
    InstAShr,
    // Signed Div/Rem
    InstSDiv,
    InstSRem,
    // MinMax
    InstSMin,
    InstSMax,
    // Int Unary
    InstNeg,
    InstAbs,
    // FP
    InstFAdd,
    InstFSub,
    InstFMul,
    InstFDiv,
    InstFNeg,
    InstFAbs,
    InstFFma,
    // Comparison
    InstICmp,  // dst, lhs, rhs, op
    InstFCmp,  // dst, lhs, rhs, op
    // Conversion
    InstSExt,
    InstZExt,
    InstTrunc,
    InstF2U,
    InstF2S,
    InstU2F,
    InstS2F,
    InstFCast,
    // Misc
    InstCopy,
    InstSelect,
    InstLoadGlobalAddress, // 41
    InstLoadImm,
    InstLoadStackObjectAddr,
    InstCopyFromReg,
    InstCopyToReg, // 45
    InstLoadImmToReg,
    InstLoadRegFromStack,
    InstStoreRegToStack,

    ISASpecificBegin,
};
class MIRInst final {
public:
    static constexpr uint32_t maxOperandCount = 7;

private:
    uint32_t mOpcode;
    std::array<MIROperand, maxOperandCount> mOperands;

public:
    explicit MIRInst(uint32_t opcode) : mOpcode{ opcode } {}
    bool operator==(const MIRInst& rhs) const {
        return mOpcode == rhs.mOpcode && mOperands == rhs.mOperands;
    }
    [[nodiscard]] uint32_t opcode() const {
        return mOpcode;
    }
    MIRInst& setOpcode(uint32_t opcode) {
        mOpcode = opcode;
        return *this;
    }
    [[nodiscard]] bool checkOperandCount(uint32_t cnt) const {
        for(uint32_t idx = cnt; idx < maxOperandCount; ++idx)
            if(!mOperands[idx].isUnused())
                return false;
        return true;
    }
    [[nodiscard]] const MIROperand& getOperand(uint32_t idx) const {
        return mOperands[idx];
    }
    [[nodiscard]] MIROperand& getOperand(uint32_t idx) {
        return mOperands[idx];
    }
    template <uint32_t Idx>
    MIRInst& setOperand(const MIROperand& operand) {
        static_assert(Idx < maxOperandCount);
        mOperands[Idx] = operand;
        return *this;
    }
};
class MIRFunction;

#ifdef CMMC_ENABLE_DETERMINISTIC
using MIRInstList = std::list<MIRInst, DeterministicAllocator<MIRInst>>;
#else
using MIRInstList = std::list<MIRInst>;
#endif

class MIRBasicBlock final : public MIRRelocable {
    MIRFunction* mFunction;
    MIRInstList mInsts;
    double mTripCount = 0.0;

public:
    MIRBasicBlock(String label, MIRFunction* func) : MIRRelocable{ label }, mFunction{ func } {}
    [[nodiscard]] MIRFunction* getFunction() const {
        return mFunction;
    }
    [[nodiscard]] MIRInstList& instructions() {
        return mInsts;
    }
    [[nodiscard]] double getTripCount() const {
        return mTripCount;
    }
    void setTripCount(double tripCount) {
        mTripCount = tripCount;
    }
    [[nodiscard]] const MIRInstList& instructions() const {
        return mInsts;
    }

    bool verify(std::ostream& out, const CodeGenContext& ctx) const override;
    void dump(std::ostream& out, const CodeGenContext& ctx) const override;
};

enum class StackObjectUsage { Argument, CalleeArgument, Local, RegSpill, CalleeSaved };
struct StackObject final {
    uint32_t size;
    uint32_t alignment;
    int32_t offset;  // positive
    StackObjectUsage usage;
};

class MIRFunction final : public MIRRelocable {
    std::list<std::unique_ptr<MIRBasicBlock>> mBlocks;
    std::unordered_map<MIROperand, StackObject, MIROperandHasher> mStackObjects;
    std::vector<MIROperand> mArgs;

public:
    explicit MIRFunction(String symbol) : MIRRelocable{ symbol } {}
    MIROperand addStackObject(CodeGenContext& ctx, uint32_t size, uint32_t alignment, int32_t offset, StackObjectUsage usage);
    std::list<std::unique_ptr<MIRBasicBlock>>& blocks() {
        return mBlocks;
    }
    std::vector<MIROperand>& args() {
        return mArgs;
    }
    auto& stackObjects() {
        return mStackObjects;
    }
    [[nodiscard]] const std::list<std::unique_ptr<MIRBasicBlock>>& blocks() const {
        return mBlocks;
    }
    [[nodiscard]] bool isFunc() const noexcept override {
        return true;
    }
    bool verify(std::ostream& out, const CodeGenContext& ctx) const override;
    void dump(std::ostream& out, const CodeGenContext& ctx) const override;
    void dumpCFG(std::ostream& out, const CodeGenContext& ctx) const;
};

// TODO: ascii/asciiz encoding

class MIRZeroStorage final : public MIRRelocable {
    size_t mSize;

public:
    explicit MIRZeroStorage(String symbol, size_t size) : MIRRelocable{ symbol }, mSize{ size } {}
    bool verify(std::ostream& out, const CodeGenContext& ctx) const override;
    void dump(std::ostream& out, const CodeGenContext& ctx) const override;
};

class MIRDataStorage final : public MIRRelocable {
public:
    using Storage = std::vector<std::variant<std::byte, uint32_t, size_t>>;

private:
    // byte, word, zero
    Storage mData;
    bool mReadOnly;

public:
    MIRDataStorage(String symbol, Storage data, bool readOnly)
        : MIRRelocable{ symbol }, mData{ std::move(data) }, mReadOnly{ readOnly } {}
    [[nodiscard]] bool isReadOnly() const noexcept {
        return mReadOnly;
    }
    uint32_t appendWord(uint32_t val);
    bool verify(std::ostream& out, const CodeGenContext& ctx) const override;
    void dump(std::ostream& out, const CodeGenContext& ctx) const override;
};

class MIRJumpTable final : public MIRRelocable {
private:
    std::vector<MIRRelocable*> mData;

public:
    explicit MIRJumpTable(String symbol) : MIRRelocable{ symbol } {}
    auto& data() {
        return mData;
    }
    bool verify(std::ostream& out, const CodeGenContext& ctx) const override;
    void dump(std::ostream& out, const CodeGenContext& ctx) const override;
};

struct MIRGlobal final {
    Linkage linkage;
    size_t alignment;
    std::unique_ptr<MIRRelocable> reloc;

    MIRGlobal(Linkage globalLinkage, size_t align, std::unique_ptr<MIRRelocable> relocable)
        : linkage{ globalLinkage }, alignment{ align }, reloc{ std::move(relocable) } {}

    bool verify(std::ostream& out, const CodeGenContext& ctx) const;
    void dump(std::ostream& out, const CodeGenContext& ctx) const;
};

class Target;
class MIRModule final {
    const Target& mTarget;
    std::vector<std::unique_ptr<MIRGlobal>> mGlobals;

public:
    explicit MIRModule(const Target& target) : mTarget{ target } {}
    std::vector<std::unique_ptr<MIRGlobal>>& globals() {
        return mGlobals;
    }
    [[nodiscard]] const std::vector<std::unique_ptr<MIRGlobal>>& globals() const {
        return mGlobals;
    }
    [[nodiscard]] const Target& getTarget() const {
        return mTarget;
    }
    // TODO: check global ref
    bool verify(std::ostream& out, const CodeGenContext& ctx) const;
    void dump(std::ostream& out, const CodeGenContext& ctx) const;
};

CMMC_MIR_NAMESPACE_END
