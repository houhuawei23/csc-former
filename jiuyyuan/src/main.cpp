#include "SysYLexer.h"
#include "SysYParser.h"
#include "analysis/IPAnalysis.hpp"
#include "analysis/LCSSA.hpp"
#include "analysis/check.hpp"
#include "analysis/checkPhi.hpp"
#include "analysis/loop.hpp"
#include "analysis/rename.hpp"
#include "asm.hpp"
#include "asm/simplifyBasicBlock.hpp"
#include "irgenerator.hpp"
#include "optimize/ConstFlod.hpp"
#include "optimize/DCE.hpp"
#include "optimize/GCM.hpp"
#include "optimize/GVN.hpp"
#include "optimize/LSLive.hpp"
#include "optimize/LSR.hpp"
#include "optimize/RecursiveCache.hpp"
#include "optimize/SCCP.hpp"
#include "optimize/SimplifyCFG.hpp"
#include "optimize/TRE.hpp"
#include "optimize/dom.hpp"
#include "optimize/fix.hpp"
#include "optimize/functionInline.hpp"
#include "optimize/instructionCombine.hpp"
#include "optimize/loop_parallel.hpp"
#include "optimize/loop_unroll.hpp"
#include "optimize/mem2reg.hpp"
#include "visitor.hpp"
// #define TEST

