#include "visitor.hpp"

using namespace IR;

std::any Visitor::visitLValue(SysYParser::LValueContext *ctx) {
  Variable *variable = compile_unit->rvariable(ctx->IDENTIFIER()->getText());
  assert(variable);
  if (variable->isConstant() && variable->addr()->type()->refSize() == 1)
    return variable->initializer()[0]->value();
  Value *addr = variable->addr();
  if (addr->type()->refSize() == 1) return addr;
  if (!addr->type()->deref(1)->isArray()) addr = irbuilder.newLoadInst(addr);
  assert(addr->type()->deref(1)->isArray());
  for (auto &exp : ctx->exp()) {
    Value *index = std::any_cast<Value *>(visit(exp));
    addr = irbuilder.newAddrDerefAddInst(
        addr, irbuilder.newMulInst(index, Constant::get((int32_t)addr->type()->deref(2)->sizeOf())));
  }
  return addr;
}
