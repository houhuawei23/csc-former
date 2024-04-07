#ifndef __IRBUILDER_HPP__
#define __IRBUILDER_HPP__

#include "instruction.hpp"

namespace IR {

class IRBuilder {
private:
  BasicBlock *basic_block;
  std::list<std::unique_ptr<Instruction>>::iterator it;

public:
  IRBuilder() = default;
  IRBuilder(std::list<std::unique_ptr<Instruction>>::iterator it);

  BasicBlock *basicBlock() {
    return basic_block;
  }
  Function *function() {
    return basic_block->function();
  }

  /// @brief set it directly
  void set(BasicBlock *basic_block, std::list<std::unique_ptr<Instruction>>::iterator it);
  /// @brief new instruction before it
  Instruction *newInstruction(Instruction *instruction);
  /// @brief del instruction at it, return next it
  std::list<std::unique_ptr<Instruction>>::iterator delInstruction();

  /// @brief Terminator Instructions
  RetInst *newRetInst(Value *ret_value);
  JmpInst *newJmpInst(BasicBlock *target);
  BrInst *newBrInst(Value *cond, BasicBlock *iftrue, BasicBlock *iffalse);
  /// @brief Unary Operations
  UnaryInst *newUnaryInst(IType itype, Type *type, Value *rhs);
  UnaryInst *newSUnaryInst(IType itype, Type *type, Value *rhs);
  UnaryInst *newFUnaryInst(IType itype, Type *type, Value *rhs);
  UnaryInst *newFnegInst(Value *rhs);
  /// @brief Binary Operations
  BinaryInst *newBinaryInst(IType itype, Type *type, Value *lhs, Value *rhs);
  BinaryInst *newAddInst(Value *lhs, Value *rhs);
  BinaryInst *newFaddInst(Value *lhs, Value *rhs);
  BinaryInst *newSubInst(Value *lhs, Value *rhs);
  BinaryInst *newFsubInst(Value *lhs, Value *rhs);
  BinaryInst *newMulInst(Value *lhs, Value *rhs);
  BinaryInst *newFmulInst(Value *lhs, Value *rhs);
  BinaryInst *newSdivInst(Value *lhs, Value *rhs);
  BinaryInst *newFdivInst(Value *lhs, Value *rhs);
  BinaryInst *newSremInst(Value *lhs, Value *rhs);
  /// @brief Bitwise Binary Operations
  BinaryInst *newShlInst(Value *lhs, Value *rhs);
  BinaryInst *newLshrInst(Value *lhs, Value *rhs);
  BinaryInst *newAshrInst(Value *lhs, Value *rhs);
  BinaryInst *newAndInst(Value *lhs, Value *rhs);
  BinaryInst *newOrInst(Value *lhs, Value *rhs);
  BinaryInst *newXorInst(Value *lhs, Value *rhs);
  /// @brief Memory Access and Addressing Operations
  AllocaInst *newAllocaInst(Type *type);
  LoadInst *newLoadInst(Value *addr);
  StoreInst *newStoreInst(Value *value, Value *addr);
  AddrAddInst *newAddrAddInst(Value *addr, Value *index);
  AddrDerefAddInst *newAddrDerefAddInst(Value *addr, Value *index);
  /// @brief Conversion Operations
  UnaryInst *newTruncInst(Value *rhs, Type *type);
  UnaryInst *newZextInst(Value *rhs, Type *type);
  UnaryInst *newSextInst(Value *rhs, Type *type);
  UnaryInst *newFptruncInst(Value *rhs, Type *type);
  UnaryInst *newFpextInst(Value *rhs, Type *type);
  UnaryInst *newFptosiInst(Value *rhs, Type *type);
  UnaryInst *newSitofpInst(Value *rhs, Type *type);
  UnaryInst *newPtrtointInst(Value *rhs, Type *type);
  UnaryInst *newInttoptrInst(Value *rhs, Type *type);
  /// @brief Other Operations
  IcmpInst *newIcmpInst(IType itype, Value *lhs, Value *rhs);
  IcmpInst *newIeqInst(Value *lhs, Value *rhs);
  IcmpInst *newIneInst(Value *lhs, Value *rhs);
  IcmpInst *newIsgtInst(Value *lhs, Value *rhs);
  IcmpInst *newIsgeInst(Value *lhs, Value *rhs);
  IcmpInst *newIsltInst(Value *lhs, Value *rhs);
  IcmpInst *newIsleInst(Value *lhs, Value *rhs);
  FcmpInst *newFcmpInst(IType itype, Value *lhs, Value *rhs);
  FcmpInst *newFoeqInst(Value *lhs, Value *rhs);
  FcmpInst *newFoneInst(Value *lhs, Value *rhs);
  FcmpInst *newFogtInst(Value *lhs, Value *rhs);
  FcmpInst *newFogeInst(Value *lhs, Value *rhs);
  FcmpInst *newFoltInst(Value *lhs, Value *rhs);
  FcmpInst *newFoleInst(Value *lhs, Value *rhs);
  PhiInst *newPhiInst(Type *type);
  CallInst *newCallInst(Function *callee, const std::vector<Value *> &arguments);
};

}  // namespace IR

#endif
