#include "instruction.hpp"

#include <cassert>

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
BasicBlock *BrInst::cond() {
  return static_cast<BasicBlock *>(operand(0));
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

PhiInst::PhiInst(BasicBlock *bb, Type *type, const std::string &name, const std::vector<Value *> &vals,
                 const std::vector<BasicBlock *> &bbs)
    : Instruction(bb, PHI, type, name), size(vals.size()) {
  newOperands(vals);
  newOperands(bbs);
}
Value *PhiInst::getvals(size_t k) {
  return operand(k);
}
Value *PhiInst::getblos(size_t k) {
  return operand(k + size);
}
void PhiInst::addIncoming(Value *val, BasicBlock *bb) {
  // if(val->type()!=_type)assert(0);
  // 将新的操作数添加到 _operands 数组中
  // _operands.emplace_back(size,this,val);
  //  val->newUse(&_operands.back());
  // _operands.emplace_back(size,this,bb);
  newOperand(val);
  newOperand(bb);
  // 更新操作数的数量
  size++;
}

// PhiInst::PhiInst(BasicBlock *basic_block, Type *type, const std::string &name, const std::vector<Value *> &values,
//                  const std::vector<BasicBlock *> &basic_blocks)
//     : Instruction(basic_block, PHI, type, name) {
//   assert(values.size() == basic_blocks.size());
//   newOperands(values);
//   newOperands(basic_blocks);
// }

// Util::Range<std::vector<IR::Use>::iterator> PhiInst::values() {
//   return Util::range(_operands.begin(), _operands.begin() + _operands.size() / 2);
// }

// Util::Range<std::vector<IR::Use>::iterator> PhiInst::basicBlocks() {
//   return Util::range(_operands.begin() + _operands.size() / 2, _operands.begin() + _operands.size());
// }

CallInst::CallInst(BasicBlock *basic_block, const std::string &name, Function *callee,
                   const std::vector<Value *> &arguments)
    : Instruction(basic_block, CALL, callee->type()->retType(), name) {
  newOperand(callee);
  newOperands(arguments);
}

Function *CallInst::callee() {
  return static_cast<Function *>(operand(0));
}

Util::Range<std::vector<IR::Use>::iterator> CallInst::arguments() {
  return Util::range(_operands.begin() + 1, _operands.end());
}

}  // namespace IR
