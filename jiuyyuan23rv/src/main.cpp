#include "SysYLexer.h"
#include "SysYParser.h"
#include "analysis/rename.hpp"
#include "asm.hpp"
#include "irgenerator.hpp"
#include "pass.hpp"
#include "visitor.hpp"
#include "optimize/mem2reg.hpp"
#include "optimize/dom.hpp"
#include "optimize/sccp.hpp"


int main(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    if (i == 0) continue;
    if (strcmp(argv[i], "-S") == 0) continue;
    if (strcmp(argv[i], "-O1") == 0) continue;
    if (strcmp(argv[i], "-O2") == 0) continue;
    if (strcmp(argv[i], "-o") == 0) {
      configuration.setOutputFilename(argv[++i]);
      continue;
    }
    configuration.setInputFilename(argv[i]);
  }
  // configuration.setInputFilename("02_mv3.sy");
  // configuration.setOutputFilename("02_mv3.s");
  std::ifstream src_stream;
  std::ofstream asm_stream;
  src_stream.open(configuration.inputFilename(), std::ios::in);
  asm_stream.open(configuration.outputFilename(), std::ios::out);
  configuration.setOstream(asm_stream);
  antlr4::ANTLRInputStream antlr_input_stream(src_stream);
  SysYLexer sysy_lexer(&antlr_input_stream);
  antlr4::CommonTokenStream common_token_stream(&sysy_lexer);
  SysYParser sysy_parser(&common_token_stream);
  IR::CompileUnit compile_unit;
  Visitor sysy_visitor(&compile_unit);
  sysy_visitor.visitComp(sysy_parser.comp());

  //* ----------------- add pass here ----------------
  // Pass::function_pass_mana.newPass(new Pass::IdomGen());
  // Pass::function_pass_mana.newPass(new Pass::DomTreeGen());
  // Pass::function_pass_mana.newPass(new Pass::DomFrontierGen());
  // Pass::function_pass_mana.newPass(new Pass::Mem2Reg());
  // for (auto& f : compile_unit.functionTable()) {
  //   Pass::function_pass_mana.run(f.get());
  // }


  // Pass::function_pass_mana.newPass(new Pass::ConstPropagation());
  Pass::function_pass_mana.newPass(new Pass::RenamePass());

  for (auto& f : compile_unit.functionTable()) {
    Pass::function_pass_mana.run(f.get());
  }

  configuration.setOstream(std::cout);
  IR::IRGenerator sysy_ir_gener(&compile_unit);
  sysy_ir_gener.generate(INFO);


  //* ------------------------------------------------
  configuration.setOstream(asm_stream);

  RISCV::Program program(&compile_unit);
  RISCV::Generator sysy_riscv_gener(&program);
  for (auto &f : program.functions()) {
    RISCV::Allocator *allocator = new RISCV::Allocator(f.get());
    allocator->allocate();
    auto res = allocator->apply();
    RISCV::Block *entry = f->blocks().front().get();
    f->loadStoreCalleeSaveReg(entry, f->exits, res);
    f->calcStackOffset();
    f->prologue(entry, f->exits);
    for (auto &block : f->blocks()) {
      for (auto it = block->insts().begin(); it != block->insts().end();) {
        if (auto mv = dynamic_cast<RISCV::Target::ADDI *>(it->get())) {
          if (mv->imm() == 0 && mv->rd() == mv->rs1()) {
            it = block->insts().erase(it);
            continue;
          }
        }
        if (auto fmv = dynamic_cast<RISCV::Target::FSGNJS *>(it->get())) {
          if (fmv->rs1() == fmv->rs2() && fmv->rd() == fmv->rs1()) {
            it = block->insts().erase(it);
            continue;
          }
        }
        it = std::next(it);
      }
    }
  }
  sysy_riscv_gener.generate(DEBUG);
  src_stream.close();
  asm_stream.clear();
  return 0;
}
