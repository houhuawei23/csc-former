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

#include "../RISCV/ISelInfoDecl.hpp"

CMMC_TARGET_NAMESPACE_BEGIN

static bool matchInstFMul(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstFMul)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstLoadImmToReg(MIRInst& inst, MIROperand& Dst, MIROperand& Imm) {
    if(inst.opcode() != InstLoadImmToReg)
        return false;
    Dst = inst.getOperand(0);
    Imm = inst.getOperand(1);
    return true;
}

static bool matchInstFCmp(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs, MIROperand& Op) {
    if(inst.opcode() != InstFCmp)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    Op = inst.getOperand(3);
    return true;
}

static bool matchInstFDiv(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstFDiv)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstXor(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstXor)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstAdd(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstAdd)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstOr(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstOr)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstFAdd(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstFAdd)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstBranch(MIRInst& inst, MIROperand& Cond, MIROperand& Tgt, MIROperand& Prob) {
    if(inst.opcode() != InstBranch)
        return false;
    Cond = inst.getOperand(0);
    Tgt = inst.getOperand(1);
    Prob = inst.getOperand(2);
    return true;
}

static bool matchInstAnd(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstAnd)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstUDiv(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstUDiv)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstSMin(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstSMin)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstS2F(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstS2F)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchANDI(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Imm) {
    if(inst.opcode() != ANDI)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Imm = inst.getOperand(2);
    return true;
}

static bool matchORI(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Imm) {
    if(inst.opcode() != ORI)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Imm = inst.getOperand(2);
    return true;
}

static bool matchSLLIW(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Imm) {
    if(inst.opcode() != SLLIW)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Imm = inst.getOperand(2);
    return true;
}

static bool matchInstLoadGlobalAddress(MIRInst& inst, MIROperand& Dst, MIROperand& Addr) {
    if(inst.opcode() != InstLoadGlobalAddress)
        return false;
    Dst = inst.getOperand(0);
    Addr = inst.getOperand(1);
    return true;
}

static bool matchInstLoad(MIRInst& inst, MIROperand& Dst, MIROperand& Addr, MIROperand& Alignment) {
    if(inst.opcode() != InstLoad)
        return false;
    Dst = inst.getOperand(0);
    Addr = inst.getOperand(1);
    Alignment = inst.getOperand(2);
    return true;
}

static bool matchInstSelect(MIRInst& inst, MIROperand& Dst, MIROperand& Cond, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstSelect)
        return false;
    Dst = inst.getOperand(0);
    Cond = inst.getOperand(1);
    Lhs = inst.getOperand(2);
    Rhs = inst.getOperand(3);
    return true;
}

static bool matchInstSDiv(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs, MIROperand& LogDividend,
                          MIROperand& LogDivisor, MIROperand& NonNegativeHint) {
    if(inst.opcode() != InstSDiv)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    LogDividend = inst.getOperand(3);
    LogDivisor = inst.getOperand(4);
    NonNegativeHint = inst.getOperand(5);
    return true;
}

static bool matchInstSRem(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs, MIROperand& LogDividend,
                          MIROperand& LogDivisor, MIROperand& NonNegativeHint) {
    if(inst.opcode() != InstSRem)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    LogDividend = inst.getOperand(3);
    LogDivisor = inst.getOperand(4);
    NonNegativeHint = inst.getOperand(5);
    return true;
}

static bool matchInstFAbs(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstFAbs)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchInstUnreachable(MIRInst& inst) {
    if(inst.opcode() != InstUnreachable)
        return false;

    return true;
}

static bool matchInstICmp(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs, MIROperand& Op) {
    if(inst.opcode() != InstICmp)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    Op = inst.getOperand(3);
    return true;
}

static bool matchInstStore(MIRInst& inst, MIROperand& Addr, MIROperand& Src, MIROperand& Alignment) {
    if(inst.opcode() != InstStore)
        return false;
    Addr = inst.getOperand(0);
    Src = inst.getOperand(1);
    Alignment = inst.getOperand(2);
    return true;
}

static bool matchInstLShr(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstLShr)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstSExt(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstSExt)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchInstAShr(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstAShr)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstF2S(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstF2S)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchSelect_GPR_GPR(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Rs2, MIROperand& Lhs, MIROperand& Rhs,
                                MIROperand& CC) {
    if(inst.opcode() != Select_GPR_GPR)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Rs2 = inst.getOperand(2);
    Lhs = inst.getOperand(3);
    Rhs = inst.getOperand(4);
    CC = inst.getOperand(5);
    return true;
}

static bool matchLoadImm32(MIRInst& inst, MIROperand& Rd, MIROperand& Imm) {
    if(inst.opcode() != LoadImm32)
        return false;
    Rd = inst.getOperand(0);
    Imm = inst.getOperand(1);
    return true;
}

static bool matchSRLIW(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Imm) {
    if(inst.opcode() != SRLIW)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Imm = inst.getOperand(2);
    return true;
}

static bool matchInstShl(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstShl)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstSub(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstSub)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstTrunc(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstTrunc)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchSRAIW(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Imm) {
    if(inst.opcode() != SRAIW)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Imm = inst.getOperand(2);
    return true;
}

static bool matchLoadImm12(MIRInst& inst, MIROperand& Rd, MIROperand& Imm) {
    if(inst.opcode() != LoadImm12)
        return false;
    Rd = inst.getOperand(0);
    Imm = inst.getOperand(1);
    return true;
}

static bool matchInstSMax(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstSMax)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstAbs(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstAbs)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchInstFNeg(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstFNeg)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchSRLI(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Imm) {
    if(inst.opcode() != SRLI)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Imm = inst.getOperand(2);
    return true;
}

static bool matchInstZExt(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstZExt)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchInstFSub(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstFSub)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchLoadImm64(MIRInst& inst, MIROperand& Rd, MIROperand& Imm) {
    if(inst.opcode() != LoadImm64)
        return false;
    Rd = inst.getOperand(0);
    Imm = inst.getOperand(1);
    return true;
}

static bool matchSUBW(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Rs2) {
    if(inst.opcode() != SUBW)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Rs2 = inst.getOperand(2);
    return true;
}

static bool matchSelect_FPR_GPR(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Rs2, MIROperand& Lhs, MIROperand& Rhs,
                                MIROperand& CC) {
    if(inst.opcode() != Select_FPR_GPR)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Rs2 = inst.getOperand(2);
    Lhs = inst.getOperand(3);
    Rhs = inst.getOperand(4);
    CC = inst.getOperand(5);
    return true;
}

static bool matchInstLoadImm(MIRInst& inst, MIROperand& Dst, MIROperand& Imm) {
    if(inst.opcode() != InstLoadImm)
        return false;
    Dst = inst.getOperand(0);
    Imm = inst.getOperand(1);
    return true;
}

static bool matchInstJump(MIRInst& inst, MIROperand& Tgt) {
    if(inst.opcode() != InstJump)
        return false;
    Tgt = inst.getOperand(0);
    return true;
}

static bool matchXORI(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Imm) {
    if(inst.opcode() != XORI)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Imm = inst.getOperand(2);
    return true;
}

static bool matchSLLI(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Imm) {
    if(inst.opcode() != SLLI)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Imm = inst.getOperand(2);
    return true;
}

static bool matchInstMul(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstMul)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstURem(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstURem)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchADD_UW(MIRInst& inst, MIROperand& Rd, MIROperand& Rs1, MIROperand& Rs2) {
    if(inst.opcode() != ADD_UW)
        return false;
    Rd = inst.getOperand(0);
    Rs1 = inst.getOperand(1);
    Rs2 = inst.getOperand(2);
    return true;
}

static bool matchAndSelectPattern1(MIRInst& inst1, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadGlobalAddress;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op2;
    MIROperand op3;
    if(!matchInstLoadGlobalAddress(inst1, op2, op3))
        return false;
    // Select
    auto op4 = (op2);
    auto op5 = (getVRegAs(ctx, op2));
    auto op6 = (getHighBits(op3));
    auto& inst7 = ctx.newInst(AUIPC).setOperand<0>(op5).setOperand<1>(op6);
    auto& op7 = ctx.getInstDef(inst7);
    auto op8 = (getLowBits(op3));
    auto& inst9 = ctx.newInst(ADDI).setOperand<0>(op4).setOperand<1>(op7).setOperand<2>(op8);
    ctx.replaceOperand(ctx.getInstDef(inst1), ctx.getInstDef(inst9));
    ctx.removeInst(inst1);
    return true;
}

static bool matchAndSelectPattern10(MIRInst& inst10, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImmToReg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op11;
    MIROperand op12;
    if(!matchInstLoadImmToReg(inst10, op11, op12))
        return false;
    if(!(isZero(op12)))
        return false;
    // Select
    auto op13 = (op11);
    auto op14 = (getZero(op11));
    auto& inst15 = ctx.newInst(MoveGPR).setOperand<0>(op13).setOperand<1>(op14);
    ctx.replaceOperand(ctx.getInstDef(inst10), ctx.getInstDef(inst15));
    ctx.removeInst(inst10);
    return true;
}

static bool matchAndSelectPattern22(MIRInst& inst22, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImmToReg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op23;
    MIROperand op24;
    if(!matchInstLoadImmToReg(inst22, op23, op24))
        return false;
    if(!(isOperandNonZeroImm12(op24)))
        return false;
    // Select
    auto op25 = (op23);
    auto op26 = (op24);
    auto& inst27 = ctx.newInst(LoadImm12).setOperand<0>(op25).setOperand<1>(op26);
    ctx.replaceOperand(ctx.getInstDef(inst22), ctx.getInstDef(inst27));
    ctx.removeInst(inst22);
    return true;
}

static bool matchAndSelectPattern34(MIRInst& inst34, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImmToReg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op35;
    MIROperand op36;
    if(!matchInstLoadImmToReg(inst34, op35, op36))
        return false;
    MIROperand op37;
    if(!(selectOperandNonZeroHigh20Bits(op36, op37)))
        return false;
    // Select
    auto op38 = (op35);
    auto op39 = (op37);
    auto& inst40 = ctx.newInst(LUI).setOperand<0>(op38).setOperand<1>(op39);
    ctx.replaceOperand(ctx.getInstDef(inst34), ctx.getInstDef(inst40));
    ctx.removeInst(inst34);
    return true;
}

static bool matchAndSelectPattern48(MIRInst& inst48, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImmToReg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op49;
    MIROperand op50;
    if(!matchInstLoadImmToReg(inst48, op49, op50))
        return false;
    if(!(isOperandNonZeroImm32(op50)))
        return false;
    // Select
    auto op51 = (op49);
    auto op52 = (op50);
    auto& inst53 = ctx.newInst(LoadImm32).setOperand<0>(op51).setOperand<1>(op52);
    ctx.replaceOperand(ctx.getInstDef(inst48), ctx.getInstDef(inst53));
    ctx.removeInst(inst48);
    return true;
}

static bool matchAndSelectPattern60(MIRInst& inst60, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImmToReg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op61;
    MIROperand op62;
    if(!matchInstLoadImmToReg(inst60, op61, op62))
        return false;
    if(!(isOperandNonZeroImm64(op62)))
        return false;
    // Select
    auto op63 = (op61);
    auto op64 = (op62);
    auto& inst65 = ctx.newInst(LoadImm64).setOperand<0>(op63).setOperand<1>(op64);
    ctx.replaceOperand(ctx.getInstDef(inst60), ctx.getInstDef(inst65));
    ctx.removeInst(inst60);
    return true;
}

static bool matchAndSelectPattern16(MIRInst& inst16, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImm;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op17;
    MIROperand op18;
    if(!matchInstLoadImm(inst16, op17, op18))
        return false;
    if(!(isZero(op18)))
        return false;
    // Select
    auto op19 = (op17);
    auto op20 = (getZero(op17));
    auto& inst21 = ctx.newInst(MoveGPR).setOperand<0>(op19).setOperand<1>(op20);
    ctx.replaceOperand(ctx.getInstDef(inst16), ctx.getInstDef(inst21));
    ctx.removeInst(inst16);
    return true;
}

static bool matchAndSelectPattern28(MIRInst& inst28, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImm;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op29;
    MIROperand op30;
    if(!matchInstLoadImm(inst28, op29, op30))
        return false;
    if(!(isOperandNonZeroImm12(op30)))
        return false;
    // Select
    auto op31 = (op29);
    auto op32 = (op30);
    auto& inst33 = ctx.newInst(LoadImm12).setOperand<0>(op31).setOperand<1>(op32);
    ctx.replaceOperand(ctx.getInstDef(inst28), ctx.getInstDef(inst33));
    ctx.removeInst(inst28);
    return true;
}

static bool matchAndSelectPattern41(MIRInst& inst41, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImm;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op42;
    MIROperand op43;
    if(!matchInstLoadImm(inst41, op42, op43))
        return false;
    MIROperand op44;
    if(!(selectOperandNonZeroHigh20Bits(op43, op44)))
        return false;
    // Select
    auto op45 = (op42);
    auto op46 = (op44);
    auto& inst47 = ctx.newInst(LUI).setOperand<0>(op45).setOperand<1>(op46);
    ctx.replaceOperand(ctx.getInstDef(inst41), ctx.getInstDef(inst47));
    ctx.removeInst(inst41);
    return true;
}

static bool matchAndSelectPattern54(MIRInst& inst54, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImm;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op55;
    MIROperand op56;
    if(!matchInstLoadImm(inst54, op55, op56))
        return false;
    if(!(isOperandNonZeroImm32(op56)))
        return false;
    // Select
    auto op57 = (op55);
    auto op58 = (op56);
    auto& inst59 = ctx.newInst(LoadImm32).setOperand<0>(op57).setOperand<1>(op58);
    ctx.replaceOperand(ctx.getInstDef(inst54), ctx.getInstDef(inst59));
    ctx.removeInst(inst54);
    return true;
}

static bool matchAndSelectPattern66(MIRInst& inst66, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImm;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op67;
    MIROperand op68;
    if(!matchInstLoadImm(inst66, op67, op68))
        return false;
    if(!(isOperandNonZeroImm64(op68)))
        return false;
    // Select
    auto op69 = (op67);
    auto op70 = (op68);
    auto& inst71 = ctx.newInst(LoadImm64).setOperand<0>(op69).setOperand<1>(op70);
    ctx.replaceOperand(ctx.getInstDef(inst66), ctx.getInstDef(inst71));
    ctx.removeInst(inst66);
    return true;
}

static bool matchAndSelectPattern72(MIRInst& inst72, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op73;
    MIROperand op74;
    MIROperand op75;
    if(!matchInstAdd(inst72, op73, op74, op75))
        return false;
    auto instptr74 = ctx.lookupDef(op74);
    if(!instptr74)
        return false;
    auto& inst74 = *instptr74;
    MIROperand op76;
    MIROperand op77;
    MIROperand op78;
    if(!matchInstShl(inst74, op76, op77, op78))
        return false;
    if(!(isOperandIReg(op73) && isOperandIReg(op77) && isOperandIReg(op75) && (op78).isImm() && (op78).imm() == 1))
        return false;
    // Select
    auto op79 = (op73);
    auto op80 = (op77);
    auto op81 = (op75);
    auto& inst82 = ctx.newInst(SH1ADD).setOperand<0>(op79).setOperand<1>(op80).setOperand<2>(op81);
    ctx.replaceOperand(ctx.getInstDef(inst72), ctx.getInstDef(inst82));
    ctx.removeInst(inst72);
    return true;
}

static bool matchAndSelectPattern83(MIRInst& inst83, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op84;
    MIROperand op85;
    MIROperand op86;
    if(!matchInstAdd(inst83, op84, op85, op86))
        return false;
    auto instptr86 = ctx.lookupDef(op86);
    if(!instptr86)
        return false;
    auto& inst86 = *instptr86;
    MIROperand op87;
    MIROperand op88;
    MIROperand op89;
    if(!matchInstShl(inst86, op87, op88, op89))
        return false;
    if(!(isOperandIReg(op84) && isOperandIReg(op85) && isOperandIReg(op88) && (op89).isImm() && (op89).imm() == 1))
        return false;
    // Select
    auto op90 = (op84);
    auto op91 = (op88);
    auto op92 = (op85);
    auto& inst93 = ctx.newInst(SH1ADD).setOperand<0>(op90).setOperand<1>(op91).setOperand<2>(op92);
    ctx.replaceOperand(ctx.getInstDef(inst83), ctx.getInstDef(inst93));
    ctx.removeInst(inst83);
    return true;
}

