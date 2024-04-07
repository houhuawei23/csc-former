#ifndef __RISCV_INST_HPP__
#define __RISCV_INST_HPP__

#include "mana.hpp"
#include "reg.hpp"

namespace RISCV {

bool validShortImm(int32_t imm);

bool validLongImm(int32_t imm);

size_t align(size_t size, size_t align);

class Inst {
protected:
  std::vector<Reg*> _regs;
  int32_t _imm;
  std::string _label;

public:
  Inst() = default;
  Inst(const std::vector<Reg*>& regs);
  Inst(const std::vector<Reg*>& regs, int32_t imm);
  Inst(const std::vector<Reg*>& regs, const std::string& label);
  virtual ~Inst() = default;
  std::vector<Reg*> regs() {
    return _regs;
  }
  Reg* reg(size_t i) {
    return _regs[i];
  }
  virtual std::vector<Reg*> defRegs() {
    return {};
  }
  virtual std::vector<Reg*> useRegs() {
    return {};
  }
  virtual std::string_view name() {
    return "";
  }
  void replace(Reg* reg, Reg* oth) {
    for (size_t i = 0; i < _regs.size(); i++)
      if (reg == _regs[i]) _regs[i] = oth;
  }
};

class RdInst : virtual public Inst {
public:
  RdInst() = default;
  virtual ~RdInst() = default;
  Reg* rd();
};

class Rs1Inst : virtual public Inst {
public:
  Rs1Inst() = default;
  virtual ~Rs1Inst() = default;
  Reg* rs1();
};

class Rs2Inst : virtual public Inst {
public:
  Rs2Inst() = default;
  virtual ~Rs2Inst() = default;
  Reg* rs2();
};

class ImmInst : virtual public Inst {
public:
  ImmInst() = default;
  virtual ~ImmInst() = default;
  int32_t imm();
};

class LabelInst : virtual public Inst {
public:
  LabelInst() = default;
  virtual ~LabelInst() = default;
  std::string label();
};

class BranchInst {};

namespace Target {

class RTypeInst : public RdInst, public Rs1Inst, public Rs2Inst {};
class ITypeInst : public RdInst, public Rs1Inst, public ImmInst {};
class STypeInst : public Rs1Inst, public Rs2Inst, public ImmInst {};
class BTypeInst : public Rs1Inst, public Rs2Inst, public LabelInst {};
class UTypeInst : public RdInst, public ImmInst {};
class JTypeInst : public RdInst, public LabelInst {};

/// @brief Target Instruction MICROS

#define RISCV_R_TYPE_INST(op, kw)                                      \
  class op : public RTypeInst {                                        \
  public:                                                              \
    op(Reg* rd, Reg* rs1, Reg* rs2 = nullptr) : Inst({rd, rs1, rs2}) { \
    }                                                                  \
    std::vector<Reg*> defRegs() {                                      \
      return {rd()};                                                   \
    }                                                                  \
    std::vector<Reg*> useRegs() {                                      \
      if (rs2() && rs2() != rs1())                                     \
        return {rs1(), rs2()};                                         \
      else                                                             \
        return {rs1()};                                                \
    }                                                                  \
    std::string_view name() {                                          \
      return kw;                                                       \
    }                                                                  \
  }

// assert(validShortImm(imm));
#define RISCV_I_TYPE_INST(op, kw)                               \
  class op : public ITypeInst {                                 \
  public:                                                       \
    op(Reg* rd, Reg* rs1, int32_t imm) : Inst({rd, rs1}, imm) { \
    }                                                           \
    std::vector<Reg*> defRegs() {                               \
      return {rd()};                                            \
    }                                                           \
    std::vector<Reg*> useRegs() {                               \
      return {rs1()};                                           \
    }                                                           \
    std::string_view name() {                                   \
      return kw;                                                \
    }                                                           \
  }

// assert(validShortImm(imm));
#define RISCV_S_TYPE_INST(op, kw)                                          \
  class op : public STypeInst {                                            \
  public:                                                                  \
    op(Reg* rs1, Reg* rs2, int32_t imm) : Inst({nullptr, rs1, rs2}, imm) { \
    }                                                                      \
    std::vector<Reg*> defRegs() {                                          \
      return {};                                                           \
    }                                                                      \
    std::vector<Reg*> useRegs() {                                          \
      if (rs1() != rs2()) return {rs1(), rs2()};                           \
      return {rs1()};                                                      \
    }                                                                      \
    std::string_view name() {                                              \
      return kw;                                                           \
    }                                                                      \
  }

#define RISCV_B_TYPE_INST(op, kw)                                                         \
  class op : public BTypeInst {                                                           \
  public:                                                                                 \
    op(Reg* rs1, Reg* rs2, const std::string& label) : Inst({nullptr, rs1, rs2}, label) { \
    }                                                                                     \
    std::vector<Reg*> defRegs() {                                                         \
      return {};                                                                          \
    }                                                                                     \
    std::vector<Reg*> useRegs() {                                                         \
      if (rs1() != rs2()) return {rs1(), rs2()};                                          \
      return {rs1()};                                                                     \
    }                                                                                     \
    std::string_view name() {                                                             \
      return kw;                                                                          \
    }                                                                                     \
  }

// assert(validLongImm(imm));
#define RISCV_U_TYPE_INST(op, kw)                \
  class op : public UTypeInst {                  \
  public:                                        \
    op(Reg* rd, int32_t imm) : Inst({rd}, imm) { \
    }                                            \
    std::vector<Reg*> defRegs() {                \
      return {rd()};                             \
    }                                            \
    std::vector<Reg*> useRegs() {                \
      return {};                                 \
    }                                            \
    std::string_view name() {                    \
      return kw;                                 \
    }                                            \
  }

#define RISCV_J_TYPE_INST(op, kw)                               \
  class op : public JTypeInst {                                 \
  public:                                                       \
    op(Reg* rd, const std::string& label) : Inst({rd}, label) { \
    }                                                           \
    std::vector<Reg*> defRegs() {                               \
      return {rd()};                                            \
    }                                                           \
    std::vector<Reg*> useRegs() {                               \
      return {};                                                \
    }                                                           \
    std::string_view name() {                                   \
      return kw;                                                \
    }                                                           \
  }

/// @brief  Integer Instructions: RV32I and RV64I
/// @brief Shifts
RISCV_R_TYPE_INST(SLL, "sll");      // RV32I
RISCV_R_TYPE_INST(SLLW, "sllw");    // +RV64I
RISCV_I_TYPE_INST(SLLI, "slli");    // RV32I
RISCV_I_TYPE_INST(SLLIW, "slliw");  // +RV64I
RISCV_R_TYPE_INST(SRL, "srl");      // RV32I
RISCV_R_TYPE_INST(SRLW, "srlw");    // +RV64I
RISCV_I_TYPE_INST(SRLI, "srli");    // RV32I
RISCV_I_TYPE_INST(SRLIW, "srliw");  // +RV64I
RISCV_R_TYPE_INST(SRA, "sra");      // RV32I
RISCV_R_TYPE_INST(SRAW, "sraw");    // +RV64I
RISCV_I_TYPE_INST(SRAI, "srai");    // RV32I
RISCV_I_TYPE_INST(SRAIW, "sraiw");  // +RV64I

/// @brief Arithmetic
RISCV_R_TYPE_INST(ADD, "add");      // RV32I
RISCV_R_TYPE_INST(ADDW, "addw");    // +RV64I
RISCV_I_TYPE_INST(ADDI, "addi");    // RV32I
RISCV_I_TYPE_INST(ADDIW, "addiw");  // +RV64I
RISCV_R_TYPE_INST(SUB, "sub");      // RV32I
RISCV_R_TYPE_INST(SUBW, "subw");    // +RV64I
RISCV_U_TYPE_INST(LUI, "lui");      // RV32I
RISCV_U_TYPE_INST(AUIPC, "auipc");  // RV32I

/// @brief Logical
RISCV_R_TYPE_INST(XOR, "xor");    // RV32I
RISCV_I_TYPE_INST(XORI, "xori");  // RV32I
RISCV_R_TYPE_INST(OR, "or");      // RV32I
RISCV_I_TYPE_INST(ORI, "ori");    // RV32I
RISCV_R_TYPE_INST(AND, "and");    // RV32I
RISCV_I_TYPE_INST(ANDI, "andi");  // RV32I

/// @brief Compare
RISCV_R_TYPE_INST(SLT, "slt");      // RV32I
RISCV_I_TYPE_INST(SLTI, "slti");    // RV32I
RISCV_R_TYPE_INST(SLTU, "sltu");    // RV32I
RISCV_I_TYPE_INST(SLTIU, "sltiu");  // RV32I

/// @brief Branches
RISCV_B_TYPE_INST(BEQ, "beq");    // RV32I
RISCV_B_TYPE_INST(BNE, "bne");    // RV32I
RISCV_B_TYPE_INST(BLT, "blt");    // RV32I
RISCV_B_TYPE_INST(BGE, "bge");    // RV32I
RISCV_B_TYPE_INST(BLTU, "bltu");  // RV32I
RISCV_B_TYPE_INST(BGEU, "bgeu");  // RV32I

/// @brief Jump & Link
RISCV_J_TYPE_INST(JAL, "jal");    // RV32I
RISCV_I_TYPE_INST(JALR, "jalr");  // RV32I

/// @brief Synch
// TODO

/// @brief Environment
// TODO

/// @brief Control Status Register (CSR)
// TODO

/// @brief Loads
RISCV_I_TYPE_INST(LB, "lb");    // RV32I
RISCV_I_TYPE_INST(LH, "lh");    // RV32I
RISCV_I_TYPE_INST(LW, "lw");    // RV32I
RISCV_I_TYPE_INST(LD, "ld");    // +RV64I
RISCV_I_TYPE_INST(LBU, "lbu");  // RV32I
RISCV_I_TYPE_INST(LHU, "lhu");  // RV32I
RISCV_I_TYPE_INST(LWU, "lwu");  // +RV64I

/// @brief Stores
RISCV_S_TYPE_INST(SB, "sb");  // RV32I
RISCV_S_TYPE_INST(SH, "sh");  // RV32I
RISCV_S_TYPE_INST(SW, "sw");  // RV32I
RISCV_S_TYPE_INST(SD, "sd");  // +RV64I

/// @brief Optional Mutiply-Divide Instruction Extension: RVM
/// @brief Multipy
RISCV_R_TYPE_INST(MUL, "mul");      // RV32M
RISCV_R_TYPE_INST(MULW, "mulw");    // +RV64M
RISCV_R_TYPE_INST(MULH, "mulh");    // RV32M
RISCV_R_TYPE_INST(MULSU, "mulsu");  // RV32M
RISCV_R_TYPE_INST(MULHU, "mulhu");  // RV32M

/// @brief Divide
RISCV_R_TYPE_INST(DIV, "div");    // RV32M
RISCV_R_TYPE_INST(DIVW, "divw");  // +RV64M
RISCV_R_TYPE_INST(DIVU, "divu");  // RV32M

/// @brief Remainder
RISCV_R_TYPE_INST(REM, "rem");      // RV32M
RISCV_R_TYPE_INST(REMW, "remw");    // +RV64M
RISCV_R_TYPE_INST(REMU, "remu");    // RV32M
RISCV_R_TYPE_INST(REMUW, "remuw");  // +RV64M

/// @brief Two Optional Floating-Point Instruction Extension: RVF & RVD
/// @brief Move
RISCV_R_TYPE_INST(FMVWX, "fmvwx");  // RV32{F|D}
RISCV_R_TYPE_INST(FMVDX, "fmvdx");  // +RV64{F|D}
RISCV_R_TYPE_INST(FMVXW, "fmvxw");  // RV32{F|D}
RISCV_R_TYPE_INST(FMVXD, "fmvxd");  // +RV64{F|D}

/// @brief Convert
RISCV_R_TYPE_INST(FCVTSW, "fcvtsw");    // RV32{F|D}
RISCV_R_TYPE_INST(FCVTSL, "fcvtsl");    // +RV64{F|D}
RISCV_R_TYPE_INST(FCVTDW, "fcvtdw");    // RV32{F|D}
RISCV_R_TYPE_INST(FCVTDL, "fcvtdl");    // +RV64{F|D}
RISCV_R_TYPE_INST(FCVTSWU, "fcvtswu");  // RV32{F|D}
RISCV_R_TYPE_INST(FCVTSLU, "fcvtslu");  // +RV64{F|D}
RISCV_R_TYPE_INST(FCVTDWU, "fcvtdwu");  // RV32{F|D}
RISCV_R_TYPE_INST(FCVTDLU, "fcvtdlu");  // +RV64{F|D}
RISCV_R_TYPE_INST(FCVTWS, "fcvtws");    // RV32{F|D}
RISCV_R_TYPE_INST(FCVTLS, "fcvtls");    // +RV64{F|D}
RISCV_R_TYPE_INST(FCVTWD, "fcvtwd");    // RV32{F|D}
RISCV_R_TYPE_INST(FCVTLD, "fcvtld");    // +RV64{F|D}
RISCV_R_TYPE_INST(FCVTWUS, "fcvtwus");  // RV32{F|D}
RISCV_R_TYPE_INST(FCVTLUS, "fcvtlus");  // +RV64{F|D}
RISCV_R_TYPE_INST(FCVTWUD, "fcvtwud");  // RV32{F|D}
RISCV_R_TYPE_INST(FCVTLUD, "fcvtlud");  // +RV64{F|D}

/// @brief Load
RISCV_I_TYPE_INST(FLW, "flw");  // RV32{F|D}
RISCV_I_TYPE_INST(FLD, "fld");  // RV32{F|D}

/// @brief Store
RISCV_S_TYPE_INST(FSW, "fsw");  // RV32{F|D}
RISCV_S_TYPE_INST(FSD, "fsd");  // RV32{F|D}

/// @brief Arithmetic
RISCV_R_TYPE_INST(FADDS, "fadds");    // RV32{F|D}
RISCV_R_TYPE_INST(FADDD, "faddd");    // RV32{F|D}
RISCV_R_TYPE_INST(FSUBS, "fsubs");    // RV32{F|D}
RISCV_R_TYPE_INST(FSUBD, "fsubd");    // RV32{F|D}
RISCV_R_TYPE_INST(FMULS, "fmuls");    // RV32{F|D}
RISCV_R_TYPE_INST(FMULD, "fmuld");    // RV32{F|D}
RISCV_R_TYPE_INST(FDIVS, "fdivs");    // RV32{F|D}
RISCV_R_TYPE_INST(FDIVD, "fdivd");    // RV32{F|D}
RISCV_R_TYPE_INST(FSQRTS, "fsqrts");  // RV32{F|D}
RISCV_R_TYPE_INST(FSQRTD, "fsqrtd");  // RV32{F|D}

/// @brief Mul-Add
// TODO

/// @brief Sign Inject
RISCV_R_TYPE_INST(FSGNJS, "fsgnjs");    // RV32{F|D}
RISCV_R_TYPE_INST(FSGNJD, "fsgnjd");    // RV32{F|D}
RISCV_R_TYPE_INST(FSGNJNS, "fsgnjns");  // RV32{F|D}
RISCV_R_TYPE_INST(FSGNJND, "fsgnjns");  // RV32{F|D}
RISCV_R_TYPE_INST(FSGNJXS, "fsgnjxs");  // RV32{F|D}
RISCV_R_TYPE_INST(FSGNJXD, "fsgnjxs");  // RV32{F|D}

/// @brief Min/Max
RISCV_R_TYPE_INST(FMINS, "fmins");  // RV32{F|D}
RISCV_R_TYPE_INST(FMIND, "fmind");  // RV32{F|D}
RISCV_R_TYPE_INST(FMAXS, "fmaxs");  // RV32{F|D}
RISCV_R_TYPE_INST(FMAXD, "fmaxd");  // RV32{F|D}

/// @brief Compare
RISCV_R_TYPE_INST(FEQS, "feqs");  // RV32{F|D}
RISCV_R_TYPE_INST(FEQD, "feqd");  // RV32{F|D}
RISCV_R_TYPE_INST(FLTS, "flts");  // RV32{F|D}
RISCV_R_TYPE_INST(FLTD, "fltd");  // RV32{F|D}
RISCV_R_TYPE_INST(FLES, "fles");  // RV32{F|D}
RISCV_R_TYPE_INST(FLED, "fled");  // RV32{F|D}

/// @brief Categorize
RISCV_R_TYPE_INST(FCLASSS, "fclasss");  // RV32{F|D}
RISCV_R_TYPE_INST(FCLASSD, "fclassd");  // RV32{F|D}

/// @brief Configure
// TODO

/// @brief Optional Vector Extension: RVV
// TODO

}  // namespace Target

class StackObject;
class Block;

namespace Pseudo {

class LoadStack : public RdInst {
public:
  StackObject* _stack_object;
  LoadStack(Reg* rd, StackObject* stack_object) : Inst({rd}), _stack_object(stack_object) {
  }
  StackObject* stackObject() {
    return _stack_object;
  }
  std::vector<Reg*> useRegs() {
    return {};
  }
  std::vector<Reg*> defRegs() {
    return {rd()};
  }
  std::string_view name() {
    return "LoadStack";
  }
};

class StoreStack : public Rs2Inst {
public:
  StackObject* _stack_object;
  StoreStack(Reg* rs2, StackObject* stack_object) : Inst({nullptr, nullptr, rs2}), _stack_object(stack_object) {
  }
  StackObject* stackObject() {
    return _stack_object;
  }
  std::vector<Reg*> useRegs() {
    return {rs2()};
  }
  std::vector<Reg*> defRegs() {
    return {};
  }
  std::string_view name() {
    return "StoreStack";
  }
};

class LoadStackAddr : public RdInst {
public:
  StackObject* _stack_object;
  LoadStackAddr(Reg* rd, StackObject* stack_object) : Inst({rd}), _stack_object(stack_object) {
  }
  StackObject* stackObject() {
    return _stack_object;
  }
  std::vector<Reg*> useRegs() {
    return {};
  }
  std::vector<Reg*> defRegs() {
    return {rd()};
  }
  std::string_view name() {
    return "LoadStackAddr";
  }
};

class MV : public RdInst, public Rs1Inst {
public:
  MV(Reg* rd, Reg* rs1) : Inst({rd, rs1}) {
  }
  std::vector<Reg*> useRegs() {
    return {rs1()};
  }
  std::vector<Reg*> defRegs() {
    return {rd()};
  }
  std::string_view name() {
    return "mv";
  }
};


class J : public LabelInst {
public:
  Block* _block;
  J(Block* block, const std::string& label) : Inst({}, label), _block(block) {
  }
  std::vector<Reg*> useRegs() {
    return {};
  }
  std::vector<Reg*> defRegs() {
    return {};
  }
  std::string_view name() {
    return "j";
  }
};

class LI : public RdInst, public ImmInst {
public:
  LI(Reg* rd, int32_t imm) : Inst({rd}, imm) {
  }
  std::vector<Reg*> useRegs() {
    return {};
  }
  std::vector<Reg*> defRegs() {
    return {rd()};
  }
  std::string_view name() {
    return "li";
  }
};

class LA : public RdInst, public LabelInst {
public:
  LA(Reg* rd, const std::string& label) : Inst({rd}, label) {
  }
  std::vector<Reg*> useRegs() {
    return {};
  }
  std::vector<Reg*> defRegs() {
    return {rd()};
  }
  std::string_view name() {
    return "la";
  }
};

class CALL : public LabelInst {
public:
  std::vector<Reg*> _def_regs;
  std::vector<Reg*> _use_regs;
  CALL(const std::string& label, size_t arg_xreg_num, size_t arg_freg_num) : Inst({}, label) {
    for (Reg* reg : CALLER_SAVE_REG) _def_regs.emplace_back(reg);
    _def_regs.emplace_back(RA);
    for (size_t i = 0; i < std::min(arg_xreg_num, ARG_XREG_NUM); i++) _use_regs.emplace_back(ARG_XREG[i]);
    for (size_t i = 0; i < std::min(arg_freg_num, ARG_FREG_NUM); i++) _use_regs.emplace_back(ARG_FREG[i]);
  }
  std::vector<Reg*> defRegs() {
    return _def_regs;
  }
  std::vector<Reg*> useRegs() {
    return _use_regs;
  }
  std::string_view name() {
    return "call";
  }
};

class FSRM : public RdInst, public Rs1Inst {
public:
  FSRM(Reg* rd, Reg* rs1) : Inst({rd, rs1}) {
  }
  std::vector<Reg*> defRegs() {
    return {rd()};
  }
  std::vector<Reg*> useRegs() {
    return {rs1()};
  }
  std::string_view name() {
    return "fsrm";
  }
};

class Ret : public Inst {
public:
  Ret() : Inst() {
  }
  std::vector<Reg*> defRegs() {
    return {};
  }
  std::vector<Reg*> useRegs() {
    return {};
  }
  std::string_view name() {
    return "ret";
  }
};

}  // namespace Pseudo

}  // namespace RISCV

#endif
