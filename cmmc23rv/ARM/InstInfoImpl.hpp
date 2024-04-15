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

#include "../ARM/InstInfoDecl.hpp"
#include "../cmmc/CodeGen/InstInfo.hpp"
#include "../cmmc/CodeGen/MIR.hpp"
#include "../cmmc/CodeGen/Target.hpp"

CMMC_TARGET_NAMESPACE_BEGIN

class ARMInstInfoADD final : public InstInfo {
public:
    ARMInstInfoADD() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "add " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2));
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
        return "ARM.ADD";
    }
};

class ARMInstInfoSUB final : public InstInfo {
public:
    ARMInstInfoSUB() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "sub " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2));
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
        return "ARM.SUB";
    }
};

class ARMInstInfoAND final : public InstInfo {
public:
    ARMInstInfoAND() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "and " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2));
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
        return "ARM.AND";
    }
};

class ARMInstInfoORR final : public InstInfo {
public:
    ARMInstInfoORR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "orr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2));
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
        return "ARM.ORR";
    }
};

class ARMInstInfoEOR final : public InstInfo {
public:
    ARMInstInfoEOR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "eor " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2));
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
        return "ARM.EOR";
    }
};

class ARMInstInfoORN final : public InstInfo {
public:
    ARMInstInfoORN() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "orn " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2));
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
        return "ARM.ORN";
    }
};

class ARMInstInfoBIC final : public InstInfo {
public:
    ARMInstInfoBIC() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "bic " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2));
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
        return "ARM.BIC";
    }
};

class ARMInstInfoRSB final : public InstInfo {
public:
    ARMInstInfoRSB() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "rsb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2));
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
        return "ARM.RSB";
    }
};

class ARMInstInfoADDS final : public InstInfo {
public:
    ARMInstInfoADDS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "adds " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ADDS";
    }
};

class ARMInstInfoSUBS final : public InstInfo {
public:
    ARMInstInfoSUBS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "subs " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.SUBS";
    }
};

class ARMInstInfoANDS final : public InstInfo {
public:
    ARMInstInfoANDS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ands " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ANDS";
    }
};

class ARMInstInfoORRS final : public InstInfo {
public:
    ARMInstInfoORRS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "orrs " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ORRS";
    }
};

class ARMInstInfoEORS final : public InstInfo {
public:
    ARMInstInfoEORS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "eors " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.EORS";
    }
};

class ARMInstInfoORNS final : public InstInfo {
public:
    ARMInstInfoORNS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "orns " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ORNS";
    }
};

class ARMInstInfoBICS final : public InstInfo {
public:
    ARMInstInfoBICS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "bics " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.BICS";
    }
};

class ARMInstInfoRSBS final : public InstInfo {
public:
    ARMInstInfoRSBS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "rsbs " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.RSBS";
    }
};

class ARMInstInfoADD_Cond final : public InstInfo {
public:
    ARMInstInfoADD_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "add" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::verifyInstADD_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ADD_Cond";
    }
};

class ARMInstInfoSUB_Cond final : public InstInfo {
public:
    ARMInstInfoSUB_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "sub" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::verifyInstSUB_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.SUB_Cond";
    }
};

class ARMInstInfoAND_Cond final : public InstInfo {
public:
    ARMInstInfoAND_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "and" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::verifyInstAND_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.AND_Cond";
    }
};

class ARMInstInfoORR_Cond final : public InstInfo {
public:
    ARMInstInfoORR_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "orr" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::verifyInstORR_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ORR_Cond";
    }
};

class ARMInstInfoEOR_Cond final : public InstInfo {
public:
    ARMInstInfoEOR_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "eor" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::verifyInstEOR_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.EOR_Cond";
    }
};

class ARMInstInfoORN_Cond final : public InstInfo {
public:
    ARMInstInfoORN_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "orn" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::verifyInstORN_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ORN_Cond";
    }
};

class ARMInstInfoBIC_Cond final : public InstInfo {
public:
    ARMInstInfoBIC_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "bic" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::verifyInstBIC_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.BIC_Cond";
    }
};

class ARMInstInfoRSB_Cond final : public InstInfo {
public:
    ARMInstInfoRSB_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "rsb" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::verifyInstRSB_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 6;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.RSB_Cond";
    }
};

class ARMInstInfoADD_Fused final : public InstInfo {
public:
    ARMInstInfoADD_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "add " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandShOp(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ADD_Fused";
    }
};

class ARMInstInfoSUB_Fused final : public InstInfo {
public:
    ARMInstInfoSUB_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "sub " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandShOp(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.SUB_Fused";
    }
};

class ARMInstInfoAND_Fused final : public InstInfo {
public:
    ARMInstInfoAND_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "and " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandShOp(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.AND_Fused";
    }
};

class ARMInstInfoORR_Fused final : public InstInfo {
public:
    ARMInstInfoORR_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "orr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandShOp(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ORR_Fused";
    }
};

class ARMInstInfoEOR_Fused final : public InstInfo {
public:
    ARMInstInfoEOR_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "eor " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandShOp(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.EOR_Fused";
    }
};

class ARMInstInfoORN_Fused final : public InstInfo {
public:
    ARMInstInfoORN_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "orn " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandShOp(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.ORN_Fused";
    }
};

class ARMInstInfoBIC_Fused final : public InstInfo {
public:
    ARMInstInfoBIC_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "bic " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandShOp(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.BIC_Fused";
    }
};

class ARMInstInfoRSB_Fused final : public InstInfo {
public:
    ARMInstInfoRSB_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "rsb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandShOp(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.RSB_Fused";
    }
};

class ARMInstInfoMUL final : public InstInfo {
public:
    ARMInstInfoMUL() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mul " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2));
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
        return "ARM.MUL";
    }
};

class ARMInstInfoSMMUL final : public InstInfo {
public:
    ARMInstInfoSMMUL() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "smmul " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2));
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
        return "ARM.SMMUL";
    }
};

class ARMInstInfoSMMLA final : public InstInfo {
public:
    ARMInstInfoSMMLA() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "smmla " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(3));
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
        return "ARM.SMMLA";
    }
};

