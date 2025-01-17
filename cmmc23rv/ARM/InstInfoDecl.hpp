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

#pragma once
#include "../cmmc/CodeGen/MIR.hpp"
#include "../cmmc/CodeGen/Target.hpp"

#define CMMC_TARGET_NAMESPACE_BEGIN namespace cmmc::mir::ARM {
#define CMMC_TARGET_NAMESPACE_END }

CMMC_TARGET_NAMESPACE_BEGIN
enum ARMInst {
    ARMInstBegin = ISASpecificBegin,
    ADD,
    SUB,
    AND,
    ORR,
    EOR,
    ORN,
    BIC,
    RSB,
    ADDS,
    SUBS,
    ANDS,
    ORRS,
    EORS,
    ORNS,
    BICS,
    RSBS,
    ADD_Cond,
    SUB_Cond,
    AND_Cond,
    ORR_Cond,
    EOR_Cond,
    ORN_Cond,
    BIC_Cond,
    RSB_Cond,
    ADD_Fused,
    SUB_Fused,
    AND_Fused,
    ORR_Fused,
    EOR_Fused,
    ORN_Fused,
    BIC_Fused,
    RSB_Fused,
    MUL,
    SMMUL,
    SMMLA,
    MLA,
    MLS,
    SXTB,
    SXTH,
    UXTB,
    UXTH,
    SDIV,
    UDIV,
    SEL,
    MOV_Constant,
    MVN_Constant,
    MOV,
    MVN,
    MOVS,
    MVNS,
    CLZ,
    MoveGPR,
    MOV_Cond,
    MVN_Cond,
    ASR,
    LSL,
    LSR,
    ROR,
    CMP,
    CMN,
    B,
    B_Cond,
    BL,
    BX,
    BX_IndirectJump,
    VLDR,
    LDR,
    LDRB,
    LDRSB,
    LDRH,
    LDRSH,
    LDR_Fused,
    LDRB_Fused,
    LDRSB_Fused,
    LDRH_Fused,
    LDRSH_Fused,
    VSTR,
    STR_Fused,
    STRB_Fused,
    STRH_Fused,
    STR,
    STRB,
    STRH,
    MOVW,
    MOVW_Cond,
    MOVT,
    VADD_F32,
    VSUB_F32,
    VMUL_F32,
    VNMUL_F32,
    VDIV_F32,
    VMLA_F32,
    VMLS_F32,
    VNMLA_F32,
    VNMLS_F32,
    VNEG_F32,
    VABS_F32,
    VCMP_F32,
    VCMP_F32_WithZero,
    TRANSFER_FPSCR_FLAG,
    VCVT_F32_S32,
    VCVT_S32_F32,
    VMOV,
    VMOV_Cond,
    VMOV_GPR2FPR,
    VMOV_FPR2GPR,
    VMOV_Constant,
    PUSH,
    VPUSH,
    POP,
    POP_RET,
    VPOP,
    USAT,
    SSAT,
    MOVT_MOVW_PAIR,
    NZCVFlag2GPR,
    Select_GPR,
    CondArith_GPR,
    Select_FPR,
    PseudoIntOpWithOp2_Cond,
    PseudoSMax,
    PseudoSMin,
    PseudoSMax_Inverted,
    PseudoSMin_Inverted,
    PseudoFMA,
    UNIMP,
    ARMInstEnd
};

const TargetInstInfo& getARMInstInfo();

CMMC_TARGET_NAMESPACE_END