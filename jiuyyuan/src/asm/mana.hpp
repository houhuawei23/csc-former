#ifndef __RISCV_MANA_HPP__
#define __RISCV_MANA_HPP__

#include <unordered_set>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "reg.hpp"

namespace RISCV {

class Mana {
protected:
  std::unordered_set<std::unique_ptr<Reg>> _vregs;
  std::unordered_map<IR::AllocaInst*, Reg*> _alloca_reg;
  std::unordered_map<Reg*, IR::AllocaInst*> _reg_alloca;
  std::unordered_map<IR::Constant*, Reg*> _constant_reg;
  std::unordered_map<Reg*, IR::Constant*> _reg_constant;
  std::unordered_map<IR::GlobalAddr*, Reg*> _global_reg;
  std::unordered_map<Reg*, IR::GlobalAddr*> _reg_global;
  std::unordered_map<Reg*, IR::Argument*> _reg_argument;
  std::unordered_map<IR::Argument*, Reg*> _argument_reg;
  std::unordered_map<IR::Value*, Reg*> _variable_reg;
  std::unordered_map<Reg*, IR::Value*> _reg_variable;

public:
  Mana();
  Reg* get(Reg::DType dtype, size_t id, size_t size_of = 8);
  Reg* vreg(Reg::DType dtype, size_t size_of);
  Reg* vreg(IR::Value* value);
  std::unordered_map<IR::Constant*, Reg*>& constantReg();
  std::unordered_map<Reg*, IR::Constant*>& regConstant();
  std::unordered_map<IR::AllocaInst*, Reg*>& allocaReg();
  std::unordered_map<Reg*, IR::AllocaInst*>& regAlloca();
  std::unordered_map<IR::GlobalAddr*, Reg*>& globalReg();
  std::unordered_map<Reg*, IR::GlobalAddr*>& regGlobal();
  std::unordered_map<Reg*, IR::Argument*>& regArgument();
  std::unordered_map<IR::Argument*, Reg*>& argumentReg();
  std::unordered_map<IR::Value*, Reg*>& variableReg();
  std::unordered_map<Reg*, IR::Value*>& regVariable();
  bool isConstant(Reg* reg);
  bool isAlloca(Reg* reg);
  bool isGlobal(Reg* reg);
  bool isArgument(Reg* reg);
  bool isVariable(Reg* reg);
};

}  // namespace RISCV

#endif
