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

#include "../ARM/ISelInfoDecl.hpp"

CMMC_TARGET_NAMESPACE_BEGIN

static bool matchInstAdd(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstAdd)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchInstLoadImm(MIRInst& inst, MIROperand& Dst, MIROperand& Imm) {
    if(inst.opcode() != InstLoadImm)
        return false;
    Dst = inst.getOperand(0);
    Imm = inst.getOperand(1);
    return true;
}

static bool matchInstF2S(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstF2S)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchInstFAbs(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstFAbs)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchSelect_GPR(MIRInst& inst, MIROperand& Rd, MIROperand& Rn, MIROperand& Rm, MIROperand& CC, MIROperand& CF) {
    if(inst.opcode() != Select_GPR)
        return false;
    Rd = inst.getOperand(0);
    Rn = inst.getOperand(1);
    Rm = inst.getOperand(2);
    CC = inst.getOperand(3);
    CF = inst.getOperand(4);
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

static bool matchVMOV_GPR2FPR(MIRInst& inst, MIROperand& Sn, MIROperand& Rd) {
    if(inst.opcode() != VMOV_GPR2FPR)
        return false;
    Sn = inst.getOperand(0);
    Rd = inst.getOperand(1);
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

static bool matchInstFMul(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstFMul)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
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

static bool matchInstAbs(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstAbs)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
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

static bool matchVMOV_FPR2GPR(MIRInst& inst, MIROperand& Rd, MIROperand& Sn) {
    if(inst.opcode() != VMOV_FPR2GPR)
        return false;
    Rd = inst.getOperand(0);
    Sn = inst.getOperand(1);
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

static bool matchORR(MIRInst& inst, MIROperand& Rd, MIROperand& Rn, MIROperand& Op2) {
    if(inst.opcode() != ORR)
        return false;
    Rd = inst.getOperand(0);
    Rn = inst.getOperand(1);
    Op2 = inst.getOperand(2);
    return true;
}

static bool matchInstZExt(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstZExt)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
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

static bool matchInstSMin(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstSMin)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
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

static bool matchInstOr(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstOr)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
    return true;
}

static bool matchEOR(MIRInst& inst, MIROperand& Rd, MIROperand& Rn, MIROperand& Op2) {
    if(inst.opcode() != EOR)
        return false;
    Rd = inst.getOperand(0);
    Rn = inst.getOperand(1);
    Op2 = inst.getOperand(2);
    return true;
}

static bool matchSUB(MIRInst& inst, MIROperand& Rd, MIROperand& Rn, MIROperand& Op2) {
    if(inst.opcode() != SUB)
        return false;
    Rd = inst.getOperand(0);
    Rn = inst.getOperand(1);
    Op2 = inst.getOperand(2);
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

static bool matchInstSExt(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstSExt)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchInstJump(MIRInst& inst, MIROperand& Tgt) {
    if(inst.opcode() != InstJump)
        return false;
    Tgt = inst.getOperand(0);
    return true;
}

static bool matchInstS2F(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstS2F)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
    return true;
}

static bool matchInstLoadGlobalAddress(MIRInst& inst, MIROperand& Dst, MIROperand& Addr) {
    if(inst.opcode() != InstLoadGlobalAddress)
        return false;
    Dst = inst.getOperand(0);
    Addr = inst.getOperand(1);
    return true;
}

static bool matchRSB_Fused(MIRInst& inst, MIROperand& Rd, MIROperand& Rn, MIROperand& Rm, MIROperand& Op, MIROperand& Sh) {
    if(inst.opcode() != RSB_Fused)
        return false;
    Rd = inst.getOperand(0);
    Rn = inst.getOperand(1);
    Rm = inst.getOperand(2);
    Op = inst.getOperand(3);
    Sh = inst.getOperand(4);
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

static bool matchInstFNeg(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstFNeg)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
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

static bool matchInstURem(MIRInst& inst, MIROperand& Dst, MIROperand& Lhs, MIROperand& Rhs) {
    if(inst.opcode() != InstURem)
        return false;
    Dst = inst.getOperand(0);
    Lhs = inst.getOperand(1);
    Rhs = inst.getOperand(2);
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

static bool matchADD(MIRInst& inst, MIROperand& Rd, MIROperand& Rn, MIROperand& Op2) {
    if(inst.opcode() != ADD)
        return false;
    Rd = inst.getOperand(0);
    Rn = inst.getOperand(1);
    Op2 = inst.getOperand(2);
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

static bool matchRSB(MIRInst& inst, MIROperand& Rd, MIROperand& Rn, MIROperand& Op2) {
    if(inst.opcode() != RSB)
        return false;
    Rd = inst.getOperand(0);
    Rn = inst.getOperand(1);
    Op2 = inst.getOperand(2);
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

static bool matchNZCVFlag2GPR(MIRInst& inst, MIROperand& Rd, MIROperand& CC, MIROperand& CF) {
    if(inst.opcode() != NZCVFlag2GPR)
        return false;
    Rd = inst.getOperand(0);
    CC = inst.getOperand(1);
    CF = inst.getOperand(2);
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

static bool matchInstLoadImmToReg(MIRInst& inst, MIROperand& Dst, MIROperand& Imm) {
    if(inst.opcode() != InstLoadImmToReg)
        return false;
    Dst = inst.getOperand(0);
    Imm = inst.getOperand(1);
    return true;
}

static bool matchInstUnreachable(MIRInst& inst) {
    if(inst.opcode() != InstUnreachable)
        return false;

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

static bool matchInstTrunc(MIRInst& inst, MIROperand& Dst, MIROperand& Src) {
    if(inst.opcode() != InstTrunc)
        return false;
    Dst = inst.getOperand(0);
    Src = inst.getOperand(1);
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

static bool matchAndSelectPattern1(MIRInst& inst1, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImmToReg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op2;
    MIROperand op3;
    if(!matchInstLoadImmToReg(inst1, op2, op3))
        return false;
    if(!(isOperandOp2Constant(op3)))
        return false;
    // Select
    auto op4 = (op2);
    auto op5 = (op3);
    auto& inst6 = ctx.newInst(MOV_Constant).setOperand<0>(op4).setOperand<1>(op5);
    ctx.replaceOperand(ctx.getInstDef(inst1), ctx.getInstDef(inst6));
    ctx.removeInst(inst1);
    return true;
}

static bool matchAndSelectPattern13(MIRInst& inst13, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImmToReg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op14;
    MIROperand op15;
    if(!matchInstLoadImmToReg(inst13, op14, op15))
        return false;
    MIROperand op16;
    if(!(selectInvertedOp2Constant(op15, op16)))
        return false;
    // Select
    auto op17 = (op14);
    auto op18 = (op16);
    auto& inst19 = ctx.newInst(MVN_Constant).setOperand<0>(op17).setOperand<1>(op18);
    ctx.replaceOperand(ctx.getInstDef(inst13), ctx.getInstDef(inst19));
    ctx.removeInst(inst13);
    return true;
}

static bool matchAndSelectPattern27(MIRInst& inst27, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImmToReg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op28;
    MIROperand op29;
    if(!matchInstLoadImmToReg(inst27, op28, op29))
        return false;
    MIROperand op30;
    if(!(selectGenericImm32(op29, op30)))
        return false;
    // Select
    auto op31 = (op28);
    auto op32 = (op30);
    auto& inst33 = ctx.newInst(MOVT_MOVW_PAIR).setOperand<0>(op31).setOperand<1>(op32);
    ctx.replaceOperand(ctx.getInstDef(inst27), ctx.getInstDef(inst33));
    ctx.removeInst(inst27);
    return true;
}

static bool matchAndSelectPattern7(MIRInst& inst7, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImm;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op8;
    MIROperand op9;
    if(!matchInstLoadImm(inst7, op8, op9))
        return false;
    if(!(isOperandOp2Constant(op9)))
        return false;
    // Select
    auto op10 = (op8);
    auto op11 = (op9);
    auto& inst12 = ctx.newInst(MOV_Constant).setOperand<0>(op10).setOperand<1>(op11);
    ctx.replaceOperand(ctx.getInstDef(inst7), ctx.getInstDef(inst12));
    ctx.removeInst(inst7);
    return true;
}

static bool matchAndSelectPattern20(MIRInst& inst20, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImm;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op21;
    MIROperand op22;
    if(!matchInstLoadImm(inst20, op21, op22))
        return false;
    MIROperand op23;
    if(!(selectInvertedOp2Constant(op22, op23)))
        return false;
    // Select
    auto op24 = (op21);
    auto op25 = (op23);
    auto& inst26 = ctx.newInst(MVN_Constant).setOperand<0>(op24).setOperand<1>(op25);
    ctx.replaceOperand(ctx.getInstDef(inst20), ctx.getInstDef(inst26));
    ctx.removeInst(inst20);
    return true;
}

static bool matchAndSelectPattern34(MIRInst& inst34, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadImm;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op35;
    MIROperand op36;
    if(!matchInstLoadImm(inst34, op35, op36))
        return false;
    MIROperand op37;
    if(!(selectGenericImm32(op36, op37)))
        return false;
    // Select
    auto op38 = (op35);
    auto op39 = (op37);
    auto& inst40 = ctx.newInst(MOVT_MOVW_PAIR).setOperand<0>(op38).setOperand<1>(op39);
    ctx.replaceOperand(ctx.getInstDef(inst34), ctx.getInstDef(inst40));
    ctx.removeInst(inst34);
    return true;
}

static bool matchAndSelectPattern41(MIRInst& inst41, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op42;
    MIROperand op43;
    MIROperand op44;
    if(!matchInstSub(inst41, op42, op43, op44))
        return false;
    auto instptr44 = ctx.lookupDef(op44);
    if(!instptr44)
        return false;
    auto& inst44 = *instptr44;
    MIROperand op45;
    MIROperand op46;
    if(!matchInstAbs(inst44, op45, op46))
        return false;
    if(!(isOperandIReg(op46) && isZero(op43)))
        return false;
    // Select
    auto op47 = (op42);
    auto op48 = (MIROperand::asImm(CondField::PL, OperandType::CondField));
    auto op49 = (op46);
    auto op50 = (getZero(op46));
    auto op51 = (op46);
    auto op52 = (MIROperand::asImm(RSB_Cond, OperandType::Special));
    auto op53 = (op46);
    auto op54 = (getZero(op46));
    auto op55 = (getCC());
    auto& inst56 = ctx.newInst(CMP).setOperand<0>(op53).setOperand<1>(op54).setOperand<2>(op55);
    auto& op56 = ctx.getInstDef(inst56);
    auto& inst57 = ctx.newInst(PseudoIntOpWithOp2_Cond)
                       .setOperand<0>(op48)
                       .setOperand<1>(op47)
                       .setOperand<2>(op49)
                       .setOperand<3>(op50)
                       .setOperand<4>(op51)
                       .setOperand<5>(op52)
                       .setOperand<6>(op56);
    ctx.replaceOperand(ctx.getInstDef(inst41), ctx.getInstDef(inst57));
    ctx.removeInst(inst41);
    return true;
}

static bool matchAndSelectPattern71(MIRInst& inst71, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op72;
    MIROperand op73;
    MIROperand op74;
    if(!matchInstSub(inst71, op72, op73, op74))
        return false;
    auto instptr74 = ctx.lookupDef(op74);
    if(!instptr74)
        return false;
    auto& inst74 = *instptr74;
    MIROperand op75;
    MIROperand op76;
    MIROperand op77;
    if(!matchInstMul(inst74, op75, op76, op77))
        return false;
    if(!(isOperandIReg(op76) && ctx.isSafeToUse(op76, op75) && (!isOperandIReg(op77) || ctx.isSafeToUse(op77, op75))))
        return false;
    MIROperand op78;
    if(!(isOperandIReg(op73) && buildIReg(ctx, op77, op78)))
        return false;
    // Select
    auto op79 = (op72);
    auto op80 = (op73);
    auto op81 = (op76);
    auto op82 = (op78);
    auto& inst83 = ctx.newInst((rootOpcode == InstAdd ? MLA : MLS))
                       .setOperand<0>(op79)
                       .setOperand<1>(op81)
                       .setOperand<2>(op82)
                       .setOperand<3>(op80);
    ctx.replaceOperand(ctx.getInstDef(inst71), ctx.getInstDef(inst83));
    ctx.removeInst(inst71);
    return true;
}

static bool matchAndSelectPattern115(MIRInst& inst115, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op116;
    MIROperand op117;
    MIROperand op118;
    if(!matchInstSub(inst115, op116, op117, op118))
        return false;
    MIROperand op119;
    MIROperand op120;
    MIROperand op121;
    if(!(isOperandIReg(op117) && selectFusedIntegerBinaryOperand(op118, ctx, op119, op120, op121)))
        return false;
    // Select
    auto op122 = (op116);
    auto op123 = (op117);
    auto op124 = (op119);
    auto op125 = (op120);
    auto op126 = (op121);
    auto& inst127 = ctx.newInst(getFusedIntegerBinaryOpcode(rootOpcode))
                        .setOperand<0>(op122)
                        .setOperand<1>(op123)
                        .setOperand<2>(op124)
                        .setOperand<3>(op125)
                        .setOperand<4>(op126);
    ctx.replaceOperand(ctx.getInstDef(inst115), ctx.getInstDef(inst127));
    ctx.removeInst(inst115);
    return true;
}

static bool matchAndSelectPattern167(MIRInst& inst167, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op168;
    MIROperand op169;
    MIROperand op170;
    if(!matchInstSub(inst167, op168, op169, op170))
        return false;
    MIROperand op171;
    MIROperand op172;
    MIROperand op173;
    if(!(selectFusedIntegerBinaryOperand(op169, ctx, op171, op172, op173) && isOperandIReg(op170)))
        return false;
    // Select
    auto op174 = (op168);
    auto op175 = (op170);
    auto op176 = (op171);
    auto op177 = (op172);
    auto op178 = (op173);
    auto& inst179 =
        ctx.newInst(RSB_Fused).setOperand<0>(op174).setOperand<1>(op175).setOperand<2>(op176).setOperand<3>(op177).setOperand<4>(
            op178);
    ctx.replaceOperand(ctx.getInstDef(inst167), ctx.getInstDef(inst179));
    ctx.removeInst(inst167);
    return true;
}

static bool matchAndSelectPattern188(MIRInst& inst188, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op189;
    MIROperand op190;
    MIROperand op191;
    if(!matchInstSub(inst188, op189, op190, op191))
        return false;
    if(!(isOperandIReg(op190) && isOperandOp2(op191)))
        return false;
    // Select
    auto op192 = (op189);
    auto op193 = (op190);
    auto op194 = (op191);
    auto& inst195 =
        ctx.newInst(getIntegerBinaryOpcode(rootOpcode)).setOperand<0>(op192).setOperand<1>(op193).setOperand<2>(op194);
    ctx.replaceOperand(ctx.getInstDef(inst188), ctx.getInstDef(inst195));
    ctx.removeInst(inst188);
    return true;
}

static bool matchAndSelectPattern229(MIRInst& inst229, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op230;
    MIROperand op231;
    MIROperand op232;
    if(!matchInstSub(inst229, op230, op231, op232))
        return false;
    if(!(isOperandOp2(op231) && isOperandIReg(op232)))
        return false;
    // Select
    auto op233 = (op230);
    auto op234 = (op232);
    auto op235 = (op231);
    auto& inst236 = ctx.newInst(RSB).setOperand<0>(op233).setOperand<1>(op234).setOperand<2>(op235);
    ctx.replaceOperand(ctx.getInstDef(inst229), ctx.getInstDef(inst236));
    ctx.removeInst(inst229);
    return true;
}

static bool matchAndSelectPattern58(MIRInst& inst58, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op59;
    MIROperand op60;
    MIROperand op61;
    if(!matchInstAdd(inst58, op59, op60, op61))
        return false;
    auto instptr61 = ctx.lookupDef(op61);
    if(!instptr61)
        return false;
    auto& inst61 = *instptr61;
    MIROperand op62;
    MIROperand op63;
    MIROperand op64;
    if(!matchInstMul(inst61, op62, op63, op64))
        return false;
    if(!(isOperandIReg(op63) && ctx.isSafeToUse(op63, op62) && (!isOperandIReg(op64) || ctx.isSafeToUse(op64, op62))))
        return false;
    MIROperand op65;
    if(!(isOperandIReg(op60) && buildIReg(ctx, op64, op65)))
        return false;
    // Select
    auto op66 = (op59);
    auto op67 = (op60);
    auto op68 = (op63);
    auto op69 = (op65);
    auto& inst70 = ctx.newInst((rootOpcode == InstAdd ? MLA : MLS))
                       .setOperand<0>(op66)
                       .setOperand<1>(op68)
                       .setOperand<2>(op69)
                       .setOperand<3>(op67);
    ctx.replaceOperand(ctx.getInstDef(inst58), ctx.getInstDef(inst70));
    ctx.removeInst(inst58);
    return true;
}

static bool matchAndSelectPattern102(MIRInst& inst102, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op103;
    MIROperand op104;
    MIROperand op105;
    if(!matchInstAdd(inst102, op103, op104, op105))
        return false;
    MIROperand op106;
    MIROperand op107;
    MIROperand op108;
    if(!(isOperandIReg(op104) && selectFusedIntegerBinaryOperand(op105, ctx, op106, op107, op108)))
        return false;
    // Select
    auto op109 = (op103);
    auto op110 = (op104);
    auto op111 = (op106);
    auto op112 = (op107);
    auto op113 = (op108);
    auto& inst114 = ctx.newInst(getFusedIntegerBinaryOpcode(rootOpcode))
                        .setOperand<0>(op109)
                        .setOperand<1>(op110)
                        .setOperand<2>(op111)
                        .setOperand<3>(op112)
                        .setOperand<4>(op113);
    ctx.replaceOperand(ctx.getInstDef(inst102), ctx.getInstDef(inst114));
    ctx.removeInst(inst102);
    return true;
}

static bool matchAndSelectPattern180(MIRInst& inst180, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op181;
    MIROperand op182;
    MIROperand op183;
    if(!matchInstAdd(inst180, op181, op182, op183))
        return false;
    if(!(isOperandIReg(op182) && isOperandOp2(op183)))
        return false;
    // Select
    auto op184 = (op181);
    auto op185 = (op182);
    auto op186 = (op183);
    auto& inst187 =
        ctx.newInst(getIntegerBinaryOpcode(rootOpcode)).setOperand<0>(op184).setOperand<1>(op185).setOperand<2>(op186);
    ctx.replaceOperand(ctx.getInstDef(inst180), ctx.getInstDef(inst187));
    ctx.removeInst(inst180);
    return true;
}

static bool matchAndSelectPattern84(MIRInst& inst84, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAnd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op85;
    MIROperand op86;
    MIROperand op87;
    if(!matchInstAnd(inst84, op85, op86, op87))
        return false;
    auto instptr87 = ctx.lookupDef(op87);
    if(!instptr87)
        return false;
    auto& inst87 = *instptr87;
    MIROperand op88;
    MIROperand op89;
    MIROperand op90;
    if(!matchInstXor(inst87, op88, op89, op90))
        return false;
    if(!(isOperandIReg(op86) && isOperandOp2(op89) && isNotImm((op85).type(), op90)))
        return false;
    // Select
    auto op91 = (op85);
    auto op92 = (op86);
    auto op93 = (op89);
    auto& inst94 = ctx.newInst(BIC).setOperand<0>(op91).setOperand<1>(op92).setOperand<2>(op93);
    ctx.replaceOperand(ctx.getInstDef(inst84), ctx.getInstDef(inst94));
    ctx.removeInst(inst84);
    return true;
}

static bool matchAndSelectPattern128(MIRInst& inst128, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAnd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op129;
    MIROperand op130;
    MIROperand op131;
    if(!matchInstAnd(inst128, op129, op130, op131))
        return false;
    MIROperand op132;
    MIROperand op133;
    MIROperand op134;
    if(!(isOperandIReg(op130) && selectFusedIntegerBinaryOperand(op131, ctx, op132, op133, op134)))
        return false;
    // Select
    auto op135 = (op129);
    auto op136 = (op130);
    auto op137 = (op132);
    auto op138 = (op133);
    auto op139 = (op134);
    auto& inst140 = ctx.newInst(getFusedIntegerBinaryOpcode(rootOpcode))
                        .setOperand<0>(op135)
                        .setOperand<1>(op136)
                        .setOperand<2>(op137)
                        .setOperand<3>(op138)
                        .setOperand<4>(op139);
    ctx.replaceOperand(ctx.getInstDef(inst128), ctx.getInstDef(inst140));
    ctx.removeInst(inst128);
    return true;
}

static bool matchAndSelectPattern196(MIRInst& inst196, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAnd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op197;
    MIROperand op198;
    MIROperand op199;
    if(!matchInstAnd(inst196, op197, op198, op199))
        return false;
    if(!(isOperandIReg(op198) && isOperandOp2(op199)))
        return false;
    // Select
    auto op200 = (op197);
    auto op201 = (op198);
    auto op202 = (op199);
    auto& inst203 =
        ctx.newInst(getIntegerBinaryOpcode(rootOpcode)).setOperand<0>(op200).setOperand<1>(op201).setOperand<2>(op202);
    ctx.replaceOperand(ctx.getInstDef(inst196), ctx.getInstDef(inst203));
    ctx.removeInst(inst196);
    return true;
}

static bool matchAndSelectPattern220(MIRInst& inst220, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAnd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op221;
    MIROperand op222;
    MIROperand op223;
    if(!matchInstAnd(inst220, op221, op222, op223))
        return false;
    MIROperand op224;
    if(!(selectInvertedOp2Constant(op223, op224) && isOperandIReg(op222)))
        return false;
    // Select
    auto op225 = (op221);
    auto op226 = (op222);
    auto op227 = (op224);
    auto& inst228 =
        ctx.newInst(getBitwiseVariantOpcode(rootOpcode)).setOperand<0>(op225).setOperand<1>(op226).setOperand<2>(op227);
    ctx.replaceOperand(ctx.getInstDef(inst220), ctx.getInstDef(inst228));
    ctx.removeInst(inst220);
    return true;
}

static bool matchAndSelectPattern95(MIRInst& inst95, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstXor;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op96;
    MIROperand op97;
    MIROperand op98;
    if(!matchInstXor(inst95, op96, op97, op98))
        return false;
    if(!(isOperandIReg(op97) && isNegativeOne(op98)))
        return false;
    // Select
    auto op99 = (op96);
    auto op100 = (op97);
    auto& inst101 = ctx.newInst(MVN).setOperand<0>(op99).setOperand<1>(op100);
    ctx.replaceOperand(ctx.getInstDef(inst95), ctx.getInstDef(inst101));
    ctx.removeInst(inst95);
    return true;
}

static bool matchAndSelectPattern154(MIRInst& inst154, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstXor;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op155;
    MIROperand op156;
    MIROperand op157;
    if(!matchInstXor(inst154, op155, op156, op157))
        return false;
    MIROperand op158;
    MIROperand op159;
    MIROperand op160;
    if(!(isOperandIReg(op156) && selectFusedIntegerBinaryOperand(op157, ctx, op158, op159, op160)))
        return false;
    // Select
    auto op161 = (op155);
    auto op162 = (op156);
    auto op163 = (op158);
    auto op164 = (op159);
    auto op165 = (op160);
    auto& inst166 = ctx.newInst(getFusedIntegerBinaryOpcode(rootOpcode))
                        .setOperand<0>(op161)
                        .setOperand<1>(op162)
                        .setOperand<2>(op163)
                        .setOperand<3>(op164)
                        .setOperand<4>(op165);
    ctx.replaceOperand(ctx.getInstDef(inst154), ctx.getInstDef(inst166));
    ctx.removeInst(inst154);
    return true;
}

static bool matchAndSelectPattern212(MIRInst& inst212, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstXor;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op213;
    MIROperand op214;
    MIROperand op215;
    if(!matchInstXor(inst212, op213, op214, op215))
        return false;
    if(!(isOperandIReg(op214) && isOperandOp2(op215)))
        return false;
    // Select
    auto op216 = (op213);
    auto op217 = (op214);
    auto op218 = (op215);
    auto& inst219 =
        ctx.newInst(getIntegerBinaryOpcode(rootOpcode)).setOperand<0>(op216).setOperand<1>(op217).setOperand<2>(op218);
    ctx.replaceOperand(ctx.getInstDef(inst212), ctx.getInstDef(inst219));
    ctx.removeInst(inst212);
    return true;
}

static bool matchAndSelectPattern141(MIRInst& inst141, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstOr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op142;
    MIROperand op143;
    MIROperand op144;
    if(!matchInstOr(inst141, op142, op143, op144))
        return false;
    MIROperand op145;
    MIROperand op146;
    MIROperand op147;
    if(!(isOperandIReg(op143) && selectFusedIntegerBinaryOperand(op144, ctx, op145, op146, op147)))
        return false;
    // Select
    auto op148 = (op142);
    auto op149 = (op143);
    auto op150 = (op145);
    auto op151 = (op146);
    auto op152 = (op147);
    auto& inst153 = ctx.newInst(getFusedIntegerBinaryOpcode(rootOpcode))
                        .setOperand<0>(op148)
                        .setOperand<1>(op149)
                        .setOperand<2>(op150)
                        .setOperand<3>(op151)
                        .setOperand<4>(op152);
    ctx.replaceOperand(ctx.getInstDef(inst141), ctx.getInstDef(inst153));
    ctx.removeInst(inst141);
    return true;
}

static bool matchAndSelectPattern204(MIRInst& inst204, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstOr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op205;
    MIROperand op206;
    MIROperand op207;
    if(!matchInstOr(inst204, op205, op206, op207))
        return false;
    if(!(isOperandIReg(op206) && isOperandOp2(op207)))
        return false;
    // Select
    auto op208 = (op205);
    auto op209 = (op206);
    auto op210 = (op207);
    auto& inst211 =
        ctx.newInst(getIntegerBinaryOpcode(rootOpcode)).setOperand<0>(op208).setOperand<1>(op209).setOperand<2>(op210);
    ctx.replaceOperand(ctx.getInstDef(inst204), ctx.getInstDef(inst211));
    ctx.removeInst(inst204);
    return true;
}

static bool matchAndSelectPattern237(MIRInst& inst237, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op238;
    MIROperand op239;
    MIROperand op240;
    if(!matchInstMul(inst237, op238, op239, op240))
        return false;
    auto instptr240 = ctx.lookupDef(op240);
    if(!instptr240)
        return false;
    auto& inst240 = *instptr240;
    MIROperand op241;
    MIROperand op242;
    MIROperand op243;
    if(!matchInstAdd(inst240, op241, op242, op243))
        return false;
    if(!(isOperandIReg(op242) && isOne(op243) && ctx.isSafeToUse(op242, op241)))
        return false;
    if(!(isOperandIReg(op239)))
        return false;
    // Select
    auto op244 = (op238);
    auto op245 = (op239);
    auto op246 = (op239);
    auto op247 = (op242);
    auto& inst248 = ctx.newInst(MLA).setOperand<0>(op244).setOperand<1>(op246).setOperand<2>(op247).setOperand<3>(op245);
    ctx.replaceOperand(ctx.getInstDef(inst237), ctx.getInstDef(inst248));
    ctx.removeInst(inst237);
    return true;
}

static bool matchAndSelectPattern249(MIRInst& inst249, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op250;
    MIROperand op251;
    MIROperand op252;
    if(!matchInstMul(inst249, op250, op251, op252))
        return false;
    auto instptr251 = ctx.lookupDef(op251);
    if(!instptr251)
        return false;
    auto& inst251 = *instptr251;
    MIROperand op253;
    MIROperand op254;
    MIROperand op255;
    if(!matchInstAdd(inst251, op253, op254, op255))
        return false;
    if(!(isOperandIReg(op254) && isOne(op255) && ctx.isSafeToUse(op254, op253)))
        return false;
    if(!(isOperandIReg(op252)))
        return false;
    // Select
    auto op256 = (op250);
    auto op257 = (op252);
    auto op258 = (op252);
    auto op259 = (op254);
    auto& inst260 = ctx.newInst(MLA).setOperand<0>(op256).setOperand<1>(op258).setOperand<2>(op259).setOperand<3>(op257);
    ctx.replaceOperand(ctx.getInstDef(inst249), ctx.getInstDef(inst260));
    ctx.removeInst(inst249);
    return true;
}

static bool matchAndSelectPattern261(MIRInst& inst261, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op262;
    MIROperand op263;
    MIROperand op264;
    if(!matchInstMul(inst261, op262, op263, op264))
        return false;
    auto instptr264 = ctx.lookupDef(op264);
    if(!instptr264)
        return false;
    auto& inst264 = *instptr264;
    MIROperand op265;
    MIROperand op266;
    MIROperand op267;
    if(!matchInstSub(inst264, op265, op266, op267))
        return false;
    if(!(isOperandIReg(op267) && isOne(op266) && ctx.isSafeToUse(op267, op265)))
        return false;
    if(!(isOperandIReg(op263)))
        return false;
    // Select
    auto op268 = (op262);
    auto op269 = (op263);
    auto op270 = (op263);
    auto op271 = (op267);
    auto& inst272 = ctx.newInst(MLS).setOperand<0>(op268).setOperand<1>(op270).setOperand<2>(op271).setOperand<3>(op269);
    ctx.replaceOperand(ctx.getInstDef(inst261), ctx.getInstDef(inst272));
    ctx.removeInst(inst261);
    return true;
}

static bool matchAndSelectPattern273(MIRInst& inst273, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op274;
    MIROperand op275;
    MIROperand op276;
    if(!matchInstMul(inst273, op274, op275, op276))
        return false;
    auto instptr275 = ctx.lookupDef(op275);
    if(!instptr275)
        return false;
    auto& inst275 = *instptr275;
    MIROperand op277;
    MIROperand op278;
    MIROperand op279;
    if(!matchInstSub(inst275, op277, op278, op279))
        return false;
    if(!(isOperandIReg(op279) && isOne(op278) && ctx.isSafeToUse(op279, op277)))
        return false;
    if(!(isOperandIReg(op276)))
        return false;
    // Select
    auto op280 = (op274);
    auto op281 = (op276);
    auto op282 = (op276);
    auto op283 = (op279);
    auto& inst284 = ctx.newInst(MLS).setOperand<0>(op280).setOperand<1>(op282).setOperand<2>(op283).setOperand<3>(op281);
    ctx.replaceOperand(ctx.getInstDef(inst273), ctx.getInstDef(inst284));
    ctx.removeInst(inst273);
    return true;
}

static bool matchAndSelectPattern285(MIRInst& inst285, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op286;
    MIROperand op287;
    MIROperand op288;
    if(!matchInstMul(inst285, op286, op287, op288))
        return false;
    if(!(isOperandIReg(op287) && isOperandIReg(op288)))
        return false;
    // Select
    auto op289 = (op286);
    auto op290 = (op287);
    auto op291 = (op288);
    auto& inst292 = ctx.newInst(MUL).setOperand<0>(op289).setOperand<1>(op290).setOperand<2>(op291);
    ctx.replaceOperand(ctx.getInstDef(inst285), ctx.getInstDef(inst292));
    ctx.removeInst(inst285);
    return true;
}

static bool matchAndSelectPattern293(MIRInst& inst293, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op294;
    MIROperand op295;
    MIROperand op296;
    MIROperand op297;
    MIROperand op298;
    MIROperand op299;
    if(!matchInstSDiv(inst293, op294, op295, op296, op297, op298, op299))
        return false;
    if(!(isOperandIReg(op294) && isOperandIReg(op295) && (op296).isImm() && (op296).imm() == 2))
        return false;
    // Select
    auto op300 = (op294);
    auto op301 = (getVRegAs(ctx, op294));
    auto op302 = (op295);
    auto op303 = (op295);
    auto op304 = (MIROperand::asImm(LSR, OperandType::ShiftType));
    auto op305 = (MIROperand::asImm(31, OperandType::Int32));
    auto& inst306 =
        ctx.newInst(ADD_Fused).setOperand<0>(op301).setOperand<1>(op302).setOperand<2>(op303).setOperand<3>(op304).setOperand<4>(
            op305);
    auto& op306 = ctx.getInstDef(inst306);
    auto op307 = (MIROperand::asImm(1, OperandType::Int32));
    auto& inst308 = ctx.newInst(ASR).setOperand<0>(op300).setOperand<1>(op306).setOperand<2>(op307);
    ctx.replaceOperand(ctx.getInstDef(inst293), ctx.getInstDef(inst308));
    ctx.removeInst(inst293);
    return true;
}

static bool matchAndSelectPattern309(MIRInst& inst309, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op310;
    MIROperand op311;
    MIROperand op312;
    MIROperand op313;
    MIROperand op314;
    MIROperand op315;
    if(!matchInstSDiv(inst309, op310, op311, op312, op313, op314, op315))
        return false;
    MIROperand op316;
    if(!(isOperandIReg(op310) && isOperandIReg(op311) && selectSDiv32ByPowerOf2(op312, op316)))
        return false;
    // Select
    auto op317 = (op310);
    auto op318 = (getVRegAs(ctx, op310));
    auto op319 = (op311);
    auto op320 = (getVRegAs(ctx, op310));
    auto op321 = (op311);
    auto op322 = (MIROperand::asImm(31, OperandType::Int32));
    auto& inst323 = ctx.newInst(ASR).setOperand<0>(op320).setOperand<1>(op321).setOperand<2>(op322);
    auto& op323 = ctx.getInstDef(inst323);
    auto op324 = (MIROperand::asImm(LSR, OperandType::ShiftType));
    auto op325 = (MIROperand::asImm(32 - (op316).imm(), OperandType::Int32));
    auto& inst326 =
        ctx.newInst(ADD_Fused).setOperand<0>(op318).setOperand<1>(op319).setOperand<2>(op323).setOperand<3>(op324).setOperand<4>(
            op325);
    auto& op326 = ctx.getInstDef(inst326);
    auto op327 = (op316);
    auto& inst328 = ctx.newInst(ASR).setOperand<0>(op317).setOperand<1>(op326).setOperand<2>(op327);
    ctx.replaceOperand(ctx.getInstDef(inst309), ctx.getInstDef(inst328));
    ctx.removeInst(inst309);
    return true;
}

static bool matchAndSelectPattern329(MIRInst& inst329, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op330;
    MIROperand op331;
    MIROperand op332;
    MIROperand op333;
    MIROperand op334;
    MIROperand op335;
    if(!matchInstSDiv(inst329, op330, op331, op332, op333, op334, op335))
        return false;
    auto instptr332 = ctx.lookupDef(op332);
    if(!instptr332)
        return false;
    auto& inst332 = *instptr332;
    MIROperand op336;
    MIROperand op337;
    MIROperand op338;
    if(!matchInstShl(inst332, op336, op337, op338))
        return false;
    if(!(isOperandIReg(op330) && isOperandIReg(op331) && isOne(op337)))
        return false;
    // Select
    auto op339 = (op330);
    auto op340 = (getVRegAs(ctx, op330));
    auto op341 = (op331);
    auto op342 = (getVRegAs(ctx, op330));
    auto op343 = (op331);
    auto op344 = (MIROperand::asImm(31, OperandType::Int32));
    auto& inst345 = ctx.newInst(ASR).setOperand<0>(op342).setOperand<1>(op343).setOperand<2>(op344);
    auto& op345 = ctx.getInstDef(inst345);
    auto op346 = (MIROperand::asImm(LSR, OperandType::ShiftType));
    auto op347 = (getVRegAs(ctx, op330));
    auto op348 = (MIROperand::asImm(32, OperandType::Int32));
    auto op349 = (op338);
    auto& inst350 = ctx.newInst(InstSub).setOperand<0>(op347).setOperand<1>(op348).setOperand<2>(op349);
    auto& op350 = ctx.getInstDef(inst350);
    auto& inst351 =
        ctx.newInst(ADD_Fused).setOperand<0>(op340).setOperand<1>(op341).setOperand<2>(op345).setOperand<3>(op346).setOperand<4>(
            op350);
    auto& op351 = ctx.getInstDef(inst351);
    auto op352 = (op338);
    auto& inst353 = ctx.newInst(ASR).setOperand<0>(op339).setOperand<1>(op351).setOperand<2>(op352);
    ctx.replaceOperand(ctx.getInstDef(inst329), ctx.getInstDef(inst353));
    ctx.removeInst(inst329);
    return true;
}

static bool matchAndSelectPattern354(MIRInst& inst354, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op355;
    MIROperand op356;
    MIROperand op357;
    MIROperand op358;
    MIROperand op359;
    MIROperand op360;
    if(!matchInstSDiv(inst354, op355, op356, op357, op358, op359, op360))
        return false;
    MIROperand op361;
    MIROperand op362;
    MIROperand op363;
    MIROperand op364;
    MIROperand op365;
    if(!(isOperandIReg(op355) && isOperandIReg(op356) && selectSDiv32ByConstant(op357, op361, op362, op363) &&
         isSDivExpandProfitable(op358, op359, op363) && buildMulHiImm(ctx, op356, op361, op363, op364) &&
         buildASR(ctx, op364, op362, op365)))
        return false;
    // Select
    auto op366 = (op355);
    auto op367 = (op365);
    auto op368 = (op364);
    auto op369 = (MIROperand::asImm(LSR, OperandType::ShiftType));
    auto op370 = (MIROperand::asImm(31, OperandType::Int32));
    auto& inst371 =
        ctx.newInst(ADD_Fused).setOperand<0>(op366).setOperand<1>(op367).setOperand<2>(op368).setOperand<3>(op369).setOperand<4>(
            op370);
    ctx.replaceOperand(ctx.getInstDef(inst354), ctx.getInstDef(inst371));
    ctx.removeInst(inst354);
    return true;
}

static bool matchAndSelectPattern372(MIRInst& inst372, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op373;
    MIROperand op374;
    MIROperand op375;
    MIROperand op376;
    MIROperand op377;
    MIROperand op378;
    if(!matchInstSDiv(inst372, op373, op374, op375, op376, op377, op378))
        return false;
    if(!(isOperandIReg(op373) && isOperandIReg(op374) && !isOperandIReg(op375)))
        return false;
    // Select
    auto op379 = (op373);
    auto op380 = (op374);
    auto op381 = (getVRegAs(ctx, op373));
    auto op382 = (op375);
    auto& inst383 = ctx.newInst(InstLoadImm).setOperand<0>(op381).setOperand<1>(op382);
    auto& op383 = ctx.getInstDef(inst383);
    auto op384 = (op376);
    auto op385 = (op377);
    auto op386 = (op378);
    auto& inst387 = ctx.newInst(InstSDiv)
                        .setOperand<0>(op379)
                        .setOperand<1>(op380)
                        .setOperand<2>(op383)
                        .setOperand<3>(op384)
                        .setOperand<4>(op385)
                        .setOperand<5>(op386);
    ctx.replaceOperand(ctx.getInstDef(inst372), ctx.getInstDef(inst387));
    ctx.removeInst(inst372);
    return true;
}

static bool matchAndSelectPattern388(MIRInst& inst388, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op389;
    MIROperand op390;
    MIROperand op391;
    MIROperand op392;
    MIROperand op393;
    MIROperand op394;
    if(!matchInstSDiv(inst388, op389, op390, op391, op392, op393, op394))
        return false;
    if(!(isOperandIReg(op390) && isOperandIReg(op391)))
        return false;
    // Select
    auto op395 = (op389);
    auto op396 = (op390);
    auto op397 = (op391);
    auto op398 = (op392);
    auto op399 = (op393);
    auto& inst400 =
        ctx.newInst(SDIV).setOperand<0>(op395).setOperand<1>(op396).setOperand<2>(op397).setOperand<3>(op398).setOperand<4>(
            op399);
    ctx.replaceOperand(ctx.getInstDef(inst388), ctx.getInstDef(inst400));
    ctx.removeInst(inst388);
    return true;
}

static bool matchAndSelectPattern401(MIRInst& inst401, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstUDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op402;
    MIROperand op403;
    MIROperand op404;
    if(!matchInstUDiv(inst401, op402, op403, op404))
        return false;
    if(!(isOperandIReg(op403) && isOperandIReg(op404)))
        return false;
    // Select
    auto op405 = (op402);
    auto op406 = (op403);
    auto op407 = (op404);
    auto& inst408 = ctx.newInst(UDIV).setOperand<0>(op405).setOperand<1>(op406).setOperand<2>(op407);
    ctx.replaceOperand(ctx.getInstDef(inst401), ctx.getInstDef(inst408));
    ctx.removeInst(inst401);
    return true;
}

static bool matchAndSelectPattern409(MIRInst& inst409, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSRem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op410;
    MIROperand op411;
    MIROperand op412;
    MIROperand op413;
    MIROperand op414;
    MIROperand op415;
    if(!matchInstSRem(inst409, op410, op411, op412, op413, op414, op415))
        return false;
    MIROperand op416;
    MIROperand op417;
    if(!(isOperandIReg(op411) && isOperandImm(op412) && buildIRegShift(ctx, op412, op416, op417)))
        return false;
    // Select
    auto op418 = (op410);
    auto op419 = (op411);
    auto op420 = (getVRegAs(ctx, op410));
    auto op421 = (op411);
    auto op422 = (op412);
    auto op423 = (op413);
    auto op424 = (op414);
    auto op425 = (getSDivHint(op415));
    auto& inst426 = ctx.newInst(InstSDiv)
                        .setOperand<0>(op420)
                        .setOperand<1>(op421)
                        .setOperand<2>(op422)
                        .setOperand<3>(op423)
                        .setOperand<4>(op424)
                        .setOperand<5>(op425);
    auto& op426 = ctx.getInstDef(inst426);
    auto op427 = (MIROperand::asImm(LSL, OperandType::ShiftType));
    auto op428 = (op417);
    auto& inst429 =
        ctx.newInst(SUB_Fused).setOperand<0>(op418).setOperand<1>(op419).setOperand<2>(op426).setOperand<3>(op427).setOperand<4>(
            op428);
    ctx.replaceOperand(ctx.getInstDef(inst409), ctx.getInstDef(inst429));
    ctx.removeInst(inst409);
    return true;
}

static bool matchAndSelectPattern430(MIRInst& inst430, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSRem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op431;
    MIROperand op432;
    MIROperand op433;
    MIROperand op434;
    MIROperand op435;
    MIROperand op436;
    if(!matchInstSRem(inst430, op431, op432, op433, op434, op435, op436))
        return false;
    MIROperand op437;
    MIROperand op438;
    MIROperand op439;
    if(!(isOperandIReg(op432) && isOperandImm(op433) && selectSDiv32ByConstant(op433, op437, op438, op439) &&
         isSDivExpandProfitable(op434, op435, op439)))
        return false;
    // Select
    auto op440 = (op431);
    auto op441 = (op432);
    auto op442 = (getVRegAs(ctx, op431));
    auto op443 = (getVRegAs(ctx, op431));
    auto op444 = (op432);
    auto op445 = (op433);
    auto op446 = (op434);
    auto op447 = (op435);
    auto op448 = (getSDivHint(op436));
    auto& inst449 = ctx.newInst(InstSDiv)
                        .setOperand<0>(op443)
                        .setOperand<1>(op444)
                        .setOperand<2>(op445)
                        .setOperand<3>(op446)
                        .setOperand<4>(op447)
                        .setOperand<5>(op448);
    auto& op449 = ctx.getInstDef(inst449);
    auto op450 = (op433);
    auto& inst451 = ctx.newInst(InstMul).setOperand<0>(op442).setOperand<1>(op449).setOperand<2>(op450);
    auto& op451 = ctx.getInstDef(inst451);
    auto& inst452 = ctx.newInst(InstSub).setOperand<0>(op440).setOperand<1>(op441).setOperand<2>(op451);
    ctx.replaceOperand(ctx.getInstDef(inst430), ctx.getInstDef(inst452));
    ctx.removeInst(inst430);
    return true;
}

static bool matchAndSelectPattern453(MIRInst& inst453, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSRem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op454;
    MIROperand op455;
    MIROperand op456;
    MIROperand op457;
    MIROperand op458;
    MIROperand op459;
    if(!matchInstSRem(inst453, op454, op455, op456, op457, op458, op459))
        return false;
    MIROperand op460;
    if(!(isOperandIReg(op454) && isOperandIReg(op455) && !isOperandIReg(op456) && buildIReg(ctx, op456, op460)))
        return false;
    // Select
    auto op461 = (op454);
    auto op462 = (op455);
    auto op463 = (getVRegAs(ctx, op454));
    auto op464 = (getVRegAs(ctx, op454));
    auto op465 = (op455);
    auto op466 = (op460);
    auto op467 = (op457);
    auto op468 = (op458);
    auto& inst469 =
        ctx.newInst(SDIV).setOperand<0>(op464).setOperand<1>(op465).setOperand<2>(op466).setOperand<3>(op467).setOperand<4>(
            op468);
    auto& op469 = ctx.getInstDef(inst469);
    auto op470 = (op456);
    auto& inst471 = ctx.newInst(InstMul).setOperand<0>(op463).setOperand<1>(op469).setOperand<2>(op470);
    auto& op471 = ctx.getInstDef(inst471);
    auto& inst472 = ctx.newInst(InstSub).setOperand<0>(op461).setOperand<1>(op462).setOperand<2>(op471);
    ctx.replaceOperand(ctx.getInstDef(inst453), ctx.getInstDef(inst472));
    ctx.removeInst(inst453);
    return true;
}

static bool matchAndSelectPattern473(MIRInst& inst473, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSRem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op474;
    MIROperand op475;
    MIROperand op476;
    MIROperand op477;
    MIROperand op478;
    MIROperand op479;
    if(!matchInstSRem(inst473, op474, op475, op476, op477, op478, op479))
        return false;
    if(!(isOperandIReg(op475) && isOperandIReg(op476)))
        return false;
    // Select
    auto op480 = (op474);
    auto op481 = (op475);
    auto op482 = (getVRegAs(ctx, op474));
    auto op483 = (op475);
    auto op484 = (op476);
    auto op485 = (op477);
    auto op486 = (op478);
    auto& inst487 =
        ctx.newInst(SDIV).setOperand<0>(op482).setOperand<1>(op483).setOperand<2>(op484).setOperand<3>(op485).setOperand<4>(
            op486);
    auto& op487 = ctx.getInstDef(inst487);
    auto op488 = (op476);
    auto& inst489 = ctx.newInst(MLS).setOperand<0>(op480).setOperand<1>(op487).setOperand<2>(op488).setOperand<3>(op481);
    ctx.replaceOperand(ctx.getInstDef(inst473), ctx.getInstDef(inst489));
    ctx.removeInst(inst473);
    return true;
}

static bool matchAndSelectPattern490(MIRInst& inst490, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstURem;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op491;
    MIROperand op492;
    MIROperand op493;
    if(!matchInstURem(inst490, op491, op492, op493))
        return false;
    if(!(isOperandIReg(op492) && isOperandIReg(op493)))
        return false;
    // Select
    auto op494 = (op491);
    auto op495 = (op492);
    auto op496 = (getVRegAs(ctx, op491));
    auto op497 = (op492);
    auto op498 = (op493);
    auto& inst499 = ctx.newInst(UDIV).setOperand<0>(op496).setOperand<1>(op497).setOperand<2>(op498);
    auto& op499 = ctx.getInstDef(inst499);
    auto op500 = (op493);
    auto& inst501 = ctx.newInst(MLS).setOperand<0>(op494).setOperand<1>(op499).setOperand<2>(op500).setOperand<3>(op495);
    ctx.replaceOperand(ctx.getInstDef(inst490), ctx.getInstDef(inst501));
    ctx.removeInst(inst490);
    return true;
}

static bool matchAndSelectPattern502(MIRInst& inst502, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstShl;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op503;
    MIROperand op504;
    MIROperand op505;
    if(!matchInstShl(inst502, op503, op504, op505))
        return false;
    if(!(isOperandIReg(op504) && isOperandShamt(op505)))
        return false;
    // Select
    auto op506 = (op503);
    auto op507 = (op504);
    auto op508 = (op505);
    auto& inst509 = ctx.newInst(getShiftOpcode(rootOpcode)).setOperand<0>(op506).setOperand<1>(op507).setOperand<2>(op508);
    ctx.replaceOperand(ctx.getInstDef(inst502), ctx.getInstDef(inst509));
    ctx.removeInst(inst502);
    return true;
}

static bool matchAndSelectPattern510(MIRInst& inst510, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op511;
    MIROperand op512;
    MIROperand op513;
    if(!matchInstLShr(inst510, op511, op512, op513))
        return false;
    if(!(isOperandIReg(op512) && isOperandShamt(op513)))
        return false;
    // Select
    auto op514 = (op511);
    auto op515 = (op512);
    auto op516 = (op513);
    auto& inst517 = ctx.newInst(getShiftOpcode(rootOpcode)).setOperand<0>(op514).setOperand<1>(op515).setOperand<2>(op516);
    ctx.replaceOperand(ctx.getInstDef(inst510), ctx.getInstDef(inst517));
    ctx.removeInst(inst510);
    return true;
}

static bool matchAndSelectPattern518(MIRInst& inst518, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAShr;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op519;
    MIROperand op520;
    MIROperand op521;
    if(!matchInstAShr(inst518, op519, op520, op521))
        return false;
    if(!(isOperandIReg(op520) && isOperandShamt(op521)))
        return false;
    // Select
    auto op522 = (op519);
    auto op523 = (op520);
    auto op524 = (op521);
    auto& inst525 = ctx.newInst(getShiftOpcode(rootOpcode)).setOperand<0>(op522).setOperand<1>(op523).setOperand<2>(op524);
    ctx.replaceOperand(ctx.getInstDef(inst518), ctx.getInstDef(inst525));
    ctx.removeInst(inst518);
    return true;
}

static bool matchAndSelectPattern526(MIRInst& inst526, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstS2F;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op527;
    MIROperand op528;
    if(!matchInstS2F(inst526, op527, op528))
        return false;
    if(!(isOperandFPR(op527) && isOperandIReg(op528)))
        return false;
    // Select
    auto op529 = (op527);
    auto op530 = (getVRegAs(ctx, op527));
    auto op531 = (op528);
    auto& inst532 = ctx.newInst(VMOV_GPR2FPR).setOperand<0>(op530).setOperand<1>(op531);
    auto& op532 = ctx.getInstDef(inst532);
    auto& inst533 = ctx.newInst(VCVT_F32_S32).setOperand<0>(op529).setOperand<1>(op532);
    ctx.replaceOperand(ctx.getInstDef(inst526), ctx.getInstDef(inst533));
    ctx.removeInst(inst526);
    return true;
}

static bool matchAndSelectPattern534(MIRInst& inst534, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstF2S;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op535;
    MIROperand op536;
    if(!matchInstF2S(inst534, op535, op536))
        return false;
    if(!(isOperandIReg(op535) && isOperandFPR(op536)))
        return false;
    // Select
    auto op537 = (op535);
    auto op538 = (getVRegAs(ctx, op536));
    auto op539 = (op536);
    auto& inst540 = ctx.newInst(VCVT_S32_F32).setOperand<0>(op538).setOperand<1>(op539);
    auto& op540 = ctx.getInstDef(inst540);
    auto& inst541 = ctx.newInst(VMOV_FPR2GPR).setOperand<0>(op537).setOperand<1>(op540);
    ctx.replaceOperand(ctx.getInstDef(inst534), ctx.getInstDef(inst541));
    ctx.removeInst(inst534);
    return true;
}

static bool matchAndSelectPattern542(MIRInst& inst542, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFAdd;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op543;
    MIROperand op544;
    MIROperand op545;
    if(!matchInstFAdd(inst542, op543, op544, op545))
        return false;
    if(!(isOperandFPR(op544) && isOperandFPR(op545)))
        return false;
    // Select
    auto op546 = (op543);
    auto op547 = (op544);
    auto op548 = (op545);
    auto& inst549 =
        ctx.newInst(getFloatingBinaryOpcode(rootOpcode)).setOperand<0>(op546).setOperand<1>(op547).setOperand<2>(op548);
    ctx.replaceOperand(ctx.getInstDef(inst542), ctx.getInstDef(inst549));
    ctx.removeInst(inst542);
    return true;
}

static bool matchAndSelectPattern550(MIRInst& inst550, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFSub;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op551;
    MIROperand op552;
    MIROperand op553;
    if(!matchInstFSub(inst550, op551, op552, op553))
        return false;
    if(!(isOperandFPR(op552) && isOperandFPR(op553)))
        return false;
    // Select
    auto op554 = (op551);
    auto op555 = (op552);
    auto op556 = (op553);
    auto& inst557 =
        ctx.newInst(getFloatingBinaryOpcode(rootOpcode)).setOperand<0>(op554).setOperand<1>(op555).setOperand<2>(op556);
    ctx.replaceOperand(ctx.getInstDef(inst550), ctx.getInstDef(inst557));
    ctx.removeInst(inst550);
    return true;
}

static bool matchAndSelectPattern558(MIRInst& inst558, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFMul;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op559;
    MIROperand op560;
    MIROperand op561;
    if(!matchInstFMul(inst558, op559, op560, op561))
        return false;
    if(!(isOperandFPR(op560) && isOperandFPR(op561)))
        return false;
    // Select
    auto op562 = (op559);
    auto op563 = (op560);
    auto op564 = (op561);
    auto& inst565 =
        ctx.newInst(getFloatingBinaryOpcode(rootOpcode)).setOperand<0>(op562).setOperand<1>(op563).setOperand<2>(op564);
    ctx.replaceOperand(ctx.getInstDef(inst558), ctx.getInstDef(inst565));
    ctx.removeInst(inst558);
    return true;
}

static bool matchAndSelectPattern566(MIRInst& inst566, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFDiv;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op567;
    MIROperand op568;
    MIROperand op569;
    if(!matchInstFDiv(inst566, op567, op568, op569))
        return false;
    if(!(isOperandFPR(op568) && isOperandFPR(op569)))
        return false;
    // Select
    auto op570 = (op567);
    auto op571 = (op568);
    auto op572 = (op569);
    auto& inst573 =
        ctx.newInst(getFloatingBinaryOpcode(rootOpcode)).setOperand<0>(op570).setOperand<1>(op571).setOperand<2>(op572);
    ctx.replaceOperand(ctx.getInstDef(inst566), ctx.getInstDef(inst573));
    ctx.removeInst(inst566);
    return true;
}

static bool matchAndSelectPattern574(MIRInst& inst574, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFNeg;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op575;
    MIROperand op576;
    if(!matchInstFNeg(inst574, op575, op576))
        return false;
    if(!(isOperandFPR(op575) && isOperandFPR(op576)))
        return false;
    // Select
    auto op577 = (op575);
    auto op578 = (op576);
    auto& inst579 = ctx.newInst(VNEG_F32).setOperand<0>(op577).setOperand<1>(op578);
    ctx.replaceOperand(ctx.getInstDef(inst574), ctx.getInstDef(inst579));
    ctx.removeInst(inst574);
    return true;
}

static bool matchAndSelectPattern580(MIRInst& inst580, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = VMOV_FPR2GPR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op581;
    MIROperand op582;
    if(!matchVMOV_FPR2GPR(inst580, op581, op582))
        return false;
    auto instptr582 = ctx.lookupDef(op582);
    if(!instptr582)
        return false;
    auto& inst582 = *instptr582;
    MIROperand op583;
    MIROperand op584;
    if(!matchVMOV_GPR2FPR(inst582, op583, op584))
        return false;
    if(!(ctx.isSafeToUse(op583, op583) && ctx.isSafeToUse(op584, op583) && isOperandVReg(op584)))
        return false;
    // Select
    auto op585 = (op581);
    auto op586 = (op584);
    auto& inst587 = ctx.newInst(InstCopyToReg).setOperand<0>(op585).setOperand<1>(op586);
    ctx.replaceOperand(ctx.getInstDef(inst580), ctx.getInstDef(inst587));
    ctx.removeInst(inst580);
    return true;
}

static bool matchAndSelectPattern588(MIRInst& inst588, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = VMOV_GPR2FPR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op589;
    MIROperand op590;
    if(!matchVMOV_GPR2FPR(inst588, op589, op590))
        return false;
    auto instptr590 = ctx.lookupDef(op590);
    if(!instptr590)
        return false;
    auto& inst590 = *instptr590;
    MIROperand op591;
    MIROperand op592;
    if(!matchVMOV_FPR2GPR(inst590, op591, op592))
        return false;
    if(!(ctx.isSafeToUse(op591, op591) && ctx.isSafeToUse(op592, op591) && isOperandVReg(op592)))
        return false;
    // Select
    auto op593 = (op589);
    auto op594 = (op592);
    auto& inst595 = ctx.newInst(VMOV).setOperand<0>(op593).setOperand<1>(op594);
    ctx.replaceOperand(ctx.getInstDef(inst588), ctx.getInstDef(inst595));
    ctx.removeInst(inst588);
    return true;
}

static bool matchAndSelectPattern596(MIRInst& inst596, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op597;
    MIROperand op598;
    if(!matchInstZExt(inst596, op597, op598))
        return false;
    if(!(isOperandBoolReg(op598)))
        return false;
    // Select
    auto op599 = (op597);
    auto op600 = (op598);
    auto& inst601 = ctx.newInst(InstCopy).setOperand<0>(op599).setOperand<1>(op600);
    ctx.replaceOperand(ctx.getInstDef(inst596), ctx.getInstDef(inst601));
    ctx.removeInst(inst596);
    return true;
}

static bool matchAndSelectPattern847(MIRInst& inst847, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op848;
    MIROperand op849;
    if(!matchInstZExt(inst847, op848, op849))
        return false;
    auto instptr849 = ctx.lookupDef(op849);
    if(!instptr849)
        return false;
    auto& inst849 = *instptr849;
    MIROperand op850;
    MIROperand op851;
    MIROperand op852;
    if(!matchInstLoad(inst849, op850, op851, op852))
        return false;
    MIROperand op853;
    MIROperand op854;
    if(!(ctx.isSafeToUse(op851, op850) && selectAddrOffset(op851, ctx, op853, op854, getZExtLoadOpcode(op850), (op850).type())))
        return false;
    // Select
    auto op855 = (op848);
    auto op856 = (op853);
    auto op857 = (op854);
    auto& inst858 = ctx.newInst(getZExtLoadOpcode(op850)).setOperand<0>(op855).setOperand<1>(op856).setOperand<2>(op857);
    ctx.replaceOperand(ctx.getInstDef(inst847), ctx.getInstDef(inst858));
    ctx.removeInst(inst847);
    return true;
}

static bool matchAndSelectPattern1236(MIRInst& inst1236, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstZExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1237;
    MIROperand op1238;
    if(!matchInstZExt(inst1236, op1237, op1238))
        return false;
    if(!(isOperandIReg(op1238)))
        return false;
    // Select
    auto op1239 = (op1237);
    auto op1240 = (op1238);
    auto& inst1241 = ctx.newInst(getZExtOpcode((op1238).type())).setOperand<0>(op1239).setOperand<1>(op1240);
    ctx.replaceOperand(ctx.getInstDef(inst1236), ctx.getInstDef(inst1241));
    ctx.removeInst(inst1236);
    return true;
}

static bool matchAndSelectPattern602(MIRInst& inst602, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSExt;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op603;
    MIROperand op604;
    if(!matchInstSExt(inst602, op603, op604))
        return false;
    if(!(isOperandIReg(op604)))
        return false;
    // Select
    auto op605 = (op603);
    auto op606 = (op604);
    auto& inst607 = ctx.newInst(InstCopy).setOperand<0>(op605).setOperand<1>(op606);
    ctx.replaceOperand(ctx.getInstDef(inst602), ctx.getInstDef(inst607));
    ctx.removeInst(inst602);
    return true;
}

static bool matchAndSelectPattern608(MIRInst& inst608, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoadGlobalAddress;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op609;
    MIROperand op610;
    if(!matchInstLoadGlobalAddress(inst608, op609, op610))
        return false;
    // Select
    auto op611 = (op609);
    auto op612 = (op610);
    auto& inst613 = ctx.newInst(MOVT_MOVW_PAIR).setOperand<0>(op611).setOperand<1>(op612);
    ctx.replaceOperand(ctx.getInstDef(inst608), ctx.getInstDef(inst613));
    ctx.removeInst(inst608);
    return true;
}

static bool matchAndSelectPattern614(MIRInst& inst614, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstJump;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op615;
    if(!matchInstJump(inst614, op615))
        return false;
    // Select
    auto op616 = (op615);
    auto& inst617 = ctx.newInst(B).setOperand<0>(op616);
    CMMC_UNUSED(inst617);
    ctx.removeInst(inst614);
    return true;
}

static bool matchAndSelectPattern618(MIRInst& inst618, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op619;
    MIROperand op620;
    MIROperand op621;
    if(!matchInstBranch(inst618, op619, op620, op621))
        return false;
    auto instptr619 = ctx.lookupDef(op619);
    if(!instptr619)
        return false;
    auto& inst619 = *instptr619;
    MIROperand op622;
    MIROperand op623;
    MIROperand op624;
    MIROperand op625;
    if(!matchInstICmp(inst619, op622, op623, op624, op625))
        return false;
    MIROperand op626;
    MIROperand op627;
    if(!(isOperandIReg(op623) && ctx.isSafeToUse(op623, op622) && (!isOperandIReg(op624) || ctx.isSafeToUse(op624, op622)) &&
         selectCompareOp2(op624, op626, op627)))
        return false;
    // Select
    auto op628 = (op623);
    auto op629 = (op626);
    auto op630 = (getCC());
    auto& inst631 = ctx.newInst(getCompareOpcode((op627).imm())).setOperand<0>(op628).setOperand<1>(op629).setOperand<2>(op630);
    auto& op631 = ctx.getInstDef(inst631);
    auto op632 = (getCondFieldICmp(op625));
    auto op633 = (op620);
    auto op634 = (op621);
    auto& inst635 = ctx.newInst(B_Cond).setOperand<0>(op632).setOperand<1>(op633).setOperand<2>(op631).setOperand<3>(op634);
    CMMC_UNUSED(inst635);
    ctx.removeInst(inst618);
    return true;
}

static bool matchAndSelectPattern636(MIRInst& inst636, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op637;
    MIROperand op638;
    MIROperand op639;
    if(!matchInstBranch(inst636, op637, op638, op639))
        return false;
    auto instptr637 = ctx.lookupDef(op637);
    if(!instptr637)
        return false;
    auto& inst637 = *instptr637;
    MIROperand op640;
    MIROperand op641;
    MIROperand op642;
    if(!matchNZCVFlag2GPR(inst637, op640, op641, op642))
        return false;
    if(!(isOperandIReg(op640) && ctx.isSafeToUse(op641, op640)))
        return false;
    // Select
    auto op643 = (op641);
    auto op644 = (op642);
    auto op645 = (op638);
    auto op646 = (op639);
    auto& inst647 = ctx.newInst(B_Cond).setOperand<0>(op644).setOperand<1>(op645).setOperand<2>(op643).setOperand<3>(op646);
    CMMC_UNUSED(inst647);
    ctx.removeInst(inst636);
    return true;
}

static bool matchAndSelectPattern785(MIRInst& inst785, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstBranch;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op786;
    MIROperand op787;
    MIROperand op788;
    if(!matchInstBranch(inst785, op786, op787, op788))
        return false;
    if(!(isOperandIReg(op786) && isNotCmp(ctx, op786)))
        return false;
    // Select
    auto op789 = (op787);
    auto op790 = (op788);
    auto op791 = (getCC());
    auto op792 = (op786);
    auto op793 = (getZero(op786));
    auto& inst794 = ctx.newInst(CMP).setOperand<0>(op792).setOperand<1>(op793).setOperand<2>(op791);
    auto& op794 = ctx.getInstDef(inst794);
    auto op795 = (MIROperand::asImm(CondField::NE, OperandType::CondField));
    auto& inst796 = ctx.newInst(B_Cond).setOperand<0>(op795).setOperand<1>(op789).setOperand<2>(op794).setOperand<3>(op790);
    CMMC_UNUSED(inst796);
    ctx.removeInst(inst785);
    return true;
}

static bool matchAndSelectPattern648(MIRInst& inst648, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSelect;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op649;
    MIROperand op650;
    MIROperand op651;
    MIROperand op652;
    if(!matchInstSelect(inst648, op649, op650, op651, op652))
        return false;
    auto instptr650 = ctx.lookupDef(op650);
    if(!instptr650)
        return false;
    auto& inst650 = *instptr650;
    MIROperand op653;
    MIROperand op654;
    MIROperand op655;
    MIROperand op656;
    if(!matchInstICmp(inst650, op653, op654, op655, op656))
        return false;
    MIROperand op657;
    MIROperand op658;
    if(!(isOperandIReg(op654) && ctx.isSafeToUse(op654, op653) && (!isOperandIReg(op655) || ctx.isSafeToUse(op655, op653)) &&
         selectCompareOp2(op655, op657, op658)))
        return false;
    if(!(isOperandIReg(op649) && isOperandOp2(op651) && isOperandOp2(op652)))
        return false;
    // Select
    auto op659 = (op649);
    auto op660 = (op651);
    auto op661 = (op652);
    auto op662 = (op654);
    auto op663 = (op657);
    auto op664 = (getCC());
    auto& inst665 = ctx.newInst(getCompareOpcode((op658).imm())).setOperand<0>(op662).setOperand<1>(op663).setOperand<2>(op664);
    auto& op665 = ctx.getInstDef(inst665);
    auto op666 = (getCondFieldICmp(op656));
    auto& inst667 = ctx.newInst(Select_GPR)
                        .setOperand<0>(op659)
                        .setOperand<1>(op660)
                        .setOperand<2>(op661)
                        .setOperand<3>(op665)
                        .setOperand<4>(op666);
    ctx.replaceOperand(ctx.getInstDef(inst648), ctx.getInstDef(inst667));
    ctx.removeInst(inst648);
    return true;
}

static bool matchAndSelectPattern668(MIRInst& inst668, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSelect;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op669;
    MIROperand op670;
    MIROperand op671;
    MIROperand op672;
    if(!matchInstSelect(inst668, op669, op670, op671, op672))
        return false;
    auto instptr670 = ctx.lookupDef(op670);
    if(!instptr670)
        return false;
    auto& inst670 = *instptr670;
    MIROperand op673;
    MIROperand op674;
    MIROperand op675;
    MIROperand op676;
    if(!matchInstICmp(inst670, op673, op674, op675, op676))
        return false;
    MIROperand op677;
    MIROperand op678;
    if(!(isOperandIReg(op674) && ctx.isSafeToUse(op674, op673) && (!isOperandIReg(op675) || ctx.isSafeToUse(op675, op673)) &&
         selectCompareOp2(op675, op677, op678)))
        return false;
    if(!(isOperandFPR(op669)))
        return false;
    // Select
    auto op679 = (op669);
    auto op680 = (op671);
    auto op681 = (op672);
    auto op682 = (op674);
    auto op683 = (op677);
    auto op684 = (getCC());
    auto& inst685 = ctx.newInst(getCompareOpcode((op678).imm())).setOperand<0>(op682).setOperand<1>(op683).setOperand<2>(op684);
    auto& op685 = ctx.getInstDef(inst685);
    auto op686 = (getCondFieldICmp(op676));
    auto& inst687 = ctx.newInst(Select_FPR)
                        .setOperand<0>(op679)
                        .setOperand<1>(op680)
                        .setOperand<2>(op681)
                        .setOperand<3>(op685)
                        .setOperand<4>(op686);
    ctx.replaceOperand(ctx.getInstDef(inst668), ctx.getInstDef(inst687));
    ctx.removeInst(inst668);
    return true;
}

static bool matchAndSelectPattern688(MIRInst& inst688, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSelect;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op689;
    MIROperand op690;
    MIROperand op691;
    MIROperand op692;
    if(!matchInstSelect(inst688, op689, op690, op691, op692))
        return false;
    auto instptr690 = ctx.lookupDef(op690);
    if(!instptr690)
        return false;
    auto& inst690 = *instptr690;
    MIROperand op693;
    MIROperand op694;
    MIROperand op695;
    if(!matchNZCVFlag2GPR(inst690, op693, op694, op695))
        return false;
    if(!(ctx.isSafeToUse(op694, op693)))
        return false;
    if(!(isOperandIReg(op689) && isOperandOp2(op691) && isOperandOp2(op692)))
        return false;
    // Select
    auto op696 = (op689);
    auto op697 = (op691);
    auto op698 = (op692);
    auto op699 = (op694);
    auto op700 = (op695);
    auto& inst701 = ctx.newInst(Select_GPR)
                        .setOperand<0>(op696)
                        .setOperand<1>(op697)
                        .setOperand<2>(op698)
                        .setOperand<3>(op699)
                        .setOperand<4>(op700);
    ctx.replaceOperand(ctx.getInstDef(inst688), ctx.getInstDef(inst701));
    ctx.removeInst(inst688);
    return true;
}

static bool matchAndSelectPattern702(MIRInst& inst702, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSelect;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op703;
    MIROperand op704;
    MIROperand op705;
    MIROperand op706;
    if(!matchInstSelect(inst702, op703, op704, op705, op706))
        return false;
    auto instptr704 = ctx.lookupDef(op704);
    if(!instptr704)
        return false;
    auto& inst704 = *instptr704;
    MIROperand op707;
    MIROperand op708;
    MIROperand op709;
    if(!matchNZCVFlag2GPR(inst704, op707, op708, op709))
        return false;
    if(!(ctx.isSafeToUse(op708, op707)))
        return false;
    if(!(isOperandFPR(op703)))
        return false;
    // Select
    auto op710 = (op703);
    auto op711 = (op705);
    auto op712 = (op706);
    auto op713 = (op708);
    auto op714 = (op709);
    auto& inst715 = ctx.newInst(Select_FPR)
                        .setOperand<0>(op710)
                        .setOperand<1>(op711)
                        .setOperand<2>(op712)
                        .setOperand<3>(op713)
                        .setOperand<4>(op714);
    ctx.replaceOperand(ctx.getInstDef(inst702), ctx.getInstDef(inst715));
    ctx.removeInst(inst702);
    return true;
}

static bool matchAndSelectPattern797(MIRInst& inst797, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSelect;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op798;
    MIROperand op799;
    MIROperand op800;
    MIROperand op801;
    if(!matchInstSelect(inst797, op798, op799, op800, op801))
        return false;
    if(!(isOperandIReg(op798) && isOperandOp2(op800) && isOperandOp2(op801) && isNotCmp(ctx, op799)))
        return false;
    // Select
    auto op802 = (op798);
    auto op803 = (op800);
    auto op804 = (op801);
    auto op805 = (op799);
    auto op806 = (getZero(op799));
    auto op807 = (getCC());
    auto& inst808 = ctx.newInst(CMP).setOperand<0>(op805).setOperand<1>(op806).setOperand<2>(op807);
    auto& op808 = ctx.getInstDef(inst808);
    auto op809 = (MIROperand::asImm(CondField::NE, OperandType::CondField));
    auto& inst810 = ctx.newInst(Select_GPR)
                        .setOperand<0>(op802)
                        .setOperand<1>(op803)
                        .setOperand<2>(op804)
                        .setOperand<3>(op808)
                        .setOperand<4>(op809);
    ctx.replaceOperand(ctx.getInstDef(inst797), ctx.getInstDef(inst810));
    ctx.removeInst(inst797);
    return true;
}

static bool matchAndSelectPattern811(MIRInst& inst811, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSelect;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op812;
    MIROperand op813;
    MIROperand op814;
    MIROperand op815;
    if(!matchInstSelect(inst811, op812, op813, op814, op815))
        return false;
    if(!(isOperandFPR(op812) && isNotCmp(ctx, op813)))
        return false;
    // Select
    auto op816 = (op812);
    auto op817 = (op814);
    auto op818 = (op815);
    auto op819 = (op813);
    auto op820 = (getZero(op813));
    auto op821 = (getCC());
    auto& inst822 = ctx.newInst(CMP).setOperand<0>(op819).setOperand<1>(op820).setOperand<2>(op821);
    auto& op822 = ctx.getInstDef(inst822);
    auto op823 = (MIROperand::asImm(CondField::NE, OperandType::CondField));
    auto& inst824 = ctx.newInst(Select_FPR)
                        .setOperand<0>(op816)
                        .setOperand<1>(op817)
                        .setOperand<2>(op818)
                        .setOperand<3>(op822)
                        .setOperand<4>(op823);
    ctx.replaceOperand(ctx.getInstDef(inst811), ctx.getInstDef(inst824));
    ctx.removeInst(inst811);
    return true;
}

static bool matchAndSelectPattern716(MIRInst& inst716, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op717;
    MIROperand op718;
    MIROperand op719;
    MIROperand op720;
    if(!matchInstICmp(inst716, op717, op718, op719, op720))
        return false;
    MIROperand op721;
    if(!(isCompareOp(op720, CompareOp::ICmpEqual) && buildSub(ctx, op718, op719, op721)))
        return false;
    // Select
    auto op722 = (op717);
    auto op723 = (getVRegAs(ctx, op717));
    auto op724 = (op721);
    auto& inst725 = ctx.newInst(CLZ).setOperand<0>(op723).setOperand<1>(op724);
    auto& op725 = ctx.getInstDef(inst725);
    auto op726 = (MIROperand::asImm(5, OperandType::Int32));
    auto& inst727 = ctx.newInst(LSR).setOperand<0>(op722).setOperand<1>(op725).setOperand<2>(op726);
    ctx.replaceOperand(ctx.getInstDef(inst716), ctx.getInstDef(inst727));
    ctx.removeInst(inst716);
    return true;
}

static bool matchAndSelectPattern728(MIRInst& inst728, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op729;
    MIROperand op730;
    MIROperand op731;
    MIROperand op732;
    if(!matchInstICmp(inst728, op729, op730, op731, op732))
        return false;
    if(!(isCompareOp(op732, CompareOp::ICmpSignedGreaterThan) && isOperandIReg(op730) && isNegativeOne(op731)))
        return false;
    // Select
    auto op733 = (op729);
    auto op734 = (getVRegAs(ctx, op729));
    auto op735 = (op730);
    auto& inst736 = ctx.newInst(MVN).setOperand<0>(op734).setOperand<1>(op735);
    auto& op736 = ctx.getInstDef(inst736);
    auto op737 = (MIROperand::asImm(31, OperandType::Int32));
    auto& inst738 = ctx.newInst(LSR).setOperand<0>(op733).setOperand<1>(op736).setOperand<2>(op737);
    ctx.replaceOperand(ctx.getInstDef(inst728), ctx.getInstDef(inst738));
    ctx.removeInst(inst728);
    return true;
}

static bool matchAndSelectPattern739(MIRInst& inst739, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstICmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op740;
    MIROperand op741;
    MIROperand op742;
    MIROperand op743;
    if(!matchInstICmp(inst739, op740, op741, op742, op743))
        return false;
    MIROperand op744;
    MIROperand op745;
    if(!(isOperandIReg(op741) && selectCompareOp2(op742, op744, op745)))
        return false;
    // Select
    auto op746 = (op740);
    auto op747 = (op741);
    auto op748 = (op744);
    auto op749 = (getCC());
    auto& inst750 = ctx.newInst(getCompareOpcode((op745).imm())).setOperand<0>(op747).setOperand<1>(op748).setOperand<2>(op749);
    auto& op750 = ctx.getInstDef(inst750);
    auto op751 = (getCondFieldICmp(op743));
    auto& inst752 = ctx.newInst(NZCVFlag2GPR).setOperand<0>(op746).setOperand<1>(op750).setOperand<2>(op751);
    ctx.replaceOperand(ctx.getInstDef(inst739), ctx.getInstDef(inst752));
    ctx.removeInst(inst739);
    return true;
}

static bool matchAndSelectPattern753(MIRInst& inst753, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFCmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op754;
    MIROperand op755;
    MIROperand op756;
    MIROperand op757;
    if(!matchInstFCmp(inst753, op754, op755, op756, op757))
        return false;
    auto instptr756 = ctx.lookupDef(op756);
    if(!instptr756)
        return false;
    auto& inst756 = *instptr756;
    MIROperand op758;
    MIROperand op759;
    if(!matchVMOV_GPR2FPR(inst756, op758, op759))
        return false;
    auto instptr759 = ctx.lookupDef(op759);
    if(!instptr759)
        return false;
    auto& inst759 = *instptr759;
    MIROperand op760;
    MIROperand op761;
    if(!matchInstLoadImm(inst759, op760, op761))
        return false;
    if(!(isOperandFPR(op755) && isZero(op761)))
        return false;
    // Select
    auto op762 = (op754);
    auto op763 = (getCC());
    auto op764 = (op755);
    auto op765 = (getFCC());
    auto op766 = (MIROperand::asImm(0, OperandType::Float32));
    auto& inst767 = ctx.newInst(VCMP_F32_WithZero).setOperand<0>(op764).setOperand<1>(op766).setOperand<2>(op765);
    auto& op767 = ctx.getInstDef(inst767);
    auto& inst768 = ctx.newInst(TRANSFER_FPSCR_FLAG).setOperand<0>(op763).setOperand<1>(op767);
    auto& op768 = ctx.getInstDef(inst768);
    auto op769 = (getCondFieldFCmp(op757));
    auto& inst770 = ctx.newInst(NZCVFlag2GPR).setOperand<0>(op762).setOperand<1>(op768).setOperand<2>(op769);
    ctx.replaceOperand(ctx.getInstDef(inst753), ctx.getInstDef(inst770));
    ctx.removeInst(inst753);
    return true;
}

static bool matchAndSelectPattern771(MIRInst& inst771, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFCmp;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op772;
    MIROperand op773;
    MIROperand op774;
    MIROperand op775;
    if(!matchInstFCmp(inst771, op772, op773, op774, op775))
        return false;
    if(!(isOperandFPR(op773) && isOperandFPR(op774)))
        return false;
    // Select
    auto op776 = (op772);
    auto op777 = (getCC());
    auto op778 = (op773);
    auto op779 = (op774);
    auto op780 = (getFCC());
    auto& inst781 = ctx.newInst(VCMP_F32).setOperand<0>(op778).setOperand<1>(op779).setOperand<2>(op780);
    auto& op781 = ctx.getInstDef(inst781);
    auto& inst782 = ctx.newInst(TRANSFER_FPSCR_FLAG).setOperand<0>(op777).setOperand<1>(op781);
    auto& op782 = ctx.getInstDef(inst782);
    auto op783 = (getCondFieldFCmp(op775));
    auto& inst784 = ctx.newInst(NZCVFlag2GPR).setOperand<0>(op776).setOperand<1>(op782).setOperand<2>(op783);
    ctx.replaceOperand(ctx.getInstDef(inst771), ctx.getInstDef(inst784));
    ctx.removeInst(inst771);
    return true;
}

static bool matchAndSelectPattern825(MIRInst& inst825, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoad;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op826;
    MIROperand op827;
    MIROperand op828;
    if(!matchInstLoad(inst825, op826, op827, op828))
        return false;
    MIROperand op829;
    MIROperand op830;
    MIROperand op831;
    if(!(isOperandIReg(op826) && selectFusedAddrOffset(op827, ctx, op826, op829, op830, op831)))
        return false;
    // Select
    auto op832 = (op826);
    auto op833 = (op829);
    auto op834 = (op830);
    auto op835 = (op831);
    auto& inst836 = ctx.newInst(getFusedLoadOpcode(op826))
                        .setOperand<0>(op832)
                        .setOperand<1>(op833)
                        .setOperand<2>(op834)
                        .setOperand<3>(op835);
    ctx.replaceOperand(ctx.getInstDef(inst825), ctx.getInstDef(inst836));
    ctx.removeInst(inst825);
    return true;
}

static bool matchAndSelectPattern837(MIRInst& inst837, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstLoad;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op838;
    MIROperand op839;
    MIROperand op840;
    if(!matchInstLoad(inst837, op838, op839, op840))
        return false;
    MIROperand op841;
    MIROperand op842;
    if(!(selectAddrOffset(op839, ctx, op841, op842, getLoadOpcode(op838), (op838).type())))
        return false;
    // Select
    auto op843 = (op838);
    auto op844 = (op841);
    auto op845 = (op842);
    auto& inst846 = ctx.newInst(getLoadOpcode(op838)).setOperand<0>(op843).setOperand<1>(op844).setOperand<2>(op845);
    ctx.replaceOperand(ctx.getInstDef(inst837), ctx.getInstDef(inst846));
    ctx.removeInst(inst837);
    return true;
}

static bool matchAndSelectPattern859(MIRInst& inst859, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstStore;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op860;
    MIROperand op861;
    MIROperand op862;
    if(!matchInstStore(inst859, op860, op861, op862))
        return false;
    auto instptr861 = ctx.lookupDef(op861);
    if(!instptr861)
        return false;
    auto& inst861 = *instptr861;
    MIROperand op863;
    MIROperand op864;
    if(!matchInstTrunc(inst861, op863, op864))
        return false;
    if(!(ctx.isSafeToUse(op864, op863)))
        return false;
    MIROperand op865;
    MIROperand op866;
    MIROperand op867;
    if(!(isOperandIReg(op864) && selectFusedAddrOffset(op860, ctx, op863, op865, op866, op867)))
        return false;
    // Select
    auto op868 = (op864);
    auto op869 = (op865);
    auto op870 = (op866);
    auto op871 = (op867);
    auto& inst872 = ctx.newInst(getFusedStoreOpcode(op863))
                        .setOperand<0>(op868)
                        .setOperand<1>(op869)
                        .setOperand<2>(op870)
                        .setOperand<3>(op871);
    CMMC_UNUSED(inst872);
    ctx.removeInst(inst859);
    return true;
}

static bool matchAndSelectPattern873(MIRInst& inst873, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstStore;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op874;
    MIROperand op875;
    MIROperand op876;
    if(!matchInstStore(inst873, op874, op875, op876))
        return false;
    MIROperand op877;
    MIROperand op878;
    MIROperand op879;
    if(!(isOperandIReg(op875) && selectFusedAddrOffset(op874, ctx, op875, op877, op878, op879)))
        return false;
    // Select
    auto op880 = (op875);
    auto op881 = (op877);
    auto op882 = (op878);
    auto op883 = (op879);
    auto& inst884 = ctx.newInst(getFusedStoreOpcode(op875))
                        .setOperand<0>(op880)
                        .setOperand<1>(op881)
                        .setOperand<2>(op882)
                        .setOperand<3>(op883);
    CMMC_UNUSED(inst884);
    ctx.removeInst(inst873);
    return true;
}

static bool matchAndSelectPattern885(MIRInst& inst885, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstStore;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op886;
    MIROperand op887;
    MIROperand op888;
    if(!matchInstStore(inst885, op886, op887, op888))
        return false;
    auto instptr887 = ctx.lookupDef(op887);
    if(!instptr887)
        return false;
    auto& inst887 = *instptr887;
    MIROperand op889;
    MIROperand op890;
    if(!matchInstTrunc(inst887, op889, op890))
        return false;
    if(!(ctx.isSafeToUse(op890, op889)))
        return false;
    MIROperand op891;
    MIROperand op892;
    if(!(isOperandVRegOrISAReg(op890) && selectAddrOffset(op886, ctx, op891, op892, getStoreOpcode(op889), (op889).type())))
        return false;
    // Select
    auto op893 = (op890);
    auto op894 = (op891);
    auto op895 = (op892);
    auto& inst896 = ctx.newInst(getStoreOpcode(op889)).setOperand<0>(op893).setOperand<1>(op894).setOperand<2>(op895);
    CMMC_UNUSED(inst896);
    ctx.removeInst(inst885);
    return true;
}

static bool matchAndSelectPattern897(MIRInst& inst897, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstStore;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op898;
    MIROperand op899;
    MIROperand op900;
    if(!matchInstStore(inst897, op898, op899, op900))
        return false;
    MIROperand op901;
    MIROperand op902;
    if(!(isOperandVRegOrISAReg(op899) && selectAddrOffset(op898, ctx, op901, op902, getStoreOpcode(op899), (op899).type())))
        return false;
    // Select
    auto op903 = (op899);
    auto op904 = (op901);
    auto op905 = (op902);
    auto& inst906 = ctx.newInst(getStoreOpcode(op899)).setOperand<0>(op903).setOperand<1>(op904).setOperand<2>(op905);
    CMMC_UNUSED(inst906);
    ctx.removeInst(inst897);
    return true;
}

static bool matchAndSelectPattern907(MIRInst& inst907, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstUnreachable;
    CMMC_UNUSED(rootOpcode);
    // Match
    if(!matchInstUnreachable(inst907))
        return false;
    // Select
    auto& inst908 = ctx.newInst(UNIMP);
    CMMC_UNUSED(inst908);
    ctx.removeInst(inst907);
    return true;
}

static bool matchAndSelectPattern909(MIRInst& inst909, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstAbs;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op910;
    MIROperand op911;
    if(!matchInstAbs(inst909, op910, op911))
        return false;
    if(!(isOperandIReg(op911)))
        return false;
    // Select
    auto op912 = (op910);
    auto op913 = (MIROperand::asImm(CondField::MI, OperandType::CondField));
    auto op914 = (op911);
    auto op915 = (getZero(op911));
    auto op916 = (op911);
    auto op917 = (MIROperand::asImm(RSB_Cond, OperandType::Special));
    auto op918 = (op911);
    auto op919 = (getZero(op911));
    auto op920 = (getCC());
    auto& inst921 = ctx.newInst(CMP).setOperand<0>(op918).setOperand<1>(op919).setOperand<2>(op920);
    auto& op921 = ctx.getInstDef(inst921);
    auto& inst922 = ctx.newInst(PseudoIntOpWithOp2_Cond)
                        .setOperand<0>(op913)
                        .setOperand<1>(op912)
                        .setOperand<2>(op914)
                        .setOperand<3>(op915)
                        .setOperand<4>(op916)
                        .setOperand<5>(op917)
                        .setOperand<6>(op921);
    ctx.replaceOperand(ctx.getInstDef(inst909), ctx.getInstDef(inst922));
    ctx.removeInst(inst909);
    return true;
}

static bool matchAndSelectPattern923(MIRInst& inst923, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = RSB;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op924;
    MIROperand op925;
    MIROperand op926;
    if(!matchRSB(inst923, op924, op925, op926))
        return false;
    auto instptr925 = ctx.lookupDef(op925);
    if(!instptr925)
        return false;
    auto& inst925 = *instptr925;
    MIROperand op927;
    MIROperand op928;
    MIROperand op929;
    MIROperand op930;
    MIROperand op931;
    if(!matchRSB_Fused(inst925, op927, op928, op929, op930, op931))
        return false;
    if(!(ctx.hasOneUse(op927)))
        return false;
    if(!(isZero(op926)))
        return false;
    // Select
    auto op932 = (op924);
    auto op933 = (op928);
    auto op934 = (op929);
    auto op935 = (op930);
    auto op936 = (op931);
    auto& inst937 =
        ctx.newInst(SUB_Fused).setOperand<0>(op932).setOperand<1>(op933).setOperand<2>(op934).setOperand<3>(op935).setOperand<4>(
            op936);
    ctx.replaceOperand(ctx.getInstDef(inst923), ctx.getInstDef(inst937));
    ctx.removeInst(inst923);
    return true;
}

static bool matchAndSelectPattern938(MIRInst& inst938, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMax;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op939;
    MIROperand op940;
    MIROperand op941;
    if(!matchInstSMax(inst938, op939, op940, op941))
        return false;
    auto instptr940 = ctx.lookupDef(op940);
    if(!instptr940)
        return false;
    auto& inst940 = *instptr940;
    MIROperand op942;
    MIROperand op943;
    MIROperand op944;
    if(!matchInstSMin(inst940, op942, op943, op944))
        return false;
    MIROperand op945;
    if(!(isOperandIReg(op943) && isZero(op941) && selectUnsignedRange(op944, op945)))
        return false;
    // Select
    auto op946 = (op939);
    auto op947 = (op945);
    auto op948 = (op943);
    auto& inst949 = ctx.newInst(USAT).setOperand<0>(op946).setOperand<1>(op947).setOperand<2>(op948);
    ctx.replaceOperand(ctx.getInstDef(inst938), ctx.getInstDef(inst949));
    ctx.removeInst(inst938);
    return true;
}

static bool matchAndSelectPattern962(MIRInst& inst962, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMax;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op963;
    MIROperand op964;
    MIROperand op965;
    if(!matchInstSMax(inst962, op963, op964, op965))
        return false;
    auto instptr964 = ctx.lookupDef(op964);
    if(!instptr964)
        return false;
    auto& inst964 = *instptr964;
    MIROperand op966;
    MIROperand op967;
    MIROperand op968;
    if(!matchInstSMin(inst964, op966, op967, op968))
        return false;
    MIROperand op969;
    if(!(isOperandIReg(op967) && selectSignedRange(op965, op968, op969)))
        return false;
    // Select
    auto op970 = (op963);
    auto op971 = (op969);
    auto op972 = (op967);
    auto& inst973 = ctx.newInst(SSAT).setOperand<0>(op970).setOperand<1>(op971).setOperand<2>(op972);
    ctx.replaceOperand(ctx.getInstDef(inst962), ctx.getInstDef(inst973));
    ctx.removeInst(inst962);
    return true;
}

static bool matchAndSelectPattern986(MIRInst& inst986, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMax;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op987;
    MIROperand op988;
    MIROperand op989;
    if(!matchInstSMax(inst986, op987, op988, op989))
        return false;
    if(!(isOperandIReg(op988) && isZero(op989)))
        return false;
    // Select
    auto op990 = (op987);
    auto op991 = (op988);
    auto op992 = (op988);
    auto op993 = (MIROperand::asImm(ASR, OperandType::ShiftType));
    auto op994 = (MIROperand::asImm(31, OperandType::Int32));
    auto& inst995 =
        ctx.newInst(BIC_Fused).setOperand<0>(op990).setOperand<1>(op991).setOperand<2>(op992).setOperand<3>(op993).setOperand<4>(
            op994);
    ctx.replaceOperand(ctx.getInstDef(inst986), ctx.getInstDef(inst995));
    ctx.removeInst(inst986);
    return true;
}

static bool matchAndSelectPattern996(MIRInst& inst996, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMax;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op997;
    MIROperand op998;
    MIROperand op999;
    if(!matchInstSMax(inst996, op997, op998, op999))
        return false;
    if(!(isOperandIReg(op998) && isOperandOp2(op999)))
        return false;
    // Select
    auto op1000 = (op997);
    auto op1001 = (op998);
    auto op1002 = (op999);
    auto op1003 = (op998);
    auto op1004 = (op999);
    auto op1005 = (getCC());
    auto& inst1006 = ctx.newInst(CMP).setOperand<0>(op1003).setOperand<1>(op1004).setOperand<2>(op1005);
    auto& op1006 = ctx.getInstDef(inst1006);
    auto& inst1007 =
        ctx.newInst(PseudoSMax).setOperand<0>(op1000).setOperand<1>(op1001).setOperand<2>(op1002).setOperand<3>(op1006);
    ctx.replaceOperand(ctx.getInstDef(inst996), ctx.getInstDef(inst1007));
    ctx.removeInst(inst996);
    return true;
}

static bool matchAndSelectPattern1020(MIRInst& inst1020, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMax;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1021;
    MIROperand op1022;
    MIROperand op1023;
    if(!matchInstSMax(inst1020, op1021, op1022, op1023))
        return false;
    MIROperand op1024;
    if(!(isOperandIReg(op1022) && selectInvertedOp2Constant(op1023, op1024)))
        return false;
    // Select
    auto op1025 = (op1021);
    auto op1026 = (op1022);
    auto op1027 = (op1024);
    auto op1028 = (op1022);
    auto op1029 = (op1024);
    auto op1030 = (getCC());
    auto& inst1031 = ctx.newInst(CMN).setOperand<0>(op1028).setOperand<1>(op1029).setOperand<2>(op1030);
    auto& op1031 = ctx.getInstDef(inst1031);
    auto& inst1032 =
        ctx.newInst(PseudoSMax_Inverted).setOperand<0>(op1025).setOperand<1>(op1026).setOperand<2>(op1027).setOperand<3>(op1031);
    ctx.replaceOperand(ctx.getInstDef(inst1020), ctx.getInstDef(inst1032));
    ctx.removeInst(inst1020);
    return true;
}

static bool matchAndSelectPattern950(MIRInst& inst950, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMin;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op951;
    MIROperand op952;
    MIROperand op953;
    if(!matchInstSMin(inst950, op951, op952, op953))
        return false;
    auto instptr952 = ctx.lookupDef(op952);
    if(!instptr952)
        return false;
    auto& inst952 = *instptr952;
    MIROperand op954;
    MIROperand op955;
    MIROperand op956;
    if(!matchInstSMax(inst952, op954, op955, op956))
        return false;
    MIROperand op957;
    if(!(isOperandIReg(op955) && isZero(op956) && selectUnsignedRange(op953, op957)))
        return false;
    // Select
    auto op958 = (op951);
    auto op959 = (op957);
    auto op960 = (op955);
    auto& inst961 = ctx.newInst(USAT).setOperand<0>(op958).setOperand<1>(op959).setOperand<2>(op960);
    ctx.replaceOperand(ctx.getInstDef(inst950), ctx.getInstDef(inst961));
    ctx.removeInst(inst950);
    return true;
}

static bool matchAndSelectPattern974(MIRInst& inst974, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMin;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op975;
    MIROperand op976;
    MIROperand op977;
    if(!matchInstSMin(inst974, op975, op976, op977))
        return false;
    auto instptr976 = ctx.lookupDef(op976);
    if(!instptr976)
        return false;
    auto& inst976 = *instptr976;
    MIROperand op978;
    MIROperand op979;
    MIROperand op980;
    if(!matchInstSMax(inst976, op978, op979, op980))
        return false;
    MIROperand op981;
    if(!(isOperandIReg(op979) && selectSignedRange(op980, op977, op981)))
        return false;
    // Select
    auto op982 = (op975);
    auto op983 = (op981);
    auto op984 = (op979);
    auto& inst985 = ctx.newInst(SSAT).setOperand<0>(op982).setOperand<1>(op983).setOperand<2>(op984);
    ctx.replaceOperand(ctx.getInstDef(inst974), ctx.getInstDef(inst985));
    ctx.removeInst(inst974);
    return true;
}

static bool matchAndSelectPattern1008(MIRInst& inst1008, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMin;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1009;
    MIROperand op1010;
    MIROperand op1011;
    if(!matchInstSMin(inst1008, op1009, op1010, op1011))
        return false;
    if(!(isOperandIReg(op1010) && isOperandOp2(op1011)))
        return false;
    // Select
    auto op1012 = (op1009);
    auto op1013 = (op1010);
    auto op1014 = (op1011);
    auto op1015 = (op1010);
    auto op1016 = (op1011);
    auto op1017 = (getCC());
    auto& inst1018 = ctx.newInst(CMP).setOperand<0>(op1015).setOperand<1>(op1016).setOperand<2>(op1017);
    auto& op1018 = ctx.getInstDef(inst1018);
    auto& inst1019 =
        ctx.newInst(PseudoSMin).setOperand<0>(op1012).setOperand<1>(op1013).setOperand<2>(op1014).setOperand<3>(op1018);
    ctx.replaceOperand(ctx.getInstDef(inst1008), ctx.getInstDef(inst1019));
    ctx.removeInst(inst1008);
    return true;
}

static bool matchAndSelectPattern1033(MIRInst& inst1033, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstSMin;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1034;
    MIROperand op1035;
    MIROperand op1036;
    if(!matchInstSMin(inst1033, op1034, op1035, op1036))
        return false;
    MIROperand op1037;
    if(!(isOperandIReg(op1035) && selectInvertedOp2Constant(op1036, op1037)))
        return false;
    // Select
    auto op1038 = (op1034);
    auto op1039 = (op1035);
    auto op1040 = (op1037);
    auto op1041 = (op1035);
    auto op1042 = (op1037);
    auto op1043 = (getCC());
    auto& inst1044 = ctx.newInst(CMN).setOperand<0>(op1041).setOperand<1>(op1042).setOperand<2>(op1043);
    auto& op1044 = ctx.getInstDef(inst1044);
    auto& inst1045 =
        ctx.newInst(PseudoSMin_Inverted).setOperand<0>(op1038).setOperand<1>(op1039).setOperand<2>(op1040).setOperand<3>(op1044);
    ctx.replaceOperand(ctx.getInstDef(inst1033), ctx.getInstDef(inst1045));
    ctx.removeInst(inst1033);
    return true;
}

static bool matchAndSelectPattern1046(MIRInst& inst1046, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstFAbs;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1047;
    MIROperand op1048;
    if(!matchInstFAbs(inst1046, op1047, op1048))
        return false;
    // Select
    auto op1049 = (op1047);
    auto op1050 = (op1048);
    auto& inst1051 = ctx.newInst(VABS_F32).setOperand<0>(op1049).setOperand<1>(op1050);
    ctx.replaceOperand(ctx.getInstDef(inst1046), ctx.getInstDef(inst1051));
    ctx.removeInst(inst1046);
    return true;
}

static bool matchAndSelectPattern1052(MIRInst& inst1052, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = ADD;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1053;
    MIROperand op1054;
    MIROperand op1055;
    if(!matchADD(inst1052, op1053, op1054, op1055))
        return false;
    auto instptr1055 = ctx.lookupDef(op1055);
    if(!instptr1055)
        return false;
    auto& inst1055 = *instptr1055;
    MIROperand op1056;
    MIROperand op1057;
    MIROperand op1058;
    MIROperand op1059;
    MIROperand op1060;
    if(!matchSelect_GPR(inst1055, op1056, op1057, op1058, op1059, op1060))
        return false;
    if(!(isZero(op1058) && ctx.hasOneUse(op1056) && ctx.isSafeToUse(op1059, op1056)))
        return false;
    // Select
    auto op1061 = (op1053);
    auto op1062 = (op1054);
    auto op1063 = (op1057);
    auto op1064 = (op1059);
    auto op1065 = (op1060);
    auto op1066 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1067 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1061)
                         .setOperand<1>(op1062)
                         .setOperand<2>(op1063)
                         .setOperand<3>(op1064)
                         .setOperand<4>(op1065)
                         .setOperand<5>(op1066);
    ctx.replaceOperand(ctx.getInstDef(inst1052), ctx.getInstDef(inst1067));
    ctx.removeInst(inst1052);
    return true;
}

static bool matchAndSelectPattern1116(MIRInst& inst1116, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = ADD;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1117;
    MIROperand op1118;
    MIROperand op1119;
    if(!matchADD(inst1116, op1117, op1118, op1119))
        return false;
    auto instptr1119 = ctx.lookupDef(op1119);
    if(!instptr1119)
        return false;
    auto& inst1119 = *instptr1119;
    MIROperand op1120;
    MIROperand op1121;
    MIROperand op1122;
    MIROperand op1123;
    MIROperand op1124;
    if(!matchSelect_GPR(inst1119, op1120, op1121, op1122, op1123, op1124))
        return false;
    if(!(isZero(op1121) && ctx.hasOneUse(op1120) && ctx.isSafeToUse(op1123, op1120)))
        return false;
    // Select
    auto op1125 = (op1117);
    auto op1126 = (op1118);
    auto op1127 = (op1122);
    auto op1128 = (op1123);
    auto op1129 = (getInvertedCondField(op1124));
    auto op1130 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1131 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1125)
                         .setOperand<1>(op1126)
                         .setOperand<2>(op1127)
                         .setOperand<3>(op1128)
                         .setOperand<4>(op1129)
                         .setOperand<5>(op1130);
    ctx.replaceOperand(ctx.getInstDef(inst1116), ctx.getInstDef(inst1131));
    ctx.removeInst(inst1116);
    return true;
}

static bool matchAndSelectPattern1180(MIRInst& inst1180, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = ADD;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1181;
    MIROperand op1182;
    MIROperand op1183;
    if(!matchADD(inst1180, op1181, op1182, op1183))
        return false;
    auto instptr1183 = ctx.lookupDef(op1183);
    if(!instptr1183)
        return false;
    auto& inst1183 = *instptr1183;
    MIROperand op1184;
    MIROperand op1185;
    MIROperand op1186;
    if(!matchNZCVFlag2GPR(inst1183, op1184, op1185, op1186))
        return false;
    if(!(ctx.isSafeToUse(op1185, op1184)))
        return false;
    // Select
    auto op1187 = (op1181);
    auto op1188 = (op1182);
    auto op1189 = (MIROperand::asImm(1, OperandType::Int32));
    auto op1190 = (op1185);
    auto op1191 = (op1186);
    auto op1192 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1193 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1187)
                         .setOperand<1>(op1188)
                         .setOperand<2>(op1189)
                         .setOperand<3>(op1190)
                         .setOperand<4>(op1191)
                         .setOperand<5>(op1192);
    ctx.replaceOperand(ctx.getInstDef(inst1180), ctx.getInstDef(inst1193));
    ctx.removeInst(inst1180);
    return true;
}

static bool matchAndSelectPattern1068(MIRInst& inst1068, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SUB;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1069;
    MIROperand op1070;
    MIROperand op1071;
    if(!matchSUB(inst1068, op1069, op1070, op1071))
        return false;
    auto instptr1071 = ctx.lookupDef(op1071);
    if(!instptr1071)
        return false;
    auto& inst1071 = *instptr1071;
    MIROperand op1072;
    MIROperand op1073;
    MIROperand op1074;
    MIROperand op1075;
    MIROperand op1076;
    if(!matchSelect_GPR(inst1071, op1072, op1073, op1074, op1075, op1076))
        return false;
    if(!(isZero(op1074) && ctx.hasOneUse(op1072) && ctx.isSafeToUse(op1075, op1072)))
        return false;
    // Select
    auto op1077 = (op1069);
    auto op1078 = (op1070);
    auto op1079 = (op1073);
    auto op1080 = (op1075);
    auto op1081 = (op1076);
    auto op1082 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1083 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1077)
                         .setOperand<1>(op1078)
                         .setOperand<2>(op1079)
                         .setOperand<3>(op1080)
                         .setOperand<4>(op1081)
                         .setOperand<5>(op1082);
    ctx.replaceOperand(ctx.getInstDef(inst1068), ctx.getInstDef(inst1083));
    ctx.removeInst(inst1068);
    return true;
}

static bool matchAndSelectPattern1132(MIRInst& inst1132, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SUB;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1133;
    MIROperand op1134;
    MIROperand op1135;
    if(!matchSUB(inst1132, op1133, op1134, op1135))
        return false;
    auto instptr1135 = ctx.lookupDef(op1135);
    if(!instptr1135)
        return false;
    auto& inst1135 = *instptr1135;
    MIROperand op1136;
    MIROperand op1137;
    MIROperand op1138;
    MIROperand op1139;
    MIROperand op1140;
    if(!matchSelect_GPR(inst1135, op1136, op1137, op1138, op1139, op1140))
        return false;
    if(!(isZero(op1137) && ctx.hasOneUse(op1136) && ctx.isSafeToUse(op1139, op1136)))
        return false;
    // Select
    auto op1141 = (op1133);
    auto op1142 = (op1134);
    auto op1143 = (op1138);
    auto op1144 = (op1139);
    auto op1145 = (getInvertedCondField(op1140));
    auto op1146 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1147 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1141)
                         .setOperand<1>(op1142)
                         .setOperand<2>(op1143)
                         .setOperand<3>(op1144)
                         .setOperand<4>(op1145)
                         .setOperand<5>(op1146);
    ctx.replaceOperand(ctx.getInstDef(inst1132), ctx.getInstDef(inst1147));
    ctx.removeInst(inst1132);
    return true;
}

static bool matchAndSelectPattern1194(MIRInst& inst1194, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = SUB;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1195;
    MIROperand op1196;
    MIROperand op1197;
    if(!matchSUB(inst1194, op1195, op1196, op1197))
        return false;
    auto instptr1197 = ctx.lookupDef(op1197);
    if(!instptr1197)
        return false;
    auto& inst1197 = *instptr1197;
    MIROperand op1198;
    MIROperand op1199;
    MIROperand op1200;
    if(!matchNZCVFlag2GPR(inst1197, op1198, op1199, op1200))
        return false;
    if(!(ctx.isSafeToUse(op1199, op1198)))
        return false;
    // Select
    auto op1201 = (op1195);
    auto op1202 = (op1196);
    auto op1203 = (MIROperand::asImm(1, OperandType::Int32));
    auto op1204 = (op1199);
    auto op1205 = (op1200);
    auto op1206 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1207 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1201)
                         .setOperand<1>(op1202)
                         .setOperand<2>(op1203)
                         .setOperand<3>(op1204)
                         .setOperand<4>(op1205)
                         .setOperand<5>(op1206);
    ctx.replaceOperand(ctx.getInstDef(inst1194), ctx.getInstDef(inst1207));
    ctx.removeInst(inst1194);
    return true;
}

static bool matchAndSelectPattern1084(MIRInst& inst1084, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = ORR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1085;
    MIROperand op1086;
    MIROperand op1087;
    if(!matchORR(inst1084, op1085, op1086, op1087))
        return false;
    auto instptr1087 = ctx.lookupDef(op1087);
    if(!instptr1087)
        return false;
    auto& inst1087 = *instptr1087;
    MIROperand op1088;
    MIROperand op1089;
    MIROperand op1090;
    MIROperand op1091;
    MIROperand op1092;
    if(!matchSelect_GPR(inst1087, op1088, op1089, op1090, op1091, op1092))
        return false;
    if(!(isZero(op1090) && ctx.hasOneUse(op1088) && ctx.isSafeToUse(op1091, op1088)))
        return false;
    // Select
    auto op1093 = (op1085);
    auto op1094 = (op1086);
    auto op1095 = (op1089);
    auto op1096 = (op1091);
    auto op1097 = (op1092);
    auto op1098 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1099 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1093)
                         .setOperand<1>(op1094)
                         .setOperand<2>(op1095)
                         .setOperand<3>(op1096)
                         .setOperand<4>(op1097)
                         .setOperand<5>(op1098);
    ctx.replaceOperand(ctx.getInstDef(inst1084), ctx.getInstDef(inst1099));
    ctx.removeInst(inst1084);
    return true;
}

static bool matchAndSelectPattern1148(MIRInst& inst1148, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = ORR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1149;
    MIROperand op1150;
    MIROperand op1151;
    if(!matchORR(inst1148, op1149, op1150, op1151))
        return false;
    auto instptr1151 = ctx.lookupDef(op1151);
    if(!instptr1151)
        return false;
    auto& inst1151 = *instptr1151;
    MIROperand op1152;
    MIROperand op1153;
    MIROperand op1154;
    MIROperand op1155;
    MIROperand op1156;
    if(!matchSelect_GPR(inst1151, op1152, op1153, op1154, op1155, op1156))
        return false;
    if(!(isZero(op1153) && ctx.hasOneUse(op1152) && ctx.isSafeToUse(op1155, op1152)))
        return false;
    // Select
    auto op1157 = (op1149);
    auto op1158 = (op1150);
    auto op1159 = (op1154);
    auto op1160 = (op1155);
    auto op1161 = (getInvertedCondField(op1156));
    auto op1162 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1163 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1157)
                         .setOperand<1>(op1158)
                         .setOperand<2>(op1159)
                         .setOperand<3>(op1160)
                         .setOperand<4>(op1161)
                         .setOperand<5>(op1162);
    ctx.replaceOperand(ctx.getInstDef(inst1148), ctx.getInstDef(inst1163));
    ctx.removeInst(inst1148);
    return true;
}

static bool matchAndSelectPattern1208(MIRInst& inst1208, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = ORR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1209;
    MIROperand op1210;
    MIROperand op1211;
    if(!matchORR(inst1208, op1209, op1210, op1211))
        return false;
    auto instptr1211 = ctx.lookupDef(op1211);
    if(!instptr1211)
        return false;
    auto& inst1211 = *instptr1211;
    MIROperand op1212;
    MIROperand op1213;
    MIROperand op1214;
    if(!matchNZCVFlag2GPR(inst1211, op1212, op1213, op1214))
        return false;
    if(!(ctx.isSafeToUse(op1213, op1212)))
        return false;
    // Select
    auto op1215 = (op1209);
    auto op1216 = (op1210);
    auto op1217 = (MIROperand::asImm(1, OperandType::Int32));
    auto op1218 = (op1213);
    auto op1219 = (op1214);
    auto op1220 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1221 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1215)
                         .setOperand<1>(op1216)
                         .setOperand<2>(op1217)
                         .setOperand<3>(op1218)
                         .setOperand<4>(op1219)
                         .setOperand<5>(op1220);
    ctx.replaceOperand(ctx.getInstDef(inst1208), ctx.getInstDef(inst1221));
    ctx.removeInst(inst1208);
    return true;
}

