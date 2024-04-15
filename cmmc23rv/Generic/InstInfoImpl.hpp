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
// Automatically generated file, do not edit!

#include "../Generic/InstInfoDecl.hpp"
#include "../cmmc/CodeGen/InstInfo.hpp"
#include "../cmmc/CodeGen/MIR.hpp"
#include "../cmmc/CodeGen/Target.hpp"

CMMC_TARGET_NAMESPACE_BEGIN

class GenericInstInfoJump final : public InstInfo {
public:
    GenericInstInfoJump() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Jump " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::Generic::isOperandReloc(inst.getOperand(0));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 1;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagTerminator | InstFlagBranch | InstFlagNoFallthrough;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Jump";
    }
};

class GenericInstInfoBranch final : public InstInfo {
public:
    GenericInstInfoBranch() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Branch " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandBool(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandReloc(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandProb(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagUse;
            case 1:
                return OperandFlagMetadata;
            case 2:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagTerminator | InstFlagBranch;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Branch";
    }
};

class GenericInstInfoUnreachable final : public InstInfo {
public:
    GenericInstInfoUnreachable() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Unreachable";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(0) && mir::checkISASpecificOperands(inst, ctx, 0);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 0;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {

            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagTerminator | InstFlagNoFallthrough;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Unreachable";
    }
};

class GenericInstInfoLoad final : public InstInfo {
public:
    GenericInstInfoLoad() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Load " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandVReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandVReg(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandAlign(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLoad;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Load";
    }
};

class GenericInstInfoStore final : public InstInfo {
public:
    GenericInstInfoStore() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Store " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandVReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandAlign(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagUse;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagStore;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Store";
    }
};

class GenericInstInfoAdd final : public InstInfo {
public:
    GenericInstInfoAdd() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Add " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Add";
    }
};

class GenericInstInfoSub final : public InstInfo {
public:
    GenericInstInfoSub() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Sub " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Sub";
    }
};

class GenericInstInfoMul final : public InstInfo {
public:
    GenericInstInfoMul() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Mul " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Mul";
    }
};

class GenericInstInfoUDiv final : public InstInfo {
public:
    GenericInstInfoUDiv() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "UDiv " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.UDiv";
    }
};

class GenericInstInfoURem final : public InstInfo {
public:
    GenericInstInfoURem() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "URem " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.URem";
    }
};

class GenericInstInfoAnd final : public InstInfo {
public:
    GenericInstInfoAnd() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "And " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.And";
    }
};

class GenericInstInfoOr final : public InstInfo {
public:
    GenericInstInfoOr() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Or " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Or";
    }
};

class GenericInstInfoXor final : public InstInfo {
public:
    GenericInstInfoXor() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Xor " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Xor";
    }
};

class GenericInstInfoShl final : public InstInfo {
public:
    GenericInstInfoShl() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Shl " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Shl";
    }
};

class GenericInstInfoLShr final : public InstInfo {
public:
    GenericInstInfoLShr() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "LShr " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.LShr";
    }
};

class GenericInstInfoAShr final : public InstInfo {
public:
    GenericInstInfoAShr() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "AShr " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.AShr";
    }
};

class GenericInstInfoSDiv final : public InstInfo {
public:
    GenericInstInfoSDiv() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "SDiv " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(3) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(4) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(5) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2)) && ::cmmc::mir::Generic::isOperandImm(inst.getOperand(3)) &&
            ::cmmc::mir::Generic::isOperandImm(inst.getOperand(4)) && ::cmmc::mir::Generic::isOperandImm(inst.getOperand(5));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagMetadata;
            case 4:
                return OperandFlagMetadata;
            case 5:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.SDiv";
    }
};

class GenericInstInfoSRem final : public InstInfo {
public:
    GenericInstInfoSRem() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "SRem " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(3) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(4) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(5) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2)) && ::cmmc::mir::Generic::isOperandImm(inst.getOperand(3)) &&
            ::cmmc::mir::Generic::isOperandImm(inst.getOperand(4)) && ::cmmc::mir::Generic::isOperandImm(inst.getOperand(5));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagMetadata;
            case 4:
                return OperandFlagMetadata;
            case 5:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.SRem";
    }
};

