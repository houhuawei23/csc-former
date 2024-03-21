#include "generator.hpp"

using namespace RISCV;

Generator::Generator(Program *program) : _program(program) {
}

void Generator::generate(LogLevel log_level) {
  configuration.setLogLevel(log_level);
  generate(_program);
}

void Generator::generate(Program *program) {
  info << IDENT << ".file "
       << "\"" << configuration.inputFilename() << "\"\n";
  info << IDENT << ".option nopic\n";
  info << IDENT << ".text\n";
  for (auto &function : program->functions()) {
    generate(function.get());
  }
  for (auto &global_value : program->globalValues()) {
    generate(global_value.get());
  }
}

void Generator::generate(const std::string &builtin_function) {
  if (builtin_function == "alice_memset") {
    info << "  .align 1\n"
            "  .globl alice_memset\n"
            "  .type alice_memset, @function\n"
            "alice_memset:\n"
            "entry_alice_memset:\n"
            "  beq a2, zero, alice_memset_LL_00\n"
            "  addi a2, a2, -4\n"
            "  sw a1, 0(a0)\n"
            "  addi a0, a0, 4\n"
            "  j entry_alice_memset\n"
            "alice_memset_LL_00:\n"
            "  ret\n";
  } else
    assert(0);
}

void Generator::generate(Function *function) {
  info << IDENT << ".align 1\n";
  info << IDENT << ".globl " << function->name() << "\n";
  info << IDENT << ".type " << function->name() << ", @function\n";
  info << function->name() << ":\n";
  for (auto &block : function->blocks()) {
    generate(block.get());
  }
}

void Generator::generate(Block *block) {
  info << block->name() << ":\n";
  for (auto &inst : block->insts()) {
    generate(inst.get());
  }
}

