#ifndef __INFRASTRUCTURE_HPP__
#define __INFRASTRUCTURE_HPP__

#include <functional>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <variant>

#include "SCEV.hpp"
#include "userelation.hpp"
#include "util.hpp"

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
  Constant(Type *type, const std::string &name);
  Constant(bool boolean);
  Constant(int32_t integer);
  Constant(float float_point);
  static Constant *getUndefine();
  static Constant *getVoid();
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
  bool isBool();
  bool getBoolVal();
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

class Variable {
protected:
  bool _is_global_variable;
  bool _is_constant;
  Type *_type;
  std::string _name;
  Value *_addr;
  std::vector<std::unique_ptr<InitialValue>> _initializer;

public:
  Variable(bool is_global_variable, bool is_constant, Type *type, const std::string &name, Value *addr);
  bool isGlobalVariable();
  bool isConstant();
  bool isCompileTimeValue();
  std::vector<std::unique_ptr<InitialValue>> &initializer();
  Type *type() {
    return _type;
  }
  std::string &name() {
    return _name;
  }
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

  void setBasicBlock(BasicBlock *basic_block) {
    _basic_block = basic_block;
  }
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
  void resetBB(BasicBlock *bb) {
    _basic_block = bb;
  }
  // void setBasicBlock(BasicBlock *bb);

  bool isCommutative();
  static bool isReverse(Instruction *x, Instruction *y);
};

#include <unordered_set>


class BasicBlock : public Value {
public:
  BasicBlock *idom;
  BasicBlock *sdom;
  std::vector<BasicBlock *> domTree;
  std::vector<BasicBlock *> domFrontier;
  int domLevel;
  std::set<BasicBlock *> dom; /* dom_frontier dom */

  std::unordered_map<const Instruction *, int> rank;
  // std::unordered_set<std::pair<Value *, size_t>> livein;
  // std::unordered_set<std::pair<Value *, size_t>> liveout;
  // std::unordered_set<std::pair<Value *, size_t>> liveuse;
  // std::unordered_set<std::pair<Value *, size_t>> livedef;
  std::unordered_set<IR::Value *> liveIn;
  std::unordered_set<IR::Value *> liveOut;
  std::unordered_set<IR::Value *> liveUse;
  std::unordered_set<IR::Value *> liveDef;

protected:
  Function *_function;
  std::list<std::unique_ptr<Instruction>> _instructions;
  std::list<BasicBlock *> _predecessors;
  std::list<BasicBlock *> _successors;
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
  static void BasicBlockDfsPost(BasicBlock *bb, std::function<bool(BasicBlock *)> cond,
                                std::function<void(BasicBlock *)> action) {
    if (cond(bb)) return;
    for (auto succ : bb->successors()) BasicBlockDfsPost(succ, cond, action);
    action(bb);
  }
  BasicBlock(Function *function, const std::string &name);
  Function *function();
  void setFunction(Function *func) {
    _function = func;
  }
  // std::vector<BasicBlock *>& getDomTree();
  // std::vector<BasicBlock *>& getDomFrontier();
  std::list<std::unique_ptr<Instruction>> &instructions();
  std::list<BasicBlock *> &predecessors();
  std::list<BasicBlock *> &successors();
  bool isExit() {
    return _is_exit;
  }
  void setIsExit(bool is_exit) {
    _is_exit = is_exit;
  }
  void replaceInstBy(Instruction *oldInst, Instruction *inst) {
    instructions().pop_back();
    instructions().emplace_back(inst);
  }
  static void DomTreeDfsPost(BasicBlock *bb, std::function<bool(BasicBlock *)> cond,
                             std::function<void(BasicBlock *)> action);
  // static void BasicBlockDfsPost(BasicBlock *bb, std::function<bool(BasicBlock *)> cond,
  //                               std::function<void(BasicBlock *)> action) {
  //   if (cond(bb)) return;
  //   for (auto succ : bb->successors()) BasicBlockDfsPost(succ, cond, action);
  //   action(bb);
  // }

  void setrank(Instruction *inst, int _rank) {
    rank[inst] = _rank;
  }

  void rankreorder() {
    rank.clear();
    int r = 0;
    for (auto &instr : _instructions) {
      rank[instr.get()] = r++;
    }
  }
  int getRank(const Instruction *instr) {
    return rank[instr];
  }

  void insertBeforeTerminal(Instruction *instr) {
    auto iter = --_instructions.end();
    _instructions.emplace(iter, instr);
    instr->setBasicBlock(this);
  }
  void insertAfterPhi(Instruction *instr);
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

class PhiInst;
class Cycle {
private:
  IR::BasicBlock *header;
  IR::BasicBlock *latchBlock;
  IR::BasicBlock *pre_header;

public:
  int id;
  int iterationCount;
  IR::PhiInst *phi;
  IR::Value *end;
  IR::Instruction *icmp;
  std::vector<IR::BasicBlock *> nodes;
  Cycle *parentCycle;
  Function *parentFunc;
  int depth;
  // 退出基本块
  std::unordered_set<BasicBlock *> ExitingBlocks;
  // 后继基本块
  std::unordered_set<BasicBlock *> ExitBlocks;
  std::unordered_set<BasicBlock *> bb_sets;

  std::vector<Cycle *> subLoops;
  std::vector<std::pair<Instruction *, SCEV>> SCEVCheck;
  // Default constructor
  Cycle(BasicBlock *Header)
      : header(Header),
        iterationCount(0),
        phi(nullptr),
        end(nullptr),
        icmp(nullptr),
        parentCycle(nullptr),
        parentFunc(Header->function()) {
    nodes.push_back(Header);
    bb_sets.insert(Header);
  }
  Cycle() {
    id = -1;
    parentCycle = NULL;
    depth = 0;
  }

