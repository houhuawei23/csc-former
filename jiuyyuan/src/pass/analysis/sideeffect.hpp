#ifndef __ANALYSIS_SIDEEFFECT_HPP__
#define __ANALYSIS_SIDEEFFECT_HPP__

#include "pass.hpp"
#include "instruction.hpp"

#include <unordered_set>

namespace Pass {

class SideEffect : public CompileUnitPass {
private:
  std::unordered_map<IR::Function*, IR::Function*> _callee;
  std::unordered_map<IR::Function*, IR::Function*> _caller;
  std::unordered_map<IR::Function*, IR::GlobalAddr*> _load;
  std::unordered_map<IR::Function*, IR::GlobalAddr*> _store;
  std::unordered_map<IR::Function*, IR::Function*> _site;

public:
  std::string_view name() override {
    return "SideEffect";
  }
  void run(IR::CompileUnit* pass_unit) override {
    for (auto& function : pass_unit->functionTable()) {
      if (!function->isDeclaration()) {
        _callee.clear();
        _caller.clear();
        _load.clear();
        _store.clear();
        _site.clear();
      }
    }

    std::unordered_set<IR::Function*> has_side_effect;

    for (auto& function : pass_unit->functionTable()) {
      if (!function->isDeclaration()) {
        for (auto& basic_block : function->basicBlocks()) {
          for (auto& instruction : basic_block->instructions()) {
            if (auto load = dynamic_cast<IR::LoadInst*>(instruction.get())) {

            }
            if (auto store = dynamic_cast<IR::StoreInst*>(instruction.get())){

            }
            if (auto call = dynamic_cast<IR::CallInst*>(instruction.get())) {

            }
          }
        }
      }
    }
  }
};

}  // namespace Pass

#endif
