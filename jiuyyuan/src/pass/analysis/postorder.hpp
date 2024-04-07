#ifndef __ANALYSIS_POSTORDER_HPP__
#define __ANALYSIS_POSTORDER_HPP__

#include <unordered_set>

#include "pass.hpp"

namespace Pass {

class Postorder : public FunctionPass {
private:
  std::unordered_set<IR::BasicBlock*> _vis;
  std::vector<IR::BasicBlock*> _postorder;

public:
  std::string_view name() override;
  void run(IR::Function* pass_unit) override;
  void dfs(IR::BasicBlock* basic_block);
  const std::vector<IR::BasicBlock*>& postorder();
};

}  // namespace Pass

#endif
