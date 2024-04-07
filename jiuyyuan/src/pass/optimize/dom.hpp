#ifndef __PASS_DOM_HPP__
#define __PASS_DOM_HPP__

#include "instruction.hpp"
#include "pass.hpp"

namespace Pass {

class IdomGen : public FunctionPass {
private:
  void getDfnum(IR::Function* func);
  void compress(IR::BasicBlock* v);
  IR::BasicBlock* eval(IR::BasicBlock* v);
  void link(IR::BasicBlock* pre, IR::BasicBlock* now);

public:
  void run(IR::Function* func) override;
  std::string_view name() override;
};

class DomTreeGen : public FunctionPass {
private:
  void computeDomLevel(IR::BasicBlock* bb, int level);
  void computeAllDom(IR::BasicBlock* bb);

public:
  void run(IR::Function* func) override;
  std::string_view name() override {
    return "domTree";
  }
};

class DomFrontierGen : public FunctionPass {
private:
  void computeDF(IR::BasicBlock* bb);

public:
  void run(IR::Function* func) override;
  std::string_view name() override {
    return "domFrontier";
  }
};

}  // namespace Pass
#endif
