#ifndef __IRGENERATOR_HPP__
#define __IRGENERATOR_HPP__

#include <string>

#include "global.hpp"
#include "infrastructure.hpp"

namespace IR {

class IRGenerator {
private:
  const std::string_view IDENT = "  ";
  CompileUnit *compile_unit;

public:
  IRGenerator(CompileUnit *compile_unit);
  void generate(LogLevel log_level);
  void generate(CompileUnit *compile_unit);
  void generate(Variable *global_variable);
  void generate(Function *function);
  void generate(BasicBlock *basic_block);
  void generate(Instruction *instruction);
};
}  // namespace IR

#endif
