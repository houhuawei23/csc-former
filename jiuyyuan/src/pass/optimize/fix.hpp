#ifndef __PASS_FIX_HPP__
#define __PASS_FIX_HPP__
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"
namespace Pass {
class FIX : public FunctionPass {
public:
  std::string_view name() override {
    return "FIX";
  }
  void run(IR::Function *func) override {
    for (auto &BB : func->basicBlocks()) {
      auto bb = BB.get();
      for (auto &inst : bb->instructions()) {
        if (auto br = dynamic_cast<IR::BrInst *>(inst.get())) {
          if (bb->successors().size() == 1) {
            auto jmp = new IR::JmpInst(bb, br->iftrue());
            br->removeAllUse();
            br->unUseAll();
            bb->instructions().pop_back();
            bb->instructions().emplace_back(jmp);
            break;
          }
        }
      }
    }
  }
};
}  // namespace Pass
#endif
