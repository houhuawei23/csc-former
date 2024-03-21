#ifndef __OPTIMIZE_SCFG__
#define __OPTIMIZE_SCFG__

#include "analysis/preorder.hpp"
#include "pass.hpp"

namespace Pass {

class SCFG : public FunctionPass {
public:
  std::string_view name() override {
    return "SCFG";
  }
  void run(IR::Function* pass_unit) override {
    PreorderPass preorder_pass;
    preorder_pass.run(pass_unit);
    for (IR::BasicBlock* basic_block : preorder_pass.preorder) {
    }
    bool fixed;
    change = false;
    do {
      fixed = true;
      change |= !fixed;
    } while (!fixed);
    // removeDeadBB();
  }
  void deleteEdge() {
  }
};

}  // namespace Pass

#endif
