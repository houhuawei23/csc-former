#ifndef __ANALYSIS_PREORDER_HPP__
#define __ANALYSIS_PREORDER_HPP__

#include "pass.hpp"

#include <unordered_set>

namespace Pass {

class PreorderPass : public FunctionPass {
public:
  std::unordered_set<IR::BasicBlock*> vis;
  std::vector<IR::BasicBlock*> preorder;
  std::string_view name() override {
    return "analysis preorder";
  }
  void run(IR::Function* pass_unit) override {
    vis.clear();
    preorder.clear();
    dfsBasicBlock(pass_unit->entry());
  }
  void dfsBasicBlock(IR::BasicBlock* basic_block) {
    if (vis.count(basic_block)) return;
    vis.emplace(basic_block);
    preorder.emplace_back(basic_block);
    for (IR::BasicBlock* succ : basic_block->successors()) dfsBasicBlock(succ);
  }
};

}  // namespace Pass

#endif