class GenericInstInfoSMin final : public InstInfo {
public:
    GenericInstInfoSMin() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "SMin " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.SMin";
    }
};

class GenericInstInfoSMax final : public InstInfo {
public:
    GenericInstInfoSMax() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "SMax " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.SMax";
    }
};

class GenericInstInfoNeg final : public InstInfo {
public:
    GenericInstInfoNeg() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Neg " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Neg";
    }
};

class GenericInstInfoAbs final : public InstInfo {
public:
    GenericInstInfoAbs() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Abs " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Abs";
    }
};

class GenericInstInfoFAdd final : public InstInfo {
public:
    GenericInstInfoFAdd() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FAdd " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FAdd";
    }
};

class GenericInstInfoFSub final : public InstInfo {
public:
    GenericInstInfoFSub() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FSub " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FSub";
    }
};

class GenericInstInfoFMul final : public InstInfo {
public:
    GenericInstInfoFMul() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FMul " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagCommutative;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FMul";
    }
};

class GenericInstInfoFDiv final : public InstInfo {
public:
    GenericInstInfoFDiv() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FDiv " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FDiv";
    }
};

class GenericInstInfoFNeg final : public InstInfo {
public:
    GenericInstInfoFNeg() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FNeg " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FNeg";
    }
};

class GenericInstInfoFAbs final : public InstInfo {
public:
    GenericInstInfoFAbs() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FAbs " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FAbs";
    }
};

class GenericInstInfoFFma final : public InstInfo {
public:
    GenericInstInfoFFma() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FFma " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(2)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(3));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 4;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FFma";
    }
};

class GenericInstInfoICmp final : public InstInfo {
public:
    GenericInstInfoICmp() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ICmp " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::Generic::isOperandBoolReg(inst.getOperand(0)) &&
            ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(2)) &&
            ::cmmc::mir::Generic::isOperandFlag(inst.getOperand(3));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 4;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.ICmp";
    }
};

class GenericInstInfoFCmp final : public InstInfo {
public:
    GenericInstInfoFCmp() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FCmp " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::Generic::isOperandBoolReg(inst.getOperand(0)) &&
            ::cmmc::mir::Generic::isOperandFVal(inst.getOperand(1)) && ::cmmc::mir::Generic::isOperandFVal(inst.getOperand(2)) &&
            ::cmmc::mir::Generic::isOperandFlag(inst.getOperand(3));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 4;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FCmp";
    }
};

class GenericInstInfoSExt final : public InstInfo {
public:
    GenericInstInfoSExt() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "SExt " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.SExt";
    }
};

class GenericInstInfoZExt final : public InstInfo {
public:
    GenericInstInfoZExt() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ZExt " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.ZExt";
    }
};

class GenericInstInfoTrunc final : public InstInfo {
public:
    GenericInstInfoTrunc() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Trunc " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Trunc";
    }
};

class GenericInstInfoF2U final : public InstInfo {
public:
    GenericInstInfoF2U() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "F2U " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.F2U";
    }
};

class GenericInstInfoF2S final : public InstInfo {
public:
    GenericInstInfoF2S() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "F2S " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.F2S";
    }
};

class GenericInstInfoU2F final : public InstInfo {
public:
    GenericInstInfoU2F() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "U2F " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.U2F";
    }
};

class GenericInstInfoS2F final : public InstInfo {
public:
    GenericInstInfoS2F() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "S2F " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandIVal(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.S2F";
    }
};

class GenericInstInfoFCast final : public InstInfo {
public:
    GenericInstInfoFCast() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "FCast " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandFReg(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.FCast";
    }
};

class GenericInstInfoCopy final : public InstInfo {
public:
    GenericInstInfoCopy() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Copy " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandVRegOrISAReg(inst.getOperand(0)) &&
            ::cmmc::mir::Generic::isOperandVRegOrISAReg(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagRegCopy;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Copy";
    }
};

