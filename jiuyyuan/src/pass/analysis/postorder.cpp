#include "postorder.hpp"

namespace Pass {

std::string_view Postorder::name() {
  return "Postorder";
}

void Postorder::run(IR::Function* pass_unit) {
  _vis.clear();
  _postorder.clear();
  dfs(pass_unit->allocas());
}

void Postorder::dfs(IR::BasicBlock* basic_block) {
  if (_vis.count(basic_block)) return;
  _vis.emplace(basic_block);
  for (IR::BasicBlock* successor : basic_block->successors()) dfs(successor);
  _postorder.emplace_back(basic_block);
}

const std::vector<IR::BasicBlock*>& Postorder::postorder() {
  return _postorder;
}

}  // namespace Pass
