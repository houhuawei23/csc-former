#ifndef __ANALYSIS_CHECKPHI_HPP__
#define __ANALYSIS_CHECKPHI_HPP__

#include <algorithm>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"

namespace Pass {

class CheckPhi : public FunctionPass {
public:
  std::string _taregt;
  CheckPhi(const std::string& target) : FunctionPass(), _taregt(target) {
  }
  std::string_view name() override {
    return "CheckPhi";
  }
  void checkPhi(IR::PhiInst* phi) {
    for (size_t i = 0; i < phi->operands().size() / 2; i++) {
      if (!((phi->operands()[2 * i] && phi->operands()[2 * i + 1]) ||
            (!phi->operands()[2 * i] && !phi->operands()[2 * i + 1]))) {
        std::cout << _taregt << std::endl;
        std::cout << (bool)phi->operands()[2 * i] << " " << (bool)phi->operands()[2 * i + 1] << std::endl;
        assert(0);
      }
    }
  }
  void run(IR::Function* pass_unit) override {
    for (auto& basic_block : pass_unit->basicBlocks()) {
      for (auto& instruction : basic_block->instructions()) {
        if (auto phi = dynamic_cast<IR::PhiInst*>(instruction.get())) checkPhi(phi);
      }
    }
  }
};
}  // namespace Pass

#endif
