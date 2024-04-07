#ifndef __ANALYSIS_CHECK_HPP__
#define __ANALYSIS_CHECK_HPP__

#include <algorithm>

#include "infrastructure.hpp"
#include "pass.hpp"

namespace Pass {

class Check : public FunctionPass {
public:
  std::string _taregt;
  Check(const std::string& target) : FunctionPass(), _taregt(target) {
  }
  std::string_view name() override {
    return "Check";
  }
  void check(IR::Value* value) {
    for (auto use : value->uses()) {
      if (use->value() != value) {
        std::cout << _taregt << std::endl;
        assert(0);
      }
      if (use->user()->operands()[use->index()] != use) {
        std::cout << _taregt << std::endl;
        if(auto inst=dynamic_cast<IR::Instruction*>(use->user()))
          std::cout<<inst->opcode()<<std::endl;
        assert(0);
      }
    }
  }
  void run(IR::Function* pass_unit) override {
    for (auto& basic_block : pass_unit->basicBlocks()) {
      check(basic_block.get());
      for (auto& instruction : basic_block->instructions()) {
        check(instruction.get());
        for (auto operand : instruction->operands()) {
          if (operand) check(operand->value());
        }
      }
    }
  }
};
}  // namespace Pass

#endif
