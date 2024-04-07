#include "visitor.hpp"

extern IR::BasicBlock *iftrue;
extern IR::BasicBlock *iffalse;

std::any Visitor::visitCall(SysYParser::CallContext *ctx) {
  std::string callee_name = ctx->IDENTIFIER()->getText();
  std::vector<IR::Value *> arguments;
  if (callee_name == "starttime") {
    callee_name = "_sysy_" + callee_name;
    arguments.emplace_back(IR::Constant::get(((int32_t)ctx->getStart()->getLine())));
  } else if (callee_name == "stoptime") {
    callee_name = "_sysy_" + callee_name;
    arguments.emplace_back(IR::Constant::get(((int32_t)ctx->getStart()->getLine())));
  } else {
  }
  IR::Function *callee = compile_unit->function(callee_name);
  assert(callee);
  // std::cout << callee->name() << std::endl;
  if (ctx->funcRParams()) arguments = std::any_cast<std::vector<IR::Value *>>(visit(ctx->funcRParams()));
  for (size_t i = 0; i < arguments.size(); i++) {
    if (callee->name() == "starttime") break;
    if (callee->name() == "stoptime") break;
    IR::Type *f_type = callee->type()->argumentTypes()[i];
    IR::Type *r_type = arguments[i]->type();
    if (f_type == r_type) continue;
    if (f_type->isFloat() && r_type->isI32()) {
      arguments[i] = irbuilder.newSitofpInst(arguments[i], IR::Type::float_t());
      continue;
    }
    if (f_type->isI32() && r_type->isFloat()) {
      arguments[i] = irbuilder.newFptosiInst(arguments[i], IR::Type::i32_t());
      continue;
    }
    if (f_type->isPointer() && r_type->isPointer()) continue;
    assert(0);
    // continue;
  }
  return static_cast<IR::Value *>(irbuilder.newCallInst(callee, arguments));
}

std::any Visitor::visitFuncRParams(SysYParser::FuncRParamsContext *ctx) {
  std::vector<IR::Value *> arguments;
  IR::BasicBlock *prev_iftrue = iftrue;
  IR::BasicBlock *prev_iffalse = iffalse;
  iftrue = nullptr;
  iffalse = nullptr;
  for (auto &exp : ctx->exp()) arguments.emplace_back(std::any_cast<IR::Value *>(visit(exp)));
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  return arguments;
}