class ARMInstInfoMLA final : public InstInfo {
public:
    ARMInstInfoMLA() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mla " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(3));
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
        return "ARM.MLA";
    }
};

class ARMInstInfoMLS final : public InstInfo {
public:
    ARMInstInfoMLS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mls " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(3));
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
        return "ARM.MLS";
    }
};

class ARMInstInfoSXTB final : public InstInfo {
public:
    ARMInstInfoSXTB() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "sxtb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1));
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
        return "ARM.SXTB";
    }
};

class ARMInstInfoSXTH final : public InstInfo {
public:
    ARMInstInfoSXTH() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "sxth " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1));
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
        return "ARM.SXTH";
    }
};

class ARMInstInfoUXTB final : public InstInfo {
public:
    ARMInstInfoUXTB() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "uxtb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1));
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
        return "ARM.UXTB";
    }
};

class ARMInstInfoUXTH final : public InstInfo {
public:
    ARMInstInfoUXTH() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "uxth " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1));
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
        return "ARM.UXTH";
    }
};

class ARMInstInfoSDIV final : public InstInfo {
public:
    ARMInstInfoSDIV() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "sdiv " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandImm(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandImm(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.SDIV";
    }
};

class ARMInstInfoUDIV final : public InstInfo {
public:
    ARMInstInfoUDIV() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "udiv " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2));
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
        return "ARM.UDIV";
    }
};

class ARMInstInfoSEL final : public InstInfo {
public:
    ARMInstInfoSEL() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "sel " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2));
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
        return "ARM.SEL";
    }
};

class ARMInstInfoMOV_Constant final : public InstInfo {
public:
    ARMInstInfoMOV_Constant() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mov " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2Constant(inst.getOperand(1));
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
        return InstFlagNone | InstFlagLoadConstant;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.MOV_Constant";
    }
};

class ARMInstInfoMVN_Constant final : public InstInfo {
public:
    ARMInstInfoMVN_Constant() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mvn " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2Constant(inst.getOperand(1));
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
        return InstFlagNone | InstFlagLoadConstant;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.MVN_Constant";
    }
};

class ARMInstInfoMOV final : public InstInfo {
public:
    ARMInstInfoMOV() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mov " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(1));
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
        return "ARM.MOV";
    }
};

class ARMInstInfoMVN final : public InstInfo {
public:
    ARMInstInfoMVN() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mvn " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(1));
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
        return "ARM.MVN";
    }
};

class ARMInstInfoMOVS final : public InstInfo {
public:
    ARMInstInfoMOVS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "movs " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(2));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.MOVS";
    }
};

class ARMInstInfoMVNS final : public InstInfo {
public:
    ARMInstInfoMVNS() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mvns " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(2));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagMultiDef;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.MVNS";
    }
};

class ARMInstInfoCLZ final : public InstInfo {
public:
    ARMInstInfoCLZ() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "clz " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1));
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
        return "ARM.CLZ";
    }
};

class ARMInstInfoMoveGPR final : public InstInfo {
public:
    ARMInstInfoMoveGPR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mov " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1));
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
        return "ARM.MoveGPR";
    }
};

class ARMInstInfoMOV_Cond final : public InstInfo {
public:
    ARMInstInfoMOV_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mov" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(4)) && ::cmmc::mir::ARM::verifyInstMOV_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.MOV_Cond";
    }
};

class ARMInstInfoMVN_Cond final : public InstInfo {
public:
    ARMInstInfoMVN_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "mvn" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(4)) && ::cmmc::mir::ARM::verifyInstMVN_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.MVN_Cond";
    }
};

class ARMInstInfoASR final : public InstInfo {
public:
    ARMInstInfoASR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "asr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(2));
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
        return "ARM.ASR";
    }
};

class ARMInstInfoLSL final : public InstInfo {
public:
    ARMInstInfoLSL() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "lsl " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(2));
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
        return "ARM.LSL";
    }
};

class ARMInstInfoLSR final : public InstInfo {
public:
    ARMInstInfoLSR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "lsr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(2));
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
        return "ARM.LSR";
    }
};

class ARMInstInfoROR final : public InstInfo {
public:
    ARMInstInfoROR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ror " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandShamt(inst.getOperand(2));
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
        return "ARM.ROR";
    }
};

class ARMInstInfoCMP final : public InstInfo {
public:
    ARMInstInfoCMP() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "cmp " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(2));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.CMP";
    }
};

class ARMInstInfoCMN final : public InstInfo {
public:
    ARMInstInfoCMN() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "cmn " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(2));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.CMN";
    }
};

class ARMInstInfoB final : public InstInfo {
public:
    ARMInstInfoB() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "b " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::ARM::isOperandReloc(inst.getOperand(0));
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
        return "ARM.B";
    }
};

class ARMInstInfoB_Cond final : public InstInfo {
public:
    ARMInstInfoB_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "b" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) }
                << ", Branch Prob: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandReloc(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandProb(inst.getOperand(3));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 4;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagMetadata;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagTerminator | InstFlagBranch;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.B_Cond";
    }
};

class ARMInstInfoBL final : public InstInfo {
public:
    ARMInstInfoBL() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "bl " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::ARM::isOperandReloc(inst.getOperand(0));
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
        return InstFlagNone | InstFlagCall;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.BL";
    }
};

class ARMInstInfoBX final : public InstInfo {
public:
    ARMInstInfoBX() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "bx " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 1;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagTerminator | InstFlagNoFallthrough | InstFlagReturn;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.BX";
    }
};

class ARMInstInfoBX_IndirectJump final : public InstInfo {
public:
    ARMInstInfoBX_IndirectJump() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "bx " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        if(printComment)
            out << " @ " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandReloc(inst.getOperand(1));
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
        return InstFlagNone | InstFlagTerminator | InstFlagNoFallthrough | InstFlagIndirectJump;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.BX_IndirectJump";
    }
};

class ARMInstInfoVLDR final : public InstInfo {
public:
    ARMInstInfoVLDR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vldr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImmVFP(inst.getOperand(2));
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
        return "ARM.VLDR";
    }
};

