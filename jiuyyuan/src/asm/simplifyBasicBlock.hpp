#ifndef __RISCV_simplifyBasicBlock_HPP__
#define __RISCV_simplifyBasicBlock_HPP__
#include "core.hpp"
#include "util.hpp"
namespace RISCV {
  void mergeBB(Function* func);
  void removeBranch(Function* func);
}
#endif
