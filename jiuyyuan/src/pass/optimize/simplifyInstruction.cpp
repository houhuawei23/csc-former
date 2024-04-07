#include "simplifyInstruction.hpp"
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "typesystem.hpp"
#include <cstdint>
namespace IR {

Value *simplifyInstruction(Instruction *inst) {
  if (auto bI = dynamic_cast<BinaryInst *>(inst)) {
    return simplifyInstruction(bI);
  } else if (auto iI = dynamic_cast<IcmpInst *>(inst)) {
    return simplifyInstruction(iI);
  }
  // else if (auto uI = dynamic_cast<UnaryInst *>(inst)) {
  //   return simplifyInstruction(uI);
  // }
  else
    return inst;
}
Value *simplifyInstruction(BinaryInst *inst) {
  if (auto bI = dynamic_cast<BinaryInst *>(inst)) {
    auto lhs = inst->lhs();
    auto rhs = inst->rhs();
    switch (bI->itype()) {
    case ADD: {
      if (auto clhs = dynamic_cast<Constant *>(lhs); clhs && clhs->isInt()) {
        inst->unUseAll();
        inst->setOperand(0, rhs);
        inst->setOperand(1, lhs);
        lhs = inst->lhs();
        rhs = inst->rhs();
      }
      // X+0=X
      if (auto constRhs = dynamic_cast<Constant *>(rhs);
          constRhs && constRhs->isInt() && constRhs->getIntVal() == 0) {
        return lhs;
      }
      if (auto subLhs = dynamic_cast<BinaryInst *>(lhs);
          subLhs && subLhs->itype() == SUB) {
        if (auto clhsOfLhs = dynamic_cast<Constant *>(subLhs->operand(0));
            clhsOfLhs && clhsOfLhs->isInt() && clhsOfLhs->getIntVal() == 0 &&
            subLhs->operand(1) == rhs)
          return Constant::get(static_cast<int32_t>(0));
        else if (auto subRhs = dynamic_cast<BinaryInst *>(rhs);
                 subRhs && subRhs->itype() == SUB) {
          if (auto clhsOfRhs = dynamic_cast<Constant *>(subRhs->operand(0));
              clhsOfRhs && clhsOfRhs->isInt() && clhsOfRhs->getIntVal() == 0 &&
              subRhs->operand(1) == lhs)
            return Constant::get(static_cast<int32_t>(0));
        }
      }
      if (auto subLhs = dynamic_cast<BinaryInst *>(lhs);
          subLhs && subLhs->itype() == SUB)
        if (auto subRhs = dynamic_cast<BinaryInst *>(rhs);
            subRhs && subRhs->itype() == SUB)
          if (subLhs->operand(0) == subRhs->operand(1) &&
              subLhs->operand(1) == subRhs->operand(0))
            return Constant::get(static_cast<int32_t>(0));
      return bI;
    }
    case SUB: {
      if (auto constRhs = dynamic_cast<Constant *>(rhs);
          constRhs && constRhs->isInt() && constRhs->getIntVal() == 0) {
        return lhs;
      }
      if (auto clhs = dynamic_cast<Constant *>(lhs);
          clhs && clhs->isInt() && clhs->getIntVal() == 0) {
        if (auto srhs = dynamic_cast<BinaryInst *>(rhs);
            srhs && srhs->itype() == SUB) {
          if (auto clhsOfRhs = dynamic_cast<Constant *>(srhs->operand(0));
              clhsOfRhs && clhsOfRhs->isInt() && clhsOfRhs->getIntVal() == 0) {
            return srhs->operand(1);
          }
        }
      }
      if (lhs == rhs)
        return Constant::get(static_cast<int32_t>(0));
      return bI;
    }
    case MUL: {
      if (auto clhs = dynamic_cast<Constant *>(lhs); clhs && clhs->isInt()) {
        inst->unUseAll();
        inst->setOperand(0, rhs);
        inst->setOperand(1, lhs);
        lhs = inst->lhs();
        rhs = inst->rhs();
      }
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && crhs->isInt() && crhs->getIntVal() == 0) {
        return Constant::get(static_cast<int32_t>(0));
      }
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && crhs->isInt() && crhs->getIntVal() == 1) {
        return lhs;
      }
      return bI;
    }
    case SDIV: {
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && crhs->isInt() && crhs->getIntVal() == 1) {
        return lhs;
      }
      return bI;
    }
    case SREM: {
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && crhs->isInt() && crhs->getIntVal() == 1) {
        return Constant::get(static_cast<int32_t>(0));
      }
      return bI;
    }
    case FADD: {
      if (auto clhs = dynamic_cast<Constant *>(lhs); clhs && clhs->isFloat()) {
        inst->unUseAll();
        inst->setOperand(0, rhs);
        inst->setOperand(1, lhs);
        lhs = inst->lhs();
        rhs = inst->rhs();
      }
      if (auto constRhs = dynamic_cast<Constant *>(rhs);
          constRhs && constRhs->isFloat() && constRhs->getFloatVal() == 0.f) {
        return lhs;
      }
      if (auto subLhs = dynamic_cast<BinaryInst *>(lhs);
          subLhs && subLhs->itype() == SUB) {
        if (auto clhsOfLhs = dynamic_cast<Constant *>(subLhs->operand(0));
            clhsOfLhs && clhsOfLhs->isFloat() &&
            clhsOfLhs->getFloatVal() == 0.f && subLhs->operand(1) == rhs)
          return Constant::get(static_cast<float>(0.f));

        else if (auto subRhs = dynamic_cast<BinaryInst *>(rhs);
                 subRhs && subRhs->itype() == SUB) {
          if (auto clhsOfRhs = dynamic_cast<Constant *>(subRhs->operand(0));
              clhsOfRhs && clhsOfRhs->isFloat() && clhsOfLhs->isFloat() &&
              clhsOfRhs->getFloatVal() == 0.f && subRhs->operand(1) == lhs)
            return Constant::get(static_cast<float>(0.f));
        }
      }
      if (auto subLhs = dynamic_cast<BinaryInst *>(lhs);
          subLhs && subLhs->itype() == SUB)
        if (auto subRhs = dynamic_cast<BinaryInst *>(rhs);
            subRhs && subRhs->itype() == SUB)
          if (subLhs->operand(0) == subRhs->operand(1) &&
              subLhs->operand(1) == subRhs->operand(0))
            return Constant::get(static_cast<float>(0.f));
      return bI;
    }
    case FSUB: {
      if (auto constRhs = dynamic_cast<Constant *>(rhs);
          constRhs && constRhs->isFloat() && constRhs->getFloatVal() == 0.f) {
        return lhs;
      }
      if (auto clhs = dynamic_cast<Constant *>(lhs);
          clhs && clhs->isFloat() && clhs->getFloatVal() == 0.f) {
        if (auto srhs = dynamic_cast<BinaryInst *>(rhs);
            srhs && srhs->itype() == SUB) {
          if (auto clhsOfRhs = dynamic_cast<Constant *>(srhs->operand(0));
              clhsOfRhs && clhsOfRhs->isFloat() &&
              clhsOfRhs->getFloatVal() == 0.f) {
            return srhs->operand(1);
          }
        }
      }
      if (lhs == rhs)
        return Constant::get(static_cast<float>(0.f));
      return bI;
    }
    case FMUL: {
      if (auto clhs = dynamic_cast<Constant *>(lhs); clhs && clhs->isFloat()) {
        inst->unUseAll();
        inst->setOperand(0, rhs);
        inst->setOperand(1, lhs);
        lhs = inst->lhs();
        rhs = inst->rhs();
      }
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && crhs->isFloat() && crhs->getFloatVal() == 0.f) {
        return Constant::get(static_cast<float>(0.f));
      }
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && crhs->isFloat() && crhs->getFloatVal() == 1.f) {
        return lhs;
      }
      return bI;
    }
    case FDIV: {
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && crhs->isFloat() && crhs->getFloatVal() == 1.f) {
        return lhs;
      }
      return bI;
    }
    default:
      return bI;
    }
  }
  return inst;
}
Value *simplifyInstruction(UnaryInst *inst) {
  if (auto uI = dynamic_cast<UnaryInst *>(inst)) {
    // 这里可以再进行局部的常数折叠
    switch (uI->itype()) {
    case FNEG: {
      // fneg a -> fsub 0, a
      return new BinaryInst(uI->basicBlock(), FSUB, uI->type(), "",
                            Constant::get(static_cast<float>(0.f)), uI->rhs());
    }
    default: {
      return uI;
    }
    }
  }
  return inst;
}
Value *simplifyInstruction(IcmpInst *inst) {
  if (auto bI = dynamic_cast<IcmpInst *>(inst)) {
    auto lhs = inst->lhs();
    auto rhs = inst->rhs();
    switch (bI->itype()) {
    case IEQ: {//==
      if (lhs == rhs)
        return Constant::get(static_cast<bool>(1));
      if (auto clhs = dynamic_cast<Constant *>(lhs); clhs && (clhs->isInt()||clhs->isBool())) {
        inst->unUseAll();
        inst->setOperand(0, rhs);
        inst->setOperand(1, lhs);
        lhs = inst->lhs();
        rhs = inst->rhs();
      }
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && ((crhs->isInt() && crhs->getIntVal() == 1)||(crhs->isBool() && crhs->getBoolVal()==1))) {
        if (auto blhs = dynamic_cast<Instruction *>(lhs);
            blhs && blhs->isCompare())
          return blhs;
      }
      return bI;
    }
    case INE: {
      if (lhs == rhs)
        return Constant::get(static_cast<bool>(0));
      if (auto clhs = dynamic_cast<Constant *>(lhs); clhs && (clhs->isInt()||clhs->isBool())) {
        inst->unUseAll();
        inst->setOperand(0, rhs);
        inst->setOperand(1, lhs);
        lhs = inst->lhs();
        rhs = inst->rhs();
      }
      if (auto crhs = dynamic_cast<Constant *>(rhs);
          crhs && ((crhs->isInt() && crhs->getIntVal() == 0)||(crhs->isBool() && crhs->getBoolVal()==0))) {
        if (auto blhs = dynamic_cast<Instruction *>(lhs);
            blhs && blhs->isCompare())
          return blhs;
      }
      return bI;
    }
    case ISGE: { // >=
      if (lhs == rhs)
        return Constant::get(static_cast<bool>(1));
      if (auto crhs = dynamic_cast<Constant *>(rhs)) {
        if (((crhs->isInt() && crhs->getIntVal() == 0)||(crhs->isBool() && crhs->getBoolVal()==0))) {
          if (auto blhs = dynamic_cast<Instruction *>(lhs);
              blhs && blhs->isCompare())
            return Constant::get(static_cast<bool>(1));
        } else if (((crhs->isInt() && crhs->getIntVal() == 1)||(crhs->isBool() && crhs->getBoolVal()==1))) {
          if (auto blhs = dynamic_cast<Instruction *>(lhs);
              blhs && blhs->isCompare())
            return blhs;
        }
      }
      else if (auto clhs = dynamic_cast<Constant *>(lhs)) {
        if (((clhs->isInt() && clhs->getIntVal() == 1)||(clhs->isBool() && clhs->getBoolVal()==1))) {
          if (auto brhs = dynamic_cast<Instruction *>(rhs);
              brhs && brhs->isCompare())
            return Constant::get(static_cast<bool>(1));
        }
      }
      return bI;
    }
    case ISGT: { // >
      if (lhs == rhs)
        return Constant::get(static_cast<bool>(0));
      if (auto crhs = dynamic_cast<Constant *>(rhs)) {
        if (((crhs->isInt() && crhs->getIntVal() == 0)||(crhs->isBool() && crhs->getBoolVal()==0))) {
          if (auto blhs = dynamic_cast<Instruction *>(lhs);
              blhs && blhs->isCompare())
            return blhs;
        } else if (((crhs->isInt() && crhs->getIntVal() == 1)||(crhs->isBool() && crhs->getBoolVal()==1))) {
          if (auto blhs = dynamic_cast<Instruction *>(lhs);
              blhs && blhs->isCompare())
            return Constant::get(static_cast<bool>(0));
        }
      }
      else if (auto clhs = dynamic_cast<Constant *>(lhs)) {
        if (((clhs->isInt() && clhs->getIntVal() == 0)||(clhs->isBool() && clhs->getBoolVal()==0))) {
          if (auto brhs = dynamic_cast<Instruction *>(rhs);
              brhs && brhs->isCompare())
            return Constant::get(static_cast<bool>(0));
        }
      }
      return bI;
    }
    case ISLE: { // <=
      if (lhs == rhs)
        return Constant::get(static_cast<bool>(1));
      if (auto crhs = dynamic_cast<Constant *>(rhs)) {
        if (((crhs->isInt() && crhs->getIntVal() == 1)||(crhs->isBool() && crhs->getBoolVal()==1))) {
          if (auto blhs = dynamic_cast<Instruction *>(lhs);
              blhs && blhs->isCompare())
            return Constant::get(static_cast<bool>(1));
        }
      }
      else if (auto clhs = dynamic_cast<Constant *>(lhs)) {
        if (((clhs->isInt() && clhs->getIntVal() == 1)||(clhs->isBool() && clhs->getBoolVal()==1))) {
          if (auto brhs = dynamic_cast<Instruction *>(rhs);
              brhs && brhs->isCompare())
            return brhs;
        }
        else if (((clhs->isInt() && clhs->getIntVal() == 0)||(clhs->isBool() && clhs->getBoolVal()==0))) {
          if (auto brhs = dynamic_cast<Instruction *>(rhs);
              brhs && brhs->isCompare())
            return Constant::get(static_cast<bool>(1));
        }
      }
      return bI;
    }
    case ISLT: { // <
      if (lhs == rhs)
        return Constant::get(static_cast<bool>(0));
      if (auto crhs = dynamic_cast<Constant *>(rhs)) {
        if (((crhs->isInt() && crhs->getIntVal() == 0)||(crhs->isBool() && crhs->getBoolVal()==0))) {
          if (auto blhs = dynamic_cast<Instruction *>(lhs);
              blhs && blhs->isCompare())
            return Constant::get(static_cast<bool>(0));
        }
      }
      else if (auto clhs = dynamic_cast<Constant *>(lhs)) {
        if (((clhs->isInt() && clhs->getIntVal() == 1)||(clhs->isBool() && clhs->getBoolVal()==1))) {
          if (auto brhs = dynamic_cast<Instruction *>(rhs);
              brhs && brhs->isCompare())
            return Constant::get(static_cast<bool>(0));
        }
        else if (((clhs->isInt() && clhs->getIntVal() == 0)||(clhs->isBool() && clhs->getBoolVal()==0))) {
          if (auto brhs = dynamic_cast<Instruction *>(rhs);
              brhs && brhs->isCompare())
            return brhs;
        }
      }
      return bI;
    }
    default: {
      return bI;
    }
    }
  }
  return inst;
}
} // namespace IR