class ARMInstInfoLDR final : public InstInfo {
public:
    ARMInstInfoLDR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImm13(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstLDR(inst);
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
        return "ARM.LDR";
    }
};

class ARMInstInfoLDRB final : public InstInfo {
public:
    ARMInstInfoLDRB() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldrb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImm13(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstLDRB(inst);
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
        return "ARM.LDRB";
    }
};

class ARMInstInfoLDRSB final : public InstInfo {
public:
    ARMInstInfoLDRSB() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldrsb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImm13(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstLDRSB(inst);
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
        return "ARM.LDRSB";
    }
};

class ARMInstInfoLDRH final : public InstInfo {
public:
    ARMInstInfoLDRH() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldrh " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImm13(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstLDRH(inst);
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
        return "ARM.LDRH";
    }
};

class ARMInstInfoLDRSH final : public InstInfo {
public:
    ARMInstInfoLDRSH() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldrsh " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImm13(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstLDRSH(inst);
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
        return "ARM.LDRSH";
    }
};

class ARMInstInfoLDR_Fused final : public InstInfo {
public:
    ARMInstInfoLDR_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) }
            << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandLoadStoreShamt(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLoad;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.LDR_Fused";
    }
};

class ARMInstInfoLDRB_Fused final : public InstInfo {
public:
    ARMInstInfoLDRB_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldrb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) }
            << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandLoadStoreShamt(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLoad;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.LDRB_Fused";
    }
};

class ARMInstInfoLDRSB_Fused final : public InstInfo {
public:
    ARMInstInfoLDRSB_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldrsb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) }
            << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandLoadStoreShamt(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLoad;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.LDRSB_Fused";
    }
};

class ARMInstInfoLDRH_Fused final : public InstInfo {
public:
    ARMInstInfoLDRH_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldrh " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) }
            << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandLoadStoreShamt(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLoad;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.LDRH_Fused";
    }
};

class ARMInstInfoLDRSH_Fused final : public InstInfo {
public:
    ARMInstInfoLDRSH_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ldrsh " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) }
            << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandLoadStoreShamt(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLoad;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.LDRSH_Fused";
    }
};

class ARMInstInfoVSTR final : public InstInfo {
public:
    ARMInstInfoVSTR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vstr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImmVFP(inst.getOperand(2));
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
        return "ARM.VSTR";
    }
};

class ARMInstInfoSTR_Fused final : public InstInfo {
public:
    ARMInstInfoSTR_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "str " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) }
            << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandLoadStoreShamt(inst.getOperand(3));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 4;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagUse;
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
        return InstFlagNone | InstFlagStore;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.STR_Fused";
    }
};

class ARMInstInfoSTRB_Fused final : public InstInfo {
public:
    ARMInstInfoSTRB_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "strb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) }
            << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandLoadStoreShamt(inst.getOperand(3));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 4;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagUse;
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
        return InstFlagNone | InstFlagStore;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.STRB_Fused";
    }
};

class ARMInstInfoSTRH_Fused final : public InstInfo {
public:
    ARMInstInfoSTRH_Fused() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "strh " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) }
            << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandLoadStoreShamt(inst.getOperand(3));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 4;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagUse;
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
        return InstFlagNone | InstFlagStore;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.STRH_Fused";
    }
};

class ARMInstInfoSTR final : public InstInfo {
public:
    ARMInstInfoSTR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "str " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImm13(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstSTR(inst);
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
        return "ARM.STR";
    }
};

class ARMInstInfoSTRB final : public InstInfo {
public:
    ARMInstInfoSTRB() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "strb " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImm13(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstSTRB(inst);
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
        return "ARM.STRB";
    }
};

class ARMInstInfoSTRH final : public InstInfo {
public:
    ARMInstInfoSTRH() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "strh " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", ["
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << "]";
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandBaseLike(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandAddrImm13(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstSTRH(inst);
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
        return "ARM.STRH";
    }
};

class ARMInstInfoMOVW final : public InstInfo {
public:
    ARMInstInfoMOVW() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "movw " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandUImm16(inst.getOperand(1));
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
        return "ARM.MOVW";
    }
};

class ARMInstInfoMOVW_Cond final : public InstInfo {
public:
    ARMInstInfoMOVW_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "movw" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandUImm16(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(4)) && ::cmmc::mir::ARM::verifyInstMOVW_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagMetadata;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.MOVW_Cond";
    }
};

class ARMInstInfoMOVT final : public InstInfo {
public:
    ARMInstInfoMOVT() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "movt " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandUImm16(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::verifyInstMOVT(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagMetadata;
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
        return "ARM.MOVT";
    }
};

class ARMInstInfoVADD_F32 final : public InstInfo {
public:
    ARMInstInfoVADD_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vadd.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2));
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
        return "ARM.VADD_F32";
    }
};

class ARMInstInfoVSUB_F32 final : public InstInfo {
public:
    ARMInstInfoVSUB_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vsub.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2));
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
        return "ARM.VSUB_F32";
    }
};

class ARMInstInfoVMUL_F32 final : public InstInfo {
public:
    ARMInstInfoVMUL_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmul.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2));
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
        return "ARM.VMUL_F32";
    }
};

class ARMInstInfoVNMUL_F32 final : public InstInfo {
public:
    ARMInstInfoVNMUL_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vnmul.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2));
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
        return "ARM.VNMUL_F32";
    }
};

class ARMInstInfoVDIV_F32 final : public InstInfo {
public:
    ARMInstInfoVDIV_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vdiv.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2));
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
        return "ARM.VDIV_F32";
    }
};

class ARMInstInfoVMLA_F32 final : public InstInfo {
public:
    ARMInstInfoVMLA_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmla.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::verifyInstVMLA_F32(inst);
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
        return "ARM.VMLA_F32";
    }
};

class ARMInstInfoVMLS_F32 final : public InstInfo {
public:
    ARMInstInfoVMLS_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmls.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::verifyInstVMLS_F32(inst);
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
        return "ARM.VMLS_F32";
    }
};