static bool matchAndSelectPattern94(MIRInst& inst94, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op95;
    MIROperand op96;
    MIROperand op97;
    if(!matchInstAdd(inst94, op95, op96, op97))
        return false;
    auto instptr96 = ctx.lookupDef(op96);
    if(!instptr96)
        return false;
    auto& inst96 = *instptr96;
    MIROperand op98;
    MIROperand op99;
    MIROperand op100;
    if(!matchInstShl(inst96, op98, op99, op100))
        return false;
    if(!(isOperandIReg(op95) && isOperandIReg(op99) && isOperandIReg(op97) && (op100).isImm() && (op100).imm() == 2))
        return false;
    // Select
    auto op101 = (op95);
    auto op102 = (op99);
    auto op103 = (op97);
    auto& inst104 = ctx.newInst(SH2ADD).setOperand<0>(op101).setOperand<1>(op102).setOperand<2>(op103);
    ctx.replaceOperand(ctx.getInstDef(inst94), ctx.getInstDef(inst104));
    ctx.removeInst(inst94);
    return true;
}

static bool matchAndSelectPattern105(MIRInst& inst105, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op106;
    MIROperand op107;
    MIROperand op108;
    if(!matchInstAdd(inst105, op106, op107, op108))
        return false;
    auto instptr108 = ctx.lookupDef(op108);
    if(!instptr108)
        return false;
    auto& inst108 = *instptr108;
    MIROperand op109;
    MIROperand op110;
    MIROperand op111;
    if(!matchInstShl(inst108, op109, op110, op111))
        return false;
    if(!(isOperandIReg(op106) && isOperandIReg(op107) && isOperandIReg(op110) && (op111).isImm() && (op111).imm() == 2))
        return false;
    // Select
    auto op112 = (op106);
    auto op113 = (op110);
    auto op114 = (op107);
    auto& inst115 = ctx.newInst(SH2ADD).setOperand<0>(op112).setOperand<1>(op113).setOperand<2>(op114);
    ctx.replaceOperand(ctx.getInstDef(inst105), ctx.getInstDef(inst115));
    ctx.removeInst(inst105);
    return true;
}

static bool matchAndSelectPattern116(MIRInst& inst116, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op117;
    MIROperand op118;
    MIROperand op119;
    if(!matchInstAdd(inst116, op117, op118, op119))
        return false;
    auto instptr118 = ctx.lookupDef(op118);
    if(!instptr118)
        return false;
    auto& inst118 = *instptr118;
    MIROperand op120;
    MIROperand op121;
    MIROperand op122;
    if(!matchInstShl(inst118, op120, op121, op122))
        return false;
    if(!(isOperandIReg(op117) && isOperandIReg(op121) && isOperandIReg(op119) && (op122).isImm() && (op122).imm() == 3))
        return false;
    // Select
    auto op123 = (op117);
    auto op124 = (op121);
    auto op125 = (op119);
    auto& inst126 = ctx.newInst(SH3ADD).setOperand<0>(op123).setOperand<1>(op124).setOperand<2>(op125);
    ctx.replaceOperand(ctx.getInstDef(inst116), ctx.getInstDef(inst126));
    ctx.removeInst(inst116);
    return true;
}

static bool matchAndSelectPattern127(MIRInst& inst127, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op128;
    MIROperand op129;
    MIROperand op130;
    if(!matchInstAdd(inst127, op128, op129, op130))
        return false;
    auto instptr130 = ctx.lookupDef(op130);
    if(!instptr130)
        return false;
    auto& inst130 = *instptr130;
    MIROperand op131;
    MIROperand op132;
    MIROperand op133;
    if(!matchInstShl(inst130, op131, op132, op133))
        return false;
    if(!(isOperandIReg(op128) && isOperandIReg(op129) && isOperandIReg(op132) && (op133).isImm() && (op133).imm() == 3))
        return false;
    // Select
    auto op134 = (op128);
    auto op135 = (op132);
    auto op136 = (op129);
    auto& inst137 = ctx.newInst(SH3ADD).setOperand<0>(op134).setOperand<1>(op135).setOperand<2>(op136);
    ctx.replaceOperand(ctx.getInstDef(inst127), ctx.getInstDef(inst137));
    ctx.removeInst(inst127);
    return true;
}

static bool matchAndSelectPattern138(MIRInst& inst138, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op139;
    MIROperand op140;
    MIROperand op141;
    if(!matchInstAdd(inst138, op139, op140, op141))
        return false;
    if(!(isOperandI64(op139) && isOperandIReg(op140) && isOperandImm12(op141)))
        return false;
    // Select
    auto op142 = (op139);
    auto op143 = (op140);
    auto op144 = (op141);
    auto& inst145 = ctx.newInst(ADDI).setOperand<0>(op142).setOperand<1>(op143).setOperand<2>(op144);
    ctx.replaceOperand(ctx.getInstDef(inst138), ctx.getInstDef(inst145));
    ctx.removeInst(inst138);
    return true;
}

static bool matchAndSelectPattern146(MIRInst& inst146, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op147;
    MIROperand op148;
    MIROperand op149;
    if(!matchInstAdd(inst146, op147, op148, op149))
        return false;
    if(!(isOperandI64(op147) && isOperandIReg(op148) && isOperandIReg(op149)))
        return false;
    // Select
    auto op150 = (op147);
    auto op151 = (op148);
    auto op152 = (op149);
    auto& inst153 = ctx.newInst(ADD).setOperand<0>(op150).setOperand<1>(op151).setOperand<2>(op152);
    ctx.replaceOperand(ctx.getInstDef(inst146), ctx.getInstDef(inst153));
    ctx.removeInst(inst146);
    return true;
}

static bool matchAndSelectPattern154(MIRInst& inst154, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op155;
    MIROperand op156;
    MIROperand op157;
    if(!matchInstAdd(inst154, op155, op156, op157))
        return false;
    if(!(isOperandI32(op155) && isOperandIReg(op156) && isOperandImm12(op157)))
        return false;
    // Select
    auto op158 = (op155);
    auto op159 = (op156);
    auto op160 = (op157);
    auto& inst161 = ctx.newInst(ADDIW).setOperand<0>(op158).setOperand<1>(op159).setOperand<2>(op160);
    ctx.replaceOperand(ctx.getInstDef(inst154), ctx.getInstDef(inst161));
    ctx.removeInst(inst154);
    return true;
}

static bool matchAndSelectPattern162(MIRInst& inst162, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op163;
    MIROperand op164;
    MIROperand op165;
    if(!matchInstAdd(inst162, op163, op164, op165))
        return false;
    if(!(isOperandI32(op163) && isOperandIReg(op164) && isOperandIReg(op165)))
        return false;
    // Select
    auto op166 = (op163);
    auto op167 = (op164);
    auto op168 = (op165);
    auto& inst169 = ctx.newInst(ADDW).setOperand<0>(op166).setOperand<1>(op167).setOperand<2>(op168);
    ctx.replaceOperand(ctx.getInstDef(inst162), ctx.getInstDef(inst169));
    ctx.removeInst(inst162);
    return true;
}

static bool matchAndSelectPattern170(MIRInst& inst170, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAnd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op171;
    MIROperand op172;
    MIROperand op173;
    if(!matchInstAnd(inst170, op171, op172, op173))
        return false;
    auto instptr173 = ctx.lookupDef(op173);
    if(!instptr173)
        return false;
    auto& inst173 = *instptr173;
    MIROperand op174;
    MIROperand op175;
    MIROperand op176;
    if(!matchInstXor(inst173, op174, op175, op176))
        return false;
    if(!(isOperandIReg(op172) && isOperandIReg(op175) && isNotImm((op171).type(), op176)))
        return false;
    // Select
    auto op177 = (op171);
    auto op178 = (op172);
    auto op179 = (op175);
    auto& inst180 = ctx.newInst(ANDN).setOperand<0>(op177).setOperand<1>(op178).setOperand<2>(op179);
    ctx.replaceOperand(ctx.getInstDef(inst170), ctx.getInstDef(inst180));
    ctx.removeInst(inst170);
    return true;
}

static bool matchAndSelectPattern214(MIRInst& inst214, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAnd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op215;
    MIROperand op216;
    MIROperand op217;
    if(!matchInstAnd(inst214, op215, op216, op217))
        return false;
    if(!(isOperandIReg(op216) && isOperandImm12(op217)))
        return false;
    // Select
    auto op218 = (op215);
    auto op219 = (op216);
    auto op220 = (op217);
    auto& inst221 =
        ctx.newInst(getIntegerBinaryImmOpcode(rootOpcode)).setOperand<0>(op218).setOperand<1>(op219).setOperand<2>(op220);
    ctx.replaceOperand(ctx.getInstDef(inst214), ctx.getInstDef(inst221));
    ctx.removeInst(inst214);
    return true;
}

static bool matchAndSelectPattern238(MIRInst& inst238, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAnd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op239;
    MIROperand op240;
    MIROperand op241;
    if(!matchInstAnd(inst238, op239, op240, op241))
        return false;
    if(!(isOperandIReg(op240) && isOperandIReg(op241)))
        return false;
    // Select
    auto op242 = (op239);
    auto op243 = (op240);
    auto op244 = (op241);
    auto& inst245 =
        ctx.newInst(getIntegerBinaryRegOpcode(rootOpcode)).setOperand<0>(op242).setOperand<1>(op243).setOperand<2>(op244);
    ctx.replaceOperand(ctx.getInstDef(inst238), ctx.getInstDef(inst245));
    ctx.removeInst(inst238);
    return true;
}

static bool matchAndSelectPattern181(MIRInst& inst181, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstOr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op182;
    MIROperand op183;
    MIROperand op184;
    if(!matchInstOr(inst181, op182, op183, op184))
        return false;
    auto instptr184 = ctx.lookupDef(op184);
    if(!instptr184)
        return false;
    auto& inst184 = *instptr184;
    MIROperand op185;
    MIROperand op186;
    MIROperand op187;
    if(!matchInstXor(inst184, op185, op186, op187))
        return false;
    if(!(isOperandIReg(op183) && isOperandIReg(op186) && isNegativeOne(op187)))
        return false;
    // Select
    auto op188 = (op182);
    auto op189 = (op183);
    auto op190 = (op186);
    auto& inst191 = ctx.newInst(ORN).setOperand<0>(op188).setOperand<1>(op189).setOperand<2>(op190);
    ctx.replaceOperand(ctx.getInstDef(inst181), ctx.getInstDef(inst191));
    ctx.removeInst(inst181);
    return true;
}

static bool matchAndSelectPattern222(MIRInst& inst222, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstOr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op223;
    MIROperand op224;
    MIROperand op225;
    if(!matchInstOr(inst222, op223, op224, op225))
        return false;
    if(!(isOperandIReg(op224) && isOperandImm12(op225)))
        return false;
    // Select
    auto op226 = (op223);
    auto op227 = (op224);
    auto op228 = (op225);
    auto& inst229 =
        ctx.newInst(getIntegerBinaryImmOpcode(rootOpcode)).setOperand<0>(op226).setOperand<1>(op227).setOperand<2>(op228);
    ctx.replaceOperand(ctx.getInstDef(inst222), ctx.getInstDef(inst229));
    ctx.removeInst(inst222);
    return true;
}

static bool matchAndSelectPattern246(MIRInst& inst246, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstOr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op247;
    MIROperand op248;
    MIROperand op249;
    if(!matchInstOr(inst246, op247, op248, op249))
        return false;
    if(!(isOperandIReg(op248) && isOperandIReg(op249)))
        return false;
    // Select
    auto op250 = (op247);
    auto op251 = (op248);
    auto op252 = (op249);
    auto& inst253 =
        ctx.newInst(getIntegerBinaryRegOpcode(rootOpcode)).setOperand<0>(op250).setOperand<1>(op251).setOperand<2>(op252);
    ctx.replaceOperand(ctx.getInstDef(inst246), ctx.getInstDef(inst253));
    ctx.removeInst(inst246);
    return true;
}

static bool matchAndSelectPattern192(MIRInst& inst192, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstXor;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op193;
    MIROperand op194;
    MIROperand op195;
    if(!matchInstXor(inst192, op193, op194, op195))
        return false;
    auto instptr194 = ctx.lookupDef(op194);
    if(!instptr194)
        return false;
    auto& inst194 = *instptr194;
    MIROperand op196;
    MIROperand op197;
    MIROperand op198;
    if(!matchInstXor(inst194, op196, op197, op198))
        return false;
    if(!(isOperandIReg(op197) && isOperandIReg(op198) && isNotImm((op193).type(), op195)))
        return false;
    // Select
    auto op199 = (op193);
    auto op200 = (op197);
    auto op201 = (op198);
    auto& inst202 = ctx.newInst(XNOR).setOperand<0>(op199).setOperand<1>(op200).setOperand<2>(op201);
    ctx.replaceOperand(ctx.getInstDef(inst192), ctx.getInstDef(inst202));
    ctx.removeInst(inst192);
    return true;
}

static bool matchAndSelectPattern203(MIRInst& inst203, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstXor;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op204;
    MIROperand op205;
    MIROperand op206;
    if(!matchInstXor(inst203, op204, op205, op206))
        return false;
    auto instptr206 = ctx.lookupDef(op206);
    if(!instptr206)
        return false;
    auto& inst206 = *instptr206;
    MIROperand op207;
    MIROperand op208;
    MIROperand op209;
    if(!matchInstXor(inst206, op207, op208, op209))
        return false;
    if(!(isOperandIReg(op205) && isOperandIReg(op208) && isNotImm((op204).type(), op209)))
        return false;
    // Select
    auto op210 = (op204);
    auto op211 = (op205);
    auto op212 = (op208);
    auto& inst213 = ctx.newInst(XNOR).setOperand<0>(op210).setOperand<1>(op211).setOperand<2>(op212);
    ctx.replaceOperand(ctx.getInstDef(inst203), ctx.getInstDef(inst213));
    ctx.removeInst(inst203);
    return true;
}

static bool matchAndSelectPattern230(MIRInst& inst230, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstXor;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op231;
    MIROperand op232;
    MIROperand op233;
    if(!matchInstXor(inst230, op231, op232, op233))
        return false;
    if(!(isOperandIReg(op232) && isOperandImm12(op233)))
        return false;
    // Select
    auto op234 = (op231);
    auto op235 = (op232);
    auto op236 = (op233);
    auto& inst237 =
        ctx.newInst(getIntegerBinaryImmOpcode(rootOpcode)).setOperand<0>(op234).setOperand<1>(op235).setOperand<2>(op236);
    ctx.replaceOperand(ctx.getInstDef(inst230), ctx.getInstDef(inst237));
    ctx.removeInst(inst230);
    return true;
}

static bool matchAndSelectPattern254(MIRInst& inst254, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstXor;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op255;
    MIROperand op256;
    MIROperand op257;
    if(!matchInstXor(inst254, op255, op256, op257))
        return false;
    if(!(isOperandIReg(op256) && isOperandIReg(op257)))
        return false;
    // Select
    auto op258 = (op255);
    auto op259 = (op256);
    auto op260 = (op257);
    auto& inst261 =
        ctx.newInst(getIntegerBinaryRegOpcode(rootOpcode)).setOperand<0>(op258).setOperand<1>(op259).setOperand<2>(op260);
    ctx.replaceOperand(ctx.getInstDef(inst254), ctx.getInstDef(inst261));
    ctx.removeInst(inst254);
    return true;
}

static bool matchAndSelectPattern262(MIRInst& inst262, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op263;
    MIROperand op264;
    MIROperand op265;
    if(!matchInstSub(inst262, op263, op264, op265))
        return false;
    auto instptr265 = ctx.lookupDef(op265);
    if(!instptr265)
        return false;
    auto& inst265 = *instptr265;
    MIROperand op266;
    MIROperand op267;
    if(!matchInstAbs(inst265, op266, op267))
        return false;
    if(!(isOperandIReg(op267) && isZero(op264) && isOperandI32(op263)))
        return false;
    // Select
    auto op268 = (op263);
    auto op269 = (getVRegAs(ctx, op263));
    auto op270 = (getZero(op263));
    auto op271 = (op267);
    auto& inst272 = ctx.newInst(SUBW).setOperand<0>(op269).setOperand<1>(op270).setOperand<2>(op271);
    auto& op272 = ctx.getInstDef(inst272);
    auto op273 = (op267);
    auto& inst274 = ctx.newInst(MIN).setOperand<0>(op268).setOperand<1>(op272).setOperand<2>(op273);
    ctx.replaceOperand(ctx.getInstDef(inst262), ctx.getInstDef(inst274));
    ctx.removeInst(inst262);
    return true;
}

static bool matchAndSelectPattern275(MIRInst& inst275, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op276;
    MIROperand op277;
    MIROperand op278;
    if(!matchInstSub(inst275, op276, op277, op278))
        return false;
    if(!(isOperandI64(op276) && isOperandIReg(op277) && isOperandIReg(op278)))
        return false;
    // Select
    auto op279 = (op276);
    auto op280 = (op277);
    auto op281 = (op278);
    auto& inst282 = ctx.newInst(SUB).setOperand<0>(op279).setOperand<1>(op280).setOperand<2>(op281);
    ctx.replaceOperand(ctx.getInstDef(inst275), ctx.getInstDef(inst282));
    ctx.removeInst(inst275);
    return true;
}

