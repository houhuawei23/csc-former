#include "infrastructure.hpp"

#include <cassert>
#include <unordered_map>

#include "instruction.hpp"

namespace IR {

/// @brief Constant
Constant::Constant() : Value(Type::void_t(), "void") {
}

Constant::Constant(bool boolean) : Value(Type::i1_t(), std::to_string(boolean)), _field(boolean) {
}

Constant::Constant(int32_t integer) : Value(Type::i32_t(), std::to_string(integer)), _field(integer) {
}

Constant::Constant(float float_point) : Value(Type::float_t(), std::to_string(float_point)), _field(float_point) {
}

Constant *Constant::get() {
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
bool Constant::isInt(){
  if(this->getField<int32_t>())return true;
  return false;
}
int32_t Constant::getIntVal(){
  if(this->isInt()){
    auto val=this->getField<int32_t>();
    return *val;
  }
  assert(0);
}
bool Constant::isFloat(){
  if(this->getField<float>())return true;
  return false;
}
float Constant::getFloatVal(){
  if(this->isFloat()){
    auto val=this->getField<float>();
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

InitialValue::InitialValue(InitialType dtype, IR::Value *value) : _initial_type(dtype), _value(value) {
}

InitialValue::InitialType InitialValue::initialType() {
  return _initial_type;
}

Value *InitialValue::value() {
  return _value;
}

/// @brief Variable
Variable::Variable(bool is_global_variable, bool is_constant, Type *type, const std::string &name, Value *addr)
    : User(type, name), _is_global_variable(is_global_variable), _is_constant(is_constant) {
  assert(addr->type()->isPointer());
  newOperand(addr);
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
  return operand(0);
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
bool Instruction::isMath(){
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
bool Instruction::isIcmp(){
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
bool Instruction::isFcmp(){
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
void Instruction::setItype(IType _type){
  _itype=_type;
}

/// @brief BasicBlock
BasicBlock::BasicBlock(Function *function, const std::string &name)
    : Value(Type::label_t(), name), _function(function), _is_exit(false) {
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

std::vector<BasicBlock *> &BasicBlock::predecessors() {
  return _predecessors;
}

std::vector<BasicBlock *> &BasicBlock::successors() {
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
  _allocas = _basic_blocks.emplace_back(new BasicBlock(this, "")).get();
  _entry = _basic_blocks.emplace_back(new BasicBlock(this, "")).get();
  _allocas->instructions().emplace_back(new JmpInst(_allocas, _entry));
  _entry->predecessors().emplace_back(_allocas);
  _allocas->successors().emplace_back(_entry);
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
CompileUnit::CompileUnit() {
}

std::list<std::unique_ptr<Function>> &CompileUnit::functionTable() {
  return _function_table;
}

std::unordered_map<std::string, std::unique_ptr<Variable>> &CompileUnit::globalVariableTable() {
  return _global_variable_table;
}

std::list<std::unique_ptr<std::unordered_map<std::string, std::unique_ptr<Variable>>>> &CompileUnit::scope() {
  return _scope;
}

bool CompileUnit::isGlobalScope() {
  return _scope.size() == 0;
}

void CompileUnit::enterScope() {
  _scope.emplace_back(new std::unordered_map<std::string, std::unique_ptr<Variable>>);
}

void CompileUnit::leaveScope() {
  _scope.pop_back();
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
  for (auto it0 = _scope.rbegin(); it0 != _scope.rend(); it0++)
    if (auto it1 = (*it0)->find(name); it1 != (*it0)->end()) return it1->second.get();
  if (auto it = _global_variable_table.find(name); it != _global_variable_table.end()) return it->second.get();
  return nullptr;
}

Variable *CompileUnit::variable(const std::string &name) {
  auto current_variable_table = _scope.size() ? _scope.back().get() : &_global_variable_table;
  if (auto t = current_variable_table->find(name); t != current_variable_table->end()) return t->second.get();
  return nullptr;
}

Variable *CompileUnit::newVariable(bool is_constant, const std::string &name, Value *addr) {
  auto current_variable_table = _scope.size() ? _scope.back().get() : &_global_variable_table;
  if (current_variable_table->find(name) != current_variable_table->end()) assert(0);  // redef
  return current_variable_table
      ->emplace(name,
                new Variable(isGlobalScope(), is_constant, addr->type()->deref(1), isGlobalScope() ? name : "", addr))
      .first->second.get();
}

}  // namespace IR
