#ifndef __OPTIMIZE_simplifyCFG_HPP__
#define __OPTIMIZE_simplifyCFG_HPP__
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"
#include <string_view>
using namespace IR;
namespace Pass {
class SimplifyCFG: public FunctionPass {
public:
  void run(Function* pass_unit)override;
  std::string_view name() override{return "simplifyCFG";}
  // void deleteEdge(BasicBlock* from,BasicBlock* to);
  // void addEdge(BasicBlock *from, BasicBlock *to,BasicBlock *origion);
  // void redirectEdge(BasicBlock *preFrom, BasicBlock *newFrom,BasicBlock *to);
  // bool brToJmp(BasicBlock *bb);
  // bool deleteEmptyBB(BasicBlock *bb);
  // bool mergeBB(BasicBlock *bb);
  // bool upperTheBranch(BasicBlock *bb);
  // bool simplifyPhi(BasicBlock *bb);
  // void eraseDeadBB(Function *pass_unit);
  void findBrToJmp(Function *pass_unit);
  bool findJmpToDel(Function *pass_unit);
  void eraseUnreachableBB(Function* pass_unit);
  bool mergeBB(Function* pass_unit);
  bool simplifyPhiInst(Function* pass_unit);
};
} // namespace Pass
#endif