static bool matchAndSelectPattern283(MIRInst& inst283, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op284;
    MIROperand op285;
    MIROperand op286;
    if(!matchInstSub(inst283, op284, op285, op286))
        return false;
    if(!(isOperandI32(op284) && isOperandIReg(op285) && isOperandIReg(op286)))
        return false;
    // Select
    auto op287 = (op284);
    auto op288 = (op285);
    auto op289 = (op286);
    auto& inst290 = ctx.newInst(SUBW).setOperand<0>(op287).setOperand<1>(op288).setOperand<2>(op289);
    ctx.replaceOperand(ctx.getInstDef(inst283), ctx.getInstDef(inst290));
    ctx.removeInst(inst283);
    return true;
}

static bool matchAndSelectPattern291(MIRInst& inst291, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstShl;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op292;
    MIROperand op293;
    MIROperand op294;
    if(!matchInstShl(inst291, op292, op293, op294))
        return false;
    if(!(isOperandI64(op292) && isOperandIReg(op293) && isOperandUImm6(op294)))
        return false;
    // Select
    auto op295 = (op292);
    auto op296 = (op293);
    auto op297 = (op294);
    auto& inst298 = ctx.newInst(SLLI).setOperand<0>(op295).setOperand<1>(op296).setOperand<2>(op297);
    ctx.replaceOperand(ctx.getInstDef(inst291), ctx.getInstDef(inst298));
    ctx.removeInst(inst291);
    return true;
}

static bool matchAndSelectPattern299(MIRInst& inst299, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstShl;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op300;
    MIROperand op301;
    MIROperand op302;
    if(!matchInstShl(inst299, op300, op301, op302))
        return false;
    if(!(isOperandI32(op300) && isOperandIReg(op301) && isOperandUImm6(op302)))
        return false;
    // Select
    auto op303 = (op300);
    auto op304 = (op301);
    auto op305 = (op302);
    auto& inst306 = ctx.newInst(SLLIW).setOperand<0>(op303).setOperand<1>(op304).setOperand<2>(op305);
    ctx.replaceOperand(ctx.getInstDef(inst299), ctx.getInstDef(inst306));
    ctx.removeInst(inst299);
    return true;
}

static bool matchAndSelectPattern339(MIRInst& inst339, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstShl;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op340;
    MIROperand op341;
    MIROperand op342;
    if(!matchInstShl(inst339, op340, op341, op342))
        return false;
    if(!(isOperandI64(op340) && isOperandIReg(op341) && isOperandIReg(op342)))
        return false;
    // Select
    auto op343 = (op340);
    auto op344 = (op341);
    auto op345 = (op342);
    auto& inst346 = ctx.newInst(SLL).setOperand<0>(op343).setOperand<1>(op344).setOperand<2>(op345);
    ctx.replaceOperand(ctx.getInstDef(inst339), ctx.getInstDef(inst346));
    ctx.removeInst(inst339);
    return true;
}

static bool matchAndSelectPattern347(MIRInst& inst347, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstShl;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op348;
    MIROperand op349;
    MIROperand op350;
    if(!matchInstShl(inst347, op348, op349, op350))
        return false;
    if(!(isOperandI32(op348) && isOperandIReg(op349) && isOperandIReg(op350)))
        return false;
    // Select
    auto op351 = (op348);
    auto op352 = (op349);
    auto op353 = (op350);
    auto& inst354 = ctx.newInst(SLLW).setOperand<0>(op351).setOperand<1>(op352).setOperand<2>(op353);
    ctx.replaceOperand(ctx.getInstDef(inst347), ctx.getInstDef(inst354));
    ctx.removeInst(inst347);
    return true;
}

static bool matchAndSelectPattern307(MIRInst& inst307, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op308;
    MIROperand op309;
    MIROperand op310;
    if(!matchInstAShr(inst307, op308, op309, op310))
        return false;
    if(!(isOperandI64(op308) && isOperandIReg(op309) && isOperandUImm6(op310)))
        return false;
    // Select
    auto op311 = (op308);
    auto op312 = (op309);
    auto op313 = (op310);
    auto& inst314 = ctx.newInst(SRAI).setOperand<0>(op311).setOperand<1>(op312).setOperand<2>(op313);
    ctx.replaceOperand(ctx.getInstDef(inst307), ctx.getInstDef(inst314));
    ctx.removeInst(inst307);
    return true;
}

static bool matchAndSelectPattern315(MIRInst& inst315, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op316;
    MIROperand op317;
    MIROperand op318;
    if(!matchInstAShr(inst315, op316, op317, op318))
        return false;
    if(!(isOperandI32(op316) && isOperandIReg(op317) && isOperandUImm6(op318)))
        return false;
    // Select
    auto op319 = (op316);
    auto op320 = (op317);
    auto op321 = (op318);
    auto& inst322 = ctx.newInst(SRAIW).setOperand<0>(op319).setOperand<1>(op320).setOperand<2>(op321);
    ctx.replaceOperand(ctx.getInstDef(inst315), ctx.getInstDef(inst322));
    ctx.removeInst(inst315);
    return true;
}

static bool matchAndSelectPattern355(MIRInst& inst355, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op356;
    MIROperand op357;
    MIROperand op358;
    if(!matchInstAShr(inst355, op356, op357, op358))
        return false;
    if(!(isOperandI64(op356) && isOperandIReg(op357) && isOperandIReg(op358)))
        return false;
    // Select
    auto op359 = (op356);
    auto op360 = (op357);
    auto op361 = (op358);
    auto& inst362 = ctx.newInst(SRA).setOperand<0>(op359).setOperand<1>(op360).setOperand<2>(op361);
    ctx.replaceOperand(ctx.getInstDef(inst355), ctx.getInstDef(inst362));
    ctx.removeInst(inst355);
    return true;
}

static bool matchAndSelectPattern363(MIRInst& inst363, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op364;
    MIROperand op365;
    MIROperand op366;
    if(!matchInstAShr(inst363, op364, op365, op366))
        return false;
    if(!(isOperandI32(op364) && isOperandIReg(op365) && isOperandIReg(op366)))
        return false;
    // Select
    auto op367 = (op364);
    auto op368 = (op365);
    auto op369 = (op366);
    auto& inst370 = ctx.newInst(SRAW).setOperand<0>(op367).setOperand<1>(op368).setOperand<2>(op369);
    ctx.replaceOperand(ctx.getInstDef(inst363), ctx.getInstDef(inst370));
    ctx.removeInst(inst363);
    return true;
}

static bool matchAndSelectPattern323(MIRInst& inst323, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op324;
    MIROperand op325;
    MIROperand op326;
    if(!matchInstLShr(inst323, op324, op325, op326))
        return false;
    if(!(isOperandI64(op324) && isOperandIReg(op325) && isOperandUImm6(op326)))
        return false;
    // Select
    auto op327 = (op324);
    auto op328 = (op325);
    auto op329 = (op326);
    auto& inst330 = ctx.newInst(SRLI).setOperand<0>(op327).setOperand<1>(op328).setOperand<2>(op329);
    ctx.replaceOperand(ctx.getInstDef(inst323), ctx.getInstDef(inst330));
    ctx.removeInst(inst323);
    return true;
}

static bool matchAndSelectPattern331(MIRInst& inst331, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op332;
    MIROperand op333;
    MIROperand op334;
    if(!matchInstLShr(inst331, op332, op333, op334))
        return false;
    if(!(isOperandI32(op332) && isOperandIReg(op333) && isOperandUImm6(op334)))
        return false;
    // Select
    auto op335 = (op332);
    auto op336 = (op333);
    auto op337 = (op334);
    auto& inst338 = ctx.newInst(SRLIW).setOperand<0>(op335).setOperand<1>(op336).setOperand<2>(op337);
    ctx.replaceOperand(ctx.getInstDef(inst331), ctx.getInstDef(inst338));
    ctx.removeInst(inst331);
    return true;
}

static bool matchAndSelectPattern371(MIRInst& inst371, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op372;
    MIROperand op373;
    MIROperand op374;
    if(!matchInstLShr(inst371, op372, op373, op374))
        return false;
    if(!(isOperandI64(op372) && isOperandIReg(op373) && isOperandIReg(op374)))
        return false;
    // Select
    auto op375 = (op372);
    auto op376 = (op373);
    auto op377 = (op374);
    auto& inst378 = ctx.newInst(SRL).setOperand<0>(op375).setOperand<1>(op376).setOperand<2>(op377);
    ctx.replaceOperand(ctx.getInstDef(inst371), ctx.getInstDef(inst378));
    ctx.removeInst(inst371);
    return true;
}

static bool matchAndSelectPattern379(MIRInst& inst379, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op380;
    MIROperand op381;
    MIROperand op382;
    if(!matchInstLShr(inst379, op380, op381, op382))
        return false;
    if(!(isOperandI32(op380) && isOperandIReg(op381) && isOperandIReg(op382)))
        return false;
    // Select
    auto op383 = (op380);
    auto op384 = (op381);
    auto op385 = (op382);
    auto& inst386 = ctx.newInst(SRLW).setOperand<0>(op383).setOperand<1>(op384).setOperand<2>(op385);
    ctx.replaceOperand(ctx.getInstDef(inst379), ctx.getInstDef(inst386));
    ctx.removeInst(inst379);
    return true;
}

static bool matchAndSelectPattern387(MIRInst& inst387, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMin;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op388;
    MIROperand op389;
    MIROperand op390;
    if(!matchInstSMin(inst387, op388, op389, op390))
        return false;
    if(!(isOperandIReg(op389) && isOperandIReg(op390)))
        return false;
    // Select
    auto op391 = (op388);
    auto op392 = (op389);
    auto op393 = (op390);
    auto& inst394 = ctx.newInst(MIN).setOperand<0>(op391).setOperand<1>(op392).setOperand<2>(op393);
    ctx.replaceOperand(ctx.getInstDef(inst387), ctx.getInstDef(inst394));
    ctx.removeInst(inst387);
    return true;
}

static bool matchAndSelectPattern395(MIRInst& inst395, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMax;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op396;
    MIROperand op397;
    MIROperand op398;
    if(!matchInstSMax(inst395, op396, op397, op398))
        return false;
    if(!(isOperandIReg(op397) && isOperandIReg(op398)))
        return false;
    // Select
    auto op399 = (op396);
    auto op400 = (op397);
    auto op401 = (op398);
    auto& inst402 = ctx.newInst(MAX).setOperand<0>(op399).setOperand<1>(op400).setOperand<2>(op401);
    ctx.replaceOperand(ctx.getInstDef(inst395), ctx.getInstDef(inst402));
    ctx.removeInst(inst395);
    return true;
}

static bool matchAndSelectPattern403(MIRInst& inst403, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op404;
    MIROperand op405;
    MIROperand op406;
    if(!matchInstMul(inst403, op404, op405, op406))
        return false;
    if(!(isOperandI64(op404) && isOperandIReg(op405) && isOperandIReg(op406)))
        return false;
    // Select
    auto op407 = (op404);
    auto op408 = (op405);
    auto op409 = (op406);
    auto& inst410 = ctx.newInst(MUL).setOperand<0>(op407).setOperand<1>(op408).setOperand<2>(op409);
    ctx.replaceOperand(ctx.getInstDef(inst403), ctx.getInstDef(inst410));
    ctx.removeInst(inst403);
    return true;
}

static bool matchAndSelectPattern411(MIRInst& inst411, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op412;
    MIROperand op413;
    MIROperand op414;
    if(!matchInstMul(inst411, op412, op413, op414))
        return false;
    if(!(isOperandI32(op412) && isOperandIReg(op413) && isOperandIReg(op414)))
        return false;
    // Select
    auto op415 = (op412);
    auto op416 = (op413);
    auto op417 = (op414);
    auto& inst418 = ctx.newInst(MULW).setOperand<0>(op415).setOperand<1>(op416).setOperand<2>(op417);
    ctx.replaceOperand(ctx.getInstDef(inst411), ctx.getInstDef(inst418));
    ctx.removeInst(inst411);
    return true;
}

static bool matchAndSelectPattern419(MIRInst& inst419, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op420;
    MIROperand op421;
    MIROperand op422;
    MIROperand op423;
    MIROperand op424;
    MIROperand op425;
    if(!matchInstSDiv(inst419, op420, op421, op422, op423, op424, op425))
        return false;
    MIROperand op426;
    MIROperand op427;
    MIROperand op428;
    if(!(isOperandI32(op420) && isOperandIReg(op421) && isOperandI32(op422) && selectSDiv32ByPowerOf2(op422, op426) &&
         selectAddImm32(ctx, (op422).imm() - 1, op427, op428)))
        return false;
    // Select
    auto op429 = (op420);
    auto op430 = (getVRegAs(ctx, op420));
    auto op431 = (op421);
    auto op432 = (op427);
    auto op433 = (op421);
    auto op434 = (getZero(op420));
    auto op435 = (MIROperand::asImm(CompareOp::ICmpSignedLessThan, OperandType::Int32));
    auto op436 = (op428);
    auto& inst437 = ctx.newInst(Select_GPR_Arith)
                        .setOperand<0>(op430)
                        .setOperand<1>(op431)
                        .setOperand<2>(op432)
                        .setOperand<3>(op433)
                        .setOperand<4>(op434)
                        .setOperand<5>(op435)
                        .setOperand<6>(op436);
    auto& op437 = ctx.getInstDef(inst437);
    auto op438 = (op426);
    auto& inst439 = ctx.newInst(SRAIW).setOperand<0>(op429).setOperand<1>(op437).setOperand<2>(op438);
    ctx.replaceOperand(ctx.getInstDef(inst419), ctx.getInstDef(inst439));
    ctx.removeInst(inst419);
    return true;
}

static bool matchAndSelectPattern440(MIRInst& inst440, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op441;
    MIROperand op442;
    MIROperand op443;
    MIROperand op444;
    MIROperand op445;
    MIROperand op446;
    if(!matchInstSDiv(inst440, op441, op442, op443, op444, op445, op446))
        return false;
    auto instptr443 = ctx.lookupDef(op443);
    if(!instptr443)
        return false;
    auto& inst443 = *instptr443;
    MIROperand op447;
    MIROperand op448;
    MIROperand op449;
    if(!matchInstShl(inst443, op447, op448, op449))
        return false;
    if(!(isOperandI32(op441) && isOperandIReg(op442) && isOne(op448)))
        return false;
    // Select
    auto op450 = (op441);
    auto op451 = (getVRegAs(ctx, op441));
    auto op452 = (op442);
    auto op453 = (getVRegAs(ctx, op441));
    auto op454 = (op447);
    auto op455 = (MIROperand::asImm(-1, OperandType::Int32));
    auto& inst456 = ctx.newInst(ADDIW).setOperand<0>(op453).setOperand<1>(op454).setOperand<2>(op455);
    auto& op456 = ctx.getInstDef(inst456);
    auto op457 = (op442);
    auto op458 = (getZero(op441));
    auto op459 = (MIROperand::asImm(CompareOp::ICmpSignedLessThan, OperandType::Int32));
    auto op460 = (MIROperand::asImm(ADDW, OperandType::Special));
    auto& inst461 = ctx.newInst(Select_GPR_Arith)
                        .setOperand<0>(op451)
                        .setOperand<1>(op452)
                        .setOperand<2>(op456)
                        .setOperand<3>(op457)
                        .setOperand<4>(op458)
                        .setOperand<5>(op459)
                        .setOperand<6>(op460);
    auto& op461 = ctx.getInstDef(inst461);
    auto op462 = (op449);
    auto& inst463 = ctx.newInst(SRAW).setOperand<0>(op450).setOperand<1>(op461).setOperand<2>(op462);
    ctx.replaceOperand(ctx.getInstDef(inst440), ctx.getInstDef(inst463));
    ctx.removeInst(inst440);
    return true;
}

static bool matchAndSelectPattern464(MIRInst& inst464, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op465;
    MIROperand op466;
    MIROperand op467;
    MIROperand op468;
    MIROperand op469;
    MIROperand op470;
    if(!matchInstSDiv(inst464, op465, op466, op467, op468, op469, op470))
        return false;
    MIROperand op471;
    MIROperand op472;
    MIROperand op473;
    MIROperand op474;
    MIROperand op475;
    if(!(isOperandI32(op465) && isOperandIReg(op466) && selectSDiv32ByConstant(op467, op471, op472, op473) &&
         isSDivExpandProfitable(op468, op469, op470, op473, false) && buildMul64Imm(ctx, op466, op471, op473, op474) &&
         buildSRAIW(ctx, op474, op472, op475)))
        return false;
    // Select
    auto op476 = (op465);
    auto op477 = (getVRegAs(ctx, op465));
    auto op478 = (op474);
    auto op479 = (MIROperand::asImm(31, OperandType::Int32));
    auto& inst480 = ctx.newInst(SRLIW).setOperand<0>(op477).setOperand<1>(op478).setOperand<2>(op479);
    auto& op480 = ctx.getInstDef(inst480);
    auto op481 = (op475);
    auto& inst482 = ctx.newInst(ADD).setOperand<0>(op476).setOperand<1>(op480).setOperand<2>(op481);
    ctx.replaceOperand(ctx.getInstDef(inst464), ctx.getInstDef(inst482));
    ctx.removeInst(inst464);
    return true;
}

