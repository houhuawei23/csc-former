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

#include "../../../cmmc/CodeGen/InstInfo.hpp"
#include "../../../cmmc/CodeGen/MIR.hpp"
#include "../../../cmmc/CodeGen/Target.hpp"
#include <RISCV/InstInfoDecl.hpp>

CMMC_TARGET_NAMESPACE_BEGIN

class RISCVInstInfoADDI final : public InstInfo {
public:
  RISCVInstInfoADDI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "addi " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }

  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.ADDI";
  }
};

class RISCVInstInfoSLTI final : public InstInfo {
public:
  RISCVInstInfoSLTI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "slti " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SLTI";
  }
};

class RISCVInstInfoSLTIU final : public InstInfo {
public:
  RISCVInstInfoSLTIU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sltiu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SLTIU";
  }
};

class RISCVInstInfoANDI final : public InstInfo {
public:
  RISCVInstInfoANDI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "andi " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.ANDI";
  }
};

class RISCVInstInfoORI final : public InstInfo {
public:
  RISCVInstInfoORI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "ori " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.ORI";
  }
};

class RISCVInstInfoXORI final : public InstInfo {
public:
  RISCVInstInfoXORI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "xori " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.XORI";
  }
};

class RISCVInstInfoSLLI final : public InstInfo {
public:
  RISCVInstInfoSLLI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "slli " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandUImm6(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SLLI";
  }
};

class RISCVInstInfoSRLI final : public InstInfo {
public:
  RISCVInstInfoSRLI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "srli " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandUImm6(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SRLI";
  }
};

class RISCVInstInfoSRAI final : public InstInfo {
public:
  RISCVInstInfoSRAI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "srai " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandUImm6(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SRAI";
  }
};

class RISCVInstInfoLUI final : public InstInfo {
public:
  RISCVInstInfoLUI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "lui " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandUImm20(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.LUI";
  }
};

class RISCVInstInfoAUIPC final : public InstInfo {
public:
  RISCVInstInfoAUIPC() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "auipc " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandUImm20(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
    case 1:
      return OperandFlagMetadata;
    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  [[nodiscard]] InstFlag getInstFlag() const noexcept override {
    return InstFlagNone | InstFlagPCRel | InstFlagLoadConstant;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.AUIPC";
  }
};

class RISCVInstInfoADD final : public InstInfo {
public:
  RISCVInstInfoADD() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "add " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ADD";
  }
};

class RISCVInstInfoSLT final : public InstInfo {
public:
  RISCVInstInfoSLT() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "slt " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SLT";
  }
};

class RISCVInstInfoSLTU final : public InstInfo {
public:
  RISCVInstInfoSLTU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sltu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SLTU";
  }
};

class RISCVInstInfoAND final : public InstInfo {
public:
  RISCVInstInfoAND() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "and " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.AND";
  }
};

class RISCVInstInfoOR final : public InstInfo {
public:
  RISCVInstInfoOR() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "or " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.OR";
  }
};

class RISCVInstInfoXOR final : public InstInfo {
public:
  RISCVInstInfoXOR() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "xor " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.XOR";
  }
};

class RISCVInstInfoSLL final : public InstInfo {
public:
  RISCVInstInfoSLL() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sll " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SLL";
  }
};

class RISCVInstInfoSRL final : public InstInfo {
public:
  RISCVInstInfoSRL() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "srl " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SRL";
  }
};

class RISCVInstInfoSUB final : public InstInfo {
public:
  RISCVInstInfoSUB() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sub " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SUB";
  }
};

class RISCVInstInfoSRA final : public InstInfo {
public:
  RISCVInstInfoSRA() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sra " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SRA";
  }
};

class RISCVInstInfoJAL final : public InstInfo {
public:
  RISCVInstInfoJAL() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "jal " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(1) &&
           mir::checkISASpecificOperands(inst, ctx, 1) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(0));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 1; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.JAL";
  }
};

class RISCVInstInfoRET final : public InstInfo {
public:
  RISCVInstInfoRET() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "ret";
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(0) &&
           mir::checkISASpecificOperands(inst, ctx, 0);
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 0; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {

    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  [[nodiscard]] InstFlag getInstFlag() const noexcept override {
    return InstFlagNone | InstFlagTerminator | InstFlagReturn |
           InstFlagNoFallthrough;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.RET";
  }
};

class RISCVInstInfoBEQ final : public InstInfo {
public:
  RISCVInstInfoBEQ() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "beq " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BEQ";
  }
};

class RISCVInstInfoBNE final : public InstInfo {
public:
  RISCVInstInfoBNE() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "bne " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BNE";
  }
};

class RISCVInstInfoBLT final : public InstInfo {
public:
  RISCVInstInfoBLT() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "blt " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BLT";
  }
};

class RISCVInstInfoBLE final : public InstInfo {
public:
  RISCVInstInfoBLE() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "ble " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BLE";
  }
};

class RISCVInstInfoBGT final : public InstInfo {
public:
  RISCVInstInfoBGT() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "bgt " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BGT";
  }
};

class RISCVInstInfoBGE final : public InstInfo {
public:
  RISCVInstInfoBGE() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "bge " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BGE";
  }
};

class RISCVInstInfoBLTU final : public InstInfo {
public:
  RISCVInstInfoBLTU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "bltu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BLTU";
  }
};

class RISCVInstInfoBLEU final : public InstInfo {
public:
  RISCVInstInfoBLEU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "bleu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BLEU";
  }
};

class RISCVInstInfoBGTU final : public InstInfo {
public:
  RISCVInstInfoBGTU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "bgtu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BGTU";
  }
};

class RISCVInstInfoBGEU final : public InstInfo {
public:
  RISCVInstInfoBGEU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "bgeu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandProb(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagMetadata;
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
    return "RISCV.BGEU";
  }
};

class RISCVInstInfoJR final : public InstInfo {
public:
  RISCVInstInfoJR() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "jr " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
    case 1:
      return OperandFlagMetadata;
    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  [[nodiscard]] InstFlag getInstFlag() const noexcept override {
    return InstFlagNone | InstFlagTerminator | InstFlagIndirectJump |
           InstFlagNoFallthrough;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.JR";
  }
};

