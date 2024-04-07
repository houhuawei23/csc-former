#include "visitor.hpp"

using namespace IR;

extern Type *ret_type;
extern BasicBlock *iftrue;
extern BasicBlock *iffalse;

BasicBlock *continue_target;
BasicBlock *break_target;

std::any Visitor::visitStmt(SysYParser::StmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  visitChildren(ctx);
  return {};
}

std::any Visitor::visitAssignStmt(SysYParser::AssignStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  Variable *variable = compile_unit->rvariable(ctx->lValue()->IDENTIFIER()->getText());
  assert(!variable->isConstant());
  IR::BasicBlock *prev_iftrue = iftrue;
  IR::BasicBlock *prev_iffalse = iffalse;
  iftrue = nullptr;
  iffalse = nullptr;
  IR::Value *value = std::any_cast<IR::Value *>(visit(ctx->exp()));
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  Value *addr = std::any_cast<Value *>(visit(ctx->lValue()));
  assert(value->type()->isI32() || value->type()->isFloat());
  assert(addr->type()->deref(1)->isI32() || addr->type()->deref(1)->isFloat());
  if (value->type() != addr->type()->deref(1)) {
    if (value->type()->isI32())
      value = irbuilder.newSitofpInst(value, Type::float_t());
    else if (value->type()->isFloat())
      value = irbuilder.newFptosiInst(value, Type::i32_t());
    else
      assert(0);
  }
  irbuilder.newStoreInst(value, addr);
  return {};
}

std::any Visitor::visitExpStmt(SysYParser::ExpStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  visit(ctx->exp());
  return {};
}

std::any Visitor::visitIfStmt(SysYParser::IfStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  BasicBlock *prev_iftrue = iftrue;
  BasicBlock *prev_iffalse = iffalse;
  iftrue = irbuilder.function()->newBasicBlock();
  iffalse = irbuilder.function()->newBasicBlock();
  BasicBlock *merge = nullptr;
  if (IR::Value *cond = std::any_cast<Value *>(visit(ctx->exp()))) {
    if (cond->type()->isI32()) cond = irbuilder.newIneInst(cond, Constant::get((int32_t)0));
    if (cond->type()->isFloat()) cond = irbuilder.newFoneInst(cond, Constant::get((float).0f));
    irbuilder.newBrInst(cond, iftrue, iffalse);
  }
  irbuilder.set(iftrue, iftrue->instructions().end());
  visit(ctx->stmt(0));
  if (irbuilder.basicBlock()->instructions().empty() ||
      !irbuilder.basicBlock()->instructions().back()->isTerminator()) {
    if (!merge) merge = irbuilder.function()->newBasicBlock();
    irbuilder.newJmpInst(merge);
  }
  irbuilder.set(iffalse, iffalse->instructions().end());
  if (ctx->stmt(1)) visit(ctx->stmt(1));
  if (irbuilder.basicBlock()->instructions().empty() ||
      !irbuilder.basicBlock()->instructions().back()->isTerminator()) {
    if (!merge) merge = irbuilder.function()->newBasicBlock();
    irbuilder.newJmpInst(merge);
  }
  if (merge) irbuilder.set(merge, merge->instructions().end());
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  return {};
}

std::any Visitor::visitWhileStmt(SysYParser::WhileStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  BasicBlock *prev_iftrue = iftrue;
  BasicBlock *prev_iffalse = iffalse;
  BasicBlock *prev_continue_target = continue_target;
  BasicBlock *prev_break_target = break_target;
  BasicBlock *condition = irbuilder.function()->newBasicBlock();
  iftrue = irbuilder.function()->newBasicBlock();
  iffalse = irbuilder.function()->newBasicBlock();
  continue_target = condition;
  break_target = iffalse;
  irbuilder.newJmpInst(condition);
  irbuilder.set(condition, condition->instructions().end());
  if (Value *cond = std::any_cast<Value *>(visit(ctx->exp()))) {
    if (cond->type()->isI32()) cond = irbuilder.newIneInst(cond, Constant::get((int32_t)0));
    if (cond->type()->isFloat()) cond = irbuilder.newFoneInst(cond, Constant::get((float).0));
    irbuilder.newBrInst(cond, iftrue, iffalse);
  }
  irbuilder.set(iftrue, iftrue->instructions().end());
  visit(ctx->stmt());
  if (irbuilder.basicBlock()->instructions().empty() || !irbuilder.basicBlock()->instructions().back()->isTerminator())
    irbuilder.newJmpInst(condition);
  irbuilder.set(iffalse, iffalse->instructions().end());
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  continue_target = prev_continue_target;
  break_target = prev_break_target;
  return {};
}

std::any Visitor::visitBreakStmt(SysYParser::BreakStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  irbuilder.newJmpInst(break_target);
  return {};
}

std::any Visitor::visitContinueStmt(SysYParser::ContinueStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  irbuilder.newJmpInst(continue_target);
  return {};
}

std::any Visitor::visitBlockStmt(SysYParser::BlockStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  compile_unit->enterScope();
  visitChildren(ctx);
  compile_unit->leaveScope();
  return {};
}

std::any Visitor::visitBlockItem(SysYParser::BlockItemContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  visitChildren(ctx);
  return {};
}

std::any Visitor::visitEmptyStmt(SysYParser::EmptyStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  return {};
}

std::any Visitor::visitReturnStmt(SysYParser::ReturnStmtContext *ctx) {
  if (irbuilder.basicBlock()->instructions().size() && irbuilder.basicBlock()->instructions().back()->isTerminator())
    return {};
  if (ctx->exp()) {
    IR::BasicBlock *prev_iftrue = iftrue;
    IR::BasicBlock *prev_iffalse = iffalse;
    iftrue = nullptr;
    iffalse = nullptr;
    IR::Value *ret_value = std::any_cast<IR::Value *>(visit(ctx->exp()));
    iftrue = prev_iftrue;
    iffalse = prev_iffalse;
    if (ret_value->type() != ret_type) {
      if (ret_type->isI32()) ret_value = irbuilder.newFptosiInst(ret_value, IR::Type::i32_t());
      if (ret_type->isFloat()) ret_value = irbuilder.newSitofpInst(ret_value, IR::Type::float_t());
    }
    irbuilder.newRetInst(ret_value);
  } else
    irbuilder.newRetInst(IR::Constant::getVoid());
  return {};
}