static bool matchAndSelectPattern483(MIRInst& inst483, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op484;
    MIROperand op485;
    MIROperand op486;
    MIROperand op487;
    MIROperand op488;
    MIROperand op489;
    if(!matchInstSDiv(inst483, op484, op485, op486, op487, op488, op489))
        return false;
    if(!(isOperandI32(op484) && isOperandIReg(op485) && !isOperandIReg(op486)))
        return false;
    // Select
    auto op490 = (op484);
    auto op491 = (op485);
    auto op492 = (getVRegAs(ctx, op484));
    auto op493 = (op486);
    auto& inst494 = ctx.newInst(InstLoadImm).setOperand<0>(op492).setOperand<1>(op493);
    auto& op494 = ctx.getInstDef(inst494);
    auto op495 = (op487);
    auto op496 = (op488);
    auto op497 = (op489);
    auto& inst498 = ctx.newInst(InstSDiv)
                        .setOperand<0>(op490)
                        .setOperand<1>(op491)
                        .setOperand<2>(op494)
                        .setOperand<3>(op495)
                        .setOperand<4>(op496)
                        .setOperand<5>(op497);
    ctx.replaceOperand(ctx.getInstDef(inst483), ctx.getInstDef(inst498));
    ctx.removeInst(inst483);
    return true;
}

static bool matchAndSelectPattern521(MIRInst& inst521, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op522;
    MIROperand op523;
    MIROperand op524;
    MIROperand op525;
    MIROperand op526;
    MIROperand op527;
    if(!matchInstSDiv(inst521, op522, op523, op524, op525, op526, op527))
        return false;
    if(!(isOperandI32(op522) && isOperandIReg(op523) && isOperandIReg(op524)))
        return false;
    // Select
    auto op528 = (op522);
    auto op529 = (op523);
    auto op530 = (op524);
    auto op531 = (op525);
    auto op532 = (op526);
    auto op533 = (op527);
    auto& inst534 = ctx.newInst(DIVW)
                        .setOperand<0>(op528)
                        .setOperand<1>(op529)
                        .setOperand<2>(op530)
                        .setOperand<3>(op531)
                        .setOperand<4>(op532)
                        .setOperand<5>(op533);
    ctx.replaceOperand(ctx.getInstDef(inst521), ctx.getInstDef(inst534));
    ctx.removeInst(inst521);
    return true;
}

static bool matchAndSelectPattern535(MIRInst& inst535, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op536;
    MIROperand op537;
    MIROperand op538;
    MIROperand op539;
    MIROperand op540;
    MIROperand op541;
    if(!matchInstSDiv(inst535, op536, op537, op538, op539, op540, op541))
        return false;
    if(!(isOperandI64(op536) && isOperandIReg(op537) && isOperandIReg(op538)))
        return false;
    // Select
    auto op542 = (op536);
    auto op543 = (op537);
    auto op544 = (op538);
    auto& inst545 = ctx.newInst(DIV).setOperand<0>(op542).setOperand<1>(op543).setOperand<2>(op544);
    ctx.replaceOperand(ctx.getInstDef(inst535), ctx.getInstDef(inst545));
    ctx.removeInst(inst535);
    return true;
}

static bool matchAndSelectPattern499(MIRInst& inst499, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SRLIW;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op500;
    MIROperand op501;
    MIROperand op502;
    if(!matchSRLIW(inst499, op500, op501, op502))
        return false;
    auto instptr501 = ctx.lookupDef(op501);
    if(!instptr501)
        return false;
    auto& inst501 = *instptr501;
    MIROperand op503;
    MIROperand op504;
    MIROperand op505;
    if(!matchSRLI(inst501, op503, op504, op505))
        return false;
    if(!((op505).imm() == 32 && ctx.isSafeToUse(op504, op503)))
        return false;
    // Select
    auto op506 = (op500);
    auto op507 = (op504);
    auto op508 = (MIROperand::asImm((op502).imm() + 32, OperandType::Int32));
    auto& inst509 = ctx.newInst(SRLI).setOperand<0>(op506).setOperand<1>(op507).setOperand<2>(op508);
    ctx.replaceOperand(ctx.getInstDef(inst499), ctx.getInstDef(inst509));
    ctx.removeInst(inst499);
    return true;
}

static bool matchAndSelectPattern510(MIRInst& inst510, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SRAIW;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op511;
    MIROperand op512;
    MIROperand op513;
    if(!matchSRAIW(inst510, op511, op512, op513))
        return false;
    auto instptr512 = ctx.lookupDef(op512);
    if(!instptr512)
        return false;
    auto& inst512 = *instptr512;
    MIROperand op514;
    MIROperand op515;
    MIROperand op516;
    if(!matchSRLI(inst512, op514, op515, op516))
        return false;
    if(!((op516).imm() == 32 && ctx.isSafeToUse(op515, op514)))
        return false;
    // Select
    auto op517 = (op511);
    auto op518 = (op515);
    auto op519 = (MIROperand::asImm((op513).imm() + 32, OperandType::Int32));
    auto& inst520 = ctx.newInst(SRAI).setOperand<0>(op517).setOperand<1>(op518).setOperand<2>(op519);
    ctx.replaceOperand(ctx.getInstDef(inst510), ctx.getInstDef(inst520));
    ctx.removeInst(inst510);
    return true;
}

static bool matchAndSelectPattern546(MIRInst& inst546, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSRem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op547;
    MIROperand op548;
    MIROperand op549;
    MIROperand op550;
    MIROperand op551;
    MIROperand op552;
    if(!matchInstSRem(inst546, op547, op548, op549, op550, op551, op552))
        return false;
    MIROperand op553;
    MIROperand op554;
    MIROperand op555;
    if(!(isOperandI32(op547) && isOperandIReg(op548) && isOperandImm(op549) &&
         selectSDiv32ByConstant(op549, op553, op554, op555) && isSDivExpandProfitable(op550, op551, op552, op555, true)))
        return false;
    // Select
    auto op556 = (op547);
    auto op557 = (op548);
    auto op558 = (getVRegAs(ctx, op547));
    auto op559 = (getVRegAs(ctx, op547));
    auto op560 = (op548);
    auto op561 = (op549);
    auto op562 = (op550);
    auto op563 = (op551);
    auto op564 = (getSDivHint(op552));
    auto& inst565 = ctx.newInst(InstSDiv)
                        .setOperand<0>(op559)
                        .setOperand<1>(op560)
                        .setOperand<2>(op561)
                        .setOperand<3>(op562)
                        .setOperand<4>(op563)
                        .setOperand<5>(op564);
    auto& op565 = ctx.getInstDef(inst565);
    auto op566 = (op549);
    auto& inst567 = ctx.newInst(InstMul).setOperand<0>(op558).setOperand<1>(op565).setOperand<2>(op566);
    auto& op567 = ctx.getInstDef(inst567);
    auto& inst568 = ctx.newInst(SUBW).setOperand<0>(op556).setOperand<1>(op557).setOperand<2>(op567);
    ctx.replaceOperand(ctx.getInstDef(inst546), ctx.getInstDef(inst568));
    ctx.removeInst(inst546);
    return true;
}

static bool matchAndSelectPattern569(MIRInst& inst569, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSRem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op570;
    MIROperand op571;
    MIROperand op572;
    MIROperand op573;
    MIROperand op574;
    MIROperand op575;
    if(!matchInstSRem(inst569, op570, op571, op572, op573, op574, op575))
        return false;
    if(!(isOperandI32(op570) && isOperandIReg(op571) && !isOperandIReg(op572)))
        return false;
    // Select
    auto op576 = (op570);
    auto op577 = (op571);
    auto op578 = (getVRegAs(ctx, op570));
    auto op579 = (op572);
    auto& inst580 = ctx.newInst(InstLoadImm).setOperand<0>(op578).setOperand<1>(op579);
    auto& op580 = ctx.getInstDef(inst580);
    auto op581 = (op573);
    auto op582 = (op574);
    auto op583 = (op575);
    auto& inst584 = ctx.newInst(InstSRem)
                        .setOperand<0>(op576)
                        .setOperand<1>(op577)
                        .setOperand<2>(op580)
                        .setOperand<3>(op581)
                        .setOperand<4>(op582)
                        .setOperand<5>(op583);
    ctx.replaceOperand(ctx.getInstDef(inst569), ctx.getInstDef(inst584));
    ctx.removeInst(inst569);
    return true;
}

static bool matchAndSelectPattern585(MIRInst& inst585, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSRem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op586;
    MIROperand op587;
    MIROperand op588;
    MIROperand op589;
    MIROperand op590;
    MIROperand op591;
    if(!matchInstSRem(inst585, op586, op587, op588, op589, op590, op591))
        return false;
    if(!(isOperandI32(op586) && isOperandIReg(op587) && isOperandIReg(op588)))
        return false;
    // Select
    auto op592 = (op586);
    auto op593 = (op587);
    auto op594 = (op588);
    auto op595 = (op589);
    auto op596 = (op590);
    auto op597 = (op591);
    auto& inst598 = ctx.newInst(REMW)
                        .setOperand<0>(op592)
                        .setOperand<1>(op593)
                        .setOperand<2>(op594)
                        .setOperand<3>(op595)
                        .setOperand<4>(op596)
                        .setOperand<5>(op597);
    ctx.replaceOperand(ctx.getInstDef(inst585), ctx.getInstDef(inst598));
    ctx.removeInst(inst585);
    return true;
}

static bool matchAndSelectPattern599(MIRInst& inst599, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSRem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op600;
    MIROperand op601;
    MIROperand op602;
    MIROperand op603;
    MIROperand op604;
    MIROperand op605;
    if(!matchInstSRem(inst599, op600, op601, op602, op603, op604, op605))
        return false;
    if(!(isOperandI64(op600) && isOperandIReg(op601) && isOperandIReg(op602)))
        return false;
    // Select
    auto op606 = (op600);
    auto op607 = (op601);
    auto op608 = (op602);
    auto& inst609 = ctx.newInst(REM).setOperand<0>(op606).setOperand<1>(op607).setOperand<2>(op608);
    ctx.replaceOperand(ctx.getInstDef(inst599), ctx.getInstDef(inst609));
    ctx.removeInst(inst599);
    return true;
}

static bool matchAndSelectPattern610(MIRInst& inst610, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstUDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op611;
    MIROperand op612;
    MIROperand op613;
    if(!matchInstUDiv(inst610, op611, op612, op613))
        return false;
    if(!(isOperandI32(op611) && isOperandIReg(op612) && isOperandIReg(op613)))
        return false;
    // Select
    auto op614 = (op611);
    auto op615 = (op612);
    auto op616 = (op613);
    auto& inst617 = ctx.newInst(DIVUW).setOperand<0>(op614).setOperand<1>(op615).setOperand<2>(op616);
    ctx.replaceOperand(ctx.getInstDef(inst610), ctx.getInstDef(inst617));
    ctx.removeInst(inst610);
    return true;
}

static bool matchAndSelectPattern626(MIRInst& inst626, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstUDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op627;
    MIROperand op628;
    MIROperand op629;
    if(!matchInstUDiv(inst626, op627, op628, op629))
        return false;
    if(!(isOperandI64(op627) && isOperandIReg(op628) && isOperandIReg(op629)))
        return false;
    // Select
    auto op630 = (op627);
    auto op631 = (op628);
    auto op632 = (op629);
    auto& inst633 = ctx.newInst(DIVU).setOperand<0>(op630).setOperand<1>(op631).setOperand<2>(op632);
    ctx.replaceOperand(ctx.getInstDef(inst626), ctx.getInstDef(inst633));
    ctx.removeInst(inst626);
    return true;
}

static bool matchAndSelectPattern618(MIRInst& inst618, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstURem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op619;
    MIROperand op620;
    MIROperand op621;
    if(!matchInstURem(inst618, op619, op620, op621))
        return false;
    if(!(isOperandI32(op619) && isOperandIReg(op620) && isOperandIReg(op621)))
        return false;
    // Select
    auto op622 = (op619);
    auto op623 = (op620);
    auto op624 = (op621);
    auto& inst625 = ctx.newInst(REMUW).setOperand<0>(op622).setOperand<1>(op623).setOperand<2>(op624);
    ctx.replaceOperand(ctx.getInstDef(inst618), ctx.getInstDef(inst625));
    ctx.removeInst(inst618);
    return true;
}

static bool matchAndSelectPattern634(MIRInst& inst634, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstURem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op635;
    MIROperand op636;
    MIROperand op637;
    if(!matchInstURem(inst634, op635, op636, op637))
        return false;
    if(!(isOperandI64(op635) && isOperandIReg(op636) && isOperandIReg(op637)))
        return false;
    // Select
    auto op638 = (op635);
    auto op639 = (op636);
    auto op640 = (op637);
    auto& inst641 = ctx.newInst(REMU).setOperand<0>(op638).setOperand<1>(op639).setOperand<2>(op640);
    ctx.replaceOperand(ctx.getInstDef(inst634), ctx.getInstDef(inst641));
    ctx.removeInst(inst634);
    return true;
}

static bool matchAndSelectPattern642(MIRInst& inst642, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SLLI;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op643;
    MIROperand op644;
    MIROperand op645;
    if(!matchSLLI(inst642, op643, op644, op645))
        return false;
    auto instptr644 = ctx.lookupDef(op644);
    if(!instptr644)
        return false;
    auto& inst644 = *instptr644;
    MIROperand op646;
    MIROperand op647;
    MIROperand op648;
    if(!matchSRAIW(inst644, op646, op647, op648))
        return false;
    MIROperand op649;
    if(!((op648) == (op645) && selectShiftImm12Mask(op648, op649)))
        return false;
    // Select
    auto op650 = (op643);
    auto op651 = (op647);
    auto op652 = (op649);
    auto& inst653 = ctx.newInst(ANDI).setOperand<0>(op650).setOperand<1>(op651).setOperand<2>(op652);
    ctx.replaceOperand(ctx.getInstDef(inst642), ctx.getInstDef(inst653));
    ctx.removeInst(inst642);
    return true;
}

static bool matchAndSelectPattern1246(MIRInst& inst1246, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SLLI;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1247;
    MIROperand op1248;
    MIROperand op1249;
    if(!matchSLLI(inst1246, op1247, op1248, op1249))
        return false;
    auto instptr1248 = ctx.lookupDef(op1248);
    if(!instptr1248)
        return false;
    auto& inst1248 = *instptr1248;
    MIROperand op1250;
    MIROperand op1251;
    if(!matchLoadImm12(inst1248, op1250, op1251))
        return false;
    // Select
    auto op1252 = (op1247);
    auto op1253 = (getShiftedImm64(op1251, op1249));
    auto& inst1254 = ctx.newInst(LoadImm64).setOperand<0>(op1252).setOperand<1>(op1253);
    ctx.replaceOperand(ctx.getInstDef(inst1246), ctx.getInstDef(inst1254));
    ctx.removeInst(inst1246);
    return true;
}

static bool matchAndSelectPattern1255(MIRInst& inst1255, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SLLI;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1256;
    MIROperand op1257;
    MIROperand op1258;
    if(!matchSLLI(inst1255, op1256, op1257, op1258))
        return false;
    auto instptr1257 = ctx.lookupDef(op1257);
    if(!instptr1257)
        return false;
    auto& inst1257 = *instptr1257;
    MIROperand op1259;
    MIROperand op1260;
    if(!matchLoadImm32(inst1257, op1259, op1260))
        return false;
    if(!(ctx.hasOneUse(op1259)))
        return false;
    // Select
    auto op1261 = (op1256);
    auto op1262 = (getShiftedImm64(op1260, op1258));
    auto& inst1263 = ctx.newInst(LoadImm64).setOperand<0>(op1261).setOperand<1>(op1262);
    ctx.replaceOperand(ctx.getInstDef(inst1255), ctx.getInstDef(inst1263));
    ctx.removeInst(inst1255);
    return true;
}