class RISCVInstInfoJ final : public InstInfo {
public:
  RISCVInstInfoJ() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "j " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(1) &&
           mir::checkISASpecificOperands(inst, ctx, 1) &&
           ::cmmc::mir::RISCV::isOperandReloc(inst.getOperand(0));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 1; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagMetadata;
    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  [[nodiscard]] InstFlag getInstFlag() const noexcept override {
    return InstFlagNone | InstFlagTerminator | InstFlagBranch |
           InstFlagNoFallthrough;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.J";
  }
};

class RISCVInstInfoUNIMP final : public InstInfo {
public:
  RISCVInstInfoUNIMP() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "unimp";
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(0) &&
           mir::checkISASpecificOperands(inst, ctx, 0);
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 0; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {

    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  [[nodiscard]] InstFlag getInstFlag() const noexcept override {
    return InstFlagNone | InstFlagTerminator | InstFlagNoFallthrough;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.UNIMP";
  }
};

class RISCVInstInfoLB final : public InstInfo {
public:
  RISCVInstInfoLB() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "lb " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
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
    return InstFlagNone | InstFlagLoad;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LB";
  }
};

class RISCVInstInfoLH final : public InstInfo {
public:
  RISCVInstInfoLH() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "lh " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
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
    return InstFlagNone | InstFlagLoad;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LH";
  }
};

class RISCVInstInfoLW final : public InstInfo {
public:
  RISCVInstInfoLW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "lw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
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
    return InstFlagNone | InstFlagLoad;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LW";
  }
};

class RISCVInstInfoLBU final : public InstInfo {
public:
  RISCVInstInfoLBU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "lbu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
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
    return InstFlagNone | InstFlagLoad;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LBU";
  }
};

class RISCVInstInfoLHU final : public InstInfo {
public:
  RISCVInstInfoLHU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "lhu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
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
    return InstFlagNone | InstFlagLoad;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LHU";
  }
};

class RISCVInstInfoSB final : public InstInfo {
public:
  RISCVInstInfoSB() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sb " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
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
    return InstFlagNone | InstFlagStore;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SB";
  }
};

class RISCVInstInfoSH final : public InstInfo {
public:
  RISCVInstInfoSH() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sh " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
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
    return InstFlagNone | InstFlagStore;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SH";
  }
};

class RISCVInstInfoSW final : public InstInfo {
public:
  RISCVInstInfoSW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
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
    return InstFlagNone | InstFlagStore;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SW";
  }
};

class RISCVInstInfoAMOADD_W final : public InstInfo {
public:
  RISCVInstInfoAMOADD_W() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "amoadd.w.aqrl "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", ("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone | InstFlagLoad | InstFlagStore;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.AMOADD_W";
  }
};

class RISCVInstInfoADDIW final : public InstInfo {
public:
  RISCVInstInfoADDIW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "addiw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.ADDIW";
  }
};

class RISCVInstInfoSLLIW final : public InstInfo {
public:
  RISCVInstInfoSLLIW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "slliw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandUImm5(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SLLIW";
  }
};

class RISCVInstInfoSRLIW final : public InstInfo {
public:
  RISCVInstInfoSRLIW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "srliw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandUImm5(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SRLIW";
  }
};

class RISCVInstInfoSRAIW final : public InstInfo {
public:
  RISCVInstInfoSRAIW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sraiw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandUImm5(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return InstFlagNone;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SRAIW";
  }
};

class RISCVInstInfoADDW final : public InstInfo {
public:
  RISCVInstInfoADDW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "addw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ADDW";
  }
};

class RISCVInstInfoSUBW final : public InstInfo {
public:
  RISCVInstInfoSUBW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "subw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SUBW";
  }
};

class RISCVInstInfoSLLW final : public InstInfo {
public:
  RISCVInstInfoSLLW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sllw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SLLW";
  }
};

class RISCVInstInfoSRLW final : public InstInfo {
public:
  RISCVInstInfoSRLW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "srlw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SRLW";
  }
};

class RISCVInstInfoSRAW final : public InstInfo {
public:
  RISCVInstInfoSRAW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sraw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SRAW";
  }
};

class RISCVInstInfoLD final : public InstInfo {
public:
  RISCVInstInfoLD() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "ld " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
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
    return InstFlagNone | InstFlagLoad;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LD";
  }
};

class RISCVInstInfoLWU final : public InstInfo {
public:
  RISCVInstInfoLWU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "lwu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
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
    return InstFlagNone | InstFlagLoad;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LWU";
  }
};

class RISCVInstInfoSD final : public InstInfo {
public:
  RISCVInstInfoSD() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sd " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
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
    return InstFlagNone | InstFlagStore;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.SD";
  }
};

class RISCVInstInfoMUL final : public InstInfo {
public:
  RISCVInstInfoMUL() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "mul " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MUL";
  }
};

class RISCVInstInfoMULH final : public InstInfo {
public:
  RISCVInstInfoMULH() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "mulh " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MULH";
  }
};

class RISCVInstInfoMULHSU final : public InstInfo {
public:
  RISCVInstInfoMULHSU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "mulhsu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MULHSU";
  }
};

class RISCVInstInfoMULHU final : public InstInfo {
public:
  RISCVInstInfoMULHU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "mulhu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MULHU";
  }
};

class RISCVInstInfoMULW final : public InstInfo {
public:
  RISCVInstInfoMULW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "mulw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MULW";
  }
};

class RISCVInstInfoDIV final : public InstInfo {
public:
  RISCVInstInfoDIV() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "div " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.DIV";
  }
};

class RISCVInstInfoDIVU final : public InstInfo {
public:
  RISCVInstInfoDIVU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "divu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.DIVU";
  }
};

class RISCVInstInfoREM final : public InstInfo {
public:
  RISCVInstInfoREM() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "rem " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.REM";
  }
};

class RISCVInstInfoREMU final : public InstInfo {
public:
  RISCVInstInfoREMU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "remu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.REMU";
  }
};

class RISCVInstInfoDIVUW final : public InstInfo {
public:
  RISCVInstInfoDIVUW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "divuw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.DIVUW";
  }
};

class RISCVInstInfoREMUW final : public InstInfo {
public:
  RISCVInstInfoREMUW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "remuw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.REMUW";
  }
};

