#ifndef __ANALYSIS_IPANALYSIS_HPP__
#define __ANALYSIS_IPANALYSIS_HPP__

#include <unordered_set>
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"
#include "AliasAnalysis.hpp"

namespace Pass {

class IPAnalysis : public CompileUnitPass {

public:
  std::string_view name() override{return "IPAnalysis";}
  void run(IR::CompileUnit* pass_unit) override;

};

}  // namespace Pass

#endif