class ARMInstInfoVNMLA_F32 final : public InstInfo {
public:
    ARMInstInfoVNMLA_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vnmla.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::verifyInstVNMLA_F32(inst);
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
        return "ARM.VNMLA_F32";
    }
};

class ARMInstInfoVNMLS_F32 final : public InstInfo {
public:
    ARMInstInfoVNMLS_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vnmls.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::verifyInstVNMLS_F32(inst);
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
        return "ARM.VNMLS_F32";
    }
};

class ARMInstInfoVNEG_F32 final : public InstInfo {
public:
    ARMInstInfoVNEG_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vneg.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1));
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
        return "ARM.VNEG_F32";
    }
};

class ARMInstInfoVABS_F32 final : public InstInfo {
public:
    ARMInstInfoVABS_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vabs.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1));
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
        return "ARM.VABS_F32";
    }
};

class ARMInstInfoVCMP_F32 final : public InstInfo {
public:
    ARMInstInfoVCMP_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vcmp.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFCC(inst.getOperand(2));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.VCMP_F32";
    }
};

class ARMInstInfoVCMP_F32_WithZero final : public InstInfo {
public:
    ARMInstInfoVCMP_F32_WithZero() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vcmp.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        if(printComment)
            out << " @ Implicit Def: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFP32Zero(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFCC(inst.getOperand(2));
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
                return OperandFlagDef;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.VCMP_F32_WithZero";
    }
};

class ARMInstInfoTRANSFER_FPSCR_FLAG final : public InstInfo {
public:
    ARMInstInfoTRANSFER_FPSCR_FLAG() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmrs " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFCC(inst.getOperand(1));
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
        return "ARM.TRANSFER_FPSCR_FLAG";
    }
};

class ARMInstInfoVCVT_F32_S32 final : public InstInfo {
public:
    ARMInstInfoVCVT_F32_S32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vcvt.f32.s32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1));
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
        return "ARM.VCVT_F32_S32";
    }
};

class ARMInstInfoVCVT_S32_F32 final : public InstInfo {
public:
    ARMInstInfoVCVT_S32_F32() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vcvt.s32.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1));
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
        return "ARM.VCVT_S32_F32";
    }
};

class ARMInstInfoVMOV final : public InstInfo {
public:
    ARMInstInfoVMOV() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmov.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1));
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
        return "ARM.VMOV";
    }
};

class ARMInstInfoVMOV_Cond final : public InstInfo {
public:
    ARMInstInfoVMOV_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmov" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ".f32 "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        if(printComment)
            out << " @ Implicit Use: " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
                << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(4)) && ::cmmc::mir::ARM::verifyInstVMOV_Cond(inst);
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.VMOV_Cond";
    }
};

class ARMInstInfoVMOV_GPR2FPR final : public InstInfo {
public:
    ARMInstInfoVMOV_GPR2FPR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmov " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1));
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
        return "ARM.VMOV_GPR2FPR";
    }
};

class ARMInstInfoVMOV_FPR2GPR final : public InstInfo {
public:
    ARMInstInfoVMOV_FPR2GPR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmov " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1));
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
        return "ARM.VMOV_FPR2GPR";
    }
};

class ARMInstInfoVMOV_Constant final : public InstInfo {
public:
    ARMInstInfoVMOV_Constant() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vmov.f32 " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFP32(inst.getOperand(1));
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
        return "ARM.VMOV_Constant";
    }
};

class ARMInstInfoPUSH final : public InstInfo {
public:
    ARMInstInfoPUSH() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "push " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::ARM::isOperandRegList(inst.getOperand(0));
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
        return InstFlagNone | InstFlagStore | InstFlagInOrder;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.PUSH";
    }
};

class ARMInstInfoVPUSH final : public InstInfo {
public:
    ARMInstInfoVPUSH() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vpush " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::ARM::isOperandRegListVFP(inst.getOperand(0));
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
        return InstFlagNone | InstFlagStore | InstFlagInOrder;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.VPUSH";
    }
};

class ARMInstInfoPOP final : public InstInfo {
public:
    ARMInstInfoPOP() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "pop " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::ARM::isOperandRegList(inst.getOperand(0));
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
        return InstFlagNone | InstFlagLoad | InstFlagInOrder;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.POP";
    }
};

class ARMInstInfoPOP_RET final : public InstInfo {
public:
    ARMInstInfoPOP_RET() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "pop " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::ARM::isOperandRegList(inst.getOperand(0));
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
        return InstFlagNone | InstFlagLoad | InstFlagTerminator | InstFlagNoFallthrough | InstFlagReturn | InstFlagInOrder;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.POP_RET";
    }
};

class ARMInstInfoVPOP final : public InstInfo {
public:
    ARMInstInfoVPOP() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "vpop " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(1) && mir::checkISASpecificOperands(inst, ctx, 1) &&
            ::cmmc::mir::ARM::isOperandRegListVFP(inst.getOperand(0));
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
        return InstFlagNone | InstFlagLoad | InstFlagInOrder;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.VPOP";
    }
};

class ARMInstInfoUSAT final : public InstInfo {
public:
    ARMInstInfoUSAT() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "usat " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandUImm32(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagMetadata;
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
        return "ARM.USAT";
    }
};

class ARMInstInfoSSAT final : public InstInfo {
public:
    ARMInstInfoSSAT() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "ssat " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandUImm32(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 3;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagDef;
            case 1:
                return OperandFlagMetadata;
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
        return "ARM.SSAT";
    }
};

class ARMInstInfoMOVT_MOVW_PAIR final : public InstInfo {
public:
    ARMInstInfoMOVT_MOVW_PAIR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "movt_movw_pair " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(2) && mir::checkISASpecificOperands(inst, ctx, 2) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandUImm32OrReloc(inst.getOperand(1));
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
        return "ARM.MOVT_MOVW_PAIR";
    }
};

class ARMInstInfoNZCVFlag2GPR final : public InstInfo {
public:
    ARMInstInfoNZCVFlag2GPR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "nzcvflag2gpr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(3) && mir::checkISASpecificOperands(inst, ctx, 3) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(2));
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
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.NZCVFlag2GPR";
    }
};

