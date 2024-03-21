#include "typesystem.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace IR {

/// @brief Type
Type::Type(BType btype) : _btype(btype) {
}

Type *Type::void_t() {
  static Type void_type(VOID);
  return &void_type;
}

Type *Type::i1_t() {
  static Type i1_type(I1);
  return &i1_type;
}

Type *Type::i32_t() {
  static Type i32_type(I32);
  return &i32_type;
}

Type *Type::float_t() {
  static Type float_type(FLOAT);
  return &float_type;
}

Type *Type::label_t() {
  static Type label_type(LABEL);
  return &label_type;
}

Type *Type::undefine_t() {
  static Type undefine_type(UNDEFINE);
  return &undefine_type;
}

Type *Type::pointer_t(Type *base) {
  return PointerType::get(base);
}

Type *Type::array_t(Type *base, size_t dim) {
  return ArrayType::get(base, dim);
}

Type *Type::function_t(Type *ret, const std::vector<Type *> &param_types) {
  return FunctionType::get(ret, param_types);
}

bool Type::in(const std::vector<Type *> &types) {
  for (const auto &type : types)
    if (this == type) return true;
  return false;
}

bool Type::notin(const std::vector<Type *> &types) {
  for (const auto &type : types)
    if (this == type) return false;
  return true;
}

bool Type::is(Type *type) {
  return this == type;
}

bool Type::isnot(Type *type) {
  return this != type;
}

bool Type::isVoid() {
  return _btype == VOID;
}

bool Type::isI1() {
  return _btype == I1;
}

bool Type::isI32() {
  return _btype == I32;
}

bool Type::isFloat() {
  return _btype == FLOAT;
}

bool Type::isLabel() {
  return _btype == LABEL;
}

bool Type::isUndefine() {
  return _btype == UNDEFINE;
}

bool Type::isPointer() {
  return _btype == POINTER;
}

bool Type::isArray() {
  return _btype == ARRAY;
}

bool Type::isFunction() {
  return _btype == FUNCTION;
}

Type *Type::btype() {
  switch (_btype) {
    case VOID:
    case I1:
    case I32:
    case FLOAT:
    case LABEL:
    case UNDEFINE:
    case FUNCTION:
      return this;
    default:
      assert(0);
  }
}

std::string Type::name() {
  switch (_btype) {
    case VOID:
      return "void";
    case I1:
      return "i1";
    case I32:
      return "i32";
    case FLOAT:
      return "float";
    case LABEL:
      return "label";
    case POINTER:
      return "ptr";
    default:
      assert(0);
  }
}
size_t Type::sizeOf() {
  switch (_btype) {
    case I1:
      return 1;
    case I32:
    case FLOAT:
      return 4;
    case POINTER:
    case FUNCTION:
      return 8;
    default:
      assert(0);
  }
}

size_t Type::size() {
  switch (_btype) {
    case VOID:
    case I1:
    case I32:
    case FLOAT:
    case LABEL:
    case POINTER:
    case FUNCTION:
      return 1;
    default:
      assert(0);
  }
}

size_t Type::refSize() {
  switch (_btype) {
    case VOID:
    case I1:
    case I32:
    case FLOAT:
    case LABEL:
    case FUNCTION:
      return 0;
    default:
      assert(0);
  }
}

Type *Type::deref(size_t deref) {
  if (deref == 0) return this;
  assert(0);
}

size_t Type::dim() {
  assert(0);
}

Type *Type::toPointer() {
  assert(0);
}

Type *Type::retType() {
  assert(0);
}

std::vector<Type *> &Type::argumentTypes() {
  assert(0);
}

/// @brief PointerType
PointerType::PointerType(Type *base) : Type(POINTER), _base(base) {
}

PointerType *PointerType::get(Type *base) {
  static std::unordered_map<Type *, std::unique_ptr<PointerType>> pointer_types;
  if (auto it = pointer_types.find(base); it != pointer_types.end()) return (it->second).get();
  return pointer_types.emplace(base, new PointerType(base)).first->second.get();
}

Type *PointerType::btype() {
  return deref(1)->btype();
}

size_t PointerType::refSize() {
  return 1 + _base->refSize();
}

Type *PointerType::deref(size_t deref_size) {
  if (deref_size == 0) return this;
  return _base->deref(deref_size - 1);
}

std::string PointerType::name() {
  return deref(1)->name() + '*';
}

/// @brief ArrayType
ArrayType::ArrayType(Type *base, size_t dim) : Type(ARRAY), _base(base), _dim(dim), _size(_base->size() * dim) {
}
ArrayType *ArrayType::get(Type *base, size_t dim) {
  static std::unordered_set<std::unique_ptr<ArrayType>> array_types;
  if (auto it = std::find_if(array_types.begin(), array_types.end(),
                             [&](auto &array_type) -> bool {
                               if (base != array_type->_base) return false;
                               if (dim != array_type->dim()) return false;
                               return true;
                             });
      it != array_types.end())
    return it->get();
  return array_types.emplace(new ArrayType(base, dim)).first->get();
}

Type *ArrayType::btype() {
  return deref(1)->btype();
}

std::string ArrayType::name() {
  return '[' + std::to_string(dim()) + " x " + deref(1)->name() + ']';
}

size_t ArrayType::sizeOf() {
  return _dim * _base->sizeOf();
}

size_t ArrayType::size() {
  return _size;
}

size_t ArrayType::refSize() {
  return 1 + _base->refSize();
}

Type *ArrayType::deref(size_t deref_size) {
  if (deref_size == 0) return this;
  return _base->deref(deref_size - 1);
}

size_t ArrayType::dim() {
  return _dim;
}

Type *ArrayType::toPointer() {
  return PointerType::get(_base);
}

/// @brief FuncType
FunctionType::FunctionType(Type *ret_type, const std::vector<Type *> &param_types)
    : Type(FUNCTION), _ret_type(ret_type), _argument_types(param_types) {
}

FunctionType *FunctionType::get(Type *ret_type, const std::vector<Type *> &argument_types) {
  static std::unordered_set<std::unique_ptr<FunctionType>> func_types;
  if (auto it = find_if(func_types.begin(), func_types.end(),
                        [&](const std::unique_ptr<FunctionType> &func_type) -> bool {
                          if (ret_type != func_type->retType()) return false;
                          if (argument_types.size() != func_type->argumentTypes().size()) return false;
                          return equal(argument_types.begin(), argument_types.end(),
                                       func_type->argumentTypes().begin());
                        });
      it != func_types.end())
    return it->get();
  return func_types.emplace(new FunctionType(ret_type, argument_types)).first->get();
}

Type *FunctionType::retType() {
  return _ret_type;
}

std::vector<Type *> &FunctionType::argumentTypes() {
  return _argument_types;
}

std::string FunctionType::name() {
  return _ret_type->name() + "(" +
         std::accumulate(_argument_types.begin(), _argument_types.end(), std::string(""),
                         [&](const std::string &acc, Type *type) -> std::string {
                           return acc + (acc.length() ? ", " : "") + type->name();
                         }) +
         ")";
}

}  // namespace IR
