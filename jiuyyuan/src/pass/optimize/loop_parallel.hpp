#ifndef __PASS_LOOPPARALLEL_HPP__
#define __PASS_LOOPPARALLEL_HPP__

#include <queue>
#include <vector>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"

namespace Pass {

class LoopParallel : public FunctionPass {
private:
  bool Parallelizable(IR::Cycle* loop);
  void runOnloop(IR::Cycle* loop);
  bool isPureStore(IR::StoreInst* store,IR::Cycle* loop);
  bool isPureBinary(IR::BinaryInst* binary,IR::StoreInst* store,IR::Cycle* loop);

public:

  void run(IR::Function * func)override;
  std::string_view name() override{
    return "LoopParallel";
  }
};
}  // namespace Pass
#endif