static bool matchAndSelectPattern1100(MIRInst& inst1100, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = EOR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1101;
    MIROperand op1102;
    MIROperand op1103;
    if(!matchEOR(inst1100, op1101, op1102, op1103))
        return false;
    auto instptr1103 = ctx.lookupDef(op1103);
    if(!instptr1103)
        return false;
    auto& inst1103 = *instptr1103;
    MIROperand op1104;
    MIROperand op1105;
    MIROperand op1106;
    MIROperand op1107;
    MIROperand op1108;
    if(!matchSelect_GPR(inst1103, op1104, op1105, op1106, op1107, op1108))
        return false;
    if(!(isZero(op1106) && ctx.hasOneUse(op1104) && ctx.isSafeToUse(op1107, op1104)))
        return false;
    // Select
    auto op1109 = (op1101);
    auto op1110 = (op1102);
    auto op1111 = (op1105);
    auto op1112 = (op1107);
    auto op1113 = (op1108);
    auto op1114 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1115 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1109)
                         .setOperand<1>(op1110)
                         .setOperand<2>(op1111)
                         .setOperand<3>(op1112)
                         .setOperand<4>(op1113)
                         .setOperand<5>(op1114);
    ctx.replaceOperand(ctx.getInstDef(inst1100), ctx.getInstDef(inst1115));
    ctx.removeInst(inst1100);
    return true;
}

