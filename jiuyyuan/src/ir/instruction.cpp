#include "instruction.hpp"

#include <cassert>

#include "userelation.hpp"

namespace IR {

/// @brief Terminator Instructions
RetInst::RetInst(BasicBlock *basic_block, Value *ret_value) : Instruction(basic_block, RET, Type::void_t(), "") {
  newOperand(ret_value);
}
Value *RetInst::retValue() {
  return operand(0);
}

JmpInst::JmpInst(BasicBlock *basic_block, BasicBlock *dest) : Instruction(basic_block, JMP, Type::void_t(), "") {
  newOperand(dest);
}
BasicBlock *JmpInst::dest() {
  return static_cast<BasicBlock *>(operand(0));
}

BrInst::BrInst(BasicBlock *basic_block, Value *cond, BasicBlock *iftrue, BasicBlock *iffalse)
    : Instruction(basic_block, BR, Type::void_t(), "") {
  newOperand(cond);
  newOperand(iftrue);
  newOperand(iffalse);
}
Value *BrInst::cond() {
  return operand(0);
}
BasicBlock *BrInst::iftrue() {
  return static_cast<BasicBlock *>(operand(1));
}
BasicBlock *BrInst::iffalse() {
  return static_cast<BasicBlock *>(operand(2));
}

/// @brief Unary Operations
UnaryInst::UnaryInst(BasicBlock *basic_block, IType itype, Type *type, const std::string &name, Value *rhs)
    : Instruction(basic_block, itype, type, name) {
  newOperand(rhs);
}
Value *UnaryInst::rhs() {
  return operand(0);
}

/// @brief Binary Operations
BinaryInst::BinaryInst(BasicBlock *basic_block, IType itype, Type *type, const std::string &name, Value *lhs,
                       Value *rhs)
    : Instruction(basic_block, itype, type, name) {
  newOperand(lhs);
  newOperand(rhs);
}
Value *BinaryInst::lhs() {
  return operand(0);
}
Value *BinaryInst::rhs() {
  return operand(1);
}

/// @brief Memory Access and Addressing Operations
AllocaInst::AllocaInst(BasicBlock *basic_block, const std::string &name, Type *type)
    : Instruction(basic_block, ALLOCA, PointerType::get(type), name) {
}

LoadInst::LoadInst(BasicBlock *basic_block, const std::string &name, Value *addr)
    : Instruction(basic_block, LOAD, addr->type()->deref(1), name) {
  newOperand(addr);
}
Value *LoadInst::addr() {
  return operand(0);
}

StoreInst::StoreInst(BasicBlock *basic_block, Value *value, Value *addr)
    : Instruction(basic_block, STORE, Type::void_t(), "") {
  newOperand(value);
  newOperand(addr);
}
Value *StoreInst::value() {
  return operand(0);
}
Value *StoreInst::addr() {
  return operand(1);
}

AddrAddInst::AddrAddInst(BasicBlock *basic_block, const std::string &name, Value *addr, Value *offset)
    : Instruction(basic_block, ADDRADD, Type::pointer_t(addr->type()->deref(1)), name) {
  newOperand(addr);
  newOperand(offset);
}

Value *AddrAddInst::addr() {
  return operand(0);
}

Value *AddrAddInst::offset() {
  return operand(1);
}

AddrDerefAddInst::AddrDerefAddInst(BasicBlock *basic_block, const std::string &name, Value *addr, Value *offset)
    : Instruction(basic_block, ADDRDEREFADD, Type::pointer_t(addr->type()->deref(2)), name) {
  newOperand(addr);
  newOperand(offset);
}

Value *AddrDerefAddInst::addr() {
  return operand(0);
}

Value *AddrDerefAddInst::offset() {
  return operand(1);
}

/// @brief Other Operations
IcmpInst::IcmpInst(BasicBlock *basic_block, IType itype, const std::string &name, Value *lhs, Value *rhs)
    : Instruction(basic_block, itype, Type::i1_t(), name) {
  newOperand(lhs);
  newOperand(rhs);
}
Value *IcmpInst::lhs() {
  return operand(0);
}
Value *IcmpInst::rhs() {
  return operand(1);
}

FcmpInst::FcmpInst(BasicBlock *basic_block, IType itype, const std::string &name, Value *lhs, Value *rhs)
    : Instruction(basic_block, itype, Type::i1_t(), name) {
  newOperand(lhs);
  newOperand(rhs);
}
Value *FcmpInst::lhs() {
  return operand(0);
}
Value *FcmpInst::rhs() {
  return operand(1);
}

PhiInst::PhiInst(BasicBlock *basic_block, Type *type, const std::string &name)
    : Instruction(basic_block, PHI, type, name) {
}

Value *PhiInst::value(size_t index) {
  // return operand(2 * index);
  if (_operands[2 * index]) {
    return operand(2 * index);
  }
  return nullptr;
}

Value *PhiInst::incoming(size_t index) {
  // return operand(2 * index + 1);
  if (_operands[2 * index + 1]) {
    return operand(2 * index + 1);
  }
  return nullptr;
}

void PhiInst::newIncoming(Value *value, BasicBlock *basic_block) {
  assert(value->type() == Type::undefine_t() || value->type() == this->type() ||
         value->type()->isPointer() == this->type()->isPointer());
  assert(basic_block);
  newOperand(value);
  newOperand(basic_block);
}

void PhiInst::removeIncomingByBB(BasicBlock *bb) {
  int indexToRemove = -1;
  for (size_t i = 0; i < this->operands().size() / 2; i++) {
    if (incoming(i) == bb) {
      indexToRemove = i;
      break;
    }
  }
  if (indexToRemove >= 0) {
    _operands[indexToRemove * 2]->value()->uses().remove(_operands[indexToRemove * 2]);
    _operands[indexToRemove * 2 + 1]->value()->uses().remove(_operands[indexToRemove * 2 + 1]);
    _operands[indexToRemove * 2] = nullptr;
    _operands[indexToRemove * 2 + 1] = nullptr;
  }
}

// PhiInst::PhiInst(BasicBlock *bb, Type *type, const std::string &name, const std::vector<Value *> &vals,
//                  const std::vector<BasicBlock *> &bbs)
//     : Instruction(bb, PHI, type, name), size(vals.size()) {
//   newOperands(vals);
//   newOperands(bbs);
// }

// Value *PhiInst::getvals(size_t k) {
//   return operand(2*k);
// }
// Value *PhiInst::getblos(size_t k) {
//   return operand(2*k + 1);
// }
// void PhiInst::addIncoming(Value *val, BasicBlock *bb) {
//   assert(val->type() == Type::undefine_t() || val->type()==this->type());
//   newOperand(val);
//   newOperand(bb);
//   size++;
// }

void BasicBlock::insertAfterPhi(Instruction *instr) {
  auto iter = _instructions.begin();
  while (dynamic_cast<IR::PhiInst *>((*iter).get())) iter++;
  _instructions.emplace(iter, instr);
  instr->setBasicBlock(this);
}

CallInst::CallInst(BasicBlock *basic_block, const std::string &name, Function *callee,
                   const std::vector<Value *> &arguments)
    : Instruction(basic_block, CALL, callee->type()->retType(), name) {
  newOperand(callee);
  newOperands(arguments);
}

Function *CallInst::callee() {
  return static_cast<Function *>(operand(0));
}

Util::Range<std::vector<std::shared_ptr<IR::Use>>::iterator> CallInst::arguments() {
  return Util::range(_operands.begin() + 1, _operands.end());
}

bool CallInst::purecall() {
  auto func = callee();
  if (func->sideEffect()) return false;
  for (auto arg : arguments()) {
    if (arg->value()->type()->isPointer()) {
      return false;
    }
    if (auto ar = dynamic_cast<AddrAddInst *>(arg->value())) {
      return false;
    }
  }
  return true;
}

}  // namespace IR
