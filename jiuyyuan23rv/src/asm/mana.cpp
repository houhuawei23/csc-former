#include "mana.hpp"

namespace RISCV {

Reg* Mana::get(Reg::DType dtype, size_t id, size_t size_of) {
  // auto it = std::find_if(regs.begin(), regs.end(), [&](const std::unique_ptr<RISCV::Reg>& reg) -> bool {
  //   if (reg->dtype() != dtype) return false;
  //   if (reg->id() != id) return false;
  //   return true;
  // });
  // if (it != regs.end()) return it->get();
  Reg* reg = new Reg(Reg::VIRTUAL, dtype, id, std::max((size_t)4, size_of));
  auto res = regs.emplace(reg);
  return res.first->get();
}

Mana::Mana() : cnt(0) {
}

Reg* Mana::vreg(Reg::DType dtype, size_t size_of) {
  return get(dtype, cnt++, size_of);
}

Reg* Mana::vreg(IR::Value* value) {
  if (auto c = dynamic_cast<IR::Constant*>(value)) {
    auto it = constantReg().find(c);
    if (it != constantReg().end()) return it->second;
    if (c->type()->isFloat()) {
      Reg* reg = vreg(Reg::FREG, c->type()->sizeOf());
      regConstant()[reg] = c;
      return constantReg()[c] = reg;
    } else {
      Reg* reg = vreg(Reg::XREG, std::max((size_t)4, c->type()->sizeOf()));
      regConstant()[reg] = c;
      return constantReg()[c] = reg;
    }
  } else if (auto g = dynamic_cast<IR::GlobalAddr*>(value)) {
    auto it = globalReg().find(g);
    if (it != globalReg().end()) return it->second;
    Reg* reg = vreg(Reg::XREG, 8);
    regGlobal()[reg] = g;
    return globalReg()[g] = reg;
  } else if (auto p = dynamic_cast<IR::Argument*>(value)) {
    auto it = paramReg().find(p);
    if (it != paramReg().end()) return it->second;
    if (p->type()->isFloat()) {
      Reg* reg = vreg(Reg::FREG, p->type()->sizeOf());
      regParam()[reg] = p;
      return paramReg()[p] = reg;
    } else {
      Reg* reg = vreg(Reg::XREG, std::max((size_t)4, p->type()->sizeOf()));
      regParam()[reg] = p;
      return paramReg()[p] = reg;
    }
  } else if (auto a = dynamic_cast<IR::AllocaInst*>(value)) {
    auto it = allocaReg().find(a);
    if (it != allocaReg().end()) return it->second;
    if (a->type()->isFloat()) {
      Reg* reg = vreg(Reg::FREG, a->type()->sizeOf());
      regAlloca()[reg] = a;
      return allocaReg()[a] = reg;
    } else {
      Reg* reg = vreg(Reg::XREG, std::max((size_t)4, a->type()->sizeOf()));
      regAlloca()[reg] = a;
      return allocaReg()[a] = reg;
    }
  } else {
    auto it = variableReg().find(value);
    if (it != variableReg().end()) return it->second;
    if (value->type()->isFloat()) {
      Reg* reg = vreg(Reg::FREG, std::max((size_t)4, value->type()->sizeOf()));
      regVariable()[reg] = value;
      return variableReg()[value] = reg;
    } else {
      Reg* reg = vreg(Reg::XREG, std::min(std::max(size_t(4), value->type()->sizeOf()), (size_t)8));
      regVariable()[reg] = value;
      return variableReg()[value] = reg;
    }
  }
}

bool Mana::isConstant(Reg* reg) {
  return regConstant().count(reg);
}

bool Mana::isAlloca(Reg* reg) {
  return regAlloca().count(reg);
}

bool Mana::isGlobal(Reg* reg) {
  return regGlobal().count(reg);
}

bool Mana::isParam(Reg* reg) {
  return regParam().count(reg);
}

bool Mana::isVariable(Reg* reg) {
  return regVariable().count(reg);
}

}  // namespace RISCV