static bool matchAndSelectPattern654(MIRInst& inst654, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SLLIW;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op655;
    MIROperand op656;
    MIROperand op657;
    if(!matchSLLIW(inst654, op655, op656, op657))
        return false;
    auto instptr656 = ctx.lookupDef(op656);
    if(!instptr656)
        return false;
    auto& inst656 = *instptr656;
    MIROperand op658;
    MIROperand op659;
    MIROperand op660;
    if(!matchSRAIW(inst656, op658, op659, op660))
        return false;
    MIROperand op661;
    if(!((op660) == (op657) && selectShiftImm12Mask(op660, op661)))
        return false;
    // Select
    auto op662 = (op655);
    auto op663 = (op659);
    auto op664 = (op661);
    auto& inst665 = ctx.newInst(ANDI).setOperand<0>(op662).setOperand<1>(op663).setOperand<2>(op664);
    ctx.replaceOperand(ctx.getInstDef(inst654), ctx.getInstDef(inst665));
    ctx.removeInst(inst654);
    return true;
}

static bool matchAndSelectPattern666(MIRInst& inst666, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op667;
    MIROperand op668;
    MIROperand op669;
    MIROperand op670;
    if(!matchInstICmp(inst666, op667, op668, op669, op670))
        return false;
    if(!(isOperandIReg(op668) && isOperandIReg(op669) && isCompareOp(op670, CompareOp::ICmpSignedLessThan)))
        return false;
    // Select
    auto op671 = (op667);
    auto op672 = (op668);
    auto op673 = (op669);
    auto& inst674 = ctx.newInst(SLT).setOperand<0>(op671).setOperand<1>(op672).setOperand<2>(op673);
    ctx.replaceOperand(ctx.getInstDef(inst666), ctx.getInstDef(inst674));
    ctx.removeInst(inst666);
    return true;
}

static bool matchAndSelectPattern675(MIRInst& inst675, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op676;
    MIROperand op677;
    MIROperand op678;
    MIROperand op679;
    if(!matchInstICmp(inst675, op676, op677, op678, op679))
        return false;
    if(!(isOperandIReg(op677) && isOperandIReg(op678) && isCompareOp(op679, CompareOp::ICmpUnsignedLessThan)))
        return false;
    // Select
    auto op680 = (op676);
    auto op681 = (op677);
    auto op682 = (op678);
    auto& inst683 = ctx.newInst(SLTU).setOperand<0>(op680).setOperand<1>(op681).setOperand<2>(op682);
    ctx.replaceOperand(ctx.getInstDef(inst675), ctx.getInstDef(inst683));
    ctx.removeInst(inst675);
    return true;
}

static bool matchAndSelectPattern684(MIRInst& inst684, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op685;
    MIROperand op686;
    MIROperand op687;
    MIROperand op688;
    if(!matchInstICmp(inst684, op685, op686, op687, op688))
        return false;
    if(!(isOperandIReg(op686) && isOperandIReg(op687) && isCompareOp(op688, CompareOp::ICmpSignedGreaterThan)))
        return false;
    // Select
    auto op689 = (op685);
    auto op690 = (op687);
    auto op691 = (op686);
    auto& inst692 = ctx.newInst(SLT).setOperand<0>(op689).setOperand<1>(op690).setOperand<2>(op691);
    ctx.replaceOperand(ctx.getInstDef(inst684), ctx.getInstDef(inst692));
    ctx.removeInst(inst684);
    return true;
}

static bool matchAndSelectPattern693(MIRInst& inst693, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op694;
    MIROperand op695;
    MIROperand op696;
    MIROperand op697;
    if(!matchInstICmp(inst693, op694, op695, op696, op697))
        return false;
    if(!(isOperandIReg(op695) && isOperandIReg(op696) && isCompareOp(op697, CompareOp::ICmpUnsignedGreaterThan)))
        return false;
    // Select
    auto op698 = (op694);
    auto op699 = (op696);
    auto op700 = (op695);
    auto& inst701 = ctx.newInst(SLTU).setOperand<0>(op698).setOperand<1>(op699).setOperand<2>(op700);
    ctx.replaceOperand(ctx.getInstDef(inst693), ctx.getInstDef(inst701));
    ctx.removeInst(inst693);
    return true;
}

static bool matchAndSelectPattern702(MIRInst& inst702, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op703;
    MIROperand op704;
    MIROperand op705;
    MIROperand op706;
    if(!matchInstICmp(inst702, op703, op704, op705, op706))
        return false;
    if(!(isOperandIReg(op704) && isOperandImm12(op705) && isCompareOp(op706, CompareOp::ICmpSignedLessThan)))
        return false;
    // Select
    auto op707 = (op703);
    auto op708 = (op704);
    auto op709 = (op705);
    auto& inst710 = ctx.newInst(SLTI).setOperand<0>(op707).setOperand<1>(op708).setOperand<2>(op709);
    ctx.replaceOperand(ctx.getInstDef(inst702), ctx.getInstDef(inst710));
    ctx.removeInst(inst702);
    return true;
}

static bool matchAndSelectPattern711(MIRInst& inst711, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op712;
    MIROperand op713;
    MIROperand op714;
    MIROperand op715;
    if(!matchInstICmp(inst711, op712, op713, op714, op715))
        return false;
    if(!(isOperandIReg(op713) && isOperandImm12(op714) && isCompareOp(op715, CompareOp::ICmpUnsignedLessThan)))
        return false;
    // Select
    auto op716 = (op712);
    auto op717 = (op713);
    auto op718 = (op714);
    auto& inst719 = ctx.newInst(SLTIU).setOperand<0>(op716).setOperand<1>(op717).setOperand<2>(op718);
    ctx.replaceOperand(ctx.getInstDef(inst711), ctx.getInstDef(inst719));
    ctx.removeInst(inst711);
    return true;
}

static bool matchAndSelectPattern720(MIRInst& inst720, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op721;
    MIROperand op722;
    MIROperand op723;
    MIROperand op724;
    if(!matchInstICmp(inst720, op721, op722, op723, op724))
        return false;
    if(!(isOperandIReg(op722) && isZero(op723) && isCompareOp(op724, CompareOp::ICmpEqual)))
        return false;
    // Select
    auto op725 = (op721);
    auto op726 = (op722);
    auto op727 = (getOne(op722));
    auto& inst728 = ctx.newInst(SLTIU).setOperand<0>(op725).setOperand<1>(op726).setOperand<2>(op727);
    ctx.replaceOperand(ctx.getInstDef(inst720), ctx.getInstDef(inst728));
    ctx.removeInst(inst720);
    return true;
}

static bool matchAndSelectPattern729(MIRInst& inst729, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op730;
    MIROperand op731;
    MIROperand op732;
    MIROperand op733;
    if(!matchInstICmp(inst729, op730, op731, op732, op733))
        return false;
    if(!(isOperandIReg(op731) && isZero(op732) && isCompareOp(op733, CompareOp::ICmpNotEqual)))
        return false;
    // Select
    auto op734 = (op730);
    auto op735 = (getZero(op732));
    auto op736 = (op731);
    auto& inst737 = ctx.newInst(SLTU).setOperand<0>(op734).setOperand<1>(op735).setOperand<2>(op736);
    ctx.replaceOperand(ctx.getInstDef(inst729), ctx.getInstDef(inst737));
    ctx.removeInst(inst729);
    return true;
}

static bool matchAndSelectPattern738(MIRInst& inst738, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op739;
    MIROperand op740;
    MIROperand op741;
    MIROperand op742;
    if(!matchInstICmp(inst738, op739, op740, op741, op742))
        return false;
    if(!(isOperandIReg(op740) && isOperandIReg(op741) && isCompareOp(op742, CompareOp::ICmpSignedLessEqual)))
        return false;
    // Select
    auto op743 = (op739);
    auto op744 = (getVRegAs(ctx, op739));
    auto op745 = (op741);
    auto op746 = (op740);
    auto& inst747 = ctx.newInst(SLT).setOperand<0>(op744).setOperand<1>(op745).setOperand<2>(op746);
    auto& op747 = ctx.getInstDef(inst747);
    auto op748 = (getOne(op739));
    auto& inst749 = ctx.newInst(XORI).setOperand<0>(op743).setOperand<1>(op747).setOperand<2>(op748);
    ctx.replaceOperand(ctx.getInstDef(inst738), ctx.getInstDef(inst749));
    ctx.removeInst(inst738);
    return true;
}

static bool matchAndSelectPattern750(MIRInst& inst750, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op751;
    MIROperand op752;
    MIROperand op753;
    MIROperand op754;
    if(!matchInstICmp(inst750, op751, op752, op753, op754))
        return false;
    if(!(isOperandIReg(op752) && isOperandIReg(op753) && isCompareOp(op754, CompareOp::ICmpUnsignedLessEqual)))
        return false;
    // Select
    auto op755 = (op751);
    auto op756 = (getVRegAs(ctx, op751));
    auto op757 = (op753);
    auto op758 = (op752);
    auto& inst759 = ctx.newInst(SLTU).setOperand<0>(op756).setOperand<1>(op757).setOperand<2>(op758);
    auto& op759 = ctx.getInstDef(inst759);
    auto op760 = (getOne(op751));
    auto& inst761 = ctx.newInst(XORI).setOperand<0>(op755).setOperand<1>(op759).setOperand<2>(op760);
    ctx.replaceOperand(ctx.getInstDef(inst750), ctx.getInstDef(inst761));
    ctx.removeInst(inst750);
    return true;
}

static bool matchAndSelectPattern762(MIRInst& inst762, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op763;
    MIROperand op764;
    if(!matchInstZExt(inst762, op763, op764))
        return false;
    if(!(isOperandBoolReg(op764)))
        return false;
    // Select
    auto op765 = (op763);
    auto op766 = (op764);
    auto& inst767 = ctx.newInst(InstCopy).setOperand<0>(op765).setOperand<1>(op766);
    ctx.replaceOperand(ctx.getInstDef(inst762), ctx.getInstDef(inst767));
    ctx.removeInst(inst762);
    return true;
}

static bool matchAndSelectPattern768(MIRInst& inst768, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op769;
    MIROperand op770;
    if(!matchInstZExt(inst768, op769, op770))
        return false;
    if(!(isOperandIReg(op770) && (op770).type() == OperandType::Int8))
        return false;
    // Select
    auto op771 = (op769);
    auto op772 = (op770);
    auto op773 = (getZExtMask((op769).type(), (op770).type()));
    auto& inst774 = ctx.newInst(ANDI).setOperand<0>(op771).setOperand<1>(op772).setOperand<2>(op773);
    ctx.replaceOperand(ctx.getInstDef(inst768), ctx.getInstDef(inst774));
    ctx.removeInst(inst768);
    return true;
}

static bool matchAndSelectPattern775(MIRInst& inst775, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op776;
    MIROperand op777;
    if(!matchInstZExt(inst775, op776, op777))
        return false;
    if(!(isOperandIReg(op777) && (op777).type() == OperandType::Int32))
        return false;
    // Select
    auto op778 = (op776);
    auto op779 = (op777);
    auto& inst780 = ctx.newInst(ZEXT_W).setOperand<0>(op778).setOperand<1>(op779);
    ctx.replaceOperand(ctx.getInstDef(inst775), ctx.getInstDef(inst780));
    ctx.removeInst(inst775);
    return true;
}

static bool matchAndSelectPattern781(MIRInst& inst781, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op782;
    MIROperand op783;
    if(!matchInstZExt(inst781, op782, op783))
        return false;
    if(!(isOperandIReg(op783) && (op783).type() == OperandType::Int16))
        return false;
    // Select
    auto op784 = (op782);
    auto op785 = (op783);
    auto& inst786 = ctx.newInst(ZEXT_H).setOperand<0>(op784).setOperand<1>(op785);
    ctx.replaceOperand(ctx.getInstDef(inst781), ctx.getInstDef(inst786));
    ctx.removeInst(inst781);
    return true;
}

static bool matchAndSelectPattern929(MIRInst& inst929, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op930;
    MIROperand op931;
    if(!matchInstZExt(inst929, op930, op931))
        return false;
    auto instptr931 = ctx.lookupDef(op931);
    if(!instptr931)
        return false;
    auto& inst931 = *instptr931;
    MIROperand op932;
    MIROperand op933;
    MIROperand op934;
    if(!matchInstLoad(inst931, op932, op933, op934))
        return false;
    MIROperand op935;
    MIROperand op936;
    if(!(ctx.isSafeToUse(op933, op932) && selectAddrOffset(op933, ctx, op935, op936)))
        return false;
    // Select
    auto op937 = (op930);
    auto op938 = (op935);
    auto op939 = (op936);
    auto op940 = (op934);
    auto& inst941 =
        ctx.newInst(getZExtLoadOpcode(op932)).setOperand<0>(op937).setOperand<1>(op939).setOperand<2>(op938).setOperand<3>(op940);
    ctx.replaceOperand(ctx.getInstDef(inst929), ctx.getInstDef(inst941));
    ctx.removeInst(inst929);
    return true;
}

static bool matchAndSelectPattern1128(MIRInst& inst1128, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1129;
    MIROperand op1130;
    if(!matchInstZExt(inst1128, op1129, op1130))
        return false;
    auto instptr1130 = ctx.lookupDef(op1130);
    if(!instptr1130)
        return false;
    auto& inst1130 = *instptr1130;
    MIROperand op1131;
    MIROperand op1132;
    MIROperand op1133;
    if(!matchANDI(inst1130, op1131, op1132, op1133))
        return false;
    if(!((op1131).type() == OperandType::Int32 && (op1129).type() == OperandType::Int64))
        return false;
    // Select
    auto op1134 = (op1129);
    auto op1135 = (op1131);
    auto& inst1136 = ctx.newInst(InstCopy).setOperand<0>(op1134).setOperand<1>(op1135);
    ctx.replaceOperand(ctx.getInstDef(inst1128), ctx.getInstDef(inst1136));
    ctx.removeInst(inst1128);
    return true;
}

static bool matchAndSelectPattern1137(MIRInst& inst1137, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1138;
    MIROperand op1139;
    if(!matchInstZExt(inst1137, op1138, op1139))
        return false;
    if(!(isOperandIReg(op1139) && ((op1138).type() == OperandType::Int32 || (op1138).type() == OperandType::Int64)))
        return false;
    // Select
    auto op1140 = (op1138);
    auto op1141 = (op1139);
    auto op1142 = (getVRegAs(ctx, op1139));
    auto op1143 = (getZExtMask((op1138).type(), (op1139).type()));
    auto& inst1144 = ctx.newInst(LoadImm32).setOperand<0>(op1142).setOperand<1>(op1143);
    auto& op1144 = ctx.getInstDef(inst1144);
    auto& inst1145 = ctx.newInst(AND).setOperand<0>(op1140).setOperand<1>(op1141).setOperand<2>(op1144);
    ctx.replaceOperand(ctx.getInstDef(inst1137), ctx.getInstDef(inst1145));
    ctx.removeInst(inst1137);
    return true;
}

static bool matchAndSelectPattern787(MIRInst& inst787, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op788;
    MIROperand op789;
    if(!matchInstSExt(inst787, op788, op789))
        return false;
    if(!(isOperandIReg(op789)))
        return false;
    // Select
    auto op790 = (op788);
    auto op791 = (op789);
    auto& inst792 = ctx.newInst(InstCopy).setOperand<0>(op790).setOperand<1>(op791);
    ctx.replaceOperand(ctx.getInstDef(inst787), ctx.getInstDef(inst792));
    ctx.removeInst(inst787);
    return true;
}

static bool matchAndSelectPattern793(MIRInst& inst793, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstUnreachable;
    CMMC_UNUSED(rootOpcode);
    // Match
    if(!matchInstUnreachable(inst793))
        return false;
    // Select
    auto& inst794 = ctx.newInst(UNIMP);
    CMMC_UNUSED(inst794);
    ctx.removeInst(inst793);
    return true;
}

static bool matchAndSelectPattern795(MIRInst& inst795, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstJump;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op796;
    if(!matchInstJump(inst795, op796))
        return false;
    // Select
    auto op797 = (op796);
    auto& inst798 = ctx.newInst(J).setOperand<0>(op797);
    CMMC_UNUSED(inst798);
    ctx.removeInst(inst795);
    return true;
}

static bool matchAndSelectPattern799(MIRInst& inst799, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op800;
    MIROperand op801;
    MIROperand op802;
    if(!matchInstBranch(inst799, op800, op801, op802))
        return false;
    auto instptr800 = ctx.lookupDef(op800);
    if(!instptr800)
        return false;
    auto& inst800 = *instptr800;
    MIROperand op803;
    MIROperand op804;
    MIROperand op805;
    MIROperand op806;
    if(!matchInstICmp(inst800, op803, op804, op805, op806))
        return false;
    if(!(isOperandIReg(op804) && isZero(op805) && ctx.isSafeToUse(op804, op803)))
        return false;
    // Select
    auto op807 = (op804);
    auto op808 = (getZero(op804));
    auto op809 = (op801);
    auto op810 = (op802);
    auto& inst811 = ctx.newInst(getICmpBranchOpcode(op806))
                        .setOperand<0>(op807)
                        .setOperand<1>(op808)
                        .setOperand<2>(op809)
                        .setOperand<3>(op810);
    CMMC_UNUSED(inst811);
    ctx.removeInst(inst799);
    return true;
}

