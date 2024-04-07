#ifndef __ANALYSIS_LOOP_HPP__
#define __ANALYSIS_LOOP_HPP__
#include "infrastructure.hpp"
#include "pass.hpp"
#include<stack>
namespace Pass {

class Loop_Analyzer : public FunctionPass {
private:

public:
  // Loop_Analyzer();
  std::string_view name() override{
    return "Loop_Analyzer";
  }
  void run(IR::Function* func) override;
};

}  // namespace Pass


#endif