class RISCVInstInfoDIVW final : public InstInfo {
public:
  RISCVInstInfoDIVW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "divw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)}
          << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(4)}
          << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(5)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(6) &&
           mir::checkISASpecificOperands(inst, ctx, 6) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandImm(inst.getOperand(3)) &&
           ::cmmc::mir::RISCV::isOperandImm(inst.getOperand(4)) &&
           ::cmmc::mir::RISCV::isOperandImm(inst.getOperand(5));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 6; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.DIVW";
  }
};

class RISCVInstInfoREMW final : public InstInfo {
public:
  RISCVInstInfoREMW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "remw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)}
          << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(4)}
          << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(5)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(6) &&
           mir::checkISASpecificOperands(inst, ctx, 6) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandImm(inst.getOperand(3)) &&
           ::cmmc::mir::RISCV::isOperandImm(inst.getOperand(4)) &&
           ::cmmc::mir::RISCV::isOperandImm(inst.getOperand(5));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 6; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.REMW";
  }
};

class RISCVInstInfoFLW final : public InstInfo {
public:
  RISCVInstInfoFLW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "flw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
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
    return InstFlagNone | InstFlagLoad;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.FLW";
  }
};

class RISCVInstInfoFSW final : public InstInfo {
public:
  RISCVInstInfoFSW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fsw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << "("
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ")";
    if (printComment)
      out << " # " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandImm12(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandBaseLike(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandAlign(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagUse;
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
    return InstFlagNone | InstFlagStore;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.FSW";
  }
};

class RISCVInstInfoFADD_S final : public InstInfo {
public:
  RISCVInstInfoFADD_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fadd.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FADD_S";
  }
};

class RISCVInstInfoFSUB_S final : public InstInfo {
public:
  RISCVInstInfoFSUB_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fsub.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FSUB_S";
  }
};

class RISCVInstInfoFMUL_S final : public InstInfo {
public:
  RISCVInstInfoFMUL_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fmul.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FMUL_S";
  }
};

class RISCVInstInfoFDIV_S final : public InstInfo {
public:
  RISCVInstInfoFDIV_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fdiv.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FDIV_S";
  }
};

class RISCVInstInfoFMIN_S final : public InstInfo {
public:
  RISCVInstInfoFMIN_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fmin.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FMIN_S";
  }
};

class RISCVInstInfoFMAX_S final : public InstInfo {
public:
  RISCVInstInfoFMAX_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fmax.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FMAX_S";
  }
};

class RISCVInstInfoFNEG_S final : public InstInfo {
public:
  RISCVInstInfoFNEG_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fneg.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FNEG_S";
  }
};

class RISCVInstInfoFABS_S final : public InstInfo {
public:
  RISCVInstInfoFABS_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fabs.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FABS_S";
  }
};

class RISCVInstInfoFSGNJ_S final : public InstInfo {
public:
  RISCVInstInfoFSGNJ_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fsgnj.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FSGNJ_S";
  }
};

class RISCVInstInfoFMV_S final : public InstInfo {
public:
  RISCVInstInfoFMV_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fmv.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FMV_S";
  }
};

class RISCVInstInfoFCVT_W_S final : public InstInfo {
public:
  RISCVInstInfoFCVT_W_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fcvt.w.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)}
        << ", rtz";
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FCVT_W_S";
  }
};

class RISCVInstInfoFCVT_WU_S final : public InstInfo {
public:
  RISCVInstInfoFCVT_WU_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fcvt.wu.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)}
        << ", rtz";
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FCVT_WU_S";
  }
};

class RISCVInstInfoFCLASS_S final : public InstInfo {
public:
  RISCVInstInfoFCLASS_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fclass.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FCLASS_S";
  }
};

class RISCVInstInfoFMV_X_W final : public InstInfo {
public:
  RISCVInstInfoFMV_X_W() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fmv.x.w " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FMV_X_W";
  }
};

class RISCVInstInfoFEQ_S final : public InstInfo {
public:
  RISCVInstInfoFEQ_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "feq.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FEQ_S";
  }
};

class RISCVInstInfoFLT_S final : public InstInfo {
public:
  RISCVInstInfoFLT_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "flt.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FLT_S";
  }
};

class RISCVInstInfoFLE_S final : public InstInfo {
public:
  RISCVInstInfoFLE_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fle.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FLE_S";
  }
};

class RISCVInstInfoFMV_W_X final : public InstInfo {
public:
  RISCVInstInfoFMV_W_X() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fmv.w.x " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FMV_W_X";
  }
};

class RISCVInstInfoFCVT_S_W final : public InstInfo {
public:
  RISCVInstInfoFCVT_S_W() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fcvt.s.w " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FCVT_S_W";
  }
};

class RISCVInstInfoFCVT_S_WU final : public InstInfo {
public:
  RISCVInstInfoFCVT_S_WU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fcvt.s.wu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FCVT_S_WU";
  }
};

class RISCVInstInfoFMADD_S final : public InstInfo {
public:
  RISCVInstInfoFMADD_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fmadd.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FMADD_S";
  }
};

class RISCVInstInfoFMSUB_S final : public InstInfo {
public:
  RISCVInstInfoFMSUB_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fmsub.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FMSUB_S";
  }
};

class RISCVInstInfoFNMADD_S final : public InstInfo {
public:
  RISCVInstInfoFNMADD_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fnmadd.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FNMADD_S";
  }
};

class RISCVInstInfoFNMSUB_S final : public InstInfo {
public:
  RISCVInstInfoFNMSUB_S() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "fnmsub.s " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(4) &&
           mir::checkISASpecificOperands(inst, ctx, 4) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(3));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 4; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.FNMSUB_S";
  }
};

class RISCVInstInfoADD_UW final : public InstInfo {
public:
  RISCVInstInfoADD_UW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "add.uw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ADD_UW";
  }
};

class RISCVInstInfoSH1ADD final : public InstInfo {
public:
  RISCVInstInfoSH1ADD() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sh1add " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SH1ADD";
  }
};

class RISCVInstInfoSH1ADD_UW final : public InstInfo {
public:
  RISCVInstInfoSH1ADD_UW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sh1add.uw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SH1ADD_UW";
  }
};

class RISCVInstInfoSH2ADD final : public InstInfo {
public:
  RISCVInstInfoSH2ADD() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sh2add " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SH2ADD";
  }
};