static bool matchAndSelectPattern812(MIRInst& inst812, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op813;
    MIROperand op814;
    MIROperand op815;
    if(!matchInstBranch(inst812, op813, op814, op815))
        return false;
    auto instptr813 = ctx.lookupDef(op813);
    if(!instptr813)
        return false;
    auto& inst813 = *instptr813;
    MIROperand op816;
    MIROperand op817;
    MIROperand op818;
    MIROperand op819;
    if(!matchInstICmp(inst813, op816, op817, op818, op819))
        return false;
    if(!(isOperandIReg(op817) && isOne(op818) && isCompareOp(op819, CompareOp::ICmpSignedGreaterEqual) &&
         ctx.isSafeToUse(op817, op816)))
        return false;
    // Select
    auto op820 = (op817);
    auto op821 = (getZero(op817));
    auto op822 = (op814);
    auto op823 = (op815);
    auto& inst824 = ctx.newInst(BGT).setOperand<0>(op820).setOperand<1>(op821).setOperand<2>(op822).setOperand<3>(op823);
    CMMC_UNUSED(inst824);
    ctx.removeInst(inst812);
    return true;
}

static bool matchAndSelectPattern825(MIRInst& inst825, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op826;
    MIROperand op827;
    MIROperand op828;
    if(!matchInstBranch(inst825, op826, op827, op828))
        return false;
    auto instptr826 = ctx.lookupDef(op826);
    if(!instptr826)
        return false;
    auto& inst826 = *instptr826;
    MIROperand op829;
    MIROperand op830;
    MIROperand op831;
    MIROperand op832;
    if(!matchInstICmp(inst826, op829, op830, op831, op832))
        return false;
    if(!(isOperandIReg(op830) && isNegativeOne(op831) && isCompareOp(op832, CompareOp::ICmpSignedGreaterThan) &&
         ctx.isSafeToUse(op830, op829)))
        return false;
    // Select
    auto op833 = (op830);
    auto op834 = (getZero(op830));
    auto op835 = (op827);
    auto op836 = (op828);
    auto& inst837 = ctx.newInst(BGE).setOperand<0>(op833).setOperand<1>(op834).setOperand<2>(op835).setOperand<3>(op836);
    CMMC_UNUSED(inst837);
    ctx.removeInst(inst825);
    return true;
}

static bool matchAndSelectPattern838(MIRInst& inst838, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op839;
    MIROperand op840;
    MIROperand op841;
    if(!matchInstBranch(inst838, op839, op840, op841))
        return false;
    auto instptr839 = ctx.lookupDef(op839);
    if(!instptr839)
        return false;
    auto& inst839 = *instptr839;
    MIROperand op842;
    MIROperand op843;
    MIROperand op844;
    MIROperand op845;
    if(!matchInstICmp(inst839, op842, op843, op844, op845))
        return false;
    if(!(isOperandIReg(op843) && isOne(op844) && isCompareOp(op845, CompareOp::ICmpSignedLessThan) &&
         ctx.isSafeToUse(op843, op842)))
        return false;
    // Select
    auto op846 = (op843);
    auto op847 = (getZero(op843));
    auto op848 = (op840);
    auto op849 = (op841);
    auto& inst850 = ctx.newInst(BLE).setOperand<0>(op846).setOperand<1>(op847).setOperand<2>(op848).setOperand<3>(op849);
    CMMC_UNUSED(inst850);
    ctx.removeInst(inst838);
    return true;
}

static bool matchAndSelectPattern851(MIRInst& inst851, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op852;
    MIROperand op853;
    MIROperand op854;
    if(!matchInstBranch(inst851, op852, op853, op854))
        return false;
    auto instptr852 = ctx.lookupDef(op852);
    if(!instptr852)
        return false;
    auto& inst852 = *instptr852;
    MIROperand op855;
    MIROperand op856;
    MIROperand op857;
    MIROperand op858;
    if(!matchInstICmp(inst852, op855, op856, op857, op858))
        return false;
    if(!(isOperandIReg(op856) && isNegativeOne(op857) && isCompareOp(op858, CompareOp::ICmpSignedLessEqual) &&
         ctx.isSafeToUse(op856, op855)))
        return false;
    // Select
    auto op859 = (op856);
    auto op860 = (getZero(op856));
    auto op861 = (op853);
    auto op862 = (op854);
    auto& inst863 = ctx.newInst(BLT).setOperand<0>(op859).setOperand<1>(op860).setOperand<2>(op861).setOperand<3>(op862);
    CMMC_UNUSED(inst863);
    ctx.removeInst(inst851);
    return true;
}

static bool matchAndSelectPattern864(MIRInst& inst864, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op865;
    MIROperand op866;
    MIROperand op867;
    if(!matchInstBranch(inst864, op865, op866, op867))
        return false;
    auto instptr865 = ctx.lookupDef(op865);
    if(!instptr865)
        return false;
    auto& inst865 = *instptr865;
    MIROperand op868;
    MIROperand op869;
    MIROperand op870;
    MIROperand op871;
    if(!matchInstICmp(inst865, op868, op869, op870, op871))
        return false;
    if(!(isOperandIReg(op869) && isOperandImm(op870) && ctx.isSafeToUse(op869, op868)))
        return false;
    // Select
    auto op872 = (op869);
    auto op873 = (getVRegAs(ctx, op869));
    auto op874 = (op870);
    auto& inst875 = ctx.newInst(InstLoadImm).setOperand<0>(op873).setOperand<1>(op874);
    auto& op875 = ctx.getInstDef(inst875);
    auto op876 = (op866);
    auto op877 = (op867);
    auto& inst878 = ctx.newInst(getICmpBranchOpcode(op871))
                        .setOperand<0>(op872)
                        .setOperand<1>(op875)
                        .setOperand<2>(op876)
                        .setOperand<3>(op877);
    CMMC_UNUSED(inst878);
    ctx.removeInst(inst864);
    return true;
}

static bool matchAndSelectPattern879(MIRInst& inst879, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op880;
    MIROperand op881;
    MIROperand op882;
    if(!matchInstBranch(inst879, op880, op881, op882))
        return false;
    auto instptr880 = ctx.lookupDef(op880);
    if(!instptr880)
        return false;
    auto& inst880 = *instptr880;
    MIROperand op883;
    MIROperand op884;
    MIROperand op885;
    MIROperand op886;
    if(!matchInstICmp(inst880, op883, op884, op885, op886))
        return false;
    if(!(isOperandIReg(op884) && isOperandIReg(op885) && ctx.isSafeToUse(op884, op883) && ctx.isSafeToUse(op885, op883)))
        return false;
    // Select
    auto op887 = (op884);
    auto op888 = (op885);
    auto op889 = (op881);
    auto op890 = (op882);
    auto& inst891 = ctx.newInst(getICmpBranchOpcode(op886))
                        .setOperand<0>(op887)
                        .setOperand<1>(op888)
                        .setOperand<2>(op889)
                        .setOperand<3>(op890);
    CMMC_UNUSED(inst891);
    ctx.removeInst(inst879);
    return true;
}

static bool matchAndSelectPattern892(MIRInst& inst892, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op893;
    MIROperand op894;
    MIROperand op895;
    if(!matchInstBranch(inst892, op893, op894, op895))
        return false;
    auto instptr893 = ctx.lookupDef(op893);
    if(!instptr893)
        return false;
    auto& inst893 = *instptr893;
    MIROperand op896;
    MIROperand op897;
    MIROperand op898;
    MIROperand op899;
    if(!matchInstFCmp(inst893, op896, op897, op898, op899))
        return false;
    if(!(isFCmpUnorderedOp(op899) && ctx.isSafeToUse(op897, op896) && ctx.isSafeToUse(op898, op896)))
        return false;
    // Select
    auto op900 = (getVRegAs(ctx, op896));
    auto op901 = (op897);
    auto op902 = (op898);
    auto op903 = (getFCmpOrderedOp(op899));
    auto& inst904 = ctx.newInst(InstFCmp).setOperand<0>(op900).setOperand<1>(op901).setOperand<2>(op902).setOperand<3>(op903);
    auto& op904 = ctx.getInstDef(inst904);
    auto op905 = (getZero(op896));
    auto op906 = (op894);
    auto op907 = (op895);
    auto& inst908 = ctx.newInst(BEQ).setOperand<0>(op904).setOperand<1>(op905).setOperand<2>(op906).setOperand<3>(op907);
    CMMC_UNUSED(inst908);
    ctx.removeInst(inst892);
    return true;
}

static bool matchAndSelectPattern909(MIRInst& inst909, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op910;
    MIROperand op911;
    MIROperand op912;
    if(!matchInstBranch(inst909, op910, op911, op912))
        return false;
    if(!(isOperandIReg(op910)))
        return false;
    // Select
    auto op913 = (op910);
    auto op914 = (getZero(op910));
    auto op915 = (op911);
    auto op916 = (op912);
    auto& inst917 = ctx.newInst(BNE).setOperand<0>(op913).setOperand<1>(op914).setOperand<2>(op915).setOperand<3>(op916);
    CMMC_UNUSED(inst917);
    ctx.removeInst(inst909);
    return true;
}

static bool matchAndSelectPattern918(MIRInst& inst918, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoad;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op919;
    MIROperand op920;
    MIROperand op921;
    if(!matchInstLoad(inst918, op919, op920, op921))
        return false;
    MIROperand op922;
    MIROperand op923;
    if(!(selectAddrOffset(op920, ctx, op922, op923)))
        return false;
    // Select
    auto op924 = (op919);
    auto op925 = (op922);
    auto op926 = (op923);
    auto op927 = (op921);
    auto& inst928 =
        ctx.newInst(getLoadOpcode(op919)).setOperand<0>(op924).setOperand<1>(op926).setOperand<2>(op925).setOperand<3>(op927);
    ctx.replaceOperand(ctx.getInstDef(inst918), ctx.getInstDef(inst928));
    ctx.removeInst(inst918);
    return true;
}

static bool matchAndSelectPattern942(MIRInst& inst942, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstStore;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op943;
    MIROperand op944;
    MIROperand op945;
    if(!matchInstStore(inst942, op943, op944, op945))
        return false;
    auto instptr944 = ctx.lookupDef(op944);
    if(!instptr944)
        return false;
    auto& inst944 = *instptr944;
    MIROperand op946;
    MIROperand op947;
    if(!matchInstTrunc(inst944, op946, op947))
        return false;
    if(!(ctx.isSafeToUse(op947, op946)))
        return false;
    MIROperand op948;
    MIROperand op949;
    if(!(isOperandVRegOrISAReg(op947) && selectAddrOffset(op943, ctx, op948, op949)))
        return false;
    // Select
    auto op950 = (op947);
    auto op951 = (op948);
    auto op952 = (op949);
    auto op953 = (op945);
    auto& inst954 =
        ctx.newInst(getStoreOpcode(op946)).setOperand<0>(op950).setOperand<1>(op952).setOperand<2>(op951).setOperand<3>(op953);
    CMMC_UNUSED(inst954);
    ctx.removeInst(inst942);
    return true;
}

static bool matchAndSelectPattern955(MIRInst& inst955, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstStore;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op956;
    MIROperand op957;
    MIROperand op958;
    if(!matchInstStore(inst955, op956, op957, op958))
        return false;
    MIROperand op959;
    MIROperand op960;
    if(!(isOperandVRegOrISAReg(op957) && selectAddrOffset(op956, ctx, op959, op960)))
        return false;
    // Select
    auto op961 = (op957);
    auto op962 = (op959);
    auto op963 = (op960);
    auto op964 = (op958);
    auto& inst965 =
        ctx.newInst(getStoreOpcode(op957)).setOperand<0>(op961).setOperand<1>(op963).setOperand<2>(op962).setOperand<3>(op964);
    CMMC_UNUSED(inst965);
    ctx.removeInst(inst955);
    return true;
}

static bool matchAndSelectPattern966(MIRInst& inst966, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstF2S;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op967;
    MIROperand op968;
    if(!matchInstF2S(inst966, op967, op968))
        return false;
    // Select
    auto op969 = (op967);
    auto op970 = (op968);
    auto& inst971 = ctx.newInst(FCVT_W_S).setOperand<0>(op969).setOperand<1>(op970);
    ctx.replaceOperand(ctx.getInstDef(inst966), ctx.getInstDef(inst971));
    ctx.removeInst(inst966);
    return true;
}

static bool matchAndSelectPattern972(MIRInst& inst972, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstS2F;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op973;
    MIROperand op974;
    if(!matchInstS2F(inst972, op973, op974))
        return false;
    // Select
    auto op975 = (op973);
    auto op976 = (op974);
    auto& inst977 = ctx.newInst(FCVT_S_W).setOperand<0>(op975).setOperand<1>(op976);
    ctx.replaceOperand(ctx.getInstDef(inst972), ctx.getInstDef(inst977));
    ctx.removeInst(inst972);
    return true;
}

static bool matchAndSelectPattern978(MIRInst& inst978, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op979;
    MIROperand op980;
    MIROperand op981;
    if(!matchInstFAdd(inst978, op979, op980, op981))
        return false;
    auto instptr980 = ctx.lookupDef(op980);
    if(!instptr980)
        return false;
    auto& inst980 = *instptr980;
    MIROperand op982;
    MIROperand op983;
    MIROperand op984;
    if(!matchInstFMul(inst980, op982, op983, op984))
        return false;
    if(!(isAggressiveOptEnabled() && ctx.hasOneUse(op982)))
        return false;
    // Select
    auto op985 = (op979);
    auto op986 = (op983);
    auto op987 = (op984);
    auto op988 = (op981);
    auto& inst989 = ctx.newInst(FMADD_S).setOperand<0>(op985).setOperand<1>(op986).setOperand<2>(op987).setOperand<3>(op988);
    ctx.replaceOperand(ctx.getInstDef(inst978), ctx.getInstDef(inst989));
    ctx.removeInst(inst978);
    return true;
}

static bool matchAndSelectPattern1002(MIRInst& inst1002, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1003;
    MIROperand op1004;
    MIROperand op1005;
    if(!matchInstFAdd(inst1002, op1003, op1004, op1005))
        return false;
    auto instptr1004 = ctx.lookupDef(op1004);
    if(!instptr1004)
        return false;
    auto& inst1004 = *instptr1004;
    MIROperand op1006;
    MIROperand op1007;
    if(!matchInstFNeg(inst1004, op1006, op1007))
        return false;
    auto instptr1007 = ctx.lookupDef(op1007);
    if(!instptr1007)
        return false;
    auto& inst1007 = *instptr1007;
    MIROperand op1008;
    MIROperand op1009;
    MIROperand op1010;
    if(!matchInstFMul(inst1007, op1008, op1009, op1010))
        return false;
    if(!(isAggressiveOptEnabled() && ctx.hasOneUse(op1008) && ctx.hasOneUse(op1006)))
        return false;
    // Select
    auto op1011 = (op1003);
    auto op1012 = (op1009);
    auto op1013 = (op1010);
    auto op1014 = (op1005);
    auto& inst1015 =
        ctx.newInst(FNMSUB_S).setOperand<0>(op1011).setOperand<1>(op1012).setOperand<2>(op1013).setOperand<3>(op1014);
    ctx.replaceOperand(ctx.getInstDef(inst1002), ctx.getInstDef(inst1015));
    ctx.removeInst(inst1002);
    return true;
}

static bool matchAndSelectPattern1030(MIRInst& inst1030, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1031;
    MIROperand op1032;
    MIROperand op1033;
    if(!matchInstFAdd(inst1030, op1031, op1032, op1033))
        return false;
    // Select
    auto op1034 = (op1031);
    auto op1035 = (op1032);
    auto op1036 = (op1033);
    auto& inst1037 =
        ctx.newInst(getFloatingPointBinaryOpcode(rootOpcode)).setOperand<0>(op1034).setOperand<1>(op1035).setOperand<2>(op1036);
    ctx.replaceOperand(ctx.getInstDef(inst1030), ctx.getInstDef(inst1037));
    ctx.removeInst(inst1030);
    return true;
}

static bool matchAndSelectPattern990(MIRInst& inst990, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op991;
    MIROperand op992;
    MIROperand op993;
    if(!matchInstFSub(inst990, op991, op992, op993))
        return false;
    auto instptr992 = ctx.lookupDef(op992);
    if(!instptr992)
        return false;
    auto& inst992 = *instptr992;
    MIROperand op994;
    MIROperand op995;
    MIROperand op996;
    if(!matchInstFMul(inst992, op994, op995, op996))
        return false;
    if(!(isAggressiveOptEnabled() && ctx.hasOneUse(op994)))
        return false;
    // Select
    auto op997 = (op991);
    auto op998 = (op995);
    auto op999 = (op996);
    auto op1000 = (op993);
    auto& inst1001 = ctx.newInst(FMSUB_S).setOperand<0>(op997).setOperand<1>(op998).setOperand<2>(op999).setOperand<3>(op1000);
    ctx.replaceOperand(ctx.getInstDef(inst990), ctx.getInstDef(inst1001));
    ctx.removeInst(inst990);
    return true;
}

