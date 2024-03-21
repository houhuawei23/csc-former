#ifndef __OPTIMIZE_DCE_HPP__
#define __OPTIMIZE_DCE_HPP__

#include "pass.hpp"
#include "analysis/preorder.hpp"
#include "infrastructure.hpp"
#include "instruction.hpp"

namespace Pass {

class DCE : public FunctionPass {
public:
  std::unordered_set<IR::Instruction*> alive;
  std::string_view name() override {
    return "DCE";
  }
  void run(IR::Function* pass_unit) override {
    alive.clear();
    PreorderPass preorder_pass;
    preorder_pass.run(pass_unit);
    for (auto it = preorder_pass.preorder.rbegin(); it != preorder_pass.preorder.rend(); it++)
      for (auto& instruction : (*it)->instructions())
        if (isVisableAlive(instruction.get())) propagateAlive(instruction.get());
    std::vector<std::list<std::unique_ptr<IR::Instruction>>::iterator> dead;
    for (auto it0 = pass_unit->basicBlocks().begin(); it0 != pass_unit->basicBlocks().end(); it0++)
      for (auto it1 = (*it0)->instructions().begin(); it1 != (*it0)->instructions().end(); it1++)
        if (!alive.count(it1->get())) dead.emplace_back(it1);
    for (auto it : dead) (*it)->basicBlock()->instructions().erase(it);
  }
  bool isVisableAlive(IR::Instruction* instr) {
    if (dynamic_cast<IR::StoreInst*>(instr))
      return true;
    else if (dynamic_cast<IR::BrInst*>(instr))
      return true;
    else if (dynamic_cast<IR::JmpInst*>(instr))
      return true;
    else if (dynamic_cast<IR::RetInst*>(instr))
      return true;
    else if (dynamic_cast<IR::CallInst*>(instr))  // TODO
      return true;
    else
      return false;
  }
  void propagateAlive(IR::Instruction* instr) {
    alive.insert(instr);
    for (auto& use : instr->operands())
      if (auto operand = dynamic_cast<IR::Instruction*>(use.value()); operand && !alive.count(operand))
        propagateAlive(operand);
  }
};

}  // namespace Pass

#endif