static bool matchAndSelectPattern1164(MIRInst& inst1164, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = EOR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1165;
    MIROperand op1166;
    MIROperand op1167;
    if(!matchEOR(inst1164, op1165, op1166, op1167))
        return false;
    auto instptr1167 = ctx.lookupDef(op1167);
    if(!instptr1167)
        return false;
    auto& inst1167 = *instptr1167;
    MIROperand op1168;
    MIROperand op1169;
    MIROperand op1170;
    MIROperand op1171;
    MIROperand op1172;
    if(!matchSelect_GPR(inst1167, op1168, op1169, op1170, op1171, op1172))
        return false;
    if(!(isZero(op1169) && ctx.hasOneUse(op1168) && ctx.isSafeToUse(op1171, op1168)))
        return false;
    // Select
    auto op1173 = (op1165);
    auto op1174 = (op1166);
    auto op1175 = (op1170);
    auto op1176 = (op1171);
    auto op1177 = (getInvertedCondField(op1172));
    auto op1178 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1179 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1173)
                         .setOperand<1>(op1174)
                         .setOperand<2>(op1175)
                         .setOperand<3>(op1176)
                         .setOperand<4>(op1177)
                         .setOperand<5>(op1178);
    ctx.replaceOperand(ctx.getInstDef(inst1164), ctx.getInstDef(inst1179));
    ctx.removeInst(inst1164);
    return true;
}