static bool matchAndSelectPattern1016(MIRInst& inst1016, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1017;
    MIROperand op1018;
    MIROperand op1019;
    if(!matchInstFSub(inst1016, op1017, op1018, op1019))
        return false;
    auto instptr1018 = ctx.lookupDef(op1018);
    if(!instptr1018)
        return false;
    auto& inst1018 = *instptr1018;
    MIROperand op1020;
    MIROperand op1021;
    if(!matchInstFNeg(inst1018, op1020, op1021))
        return false;
    auto instptr1021 = ctx.lookupDef(op1021);
    if(!instptr1021)
        return false;
    auto& inst1021 = *instptr1021;
    MIROperand op1022;
    MIROperand op1023;
    MIROperand op1024;
    if(!matchInstFMul(inst1021, op1022, op1023, op1024))
        return false;
    if(!(isAggressiveOptEnabled() && ctx.hasOneUse(op1022) && ctx.hasOneUse(op1020)))
        return false;
    // Select
    auto op1025 = (op1017);
    auto op1026 = (op1023);
    auto op1027 = (op1024);
    auto op1028 = (op1019);
    auto& inst1029 =
        ctx.newInst(FNMADD_S).setOperand<0>(op1025).setOperand<1>(op1026).setOperand<2>(op1027).setOperand<3>(op1028);
    ctx.replaceOperand(ctx.getInstDef(inst1016), ctx.getInstDef(inst1029));
    ctx.removeInst(inst1016);
    return true;
}

static bool matchAndSelectPattern1038(MIRInst& inst1038, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1039;
    MIROperand op1040;
    MIROperand op1041;
    if(!matchInstFSub(inst1038, op1039, op1040, op1041))
        return false;
    // Select
    auto op1042 = (op1039);
    auto op1043 = (op1040);
    auto op1044 = (op1041);
    auto& inst1045 =
        ctx.newInst(getFloatingPointBinaryOpcode(rootOpcode)).setOperand<0>(op1042).setOperand<1>(op1043).setOperand<2>(op1044);
    ctx.replaceOperand(ctx.getInstDef(inst1038), ctx.getInstDef(inst1045));
    ctx.removeInst(inst1038);
    return true;
}

static bool matchAndSelectPattern1046(MIRInst& inst1046, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1047;
    MIROperand op1048;
    MIROperand op1049;
    if(!matchInstFMul(inst1046, op1047, op1048, op1049))
        return false;
    // Select
    auto op1050 = (op1047);
    auto op1051 = (op1048);
    auto op1052 = (op1049);
    auto& inst1053 =
        ctx.newInst(getFloatingPointBinaryOpcode(rootOpcode)).setOperand<0>(op1050).setOperand<1>(op1051).setOperand<2>(op1052);
    ctx.replaceOperand(ctx.getInstDef(inst1046), ctx.getInstDef(inst1053));
    ctx.removeInst(inst1046);
    return true;
}

static bool matchAndSelectPattern1054(MIRInst& inst1054, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1055;
    MIROperand op1056;
    MIROperand op1057;
    if(!matchInstFDiv(inst1054, op1055, op1056, op1057))
        return false;
    // Select
    auto op1058 = (op1055);
    auto op1059 = (op1056);
    auto op1060 = (op1057);
    auto& inst1061 =
        ctx.newInst(getFloatingPointBinaryOpcode(rootOpcode)).setOperand<0>(op1058).setOperand<1>(op1059).setOperand<2>(op1060);
    ctx.replaceOperand(ctx.getInstDef(inst1054), ctx.getInstDef(inst1061));
    ctx.removeInst(inst1054);
    return true;
}

static bool matchAndSelectPattern1062(MIRInst& inst1062, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFNeg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1063;
    MIROperand op1064;
    if(!matchInstFNeg(inst1062, op1063, op1064))
        return false;
    // Select
    auto op1065 = (op1063);
    auto op1066 = (op1064);
    auto& inst1067 = ctx.newInst(FNEG_S).setOperand<0>(op1065).setOperand<1>(op1066);
    ctx.replaceOperand(ctx.getInstDef(inst1062), ctx.getInstDef(inst1067));
    ctx.removeInst(inst1062);
    return true;
}

static bool matchAndSelectPattern1068(MIRInst& inst1068, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFCmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1069;
    MIROperand op1070;
    MIROperand op1071;
    MIROperand op1072;
    if(!matchInstFCmp(inst1068, op1069, op1070, op1071, op1072))
        return false;
    MIROperand op1073;
    MIROperand op1074;
    MIROperand op1075;
    if(!(selectFCmpOpcode(op1072, op1070, op1071, op1073, op1074, op1075)))
        return false;
    // Select
    auto op1076 = (op1069);
    auto op1077 = (op1073);
    auto op1078 = (op1074);
    auto& inst1079 =
        ctx.newInst(static_cast<uint32_t>((op1075).imm())).setOperand<0>(op1076).setOperand<1>(op1077).setOperand<2>(op1078);
    ctx.replaceOperand(ctx.getInstDef(inst1068), ctx.getInstDef(inst1079));
    ctx.removeInst(inst1068);
    return true;
}

static bool matchAndSelectPattern1080(MIRInst& inst1080, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFCmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1081;
    MIROperand op1082;
    MIROperand op1083;
    MIROperand op1084;
    if(!matchInstFCmp(inst1080, op1081, op1082, op1083, op1084))
        return false;
    if(!(isFCmpUnorderedOp(op1084)))
        return false;
    // Select
    auto op1085 = (op1081);
    auto op1086 = (getVRegAs(ctx, op1081));
    auto op1087 = (op1082);
    auto op1088 = (op1083);
    auto op1089 = (getFCmpOrderedOp(op1084));
    auto& inst1090 =
        ctx.newInst(InstFCmp).setOperand<0>(op1086).setOperand<1>(op1087).setOperand<2>(op1088).setOperand<3>(op1089);
    auto& op1090 = ctx.getInstDef(inst1090);
    auto op1091 = (getOne(op1081));
    auto& inst1092 = ctx.newInst(XORI).setOperand<0>(op1085).setOperand<1>(op1090).setOperand<2>(op1091);
    ctx.replaceOperand(ctx.getInstDef(inst1080), ctx.getInstDef(inst1092));
    ctx.removeInst(inst1080);
    return true;
}

static bool matchAndSelectPattern1093(MIRInst& inst1093, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAbs;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1094;
    MIROperand op1095;
    if(!matchInstAbs(inst1093, op1094, op1095))
        return false;
    if(!(isOperandIReg(op1095) && isOperandI32(op1094)))
        return false;
    // Select
    auto op1096 = (op1094);
    auto op1097 = (getVRegAs(ctx, op1094));
    auto op1098 = (getZero(op1094));
    auto op1099 = (op1095);
    auto& inst1100 = ctx.newInst(SUBW).setOperand<0>(op1097).setOperand<1>(op1098).setOperand<2>(op1099);
    auto& op1100 = ctx.getInstDef(inst1100);
    auto op1101 = (op1095);
    auto& inst1102 = ctx.newInst(MAX).setOperand<0>(op1096).setOperand<1>(op1100).setOperand<2>(op1101);
    ctx.replaceOperand(ctx.getInstDef(inst1093), ctx.getInstDef(inst1102));
    ctx.removeInst(inst1093);
    return true;
}

static bool matchAndSelectPattern1103(MIRInst& inst1103, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SUBW;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1104;
    MIROperand op1105;
    MIROperand op1106;
    if(!matchSUBW(inst1103, op1104, op1105, op1106))
        return false;
    auto instptr1106 = ctx.lookupDef(op1106);
    if(!instptr1106)
        return false;
    auto& inst1106 = *instptr1106;
    MIROperand op1107;
    MIROperand op1108;
    MIROperand op1109;
    if(!matchSUBW(inst1106, op1107, op1108, op1109))
        return false;
    if(!(ctx.hasOneUse(op1107)))
        return false;
    // Select
    auto op1110 = (op1104);
    auto op1111 = (getVRegAs(ctx, op1104));
    auto op1112 = (op1105);
    auto op1113 = (op1109);
    auto& inst1114 = ctx.newInst(ADDW).setOperand<0>(op1111).setOperand<1>(op1112).setOperand<2>(op1113);
    auto& op1114 = ctx.getInstDef(inst1114);
    auto op1115 = (op1108);
    auto& inst1116 = ctx.newInst(SUBW).setOperand<0>(op1110).setOperand<1>(op1114).setOperand<2>(op1115);
    ctx.replaceOperand(ctx.getInstDef(inst1103), ctx.getInstDef(inst1116));
    ctx.removeInst(inst1103);
    return true;
}

static bool matchAndSelectPattern1117(MIRInst& inst1117, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SUBW;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1118;
    MIROperand op1119;
    MIROperand op1120;
    if(!matchSUBW(inst1117, op1118, op1119, op1120))
        return false;
    auto instptr1120 = ctx.lookupDef(op1120);
    if(!instptr1120)
        return false;
    auto& inst1120 = *instptr1120;
    MIROperand op1121;
    MIROperand op1122;
    MIROperand op1123;
    if(!matchSUBW(inst1120, op1121, op1122, op1123))
        return false;
    if(!(isZero(op1119)))
        return false;
    // Select
    auto op1124 = (op1118);
    auto op1125 = (op1123);
    auto op1126 = (op1122);
    auto& inst1127 = ctx.newInst(SUBW).setOperand<0>(op1124).setOperand<1>(op1125).setOperand<2>(op1126);
    ctx.replaceOperand(ctx.getInstDef(inst1117), ctx.getInstDef(inst1127));
    ctx.removeInst(inst1117);
    return true;
}

static bool matchAndSelectPattern1146(MIRInst& inst1146, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstTrunc;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1147;
    MIROperand op1148;
    if(!matchInstTrunc(inst1146, op1147, op1148))
        return false;
    if(!(isOperandIReg(op1148) && ((op1147).type() == OperandType::Int32 && (op1148).type() == OperandType::Int32)))
        return false;
    // Select
    auto op1149 = (op1147);
    auto op1150 = (op1148);
    auto& inst1151 = ctx.newInst(InstCopy).setOperand<0>(op1149).setOperand<1>(op1150);
    ctx.replaceOperand(ctx.getInstDef(inst1146), ctx.getInstDef(inst1151));
    ctx.removeInst(inst1146);
    return true;
}

static bool matchAndSelectPattern1152(MIRInst& inst1152, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstTrunc;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1153;
    MIROperand op1154;
    if(!matchInstTrunc(inst1152, op1153, op1154))
        return false;
    if(!(isOperandIReg(op1154)))
        return false;
    // Select
    auto op1155 = (op1153);
    auto op1156 = (op1154);
    auto& inst1157 = ctx.newInst(selectSExtOpcode((op1153).type())).setOperand<0>(op1155).setOperand<1>(op1156);
    ctx.replaceOperand(ctx.getInstDef(inst1152), ctx.getInstDef(inst1157));
    ctx.removeInst(inst1152);
    return true;
}

static bool matchAndSelectPattern1158(MIRInst& inst1158, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = Select_GPR_GPR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1159;
    MIROperand op1160;
    MIROperand op1161;
    MIROperand op1162;
    MIROperand op1163;
    MIROperand op1164;
    if(!matchSelect_GPR_GPR(inst1158, op1159, op1160, op1161, op1162, op1163, op1164))
        return false;
    MIROperand op1165;
    MIROperand op1166;
    MIROperand op1167;
    if(!(isOperandIReg(op1159) && isOperandIReg(op1160) && isOperandIReg(op1161) &&
         selectSFBArith(ctx, op1160, op1161, op1165, op1166, op1167)))
        return false;
    // Select
    auto op1168 = (op1159);
    auto op1169 = (op1165);
    auto op1170 = (op1166);
    auto op1171 = (op1162);
    auto op1172 = (op1163);
    auto op1173 = (op1164);
    auto op1174 = (op1167);
    auto& inst1175 = ctx.newInst(Select_GPR_Arith)
                         .setOperand<0>(op1168)
                         .setOperand<1>(op1169)
                         .setOperand<2>(op1170)
                         .setOperand<3>(op1171)
                         .setOperand<4>(op1172)
                         .setOperand<5>(op1173)
                         .setOperand<6>(op1174);
    ctx.replaceOperand(ctx.getInstDef(inst1158), ctx.getInstDef(inst1175));
    ctx.removeInst(inst1158);
    return true;
}

static bool matchAndSelectPattern1206(MIRInst& inst1206, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = Select_GPR_GPR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1207;
    MIROperand op1208;
    MIROperand op1209;
    MIROperand op1210;
    MIROperand op1211;
    MIROperand op1212;
    if(!matchSelect_GPR_GPR(inst1206, op1207, op1208, op1209, op1210, op1211, op1212))
        return false;
    auto instptr1210 = ctx.lookupDef(op1210);
    if(!instptr1210)
        return false;
    auto& inst1210 = *instptr1210;
    MIROperand op1213;
    MIROperand op1214;
    MIROperand op1215;
    if(!matchXORI(inst1210, op1213, op1214, op1215))
        return false;
    if(!(ctx.hasOneUse(op1213) && isOperandIReg(op1214) && isOne(op1215) && isZero(op1211) &&
         isCompareOp(op1212, CompareOp::ICmpNotEqual)))
        return false;
    // Select
    auto op1216 = (op1207);
    auto op1217 = (op1209);
    auto op1218 = (op1208);
    auto op1219 = (op1214);
    auto op1220 = (op1211);
    auto op1221 = (op1212);
    auto& inst1222 = ctx.newInst(Select_GPR_GPR)
                         .setOperand<0>(op1216)
                         .setOperand<1>(op1217)
                         .setOperand<2>(op1218)
                         .setOperand<3>(op1219)
                         .setOperand<4>(op1220)
                         .setOperand<5>(op1221);
    ctx.replaceOperand(ctx.getInstDef(inst1206), ctx.getInstDef(inst1222));
    ctx.removeInst(inst1206);
    return true;
}

static bool matchAndSelectPattern1176(MIRInst& inst1176, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSelect;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1177;
    MIROperand op1178;
    MIROperand op1179;
    MIROperand op1180;
    if(!matchInstSelect(inst1176, op1177, op1178, op1179, op1180))
        return false;
    MIROperand op1181;
    MIROperand op1182;
    MIROperand op1183;
    if(!(isOperandIReg(op1177) && isOperandIRegOrImm(op1179) && isOperandIRegOrImm(op1180) &&
         selectCompare(ctx, op1178, op1181, op1182, op1183)))
        return false;
    // Select
    auto op1184 = (op1177);
    auto op1185 = (op1179);
    auto op1186 = (op1180);
    auto op1187 = (op1181);
    auto op1188 = (op1182);
    auto op1189 = (op1183);
    auto& inst1190 = ctx.newInst(Select_GPR_GPR)
                         .setOperand<0>(op1184)
                         .setOperand<1>(op1185)
                         .setOperand<2>(op1186)
                         .setOperand<3>(op1187)
                         .setOperand<4>(op1188)
                         .setOperand<5>(op1189);
    ctx.replaceOperand(ctx.getInstDef(inst1176), ctx.getInstDef(inst1190));
    ctx.removeInst(inst1176);
    return true;
}

static bool matchAndSelectPattern1191(MIRInst& inst1191, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSelect;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1192;
    MIROperand op1193;
    MIROperand op1194;
    MIROperand op1195;
    if(!matchInstSelect(inst1191, op1192, op1193, op1194, op1195))
        return false;
    MIROperand op1196;
    MIROperand op1197;
    MIROperand op1198;
    if(!(isOperandFPR(op1192) && isOperandFPR(op1194) && isOperandFPR(op1195) &&
         selectCompare(ctx, op1193, op1196, op1197, op1198)))
        return false;
    // Select
    auto op1199 = (op1192);
    auto op1200 = (op1194);
    auto op1201 = (op1195);
    auto op1202 = (op1196);
    auto op1203 = (op1197);
    auto op1204 = (op1198);
    auto& inst1205 = ctx.newInst(Select_FPR_GPR)
                         .setOperand<0>(op1199)
                         .setOperand<1>(op1200)
                         .setOperand<2>(op1201)
                         .setOperand<3>(op1202)
                         .setOperand<4>(op1203)
                         .setOperand<5>(op1204);
    ctx.replaceOperand(ctx.getInstDef(inst1191), ctx.getInstDef(inst1205));
    ctx.removeInst(inst1191);
    return true;
}

