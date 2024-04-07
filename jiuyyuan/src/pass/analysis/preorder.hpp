#ifndef __ANALYSIS_PREORDER_HPP__
#define __ANALYSIS_PREORDER_HPP__

#include <unordered_set>

#include "pass.hpp"

namespace Pass {

class Preorder : public FunctionPass {
private:
  std::unordered_set<IR::BasicBlock*> _vis;
  std::vector<IR::BasicBlock*> _preorder;

public:
  std::string_view name() override;
  void run(IR::Function* pass_unit) override;
  void dfs(IR::BasicBlock* basic_block);
  const std::vector<IR::BasicBlock*>& preorder();
};

}  // namespace Pass

#endif
