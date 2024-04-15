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

#define CMMC_TARGET_NAMESPACE_BEGIN namespace cmmc::mir::RISCV {
#define CMMC_TARGET_NAMESPACE_END }

CMMC_TARGET_NAMESPACE_BEGIN
enum RISCVInst {
    RISCVInstBegin = ISASpecificBegin,
    ADDI,
    SLTI,
    SLTIU,
    ANDI,
    ORI,
    XORI,
    SLLI,
    SRLI,
    SRAI,
    LUI,
    AUIPC,//60
    ADD,
    SLT,
    SLTU,
    AND,
    OR,
    XOR,
    SLL,
    SRL,
    SUB,
    SRA,
    JAL,
    RET, // 72
    BEQ,
    BNE,
    BLT,
    BLE,
    BGT,
    BGE,
    BLTU,
    BLEU,
    BGTU,
    BGEU,
    JR,
    J,
    UNIMP,
    LB,
    LH,
    LW,//88
    LBU,
    LHU,
    SB,
    SH,
    SW,
    AMOADD_W,
    ADDIW,
    SLLIW,
    SRLIW,
    SRAIW,
    ADDW,//99
    SUBW,
    SLLW,
    SRLW,
    SRAW,
    LD,
    LWU,
    SD,
    MUL,
    MULH,
    MULHSU,
    MULHU,
    MULW,
    DIV,
    DIVU,
    REM,
    REMU,
    DIVUW,
    REMUW,
    DIVW,
    REMW,
    FLW,
    FSW,
    FADD_S,
    FSUB_S,
    FMUL_S,
    FDIV_S,
    FMIN_S,
    FMAX_S,
    FNEG_S,
    FABS_S,
    FSGNJ_S,
    FMV_S,
    FCVT_W_S,
    FCVT_WU_S,
    FCLASS_S,
    FMV_X_W,
    FEQ_S,
    FLT_S,
    FLE_S,
    FMV_W_X,
    FCVT_S_W,
    FCVT_S_WU,
    FMADD_S,
    FMSUB_S,
    FNMADD_S,
    FNMSUB_S,
    ADD_UW,
    SH1ADD,
    SH1ADD_UW,
    SH2ADD,
    SH2ADD_UW,
    SH3ADD,
    SH3ADD_UW,
    SLLI_UW,
    ANDN,
    ORN,
    XNOR,
    MIN,
    MINU,
    MAX,
    MAXU,
    ROL,
    ROLW,
    ROR,
    RORI,
    RORIW,
    RORW,
    SEXT_B,
    SEXT_H,
    SEXT_W,
    ZEXT_H,
    ZEXT_W,
    CLZ,
    CLZW,
    CTZ,
    CTZW,
    CPOP,
    CPOPW,
    ORC_B,
    REV8,
    LoadImm12,
    LoadImm32,
    LoadImm64,
    LoadImm64Complex,
    MoveGPR,
    Select_GPR_GPR,
    Select_GPR_Arith,
    Select_FPR_GPR,
    RISCVInstEnd
};

const TargetInstInfo& getRISCVInstInfo();

CMMC_TARGET_NAMESPACE_END