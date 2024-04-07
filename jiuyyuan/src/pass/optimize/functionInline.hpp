#ifndef __OPTIMIZE_functionInline_HPP__
#define __OPTIMIZE_functionInline_HPP__
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"
#include <string_view>
namespace Pass {
class functionInline : public CompileUnitPass{
public:
  std::string_view name() override{return "functionInline";}
  void run(IR::CompileUnit* compileUnit) override;
  void inlineAtCall(IR::CallInst* call);
};
}
#endif
