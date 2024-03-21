#ifndef __TYPESYSTEM_HPP__
#define __TYPESYSTEM_HPP__

#include <vector>
#include <string>
#include <memory>

namespace IR {

typedef enum : size_t {
  VOID,
  I1,
  I32,
  FLOAT,
  LABEL,
  POINTER,
  ARRAY,
  FUNCTION,
  UNDEFINE,
} BType;

typedef enum : size_t {
  RET,
  JMP,
  BR,
  FNEG,
  ADD,
  FADD,
  SUB,
  FSUB,
  MUL,
  FMUL,
  SDIV,
  FDIV,
  SREM,
  SHL,
  LSHR,
  ASHR,
  AND,
  OR,
  XOR,
  ALLOCA,
  LOAD,
  STORE,
  ADDRADD,
  ADDRDEREFADD,
  TRUNC,
  ZEXT,
  SEXT,
  FPTRUNC,
  FPEXT,
  FPTOSI,
  SITOFP,
  PTRTOINT,
  INTTOPTR,
  IEQ,
  INE,
  ISGT,
  ISGE,
  ISLT,
  ISLE,
  FOEQ,
  FONE,
  FOGT,
  FOGE,
  FOLT,
  FOLE,
  PHI,
  CALL,
} IType;

class Type;
class PointerType;
class ArrayType;
class FunctionType;

class Type {
protected:
  BType _btype;
  Type(BType btype);
  virtual ~Type() = default;

public:
  static Type *void_t();
  static Type *i1_t();
  static Type *i32_t();
  static Type *float_t();
  static Type *label_t();
  static Type *undefine_t();
  static Type *pointer_t(Type *base);
  static Type *array_t(Type *base, size_t dim);
  static Type *function_t(Type *ret_type, const std::vector<Type *> &param_types = {});
  bool in(const std::vector<Type *> &types);
  bool notin(const std::vector<Type *> &types);
  bool is(Type *type);
  bool isnot(Type *type);
  bool isVoid();
  bool isI1();
  bool isI32();
  bool isFloat();
  bool isLabel();
  bool isUndefine();
  bool isPointer();
  bool isArray();
  bool isFunction();
  virtual Type *btype();
  virtual std::string name();
  virtual size_t sizeOf();
  virtual size_t size();
  virtual size_t refSize();
  virtual Type *deref(size_t deref);
  virtual size_t dim();
  virtual Type *toPointer();
  virtual Type *retType();
  virtual std::vector<Type *> &argumentTypes();
};

class PointerType : public Type {
protected:
  Type *_base;
  PointerType(Type *base);

public:
  static PointerType *get(Type *base);
  Type *btype() override;
  size_t refSize() override;
  Type *deref(size_t deref_size) override;
  std::string name() override;
};

class ArrayType : public Type {
protected:
  Type *_base;
  size_t _dim;
  size_t _size;
  ArrayType(Type *base, size_t dim);

public:
  static ArrayType *get(Type *base, size_t dim);
  Type *btype() override;
  std::string name() override;
  size_t sizeOf() override;
  size_t size() override;
  size_t refSize() override;
  Type *deref(size_t deref_size) override;
  size_t dim() override;
  Type *toPointer() override;
};

class FunctionType : public Type {
protected:
  Type *_ret_type;
  std::vector<Type *> _argument_types;
  FunctionType(Type *ret, const std::vector<Type *> &param_types);

public:
  Type *retType() override;
  std::vector<Type *> &argumentTypes() override;
  static FunctionType *get(Type *ret, const std::vector<Type *> &param_types);
  std::string name() override;
};

}  // namespace IR

#endif