class ARMInstInfoSelect_GPR final : public InstInfo {
public:
    ARMInstInfoSelect_GPR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "select_gpr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
            case 4:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.Select_GPR";
    }
};

class ARMInstInfoCondArith_GPR final : public InstInfo {
public:
    ARMInstInfoCondArith_GPR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "cond_arith_gpr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(6) && mir::checkISASpecificOperands(inst, ctx, 6) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandImm(inst.getOperand(5));
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
                return OperandFlagUse;
            case 4:
                return OperandFlagMetadata;
            case 5:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.CondArith_GPR";
    }
};

class ARMInstInfoSelect_FPR final : public InstInfo {
public:
    ARMInstInfoSelect_FPR() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "select_fpr " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
            case 4:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.Select_FPR";
    }
};

class ARMInstInfoPseudoIntOpWithOp2_Cond final : public InstInfo {
public:
    ARMInstInfoPseudoIntOpWithOp2_Cond() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "pseudo_int_op_with_op2" << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << " "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(5) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(6) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(7) && mir::checkISASpecificOperands(inst, ctx, 7) &&
            ::cmmc::mir::ARM::isOperandCondField(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(4)) && ::cmmc::mir::ARM::isOperandImm(inst.getOperand(5)) &&
            ::cmmc::mir::ARM::isOperandCC(inst.getOperand(6));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 7;
    }
    [[nodiscard]] OperandFlag getOperandFlag(uint32_t idx) const noexcept override {
        switch(idx) {
            case 0:
                return OperandFlagMetadata;
            case 1:
                return OperandFlagDef;
            case 2:
                return OperandFlagUse;
            case 3:
                return OperandFlagUse;
            case 4:
                return OperandFlagUse;
            case 5:
                return OperandFlagMetadata;
            case 6:
                return OperandFlagUse;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.PseudoIntOpWithOp2_Cond";
    }
};

class ARMInstInfoPseudoSMax final : public InstInfo {
public:
    ARMInstInfoPseudoSMax() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "pseudo_smax " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.PseudoSMax";
    }
};

class ARMInstInfoPseudoSMin final : public InstInfo {
public:
    ARMInstInfoPseudoSMin() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "pseudo_smin " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.PseudoSMin";
    }
};

class ARMInstInfoPseudoSMax_Inverted final : public InstInfo {
public:
    ARMInstInfoPseudoSMax_Inverted() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "pseudo_smax_inverted " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.PseudoSMax_Inverted";
    }
};

class ARMInstInfoPseudoSMin_Inverted final : public InstInfo {
public:
    ARMInstInfoPseudoSMin_Inverted() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "pseudo_smin_inverted " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(4) && mir::checkISASpecificOperands(inst, ctx, 4) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandOp2(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandCC(inst.getOperand(3));
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
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.PseudoSMin_Inverted";
    }
};

class ARMInstInfoPseudoFMA final : public InstInfo {
public:
    ARMInstInfoPseudoFMA() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << "pseudo_fma " << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(0) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(1) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(2) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(3) } << ", "
            << ::cmmc::mir::ARM::OperandDumper{ inst.getOperand(4) };
        CMMC_UNUSED(printComment);
    }
    [[nodiscard]] bool verify(const MIRInst& inst, const CodeGenContext& ctx) const override {
        return inst.checkOperandCount(5) && mir::checkISASpecificOperands(inst, ctx, 5) &&
            ::cmmc::mir::ARM::isOperandGPR(inst.getOperand(0)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(1)) &&
            ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(2)) && ::cmmc::mir::ARM::isOperandFPR(inst.getOperand(3)) &&
            ::cmmc::mir::ARM::isOperandImm(inst.getOperand(4));
    }
    [[nodiscard]] uint32_t getOperandNum() const noexcept override {
        return 5;
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
            case 4:
                return OperandFlagMetadata;
            default:
                reportUnreachable(CMMC_LOCATION());
        }
    }
    [[nodiscard]] InstFlag getInstFlag() const noexcept override {
        return InstFlagNone | InstFlagLegalizePreRA;
    }
    [[nodiscard]] std::string_view getUniqueName() const noexcept override {
        return "ARM.PseudoFMA";
    }
};

class ARMInstInfoUNIMP final : public InstInfo {
public:
    ARMInstInfoUNIMP() = default;
    void print(std::ostream& out, const MIRInst& inst, bool printComment) const override {
        CMMC_UNUSED(inst);
        out << ".inst 0xdeff";
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
        return "ARM.UNIMP";
    }
};

