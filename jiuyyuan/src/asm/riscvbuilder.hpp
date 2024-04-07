#ifndef __RISCV_BUILDER_HPP__
#define __RISCV_BUILDER_HPP__

#include "core.hpp"
#include "util.hpp"

namespace RISCV {

class RISCVBuilder {
private:
  Block* block;
  std::list<std::unique_ptr<Inst>>::iterator it;

public:
  RISCVBuilder() = default;
  RISCVBuilder(Block* block, std::list<std::unique_ptr<Inst>>::iterator it);

  void set(Block* block, std::list<std::unique_ptr<Inst>>::iterator it);
  Inst* newInst(Inst* inst) {
    block->insts().emplace(it, inst);
    return inst;
  }
  Inst* newMove(Reg* rd, Reg* rs1) {
    if (rd->isxreg() && rs1->isxreg()) {
      return newInst(new Target::ADDI(rd, rs1, 0));
    } else if (rd->isfreg() && rs1->isfreg()) {
      return newInst(new Target::FSGNJD(rd, rs1, rs1));
    } else {
      assert(0);
    }
  }
  void newLoadImm(Reg* rd, int32_t imm) {
    assert(rd->isxreg());
    newInst(new Pseudo::LI(rd, imm));
  }
  void newLoadImm(Reg* rd, Reg* rt, float imm) {
    assert(rd->isfreg() && rt->isxreg());
    newInst(new Pseudo::LI(rt, Util::floatToI32(imm)));
    if (rd->sizeOf() == 4) {
      newInst(new Target::FMVWX(rd, ZERO));
    } else if (rd->sizeOf() == 8) {
      newInst(new Target::FMVDX(rd, ZERO));
    } else {
      assert(0);
    }
  }
  void newLoad(Reg* rd, Reg* rs1, int32_t imm) {
    assert(rs1->isxreg() && rs1->sizeOf() == 8);
    if (validShortImm(imm)) {
      if (rd->isxreg()) {
        if (rd->sizeOf() == 4) {
          newInst(new Target::LW(rd, rs1, imm));
        } else if (rd->sizeOf() == 8) {
          newInst(new Target::LD(rd, rs1, imm));
        } else {
          assert(0);
        }
      } else if (rd->isfreg()) {
        if (rd->sizeOf() == 4) {
          newInst(new Target::FLW(rd, rs1, imm));
        } else if (rd->sizeOf() == 8) {
          newInst(new Target::FLD(rd, rs1, imm));
        } else {
          assert(0);
        }
      } else {
        assert(0);
      }
    } else {
      if (rd->isxreg()) {
        newInst(new Pseudo::LI(rd, imm));
        newInst(new Target::ADD(rd, rd, rs1));
        if (rd->sizeOf() == 4) {
          newInst(new Target::LW(rd, rd, 0));
        } else if (rd->sizeOf() == 8) {
          newInst(new Target::LD(rd, rd, 0));
        } else {
          assert(0);
        }
      } else if (rd->isfreg()) {
        Reg* rt = block->function()->mana()->vreg(Reg::XREG, 8);
        newInst(new Pseudo::LI(rt, imm));
        newInst(new Target::ADD(rt, rt, rs1));
        if (rd->sizeOf() == 4) {
          newInst(new Target::FLW(rd, rt, 0));
        } else if (rd->sizeOf() == 8) {
          newInst(new Target::FLD(rd, rt, 0));
        } else {
          assert(0);
        }
      } else {
        assert(0);
      }
    }
  }
  void newStore(Reg* rs1, Reg* rs2, int32_t imm) {
    assert(rs1->isxreg() && rs1->sizeOf() == 8);
    if (validShortImm(imm)) {
      if (rs2->isxreg()) {
        if (rs2->sizeOf() == 4) {
          newInst(new Target::SW(rs1, rs2, imm));
        } else if (rs2->sizeOf() == 8) {
          newInst(new Target::SD(rs1, rs2, imm));
        } else {
          assert(0);
        }
      } else if (rs2->isfreg()) {
        if (rs2->sizeOf() == 4) {
          newInst(new Target::FSW(rs1, rs2, imm));
        } else if (rs2->sizeOf() == 8) {
          newInst(new Target::FSD(rs1, rs2, imm));
        } else {
          assert(0);
        }
      } else {
        assert(0);
      }
    } else {
      Reg* rt = block->function()->mana()->vreg(Reg::XREG, 8);
      newInst(new Pseudo::LI(rt, imm));
      newInst(new Target::ADD(rt, rt, rs1));
      if (rs2->isxreg()) {
        if (rs2->sizeOf() == 4) {
          newInst(new Target::SW(rt, rs2, 0));
        } else if (rs2->sizeOf() == 8) {
          newInst(new Target::SD(rt, rs2, 0));
        } else {
          assert(0);
        }
      } else if (rs2->isfreg()) {
        if (rs2->sizeOf() == 4) {
          newInst(new Target::FSW(rt, rs2, 0));
        } else if (rs2->sizeOf() == 8) {
          newInst(new Target::FSD(rt, rs2, 0));
        } else {
          assert(0);
        }
      } else {
        assert(0);
      }
    }
  }
  void newFastSMul(Reg* rd, Reg* rs1, int32_t imm) {
    size_t shift = 0;
    Reg* rt = block->function()->mana()->vreg(rd->dtype(), rd->sizeOf());
    newMove(rd, ZERO);
    newMove(rt, rs1);
    while (imm) {
      if (imm & 1) {
        if (shift) {
          if (rd->sizeOf() == 4)
            newInst(new Target::SLLIW(rt, rt, shift));
          else if (rd->sizeOf() == 8)
            newInst(new Target::SLLI(rt, rt, shift));
          else
            assert(0);
          shift = 0;
        }
        if (rd->sizeOf() == 4)
          newInst(new Target::ADDW(rd, rd, rt));
        else if (rd->sizeOf() == 8)
          newInst(new Target::ADD(rd, rd, rt));
        else
          assert(0);
      }
      shift++;
      imm >>= 1;
    }
  }
  void newFastSDiv(Reg* rd, Reg* rs1, int32_t imm) {
    // TODO https://zhuanlan.zhihu.com/p/571939337
  }
};

}  // namespace RISCV

#endif
