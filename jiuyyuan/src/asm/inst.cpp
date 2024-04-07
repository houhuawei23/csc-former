#include "inst.hpp"

namespace RISCV {

bool validShortImm(int32_t imm) {
  return (((-(1 << 11)) <= (imm)) && ((imm) <= ((1 << 11) - 1)));
}

bool validLongImm(int32_t imm) {
  return (((-(1 << 19)) <= (imm)) && ((imm) <= ((1 << 19) - 1)));
}

size_t align(size_t size, size_t align) {
  return size % align == 0 ? size : (size / align + 1) * align;
}

Inst::Inst(const std::vector<Reg*>& regs) : _regs(regs) {
}

Inst::Inst(const std::vector<Reg*>& regs, int32_t imm) : _regs(regs), _imm(imm) {
}

Inst::Inst(const std::vector<Reg*>& regs, const std::string& label) : _regs(regs), _label(label) {
}

Reg* RdInst::rd() {
  return _regs[0];
}

Reg* Rs1Inst::rs1() {
  return _regs[1];
}

Reg* Rs2Inst::rs2() {
  return _regs[2];
}

int32_t ImmInst::imm() {
  return _imm;
}

std::string LabelInst::label() {
  return _label;
}

}  // namespace RISCV
