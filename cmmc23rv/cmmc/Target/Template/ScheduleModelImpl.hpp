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

#include "../../../cmmc/Support/Diagnostics.hpp"
#include "../../../cmmc/Support/Options.hpp"
#include <RISCV/ScheduleModelDecl.hpp>
#include <iostream>

CMMC_MIR_NAMESPACE_BEGIN
extern StringOpt targetMachine;
CMMC_MIR_NAMESPACE_END

CMMC_TARGET_NAMESPACE_BEGIN

class RISCVScheduleModel_sifive_u74 final : public TargetScheduleModel {
  RISCVScheduleClassIntegerArithmetic mScheduleClass_IntegerArithmetic;
  RISCVScheduleClassSlowLoadImm mScheduleClass_SlowLoadImm;
  RISCVScheduleClassIntegerArithmeticLateB
      mScheduleClass_IntegerArithmeticLateB;
  RISCVScheduleClassIntegerArithmeticEarlyB
      mScheduleClass_IntegerArithmeticEarlyB;
  RISCVScheduleClassIntegerArithmeticLateAB
      mScheduleClass_IntegerArithmeticLateAB;
  RISCVScheduleClassIntegerArithmeticEarlyLateB
      mScheduleClass_IntegerArithmeticEarlyLateB;
  RISCVScheduleClassBranch mScheduleClass_Branch;
  RISCVScheduleClassLoadStore mScheduleClass_LoadStore;
  RISCVScheduleClassMulti mScheduleClass_Multi;
  RISCVScheduleClassDivRem mScheduleClass_DivRem;
  RISCVScheduleClassSDivRemW mScheduleClass_SDivRemW;
  RISCVScheduleClassFPCycle1 mScheduleClass_FPCycle1;
  RISCVScheduleClassFPCycle2 mScheduleClass_FPCycle2;
  RISCVScheduleClassFPCycle4 mScheduleClass_FPCycle4;
  RISCVScheduleClassFPCycle5 mScheduleClass_FPCycle5;
  RISCVScheduleClassFPDiv mScheduleClass_FPDiv;
  RISCVScheduleClassFPLoadStore mScheduleClass_FPLoadStore;
  RISCVScheduleClassGeneralLoad mScheduleClass_GeneralLoad;

public:
  const ScheduleClass &getInstScheClass(uint32_t opcode) const override {
    switch (opcode) {
    case ADDI:
    case SLTI:
    case SLTIU:
    case ANDI:
    case ORI:
    case XORI:
    case SLLI:
    case SRLI:
    case SRAI:
    case LUI:
    case AUIPC:
    case ADD:
    case SLT:
    case SLTU:
    case AND:
    case OR:
    case XOR:
    case SLL:
    case SRL:
    case SUB:
    case SRA:
    case ADDIW:
    case SLLIW:
    case SRLIW:
    case SRAIW:
    case ADDW:
    case SUBW:
    case SLLW:
    case SRLW:
    case SRAW:
    case ADD_UW:
    case SLLI_UW:
    case ANDN:
    case ORN:
    case XNOR:
    case MIN:
    case MINU:
    case MAX:
    case MAXU:
    case SEXT_B:
    case SEXT_H:
    case SEXT_W:
    case ZEXT_H:
    case ZEXT_W:
    case LoadImm12:
    case MoveGPR:
    case InstLoadStackObjectAddr:
    case InstCopy:
    case InstCopyFromReg:
    case InstCopyToReg:
      return mScheduleClass_IntegerArithmetic;
    case InstLoadImm:
    case LoadImm32:
    case LoadImm64:
    case LoadImm64Complex:
      return mScheduleClass_SlowLoadImm;
    case ROL:
    case ROLW:
    case ROR:
    case RORI:
    case RORIW:
    case RORW:
    case CLZ:
    case CLZW:
    case CTZ:
    case CTZW:
    case ORC_B:
      return mScheduleClass_IntegerArithmeticLateB;
    case CPOP:
    case CPOPW:
      return mScheduleClass_IntegerArithmeticEarlyB;
    case REV8:
      return mScheduleClass_IntegerArithmeticLateAB;
    case SH1ADD:
    case SH1ADD_UW:
    case SH2ADD:
    case SH2ADD_UW:
    case SH3ADD:
    case SH3ADD_UW:
      return mScheduleClass_IntegerArithmeticEarlyLateB;
    case JAL:
    case RET:
    case BEQ:
    case BNE:
    case BLT:
    case BLE:
    case BGT:
    case BGE:
    case BLTU:
    case BLEU:
    case BGTU:
    case BGEU:
    case J:
    case JR:
    case UNIMP:
      return mScheduleClass_Branch;
    case LB:
    case LH:
    case LW:
    case LBU:
    case LHU:
    case SB:
    case SH:
    case SW:
    case LD:
    case LWU:
    case SD:
    case InstStoreRegToStack:
    case AMOADD_W:
      return mScheduleClass_LoadStore;
    case MUL:
    case MULH:
    case MULHSU:
    case MULHU:
    case MULW:
      return mScheduleClass_Multi;
    case DIV:
    case DIVU:
    case REM:
    case REMU:
    case DIVUW:
    case REMUW:
      return mScheduleClass_DivRem;
    case DIVW:
    case REMW:
      return mScheduleClass_SDivRemW;
    case FMV_X_W:
      return mScheduleClass_FPCycle1;
    case FNEG_S:
    case FCVT_S_W:
    case FCVT_S_WU:
    case FMV_S:
    case FMV_W_X:
    case FMIN_S:
    case FMAX_S:
    case FSGNJ_S:
    case FABS_S:
      return mScheduleClass_FPCycle2;
    case FEQ_S:
    case FLT_S:
    case FLE_S:
    case FCVT_W_S:
    case FCVT_WU_S:
      return mScheduleClass_FPCycle4;
    case FADD_S:
    case FSUB_S:
    case FMUL_S:
    case FMADD_S:
    case FMSUB_S:
    case FNMADD_S:
    case FNMSUB_S:
      return mScheduleClass_FPCycle5;
    case FDIV_S:
      return mScheduleClass_FPDiv;
    case FLW:
    case FSW:
      return mScheduleClass_FPLoadStore;
    case InstLoadRegFromStack:
      return mScheduleClass_GeneralLoad;
    default:
      std::cerr << "getInstScheClass() failed: unknown op: " << opcode
                << std::endl;
      reportNotImplemented(CMMC_LOCATION());
    }
  }
  const MicroarchitectureInfo &getInfo() const override;
  bool peepholeOpt(MIRFunction &func, CodeGenContext &ctx) const override;
  bool isExpensiveInst(const MIRInst &inst,
                       const CodeGenContext &ctx) const override;
};

const TargetScheduleModel &getRISCVScheduleModel() {
  auto machine = targetMachine.get();
  if (machine == "native") {
    machine = "sifive-u74";
  }

  static RISCVScheduleModel_sifive_u74 model_sifive_u74;
  if (machine == "sifive-u74") {
    return model_sifive_u74;
  }

  DiagnosticsContext::get()
      .attach<Reason>("Unrecognized target machine")
      .reportFatal();
}

CMMC_TARGET_NAMESPACE_END