class GenericInstInfoSelect final : public InstInfo {
public:
    GenericInstInfoSelect() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "Select " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::Generic::isOperandVReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandBool(inst.getOperand(1)) &&
            ::cmmc::mir::Generic::isOperandVal(inst.getOperand(2)) && ::cmmc::mir::Generic::isOperandVal(inst.getOperand(3));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 4;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.Select";
    }
};

class GenericInstInfoLoadGlobalAddress final : public InstInfo {
public:
    GenericInstInfoLoadGlobalAddress() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "LoadGlobalAddress " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandReloc(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLoadConstant;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.LoadGlobalAddress";
    }
};

class GenericInstInfoLoadImm final : public InstInfo {
public:
    GenericInstInfoLoadImm() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "LoadImm " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandImm(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLoadConstant;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.LoadImm";
    }
};

class GenericInstInfoLoadStackObjectAddr final : public InstInfo {
public:
    GenericInstInfoLoadStackObjectAddr() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "LoadStackObjectAddr " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandIReg(inst.getOperand(0)) &&
            ::cmmc::mir::Generic::isOperandStackObject(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLoadConstant;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.LoadStackObjectAddr";
    }
};

class GenericInstInfoCopyFromReg final : public InstInfo {
public:
    GenericInstInfoCopyFromReg() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "CopyFromReg " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandVRegOrISAReg(inst.getOperand(0)) &&
            ::cmmc::mir::Generic::isOperandISAReg(inst.getOperand(1)) && ::cmmc::mir::Generic::verifyInstCopyFromReg(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagRegCopy;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.CopyFromReg";
    }
};

class GenericInstInfoCopyToReg final : public InstInfo {
public:
    GenericInstInfoCopyToReg() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "CopyToReg " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandISAReg(inst.getOperand(0)) &&
            ::cmmc::mir::Generic::isOperandVRegOrISAReg(inst.getOperand(1)) && ::cmmc::mir::Generic::verifyInstCopyToReg(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagRegDef | InstFlagRegCopy;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.CopyToReg";
    }
};

class GenericInstInfoLoadImmToReg final : public InstInfo {
public:
    GenericInstInfoLoadImmToReg() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "LoadImmToReg " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandISAReg(inst.getOperand(0)) && ::cmmc::mir::Generic::isOperandImm(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagRegDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.LoadImmToReg";
    }
};

class GenericInstInfoLoadRegFromStack final : public InstInfo {
public:
    GenericInstInfoLoadRegFromStack() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "LoadRegFromStack " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandVRegOrISAReg(inst.getOperand(0)) &&
            ::cmmc::mir::Generic::isOperandStackObject(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLoad;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.LoadRegFromStack";
    }
};

class GenericInstInfoStoreRegToStack final : public InstInfo {
public:
    GenericInstInfoStoreRegToStack() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "StoreRegToStack " << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::Generic::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::Generic::isOperandVRegOrISAReg(inst.getOperand(0)) &&
            ::cmmc::mir::Generic::isOperandStackObject(inst.getOperand(1));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 2;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagUse;
            case 1:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagStore;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "Generic.StoreRegToStack";
    }
};

