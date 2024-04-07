
#include "rename.hpp"

namespace Pass {

std::string_view Rename::name() {
  return "rename";
}

void Rename::run(IR::Function* pass_unit) {
  _rename_progress.clear();
  for (const auto& basic_block : pass_unit->basicBlocks()) {
    rename(basic_block.get());
    for (const auto& instruction : basic_block->instructions()) {
      rename(instruction.get());
    }
  }
}

void Rename::rename(IR::Value* value) {
  if (!value->type()->isVoid() && !value->name().length() && !_rename_progress.count(value))
    value->rename("%" + std::to_string(_rename_progress.size()));
  _rename_progress.emplace(value);
};

}  // namespace Pass