int main(int argc, char **argv) {
  int flag = 0;
  for (int i = 0; i < argc; i++) {
    if (i == 0) continue;
    if (strcmp(argv[i], "-S") == 0) continue;
    if (strcmp(argv[i], "-O1") == 0) {
      flag = 1;
      continue;
    }
    if (strcmp(argv[i], "-o") == 0) {
      configuration.setOutputFilename(argv[++i]);
      continue;
    }
    configuration.setInputFilename(argv[i]);
  }

#ifdef TEST
  flag = 1;
  configuration.setInputFilename("51_short_circuit3.sy");
  configuration.setOutputFilename("51_short_circuit3.s");
#endif

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

  // Pass::function_pass_mana.newPass(new Pass::Check("Frontend"));
  Pass::function_pass_mana.newPass(new Pass::IdomGen());
  // Pass::function_pass_mana.newPass(new Pass::Check("IdomGen"));
  Pass::function_pass_mana.newPass(new Pass::DomTreeGen());
  // Pass::function_pass_mana.newPass(new Pass::Check("DomTreeGen"));
  Pass::function_pass_mana.newPass(new Pass::DomFrontierGen());
  // Pass::function_pass_mana.newPass(new Pass::Check("DomFrontierGen"));
  Pass::function_pass_mana.newPass(new Pass::Mem2Reg());
  // Pass::function_pass_mana.newPass(new Pass::Check("Mem2Reg"));
  Pass::function_pass_mana.newPass(new Pass::DCE());
  if (flag) {
    // Pass::function_pass_mana.newPass(new Pass::Check("DCE"));
    for (auto &f : compile_unit.functionTable()) {
      if (!f->isDeclaration()) Pass::function_pass_mana.run(f.get());
    }
    Pass::function_pass_mana.passes().clear();

    Pass::compile_unit_pass_mana.newPass(new Pass::IPAnalysis());
    Pass::compile_unit_pass_mana.newPass(new Pass::RecursiveCache());
    Pass::compile_unit_pass_mana.newPass(new Pass::functionInline());
    Pass::compile_unit_pass_mana.run(&compile_unit);

    // Pass::function_pass_mana.newPass(new Pass::Check("IPAnalysis && functionInline"));
    Pass::function_pass_mana.newPass(new Pass::IdomGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("IdomGen"));
    Pass::function_pass_mana.newPass(new Pass::DomTreeGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("DomTreeGen"));
    Pass::function_pass_mana.newPass(new Pass::DomFrontierGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("DomFrontierGen"));
    Pass::function_pass_mana.newPass(new Pass::instructionCombine());
    // Pass::function_pass_mana.newPass(new Pass::Check("instructionCombine"));
    Pass::function_pass_mana.newPass(new Pass::SCCP());
    // Pass::function_pass_mana.newPass(new Pass::Check("SCCP"));
    Pass::function_pass_mana.newPass(new Pass::ConstFlod());
    // Pass::function_pass_mana.newPass(new Pass::Check("ConstFlod"));
    Pass::function_pass_mana.newPass(new Pass::SCCP());
    // Pass::function_pass_mana.newPass(new Pass::Check("SCCP"));
    Pass::function_pass_mana.newPass(new Pass::instructionCombine());
    // Pass::function_pass_mana.newPass(new Pass::Check("instructionCombine"));
    Pass::function_pass_mana.newPass(new Pass::DCE());
    // Pass::function_pass_mana.newPass(new Pass::Check("DCE"));
    Pass::function_pass_mana.newPass(new Pass::Gvnum());
    // Pass::function_pass_mana.newPass(new Pass::Check("Gvnum"));
    Pass::function_pass_mana.newPass(new Pass::GCM());
    // Pass::function_pass_mana.newPass(new Pass::Check("GCM"));
    Pass::function_pass_mana.newPass(new Pass::instructionCombine());
    // Pass::function_pass_mana.newPass(new Pass::Check("instructionCombine"));
    Pass::function_pass_mana.newPass(new Pass::Loop_Analyzer());
    // Pass::function_pass_mana.newPass(new Pass::Check("Loop_Analyzer"));
    Pass::function_pass_mana.newPass(new Pass::LSR());

    Pass::function_pass_mana.newPass(new Pass::IdomGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("IdomGen"));
    Pass::function_pass_mana.newPass(new Pass::DomTreeGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("DomTreeGen"));
    Pass::function_pass_mana.newPass(new Pass::DomFrontierGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("DomFrontierGen"));
    Pass::function_pass_mana.newPass(new Pass::Loop_Analyzer());
    // Pass::function_pass_mana.newPass(new Pass::Check("Loop_Analyzer"));
    Pass::function_pass_mana.newPass(new Pass::SCEV_Analyzer());
    // Pass::function_pass_mana.newPass(new Pass::Check("SCEV_Analyzer"));
    Pass::function_pass_mana.newPass(new Pass::LCSSA_Analyzer());
    // Pass::function_pass_mana.newPass(new Pass::Check("LCSSA_Analyzer"));
    // Pass::function_pass_mana.newPass(new Pass::LoopParallel());
    Pass::function_pass_mana.newPass(new Pass::Loop_Unroll());
    Pass::function_pass_mana.newPass(new Pass::FIX());
    // Pass::function_pass_mana.newPass(new Pass::Check("Loop_Unroll && FIX"));
    Pass::function_pass_mana.newPass(new Pass::SCEV_Clean());
    // Pass::function_pass_mana.newPass(new Pass::Check("SCEV_Clean"));
    Pass::function_pass_mana.newPass(new Pass::DCE());
    // Pass::function_pass_mana.newPass(new Pass::Check("DCE"));

    Pass::function_pass_mana.newPass(new Pass::IdomGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("IdomGen"));
    Pass::function_pass_mana.newPass(new Pass::DomTreeGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("DomTreeGen"));
    Pass::function_pass_mana.newPass(new Pass::DomFrontierGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("DomFrontierGen"));
    Pass::function_pass_mana.newPass(new Pass::Loop_Analyzer());
    // Pass::function_pass_mana.newPass(new Pass::Check("Loop_Analyzer"));
    Pass::function_pass_mana.newPass(new Pass::SCEV_Analyzer());
    // Pass::function_pass_mana.newPass(new Pass::Check("SCEV_Analyzer"));
    Pass::function_pass_mana.newPass(new Pass::LCSSA_Analyzer());
    // Pass::function_pass_mana.newPass(new Pass::Check("LCSSA_Analyzer"));
    // Pass::function_pass_mana.newPass(new Pass::LoopParallel());
    Pass::function_pass_mana.newPass(new Pass::Loop_Unroll());
    Pass::function_pass_mana.newPass(new Pass::FIX());
    // Pass::function_pass_mana.newPass(new Pass::Check("Loop_Unroll && FIX"));
    Pass::function_pass_mana.newPass(new Pass::SCEV_Clean());
    // Pass::function_pass_mana.newPass(new Pass::Check("SCEV_Clean"));
    Pass::function_pass_mana.newPass(new Pass::DCE());
    // Pass::function_pass_mana.newPass(new Pass::Check("DCE"));

    Pass::function_pass_mana.newPass(new Pass::IdomGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("IdomGen"));
    Pass::function_pass_mana.newPass(new Pass::DomTreeGen());
    // Pass::function_pass_mana.newPass(new Pass::Check("DomTreeGen"));
    Pass::function_pass_mana.newPass(new Pass::DomFrontierGen());

    Pass::function_pass_mana.newPass(new Pass::SCCP());
    // Pass::function_pass_mana.newPass(new Pass::Check("SCCP"));
    Pass::function_pass_mana.newPass(new Pass::ConstFlod());
    // Pass::function_pass_mana.newPass(new Pass::Check("ConstFlod"));
    Pass::function_pass_mana.newPass(new Pass::SCCP());
    // Pass::function_pass_mana.newPass(new Pass::Check("SCCP"));
    Pass::function_pass_mana.newPass(new Pass::instructionCombine());
    // Pass::function_pass_mana.newPass(new Pass::Check("instructionCombine"));
    Pass::function_pass_mana.newPass(new Pass::DCE());

    Pass::function_pass_mana.newPass(new Pass::Gvnum());

    Pass::function_pass_mana.newPass(new Pass::GCM());

    Pass::function_pass_mana.newPass(new Pass::instructionCombine());
    // Pass::function_pass_mana.newPass(new Pass::Check("DCE"));
    // Pass::function_pass_mana.newPass(new Pass::CheckPhi("Before SimplifyCFG"));

    Pass::function_pass_mana.newPass(new Pass::SimplifyCFG());
    // Pass::function_pass_mana.newPass(new Pass::CheckPhi("After SimplifyCFG"));
    // Pass::function_pass_mana.newPass(new Pass::Check("SimplifyCFG"));

    Pass::function_pass_mana.newPass(new Pass::DCE());
    // Pass::function_pass_mana.newPass(new Pass::Check("DCE"));
    Pass::function_pass_mana.newPass(new Pass::TRE());
    // Pass::function_pass_mana.newPass(new Pass::Check("TRE"));
    // Pass::function_pass_mana.newPass(new Pass::CheckPhi("TRE"));
  }
  // Pass::function_pass_mana.newPass(new Pass::Rename());

  for (auto &f : compile_unit.functionTable()) {
    if (!f->isDeclaration()) Pass::function_pass_mana.run(f.get());
  }

#ifdef TEST
  configuration.setOstream(std::cout);
  IR::IRGenerator ir_generator(&compile_unit);
  ir_generator.generate(INFO);
  configuration.setOstream(asm_stream);
#endif

  RISCV::Program program(&compile_unit);
  RISCV::Generator sysy_riscv_gener(&program);
  for (auto &f : program.functions()) {
    while (true) {
      std::unique_ptr<RISCV::Allocator> allocator(new RISCV::Allocator(f.get()));
      allocator->allocate();
      auto res = allocator->calleeSaveRegUsed();
      f->initCalleeSaveReg(res);
      f->scheduleCalleeStack();
      f->initStackOffset();
      if (allocator->checkShortImm()) {
        // f->addCode(res);
        f->initStackPointer(res);
        allocator->apply();
        f->eliminateMove();
        break;
      }
    }
    RISCV::mergeBB(f.get());
    RISCV::removeBranch(f.get());
    // for (auto it = f->blocks().begin(); it != f->blocks().end(); it++) {
    //   auto block = it->get();
    //   if (block->insts().size()) {
    //     if (auto j = dynamic_cast<RISCV::Pseudo::J *>(block->insts().back().get())) {
    //       if (std::next(it) != f->blocks().end()) {
    //         if (j->label() == (*std::next(it))->name()) {
    //           block->insts().pop_back();
    //           break;
    //         }
    //       }
    //     }
    //   }
    // }
    // }
  }
  sysy_riscv_gener.generate(DEBUG);
  src_stream.close();
  asm_stream.clear();
  return 0;
}
