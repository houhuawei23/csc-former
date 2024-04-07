#ifndef __RISCV_REG_HPP__
#define __RISCV_REG_HPP__

#include <memory>

namespace RISCV {

const size_t REG_NUM = 64;

const size_t XREG_NUM = 32;

const size_t FREG_NUM = 32;

typedef enum : size_t {
  /* x0 = */ zero = 0,
  /* x1 = */ ra = 1,
  /* x2 = */ sp = 2,
  /* x3 = */ gp = 3,
  /* x4 = */ tp = 4,
  /* x5 = */ t0 = 5,
  /* x6 = */ t1 = 6,
  /* x7 = */ t2 = 7,
  /* x8 = */ fp = 8,
  /* x9 = */ s1 = 9,
  /* x10 = */ a0 = 10,
  /* x11 = */ a1 = 11,
  /* x12 = */ a2 = 12,
  /* x13 = */ a3 = 13,
  /* x14 = */ a4 = 14,
  /* x15 = */ a5 = 15,
  /* x16 = */ a6 = 16,
  /* x17 = */ a7 = 17,
  /* x18 = */ s2 = 18,
  /* x19 = */ s3 = 19,
  /* x20 = */ s4 = 20,
  /* x21 = */ s5 = 21,
  /* x22 = */ s6 = 22,
  /* x23 = */ s7 = 23,
  /* x24 = */ s8 = 24,
  /* x25 = */ s9 = 25,
  /* x26 = */ s10 = 26,
  /* x27 = */ s11 = 27,
  /* x28 = */ t3 = 28,
  /* x29 = */ t4 = 29,
  /* x30 = */ t5 = 30,
  /* x31 = */ t6 = 31,
  /* f0 = */ ft0 = 32,
  /* f1 = */ ft1 = 33,
  /* f2 = */ ft2 = 34,
  /* f3 = */ ft3 = 35,
  /* f4 = */ ft4 = 36,
  /* f5 = */ ft5 = 37,
  /* f6 = */ ft6 = 38,
  /* f7 = */ ft7 = 39,
  /* f8 = */ fs0 = 40,
  /* f9 = */ fs1 = 41,
  /* f10 = */ fa0 = 42,
  /* f11 = */ fa1 = 43,
  /* f12 = */ fa2 = 44,
  /* f13 = */ fa3 = 45,
  /* f14 = */ fa4 = 46,
  /* f15 = */ fa5 = 47,
  /* f16 = */ fa6 = 48,
  /* f17 = */ fa7 = 49,
  /* f18 = */ fs2 = 50,
  /* f19 = */ fs3 = 51,
  /* f20 = */ fs4 = 52,
  /* f21 = */ fs5 = 53,
  /* f22 = */ fs6 = 54,
  /* f23 = */ fs7 = 55,
  /* f24 = */ fs8 = 56,
  /* f25 = */ fs9 = 57,
  /* f26 = */ fs10 = 58,
  /* f27 = */ fs11 = 59,
  /* f28 = */ ft8 = 60,
  /* f29 = */ ft9 = 61,
  /* f30 = */ ft10 = 62,
  /* f31 = */ ft11 = 63,
} RegId;

typedef enum : size_t {
  NONE,
  SPECIAL,
  CALLER,
  CALLEE,
} RegSaver;

extern const RegSaver REG_SAVER[REG_NUM];

extern const std::string REG_NAMES[REG_NUM];

class Reg {
public:
  typedef enum : size_t {
    VIRTUAL,
    PHYSIC,
  } RType;

  typedef enum : size_t {
    XREG,
    FREG,
  } DType;

protected:
  RType _rtype;
  DType _dtype;
  size_t _id;
  size_t _size_of;

public:
  Reg(RType rtype, DType dtype, size_t id, size_t size_of);
  RType rtype();
  DType dtype();
  size_t sizeOf();
  size_t id();
  bool isvreg();
  bool ispreg();
  bool isxreg();
  bool isfreg();
  bool callerSave();
  bool calleeSave();
  bool allocable();
  bool isnode();
  std::string name();
  bool operator==(const Reg& oth) {
    return _rtype == oth._rtype && _id == oth._id;
  }
};

extern Reg PHYSIC_REG[REG_NUM];

extern Reg* ZERO;
extern Reg* RA;
extern Reg* SP;
extern Reg* GP;
extern Reg* TP;
extern Reg* T0;
extern Reg* T1;
extern Reg* T2;
extern Reg* S0;
extern Reg* S1;
extern Reg* A0;
extern Reg* A1;
extern Reg* A2;
extern Reg* A3;
extern Reg* A4;
extern Reg* A5;
extern Reg* A6;
extern Reg* A7;
extern Reg* S2;
extern Reg* S3;
extern Reg* S4;
extern Reg* S5;
extern Reg* S6;
extern Reg* S7;
extern Reg* S8;
extern Reg* S9;
extern Reg* S10;
extern Reg* S11;
extern Reg* T3;
extern Reg* T4;
extern Reg* T5;
extern Reg* T6;
extern Reg* FT0;
extern Reg* FT1;
extern Reg* FT2;
extern Reg* FT3;
extern Reg* FT4;
extern Reg* FT5;
extern Reg* FT6;
extern Reg* FT7;
extern Reg* FS0;
extern Reg* FS1;
extern Reg* FA0;
extern Reg* FA1;
extern Reg* FA2;
extern Reg* FA3;
extern Reg* FA4;
extern Reg* FA5;
extern Reg* FA6;
extern Reg* FA7;
extern Reg* FS2;
extern Reg* FS3;
extern Reg* FS4;
extern Reg* FS5;
extern Reg* FS6;
extern Reg* FS7;
extern Reg* FS8;
extern Reg* FS9;
extern Reg* FS10;
extern Reg* FS11;
extern Reg* FT8;
extern Reg* FT9;
extern Reg* FT10;
extern Reg* FT11;

const size_t ARG_XREG_NUM = 8;

const size_t ARG_FREG_NUM = 8;

extern Reg* ARG_XREG[ARG_XREG_NUM];

extern Reg* ARG_FREG[ARG_FREG_NUM];

const size_t CALLER_SAVE_REG_NUM = 35;

const size_t CALLEE_SAVE_REG_NUM = 24;

extern Reg* CALLER_SAVE_REG[CALLER_SAVE_REG_NUM];

extern Reg* CALLEE_SAVE_REG[CALLEE_SAVE_REG_NUM];

}  // namespace RISCV

#endif
