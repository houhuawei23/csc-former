#ifndef __RISCV_DIRECTIVE_HPP__
#define __RISCV_DIRECTIVE_HPP__

#include <memory>
#include <string>
#include <vector>

namespace RISCV {

class Directive {
public:
  typedef enum : size_t {
    ZERO,
    WORD,
  } DType;

protected:
  DType _dtype;
  int32_t _value;

public:
  Directive(DType dtype, int32_t value);
  DType dtype();
  int32_t value();
};

class GlobalValue {
public:
  typedef enum : size_t {
    BSS,
    RODATA,
    DATA,
  } MType;

protected:
  MType _mtype;
  size_t _size_of;
  std::string _name;
  std::vector<std::unique_ptr<Directive>> _directives;

public:
  GlobalValue(MType mtype, size_t size, const std::string& name);
  MType mtype() {
    return _mtype;
  }
  std::string name();
  size_t sizeOf() {
    return _size_of;
  }
  std::vector<std::unique_ptr<Directive>>& directives();
  Directive* newDirective(Directive* directive);
};

}  // namespace RISCV

#endif
