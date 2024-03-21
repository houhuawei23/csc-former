#include "irbuilder.hpp"

#include <cassert>

namespace IR {

IRBuilder::IRBuilder(std::list<std::unique_ptr<Instruction>>::iterator it) : it(it) {
}

/// @brief set it directly
void IRBuilder::set(BasicBlock *basic_block, std::list<std::unique_ptr<Instruction>>::iterator it) {
  this->basic_block = basic_block;
  this->it = it;
}

/// @brief new instruction before it
Instruction *IRBuilder::newInstruction(Instruction *instruction) {
  basic_block->instructions().emplace(it, instruction);
  return instruction;
}

/// @brief del instruction at it, return next it
std::list<std::unique_ptr<Instruction>>::iterator IRBuilder::delInstruction() {
  return it = basic_block->instructions().erase(it);
}

/// @brief Terminator Instructions
RetInst *IRBuilder::newRetInst(Value *ret_value) {
  assert(ret_value->type()->in({Type::void_t(), Type::i32_t(), Type::float_t()}));
  function()->exits().emplace_back(basic_block);
  basic_block->setIsExit(true);
  auto instruction = static_cast<RetInst *>(newInstruction(new RetInst(basic_block, ret_value)));
  return instruction;
}

JmpInst *IRBuilder::newJmpInst(BasicBlock *dest) {
  assert(dest);
  dest->predecessors().emplace_back(basic_block);
  basic_block->successors().emplace_back(dest);
  auto instruction = static_cast<JmpInst *>(newInstruction(new JmpInst(basic_block, dest)));
  return instruction;
}

BrInst *IRBuilder::newBrInst(Value *cond, BasicBlock *iftrue, BasicBlock *iffalse) {
  assert(cond->type()->isI1() && iftrue && iffalse);
  iftrue->predecessors().emplace_back(basic_block);
  basic_block->successors().emplace_back(iftrue);
  iffalse->predecessors().emplace_back(basic_block);
  basic_block->successors().emplace_back(iffalse);
  auto instruction = static_cast<BrInst *>(newInstruction(new BrInst(basic_block, cond, iftrue, iffalse)));
  return instruction;
}

/// @brief Unary Operations
UnaryInst *IRBuilder::newUnaryInst(IType itype, Type *type, Value *rhs) {
  return static_cast<UnaryInst *>(newInstruction(new UnaryInst(basic_block, itype, type, "", rhs)));
}

UnaryInst *IRBuilder::newSUnaryInst(IType itype, Type *type, Value *rhs) {
  assert(rhs->type()->isI32());
  return newUnaryInst(itype, type, rhs);
}

UnaryInst *IRBuilder::newFUnaryInst(IType itype, Type *type, Value *rhs) {
  assert(rhs->type()->isFloat());
  return newUnaryInst(itype, type, rhs);
}

UnaryInst *IRBuilder::newFnegInst(Value *rhs) {
  return newFUnaryInst(FNEG, Type::float_t(), rhs);
}

/// @brief Binary Operations
BinaryInst *IRBuilder::newBinaryInst(IType itype, Type *type, Value *lhs, Value *rhs) {
  assert(lhs->type() == type);
  assert(rhs->type() == type);
  return static_cast<BinaryInst *>(newInstruction(new BinaryInst(basic_block, itype, type, "", lhs, rhs)));
}

BinaryInst *IRBuilder::newAddInst(Value *lhs, Value *rhs) {
  return newBinaryInst(ADD, Type::i32_t(), lhs, rhs);
}

BinaryInst *IRBuilder::newFaddInst(Value *lhs, Value *rhs) {
  return newBinaryInst(FADD, Type::float_t(), lhs, rhs);
}

BinaryInst *IRBuilder::newSubInst(Value *lhs, Value *rhs) {
  return newBinaryInst(SUB, Type::i32_t(), lhs, rhs);
}

BinaryInst *IRBuilder::newFsubInst(Value *lhs, Value *rhs) {
  return newBinaryInst(FSUB, Type::float_t(), lhs, rhs);
}

BinaryInst *IRBuilder::newMulInst(Value *lhs, Value *rhs) {
  return newBinaryInst(MUL, Type::i32_t(), lhs, rhs);
}

BinaryInst *IRBuilder::newFmulInst(Value *lhs, Value *rhs) {
  return newBinaryInst(FMUL, Type::float_t(), lhs, rhs);
}

BinaryInst *IRBuilder::newSdivInst(Value *lhs, Value *rhs) {
  return newBinaryInst(SDIV, Type::i32_t(), lhs, rhs);
}

BinaryInst *IRBuilder::newFdivInst(Value *lhs, Value *rhs) {
  return newBinaryInst(FDIV, Type::float_t(), lhs, rhs);
}

BinaryInst *IRBuilder::newSremInst(Value *lhs, Value *rhs) {
  return newBinaryInst(SREM, Type::i32_t(), lhs, rhs);
}

/// @brief Bitwise Binary Operations
BinaryInst *IRBuilder::newShlInst(Value *lhs, Value *rhs) {
  assert(0);
}
BinaryInst *IRBuilder::newLshrInst(Value *lhs, Value *rhs) {
  assert(0);
}
BinaryInst *IRBuilder::newAshrInst(Value *lhs, Value *rhs) {
  assert(0);
}
BinaryInst *IRBuilder::newAndInst(Value *lhs, Value *rhs) {
  assert(0);
}
BinaryInst *IRBuilder::newOrInst(Value *lhs, Value *rhs) {
  assert(0);
}
BinaryInst *IRBuilder::newXorInst(Value *lhs, Value *rhs) {
  assert(0);
}

/// @brief Memory Access and Addressing Operations
AllocaInst *IRBuilder::newAllocaInst(Type *type) {
  auto preserve_basic_block = basic_block;
  auto preserve_it = it;
  basic_block = function()->allocas();
  it = std::prev(function()->allocas()->instructions().end());
  auto instruction = static_cast<AllocaInst *>(newInstruction(new AllocaInst(basic_block, "", type)));
  basic_block = preserve_basic_block;
  it = preserve_it;
  return instruction;
}

LoadInst *IRBuilder::newLoadInst(Value *addr) {
  assert(addr->type()->isPointer());
  return static_cast<LoadInst *>(newInstruction(new LoadInst(basic_block, "", addr)));
}

StoreInst *IRBuilder::newStoreInst(Value *value, Value *addr) {
  if (!function()->sideEffect()) {
    if (auto global_addr = dynamic_cast<GlobalAddr *>(addr)) {
      function()->setSideEffect(true);
    }
  }
  assert(addr->type()->isPointer());
  assert(addr->type()->deref(1) == value->type());
  return static_cast<StoreInst *>(newInstruction(new StoreInst(basic_block, value, addr)));
}

AddrAddInst *IRBuilder::newAddrAddInst(Value *addr, Value *offset) {
  assert(addr->type()->isPointer() || addr->type()->isArray());
  assert(offset->type()->isI32());
  return static_cast<AddrAddInst *>(newInstruction(new AddrAddInst(basic_block, "", addr, offset)));
}

AddrDerefAddInst *IRBuilder::newAddrDerefAddInst(Value *addr, Value *offset) {
  assert(addr->type()->isPointer() || addr->type()->isArray());
  assert(offset->type()->isI32());
  return static_cast<AddrDerefAddInst *>(newInstruction(new AddrDerefAddInst(basic_block, "", addr, offset)));
}

/// @brief Conversion Operations
UnaryInst *IRBuilder::newTruncInst(Value *rhs, Type *type) {
  assert(0);
}

UnaryInst *IRBuilder::newZextInst(Value *rhs, Type *type) {
  assert(rhs->type()->sizeOf() < type->sizeOf());
  return static_cast<UnaryInst *>(newInstruction(new UnaryInst(basic_block, ZEXT, type, "", rhs)));
}

UnaryInst *IRBuilder::newSextInst(Value *rhs, Type *type) {
  assert(0);
}

UnaryInst *IRBuilder::newFptruncInst(Value *rhs, Type *type) {
  assert(0);
}

UnaryInst *IRBuilder::newFpextInst(Value *rhs, Type *type) {
  assert(0);
}

UnaryInst *IRBuilder::newFptosiInst(Value *rhs, Type *type) {
  assert(rhs->type()->isFloat());
  assert(type->isI32());
  return static_cast<UnaryInst *>(newInstruction(new UnaryInst(basic_block, FPTOSI, type, "", rhs)));
}

UnaryInst *IRBuilder::newSitofpInst(Value *rhs, Type *type) {
  assert(rhs->type()->isI32());
  assert(type->isFloat());
  return static_cast<UnaryInst *>(newInstruction(new UnaryInst(basic_block, SITOFP, type, "", rhs)));
}

UnaryInst *IRBuilder::newPtrtointInst(Value *rhs, Type *type) {
  assert(rhs->type()->isPointer());
  assert(type->isI32());
  return static_cast<UnaryInst *>(newInstruction(new UnaryInst(basic_block, PTRTOINT, type, "", rhs)));
}

UnaryInst *IRBuilder::newInttoptrInst(Value *rhs, Type *type) {
  assert(rhs->type()->isI32());
  assert(type->isPointer());
  return static_cast<UnaryInst *>(newInstruction(new UnaryInst(basic_block, INTTOPTR, type, "", rhs)));
}

/// @brief Other Operations
IcmpInst *IRBuilder::newIcmpInst(IType itype, Value *lhs, Value *rhs) {
  assert(lhs->type() == rhs->type());
  assert(lhs->type()->isI1() || lhs->type()->isI32() || lhs->type()->isPointer());
  return static_cast<IcmpInst *>(newInstruction(new IcmpInst(basic_block, itype, "", lhs, rhs)));
}

IcmpInst *IRBuilder::newIeqInst(Value *lhs, Value *rhs) {
  return newIcmpInst(IEQ, lhs, rhs);
}

IcmpInst *IRBuilder::newIneInst(Value *lhs, Value *rhs) {
  return newIcmpInst(INE, lhs, rhs);
}

IcmpInst *IRBuilder::newIsgtInst(Value *lhs, Value *rhs) {
  return newIcmpInst(ISGT, lhs, rhs);
}

IcmpInst *IRBuilder::newIsgeInst(Value *lhs, Value *rhs) {
  return newIcmpInst(ISGE, lhs, rhs);
}

IcmpInst *IRBuilder::newIsltInst(Value *lhs, Value *rhs) {
  return newIcmpInst(ISLT, lhs, rhs);
}

IcmpInst *IRBuilder::newIsleInst(Value *lhs, Value *rhs) {
  return newIcmpInst(ISLE, lhs, rhs);
}

FcmpInst *IRBuilder::newFcmpInst(IType itype, Value *lhs, Value *rhs) {
  assert(lhs->type() == rhs->type());
  assert(lhs->type()->isFloat());
  return static_cast<FcmpInst *>(newInstruction(new FcmpInst(basic_block, itype, "", lhs, rhs)));
}

FcmpInst *IRBuilder::newFoeqInst(Value *lhs, Value *rhs) {
  return newFcmpInst(FOEQ, lhs, rhs);
}

FcmpInst *IRBuilder::newFoneInst(Value *lhs, Value *rhs) {
  return newFcmpInst(FONE, lhs, rhs);
}

FcmpInst *IRBuilder::newFogtInst(Value *lhs, Value *rhs) {
  return newFcmpInst(FOGT, lhs, rhs);
}

FcmpInst *IRBuilder::newFogeInst(Value *lhs, Value *rhs) {
  return newFcmpInst(FOGE, lhs, rhs);
}

FcmpInst *IRBuilder::newFoltInst(Value *lhs, Value *rhs) {
  return newFcmpInst(FOLT, lhs, rhs);
}

FcmpInst *IRBuilder::newFoleInst(Value *lhs, Value *rhs) {
  return newFcmpInst(FOLE, lhs, rhs);
}

PhiInst *IRBuilder::newPhiInst(Type *type, const std::vector<Value *> &values,
                               const std::vector<BasicBlock *> &basic_blocks) {
  assert(values.size() == basic_blocks.size());
  for (auto value : values)
    if (value->type() != type) assert(0);
  return static_cast<PhiInst *>(newInstruction(new PhiInst(basic_block, type, "", values, basic_blocks)));
}

CallInst *IRBuilder::newCallInst(Function *callee, const std::vector<Value *> &arguments) {
  assert(callee);
  return static_cast<CallInst *>(newInstruction(new CallInst(basic_block, "", callee, arguments)));
}

}  // namespace IR