static bool matchAndSelectPattern1222(MIRInst& inst1222, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = EOR;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1223;
    MIROperand op1224;
    MIROperand op1225;
    if(!matchEOR(inst1222, op1223, op1224, op1225))
        return false;
    auto instptr1225 = ctx.lookupDef(op1225);
    if(!instptr1225)
        return false;
    auto& inst1225 = *instptr1225;
    MIROperand op1226;
    MIROperand op1227;
    MIROperand op1228;
    if(!matchNZCVFlag2GPR(inst1225, op1226, op1227, op1228))
        return false;
    if(!(ctx.isSafeToUse(op1227, op1226)))
        return false;
    // Select
    auto op1229 = (op1223);
    auto op1230 = (op1224);
    auto op1231 = (MIROperand::asImm(1, OperandType::Int32));
    auto op1232 = (op1227);
    auto op1233 = (op1228);
    auto op1234 = (MIROperand::asImm(rootOpcode, OperandType::Special));
    auto& inst1235 = ctx.newInst(CondArith_GPR)
                         .setOperand<0>(op1229)
                         .setOperand<1>(op1230)
                         .setOperand<2>(op1231)
                         .setOperand<3>(op1232)
                         .setOperand<4>(op1233)
                         .setOperand<5>(op1234);
    ctx.replaceOperand(ctx.getInstDef(inst1222), ctx.getInstDef(inst1235));
    ctx.removeInst(inst1222);
    return true;
}

