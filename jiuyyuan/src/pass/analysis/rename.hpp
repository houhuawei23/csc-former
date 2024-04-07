#ifndef __ANALYSIS_RENAME_HPP__
#define __ANALYSIS_RENAME_HPP__

#include "infrastructure.hpp"
#include "pass.hpp"

#include <unordered_set>

namespace Pass {

class Rename : public FunctionPass {
private:
  std::unordered_set<IR::Value*> _rename_progress;

public:
  std::string_view name();
  void run(IR::Function* pass_unit);
  void rename(IR::Value* value);
};

}  // namespace Pass

#endif
