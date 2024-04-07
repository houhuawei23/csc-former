#ifndef __OPTIMIZE_GVN_HPP__
#define __OPTIMIZE_GVN_HPP__

#include <unordered_map>
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"

using namespace IR;
namespace Pass {
class Gvnum : public FunctionPass{
public:
  // GlobalValueNumbering();
  std::string_view name() override {
    return "Gvnum";
  }

  void visitInst(IR::Instruction* inst);
  Value* checkoutTable(Value* val);
  // Value *Gvnum::checkoutLocalTable(Value *val);
  Value* getValueNumber(Instruction* inst);
  Value* getValueNumber(BinaryInst* binary);
  Value* getValueNumber(UnaryInst* unary);
  Value* getValueNumber(PhiInst* phi);
  Value* getValueNumber(CallInst* cal);
  Value* getValueNumber(AddrAddInst* addr);
  Value* getValueNumber(AddrDerefAddInst *addrderef);
  Value* getValueNumber(AllocaInst *alloca);
  // void Gvnum::visitload(IR::Instruction *inst);
  void run(IR::Function* pass_unit) override;
};
}

#endif
