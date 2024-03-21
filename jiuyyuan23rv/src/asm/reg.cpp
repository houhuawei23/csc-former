#include "reg.hpp"

#include <cassert>
#include <string>

namespace RISCV {

Reg::Reg(RType rtype, DType dtype, size_t id, size_t size_of)
    : _rtype(rtype), _dtype(dtype), _id(id), _size_of(size_of) {
  assert(rtype == VIRTUAL || 0 <= id && id < 64);
}

Reg::RType Reg::rtype() {
  return _rtype;
}

Reg::DType Reg::dtype() {
  return _dtype;
}

size_t Reg::sizeOf() {
  return _size_of;
}

size_t Reg::id() {
  return _id;
}

bool Reg::isvreg() {
  return _rtype == VIRTUAL;
}

bool Reg::ispreg() {
  return _rtype == PHYSIC;
}

bool Reg::isxreg() {
  return _dtype == XREG;
}

bool Reg::isfreg() {
  return _dtype == FREG;
}

bool Reg::callerSave() {
  return REG_SAVER[id()] == CALLER;
}

bool Reg::calleeSave() {
  return REG_SAVER[id()] == CALLEE;
}

bool Reg::allocable() {
  return REG_SAVER[id()] == CALLER || REG_SAVER[id()] == CALLEE;
}

bool Reg::isnode() {
  return isvreg() || allocable();
}

std::string Reg::name() {
  if (rtype() == PHYSIC) return REG_NAMES[_id];
  if (dtype() == FREG) return "fv" + std::to_string(id());
  return "v" + std::to_string(id());
}

const RegSaver REG_SAVER[REG_NUM] = {
    /* zero = */ NONE,
    /* ra = */
    CALLEE,  //! 将ra视为callee_save_reg，如果存在对ra的定值，则会在函数开头保存。对于call指令，对所有caller_save_reg定值，包括ra
    /* sp = */ SPECIAL,
    /* gp = */ NONE,
    /* tp = */ NONE,
    /* t0 = */ CALLER,
    /* t1 = */ CALLER,
    /* t2 = */ CALLER,
    /* fp = */ SPECIAL,
    /* s1 = */ CALLEE,
    /* a0 = */ CALLER,
    /* a1 = */ CALLER,
    /* a2 = */ CALLER,
    /* a3 = */ CALLER,
    /* a4 = */ CALLER,
    /* a5 = */ CALLER,
    /* a6 = */ CALLER,
    /* a7 = */ CALLER,
    /* s2 = */ CALLEE,
    /* s3 = */ CALLEE,
    /* s4 = */ CALLEE,
    /* s5 = */ CALLEE,
    /* s6 = */ CALLEE,
    /* s7 = */ CALLEE,
    /* s8 = */ CALLEE,
    /* s9 = */ CALLEE,
    /* s10 = */ CALLEE,
    /* s11 = */ CALLEE,
    /* t3 = */ CALLER,
    /* t4 = */ CALLER,
    /* t5 = */ CALLER,
    /* t6 = */ CALLER,
    /* ft0 = */ CALLER,
    /* ft1 = */ CALLER,
    /* ft2 = */ CALLER,
    /* ft3 = */ CALLER,
    /* ft4 = */ CALLER,
    /* ft5 = */ CALLER,
    /* ft6 = */ CALLER,
    /* ft7 = */ CALLER,
    /* fs0 = */ CALLEE,
    /* fs1 = */ CALLEE,
    /* fa0 = */ CALLER,
    /* fa1 = */ CALLER,
    /* fa2 = */ CALLER,
    /* fa3 = */ CALLER,
    /* fa4 = */ CALLER,
    /* fa5 = */ CALLER,
    /* fa6 = */ CALLER,
    /* fa7 = */ CALLER,
    /* fs2 = */ CALLEE,
    /* fs3 = */ CALLEE,
    /* fs4 = */ CALLEE,
    /* fs5 = */ CALLEE,
    /* fs6 = */ CALLEE,
    /* fs7 = */ CALLEE,
    /* fs8 = */ CALLEE,
    /* fs9 = */ CALLEE,
    /* fs10 = */ CALLEE,
    /* fs11 = */ CALLEE,
    /* ft8 = */ CALLER,
    /* ft9 = */ CALLER,
    /* ft10 = */ CALLER,
    /* ft11 = */ CALLER,
};

const std::string REG_NAMES[REG_NUM] = {
    /* x0 = */ "zero",
    /* x1 = */ "ra",
    /* x2 = */ "sp",
    /* x3 = */ "gp",
    /* x4 = */ "tp",
    /* x5 = */ "t0",
    /* x6 = */ "t1",
    /* x7 = */ "t2",
    /* x8 = */ "s0",
    /* x9 = */ "s1",
    /* x10 = */ "a0",
    /* x11 = */ "a1",
    /* x12 = */ "a2",
    /* x13 = */ "a3",
    /* x14 = */ "a4",
    /* x15 = */ "a5",
    /* x16 = */ "a6",
    /* x17 = */ "a7",
    /* x18 = */ "s2",
    /* x19 = */ "s3",
    /* x20 = */ "s4",
    /* x21 = */ "s5",
    /* x22 = */ "s6",
    /* x23 = */ "s7",
    /* x24 = */ "s8",
    /* x25 = */ "s9",
    /* x26 = */ "s10",
    /* x27 = */ "s11",
    /* x28 = */ "t3",
    /* x29 = */ "t4",
    /* x30 = */ "t5",
    /* x31 = */ "t6",
    /* f0 = */ "ft0",
    /* f1 = */ "ft1",
    /* f2 = */ "ft2",
    /* f3 = */ "ft3",
    /* f4 = */ "ft4",
    /* f5 = */ "ft5",
    /* f6 = */ "ft6",
    /* f7 = */ "ft7",
    /* f8 = */ "fs0",
    /* f9 = */ "fs1",
    /* f10 = */ "fa0",
    /* f11 = */ "fa1",
    /* f12 = */ "fa2",
    /* f13 = */ "fa3",
    /* f14 = */ "fa4",
    /* f15 = */ "fa5",
    /* f16 = */ "fa6",
    /* f17 = */ "fa7",
    /* f18 = */ "fs2",
    /* f19 = */ "fs3",
    /* f20 = */ "fs4",
    /* f21 = */ "fs5",
    /* f22 = */ "fs6",
    /* f23 = */ "fs7",
    /* f24 = */ "fs8",
    /* f25 = */ "fs9",
    /* f26 = */ "fs10",
    /* f27 = */ "fs11",
    /* f28 = */ "ft8",
    /* f29 = */ "ft9",
    /* f30 = */ "ft10",
    /* f31 = */ "ft11",
};

Reg PHYSIC_REG[REG_NUM] = {
    Reg(Reg::PHYSIC, Reg::XREG, zero, 8), Reg(Reg::PHYSIC, Reg::XREG, ra, 8),   Reg(Reg::PHYSIC, Reg::XREG, sp, 8),
    Reg(Reg::PHYSIC, Reg::XREG, gp, 8),   Reg(Reg::PHYSIC, Reg::XREG, tp, 8),   Reg(Reg::PHYSIC, Reg::XREG, t0, 8),
    Reg(Reg::PHYSIC, Reg::XREG, t1, 8),   Reg(Reg::PHYSIC, Reg::XREG, t2, 8),   Reg(Reg::PHYSIC, Reg::XREG, fp, 8),
    Reg(Reg::PHYSIC, Reg::XREG, s1, 8),   Reg(Reg::PHYSIC, Reg::XREG, a0, 8),   Reg(Reg::PHYSIC, Reg::XREG, a1, 8),
    Reg(Reg::PHYSIC, Reg::XREG, a2, 8),   Reg(Reg::PHYSIC, Reg::XREG, a3, 8),   Reg(Reg::PHYSIC, Reg::XREG, a4, 8),
    Reg(Reg::PHYSIC, Reg::XREG, a5, 8),   Reg(Reg::PHYSIC, Reg::XREG, a6, 8),   Reg(Reg::PHYSIC, Reg::XREG, a7, 8),
    Reg(Reg::PHYSIC, Reg::XREG, s2, 8),   Reg(Reg::PHYSIC, Reg::XREG, s3, 8),   Reg(Reg::PHYSIC, Reg::XREG, s4, 8),
    Reg(Reg::PHYSIC, Reg::XREG, s5, 8),   Reg(Reg::PHYSIC, Reg::XREG, s6, 8),   Reg(Reg::PHYSIC, Reg::XREG, s7, 8),
    Reg(Reg::PHYSIC, Reg::XREG, s8, 8),   Reg(Reg::PHYSIC, Reg::XREG, s9, 8),   Reg(Reg::PHYSIC, Reg::XREG, s10, 8),
    Reg(Reg::PHYSIC, Reg::XREG, s11, 8),  Reg(Reg::PHYSIC, Reg::XREG, t3, 8),   Reg(Reg::PHYSIC, Reg::XREG, t4, 8),
    Reg(Reg::PHYSIC, Reg::XREG, t5, 8),   Reg(Reg::PHYSIC, Reg::XREG, t6, 8),   Reg(Reg::PHYSIC, Reg::FREG, ft0, 8),
    Reg(Reg::PHYSIC, Reg::FREG, ft1, 8),  Reg(Reg::PHYSIC, Reg::FREG, ft2, 8),  Reg(Reg::PHYSIC, Reg::FREG, ft3, 8),
    Reg(Reg::PHYSIC, Reg::FREG, ft4, 8),  Reg(Reg::PHYSIC, Reg::FREG, ft5, 8),  Reg(Reg::PHYSIC, Reg::FREG, ft6, 8),
    Reg(Reg::PHYSIC, Reg::FREG, ft7, 8),  Reg(Reg::PHYSIC, Reg::FREG, fs0, 8),  Reg(Reg::PHYSIC, Reg::FREG, fs1, 8),
    Reg(Reg::PHYSIC, Reg::FREG, fa0, 8),  Reg(Reg::PHYSIC, Reg::FREG, fa1, 8),  Reg(Reg::PHYSIC, Reg::FREG, fa2, 8),
    Reg(Reg::PHYSIC, Reg::FREG, fa3, 8),  Reg(Reg::PHYSIC, Reg::FREG, fa4, 8),  Reg(Reg::PHYSIC, Reg::FREG, fa5, 8),
    Reg(Reg::PHYSIC, Reg::FREG, fa6, 8),  Reg(Reg::PHYSIC, Reg::FREG, fa7, 8),  Reg(Reg::PHYSIC, Reg::FREG, fs2, 8),
    Reg(Reg::PHYSIC, Reg::FREG, fs3, 8),  Reg(Reg::PHYSIC, Reg::FREG, fs4, 8),  Reg(Reg::PHYSIC, Reg::FREG, fs5, 8),
    Reg(Reg::PHYSIC, Reg::FREG, fs6, 8),  Reg(Reg::PHYSIC, Reg::FREG, fs7, 8),  Reg(Reg::PHYSIC, Reg::FREG, fs8, 8),
    Reg(Reg::PHYSIC, Reg::FREG, fs9, 8),  Reg(Reg::PHYSIC, Reg::FREG, fs10, 8), Reg(Reg::PHYSIC, Reg::FREG, fs11, 8),
    Reg(Reg::PHYSIC, Reg::FREG, ft8, 8),  Reg(Reg::PHYSIC, Reg::FREG, ft9, 8),  Reg(Reg::PHYSIC, Reg::FREG, ft10, 8),
    Reg(Reg::PHYSIC, Reg::FREG, ft11, 8),
};

Reg* ZERO = &PHYSIC_REG[zero];
Reg* RA = &PHYSIC_REG[ra];
Reg* SP = &PHYSIC_REG[sp];
Reg* GP = &PHYSIC_REG[gp];
Reg* TP = &PHYSIC_REG[tp];
Reg* T0 = &PHYSIC_REG[t0];
Reg* T1 = &PHYSIC_REG[t1];
Reg* T2 = &PHYSIC_REG[t2];
Reg* S0 = &PHYSIC_REG[fp];
Reg* S1 = &PHYSIC_REG[s1];
Reg* A0 = &PHYSIC_REG[a0];
Reg* A1 = &PHYSIC_REG[a1];
Reg* A2 = &PHYSIC_REG[a2];
Reg* A3 = &PHYSIC_REG[a3];
Reg* A4 = &PHYSIC_REG[a4];
Reg* A5 = &PHYSIC_REG[a5];
Reg* A6 = &PHYSIC_REG[a6];
Reg* A7 = &PHYSIC_REG[a7];
Reg* S2 = &PHYSIC_REG[s2];
Reg* S3 = &PHYSIC_REG[s3];
Reg* S4 = &PHYSIC_REG[s4];
Reg* S5 = &PHYSIC_REG[s5];
Reg* S6 = &PHYSIC_REG[s6];
Reg* S7 = &PHYSIC_REG[s7];
Reg* S8 = &PHYSIC_REG[s8];
Reg* S9 = &PHYSIC_REG[s9];
Reg* S10 = &PHYSIC_REG[s10];
Reg* S11 = &PHYSIC_REG[s11];
Reg* T3 = &PHYSIC_REG[t3];
Reg* T4 = &PHYSIC_REG[t4];
Reg* T5 = &PHYSIC_REG[t5];
Reg* T6 = &PHYSIC_REG[t6];
Reg* FT0 = &PHYSIC_REG[ft0];
Reg* FT1 = &PHYSIC_REG[ft1];
Reg* FT2 = &PHYSIC_REG[ft2];
Reg* FT3 = &PHYSIC_REG[ft3];
Reg* FT4 = &PHYSIC_REG[ft4];
Reg* FT5 = &PHYSIC_REG[ft5];
Reg* FT6 = &PHYSIC_REG[ft6];
Reg* FT7 = &PHYSIC_REG[ft7];
Reg* FS0 = &PHYSIC_REG[fs0];
Reg* FS1 = &PHYSIC_REG[fs1];
Reg* FA0 = &PHYSIC_REG[fa0];
Reg* FA1 = &PHYSIC_REG[fa1];
Reg* FA2 = &PHYSIC_REG[fa2];
Reg* FA3 = &PHYSIC_REG[fa3];
Reg* FA4 = &PHYSIC_REG[fa4];
Reg* FA5 = &PHYSIC_REG[fa5];
Reg* FA6 = &PHYSIC_REG[fa6];
Reg* FA7 = &PHYSIC_REG[fa7];
Reg* FS2 = &PHYSIC_REG[fs2];
Reg* FS3 = &PHYSIC_REG[fs3];
Reg* FS4 = &PHYSIC_REG[fs4];
Reg* FS5 = &PHYSIC_REG[fs5];
Reg* FS6 = &PHYSIC_REG[fs6];
Reg* FS7 = &PHYSIC_REG[fs7];
Reg* FS8 = &PHYSIC_REG[fs8];
Reg* FS9 = &PHYSIC_REG[fs9];
Reg* FS10 = &PHYSIC_REG[fs10];
Reg* FS11 = &PHYSIC_REG[fs11];
Reg* FT8 = &PHYSIC_REG[ft8];
Reg* FT9 = &PHYSIC_REG[ft9];
Reg* FT10 = &PHYSIC_REG[ft10];
Reg* FT11 = &PHYSIC_REG[ft11];

Reg* ARG_XREG[ARG_XREG_NUM] = {
    A0, A1, A2, A3, A4, A5, A6, A7,
};

Reg* ARG_FREG[ARG_FREG_NUM] = {
    FA0, FA1, FA2, FA3, FA4, FA5, FA6, FA7,
};

Reg* CALLER_SAVE_REG[CALLER_SAVE_REG_NUM] = {
    T0,  T1,  T2,  A0,  A1,  A2,  A3,  A4,  A5,  A6,
    A7,  T3,  T4,  T5,  T6,  FT0,  FT1,  FT2,FT3, FT4,
    FT5, FT6, FT7, FA0, FA1, FA2, FA3, FA4, FA5, FA6,
     FA7, FT8, FT9, FT10, FT11,
};

Reg* CALLEE_SAVE_REG[CALLEE_SAVE_REG_NUM] = {
    RA, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, FS0, FS1, FS2, FS3, FS4, FS5, FS6, FS7, FS8, FS9, FS10, FS11,
};

}  // namespace RISCV