static bool matchAndSelectPattern1223(MIRInst& inst1223, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = Select_FPR_GPR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1224;
    MIROperand op1225;
    MIROperand op1226;
    MIROperand op1227;
    MIROperand op1228;
    MIROperand op1229;
    if(!matchSelect_FPR_GPR(inst1223, op1224, op1225, op1226, op1227, op1228, op1229))
        return false;
    auto instptr1227 = ctx.lookupDef(op1227);
    if(!instptr1227)
        return false;
    auto& inst1227 = *instptr1227;
    MIROperand op1230;
    MIROperand op1231;
    MIROperand op1232;
    if(!matchXORI(inst1227, op1230, op1231, op1232))
        return false;
    if(!(ctx.hasOneUse(op1230) && isOperandIReg(op1231) && isOne(op1232) && isZero(op1228) &&
         isCompareOp(op1229, CompareOp::ICmpNotEqual)))
        return false;
    // Select
    auto op1233 = (op1224);
    auto op1234 = (op1226);
    auto op1235 = (op1225);
    auto op1236 = (op1231);
    auto op1237 = (op1228);
    auto op1238 = (op1229);
    auto& inst1239 = ctx.newInst(Select_FPR_GPR)
                         .setOperand<0>(op1233)
                         .setOperand<1>(op1234)
                         .setOperand<2>(op1235)
                         .setOperand<3>(op1236)
                         .setOperand<4>(op1237)
                         .setOperand<5>(op1238);
    ctx.replaceOperand(ctx.getInstDef(inst1223), ctx.getInstDef(inst1239));
    ctx.removeInst(inst1223);
    return true;
}

static bool matchAndSelectPattern1240(MIRInst& inst1240, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFAbs;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1241;
    MIROperand op1242;
    if(!matchInstFAbs(inst1240, op1241, op1242))
        return false;
    // Select
    auto op1243 = (op1241);
    auto op1244 = (op1242);
    auto& inst1245 = ctx.newInst(FABS_S).setOperand<0>(op1243).setOperand<1>(op1244);
    ctx.replaceOperand(ctx.getInstDef(inst1240), ctx.getInstDef(inst1245));
    ctx.removeInst(inst1240);
    return true;
}

static bool matchAndSelectPattern1264(MIRInst& inst1264, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = ORI;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1265;
    MIROperand op1266;
    MIROperand op1267;
    if(!matchORI(inst1264, op1265, op1266, op1267))
        return false;
    auto instptr1266 = ctx.lookupDef(op1266);
    if(!instptr1266)
        return false;
    auto& inst1266 = *instptr1266;
    MIROperand op1268;
    MIROperand op1269;
    if(!matchLoadImm64(inst1266, op1268, op1269))
        return false;
    if(!(ctx.hasOneUse(op1268)))
        return false;
    // Select
    auto op1270 = (op1265);
    auto op1271 = (MIROperand::asImm((op1269).imm() | (op1267).imm(), OperandType::Int64));
    auto& inst1272 = ctx.newInst(LoadImm64).setOperand<0>(op1270).setOperand<1>(op1271);
    ctx.replaceOperand(ctx.getInstDef(inst1264), ctx.getInstDef(inst1272));
    ctx.removeInst(inst1264);
    return true;
}

static bool matchAndSelectPattern1273(MIRInst& inst1273, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = ADD_UW;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1274;
    MIROperand op1275;
    MIROperand op1276;
    if(!matchADD_UW(inst1273, op1274, op1275, op1276))
        return false;
    auto instptr1275 = ctx.lookupDef(op1275);
    if(!instptr1275)
        return false;
    auto& inst1275 = *instptr1275;
    auto instptr1276 = ctx.lookupDef(op1276);
    if(!instptr1276)
        return false;
    auto& inst1276 = *instptr1276;
    MIROperand op1277;
    MIROperand op1278;
    if(!matchLoadImm12(inst1275, op1277, op1278))
        return false;
    if(!((op1278).imm() > 0))
        return false;
    MIROperand op1279;
    MIROperand op1280;
    MIROperand op1281;
    if(!matchSLLI(inst1276, op1279, op1280, op1281))
        return false;
    if(!((op1281).imm() == 32))
        return false;
    // Select
    auto op1282 = (op1274);
    auto op1283 = (op1279);
    auto op1284 = (op1278);
    auto& inst1285 = ctx.newInst(ORI).setOperand<0>(op1282).setOperand<1>(op1283).setOperand<2>(op1284);
    ctx.replaceOperand(ctx.getInstDef(inst1273), ctx.getInstDef(inst1285));
    ctx.removeInst(inst1273);
    return true;
}

static bool matchAndSelectImpl(MIRInst& inst, ISelContext& ctx) {
    switch(inst.opcode()) {
        case InstLoadGlobalAddress: {
            if(matchAndSelectPattern1(inst, ctx))
                return true;
            break;
        }
        case InstLoadImmToReg: {
            if(matchAndSelectPattern10(inst, ctx))
                return true;
            if(matchAndSelectPattern22(inst, ctx))
                return true;
            if(matchAndSelectPattern34(inst, ctx))
                return true;
            if(matchAndSelectPattern48(inst, ctx))
                return true;
            if(matchAndSelectPattern60(inst, ctx))
                return true;
            break;
        }
        case InstLoadImm: {
            if(matchAndSelectPattern16(inst, ctx))
                return true;
            if(matchAndSelectPattern28(inst, ctx))
                return true;
            if(matchAndSelectPattern41(inst, ctx))
                return true;
            if(matchAndSelectPattern54(inst, ctx))
                return true;
            if(matchAndSelectPattern66(inst, ctx))
                return true;
            break;
        }
        case InstAdd: {
            if(matchAndSelectPattern72(inst, ctx))
                return true;
            if(matchAndSelectPattern83(inst, ctx))
                return true;
            if(matchAndSelectPattern94(inst, ctx))
                return true;
            if(matchAndSelectPattern105(inst, ctx))
                return true;
            if(matchAndSelectPattern116(inst, ctx))
                return true;
            if(matchAndSelectPattern127(inst, ctx))
                return true;
            if(matchAndSelectPattern138(inst, ctx))
                return true;
            if(matchAndSelectPattern146(inst, ctx))
                return true;
            if(matchAndSelectPattern154(inst, ctx))
                return true;
            if(matchAndSelectPattern162(inst, ctx))
                return true;
            break;
        }
        case InstAnd: {
            if(matchAndSelectPattern170(inst, ctx))
                return true;
            if(matchAndSelectPattern214(inst, ctx))
                return true;
            if(matchAndSelectPattern238(inst, ctx))
                return true;
            break;
        }
        case InstOr: {
            if(matchAndSelectPattern181(inst, ctx))
                return true;
            if(matchAndSelectPattern222(inst, ctx))
                return true;
            if(matchAndSelectPattern246(inst, ctx))
                return true;
            break;
        }
        case InstXor: {
            if(matchAndSelectPattern192(inst, ctx))
                return true;
            if(matchAndSelectPattern203(inst, ctx))
                return true;
            if(matchAndSelectPattern230(inst, ctx))
                return true;
            if(matchAndSelectPattern254(inst, ctx))
                return true;
            break;
        }
        case InstSub: {
            if(matchAndSelectPattern262(inst, ctx))
                return true;
            if(matchAndSelectPattern275(inst, ctx))
                return true;
            if(matchAndSelectPattern283(inst, ctx))
                return true;
            break;
        }
        case InstShl: {
            if(matchAndSelectPattern291(inst, ctx))
                return true;
            if(matchAndSelectPattern299(inst, ctx))
                return true;
            if(matchAndSelectPattern339(inst, ctx))
                return true;
            if(matchAndSelectPattern347(inst, ctx))
                return true;
            break;
        }
        case InstAShr: {
            if(matchAndSelectPattern307(inst, ctx))
                return true;
            if(matchAndSelectPattern315(inst, ctx))
                return true;
            if(matchAndSelectPattern355(inst, ctx))
                return true;
            if(matchAndSelectPattern363(inst, ctx))
                return true;
            break;
        }
        case InstLShr: {
            if(matchAndSelectPattern323(inst, ctx))
                return true;
            if(matchAndSelectPattern331(inst, ctx))
                return true;
            if(matchAndSelectPattern371(inst, ctx))
                return true;
            if(matchAndSelectPattern379(inst, ctx))
                return true;
            break;
        }
        case InstSMin: {
            if(matchAndSelectPattern387(inst, ctx))
                return true;
            break;
        }
        case InstSMax: {
            if(matchAndSelectPattern395(inst, ctx))
                return true;
            break;
        }
        case InstMul: {
            if(matchAndSelectPattern403(inst, ctx))
                return true;
            if(matchAndSelectPattern411(inst, ctx))
                return true;
            break;
        }
        case InstSDiv: {
            if(matchAndSelectPattern419(inst, ctx))
                return true;
            if(matchAndSelectPattern440(inst, ctx))
                return true;
            if(matchAndSelectPattern464(inst, ctx))
                return true;
            if(matchAndSelectPattern483(inst, ctx))
                return true;
            if(matchAndSelectPattern521(inst, ctx))
                return true;
            if(matchAndSelectPattern535(inst, ctx))
                return true;
            break;
        }
        case SRLIW: {
            if(matchAndSelectPattern499(inst, ctx))
                return true;
            break;
        }
        case SRAIW: {
            if(matchAndSelectPattern510(inst, ctx))
                return true;
            break;
        }
        case InstSRem: {
            if(matchAndSelectPattern546(inst, ctx))
                return true;
            if(matchAndSelectPattern569(inst, ctx))
                return true;
            if(matchAndSelectPattern585(inst, ctx))
                return true;
            if(matchAndSelectPattern599(inst, ctx))
                return true;
            break;
        }
        case InstUDiv: {
            if(matchAndSelectPattern610(inst, ctx))
                return true;
            if(matchAndSelectPattern626(inst, ctx))
                return true;
            break;
        }
        case InstURem: {
            if(matchAndSelectPattern618(inst, ctx))
                return true;
            if(matchAndSelectPattern634(inst, ctx))
                return true;
            break;
        }
        case SLLI: {
            if(matchAndSelectPattern642(inst, ctx))
                return true;
            if(matchAndSelectPattern1246(inst, ctx))
                return true;
            if(matchAndSelectPattern1255(inst, ctx))
                return true;
            break;
        }
        case SLLIW: {
            if(matchAndSelectPattern654(inst, ctx))
                return true;
            break;
        }
        case InstICmp: {
            if(matchAndSelectPattern666(inst, ctx))
                return true;
            if(matchAndSelectPattern675(inst, ctx))
                return true;
            if(matchAndSelectPattern684(inst, ctx))
                return true;
            if(matchAndSelectPattern693(inst, ctx))
                return true;
            if(matchAndSelectPattern702(inst, ctx))
                return true;
            if(matchAndSelectPattern711(inst, ctx))
                return true;
            if(matchAndSelectPattern720(inst, ctx))
                return true;
            if(matchAndSelectPattern729(inst, ctx))
                return true;
            if(matchAndSelectPattern738(inst, ctx))
                return true;
            if(matchAndSelectPattern750(inst, ctx))
                return true;
            break;
        }
        case InstZExt: {
            if(matchAndSelectPattern762(inst, ctx))
                return true;
            if(matchAndSelectPattern768(inst, ctx))
                return true;
            if(matchAndSelectPattern775(inst, ctx))
                return true;
            if(matchAndSelectPattern781(inst, ctx))
                return true;
            if(matchAndSelectPattern929(inst, ctx))
                return true;
            if(matchAndSelectPattern1128(inst, ctx))
                return true;
            if(matchAndSelectPattern1137(inst, ctx))
                return true;
            break;
        }
        case InstSExt: {
            if(matchAndSelectPattern787(inst, ctx))
                return true;
            break;
        }
        case InstUnreachable: {
            if(matchAndSelectPattern793(inst, ctx))
                return true;
            break;
        }
        case InstJump: {
            if(matchAndSelectPattern795(inst, ctx))
                return true;
            break;
        }
        case InstBranch: {
            if(matchAndSelectPattern799(inst, ctx))
                return true;
            if(matchAndSelectPattern812(inst, ctx))
                return true;
            if(matchAndSelectPattern825(inst, ctx))
                return true;
            if(matchAndSelectPattern838(inst, ctx))
                return true;
            if(matchAndSelectPattern851(inst, ctx))
                return true;
            if(matchAndSelectPattern864(inst, ctx))
                return true;
            if(matchAndSelectPattern879(inst, ctx))
                return true;
            if(matchAndSelectPattern892(inst, ctx))
                return true;
            if(matchAndSelectPattern909(inst, ctx))
                return true;
            break;
        }
        case InstLoad: {
            if(matchAndSelectPattern918(inst, ctx))
                return true;
            break;
        }
        case InstStore: {
            if(matchAndSelectPattern942(inst, ctx))
                return true;
            if(matchAndSelectPattern955(inst, ctx))
                return true;
            break;
        }
        case InstF2S: {
            if(matchAndSelectPattern966(inst, ctx))
                return true;
            break;
        }
        case InstS2F: {
            if(matchAndSelectPattern972(inst, ctx))
                return true;
            break;
        }
        case InstFAdd: {
            if(matchAndSelectPattern978(inst, ctx))
                return true;
            if(matchAndSelectPattern1002(inst, ctx))
                return true;
            if(matchAndSelectPattern1030(inst, ctx))
                return true;
            break;
        }
        case InstFSub: {
            if(matchAndSelectPattern990(inst, ctx))
                return true;
            if(matchAndSelectPattern1016(inst, ctx))
                return true;
            if(matchAndSelectPattern1038(inst, ctx))
                return true;
            break;
        }
        case InstFMul: {
            if(matchAndSelectPattern1046(inst, ctx))
                return true;
            break;
        }
        case InstFDiv: {
            if(matchAndSelectPattern1054(inst, ctx))
                return true;
            break;
        }
        case InstFNeg: {
            if(matchAndSelectPattern1062(inst, ctx))
                return true;
            break;
        }
        case InstFCmp: {
            if(matchAndSelectPattern1068(inst, ctx))
                return true;
            if(matchAndSelectPattern1080(inst, ctx))
                return true;
            break;
        }
        case InstAbs: {
            if(matchAndSelectPattern1093(inst, ctx))
                return true;
            break;
        }
        case SUBW: {
            if(matchAndSelectPattern1103(inst, ctx))
                return true;
            if(matchAndSelectPattern1117(inst, ctx))
                return true;
            break;
        }
        case InstTrunc: {
            if(matchAndSelectPattern1146(inst, ctx))
                return true;
            if(matchAndSelectPattern1152(inst, ctx))
                return true;
            break;
        }
        case Select_GPR_GPR: {
            if(matchAndSelectPattern1158(inst, ctx))
                return true;
            if(matchAndSelectPattern1206(inst, ctx))
                return true;
            break;
        }
        case InstSelect: {
            if(matchAndSelectPattern1176(inst, ctx))
                return true;
            if(matchAndSelectPattern1191(inst, ctx))
                return true;
            break;
        }
        case Select_FPR_GPR: {
            if(matchAndSelectPattern1223(inst, ctx))
                return true;
            break;
        }
        case InstFAbs: {
            if(matchAndSelectPattern1240(inst, ctx))
                return true;
            break;
        }
        case ORI: {
            if(matchAndSelectPattern1264(inst, ctx))
                return true;
            break;
        }
        case ADD_UW: {
            if(matchAndSelectPattern1273(inst, ctx))
                return true;
            break;
        }
        default:
            break;
    }
    return false;
}

class RISCVISelInfo final : public TargetISelInfo {
public:
    [[nodiscard]] bool isLegalGenericInst(uint32_t opcode) const override;
    bool matchAndSelect(MIRInst& inst, ISelContext& ctx, bool allowComplexPattern) const override;
    void postLegalizeInst(const InstLegalizeContext& ctx) const override;
    void postLegalizeInstSeq(const CodeGenContext& ctx, MIRInstList& instructions) const override;
    void preRALegalizeInst(const InstLegalizeContext& ctx) const override;
    void legalizeInstWithStackOperand(const InstLegalizeContext& ctx, MIROperand& op, const StackObject& obj) const override;
    MIROperand materializeFPConstant(ConstantFloatingPoint* fp, LoweringContext& loweringCtx) const override;
    bool lowerInst(Instruction* inst, LoweringContext& loweringCtx) const override;
    void lowerIndirectJump(MIRJumpTable* jumpTable, const MIROperand& offset, LoweringContext& ctx) const override;
};

const TargetISelInfo& getRISCVISelInfo() {
    static RISCVISelInfo iselInfo;
    return iselInfo;
}

CMMC_TARGET_NAMESPACE_END