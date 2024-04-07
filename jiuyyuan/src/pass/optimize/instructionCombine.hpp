#ifndef __OPTIMIZE_instructionCombine_HPP__
#define __OPTIMIZE_instructionCombine_HPP__

// #include "core.hpp"
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"
#include <unordered_map>
using namespace IR;
namespace Pass {
class instructionCombine : public FunctionPass {
public:
  std::string_view name() override { return "instructionCombine"; }
  Instruction *visitBinary(BinaryInst *inst);
  Instruction *visitADD(BinaryInst *inst);
  Instruction *visitSUB(BinaryInst *inst);
  void run(IR::Function *pass_unit) override {
    for (auto &bb : pass_unit->basicBlocks()) {
      for (auto inst = bb->instructions().begin();
           inst != bb->instructions().end(); inst++) {
        if (auto bI = dynamic_cast<BinaryInst *>(inst->get())) {
          // if can simplify, then simplify; else visit binary inst
          if (auto combine = visitBinary(bI); combine != bI) {
            bI->replaceAllUseWith(combine);
            bI->unUseAll();
            inst->reset(combine);
            continue;
          }
          // if(auto divLhs=dynamic_cast<BinaryInst*>(bI->lhs());divLhs&&divLhs->itype()==IR::SDIV){
          //   if(auto divRhs=dynamic_cast<BinaryInst*>(bI->rhs());divRhs&&divRhs->itype()==IR::SDIV){
          //     if(auto rhsOfdivLhs=dynamic_cast<Constant*>(divLhs->rhs());rhsOfdivLhs&&rhsOfdivLhs->isInt()){
          //       if(auto rhsOfdivRhs=dynamic_cast<Constant*>(divRhs->rhs());rhsOfdivRhs&&rhsOfdivRhs->isInt()){
          //         if(rhsOfdivLhs->getIntVal()==rhsOfdivRhs->getIntVal()){
          //           // X1/C + X2/C -> (X1+X2)/C
          //           auto newAddInst=new BinaryInst(bI->basicBlock(),IR::ADD,bI->type(),"",divLhs->lhs(),divRhs->lhs());
          //           auto newDivInst=new BinaryInst(bI->basicBlock(),IR::SDIV,bI->type(),"",newAddInst,Constant::get(static_cast<int32_t>(rhsOfdivLhs->getIntVal())));
          //           bI->basicBlock()->instructions().emplace(inst, newAddInst);
          //           bI->basicBlock()->instructions().emplace(inst, newDivInst);
          //           bI->replaceAllUseWith(newDivInst);
          //         }
          //       }
          //     }
          //   }
          // }
        }
      }
    }
  }
};
} // namespace Pass

#endif