class ARMInstInfo final : public TargetInstInfo {
    ARMInstInfoADD mInstInfoADD;
    ARMInstInfoSUB mInstInfoSUB;
    ARMInstInfoAND mInstInfoAND;
    ARMInstInfoORR mInstInfoORR;
    ARMInstInfoEOR mInstInfoEOR;
    ARMInstInfoORN mInstInfoORN;
    ARMInstInfoBIC mInstInfoBIC;
    ARMInstInfoRSB mInstInfoRSB;
    ARMInstInfoADDS mInstInfoADDS;
    ARMInstInfoSUBS mInstInfoSUBS;
    ARMInstInfoANDS mInstInfoANDS;
    ARMInstInfoORRS mInstInfoORRS;
    ARMInstInfoEORS mInstInfoEORS;
    ARMInstInfoORNS mInstInfoORNS;
    ARMInstInfoBICS mInstInfoBICS;
    ARMInstInfoRSBS mInstInfoRSBS;
    ARMInstInfoADD_Cond mInstInfoADD_Cond;
    ARMInstInfoSUB_Cond mInstInfoSUB_Cond;
    ARMInstInfoAND_Cond mInstInfoAND_Cond;
    ARMInstInfoORR_Cond mInstInfoORR_Cond;
    ARMInstInfoEOR_Cond mInstInfoEOR_Cond;
    ARMInstInfoORN_Cond mInstInfoORN_Cond;
    ARMInstInfoBIC_Cond mInstInfoBIC_Cond;
    ARMInstInfoRSB_Cond mInstInfoRSB_Cond;
    ARMInstInfoADD_Fused mInstInfoADD_Fused;
    ARMInstInfoSUB_Fused mInstInfoSUB_Fused;
    ARMInstInfoAND_Fused mInstInfoAND_Fused;
    ARMInstInfoORR_Fused mInstInfoORR_Fused;
    ARMInstInfoEOR_Fused mInstInfoEOR_Fused;
    ARMInstInfoORN_Fused mInstInfoORN_Fused;
    ARMInstInfoBIC_Fused mInstInfoBIC_Fused;
    ARMInstInfoRSB_Fused mInstInfoRSB_Fused;
    ARMInstInfoMUL mInstInfoMUL;
    ARMInstInfoSMMUL mInstInfoSMMUL;
    ARMInstInfoSMMLA mInstInfoSMMLA;
    ARMInstInfoMLA mInstInfoMLA;
    ARMInstInfoMLS mInstInfoMLS;
    ARMInstInfoSXTB mInstInfoSXTB;
    ARMInstInfoSXTH mInstInfoSXTH;
    ARMInstInfoUXTB mInstInfoUXTB;
    ARMInstInfoUXTH mInstInfoUXTH;
    ARMInstInfoSDIV mInstInfoSDIV;
    ARMInstInfoUDIV mInstInfoUDIV;
    ARMInstInfoSEL mInstInfoSEL;
    ARMInstInfoMOV_Constant mInstInfoMOV_Constant;
    ARMInstInfoMVN_Constant mInstInfoMVN_Constant;
    ARMInstInfoMOV mInstInfoMOV;
    ARMInstInfoMVN mInstInfoMVN;
    ARMInstInfoMOVS mInstInfoMOVS;
    ARMInstInfoMVNS mInstInfoMVNS;
    ARMInstInfoCLZ mInstInfoCLZ;
    ARMInstInfoMoveGPR mInstInfoMoveGPR;
    ARMInstInfoMOV_Cond mInstInfoMOV_Cond;
    ARMInstInfoMVN_Cond mInstInfoMVN_Cond;
    ARMInstInfoASR mInstInfoASR;
    ARMInstInfoLSL mInstInfoLSL;
    ARMInstInfoLSR mInstInfoLSR;
    ARMInstInfoROR mInstInfoROR;
    ARMInstInfoCMP mInstInfoCMP;
    ARMInstInfoCMN mInstInfoCMN;
    ARMInstInfoB mInstInfoB;
    ARMInstInfoB_Cond mInstInfoB_Cond;
    ARMInstInfoBL mInstInfoBL;
    ARMInstInfoBX mInstInfoBX;
    ARMInstInfoBX_IndirectJump mInstInfoBX_IndirectJump;
    ARMInstInfoVLDR mInstInfoVLDR;
    ARMInstInfoLDR mInstInfoLDR;
    ARMInstInfoLDRB mInstInfoLDRB;
    ARMInstInfoLDRSB mInstInfoLDRSB;
    ARMInstInfoLDRH mInstInfoLDRH;
    ARMInstInfoLDRSH mInstInfoLDRSH;
    ARMInstInfoLDR_Fused mInstInfoLDR_Fused;
    ARMInstInfoLDRB_Fused mInstInfoLDRB_Fused;
    ARMInstInfoLDRSB_Fused mInstInfoLDRSB_Fused;
    ARMInstInfoLDRH_Fused mInstInfoLDRH_Fused;
    ARMInstInfoLDRSH_Fused mInstInfoLDRSH_Fused;
    ARMInstInfoVSTR mInstInfoVSTR;
    ARMInstInfoSTR_Fused mInstInfoSTR_Fused;
    ARMInstInfoSTRB_Fused mInstInfoSTRB_Fused;
    ARMInstInfoSTRH_Fused mInstInfoSTRH_Fused;
    ARMInstInfoSTR mInstInfoSTR;
    ARMInstInfoSTRB mInstInfoSTRB;
    ARMInstInfoSTRH mInstInfoSTRH;
    ARMInstInfoMOVW mInstInfoMOVW;
    ARMInstInfoMOVW_Cond mInstInfoMOVW_Cond;
    ARMInstInfoMOVT mInstInfoMOVT;
    ARMInstInfoVADD_F32 mInstInfoVADD_F32;
    ARMInstInfoVSUB_F32 mInstInfoVSUB_F32;
    ARMInstInfoVMUL_F32 mInstInfoVMUL_F32;
    ARMInstInfoVNMUL_F32 mInstInfoVNMUL_F32;
    ARMInstInfoVDIV_F32 mInstInfoVDIV_F32;
    ARMInstInfoVMLA_F32 mInstInfoVMLA_F32;
    ARMInstInfoVMLS_F32 mInstInfoVMLS_F32;
    ARMInstInfoVNMLA_F32 mInstInfoVNMLA_F32;
    ARMInstInfoVNMLS_F32 mInstInfoVNMLS_F32;
    ARMInstInfoVNEG_F32 mInstInfoVNEG_F32;
    ARMInstInfoVABS_F32 mInstInfoVABS_F32;
    ARMInstInfoVCMP_F32 mInstInfoVCMP_F32;
    ARMInstInfoVCMP_F32_WithZero mInstInfoVCMP_F32_WithZero;
    ARMInstInfoTRANSFER_FPSCR_FLAG mInstInfoTRANSFER_FPSCR_FLAG;
    ARMInstInfoVCVT_F32_S32 mInstInfoVCVT_F32_S32;
    ARMInstInfoVCVT_S32_F32 mInstInfoVCVT_S32_F32;
    ARMInstInfoVMOV mInstInfoVMOV;
    ARMInstInfoVMOV_Cond mInstInfoVMOV_Cond;
    ARMInstInfoVMOV_GPR2FPR mInstInfoVMOV_GPR2FPR;
    ARMInstInfoVMOV_FPR2GPR mInstInfoVMOV_FPR2GPR;
    ARMInstInfoVMOV_Constant mInstInfoVMOV_Constant;
    ARMInstInfoPUSH mInstInfoPUSH;
    ARMInstInfoVPUSH mInstInfoVPUSH;
    ARMInstInfoPOP mInstInfoPOP;
    ARMInstInfoPOP_RET mInstInfoPOP_RET;
    ARMInstInfoVPOP mInstInfoVPOP;
    ARMInstInfoUSAT mInstInfoUSAT;
    ARMInstInfoSSAT mInstInfoSSAT;
    ARMInstInfoMOVT_MOVW_PAIR mInstInfoMOVT_MOVW_PAIR;
    ARMInstInfoNZCVFlag2GPR mInstInfoNZCVFlag2GPR;
    ARMInstInfoSelect_GPR mInstInfoSelect_GPR;
    ARMInstInfoCondArith_GPR mInstInfoCondArith_GPR;
    ARMInstInfoSelect_FPR mInstInfoSelect_FPR;
    ARMInstInfoPseudoIntOpWithOp2_Cond mInstInfoPseudoIntOpWithOp2_Cond;
    ARMInstInfoPseudoSMax mInstInfoPseudoSMax;
    ARMInstInfoPseudoSMin mInstInfoPseudoSMin;
    ARMInstInfoPseudoSMax_Inverted mInstInfoPseudoSMax_Inverted;
    ARMInstInfoPseudoSMin_Inverted mInstInfoPseudoSMin_Inverted;
    ARMInstInfoPseudoFMA mInstInfoPseudoFMA;
    ARMInstInfoUNIMP mInstInfoUNIMP;

public:
    ARMInstInfo() = default;
    const InstInfo& getInstInfo(uint32_t opcode) const override {
        switch(opcode) {
            case ARMInst::ADD:
                return mInstInfoADD;
            case ARMInst::SUB:
                return mInstInfoSUB;
            case ARMInst::AND:
                return mInstInfoAND;
            case ARMInst::ORR:
                return mInstInfoORR;
            case ARMInst::EOR:
                return mInstInfoEOR;
            case ARMInst::ORN:
                return mInstInfoORN;
            case ARMInst::BIC:
                return mInstInfoBIC;
            case ARMInst::RSB:
                return mInstInfoRSB;
            case ARMInst::ADDS:
                return mInstInfoADDS;
            case ARMInst::SUBS:
                return mInstInfoSUBS;
            case ARMInst::ANDS:
                return mInstInfoANDS;
            case ARMInst::ORRS:
                return mInstInfoORRS;
            case ARMInst::EORS:
                return mInstInfoEORS;
            case ARMInst::ORNS:
                return mInstInfoORNS;
            case ARMInst::BICS:
                return mInstInfoBICS;
            case ARMInst::RSBS:
                return mInstInfoRSBS;
            case ARMInst::ADD_Cond:
                return mInstInfoADD_Cond;
            case ARMInst::SUB_Cond:
                return mInstInfoSUB_Cond;
            case ARMInst::AND_Cond:
                return mInstInfoAND_Cond;
            case ARMInst::ORR_Cond:
                return mInstInfoORR_Cond;
            case ARMInst::EOR_Cond:
                return mInstInfoEOR_Cond;
            case ARMInst::ORN_Cond:
                return mInstInfoORN_Cond;
            case ARMInst::BIC_Cond:
                return mInstInfoBIC_Cond;
            case ARMInst::RSB_Cond:
                return mInstInfoRSB_Cond;
            case ARMInst::ADD_Fused:
                return mInstInfoADD_Fused;
            case ARMInst::SUB_Fused:
                return mInstInfoSUB_Fused;
            case ARMInst::AND_Fused:
                return mInstInfoAND_Fused;
            case ARMInst::ORR_Fused:
                return mInstInfoORR_Fused;
            case ARMInst::EOR_Fused:
                return mInstInfoEOR_Fused;
            case ARMInst::ORN_Fused:
                return mInstInfoORN_Fused;
            case ARMInst::BIC_Fused:
                return mInstInfoBIC_Fused;
            case ARMInst::RSB_Fused:
                return mInstInfoRSB_Fused;
            case ARMInst::MUL:
                return mInstInfoMUL;
            case ARMInst::SMMUL:
                return mInstInfoSMMUL;
            case ARMInst::SMMLA:
                return mInstInfoSMMLA;
            case ARMInst::MLA:
                return mInstInfoMLA;
            case ARMInst::MLS:
                return mInstInfoMLS;
            case ARMInst::SXTB:
                return mInstInfoSXTB;
            case ARMInst::SXTH:
                return mInstInfoSXTH;
            case ARMInst::UXTB:
                return mInstInfoUXTB;
            case ARMInst::UXTH:
                return mInstInfoUXTH;
            case ARMInst::SDIV:
                return mInstInfoSDIV;
            case ARMInst::UDIV:
                return mInstInfoUDIV;
            case ARMInst::SEL:
                return mInstInfoSEL;
            case ARMInst::MOV_Constant:
                return mInstInfoMOV_Constant;
            case ARMInst::MVN_Constant:
                return mInstInfoMVN_Constant;
            case ARMInst::MOV:
                return mInstInfoMOV;
            case ARMInst::MVN:
                return mInstInfoMVN;
            case ARMInst::MOVS:
                return mInstInfoMOVS;
            case ARMInst::MVNS:
                return mInstInfoMVNS;
            case ARMInst::CLZ:
                return mInstInfoCLZ;
            case ARMInst::MoveGPR:
                return mInstInfoMoveGPR;
            case ARMInst::MOV_Cond:
                return mInstInfoMOV_Cond;
            case ARMInst::MVN_Cond:
                return mInstInfoMVN_Cond;
            case ARMInst::ASR:
                return mInstInfoASR;
            case ARMInst::LSL:
                return mInstInfoLSL;
            case ARMInst::LSR:
                return mInstInfoLSR;
            case ARMInst::ROR:
                return mInstInfoROR;
            case ARMInst::CMP:
                return mInstInfoCMP;
            case ARMInst::CMN:
                return mInstInfoCMN;
            case ARMInst::B:
                return mInstInfoB;
            case ARMInst::B_Cond:
                return mInstInfoB_Cond;
            case ARMInst::BL:
                return mInstInfoBL;
            case ARMInst::BX:
                return mInstInfoBX;
            case ARMInst::BX_IndirectJump:
                return mInstInfoBX_IndirectJump;
            case ARMInst::VLDR:
                return mInstInfoVLDR;
            case ARMInst::LDR:
                return mInstInfoLDR;
            case ARMInst::LDRB:
                return mInstInfoLDRB;
            case ARMInst::LDRSB:
                return mInstInfoLDRSB;
            case ARMInst::LDRH:
                return mInstInfoLDRH;
            case ARMInst::LDRSH:
                return mInstInfoLDRSH;
            case ARMInst::LDR_Fused:
                return mInstInfoLDR_Fused;
            case ARMInst::LDRB_Fused:
                return mInstInfoLDRB_Fused;
            case ARMInst::LDRSB_Fused:
                return mInstInfoLDRSB_Fused;
            case ARMInst::LDRH_Fused:
                return mInstInfoLDRH_Fused;
            case ARMInst::LDRSH_Fused:
                return mInstInfoLDRSH_Fused;
            case ARMInst::VSTR:
                return mInstInfoVSTR;
            case ARMInst::STR_Fused:
                return mInstInfoSTR_Fused;
            case ARMInst::STRB_Fused:
                return mInstInfoSTRB_Fused;
            case ARMInst::STRH_Fused:
                return mInstInfoSTRH_Fused;
            case ARMInst::STR:
                return mInstInfoSTR;
            case ARMInst::STRB:
                return mInstInfoSTRB;
            case ARMInst::STRH:
                return mInstInfoSTRH;
            case ARMInst::MOVW:
                return mInstInfoMOVW;
            case ARMInst::MOVW_Cond:
                return mInstInfoMOVW_Cond;
            case ARMInst::MOVT:
                return mInstInfoMOVT;
            case ARMInst::VADD_F32:
                return mInstInfoVADD_F32;
            case ARMInst::VSUB_F32:
                return mInstInfoVSUB_F32;
            case ARMInst::VMUL_F32:
                return mInstInfoVMUL_F32;
            case ARMInst::VNMUL_F32:
                return mInstInfoVNMUL_F32;
            case ARMInst::VDIV_F32:
                return mInstInfoVDIV_F32;
            case ARMInst::VMLA_F32:
                return mInstInfoVMLA_F32;
            case ARMInst::VMLS_F32:
                return mInstInfoVMLS_F32;
            case ARMInst::VNMLA_F32:
                return mInstInfoVNMLA_F32;
            case ARMInst::VNMLS_F32:
                return mInstInfoVNMLS_F32;
            case ARMInst::VNEG_F32:
                return mInstInfoVNEG_F32;
            case ARMInst::VABS_F32:
                return mInstInfoVABS_F32;
            case ARMInst::VCMP_F32:
                return mInstInfoVCMP_F32;
            case ARMInst::VCMP_F32_WithZero:
                return mInstInfoVCMP_F32_WithZero;
            case ARMInst::TRANSFER_FPSCR_FLAG:
                return mInstInfoTRANSFER_FPSCR_FLAG;
            case ARMInst::VCVT_F32_S32:
                return mInstInfoVCVT_F32_S32;
            case ARMInst::VCVT_S32_F32:
                return mInstInfoVCVT_S32_F32;
            case ARMInst::VMOV:
                return mInstInfoVMOV;
            case ARMInst::VMOV_Cond:
                return mInstInfoVMOV_Cond;
            case ARMInst::VMOV_GPR2FPR:
                return mInstInfoVMOV_GPR2FPR;
            case ARMInst::VMOV_FPR2GPR:
                return mInstInfoVMOV_FPR2GPR;
            case ARMInst::VMOV_Constant:
                return mInstInfoVMOV_Constant;
            case ARMInst::PUSH:
                return mInstInfoPUSH;
            case ARMInst::VPUSH:
                return mInstInfoVPUSH;
            case ARMInst::POP:
                return mInstInfoPOP;
            case ARMInst::POP_RET:
                return mInstInfoPOP_RET;
            case ARMInst::VPOP:
                return mInstInfoVPOP;
            case ARMInst::USAT:
                return mInstInfoUSAT;
            case ARMInst::SSAT:
                return mInstInfoSSAT;
            case ARMInst::MOVT_MOVW_PAIR:
                return mInstInfoMOVT_MOVW_PAIR;
            case ARMInst::NZCVFlag2GPR:
                return mInstInfoNZCVFlag2GPR;
            case ARMInst::Select_GPR:
                return mInstInfoSelect_GPR;
            case ARMInst::CondArith_GPR:
                return mInstInfoCondArith_GPR;
            case ARMInst::Select_FPR:
                return mInstInfoSelect_FPR;
            case ARMInst::PseudoIntOpWithOp2_Cond:
                return mInstInfoPseudoIntOpWithOp2_Cond;
            case ARMInst::PseudoSMax:
                return mInstInfoPseudoSMax;
            case ARMInst::PseudoSMin:
                return mInstInfoPseudoSMin;
            case ARMInst::PseudoSMax_Inverted:
                return mInstInfoPseudoSMax_Inverted;
            case ARMInst::PseudoSMin_Inverted:
                return mInstInfoPseudoSMin_Inverted;
            case ARMInst::PseudoFMA:
                return mInstInfoPseudoFMA;
            case ARMInst::UNIMP:
                return mInstInfoUNIMP;
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
                case B:
                    target = dynamic_cast<MIRBasicBlock*>(inst.getOperand(0).reloc());
                    prob = 1.0;
                    break;
                case B_Cond:
                    target = dynamic_cast<MIRBasicBlock*>(inst.getOperand(1).reloc());
                    prob = inst.getOperand(3).prob();
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
            case B:
                inst.setOperand<0>(MIROperand::asReloc(target));
                break;
            case B_Cond:
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

const TargetInstInfo& getARMInstInfo() {
    static ARMInstInfo instance;
    return instance;
}

CMMC_TARGET_NAMESPACE_END