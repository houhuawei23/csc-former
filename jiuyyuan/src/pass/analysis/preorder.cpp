#include "preorder.hpp"

namespace Pass {

std::string_view Preorder::name() {
  return "Preorder";
}

void Preorder::run(IR::Function* pass_unit) {
  _vis.clear();
  _preorder.clear();
  dfs(pass_unit->allocas());
}

void Preorder::dfs(IR::BasicBlock* basic_block) {
  if (_vis.count(basic_block)) return;
  _vis.emplace(basic_block);
  _preorder.emplace_back(basic_block);
  for (IR::BasicBlock* successor : basic_block->successors()) dfs(successor);
}

const std::vector<IR::BasicBlock*>& Preorder::preorder() {
  return _preorder;
}

}  // namespace Pass