void Generator::generate(Inst *inst) {
  info << IDENT;
  if (auto r = dynamic_cast<Target::RTypeInst *>(inst)) {
    if (auto ins = dynamic_cast<Target::SLL *>(r)) {
      info << "sll " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SLLW *>(r)) {
      info << "sllw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SRL *>(r)) {
      info << "srl " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SRLW *>(r)) {
      info << "srlw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SRA *>(r)) {
      info << "sra " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SRAW *>(r)) {
      info << "sraw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::ADD *>(r)) {
      info << "add " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::ADDW *>(r)) {
      info << "addw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SUB *>(r)) {
      info << "sub " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SUBW *>(r)) {
      info << "subw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::XOR *>(r)) {
      info << "xor " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::OR *>(r)) {
      info << "or " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::AND *>(r)) {
      info << "and " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SLT *>(r)) {
      info << "slt " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::SLTU *>(r)) {
      info << "sltu " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::MUL *>(r)) {
      info << "mul " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::MULW *>(r)) {
      info << "mulw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::MULH *>(r)) {
      info << "mulh " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::MULHU *>(r)) {
      info << "mulhu " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::MULSU *>(r)) {
      info << "mulsu " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::DIV *>(r)) {
      info << "div " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::DIVU *>(r)) {
      info << "divu " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::DIVW *>(r)) {
      info << "divw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::REM *>(r)) {
      info << "rem " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::REMU *>(r)) {
      info << "remu " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::REMW *>(r)) {
      info << "remw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::REMUW *>(r)) {
      info << "remuw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FMVDX *>(r)) {
      info << "fmv.d.x " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FMVWX *>(r)) {
      info << "fmv.w.x " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FMVXD *>(r)) {
      info << "fmv.x.d " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FMVXW *>(r)) {
      info << "fmv.x.w " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTSW *>(r)) {
      info << "fcvt.s.w " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTSL *>(r)) {
      info << "fcvt.s.l " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTDW *>(r)) {
      info << "fcvt.d.w " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTDL *>(r)) {
      info << "fcvt.d.l " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTSWU *>(r)) {
      info << "fcvt.s.wu " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTSLU *>(r)) {
      info << "fcvt.s.lu " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTDWU *>(r)) {
      info << "fcvt.d.wu " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTDLU *>(r)) {
      info << "fcvt.d.lu " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTWS *>(r)) {
      info << "fcvt.w.s " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTLS *>(r)) {
      info << "fcvt.l.s " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTWD *>(r)) {
      info << "fcvt.w.d " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTLD *>(r)) {
      info << "fcvt.l.d " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTWUS *>(r)) {
      info << "fcvt.wu.s " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTLUS *>(r)) {
      info << "fcvt.lu.s " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTWUD *>(r)) {
      info << "fcvt.wu.d " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FCVTLUD *>(r)) {
      info << "fcvt.lu.d " << ins->rd()->name() << ", " << ins->rs1()->name();
    } else if (auto ins = dynamic_cast<Target::FADDS *>(r)) {
      info << "fadd.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FADDD *>(r)) {
      info << "fadd.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSUBS *>(r)) {
      info << "fsub.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSUBD *>(r)) {
      info << "fsub.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FMULS *>(r)) {
      info << "fmul.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FMULD *>(r)) {
      info << "fmul.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FDIVS *>(r)) {
      info << "fdiv.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FDIVD *>(r)) {
      info << "fdiv.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSQRTS *>(r)) {
      info << "fsqrt.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSQRTD *>(r)) {
      info << "fsqrt.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSGNJS *>(r)) {
      info << "fsgnj.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSGNJD *>(r)) {
      info << "fsgnj.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSGNJNS *>(r)) {
      info << "fsgnjn.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSGNJND *>(r)) {
      info << "fsgnjn.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSGNJXS *>(r)) {
      info << "fsgnjx.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FSGNJXD *>(r)) {
      info << "fsgnjx.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FMINS *>(r)) {
      info << "fmin.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FMIND *>(r)) {
      info << "fmin.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FMAXS *>(r)) {
      info << "fmax.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FMAXD *>(r)) {
      info << "fmax.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FEQS *>(r)) {
      info << "feq.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FEQD *>(r)) {
      info << "feq.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FLTS *>(r)) {
      info << "flt.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FLTD *>(r)) {
      info << "flt.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FLES *>(r)) {
      info << "fle.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FLED *>(r)) {
      info << "fle.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FCLASSS *>(r)) {
      info << "fclass.s " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else if (auto ins = dynamic_cast<Target::FCLASSD *>(r)) {
      info << "fclass.d " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->rs2()->name();
    } else {
      assert(0);
    }
  } else if (auto i = dynamic_cast<Target::ITypeInst *>(inst)) {
    if (auto ins = dynamic_cast<Target::SLLI *>(i)) {
      info << "slli " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::SLLIW *>(i)) {
      info << "slliw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::SRLI *>(i)) {
      info << "srli " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::SRLIW *>(i)) {
      info << "slliw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::SRAI *>(i)) {
      info << "srai " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::SRAIW *>(i)) {
      info << "sraiw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::ADDI *>(i)) {
      info << "addi " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::ADDIW *>(i)) {
      info << "addiw " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::XORI *>(i)) {
      info << "xori " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::ORI *>(i)) {
      info << "ori " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::ANDI *>(i)) {
      info << "andi " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::SLTI *>(i)) {
      info << "slti " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::SLTIU *>(i)) {
      info << "sltiu " << ins->rd()->name() << ", " << ins->rs1()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::JALR *>(i)) {
      info << "jalr " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::LB *>(i)) {
      info << "lb " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::LH *>(i)) {
      info << "lh " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::LW *>(i)) {
      info << "lw " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::LD *>(i)) {
      info << "ld " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::LBU *>(i)) {
      info << "lbu " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::LHU *>(i)) {
      info << "lhu " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::LWU *>(i)) {
      info << "lwu " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::FLW *>(i)) {
      info << "flw " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::FLD *>(i)) {
      info << "fld " << ins->rd()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else {
      assert(0);
    }
  } else if (auto s = dynamic_cast<Target::STypeInst *>(inst)) {
    if (auto ins = dynamic_cast<Target::SB *>(s)) {
      info << "sb " << ins->rs2()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::SH *>(s)) {
      info << "sh " << ins->rs2()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::SW *>(s)) {
      info << "sw " << ins->rs2()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::SD *>(s)) {
      info << "sd " << ins->rs2()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::FSW *>(s)) {
      info << "fsw " << ins->rs2()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    } else if (auto ins = dynamic_cast<Target::FSD *>(s)) {
      info << "fsd " << ins->rs2()->name() << ", " << ins->imm() << "(" << ins->rs1()->name() << ")";
    }
  } else if (auto b = dynamic_cast<Target::BTypeInst *>(inst)) {
    if (auto ins = dynamic_cast<Target::BEQ *>(b)) {
      info << "beq " << ins->rs1()->name() << ", " << ins->rs2()->name() << ", " << b->label();
    } else if (auto ins = dynamic_cast<Target::BNE *>(b)) {
      info << "bne " << ins->rs1()->name() << ", " << ins->rs2()->name() << ", " << b->label();
    } else if (auto ins = dynamic_cast<Target::BLT *>(b)) {
      info << "blt " << ins->rs1()->name() << ", " << ins->rs2()->name() << ", " << b->label();
    } else if (auto ins = dynamic_cast<Target::BGE *>(b)) {
      info << "bge " << ins->rs1()->name() << ", " << ins->rs2()->name() << ", " << b->label();
    } else if (auto ins = dynamic_cast<Target::BLTU *>(b)) {
      info << "bltu " << ins->rs1()->name() << ", " << ins->rs2()->name() << ", " << b->label();
    } else if (auto ins = dynamic_cast<Target::BGEU *>(b)) {
      info << "bgeu " << ins->rs1()->name() << ", " << ins->rs2()->name() << ", " << b->label();
    } else {
      assert(0);
    }
  } else if (auto u = dynamic_cast<Target::UTypeInst *>(inst)) {
    if (auto ins = dynamic_cast<Target::LUI *>(u)) {
      info << "lui " << ins->rd()->name() << ", " << ins->imm();
    } else if (auto ins = dynamic_cast<Target::AUIPC *>(u)) {
      info << "auipc " << ins->rd()->name() << ", " << ins->imm();
    } else {
      assert(0);
    }
  } else if (auto j = dynamic_cast<Target::JTypeInst *>(inst)) {
    if (auto ins = dynamic_cast<Target::JAL *>(j)) {
      info << "jal " << ins->rd()->name() << ", " << ins->label();
    } else {
      assert(0);
    }
  } else if (auto call = dynamic_cast<Pseudo::CALL *>(inst)) {
    info << "call " << call->label();
  } else if (auto j = dynamic_cast<Pseudo::J *>(inst)) {
    info << "j " << j->label();
  } else if (auto li = dynamic_cast<Pseudo::LI *>(inst)) {
    info << "li " << li->rd()->name() << ", " << li->imm();
  } else if (auto la = dynamic_cast<Pseudo::LA *>(inst)) {
    info << "la " << la->rd()->name() << ", " << la->label();
  } else if (auto ld = dynamic_cast<Pseudo::LoadStack *>(inst)) {
    if (!ld->stackObject()->base()) {
      info << "LoadStack";
    } else {
      if (ld->rd()->isxreg()) {
        if (ld->stackObject()->size() == 4) {
          info << "lw " << ld->rd()->name() << ", " << ld->stackObject()->offset() << "("
               << ld->stackObject()->base()->name() << ")";
        } else if (ld->stackObject()->size() == 8) {  // 物理寄存器一定是8
          info << "ld " << ld->rd()->name() << ", " << ld->stackObject()->offset() << "("
               << ld->stackObject()->base()->name() << ")";
        } else {
          assert(0);
        }
      } else if (ld->rd()->isfreg()) {
        if (ld->stackObject()->size() == 4) {
          info << "flw " << ld->rd()->name() << ", " << ld->stackObject()->offset() << "("
               << ld->stackObject()->base()->name() << ")";
        } else if (ld->stackObject()->size() == 8) {
          info << "fld " << ld->rd()->name() << ", " << ld->stackObject()->offset() << "("
               << ld->stackObject()->base()->name() << ")";
        } else {
          assert(0);
        }
      } else {
        assert(0);
      }
    }
  } else if (auto ld = dynamic_cast<Pseudo::LoadStackAddr *>(inst)) {
    if (!ld->stackObject()->base()) {
      info << "LoadStackAddr";
    } else {
      if (validShortImm(ld->stackObject()->offset())) {
        info << "addi " << ld->rd()->name() << ", " << ld->stackObject()->base()->name() << ", "
             << ld->stackObject()->offset();
      } else {
        info << "li " << ld->rd()->name() << ", " << ld->stackObject()->offset() << "\n";
        info << IDENT << "add " << ld->rd()->name() << ", " << ld->stackObject()->base()->name() << ", "
             << ld->rd()->name();
      }
    }
  } else if (auto st = dynamic_cast<Pseudo::StoreStack *>(inst)) {
    if (!st->stackObject()->base()) {
      info << "StoreStack";
    } else {
      if (st->rs2()->isxreg()) {
        if (st->stackObject()->size() == 8) {
          info << "sd " << st->rs2()->name() << ", " << st->stackObject()->offset() << "("
               << st->stackObject()->base()->name() << ")";
        } else {
          info << "sw " << st->rs2()->name() << ", " << st->stackObject()->offset() << "("
               << st->stackObject()->base()->name() << ")";
        }
      } else if (st->rs2()->isfreg()) {
        if (st->stackObject()->size() == 8) {
          info << "fsd " << st->rs2()->name() << ", " << st->stackObject()->offset() << "("
               << st->stackObject()->base()->name() << ")";
        } else {
          info << "fsw " << st->rs2()->name() << ", " << st->stackObject()->offset() << "("
               << st->stackObject()->base()->name() << ")";
        }
      } else {
        assert(0);
      }
    }
  } else if (auto fsrm = dynamic_cast<Pseudo::FSRM *>(inst)) {
    info << "fsrm " << fsrm->rd()->name() << ", " << fsrm->rs1()->name() << "\n";
  } else {
    assert(0);
  }
  info << "\n";
}

void Generator::generate(GlobalValue *global_value) {
  info << IDENT << ".globl " << global_value->name() << "\n";
  if (global_value->mtype() == GlobalValue::BSS) {
    info << IDENT << ".bss\n";
  } else if (global_value->mtype() == GlobalValue::DATA) {
    info << IDENT << ".data\n";
  } else if (global_value->mtype() == GlobalValue::RODATA) {
    info << IDENT << ".section .rodata\n";
  } else {
    assert(0);
  }
  info << IDENT << ".align 2\n";
  info << IDENT << ".type " << global_value->name() << ", @object\n";
  info << IDENT << ".size " << global_value->name() << ", " << global_value->sizeOf() << "\n";
  info << global_value->name() << ":\n";
  for (auto &directive : global_value->directives()) {
    if (directive->dtype() == Directive::WORD) {
      info << IDENT << ".word " << directive->value() << "\n";
    } else if (directive->dtype() == Directive::ZERO) {
      info << IDENT << ".zero " << directive->value() << "\n";
    } else {
      assert(0);
    }
  }
}
