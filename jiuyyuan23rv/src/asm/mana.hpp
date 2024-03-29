#ifndef __RISCV_MANA_HPP__
#define __RISCV_MANA_HPP__

#include <unordered_set>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "reg.hpp"

namespace RISCV {
// register manager
class Mana {
protected:
  std::unordered_set<std::unique_ptr<Reg>> regs;
  size_t cnt;
  Reg* get(Reg::DType dtype, size_t id, size_t size_of = 8);

  std::unordered_map<IR::AllocaInst*, Reg*> _alloca_reg;
  std::unordered_map<Reg*, IR::AllocaInst*> _reg_alloca;

  std::unordered_map<IR::Constant*, Reg*> _constant_reg;
  std::unordered_map<Reg*, IR::Constant*> _reg_constant;

  std::unordered_map<IR::GlobalAddr*, Reg*> _global_reg;
  std::unordered_map<Reg*, IR::GlobalAddr*> _reg_global;

  std::unordered_map<Reg*, IR::Argument*> _reg_param;
  std::unordered_map<IR::Argument*, Reg*> _param_reg;
  
  std::unordered_map<IR::Value*, Reg*> _variable_reg;
  std::unordered_map<Reg*, IR::Value*> _reg_variable;

public:
  Mana();
  // std::unordered_map<IR::Constant*, Reg*>& constants();
  // std::unordered_map<IR::Variable*, Reg*>& globals();
  // std::unordered_map<IR::Value*, Reg*>& variables();
  std::unordered_map<IR::AllocaInst*, Reg*>& allocaReg() {
    return _alloca_reg;
  }
  std::unordered_map<Reg*, IR::AllocaInst*>& regAlloca() {
    return _reg_alloca;
  }
  std::unordered_map<IR::Constant*, Reg*>& constantReg() {
    return _constant_reg;
  }
  std::unordered_map<Reg*, IR::Constant*>& regConstant() {
    return _reg_constant;
  }
  std::unordered_map<IR::GlobalAddr*, Reg*>& globalReg() {
    return _global_reg;
  }
  std::unordered_map<Reg*, IR::GlobalAddr*>& regGlobal() {
    return _reg_global;
  }
  std::unordered_map<Reg*, IR::Argument*>& regParam() {
    return _reg_param;
  }
  std::unordered_map<IR::Argument*, Reg*>& paramReg() {
    return _param_reg;
  }
  std::unordered_map<IR::Value*, Reg*>& variableReg() {
    return _variable_reg;
  }
  std::unordered_map<Reg*, IR::Value*>& regVariable() {
    return _reg_variable;
  }
  Reg* vreg(Reg::DType dtype, size_t size_of);
  Reg* vreg(IR::Value* value);
  bool isConstant(Reg* reg);
  bool isAlloca(Reg* reg);
  bool isGlobal(Reg* reg);
  bool isParam(Reg* reg);
  bool isVariable(Reg* reg);
};

}  // namespace RISCV

#endif
