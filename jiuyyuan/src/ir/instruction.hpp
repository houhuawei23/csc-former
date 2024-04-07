#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__

#include "infrastructure.hpp"
#include "range.hpp"

namespace IR {

class RetInst : public Instruction {
public:
  RetInst(BasicBlock *basic_block, Value *ret_value);
  Value *retValue();
};

class JmpInst : public Instruction {
public:
  JmpInst(BasicBlock *basic_block, BasicBlock *dest);
  BasicBlock *dest();
};

class BrInst : public Instruction {
public:
  BrInst(BasicBlock *basic_block, Value *cond, BasicBlock *iftrue, BasicBlock *iffase);
  Value *cond();
  BasicBlock *iftrue();
  BasicBlock *iffalse();
};

class UnaryInst : public Instruction {
public:
  UnaryInst(BasicBlock *basic_block, IType itype, Type *type, const std::string &name, Value *rhs);
  Value *rhs();
};

class BinaryInst : public Instruction {
public:
  BinaryInst(BasicBlock *basic_block, IType itype, Type *type, const std::string &name, Value *lhs, Value *rhs);
  Value *lhs();
  Value *rhs();
};

class AllocaInst : public Instruction {
public:
  AllocaInst(BasicBlock *basic_block, const std::string &name, Type *type);
};

class LoadInst : public Instruction {
public:
  LoadInst(BasicBlock *basic_block, const std::string &name, Value *addr);
  Value *addr();
};

class StoreInst : public Instruction {
public:
  StoreInst(BasicBlock *basic_block, Value *value, Value *addr);
  Value *value();
  Value *addr();
};

class AddrAddInst : public Instruction {
public:
  AddrAddInst(BasicBlock *basic_block, const std::string &name, Value *addr, Value *offset);
  Value *addr();
  Value *offset();
};

class AddrDerefAddInst : public Instruction {
public:
  AddrDerefAddInst(BasicBlock *basic_block, const std::string &name, Value *addr, Value *offset);
  Value *addr();
  Value *offset();
};

class IcmpInst : public Instruction {
public:
  IcmpInst(BasicBlock *basic_block, IType itype, const std::string &name, Value *lhs, Value *rhs);
  Value *lhs();
  Value *rhs();
};

class FcmpInst : public Instruction {
public:
  FcmpInst(BasicBlock *basic_block, IType itype, const std::string &name, Value *lhs, Value *rhs);
  Value *lhs();
  Value *rhs();
};

class PhiInst : public Instruction {
public:
  PhiInst(BasicBlock *basic_block, Type *type, const std::string &name);
  Value *value(size_t index);
  Value *incoming(size_t index);
  void newIncoming(Value *value, BasicBlock *basic_block);
  void removeIncomingByBB(BasicBlock *bb);
};

class CallInst : public Instruction {
public:
  CallInst(BasicBlock *basic_block, const std::string &name, Function *callee, const std::vector<Value *> &arguments);
  Function *callee();
  Util::Range<std::vector<std::shared_ptr<IR::Use>>::iterator> arguments();
  bool purecall();
};

}  // namespace IR

#endif
