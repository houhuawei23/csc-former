#ifndef __RISCV_GENERATOR_HPP__
#define __RISCV_GENERATOR_HPP__

#include "core.hpp"
#include "global.hpp"

namespace RISCV {

class Generator {
private:
  Program *_program;
  const std::string_view IDENT = "  ";

public:
  Generator(RISCV::Program *program);
  void generate(LogLevel log_level);
  void generate(RISCV::Program *program);
  // void generate(const std::string &builtin_function);
  void generate(RISCV::Function *function);
  void generate(RISCV::Block *block);
  void generate(RISCV::Inst *inst);
  void generate(RISCV::GlobalValue *global_value);
};

}  // namespace RISCV

#endif
