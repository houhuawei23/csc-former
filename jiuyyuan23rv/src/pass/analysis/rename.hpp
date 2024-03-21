#ifndef __ANALYSIS_RENAME_HPP__
#define __ANALYSIS_RENAME_HPP__

#include <functional>
#include <unordered_set>

#include "infrastructure.hpp"
#include "pass.hpp"

namespace Pass {

class RenamePass : public FunctionPass {
public:
  std::string_view name() override {
    return "rename";
  }
  void run(IR::Function* pass_unit) override {
    std::unordered_set<IR::Value*> rename_progress;
    std::function<void(IR::Value*)> rename = [&](IR::Value* value) -> void {
      if (!value->type()->isVoid() && !value->name().length() && !rename_progress.count(value))
        value->rename("%" + std::to_string(rename_progress.size()));
      rename_progress.insert(value);
    };
    for (const auto& argument : pass_unit->arguments()) rename(argument.get());
    for (const auto& basic_block : pass_unit->basicBlocks()) {
      rename(basic_block.get());
      for (const auto& instruction : basic_block->instructions()) rename(instruction.get());
    }
  }
};

}  // namespace Pass

#endif
