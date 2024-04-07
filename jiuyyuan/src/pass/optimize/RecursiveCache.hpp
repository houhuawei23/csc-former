#ifndef __OPTIMIZE_RECURSIVECACHE_HPP__
#define __OPTIMIZE_RECURSIVECACHE_HPP__

#include <unordered_map>
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"

using namespace IR;
namespace Pass {
class RecursiveCache : public CompileUnitPass{
public:
  // GlobalValueNumbering();
  std::string_view name() override {
    return "recuesivecache";
  }

  void run(IR::CompileUnit* pass_unit) override;
};
}

#endif