static bool matchAndSelectPattern1242(MIRInst& inst1242, ISelContext& ctx) {
    constexpr uint32_t rootOpcode = InstTrunc;
    CMMC_UNUSED(rootOpcode);
    // Match
    MIROperand op1243;
    MIROperand op1244;
    if(!matchInstTrunc(inst1242, op1243, op1244))
        return false;
    if(!(isOperandIReg(op1244)))
        return false;
    // Select
    auto op1245 = (op1243);
    auto op1246 = (op1244);
    auto& inst1247 = ctx.newInst(getSExtOpcode((op1243).type())).setOperand<0>(op1245).setOperand<1>(op1246);
    ctx.replaceOperand(ctx.getInstDef(inst1242), ctx.getInstDef(inst1247));
    ctx.removeInst(inst1242);
    return true;
}

static bool matchAndSelectImpl(MIRInst& inst, ISelContext& ctx) {
    switch(inst.opcode()) {
        case InstLoadImmToReg: {
            if(matchAndSelectPattern1(inst, ctx))
                return true;
            if(matchAndSelectPattern13(inst, ctx))
                return true;
            if(matchAndSelectPattern27(inst, ctx))
                return true;
            break;
        }
        case InstLoadImm: {
            if(matchAndSelectPattern7(inst, ctx))
                return true;
            if(matchAndSelectPattern20(inst, ctx))
                return true;
            if(matchAndSelectPattern34(inst, ctx))
                return true;
            break;
        }
        case InstSub: {
            if(matchAndSelectPattern41(inst, ctx))
                return true;
            if(matchAndSelectPattern71(inst, ctx))
                return true;
            if(matchAndSelectPattern115(inst, ctx))
                return true;
            if(matchAndSelectPattern167(inst, ctx))
                return true;
            if(matchAndSelectPattern188(inst, ctx))
                return true;
            if(matchAndSelectPattern229(inst, ctx))
                return true;
            break;
        }
        case InstAdd: {
            if(matchAndSelectPattern58(inst, ctx))
                return true;
            if(matchAndSelectPattern102(inst, ctx))
                return true;
            if(matchAndSelectPattern180(inst, ctx))
                return true;
            break;
        }
        case InstAnd: {
            if(matchAndSelectPattern84(inst, ctx))
                return true;
            if(matchAndSelectPattern128(inst, ctx))
                return true;
            if(matchAndSelectPattern196(inst, ctx))
                return true;
            if(matchAndSelectPattern220(inst, ctx))
                return true;
            break;
        }
        case InstXor: {
            if(matchAndSelectPattern95(inst, ctx))
                return true;
            if(matchAndSelectPattern154(inst, ctx))
                return true;
            if(matchAndSelectPattern212(inst, ctx))
                return true;
            break;
        }
        case InstOr: {
            if(matchAndSelectPattern141(inst, ctx))
                return true;
            if(matchAndSelectPattern204(inst, ctx))
                return true;
            break;
        }
        case InstMul: {
            if(matchAndSelectPattern237(inst, ctx))
                return true;
            if(matchAndSelectPattern249(inst, ctx))
                return true;
            if(matchAndSelectPattern261(inst, ctx))
                return true;
            if(matchAndSelectPattern273(inst, ctx))
                return true;
            if(matchAndSelectPattern285(inst, ctx))
                return true;
            break;
        }
        case InstSDiv: {
            if(matchAndSelectPattern293(inst, ctx))
                return true;
            if(matchAndSelectPattern309(inst, ctx))
                return true;
            if(matchAndSelectPattern329(inst, ctx))
                return true;
            if(matchAndSelectPattern354(inst, ctx))
                return true;
            if(matchAndSelectPattern372(inst, ctx))
                return true;
            if(matchAndSelectPattern388(inst, ctx))
                return true;
            break;
        }
        case InstUDiv: {
            if(matchAndSelectPattern401(inst, ctx))
                return true;
            break;
        }
        case InstSRem: {
            if(matchAndSelectPattern409(inst, ctx))
                return true;
            if(matchAndSelectPattern430(inst, ctx))
                return true;
            if(matchAndSelectPattern453(inst, ctx))
                return true;
            if(matchAndSelectPattern473(inst, ctx))
                return true;
            break;
        }
        case InstURem: {
            if(matchAndSelectPattern490(inst, ctx))
                return true;
            break;
        }
        case InstShl: {
            if(matchAndSelectPattern502(inst, ctx))
                return true;
            break;
        }
        case InstLShr: {
            if(matchAndSelectPattern510(inst, ctx))
                return true;
            break;
        }
        case InstAShr: {
            if(matchAndSelectPattern518(inst, ctx))
                return true;
            break;
        }
        case InstS2F: {
            if(matchAndSelectPattern526(inst, ctx))
                return true;
            break;
        }
        case InstF2S: {
            if(matchAndSelectPattern534(inst, ctx))
                return true;
            break;
        }
        case InstFAdd: {
            if(matchAndSelectPattern542(inst, ctx))
                return true;
            break;
        }
        case InstFSub: {
            if(matchAndSelectPattern550(inst, ctx))
                return true;
            break;
        }
        case InstFMul: {
            if(matchAndSelectPattern558(inst, ctx))
                return true;
            break;
        }
        case InstFDiv: {
            if(matchAndSelectPattern566(inst, ctx))
                return true;
            break;
        }
        case InstFNeg: {
            if(matchAndSelectPattern574(inst, ctx))
                return true;
            break;
        }
        case VMOV_FPR2GPR: {
            if(matchAndSelectPattern580(inst, ctx))
                return true;
            break;
        }
        case VMOV_GPR2FPR: {
            if(matchAndSelectPattern588(inst, ctx))
                return true;
            break;
        }
        case InstZExt: {
            if(matchAndSelectPattern596(inst, ctx))
                return true;
            if(matchAndSelectPattern847(inst, ctx))
                return true;
            if(matchAndSelectPattern1236(inst, ctx))
                return true;
            break;
        }
        case InstSExt: {
            if(matchAndSelectPattern602(inst, ctx))
                return true;
            break;
        }
        case InstLoadGlobalAddress: {
            if(matchAndSelectPattern608(inst, ctx))
                return true;
            break;
        }
        case InstJump: {
            if(matchAndSelectPattern614(inst, ctx))
                return true;
            break;
        }
        case InstBranch: {
            if(matchAndSelectPattern618(inst, ctx))
                return true;
            if(matchAndSelectPattern636(inst, ctx))
                return true;
            if(matchAndSelectPattern785(inst, ctx))
                return true;
            break;
        }
        case InstSelect: {
            if(matchAndSelectPattern648(inst, ctx))
                return true;
            if(matchAndSelectPattern668(inst, ctx))
                return true;
            if(matchAndSelectPattern688(inst, ctx))
                return true;
            if(matchAndSelectPattern702(inst, ctx))
                return true;
            if(matchAndSelectPattern797(inst, ctx))
                return true;
            if(matchAndSelectPattern811(inst, ctx))
                return true;
            break;
        }
        case InstICmp: {
            if(matchAndSelectPattern716(inst, ctx))
                return true;
            if(matchAndSelectPattern728(inst, ctx))
                return true;
            if(matchAndSelectPattern739(inst, ctx))
                return true;
            break;
        }
        case InstFCmp: {
            if(matchAndSelectPattern753(inst, ctx))
                return true;
            if(matchAndSelectPattern771(inst, ctx))
                return true;
            break;
        }
        case InstLoad: {
            if(matchAndSelectPattern825(inst, ctx))
                return true;
            if(matchAndSelectPattern837(inst, ctx))
                return true;
            break;
        }
        case InstStore: {
            if(matchAndSelectPattern859(inst, ctx))
                return true;
            if(matchAndSelectPattern873(inst, ctx))
                return true;
            if(matchAndSelectPattern885(inst, ctx))
                return true;
            if(matchAndSelectPattern897(inst, ctx))
                return true;
            break;
        }
        case InstUnreachable: {
            if(matchAndSelectPattern907(inst, ctx))
                return true;
            break;
        }
        case InstAbs: {
            if(matchAndSelectPattern909(inst, ctx))
                return true;
            break;
        }
        case RSB: {
            if(matchAndSelectPattern923(inst, ctx))
                return true;
            break;
        }
        case InstSMax: {
            if(matchAndSelectPattern938(inst, ctx))
                return true;
            if(matchAndSelectPattern962(inst, ctx))
                return true;
            if(matchAndSelectPattern986(inst, ctx))
                return true;
            if(matchAndSelectPattern996(inst, ctx))
                return true;
            if(matchAndSelectPattern1020(inst, ctx))
                return true;
            break;
        }
        case InstSMin: {
            if(matchAndSelectPattern950(inst, ctx))
                return true;
            if(matchAndSelectPattern974(inst, ctx))
                return true;
            if(matchAndSelectPattern1008(inst, ctx))
                return true;
            if(matchAndSelectPattern1033(inst, ctx))
                return true;
            break;
        }
        case InstFAbs: {
            if(matchAndSelectPattern1046(inst, ctx))
                return true;
            break;
        }
        case ADD: {
            if(matchAndSelectPattern1052(inst, ctx))
                return true;
            if(matchAndSelectPattern1116(inst, ctx))
                return true;
            if(matchAndSelectPattern1180(inst, ctx))
                return true;
            break;
        }
        case SUB: {
            if(matchAndSelectPattern1068(inst, ctx))
                return true;
            if(matchAndSelectPattern1132(inst, ctx))
                return true;
            if(matchAndSelectPattern1194(inst, ctx))
                return true;
            break;
        }
        case ORR: {
            if(matchAndSelectPattern1084(inst, ctx))
                return true;
            if(matchAndSelectPattern1148(inst, ctx))
                return true;
            if(matchAndSelectPattern1208(inst, ctx))
                return true;
            break;
        }
        case EOR: {
            if(matchAndSelectPattern1100(inst, ctx))
                return true;
            if(matchAndSelectPattern1164(inst, ctx))
                return true;
            if(matchAndSelectPattern1222(inst, ctx))
                return true;
            break;
        }
        case InstTrunc: {
            if(matchAndSelectPattern1242(inst, ctx))
                return true;
            break;
        }
        default:
            break;
    }
    return false;
}

class ARMISelInfo final : public TargetISelInfo {
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

const TargetISelInfo& getARMISelInfo() {
    static ARMISelInfo iselInfo;
    return iselInfo;
}

CMMC_TARGET_NAMESPACE_END