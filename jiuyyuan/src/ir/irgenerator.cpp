#include "irgenerator.hpp"

#include <cassert>

#include "instruction.hpp"

namespace IR {

IRGenerator::IRGenerator(CompileUnit *compile_unit) : compile_unit(compile_unit) {
}

void IRGenerator::generate(LogLevel log_level) {
  configuration.setLogLevel(log_level);
  generate(compile_unit);
}

void IRGenerator::generate(CompileUnit *compile_unit) {
  for (auto &[_, global_variable] : compile_unit->globalVariableTable()->table()) generate(global_variable.get());
  for (auto &function : compile_unit->functionTable()) generate(function.get());
}

void IRGenerator::generate(Variable *global_variable) {
  info << global_variable->type()->name() << " " << global_variable->name() << " = ";
  for (auto &initial_value : global_variable->initializer())
    if (initial_value->initialType() == InitialValue::ZERO)
      info << "[zero " << initial_value->value()->name() << "]";
    else if (initial_value->initialType() == InitialValue::VALUE)
      info << "[value " << initial_value->value()->name() << "]";
    else
      assert(0);
  info << "\n";
}

void IRGenerator::generate(Function *function) {
  info << (function->isDeclaration() ? "declar " : "define ") << function->type()->retType()->name() << " "
       << function->name() << "(";
  for (auto it = function->arguments().begin(); it != function->arguments().end(); it++)
    info << (it == function->arguments().begin() ? "" : ", ") << (*it)->type()->name() << " " << (*it)->name();
  info << ")";
  if (function->isDeclaration()) {
    info << ";\n";
  } else {
    info << " {\n";
    for (auto &basic_block : function->basicBlocks()) generate(basic_block.get());
    info << "}\n";
  }
  info << "\n";
}

void IRGenerator::generate(BasicBlock *basic_block) {
  info << basic_block->name() << ":";
  info << (basic_block->predecessors().size() || basic_block->successors().size() ? " ;" : "");
  if (basic_block->predecessors().size()) info << " predecessors = ";
  for (auto it = basic_block->predecessors().begin(); it != basic_block->predecessors().end(); it++) {
    info << (it == basic_block->predecessors().begin() ? "" : ", ");
    info << (*it)->name();
  }
  if (basic_block->successors().size()) info << " successors = ";
  for (auto it = basic_block->successors().begin(); it != basic_block->successors().end(); it++) {
    info << (it == basic_block->successors().begin() ? "" : ", ");
    info << (*it)->name();
  }
  info << "\n";
  for (const auto &inst : basic_block->instructions()) generate(inst.get());
  info << "\n";
}

void IRGenerator::generate(Instruction *inst) {
  info << IDENT << (inst->type()->isVoid() ? "" : inst->name() + " := ") << inst->opcode() << " ";
  switch (inst->itype()) {
    case RET:
    case JMP: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << "\n";
    } break;
    case BR: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << ", "
           << inst->operand(1)->type()->name() << " " << inst->operand(1)->name() << ", "
           << inst->operand(2)->type()->name() << " " << inst->operand(2)->name() << "\n";
    } break;
    case FNEG: {
      info << inst->type()->name() << " " << inst->operand(0)->name() << "\n";
    } break;
    case ADD:
    case FADD:
    case SUB:
    case FSUB:
    case MUL:
    case FMUL:
    case SDIV:
    case FDIV:
    case SREM: {
      info << inst->type()->name() << " " << inst->operand(0)->name() << ", " << inst->operand(1)->name() << "\n";
    } break;
    case SHL:
    case LSHR:
    case ASHR:
    case AND:
    case OR:
    case XOR: {
      assert(0);
    } break;
    case ALLOCA: {
      info << inst->type()->deref(1)->name() << "\n";
    } break;
    case LOAD: {
      info << inst->type()->name() << ", " << inst->operand(0)->type()->name() << " " << inst->operand(0)->name()
           << "\n";
    } break;
    case STORE: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << ", "
           << inst->operand(1)->type()->name() << " " << inst->operand(1)->name() << "\n";
    } break;
    case TRUNC: {
      assert(0);
    } break;
    case ZEXT: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << " to " << inst->type()->name()
           << "\n";
    } break;
    case SEXT:
    case FPTRUNC:
    case FPEXT: {
      assert(0);
    } break;
    case FPTOSI: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << " to " << inst->type()->name()
           << "\n";
    } break;
    case SITOFP: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << " to " << inst->type()->name()
           << "\n";
    } break;
    case PTRTOINT: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << " to " << inst->type()->name()
           << "\n";
    } break;
    case INTTOPTR: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << " to " << inst->type()->name()
           << "\n";
    } break;
    case IEQ:
    case INE:
    case ISGT:
    case ISGE:
    case ISLT:
    case ISLE:
    case FOEQ:
    case FONE:
    case FOGT:
    case FOGE:
    case FOLT:
    case FOLE: {
      info << inst->operand(0)->type()->name() << " " << inst->operand(0)->name() << ", " << inst->operand(1)->name()
           << "\n";
    } break;
    case PHI: {
      // TODO
      for (size_t i = 0; i < static_cast<PhiInst *>(inst)->operands().size() / 2; i++) {
        if (static_cast<PhiInst *>(inst)->operands()[i * 2]) {
          info << "[ " << inst->operand(2 * i)->name() << ", " << inst->operand(2 * i + 1)->name()
               << " ] ";
        }
      }
      info << "\n";
      // for (size_t i = 0; i < 2 * static_cast<PhiInst *>(inst)->vals().size(); i = i + 2)
      //   info << (i ? ", " : "") << "[ " << inst->operand(i)->name() << ", " << inst->operand(i + 1)->name() << " ]";
      // info << "\n";
    } break;
    case CALL: {
      info << inst->operand(0)->type()->retType()->name() << " " << inst->operand(0)->name() << "(";
      for (size_t i = 1; i < inst->operands().size(); i++)
        info << (i == 1 ? "" : ", ") << inst->operand(i)->type()->name() << " " << inst->operand(i)->name();
      info << ")\n";
    } break;
    case ADDRADD:
    case ADDRDEREFADD: {
      info << inst->type()->name() << inst->operand(0)->name() << ", " << inst->operand(1)->name() << "\n";
    } break;
    default: {
      assert(0);
    } break;
  }
}

}  // namespace IR
