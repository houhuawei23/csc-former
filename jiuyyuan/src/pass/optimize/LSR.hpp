#ifndef __PASS_LSR_HPP__
#define __PASS_LSR_HPP__
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "SCEV.hpp"
#include "pass.hpp"
namespace Pass {
class LSR : public FunctionPass {
private:
  std::vector<IR::BinaryInst*> Multiplies;
  void collectAllLoopInvariantMultiplications(IR::Cycle* loop);
  void replaceSingleMulWithPhi(IR::Cycle* loop, IR::BinaryInst* mul);

public:
  std::string_view name() override {
    return "LSR";
  }
  void runOnLoop(IR::Cycle* loop);
  void run(IR::Function* func)override;
};
}  // namespace Pass
#endif