class RISCVInstInfoSH2ADD_UW final : public InstInfo {
public:
  RISCVInstInfoSH2ADD_UW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sh2add.uw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SH2ADD_UW";
  }
};

class RISCVInstInfoSH3ADD final : public InstInfo {
public:
  RISCVInstInfoSH3ADD() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sh3add " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SH3ADD";
  }
};

class RISCVInstInfoSH3ADD_UW final : public InstInfo {
public:
  RISCVInstInfoSH3ADD_UW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sh3add.uw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SH3ADD_UW";
  }
};

class RISCVInstInfoSLLI_UW final : public InstInfo {
public:
  RISCVInstInfoSLLI_UW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "slli.uw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SLLI_UW";
  }
};

class RISCVInstInfoANDN final : public InstInfo {
public:
  RISCVInstInfoANDN() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "andn " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ANDN";
  }
};

class RISCVInstInfoORN final : public InstInfo {
public:
  RISCVInstInfoORN() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "orn " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ORN";
  }
};

class RISCVInstInfoXNOR final : public InstInfo {
public:
  RISCVInstInfoXNOR() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "xnor " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.XNOR";
  }
};

class RISCVInstInfoMIN final : public InstInfo {
public:
  RISCVInstInfoMIN() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "min " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MIN";
  }
};

class RISCVInstInfoMINU final : public InstInfo {
public:
  RISCVInstInfoMINU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "minu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MINU";
  }
};

class RISCVInstInfoMAX final : public InstInfo {
public:
  RISCVInstInfoMAX() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "max " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MAX";
  }
};

class RISCVInstInfoMAXU final : public InstInfo {
public:
  RISCVInstInfoMAXU() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "maxu " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MAXU";
  }
};

class RISCVInstInfoROL final : public InstInfo {
public:
  RISCVInstInfoROL() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "rol " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ROL";
  }
};

class RISCVInstInfoROLW final : public InstInfo {
public:
  RISCVInstInfoROLW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "rolw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ROLW";
  }
};

class RISCVInstInfoROR final : public InstInfo {
public:
  RISCVInstInfoROR() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "ror " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ROR";
  }
};

class RISCVInstInfoRORI final : public InstInfo {
public:
  RISCVInstInfoRORI() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "rori " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.RORI";
  }
};

class RISCVInstInfoRORIW final : public InstInfo {
public:
  RISCVInstInfoRORIW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "roriw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.RORIW";
  }
};

class RISCVInstInfoRORW final : public InstInfo {
public:
  RISCVInstInfoRORW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "rorw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(3) &&
           mir::checkISASpecificOperands(inst, ctx, 3) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 3; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.RORW";
  }
};

class RISCVInstInfoSEXT_B final : public InstInfo {
public:
  RISCVInstInfoSEXT_B() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sext.b " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SEXT_B";
  }
};

class RISCVInstInfoSEXT_H final : public InstInfo {
public:
  RISCVInstInfoSEXT_H() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sext.h " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SEXT_H";
  }
};

class RISCVInstInfoSEXT_W final : public InstInfo {
public:
  RISCVInstInfoSEXT_W() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "sext.w " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.SEXT_W";
  }
};

class RISCVInstInfoZEXT_H final : public InstInfo {
public:
  RISCVInstInfoZEXT_H() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "zext.h " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ZEXT_H";
  }
};

class RISCVInstInfoZEXT_W final : public InstInfo {
public:
  RISCVInstInfoZEXT_W() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "zext.w " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ZEXT_W";
  }
};

class RISCVInstInfoCLZ final : public InstInfo {
public:
  RISCVInstInfoCLZ() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "clz " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.CLZ";
  }
};

class RISCVInstInfoCLZW final : public InstInfo {
public:
  RISCVInstInfoCLZW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "clzw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.CLZW";
  }
};

class RISCVInstInfoCTZ final : public InstInfo {
public:
  RISCVInstInfoCTZ() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "ctz " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.CTZ";
  }
};

class RISCVInstInfoCTZW final : public InstInfo {
public:
  RISCVInstInfoCTZW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "ctzw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.CTZW";
  }
};

class RISCVInstInfoCPOP final : public InstInfo {
public:
  RISCVInstInfoCPOP() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "cpop " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.CPOP";
  }
};

class RISCVInstInfoCPOPW final : public InstInfo {
public:
  RISCVInstInfoCPOPW() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "cpopw " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.CPOPW";
  }
};

class RISCVInstInfoORC_B final : public InstInfo {
public:
  RISCVInstInfoORC_B() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "orc.b " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.ORC_B";
  }
};

class RISCVInstInfoREV8 final : public InstInfo {
public:
  RISCVInstInfoREV8() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "rev8 " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.REV8";
  }
};

class RISCVInstInfoLoadImm12 final : public InstInfo {
public:
  RISCVInstInfoLoadImm12() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "li " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandNonZeroImm12(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.LoadImm12";
  }
};

class RISCVInstInfoLoadImm32 final : public InstInfo {
public:
  RISCVInstInfoLoadImm32() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "li " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandNonZeroImm32(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
    case 1:
      return OperandFlagMetadata;
    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  [[nodiscard]] InstFlag getInstFlag() const noexcept override {
    return InstFlagNone | InstFlagLegalizePreRA | InstFlagLoadConstant;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LoadImm32";
  }
};

class RISCVInstInfoLoadImm64 final : public InstInfo {
public:
  RISCVInstInfoLoadImm64() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "li " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandNonZeroImm64(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
    case 1:
      return OperandFlagMetadata;
    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  [[nodiscard]] InstFlag getInstFlag() const noexcept override {
    return InstFlagNone | InstFlagLegalizePreRA | InstFlagLoadConstant;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.LoadImm64";
  }
};

class RISCVInstInfoLoadImm64Complex final : public InstInfo {
public:
  RISCVInstInfoLoadImm64Complex() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "li " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandNonZeroImm64(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.LoadImm64Complex";
  }
};

class RISCVInstInfoMoveGPR final : public InstInfo {
public:
  RISCVInstInfoMoveGPR() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "mv " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)}
        << ", " << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(2) &&
           mir::checkISASpecificOperands(inst, ctx, 2) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 2; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
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
    return "RISCV.MoveGPR";
  }
};

