#include "directive.hpp"

using namespace RISCV;

#include <memory>

/// @brief Directive
Directive::Directive(DType dtype, int32_t value) : _dtype(dtype), _value(value) {
}
Directive::DType Directive::dtype() {
  return _dtype;
}
int32_t Directive::value() {
  return _value;
}

/// @brief GlobalValue
GlobalValue::GlobalValue(MType mtype, size_t size_of, const std::string& label)
    : _mtype(mtype), _size_of(size_of), _name(label) {
}
std::string GlobalValue::name() {
  return _name;
}
std::vector<std::unique_ptr<Directive>>& GlobalValue::directives() {
  return _directives;
}
Directive* GlobalValue::newDirective(Directive* directive) {
  directives().emplace_back(directive);
  return directives().back().get();
}