  // Parameterized constructor
  Cycle(int id, std::vector<IR::BasicBlock *> nodes, Cycle *parentCycle, int depth) {
    this->id = id;
    this->nodes = nodes;
    this->parentCycle = parentCycle;
    this->depth = depth;
  }
  void setHeader(BasicBlock *Header) {
    header = Header;
  }
  void setLatch(BasicBlock *latch) {
    latchBlock = latch;
  }
  BasicBlock *Header() {
    return header;
  }
  BasicBlock *Latch() {
    return latchBlock;
  }
  SCEV &getSCEV(Instruction *instr);
  bool hasSCEV(Instruction *instr);
  bool isLoopInvariant(Value *val);
  void logupSCEV(Instruction *inst, SCEV scev);
  using scev_iterator = std::unordered_map<Instruction *, SCEV>::iterator;
  auto getSCEV() {
    return Util::range(SCEVCheck.begin(), SCEVCheck.end());
  }
  Cycle *getLoopCopy(Cycle *loop, std::unordered_map<Value *, Value *> &LoopValueCpy,
                     std::unordered_map<PhiInst *, Value *> &CurrentIncomingValue);
  BasicBlock *Pre_Header() {
    return pre_header;
  }
  void setPre_Header(BasicBlock *Pre_Header) {
    pre_header = Pre_Header;
  }
};

class LoadInst;
class StoreInst;

using Cycles = typename std::vector<Cycle *>;
class CallInst;
class Function : public Value {
protected:
  CompileUnit *_compile_unit;
  bool _is_declaration;
  bool _side_effect = true;
  bool redosilf = false;
  size_t _xarg_num;
  size_t _farg_num;
  std::list<std::unique_ptr<Argument>> _arguments;
  std::list<std::unique_ptr<BasicBlock>> _basic_blocks;
  BasicBlock *_allocas;
  BasicBlock *_entry;
  std::list<BasicBlock *> _exits;
  Cycles _cycles;
  std::unordered_map<BasicBlock *, Cycle *> bbToLoop;
  std::vector<Cycle *> topLoops;

  std::set<Function *> caller, callee;  // 调用者，被调用者
  std::vector<CallInst *> callSite;
  std::set<GlobalAddr *> storeG, loadG;

public:
  Function(CompileUnit *compile_unit, bool is_declaration, Type *type, const std::string &name);
  CompileUnit *compileUnit();
  bool isDeclaration();
  bool sideEffect();
  void setSideEffect(bool side_effect) {
    _side_effect = side_effect;
  }
  std::pair<IR::Value *, size_t> getDef(IR::StoreInst *def);
  std::pair<IR::Value *, size_t> getUse(IR::LoadInst *use);
  void calcLive();
  std::list<std::unique_ptr<Argument>> &arguments();
  std::list<std::unique_ptr<BasicBlock>> &basicBlocks();
  BasicBlock *allocas();
  BasicBlock *entry();
  std::list<BasicBlock *> &exits();
  Argument *newArgument(Type *type, const std::string &name);
  BasicBlock *newBasicBlock();
  Cycles &cycles();
  void clearLinkOfBBToLoop() {
    bbToLoop.clear();
  }
  void linkBBToLoop(BasicBlock *bb, Cycle *loop) {
    bbToLoop[bb] = loop;
  };
  Cycle *getLoopOfBB(BasicBlock *bb) {
    if (bbToLoop.count(bb))
      return bbToLoop[bb];
    else
      return nullptr;
  }
  std::vector<Cycle *> &getTopLoops() {
    return topLoops;
  }
  // function inline
  Function *functionCopy();
  std::set<Function *> &getCaller() {
    return caller;
  }
  std::set<Function *> &getCallee() {
    return callee;
  }
  std::vector<CallInst *> &getCallSite() {
    return callSite;
  }
  std::set<GlobalAddr *> &getstoreG() {
    return storeG;
  }
  std::set<GlobalAddr *> &getloadG() {
    return loadG;
  }

  void nosideef() {
    _side_effect = false;
  }
  void setredosilf() {
    redosilf = true;
  }

  bool isrecursive() {
    return redosilf;
  }

  void clearFunction() {
    _allocas->instructions().clear();
    _allocas = nullptr;
    _entry->instructions().clear();
    _entry = nullptr;
    _basic_blocks.clear();
  }
  void setAllocas(BasicBlock *bb) {
    _allocas = bb;
  }
  void setEntry(BasicBlock *bb) {
    _entry = bb;
  }
};

class VariableTable {
public:
  VariableTable *_father;
  VariableTable() : _father(nullptr) {
  }
  VariableTable *father() {
    return _father;
  }
  void setFather(VariableTable *variable_table) {
    _father = variable_table;
  }
  std::unordered_map<std::string, std::unique_ptr<Variable>> _table;
  std::unordered_map<std::string, std::unique_ptr<Variable>> &table() {
    return _table;
  }
};

class CompileUnit {
protected:
  std::list<std::unique_ptr<Function>> _function_table;
  std::unique_ptr<VariableTable> _global_variable_table;
  VariableTable *_current_variable_table;

public:
  CompileUnit();
  std::list<std::unique_ptr<Function>> &functionTable();

  VariableTable *globalVariableTable();
  bool isGlobalScope();
  void enterScope();
  void leaveScope();
  Function *function(const std::string &name);
  Function *newFunction(bool is_declaration, Type *type, const std::string &name);
  Variable *rvariable(const std::string &name);
  Variable *variable(const std::string &name);
  Variable *newVariable(bool is_constant, const std::string &name, Value *addr);
  Function *getFuncByName(const std::string &name);
};

}  // namespace IR

#endif