class RISCVInstInfoSelect_GPR_GPR final : public InstInfo {
public:
  RISCVInstInfoSelect_GPR_GPR() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "select_gpr_gpr "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(4)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(5)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(6) &&
           mir::checkISASpecificOperands(inst, ctx, 6) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandIRegOrImm(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandIRegOrImm(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(3)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(4)) &&
           ::cmmc::mir::RISCV::isOperandCC(inst.getOperand(5));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 6; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagUse;
    case 3:
      return OperandFlagUse;
    case 4:
      return OperandFlagUse;
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
    return "RISCV.Select_GPR_GPR";
  }
};

class RISCVInstInfoSelect_GPR_Arith final : public InstInfo {
public:
  RISCVInstInfoSelect_GPR_Arith() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "select_gpr_arith "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(4)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(5)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(6)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(7) &&
           mir::checkISASpecificOperands(inst, ctx, 7) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(3)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(4)) &&
           ::cmmc::mir::RISCV::isOperandCC(inst.getOperand(5)) &&
           ::cmmc::mir::RISCV::isOperandImm(inst.getOperand(6));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 7; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagUse;
    case 3:
      return OperandFlagUse;
    case 4:
      return OperandFlagUse;
    case 5:
      return OperandFlagMetadata;
    case 6:
      return OperandFlagMetadata;
    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  [[nodiscard]] InstFlag getInstFlag() const noexcept override {
    return InstFlagNone | InstFlagLegalizePreRA;
  }
  [[nodiscard]] std::string_view getUniqueName() const noexcept override {
    return "RISCV.Select_GPR_Arith";
  }
};

class RISCVInstInfoSelect_FPR_GPR final : public InstInfo {
public:
  RISCVInstInfoSelect_FPR_GPR() = default;
  void print(std::ostream &out, const MIRInst &inst,
             bool printComment) const override {
    CMMC_UNUSED(inst);
    out << "select_fpr_gpr "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(0)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(1)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(2)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(3)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(4)} << ", "
        << ::cmmc::mir::RISCV::OperandDumper{inst.getOperand(5)};
    CMMC_UNUSED(printComment);
  }
  [[nodiscard]] bool verify(const MIRInst &inst,
                            const CodeGenContext &ctx) const override {
    return inst.checkOperandCount(6) &&
           mir::checkISASpecificOperands(inst, ctx, 6) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(0)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(1)) &&
           ::cmmc::mir::RISCV::isOperandFPR(inst.getOperand(2)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(3)) &&
           ::cmmc::mir::RISCV::isOperandGPR(inst.getOperand(4)) &&
           ::cmmc::mir::RISCV::isOperandCC(inst.getOperand(5));
  }
  [[nodiscard]] uint32_t getOperandNum() const noexcept override { return 6; }
  [[nodiscard]] OperandFlag
  getOperandFlag(uint32_t idx) const noexcept override {
    switch (idx) {
    case 0:
      return OperandFlagDef;
    case 1:
      return OperandFlagUse;
    case 2:
      return OperandFlagUse;
    case 3:
      return OperandFlagUse;
    case 4:
      return OperandFlagUse;
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
    return "RISCV.Select_FPR_GPR";
  }
};