class GenericInstInfo final : public TargetInstInfo {
    GenericInstInfoJump mInstInfoJump;
    GenericInstInfoBranch mInstInfoBranch;
    GenericInstInfoUnreachable mInstInfoUnreachable;
    GenericInstInfoLoad mInstInfoLoad;
    GenericInstInfoStore mInstInfoStore;
    GenericInstInfoAdd mInstInfoAdd;
    GenericInstInfoSub mInstInfoSub;
    GenericInstInfoMul mInstInfoMul;
    GenericInstInfoUDiv mInstInfoUDiv;
    GenericInstInfoURem mInstInfoURem;
    GenericInstInfoAnd mInstInfoAnd;
    GenericInstInfoOr mInstInfoOr;
    GenericInstInfoXor mInstInfoXor;
    GenericInstInfoShl mInstInfoShl;
    GenericInstInfoLShr mInstInfoLShr;
    GenericInstInfoAShr mInstInfoAShr;
    GenericInstInfoSDiv mInstInfoSDiv;
    GenericInstInfoSRem mInstInfoSRem;
    GenericInstInfoSMin mInstInfoSMin;
    GenericInstInfoSMax mInstInfoSMax;
    GenericInstInfoNeg mInstInfoNeg;
    GenericInstInfoAbs mInstInfoAbs;
    GenericInstInfoFAdd mInstInfoFAdd;
    GenericInstInfoFSub mInstInfoFSub;
    GenericInstInfoFMul mInstInfoFMul;
    GenericInstInfoFDiv mInstInfoFDiv;
    GenericInstInfoFNeg mInstInfoFNeg;
    GenericInstInfoFAbs mInstInfoFAbs;
    GenericInstInfoFFma mInstInfoFFma;
    GenericInstInfoICmp mInstInfoICmp;
    GenericInstInfoFCmp mInstInfoFCmp;
    GenericInstInfoSExt mInstInfoSExt;
    GenericInstInfoZExt mInstInfoZExt;
    GenericInstInfoTrunc mInstInfoTrunc;
    GenericInstInfoF2U mInstInfoF2U;
    GenericInstInfoF2S mInstInfoF2S;
    GenericInstInfoU2F mInstInfoU2F;
    GenericInstInfoS2F mInstInfoS2F;
    GenericInstInfoFCast mInstInfoFCast;
    GenericInstInfoCopy mInstInfoCopy;
    GenericInstInfoSelect mInstInfoSelect;
    GenericInstInfoLoadGlobalAddress mInstInfoLoadGlobalAddress;
    GenericInstInfoLoadImm mInstInfoLoadImm;
    GenericInstInfoLoadStackObjectAddr mInstInfoLoadStackObjectAddr;
    GenericInstInfoCopyFromReg mInstInfoCopyFromReg;
    GenericInstInfoCopyToReg mInstInfoCopyToReg;
    GenericInstInfoLoadImmToReg mInstInfoLoadImmToReg;
    GenericInstInfoLoadRegFromStack mInstInfoLoadRegFromStack;
    GenericInstInfoStoreRegToStack mInstInfoStoreRegToStack;

public:
    GenericInstInfo() = default;
    const InstInfo& getInstInfo(uint32_t opcode) const override {
        switch(opcode) {
            case GenericInst::Jump:
                return mInstInfoJump;
            case GenericInst::Branch:
                return mInstInfoBranch;
            case GenericInst::Unreachable:
                return mInstInfoUnreachable;
            case GenericInst::Load:
                return mInstInfoLoad;
            case GenericInst::Store:
                return mInstInfoStore;
            case GenericInst::Add:
                return mInstInfoAdd;
            case GenericInst::Sub:
                return mInstInfoSub;
            case GenericInst::Mul:
                return mInstInfoMul;
            case GenericInst::UDiv:
                return mInstInfoUDiv;
            case GenericInst::URem:
                return mInstInfoURem;
            case GenericInst::And:
                return mInstInfoAnd;
            case GenericInst::Or:
                return mInstInfoOr;
            case GenericInst::Xor:
                return mInstInfoXor;
            case GenericInst::Shl:
                return mInstInfoShl;
            case GenericInst::LShr:
                return mInstInfoLShr;
            case GenericInst::AShr:
                return mInstInfoAShr;
            case GenericInst::SDiv:
                return mInstInfoSDiv;
            case GenericInst::SRem:
                return mInstInfoSRem;
            case GenericInst::SMin:
                return mInstInfoSMin;
            case GenericInst::SMax:
                return mInstInfoSMax;
            case GenericInst::Neg:
                return mInstInfoNeg;
            case GenericInst::Abs:
                return mInstInfoAbs;
            case GenericInst::FAdd:
                return mInstInfoFAdd;
            case GenericInst::FSub:
                return mInstInfoFSub;
            case GenericInst::FMul:
                return mInstInfoFMul;
            case GenericInst::FDiv:
                return mInstInfoFDiv;
            case GenericInst::FNeg:
                return mInstInfoFNeg;
            case GenericInst::FAbs:
                return mInstInfoFAbs;
            case GenericInst::FFma:
                return mInstInfoFFma;
            case GenericInst::ICmp:
                return mInstInfoICmp;
            case GenericInst::FCmp:
                return mInstInfoFCmp;
            case GenericInst::SExt:
                return mInstInfoSExt;
            case GenericInst::ZExt:
                return mInstInfoZExt;
            case GenericInst::Trunc:
                return mInstInfoTrunc;
            case GenericInst::F2U:
                return mInstInfoF2U;
            case GenericInst::F2S:
                return mInstInfoF2S;
            case GenericInst::U2F:
                return mInstInfoU2F;
            case GenericInst::S2F:
                return mInstInfoS2F;
            case GenericInst::FCast:
                return mInstInfoFCast;
            case GenericInst::Copy:
                return mInstInfoCopy;
            case GenericInst::Select:
                return mInstInfoSelect;
            case GenericInst::LoadGlobalAddress:
                return mInstInfoLoadGlobalAddress;
            case GenericInst::LoadImm:
                return mInstInfoLoadImm;
            case GenericInst::LoadStackObjectAddr:
                return mInstInfoLoadStackObjectAddr;
            case GenericInst::CopyFromReg:
                return mInstInfoCopyFromReg;
            case GenericInst::CopyToReg:
                return mInstInfoCopyToReg;
            case GenericInst::LoadImmToReg:
                return mInstInfoLoadImmToReg;
            case GenericInst::LoadRegFromStack:
                return mInstInfoLoadRegFromStack;
            case GenericInst::StoreRegToStack:
                return mInstInfoStoreRegToStack;
            default:
                return TargetInstInfo::getInstInfo(opcode);
        }
    }
    bool matchBranch(const MIRInst& inst, MIRBasicBlock*& target, double& prob) const override {
        auto& instInfo = getInstInfo(inst.opcode());
        if(requireFlag(instInfo.getInstFlag(), InstFlagBranch)) {
            if(inst.opcode() < ISASpecificBegin)
                return TargetInstInfo::matchBranch(inst, target, prob);
            switch(inst.opcode()) {
                case Jump:
                    target = dynamic_cast<MIRBasicBlock*>(inst.getOperand(0).reloc());
                    prob = 1.0;
                    break;
                case Branch:
                    target = dynamic_cast<MIRBasicBlock*>(inst.getOperand(1).reloc());
                    prob = inst.getOperand(2).prob();
                    break;
                default:
                    reportUnreachable(CMMC_LOCATION());
            }
            return true;
        }
        return false;
    }
    void redirectBranch(MIRInst& inst, MIRBasicBlock* target) const override {
        if(inst.opcode() < ISASpecificBegin)
            return TargetInstInfo::redirectBranch(inst, target);
        assert(requireFlag(getInstInfo(inst.opcode()).getInstFlag(), InstFlagBranch));
        switch(inst.opcode()) {
            case Jump:
                inst.setOperand<0>(MIROperand::asReloc(target));
                break;
            case Branch:
                inst.setOperand<1>(MIROperand::asReloc(target));
                break;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    MIRInst emitGoto(MIRBasicBlock* target) const override {
        return emitGotoImpl(target);
    }
    void inverseBranch(MIRInst& inst, MIRBasicBlock* newTarget) const override {
        inverseBranchImpl(inst, newTarget);
    }
    std::pair<intmax_t, intmax_t> getAddressingImmRange() const override {
        return getAddressingImmRangeImpl();
    }
};

const TargetInstInfo& getGenericInstInfo() {
    static GenericInstInfo instance;
    return instance;
}

CMMC_TARGET_NAMESPACE_END