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

#include "../ARM/ScheduleModelDecl.hpp"
#include "../cmmc/Support/Diagnostics.hpp"
#include "../cmmc/Support/Options.hpp"
#include <iostream>

CMMC_MIR_NAMESPACE_BEGIN
extern StringOpt targetMachine;
CMMC_MIR_NAMESPACE_END

CMMC_TARGET_NAMESPACE_BEGIN

class ARMScheduleModel_cortex_a72 final : public TargetScheduleModel {
    ARMScheduleClassIntegerArithmetic mScheduleClass_IntegerArithmetic;
    ARMScheduleClassIntegerArithmeticConditional mScheduleClass_IntegerArithmeticConditional;
    ARMScheduleClassIntegerArithmeticFused mScheduleClass_IntegerArithmeticFused;
    ARMScheduleClassSaturate mScheduleClass_Saturate;
    ARMScheduleClassMultiply mScheduleClass_Multiply;
    ARMScheduleClassMultiplyAccumulate mScheduleClass_MultiplyAccumulate;
    ARMScheduleClassDivide mScheduleClass_Divide;
    ARMScheduleClassSignedDivide mScheduleClass_SignedDivide;
    ARMScheduleClassBranch mScheduleClass_Branch;
    ARMScheduleClassBranchLink mScheduleClass_BranchLink;
    ARMScheduleClassFPLoad mScheduleClass_FPLoad;
    ARMScheduleClassFPLoadPop mScheduleClass_FPLoadPop;
    ARMScheduleClassLoad mScheduleClass_Load;
    ARMScheduleClassLoadScaledLSL2 mScheduleClass_LoadScaledLSL2;
    ARMScheduleClassLoadScaledOther mScheduleClass_LoadScaledOther;
    ARMScheduleClassPop mScheduleClass_Pop;
    ARMScheduleClassStore mScheduleClass_Store;
    ARMScheduleClassPush mScheduleClass_Push;
    ARMScheduleClassFPArithmetic mScheduleClass_FPArithmetic;
    ARMScheduleClassFPUnaryArithmetic mScheduleClass_FPUnaryArithmetic;
    ARMScheduleClassFPDivide mScheduleClass_FPDivide;
    ARMScheduleClassFPCompare mScheduleClass_FPCompare;
    ARMScheduleClassFPConvert mScheduleClass_FPConvert;
    ARMScheduleClassFPMoveWithCore mScheduleClass_FPMoveWithCore;
    ARMScheduleClassFPFma mScheduleClass_FPFma;
    ARMScheduleClassMisc mScheduleClass_Misc;
    ARMScheduleClassGeneralMove mScheduleClass_GeneralMove;
    ARMScheduleClassGeneralLoad mScheduleClass_GeneralLoad;

public:
    const ScheduleClass& getInstScheClass(uint32_t opcode) const override {
        switch(opcode) {
            case ADD:
            case SUB:
            case AND:
            case ORR:
            case EOR:
            case ORN:
            case BIC:
            case RSB:
            case ADDS:
            case SUBS:
            case ANDS:
            case ORRS:
            case EORS:
            case ORNS:
            case BICS:
            case RSBS:
            case CMP:
            case CMN:
            case InstLoadStackObjectAddr:
            case MOV_Constant:
            case MVN_Constant:
            case MOV:
            case MVN:
            case MOVW:
            case MOVT:
            case MOVT_MOVW_PAIR:
            case MoveGPR:
            case ASR:
            case LSL:
            case LSR:
            case ROR:
            case InstLoadImm:
            case SXTB:
            case SXTH:
            case UXTB:
            case UXTH:
            case SEL:
            case CLZ:
                return mScheduleClass_IntegerArithmetic;
            case ADD_Cond:
            case SUB_Cond:
            case AND_Cond:
            case ORR_Cond:
            case EOR_Cond:
            case ORN_Cond:
            case BIC_Cond:
            case RSB_Cond:
            case MOV_Cond:
            case MVN_Cond:
            case MOVW_Cond:
                return mScheduleClass_IntegerArithmeticConditional;
            case ADD_Fused:
            case SUB_Fused:
            case AND_Fused:
            case ORR_Fused:
            case EOR_Fused:
            case ORN_Fused:
            case BIC_Fused:
            case RSB_Fused:
                return mScheduleClass_IntegerArithmeticFused;
            case USAT:
            case SSAT:
                return mScheduleClass_Saturate;
            case MUL:
            case SMMUL:
                return mScheduleClass_Multiply;
            case MLA:
            case MLS:
            case SMMLA:
                return mScheduleClass_MultiplyAccumulate;
            case UDIV:
                return mScheduleClass_Divide;
            case SDIV:
                return mScheduleClass_SignedDivide;
            case B:
            case B_Cond:
            case BX:
            case BX_IndirectJump:
                return mScheduleClass_Branch;
            case BL:
                return mScheduleClass_BranchLink;
            case VLDR:
                return mScheduleClass_FPLoad;
            case VPOP:
                return mScheduleClass_FPLoadPop;
            case LDR:
            case LDRB:
            case LDRH:
            case LDRSB:
            case LDRSH:
                return mScheduleClass_Load;
            case LDR_Fused:
            case LDRB_Fused:
                return mScheduleClass_LoadScaledLSL2;
            case LDRH_Fused:
            case LDRSB_Fused:
            case LDRSH_Fused:
                return mScheduleClass_LoadScaledOther;
            case POP:
            case POP_RET:
                return mScheduleClass_Pop;
            case STR:
            case STRB:
            case STRH:
            case STR_Fused:
            case STRB_Fused:
            case STRH_Fused:
            case VSTR:
            case InstStoreRegToStack:
                return mScheduleClass_Store;
            case PUSH:
            case VPUSH:
                return mScheduleClass_Push;
            case VADD_F32:
            case VSUB_F32:
            case VMUL_F32:
            case VNMUL_F32:
            case VMOV:
            case VMOV_Cond:
            case VMOV_Constant:
                return mScheduleClass_FPArithmetic;
            case VABS_F32:
            case VNEG_F32:
                return mScheduleClass_FPUnaryArithmetic;
            case VDIV_F32:
                return mScheduleClass_FPDivide;
            case VCMP_F32:
            case VCMP_F32_WithZero:
                return mScheduleClass_FPCompare;
            case VCVT_F32_S32:
            case VCVT_S32_F32:
                return mScheduleClass_FPConvert;
            case VMOV_GPR2FPR:
            case VMOV_FPR2GPR:
                return mScheduleClass_FPMoveWithCore;
            case VMLA_F32:
            case VMLS_F32:
            case VNMLA_F32:
            case VNMLS_F32:
                return mScheduleClass_FPFma;
            case TRANSFER_FPSCR_FLAG:
            case UNIMP:
                return mScheduleClass_Misc;
            case InstCopy:
            case InstCopyFromReg:
            case InstCopyToReg:
                return mScheduleClass_GeneralMove;
            case InstLoadRegFromStack:
                return mScheduleClass_GeneralLoad;
            default:
                std::cerr << "getInstScheClass() failed: unknown op: " << opcode << std::endl;
                reportNotImplemented(CMMC_LOCATION());
        }
    }
    const MicroarchitectureInfo& getInfo() const override;
    bool peepholeOpt(MIRFunction& func, CodeGenContext& ctx) const override;
    bool isExpensiveInst(const MIRInst& inst, const CodeGenContext& ctx) const override;
};

const TargetScheduleModel& getARMScheduleModel() {
    auto machine = targetMachine.get();
    if(machine == "native") {
        machine = "cortex_a72";
    }

    static ARMScheduleModel_cortex_a72 model_cortex_a72;
    if(machine == "cortex_a72") {
        return model_cortex_a72;
    }

    DiagnosticsContext::get().attach<Reason>("Unrecognized target machine").reportFatal();
}

CMMC_TARGET_NAMESPACE_END