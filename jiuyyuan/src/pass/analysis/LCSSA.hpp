#ifndef __ANALYSIS_LCSSA_HPP__
#define __ANALYSIS_LCSSA_HPP__
#include "infrastructure.hpp"
#include "pass.hpp"
namespace Pass {

class LCSSA_Analyzer : public FunctionPass {
private:
public:
  std::string_view name() override {
    return "LCSSA_Analyzer";
  }
  void runOnLoop(IR::Cycle* loop);
  void run(IR::Function* func) override{
    for(auto loop:func->getTopLoops()){
      if(loop->iterationCount)runOnLoop(loop);
    }
  };
};

}  // namespace Pass
#endif
