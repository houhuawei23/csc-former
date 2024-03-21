#ifndef __INFRASTRUCTURE_HPP__
#define __INFRASTRUCTURE_HPP__

#include <set>
#include <unordered_map>
#include <variant>
#include <functional>
#include "userelation.hpp"

namespace IR {

class Constant;
class InitialValue;
class Variable;
class Instruction;
class BasicBlock;
class Argument;
class Function;
class CompileUnit;

class Constant : public Value {
protected:
  std::variant<bool, int32_t, float> _field;

public:
  Constant();
  Constant(bool boolean);
  Constant(int32_t integer);
  Constant(float float_point);
  static Constant *get();
  static Constant *get(bool boolean);
  static Constant *get(int32_t integer);
  static Constant *get(float float_point);
  template <typename T>
  T *getField() {
    return std::get_if<T>(&_field);
  }
  operator bool();
  operator int32_t();
  operator float();
  friend Constant *operator-(Constant &rhs);
  friend Constant *operator!(Constant &rhs);
  friend Constant *operator+(Constant &lhs, Constant &rhs);
  friend Constant *operator-(Constant &lhs, Constant &rhs);
  friend Constant *operator*(Constant &lhs, Constant &rhs);
  friend Constant *operator/(Constant &lhs, Constant &rhs);
  friend Constant *operator%(Constant &lhs, Constant &rhs);
  friend Constant *operator<(Constant &lhs, Constant &rhs);
  friend Constant *operator<=(Constant &lhs, Constant &rhs);
  friend Constant *operator>(Constant &lhs, Constant &rhs);
  friend Constant *operator>=(Constant &lhs, Constant &rhs);
  friend Constant *operator==(Constant &lhs, Constant &rhs);
  friend Constant *operator!=(Constant &lhs, Constant &rhs);
  friend Constant *operator&&(Constant &lhs, Constant &rhs);
  friend Constant *operator||(Constant &lhs, Constant &rhs);
  bool isInt();
  bool isFloat();
  int32_t getIntVal();
  float getFloatVal();
};

class InitialValue {
public:
  typedef enum : size_t {
    ZERO,
    VALUE,
  } InitialType;

protected:
  InitialType _initial_type;
  Value *_value;

public:
  InitialValue(InitialType dtype, Value *value);
  InitialType initialType();
  Value *value();
};

class Variable : public User {
protected:
  bool _is_global_variable;
  bool _is_constant;
  std::vector<std::unique_ptr<InitialValue>> _initializer;

public:
  Variable(bool is_global_variable, bool is_constant, Type *type, const std::string &name, Value *addr);
  bool isGlobalVariable();
  bool isConstant();
  bool isCompileTimeValue();
  std::vector<std::unique_ptr<InitialValue>> &initializer();
  Value *addr();
  InitialValue *newInitialValue(InitialValue::InitialType initial_type, Value *value);
};

class Instruction : public User {
public:
  static constexpr std::string_view OPCODE[47] = {
      "ret",      "br",       "br",       "fneg",     "add",      "fadd",     "sub",      "fsub",
      "mul",      "fmul",     "sdiv",     "fdiv",     "srem",     "shl",      "lshr",     "ashr",
      "and",      "or",       "xor",      "alloca",   "load",     "store",    "addradd",  "addrderefadd",
      "trunc",    "zext",     "sext",     "fptrunc",  "fpext",    "fptosi",   "sitofp",   "ptrtoint",
      "inttoptr", "icmp eq",  "icmp ne",  "icmp sgt", "icmp sge", "icmp slt", "icmp sle", "fcmp oeq",
      "fcmp one", "fcmp ogt", "fcmp oge", "fcmp olt", "fcmp ole", "phi",      "call",
  };

protected:
  BasicBlock *_basic_block;
  IType _itype;

public:
  Instruction(BasicBlock *basic_block, IType itype, Type *type, const std::string &name);
  BasicBlock *basicBlock();
  IType itype();
  std::string_view opcode();
  bool isTerminator();
  bool isUnary();
  bool isBinary();
  bool isBitwise();
  bool isMemory();
  bool isConversion();
  bool isCompare();
  bool isOther();
  bool isIcmp();
  bool isFcmp();
  bool isMath();
  void setItype(IType _type);
};

class BasicBlock : public Value {
public:
  BasicBlock *idom;
  BasicBlock *sdom;
  std::vector<BasicBlock *> domTree;
  std::vector<BasicBlock *> domFrontier;
  size_t dfn;
  int domLevel;
  std::set<BasicBlock *> dom; /* dom_frontier dom */

protected:
  Function *_function;
  std::list<std::unique_ptr<Instruction>> _instructions;
  std::vector<BasicBlock *> _predecessors;
  std::vector<BasicBlock *> _successors;
  bool _is_exit;

public:
  static void BasicBlockDfs(BasicBlock *bb, std::function<bool(BasicBlock *)> func) {
    if (func(bb)) return;
    for (auto succ : bb->successors()) BasicBlockDfs(succ, func);
  }
  static void BasicBlockDfs(BasicBlock *pre, BasicBlock *bb, std::function<bool(BasicBlock *, BasicBlock *)> func) {
    if (func(pre, bb)) return;
    for (auto succ : bb->successors()) BasicBlockDfs(bb, succ, func);
  }
  BasicBlock(Function *function, const std::string &name);
  Function *function();
  // std::vector<BasicBlock *>& getDomTree();
  // std::vector<BasicBlock *>& getDomFrontier();
  std::list<std::unique_ptr<Instruction>> &instructions();
  std::vector<BasicBlock *> &predecessors();
  std::vector<BasicBlock *> &successors();
  bool isExit() {
    return _is_exit;
  }
  void setIsExit(bool is_exit) {
    _is_exit = is_exit;
  }
};

class GlobalAddr : public Value {
public:
  GlobalAddr(Type *type, const std::string &name);
};

class Argument : public Value {
public:
  typedef enum : size_t {
    XARG,
    FARG,
  } AType;
  AType _atype;
  size_t _index;
  Argument(Type *type, const std::string &name, size_t index);
  AType atype();
  size_t index();
};

class Function : public Value {
protected:
  CompileUnit *_compile_unit;
  bool _is_declaration;
  bool _side_effect;
  size_t _xarg_num;
  size_t _farg_num;
  std::list<std::unique_ptr<Argument>> _arguments;
  std::list<std::unique_ptr<BasicBlock>> _basic_blocks;
  BasicBlock *_allocas;
  BasicBlock *_entry;
  std::list<BasicBlock *> _exits;

public:
  Function(CompileUnit *compile_unit, bool is_declaration, Type *type, const std::string &name);
  CompileUnit *compileUnit();
  bool isDeclaration();
  bool sideEffect();
  void setSideEffect(bool side_effect) {
    _side_effect = side_effect;
  }
  std::list<std::unique_ptr<Argument>> &arguments();
  std::list<std::unique_ptr<BasicBlock>> &basicBlocks();
  BasicBlock *allocas();
  BasicBlock *entry();
  std::list<BasicBlock *> &exits();
  Argument *newArgument(Type *type, const std::string &name);
  BasicBlock *newBasicBlock();
};

class CompileUnit {
protected:
  std::list<std::unique_ptr<Function>> _function_table;
  std::unordered_map<std::string, std::unique_ptr<Variable>> _global_variable_table;
  std::list<std::unique_ptr<std::unordered_map<std::string, std::unique_ptr<Variable>>>> _scope;

public:
  CompileUnit();
  std::list<std::unique_ptr<Function>> &functionTable();
  std::unordered_map<std::string, std::unique_ptr<Variable>> &globalVariableTable();
  std::list<std::unique_ptr<std::unordered_map<std::string, std::unique_ptr<Variable>>>> &scope();
  bool isGlobalScope();
  void enterScope();
  void leaveScope();
  Function *function(const std::string &name);
  Function *newFunction(bool is_declaration, Type *type, const std::string &name);
  Variable *rvariable(const std::string &name);
  Variable *variable(const std::string &name);
  Variable *newVariable(bool is_constant, const std::string &name, Value *addr);
};

}  // namespace IR

#endif
