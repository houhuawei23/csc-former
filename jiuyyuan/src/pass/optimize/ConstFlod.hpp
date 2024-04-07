#ifndef __OPTIMIZE_ConstFlod_HPP__
#define __OPTIMIZE_ConstFlod_HPP__
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"
#include <string_view>
using namespace IR;
namespace Pass {
class ConstFlod : public FunctionPass {
public:
  std::string_view name() override { return "ConstFlod"; }
  void run(Function *pass_unit) override;
  Value *constFlod(BinaryInst *inst);
  Value *constFlod(UnaryInst *inst);
  Value *constFlod(IcmpInst* inst);
  Value *constFlod(FcmpInst* inst);
};
} // namespace Pass
#endif