class RISCVInstInfo final : public TargetInstInfo {
  RISCVInstInfoADDI mInstInfoADDI;
  RISCVInstInfoSLTI mInstInfoSLTI;
  RISCVInstInfoSLTIU mInstInfoSLTIU;
  RISCVInstInfoANDI mInstInfoANDI;
  RISCVInstInfoORI mInstInfoORI;
  RISCVInstInfoXORI mInstInfoXORI;
  RISCVInstInfoSLLI mInstInfoSLLI;
  RISCVInstInfoSRLI mInstInfoSRLI;
  RISCVInstInfoSRAI mInstInfoSRAI;
  RISCVInstInfoLUI mInstInfoLUI;
  RISCVInstInfoAUIPC mInstInfoAUIPC;
  RISCVInstInfoADD mInstInfoADD;
  RISCVInstInfoSLT mInstInfoSLT;
  RISCVInstInfoSLTU mInstInfoSLTU;
  RISCVInstInfoAND mInstInfoAND;
  RISCVInstInfoOR mInstInfoOR;
  RISCVInstInfoXOR mInstInfoXOR;
  RISCVInstInfoSLL mInstInfoSLL;
  RISCVInstInfoSRL mInstInfoSRL;
  RISCVInstInfoSUB mInstInfoSUB;
  RISCVInstInfoSRA mInstInfoSRA;
  RISCVInstInfoJAL mInstInfoJAL;
  RISCVInstInfoRET mInstInfoRET;
  RISCVInstInfoBEQ mInstInfoBEQ;
  RISCVInstInfoBNE mInstInfoBNE;
  RISCVInstInfoBLT mInstInfoBLT;
  RISCVInstInfoBLE mInstInfoBLE;
  RISCVInstInfoBGT mInstInfoBGT;
  RISCVInstInfoBGE mInstInfoBGE;
  RISCVInstInfoBLTU mInstInfoBLTU;
  RISCVInstInfoBLEU mInstInfoBLEU;
  RISCVInstInfoBGTU mInstInfoBGTU;
  RISCVInstInfoBGEU mInstInfoBGEU;
  RISCVInstInfoJR mInstInfoJR;
  RISCVInstInfoJ mInstInfoJ;
  RISCVInstInfoUNIMP mInstInfoUNIMP;
  RISCVInstInfoLB mInstInfoLB;
  RISCVInstInfoLH mInstInfoLH;
  RISCVInstInfoLW mInstInfoLW;
  RISCVInstInfoLBU mInstInfoLBU;
  RISCVInstInfoLHU mInstInfoLHU;
  RISCVInstInfoSB mInstInfoSB;
  RISCVInstInfoSH mInstInfoSH;
  RISCVInstInfoSW mInstInfoSW;
  RISCVInstInfoAMOADD_W mInstInfoAMOADD_W;
  RISCVInstInfoADDIW mInstInfoADDIW;
  RISCVInstInfoSLLIW mInstInfoSLLIW;
  RISCVInstInfoSRLIW mInstInfoSRLIW;
  RISCVInstInfoSRAIW mInstInfoSRAIW;
  RISCVInstInfoADDW mInstInfoADDW;
  RISCVInstInfoSUBW mInstInfoSUBW;
  RISCVInstInfoSLLW mInstInfoSLLW;
  RISCVInstInfoSRLW mInstInfoSRLW;
  RISCVInstInfoSRAW mInstInfoSRAW;
  RISCVInstInfoLD mInstInfoLD;
  RISCVInstInfoLWU mInstInfoLWU;
  RISCVInstInfoSD mInstInfoSD;
  RISCVInstInfoMUL mInstInfoMUL;
  RISCVInstInfoMULH mInstInfoMULH;
  RISCVInstInfoMULHSU mInstInfoMULHSU;
  RISCVInstInfoMULHU mInstInfoMULHU;
  RISCVInstInfoMULW mInstInfoMULW;
  RISCVInstInfoDIV mInstInfoDIV;
  RISCVInstInfoDIVU mInstInfoDIVU;
  RISCVInstInfoREM mInstInfoREM;
  RISCVInstInfoREMU mInstInfoREMU;
  RISCVInstInfoDIVUW mInstInfoDIVUW;
  RISCVInstInfoREMUW mInstInfoREMUW;
  RISCVInstInfoDIVW mInstInfoDIVW;
  RISCVInstInfoREMW mInstInfoREMW;
  RISCVInstInfoFLW mInstInfoFLW;
  RISCVInstInfoFSW mInstInfoFSW;
  RISCVInstInfoFADD_S mInstInfoFADD_S;
  RISCVInstInfoFSUB_S mInstInfoFSUB_S;
  RISCVInstInfoFMUL_S mInstInfoFMUL_S;
  RISCVInstInfoFDIV_S mInstInfoFDIV_S;
  RISCVInstInfoFMIN_S mInstInfoFMIN_S;
  RISCVInstInfoFMAX_S mInstInfoFMAX_S;
  RISCVInstInfoFNEG_S mInstInfoFNEG_S;
  RISCVInstInfoFABS_S mInstInfoFABS_S;
  RISCVInstInfoFSGNJ_S mInstInfoFSGNJ_S;
  RISCVInstInfoFMV_S mInstInfoFMV_S;
  RISCVInstInfoFCVT_W_S mInstInfoFCVT_W_S;
  RISCVInstInfoFCVT_WU_S mInstInfoFCVT_WU_S;
  RISCVInstInfoFCLASS_S mInstInfoFCLASS_S;
  RISCVInstInfoFMV_X_W mInstInfoFMV_X_W;
  RISCVInstInfoFEQ_S mInstInfoFEQ_S;
  RISCVInstInfoFLT_S mInstInfoFLT_S;
  RISCVInstInfoFLE_S mInstInfoFLE_S;
  RISCVInstInfoFMV_W_X mInstInfoFMV_W_X;
  RISCVInstInfoFCVT_S_W mInstInfoFCVT_S_W;
  RISCVInstInfoFCVT_S_WU mInstInfoFCVT_S_WU;
  RISCVInstInfoFMADD_S mInstInfoFMADD_S;
  RISCVInstInfoFMSUB_S mInstInfoFMSUB_S;
  RISCVInstInfoFNMADD_S mInstInfoFNMADD_S;
  RISCVInstInfoFNMSUB_S mInstInfoFNMSUB_S;
  RISCVInstInfoADD_UW mInstInfoADD_UW;
  RISCVInstInfoSH1ADD mInstInfoSH1ADD;
  RISCVInstInfoSH1ADD_UW mInstInfoSH1ADD_UW;
  RISCVInstInfoSH2ADD mInstInfoSH2ADD;
  RISCVInstInfoSH2ADD_UW mInstInfoSH2ADD_UW;
  RISCVInstInfoSH3ADD mInstInfoSH3ADD;
  RISCVInstInfoSH3ADD_UW mInstInfoSH3ADD_UW;
  RISCVInstInfoSLLI_UW mInstInfoSLLI_UW;
  RISCVInstInfoANDN mInstInfoANDN;
  RISCVInstInfoORN mInstInfoORN;
  RISCVInstInfoXNOR mInstInfoXNOR;
  RISCVInstInfoMIN mInstInfoMIN;
  RISCVInstInfoMINU mInstInfoMINU;
  RISCVInstInfoMAX mInstInfoMAX;
  RISCVInstInfoMAXU mInstInfoMAXU;
  RISCVInstInfoROL mInstInfoROL;
  RISCVInstInfoROLW mInstInfoROLW;
  RISCVInstInfoROR mInstInfoROR;
  RISCVInstInfoRORI mInstInfoRORI;
  RISCVInstInfoRORIW mInstInfoRORIW;
  RISCVInstInfoRORW mInstInfoRORW;
  RISCVInstInfoSEXT_B mInstInfoSEXT_B;
  RISCVInstInfoSEXT_H mInstInfoSEXT_H;
  RISCVInstInfoSEXT_W mInstInfoSEXT_W;
  RISCVInstInfoZEXT_H mInstInfoZEXT_H;
  RISCVInstInfoZEXT_W mInstInfoZEXT_W;
  RISCVInstInfoCLZ mInstInfoCLZ;
  RISCVInstInfoCLZW mInstInfoCLZW;
  RISCVInstInfoCTZ mInstInfoCTZ;
  RISCVInstInfoCTZW mInstInfoCTZW;
  RISCVInstInfoCPOP mInstInfoCPOP;
  RISCVInstInfoCPOPW mInstInfoCPOPW;
  RISCVInstInfoORC_B mInstInfoORC_B;
  RISCVInstInfoREV8 mInstInfoREV8;
  RISCVInstInfoLoadImm12 mInstInfoLoadImm12;
  RISCVInstInfoLoadImm32 mInstInfoLoadImm32;
  RISCVInstInfoLoadImm64 mInstInfoLoadImm64;
  RISCVInstInfoLoadImm64Complex mInstInfoLoadImm64Complex;
  RISCVInstInfoMoveGPR mInstInfoMoveGPR;
  RISCVInstInfoSelect_GPR_GPR mInstInfoSelect_GPR_GPR;
  RISCVInstInfoSelect_GPR_Arith mInstInfoSelect_GPR_Arith;
  RISCVInstInfoSelect_FPR_GPR mInstInfoSelect_FPR_GPR;

public:
  RISCVInstInfo() = default;
  const InstInfo &getInstInfo(uint32_t opcode) const override {
    switch (opcode) {
    case RISCVInst::ADDI:
      return mInstInfoADDI;
    case RISCVInst::SLTI:
      return mInstInfoSLTI;
    case RISCVInst::SLTIU:
      return mInstInfoSLTIU;
    case RISCVInst::ANDI:
      return mInstInfoANDI;
    case RISCVInst::ORI:
      return mInstInfoORI;
    case RISCVInst::XORI:
      return mInstInfoXORI;
    case RISCVInst::SLLI:
      return mInstInfoSLLI;
    case RISCVInst::SRLI:
      return mInstInfoSRLI;
    case RISCVInst::SRAI:
      return mInstInfoSRAI;
    case RISCVInst::LUI:
      return mInstInfoLUI;
    case RISCVInst::AUIPC:
      return mInstInfoAUIPC;
    case RISCVInst::ADD:
      return mInstInfoADD;
    case RISCVInst::SLT:
      return mInstInfoSLT;
    case RISCVInst::SLTU:
      return mInstInfoSLTU;
    case RISCVInst::AND:
      return mInstInfoAND;
    case RISCVInst::OR:
      return mInstInfoOR;
    case RISCVInst::XOR:
      return mInstInfoXOR;
    case RISCVInst::SLL:
      return mInstInfoSLL;
    case RISCVInst::SRL:
      return mInstInfoSRL;
    case RISCVInst::SUB:
      return mInstInfoSUB;
    case RISCVInst::SRA:
      return mInstInfoSRA;
    case RISCVInst::JAL:
      return mInstInfoJAL;
    case RISCVInst::RET:
      return mInstInfoRET;
    case RISCVInst::BEQ:
      return mInstInfoBEQ;
    case RISCVInst::BNE:
      return mInstInfoBNE;
    case RISCVInst::BLT:
      return mInstInfoBLT;
    case RISCVInst::BLE:
      return mInstInfoBLE;
    case RISCVInst::BGT:
      return mInstInfoBGT;
    case RISCVInst::BGE:
      return mInstInfoBGE;
    case RISCVInst::BLTU:
      return mInstInfoBLTU;
    case RISCVInst::BLEU:
      return mInstInfoBLEU;
    case RISCVInst::BGTU:
      return mInstInfoBGTU;
    case RISCVInst::BGEU:
      return mInstInfoBGEU;
    case RISCVInst::JR:
      return mInstInfoJR;
    case RISCVInst::J:
      return mInstInfoJ;
    case RISCVInst::UNIMP:
      return mInstInfoUNIMP;
    case RISCVInst::LB:
      return mInstInfoLB;
    case RISCVInst::LH:
      return mInstInfoLH;
    case RISCVInst::LW:
      return mInstInfoLW;
    case RISCVInst::LBU:
      return mInstInfoLBU;
    case RISCVInst::LHU:
      return mInstInfoLHU;
    case RISCVInst::SB:
      return mInstInfoSB;
    case RISCVInst::SH:
      return mInstInfoSH;
    case RISCVInst::SW:
      return mInstInfoSW;
    case RISCVInst::AMOADD_W:
      return mInstInfoAMOADD_W;
    case RISCVInst::ADDIW:
      return mInstInfoADDIW;
    case RISCVInst::SLLIW:
      return mInstInfoSLLIW;
    case RISCVInst::SRLIW:
      return mInstInfoSRLIW;
    case RISCVInst::SRAIW:
      return mInstInfoSRAIW;
    case RISCVInst::ADDW:
      return mInstInfoADDW;
    case RISCVInst::SUBW:
      return mInstInfoSUBW;
    case RISCVInst::SLLW:
      return mInstInfoSLLW;
    case RISCVInst::SRLW:
      return mInstInfoSRLW;
    case RISCVInst::SRAW:
      return mInstInfoSRAW;
    case RISCVInst::LD:
      return mInstInfoLD;
    case RISCVInst::LWU:
      return mInstInfoLWU;
    case RISCVInst::SD:
      return mInstInfoSD;
    case RISCVInst::MUL:
      return mInstInfoMUL;
    case RISCVInst::MULH:
      return mInstInfoMULH;
    case RISCVInst::MULHSU:
      return mInstInfoMULHSU;
    case RISCVInst::MULHU:
      return mInstInfoMULHU;
    case RISCVInst::MULW:
      return mInstInfoMULW;
    case RISCVInst::DIV:
      return mInstInfoDIV;
    case RISCVInst::DIVU:
      return mInstInfoDIVU;
    case RISCVInst::REM:
      return mInstInfoREM;
    case RISCVInst::REMU:
      return mInstInfoREMU;
    case RISCVInst::DIVUW:
      return mInstInfoDIVUW;
    case RISCVInst::REMUW:
      return mInstInfoREMUW;
    case RISCVInst::DIVW:
      return mInstInfoDIVW;
    case RISCVInst::REMW:
      return mInstInfoREMW;
    case RISCVInst::FLW:
      return mInstInfoFLW;
    case RISCVInst::FSW:
      return mInstInfoFSW;
    case RISCVInst::FADD_S:
      return mInstInfoFADD_S;
    case RISCVInst::FSUB_S:
      return mInstInfoFSUB_S;
    case RISCVInst::FMUL_S:
      return mInstInfoFMUL_S;
    case RISCVInst::FDIV_S:
      return mInstInfoFDIV_S;
    case RISCVInst::FMIN_S:
      return mInstInfoFMIN_S;
    case RISCVInst::FMAX_S:
      return mInstInfoFMAX_S;
    case RISCVInst::FNEG_S:
      return mInstInfoFNEG_S;
    case RISCVInst::FABS_S:
      return mInstInfoFABS_S;
    case RISCVInst::FSGNJ_S:
      return mInstInfoFSGNJ_S;
    case RISCVInst::FMV_S:
      return mInstInfoFMV_S;
    case RISCVInst::FCVT_W_S:
      return mInstInfoFCVT_W_S;
    case RISCVInst::FCVT_WU_S:
      return mInstInfoFCVT_WU_S;
    case RISCVInst::FCLASS_S:
      return mInstInfoFCLASS_S;
    case RISCVInst::FMV_X_W:
      return mInstInfoFMV_X_W;
    case RISCVInst::FEQ_S:
      return mInstInfoFEQ_S;
    case RISCVInst::FLT_S:
      return mInstInfoFLT_S;
    case RISCVInst::FLE_S:
      return mInstInfoFLE_S;
    case RISCVInst::FMV_W_X:
      return mInstInfoFMV_W_X;
    case RISCVInst::FCVT_S_W:
      return mInstInfoFCVT_S_W;
    case RISCVInst::FCVT_S_WU:
      return mInstInfoFCVT_S_WU;
    case RISCVInst::FMADD_S:
      return mInstInfoFMADD_S;
    case RISCVInst::FMSUB_S:
      return mInstInfoFMSUB_S;
    case RISCVInst::FNMADD_S:
      return mInstInfoFNMADD_S;
    case RISCVInst::FNMSUB_S:
      return mInstInfoFNMSUB_S;
    case RISCVInst::ADD_UW:
      return mInstInfoADD_UW;
    case RISCVInst::SH1ADD:
      return mInstInfoSH1ADD;
    case RISCVInst::SH1ADD_UW:
      return mInstInfoSH1ADD_UW;
    case RISCVInst::SH2ADD:
      return mInstInfoSH2ADD;
    case RISCVInst::SH2ADD_UW:
      return mInstInfoSH2ADD_UW;
    case RISCVInst::SH3ADD:
      return mInstInfoSH3ADD;
    case RISCVInst::SH3ADD_UW:
      return mInstInfoSH3ADD_UW;
    case RISCVInst::SLLI_UW:
      return mInstInfoSLLI_UW;
    case RISCVInst::ANDN:
      return mInstInfoANDN;
    case RISCVInst::ORN:
      return mInstInfoORN;
    case RISCVInst::XNOR:
      return mInstInfoXNOR;
    case RISCVInst::MIN:
      return mInstInfoMIN;
    case RISCVInst::MINU:
      return mInstInfoMINU;
    case RISCVInst::MAX:
      return mInstInfoMAX;
    case RISCVInst::MAXU:
      return mInstInfoMAXU;
    case RISCVInst::ROL:
      return mInstInfoROL;
    case RISCVInst::ROLW:
      return mInstInfoROLW;
    case RISCVInst::ROR:
      return mInstInfoROR;
    case RISCVInst::RORI:
      return mInstInfoRORI;
    case RISCVInst::RORIW:
      return mInstInfoRORIW;
    case RISCVInst::RORW:
      return mInstInfoRORW;
    case RISCVInst::SEXT_B:
      return mInstInfoSEXT_B;
    case RISCVInst::SEXT_H:
      return mInstInfoSEXT_H;
    case RISCVInst::SEXT_W:
      return mInstInfoSEXT_W;
    case RISCVInst::ZEXT_H:
      return mInstInfoZEXT_H;
    case RISCVInst::ZEXT_W:
      return mInstInfoZEXT_W;
    case RISCVInst::CLZ:
      return mInstInfoCLZ;
    case RISCVInst::CLZW:
      return mInstInfoCLZW;
    case RISCVInst::CTZ:
      return mInstInfoCTZ;
    case RISCVInst::CTZW:
      return mInstInfoCTZW;
    case RISCVInst::CPOP:
      return mInstInfoCPOP;
    case RISCVInst::CPOPW:
      return mInstInfoCPOPW;
    case RISCVInst::ORC_B:
      return mInstInfoORC_B;
    case RISCVInst::REV8:
      return mInstInfoREV8;
    case RISCVInst::LoadImm12:
      return mInstInfoLoadImm12;
    case RISCVInst::LoadImm32:
      return mInstInfoLoadImm32;
    case RISCVInst::LoadImm64:
      return mInstInfoLoadImm64;
    case RISCVInst::LoadImm64Complex:
      return mInstInfoLoadImm64Complex;
    case RISCVInst::MoveGPR:
      return mInstInfoMoveGPR;
    case RISCVInst::Select_GPR_GPR:
      return mInstInfoSelect_GPR_GPR;
    case RISCVInst::Select_GPR_Arith:
      return mInstInfoSelect_GPR_Arith;
    case RISCVInst::Select_FPR_GPR:
      return mInstInfoSelect_FPR_GPR;
    default:
      return TargetInstInfo::getInstInfo(opcode);
    }
  }
  bool matchBranch(const MIRInst &inst, MIRBasicBlock *&target,
                   double &prob) const override {
    auto &instInfo = getInstInfo(inst.opcode());
    if (requireFlag(instInfo.getInstFlag(), InstFlagBranch)) {
      if (inst.opcode() < ISASpecificBegin)
        return TargetInstInfo::matchBranch(inst, target, prob);
      switch (inst.opcode()) {
      case BEQ:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BNE:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BLT:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BLE:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BGT:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BGE:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BLTU:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BLEU:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BGTU:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case BGEU:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(2).reloc());
        prob = inst.getOperand(3).prob();
        break;
      case J:
        target = dynamic_cast<MIRBasicBlock *>(inst.getOperand(0).reloc());
        prob = 1.0;
        break;
      default:
        reportUnreachable(CMMC_LOCATION());
      }
      return true;
    }
    return false;
  }
  void redirectBranch(MIRInst &inst, MIRBasicBlock *target) const override {
    if (inst.opcode() < ISASpecificBegin)
      return TargetInstInfo::redirectBranch(inst, target);
    assert(
        requireFlag(getInstInfo(inst.opcode()).getInstFlag(), InstFlagBranch));
    switch (inst.opcode()) {
    case BEQ:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BNE:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BLT:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BLE:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BGT:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BGE:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BLTU:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BLEU:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BGTU:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case BGEU:
      inst.setOperand<2>(MIROperand::asReloc(target));
      break;
    case J:
      inst.setOperand<0>(MIROperand::asReloc(target));
      break;
    default:
      reportUnreachable(CMMC_LOCATION());
    }
  }
  MIRInst emitGoto(MIRBasicBlock *target) const override {
    return emitGotoImpl(target);
  }
  void inverseBranch(MIRInst &inst, MIRBasicBlock *newTarget) const override {
    inverseBranchImpl(inst, newTarget);
  }
  std::pair<intmax_t, intmax_t> getAddressingImmRange() const override {
    return getAddressingImmRangeImpl();
  }
};

const TargetInstInfo &getRISCVInstInfo() {
  static RISCVInstInfo instance;
  return instance;
}

CMMC_TARGET_NAMESPACE_END