#include "infrastructure.hpp"

#include <cassert>
#include <queue>
#include <unordered_map>

#include "instruction.hpp"

namespace IR {

/// @brief Constant
Constant::Constant(Type *type, const std::string &name) : Value(type, name) {
}

Constant::Constant() : Value(Type::void_t(), "") {
}

Constant::Constant(bool boolean) : Value(Type::i1_t(), std::to_string(boolean)), _field(boolean) {
}

Constant::Constant(int32_t integer) : Value(Type::i32_t(), std::to_string(integer)), _field(integer) {
}

Constant::Constant(float float_point) : Value(Type::float_t(), std::to_string(float_point)), _field(float_point) {
}

Constant *Constant::getUndefine() {
  static Constant *UNDEFINE = new Constant(Type::undefine_t(), "undefine");
  return UNDEFINE;
}

Constant *Constant::getVoid() {
  static Constant *VOID = new Constant();
  return VOID;
}

Constant *Constant::get(bool boolean) {
  static Constant *TRUE = new Constant(true);
  static Constant *FALSE = new Constant(false);
  return boolean ? TRUE : FALSE;
}

Constant *Constant::get(int32_t number) {
  static std::unordered_map<int32_t, std::unique_ptr<Constant>> i32s;
  if (auto it = i32s.find(number); it != i32s.end()) return (it->second).get();
  Constant *c = new Constant((int32_t)number);
  return i32s.emplace(number, c).first->second.get();
}

Constant *Constant::get(float number) {
  static std::unordered_map<float, std::unique_ptr<Constant>> floats;
  if (auto it = floats.find(number); it != floats.end()) return (it->second).get();
  Constant *c = new Constant((float)number);
  return floats.emplace(number, c).first->second.get();
}
bool Constant::isInt() {
  if (this->getField<int32_t>()) return true;
  return false;
}
int32_t Constant::getIntVal() {
  if (this->isInt()) {
    auto val = this->getField<int32_t>();
    return *val;
  }
  assert(0);
}
bool Constant::isFloat() {
  if (this->getField<float>()) return true;
  return false;
}
float Constant::getFloatVal() {
  if (this->isFloat()) {
    auto val = this->getField<float>();
    return *val;
  }
  assert(0);
}
bool Constant::isBool() {
  if (this->getField<bool>()) return true;
  return false;
}
bool Constant::getBoolVal() {
  if (this->isBool()) {
    auto val = this->getField<bool>();
    return *val;
  }
  assert(0);
}
#define CONSTANT_CONVERT_OPERATOR_FUNCTION(op)                        \
  Constant::operator op() {                                           \
    if (_type->isI1()) return static_cast<op>(*getField<bool>());     \
    if (_type->isI32()) return static_cast<op>(*getField<int32_t>()); \
    if (_type->isFloat()) return static_cast<op>(*getField<float>()); \
    assert(0);                                                        \
  }

CONSTANT_CONVERT_OPERATOR_FUNCTION(bool)
CONSTANT_CONVERT_OPERATOR_FUNCTION(int32_t)
CONSTANT_CONVERT_OPERATOR_FUNCTION(float)

#define CONSTANT_UNARY_OPERATOR_FUNCTION(op)                            \
  Constant *operator op(Constant &rhs) {                                \
    if (auto c = rhs.getField<bool>()) return Constant::get(op(*c));    \
    if (auto c = rhs.getField<int32_t>()) return Constant::get(op(*c)); \
    if (auto c = rhs.getField<float>()) return Constant::get(op(*c));   \
    assert(0);                                                          \
  }

CONSTANT_UNARY_OPERATOR_FUNCTION(-)
CONSTANT_UNARY_OPERATOR_FUNCTION(!)

#define CONSTANT_BINARY_OPERATOR_FUNCTION(op)           \
  Constant *operator op(Constant &lhs, Constant &rhs) { \
    auto l0 = lhs.getField<bool>();                     \
    auto r0 = rhs.getField<bool>();                     \
    auto l1 = lhs.getField<int32_t>();                  \
    auto r1 = rhs.getField<int32_t>();                  \
    auto l2 = lhs.getField<float>();                    \
    auto r2 = rhs.getField<float>();                    \
    if (l0 && r0) return Constant::get((*l0)op(*r0));   \
    if (l0 && r1) return Constant::get((*l0)op(*r1));   \
    if (l0 && r2) return Constant::get((*l0)op(*r2));   \
    if (l1 && r0) return Constant::get((*l1)op(*r0));   \
    if (l1 && r1) return Constant::get((*l1)op(*r1));   \
    if (l1 && r2) return Constant::get((*l1)op(*r2));   \
    if (l2 && r0) return Constant::get((*l2)op(*r0));   \
    if (l2 && r1) return Constant::get((*l2)op(*r1));   \
    if (l2 && r2) return Constant::get((*l2)op(*r2));   \
    assert(0);                                          \
  }

CONSTANT_BINARY_OPERATOR_FUNCTION(+)
CONSTANT_BINARY_OPERATOR_FUNCTION(-)
CONSTANT_BINARY_OPERATOR_FUNCTION(*)
CONSTANT_BINARY_OPERATOR_FUNCTION(/)
CONSTANT_BINARY_OPERATOR_FUNCTION(<)
CONSTANT_BINARY_OPERATOR_FUNCTION(<=)
CONSTANT_BINARY_OPERATOR_FUNCTION(>)
CONSTANT_BINARY_OPERATOR_FUNCTION(>=)
CONSTANT_BINARY_OPERATOR_FUNCTION(==)
CONSTANT_BINARY_OPERATOR_FUNCTION(!=)
CONSTANT_BINARY_OPERATOR_FUNCTION(&&)
CONSTANT_BINARY_OPERATOR_FUNCTION(||)

Constant *operator%(Constant &lhs, Constant &rhs) {
  auto l0 = lhs.getField<int32_t>();
  auto r0 = rhs.getField<int32_t>();
  if (l0 && r0) return Constant::get(int32_t((*l0) % (*r0)));
  assert(0);
}

InitialValue::InitialValue(InitialType dtype, Value *value) : _initial_type(dtype), _value(value) {
}

InitialValue::InitialType InitialValue::initialType() {
  return _initial_type;
}

Value *InitialValue::value() {
  return _value;
}

/// @brief Variable
Variable::Variable(bool is_global_variable, bool is_constant, Type *type, const std::string &name, Value *addr)
    : _is_global_variable(is_global_variable), _is_constant(is_constant), _type(type), _name(name), _addr(addr) {
  assert(addr->type()->isPointer());
}

bool Variable::isGlobalVariable() {
  return _is_global_variable;
}

bool Variable::isConstant() {
  return _is_constant;
}

bool Variable::isCompileTimeValue() {
  return _is_global_variable && _is_constant;
}

std::vector<std::unique_ptr<InitialValue>> &Variable::initializer() {
  return _initializer;
}

Value *Variable::addr() {
  return _addr;
}

InitialValue *Variable::newInitialValue(InitialValue::InitialType initial_type, Value *value) {
  return _initializer.emplace_back(new InitialValue(initial_type, value)).get();
}

/// @brief Inst
Instruction::Instruction(BasicBlock *basic_block, IType itype, Type *type, const std::string &name)
    : User(type, name), _basic_block(basic_block), _itype(itype) {
}

BasicBlock *Instruction::basicBlock() {
  return _basic_block;
}

IType Instruction::itype() {
  return _itype;
}

std::string_view Instruction::opcode() {
  return OPCODE[_itype];
}

bool Instruction::isTerminator() {
  switch (_itype) {
    case RET:
    case JMP:
    case BR:
      return true;
    default:
      return false;
  }
}

bool Instruction::isUnary() {
  switch (_itype) {
    case FNEG:
    case TRUNC:
    case ZEXT:
    case SEXT:
    case FPTRUNC:
    case FPEXT:
    case FPTOSI:
    case SITOFP:
    case PTRTOINT:
    case INTTOPTR:
      return true;
    default:
      return false;
  }
}

bool Instruction::isBinary() {
  switch (_itype) {
    case ADD:
    case FADD:
    case SUB:
    case FSUB:
    case MUL:
    case FMUL:
    case SDIV:
    case FDIV:
    case SREM:
    case IEQ:
    case INE:
    case ISGT:
    case ISGE:
    case ISLT:
    case ISLE:
    case FOEQ:
    case FONE:
    case FOGT:
    case FOGE:
    case FOLT:
    case FOLE:
      return true;
    default:
      return false;
  }
}

bool Instruction::isBitwise() {
  switch (_itype) {
    case SHL:
    case LSHR:
    case ASHR:
    case AND:
    case OR:
    case XOR:
      return true;
    default:
      return false;
  }
}

bool Instruction::isMemory() {
  switch (_itype) {
    case ALLOCA:
    case LOAD:
    case STORE:
      return true;
    default:
      return false;
  }
}

bool Instruction::isConversion() {
  switch (_itype) {
    case TRUNC:
    case ZEXT:
    case SEXT:
    case FPTRUNC:
    case FPEXT:
    case FPTOSI:
    case SITOFP:
    case PTRTOINT:
    case INTTOPTR:
      return true;
    default:
      return false;
  }
}

bool Instruction::isCompare() {
  switch (_itype) {
    case IEQ:
    case INE:
    case ISGT:
    case ISGE:
    case ISLT:
    case ISLE:
    case FOEQ:
    case FONE:
    case FOGT:
    case FOGE:
    case FOLT:
    case FOLE:
      return true;
    default:
      return false;
  }
}

bool Instruction::isOther() {
  switch (_itype) {
    case PHI:
    case CALL:
      return true;
    default:
      return false;
  }
}
bool Instruction::isMath() {
  switch (_itype) {
    case ADD:
    case FADD:
    case SUB:
    case FSUB:
    case MUL:
    case FMUL:
    case SDIV:
    case FDIV:
    case SREM:
      return true;
    default:
      return false;
  }
}
bool Instruction::isIcmp() {
  switch (_itype) {
    case IEQ:
    case INE:
    case ISGT:
    case ISGE:
    case ISLT:
    case ISLE:
      return true;
    default:
      return false;
  }
}
bool Instruction::isFcmp() {
  switch (_itype) {
    case FOEQ:
    case FONE:
    case FOGT:
    case FOGE:
    case FOLT:
    case FOLE:
      return true;
    default:
      return false;
  }
}
void Instruction::setItype(IType _type) {
  _itype = _type;
}

bool Instruction::isCommutative() {
  return _itype == ADD || _itype == MUL || _itype == IEQ || _itype == INE || _itype == FADD || _itype == FMUL ||
         _itype == FOEQ || _itype == FONE;
}

bool Instruction::isReverse(Instruction *x, Instruction *y) {
  if ((x->itype() == ISGE && y->itype() == ISLE) || (x->itype() == ISLE && y->itype() == ISGE)) {
    return true;
  } else if ((x->itype() == ISGT && y->itype() == ISLT) || (x->itype() == ISLT && y->itype() == ISGT)) {
    return true;
  } else if ((x->itype() == FOGE && y->itype() == FOLE) || (x->itype() == FOLE && y->itype() == FOGE)) {
    return true;
  } else if ((x->itype() == FOGT && y->itype() == FOLT) || (x->itype() == FOLT && y->itype() == FOGT)) {
    return true;
  } else {
    return false;
  }
}

// void Instruction::setBasicBlock(BasicBlock* bb){
//   _basic_block=bb;
// }

/// @brief BasicBlock
BasicBlock::BasicBlock(Function *function, const std::string &name)
    : Value(Type::label_t(), name), _function(function), _is_exit(false) {
}

void BasicBlock::DomTreeDfsPost(BasicBlock *bb, std::function<bool(BasicBlock *)> cond,
                                std::function<void(BasicBlock *)> action) {
  if (cond(bb)) return;
  for (auto succ : bb->domTree) DomTreeDfsPost(succ, cond, action);
  action(bb);
}

Function *BasicBlock::function() {
  return _function;
}

std::list<std::unique_ptr<Instruction>> &BasicBlock::instructions() {
  return _instructions;
}

BasicBlock *Function::allocas() {
  return _allocas;
}

BasicBlock *Function::entry() {
  return _entry;
}

std::list<BasicBlock *> &Function::exits() {
  return _exits;
}

// std::vector<BasicBlock *> &BasicBlock::predecessors() {
//   return _predecessors;
// }

// std::vector<BasicBlock *> &BasicBlock::successors() {
//   return _successors;
// }
std::list<BasicBlock *> &BasicBlock::predecessors() {
  return _predecessors;
}

std::list<BasicBlock *> &BasicBlock::successors() {
  return _successors;
}

/// @brief GlobalAddr
GlobalAddr::GlobalAddr(Type *type, const std::string &name) : Value(type, name) {
  assert(type->isPointer());
}

/// @brief Argument
Argument::Argument(Type *type, const std::string &name, size_t index) : Value(type, name), _index(index) {
  if (type->isFloat())
    _atype = FARG;
  else if (type->isI32() || type->isPointer())
    _atype = XARG;
  else
    assert(0);
}

Argument::AType Argument::atype() {
  return _atype;
}

size_t Argument::index() {
  return _index;
}

/// @brief Function
Function::Function(CompileUnit *compile_unit, bool is_declaration, Type *type, const std::string &name)
    : Value(type, name),
      _compile_unit(compile_unit),
      _is_declaration(is_declaration),
      _side_effect(false),
      _xarg_num(0),
      _farg_num(0) {
  assert(type->isFunction());
  for (Type *argument_type : type->argumentTypes()) {
    if (argument_type->isPointer()) _side_effect = true;
  }
  if (!is_declaration) {
    _allocas = _basic_blocks.emplace_back(new BasicBlock(this, "")).get();
    _entry = _basic_blocks.emplace_back(new BasicBlock(this, "")).get();
    _allocas->instructions().emplace_back(new JmpInst(_allocas, _entry));
    _entry->predecessors().emplace_back(_allocas);
    _allocas->successors().emplace_back(_entry);
  }
}

CompileUnit *Function::compileUnit() {
  return _compile_unit;
}

bool Function::isDeclaration() {
  return _is_declaration;
}

bool Function::sideEffect() {
  return _side_effect;
}

Cycles &Function::cycles() {
  return _cycles;
}

std::list<std::unique_ptr<Argument>> &Function::arguments() {
  return _arguments;
}

std::list<std::unique_ptr<BasicBlock>> &Function::basicBlocks() {
  return _basic_blocks;
}

Argument *Function::newArgument(Type *type, const std::string &name) {
  if (type->isFloat()) return _arguments.emplace_back(new Argument(type, name, _farg_num++)).get();
  if (type->isI32() || type->isPointer()) return _arguments.emplace_back(new Argument(type, name, _xarg_num++)).get();
  assert(0);
}

BasicBlock *Function::newBasicBlock() {
  return _basic_blocks.emplace_back(new BasicBlock(this, "")).get();
}

/// @brief CompileUnit
CompileUnit::CompileUnit()
    : _global_variable_table(new VariableTable()), _current_variable_table(_global_variable_table.get()) {
}

std::list<std::unique_ptr<Function>> &CompileUnit::functionTable() {
  return _function_table;
}

VariableTable *CompileUnit::globalVariableTable() {
  return _global_variable_table.get();
}

bool CompileUnit::isGlobalScope() {
  return _current_variable_table == _global_variable_table.get();
}

void CompileUnit::enterScope() {
  auto variable_table = new VariableTable();
  variable_table->setFather(_current_variable_table);
  _current_variable_table = variable_table;
}

void CompileUnit::leaveScope() {
  _current_variable_table = _current_variable_table->father();
}

Function *CompileUnit::function(const std::string &name) {
  for (auto &f : _function_table)
    if (f->name() == name) return f.get();
  return nullptr;
}

Function *CompileUnit::newFunction(bool is_declaration, Type *type, const std::string &name) {
  if (function(name)) assert(0);  // redef
  _function_table.emplace_back(new Function(this, is_declaration, type, name));
  return _function_table.back().get();
}

Variable *CompileUnit::rvariable(const std::string &name) {
  VariableTable *walker = _current_variable_table;
  while (walker) {
    if (auto it = walker->table().find(name); it != walker->table().end()) return it->second.get();
    walker = walker->father();
  }
  return nullptr;
}

Variable *CompileUnit::variable(const std::string &name) {
  if (auto it = _current_variable_table->table().find(name); it != _current_variable_table->table().end())
    return it->second.get();
  return nullptr;
}

Variable *CompileUnit::newVariable(bool is_constant, const std::string &name, Value *addr) {
  if (_current_variable_table->table().find(name) != _current_variable_table->table().end()) assert(0);  // redef
  return _current_variable_table->table()
      .emplace(name,
               new Variable(isGlobalScope(), is_constant, addr->type()->deref(1), isGlobalScope() ? name : "", addr))
      .first->second.get();
}
Function *CompileUnit::getFuncByName(const std::string &name) {
  for (auto &func : functionTable()) {
    if (func->name() == name) {
      return func.get();
    }
  }
  return nullptr;
}

std::pair<Value *, size_t> Function::getDef(StoreInst *def) {
  if (auto i = dynamic_cast<AddrDerefAddInst *>(def->addr())) {
    if (dynamic_cast<AllocaInst *>(i->addr()) && dynamic_cast<Constant *>(i->offset())) {
      auto coffset = *dynamic_cast<Constant *>(i->offset())->getField<int32_t>();
      return {i->addr(), coffset};
    } else {
      return {nullptr, 0};
    }
  } else {
    return {nullptr, 0};
  }
}
std::pair<Value *, size_t> Function::getUse(LoadInst *use) {
  if (auto i = dynamic_cast<AddrDerefAddInst *>(use->addr())) {
    if (dynamic_cast<AllocaInst *>(i->addr()) && dynamic_cast<Constant *>(i->offset())) {
      auto coffset = *dynamic_cast<Constant *>(i->offset())->getField<int32_t>();
      return {i->addr(), coffset};
    } else {
      return {nullptr, 0};
    }
  } else {
    return {nullptr, 0};
  }
}

void Function::calcLive() {
  // std::queue<std::pair<BasicBlock *, std::pair<Value *, size_t>>> update;
  std::queue<std::pair<BasicBlock *, Value *>> update;

  for (auto &basic_block : basicBlocks()) {
    basic_block->liveUse.clear();
    basic_block->liveDef.clear();
    for (auto it = basic_block->instructions().rbegin(); it != basic_block->instructions().rend(); ++it) {
      if (auto def = dynamic_cast<StoreInst *>(it->get())) {
        auto cdef = getDef(def);
        if (cdef.first == nullptr && cdef.second == 0) {
          basic_block->liveUse.clear();
          basic_block->liveDef.insert(def);
        } else {
          std::vector<Value *> liveUseToRemove;
          for (auto use : basic_block->liveUse) {
            auto cuse = getUse(dynamic_cast<LoadInst *>(use));
            if ((cuse.first == nullptr && cuse.second == 0) || (cuse.first == cdef.first && cuse.second == cdef.second))
              liveUseToRemove.emplace_back(use);
          }
          for (auto use : liveUseToRemove) basic_block->liveUse.erase(use);
          basic_block->liveDef.insert(def);
        }
      }
      if (auto use = dynamic_cast<LoadInst *>(it->get())) {
        auto cuse = getUse(use);
        if (cuse.first == nullptr && cuse.second == 0) {
          basic_block->liveDef.clear();
          basic_block->liveUse.insert(use);
        } else {
          std::vector<Value *> liveDefToRemove;
          for (auto def : basic_block->liveDef) {
            auto cdef = getDef(dynamic_cast<StoreInst *>(def));
            if ((cdef.first == nullptr && cdef.second == 0) || (cdef.first == cuse.first && cdef.second == cuse.second))
              liveDefToRemove.emplace_back(def);
          }
          for (auto def : liveDefToRemove) basic_block->liveDef.erase(def);
          basic_block->liveUse.insert(use);
        }
      }
      for (auto x : basic_block->liveUse) update.emplace(basic_block.get(), x);
      basic_block->liveIn = basic_block->liveUse;
      basic_block->liveOut.clear();
    }
    while (update.size()) {
      auto basic_block = update.front().first;
      auto x = update.front().second;
      update.pop();
      auto cuse = getUse(dynamic_cast<IR::LoadInst *>(x));
      for (auto pred : basic_block->predecessors()) {
        if (!pred->liveOut.count(x)) {
          pred->liveOut.insert(x);
          bool flag = true;
          for (auto def : pred->liveDef) {
            auto cdef = getDef(dynamic_cast<IR::StoreInst *>(def));
            if ((cuse.first == nullptr && cuse.second == 0) || (cdef.first == nullptr && cdef.second == 0) ||
                (cuse.first == cdef.first && cuse.second == cdef.second)) {
              flag = false;
              break;
            }
          }
          if (flag && !pred->liveIn.count(x)) {
            pred->liveIn.insert(x);
            update.emplace(pred, x);
          }
          // if (!pred->liveDef.count(x) && !pred->liveIn.count(x)) {
          // pred->liveIn.insert(x);
          // update.emplace(pred, x);
          // }
        }
      }
    }
  }
}
}  // namespace IR
