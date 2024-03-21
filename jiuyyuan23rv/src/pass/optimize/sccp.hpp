#ifndef __OPTIMIZE_SCCP_HPP__
#define __OPTIMIZE_SCCP_HPP__

// #include "core.hpp"
#include "infrastructure.hpp"
#include "global.hpp"
#include <unordered_map>
#include "pass.hpp"
using namespace IR;

namespace Pass {
class ConstPropagation : public FunctionPass {
private:
  std::list<Instruction*> delInstList;
  // std::list<BasicBlock*> delBBList;
  std::unordered_map<BasicBlock*,std::unordered_map<Value*,Constant*>>valueMap;
  std::list<BasicBlock*> visitedBB;

public:
  std::string_view name() override {
    return "ConstPropagation";
  }
  void run(IR::Function *pass_unit) override {

    if(pass_unit->isDeclaration()||pass_unit->basicBlocks().empty())return;
    delInstList.clear();
    // delBBList.clear();
    valueMap.clear();
    visitedBB.clear();
    visitBB(pass_unit->entry());
    delInst();
    delBB(pass_unit);
    // mergeBlocks(pass_unit);

  };
  void visitBB(BasicBlock *bb);
  bool visitInst(Instruction *inst,std::unordered_map<Value*,Constant*>&curStatus);
  void delInst();
  void delBB(Function *f);
  void mergeBlocks(Function *f);
  // void findEmptyBB(Function *f);
  // void delAllocaInst();
};
}  // namespace Pass

#endif
