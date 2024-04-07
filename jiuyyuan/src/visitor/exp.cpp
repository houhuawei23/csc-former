#include "visitor.hpp"

IR::BasicBlock *iftrue = nullptr;
IR::BasicBlock *iffalse = nullptr;

std::any Visitor::visitParenExp(SysYParser::ParenExpContext *ctx) {
  return visit(ctx->exp());
}

std::any Visitor::visitLValueExp(SysYParser::LValueExpContext *ctx) {
  IR::Value *addr = std::any_cast<IR::Value *>(visit(ctx->lValue()));
  if (addr->type()->refSize() == 1)
    return static_cast<IR::Value *>(irbuilder.newLoadInst(addr));
  else
    return addr;
}

std::any Visitor::visitNumberExp(SysYParser::NumberExpContext *ctx) {
  return visit(ctx->number());
}

std::any Visitor::visitStringExp(SysYParser::StringExpContext *ctx) {
  return visit(ctx->string());
}

std::any Visitor::visitCallExp(SysYParser::CallExpContext *ctx) {
  return visit(ctx->call());
}

std::any Visitor::visitUnaryExp(SysYParser::UnaryExpContext *ctx) {
  if (iftrue && iffalse) {
    IR::BasicBlock *prev_iftrue = iftrue;
    IR::BasicBlock *prev_iffalse = iffalse;
    if (ctx->NOT()) {
      iftrue = prev_iffalse;
      iffalse = prev_iftrue;
    }
    if (IR::Value *cond = std::any_cast<IR::Value *>(visit(ctx->exp()))) {
      if (cond->type()->isI32()) cond = irbuilder.newIneInst(cond, IR::Constant::get((int32_t)0));
      if (cond->type()->isFloat()) cond = irbuilder.newFoneInst(cond, IR::Constant::get((float).0f));
      irbuilder.newBrInst(cond, iftrue, iffalse);
    }
    iftrue = prev_iftrue;
    iffalse = prev_iffalse;
    return static_cast<IR::Value *>(nullptr);
  }
  IR::BasicBlock *prev_iftrue = iftrue;
  IR::BasicBlock *prev_iffalse = iffalse;
  iftrue = nullptr;
  iffalse = nullptr;
  IR::Value *rhs = std::any_cast<IR::Value *>(visit(ctx->exp()));
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  if (IR::Constant *c = dynamic_cast<IR::Constant *>(rhs)) {
    if (ctx->ADD()) return static_cast<IR::Value *>(c);
    if (ctx->SUB()) return static_cast<IR::Value *>(-*c);
    if (ctx->NOT()) return static_cast<IR::Value *>(!*c);
  }
  if (rhs->type()->isI1()) {
    if (ctx->ADD()) return static_cast<IR::Value *>(irbuilder.newZextInst(rhs, IR::Type::i32_t()));
    if (ctx->SUB())
      return static_cast<IR::Value *>(
          irbuilder.newSubInst(IR::Constant::get((int32_t)0), irbuilder.newZextInst(rhs, IR::Type::i32_t())));
    if (ctx->NOT()) return static_cast<IR::Value *>(irbuilder.newIeqInst(rhs, IR::Constant::get(false)));
  }
  if (rhs->type()->isI32()) {
    if (ctx->ADD()) return rhs;
    if (ctx->SUB()) return static_cast<IR::Value *>(irbuilder.newSubInst(IR::Constant::get(0), rhs));
    if (ctx->NOT()) return static_cast<IR::Value *>(irbuilder.newIeqInst(rhs, IR::Constant::get(0)));
  }
  if (rhs->type()->isFloat()) {
    if (ctx->ADD()) return rhs;
    if (ctx->SUB()) return static_cast<IR::Value *>(irbuilder.newFnegInst(rhs));
    if (ctx->NOT()) return static_cast<IR::Value *>(irbuilder.newFoeqInst(rhs, IR::Constant::get(0.f)));
  }
  assert(0);
}

std::any Visitor::visitMulExp(SysYParser::MulExpContext *ctx) {
  IR::BasicBlock *prev_iftrue = iftrue;
  IR::BasicBlock *prev_iffalse = iffalse;
  iftrue = nullptr;
  iffalse = nullptr;
  IR::Value *lhs = std::any_cast<IR::Value *>(visit(ctx->exp(0)));
  IR::Value *rhs = std::any_cast<IR::Value *>(visit(ctx->exp(1)));
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  IR::Constant *l = dynamic_cast<IR::Constant *>(lhs);
  IR::Constant *r = dynamic_cast<IR::Constant *>(rhs);
  if (l && r) {
    if (ctx->MUL()) return static_cast<IR::Value *>((*l) * (*r));
    if (ctx->DIV()) return static_cast<IR::Value *>((*l) / (*r));
    if (ctx->MOD()) return static_cast<IR::Value *>((*l) % (*r));
  }
  if (lhs->type()->isI1()) lhs = irbuilder.newZextInst(lhs, IR::Type::i32_t());
  if (rhs->type()->isI1()) rhs = irbuilder.newZextInst(rhs, IR::Type::i32_t());
  if (lhs->type()->isI32() && rhs->type()->isI32()) {
    if (ctx->MUL()) return static_cast<IR::Value *>(irbuilder.newMulInst(lhs, rhs));
    if (ctx->DIV()) return static_cast<IR::Value *>(irbuilder.newSdivInst(lhs, rhs));
    if (ctx->MOD()) return static_cast<IR::Value *>(irbuilder.newSremInst(lhs, rhs));
  }
  if (lhs->type()->isI32()) lhs = irbuilder.newSitofpInst(lhs, IR::Type::float_t());
  if (rhs->type()->isI32()) rhs = irbuilder.newSitofpInst(rhs, IR::Type::float_t());
  if (ctx->MUL()) return static_cast<IR::Value *>(irbuilder.newFmulInst(lhs, rhs));
  if (ctx->DIV()) return static_cast<IR::Value *>(irbuilder.newFdivInst(lhs, rhs));
  assert(0);
}

std::any Visitor::visitAddExp(SysYParser::AddExpContext *ctx) {
  IR::BasicBlock *prev_iftrue = iftrue;
  IR::BasicBlock *prev_iffalse = iffalse;
  iftrue = nullptr;
  iffalse = nullptr;
  IR::Value *lhs = std::any_cast<IR::Value *>(visit(ctx->exp(0)));
  IR::Value *rhs = std::any_cast<IR::Value *>(visit(ctx->exp(1)));
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  IR::Constant *l = dynamic_cast<IR::Constant *>(lhs);
  IR::Constant *r = dynamic_cast<IR::Constant *>(rhs);
  if (l && r) {
    if (ctx->ADD()) return static_cast<IR::Value *>((*l) + (*r));
    if (ctx->SUB()) return static_cast<IR::Value *>((*l) - (*r));
  }
  if (lhs->type()->isI1()) lhs = irbuilder.newZextInst(lhs, IR::Type::i32_t());
  if (rhs->type()->isI1()) rhs = irbuilder.newZextInst(rhs, IR::Type::i32_t());
  if (lhs->type()->isI32() && rhs->type()->isI32()) {
    if (ctx->ADD()) return static_cast<IR::Value *>(irbuilder.newAddInst(lhs, rhs));
    if (ctx->SUB()) return static_cast<IR::Value *>(irbuilder.newSubInst(lhs, rhs));
  }
  if (lhs->type()->isI32()) lhs = irbuilder.newSitofpInst(lhs, IR::Type::float_t());
  if (rhs->type()->isI32()) rhs = irbuilder.newSitofpInst(rhs, IR::Type::float_t());
  if (ctx->ADD()) return static_cast<IR::Value *>(irbuilder.newFaddInst(lhs, rhs));
  if (ctx->SUB()) return static_cast<IR::Value *>(irbuilder.newFsubInst(lhs, rhs));
  assert(0);
}

std::any Visitor::visitRelExp(SysYParser::RelExpContext *ctx) {
  IR::BasicBlock *prev_iftrue = iftrue;
  IR::BasicBlock *prev_iffalse = iffalse;
  iftrue = nullptr;
  iffalse = nullptr;
  IR::Value *lhs = std::any_cast<IR::Value *>(visit(ctx->exp(0)));
  IR::Value *rhs = std::any_cast<IR::Value *>(visit(ctx->exp(1)));
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  IR::Constant *l = dynamic_cast<IR::Constant *>(lhs);
  IR::Constant *r = dynamic_cast<IR::Constant *>(rhs);
  if (l && r) {
    if (ctx->LT()) return static_cast<IR::Value *>((*l) < (*r));
    if (ctx->LE()) return static_cast<IR::Value *>((*l) <= (*r));
    if (ctx->GT()) return static_cast<IR::Value *>((*l) > (*r));
    if (ctx->GE()) return static_cast<IR::Value *>((*l) >= (*r));
  }
  if (lhs->type()->isI1()) lhs = irbuilder.newZextInst(lhs, IR::Type::i32_t());
  if (rhs->type()->isI1()) rhs = irbuilder.newZextInst(rhs, IR::Type::i32_t());
  if (lhs->type()->isI32() && rhs->type()->isI32()) {
    if (ctx->LT()) return static_cast<IR::Value *>(irbuilder.newIsltInst(lhs, rhs));
    if (ctx->LE()) return static_cast<IR::Value *>(irbuilder.newIsleInst(lhs, rhs));
    if (ctx->GT()) return static_cast<IR::Value *>(irbuilder.newIsgtInst(lhs, rhs));
    if (ctx->GE()) return static_cast<IR::Value *>(irbuilder.newIsgeInst(lhs, rhs));
  }
  if (lhs->type()->isI32()) lhs = irbuilder.newSitofpInst(lhs, IR::Type::float_t());
  if (rhs->type()->isI32()) rhs = irbuilder.newSitofpInst(rhs, IR::Type::float_t());
  if (ctx->LT()) return static_cast<IR::Value *>(irbuilder.newFoltInst(lhs, rhs));
  if (ctx->LE()) return static_cast<IR::Value *>(irbuilder.newFoleInst(lhs, rhs));
  if (ctx->GT()) return static_cast<IR::Value *>(irbuilder.newFogtInst(lhs, rhs));
  if (ctx->GE()) return static_cast<IR::Value *>(irbuilder.newFogeInst(lhs, rhs));
  assert(0);
}

std::any Visitor::visitEqExp(SysYParser::EqExpContext *ctx) {
  IR::BasicBlock *prev_iftrue = iftrue;
  IR::BasicBlock *prev_iffalse = iffalse;
  iftrue = nullptr;
  iffalse = nullptr;
  IR::Value *lhs = std::any_cast<IR::Value *>(visit(ctx->exp(0)));
  IR::Value *rhs = std::any_cast<IR::Value *>(visit(ctx->exp(1)));
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  IR::Constant *l = dynamic_cast<IR::Constant *>(lhs);
  IR::Constant *r = dynamic_cast<IR::Constant *>(rhs);
  if (l && r) {
    if (ctx->EQ()) return static_cast<IR::Value *>((*l) == (*r));
    if (ctx->NE()) return static_cast<IR::Value *>((*l) != (*r));
  }
  if (lhs->type()->isI1()) lhs = irbuilder.newZextInst(lhs, IR::Type::i32_t());
  if (rhs->type()->isI1()) rhs = irbuilder.newZextInst(rhs, IR::Type::i32_t());
  if (lhs->type()->isI32() && rhs->type()->isI32()) {
    if (ctx->EQ()) return static_cast<IR::Value *>(irbuilder.newIeqInst(lhs, rhs));
    if (ctx->NE()) return static_cast<IR::Value *>(irbuilder.newIneInst(lhs, rhs));
  }
  if (lhs->type()->isI32()) lhs = irbuilder.newSitofpInst(lhs, IR::Type::float_t());
  if (rhs->type()->isI32()) rhs = irbuilder.newSitofpInst(rhs, IR::Type::float_t());
  if (ctx->EQ()) return static_cast<IR::Value *>(irbuilder.newFoeqInst(lhs, rhs));
  if (ctx->NE()) return static_cast<IR::Value *>(irbuilder.newFoneInst(lhs, rhs));
  assert(0);
}

std::any Visitor::visitAndExp(SysYParser::AndExpContext *ctx) {
  if (iftrue && iffalse) {
    IR::BasicBlock *prev_iftrue = iftrue;
    IR::BasicBlock *prev_iffalse = iffalse;
    IR::BasicBlock *next = irbuilder.function()->newBasicBlock();
    iftrue = next;
    iffalse = prev_iffalse;
    if (IR::Value *cond = std::any_cast<IR::Value *>(visit(ctx->exp(0)))) {
      if (cond->type()->isI32()) cond = irbuilder.newIneInst(cond, IR::Constant::get(0));
      if (cond->type()->isFloat()) cond = irbuilder.newFoneInst(cond, IR::Constant::get(0.f));
      irbuilder.newBrInst(cond, iftrue, iffalse);
    }
    irbuilder.set(next, next->instructions().end());
    iftrue = prev_iftrue;
    iffalse = prev_iffalse;
    if (IR::Value *cond = std::any_cast<IR::Value *>(visit(ctx->exp(1)))) {
      if (cond->type()->isI32()) cond = irbuilder.newIneInst(cond, IR::Constant::get(0));
      if (cond->type()->isFloat()) cond = irbuilder.newFoneInst(cond, IR::Constant::get(0.f));
      irbuilder.newBrInst(cond, iftrue, iffalse);
    }
    iftrue = prev_iftrue;
    iffalse = prev_iffalse;
    return static_cast<IR::Value *>(nullptr);
  }
  assert(0);
}

std::any Visitor::visitOrExp(SysYParser::OrExpContext *ctx) {
  if (iftrue && iffalse) {
    IR::BasicBlock *prev_iftrue = iftrue;
    IR::BasicBlock *prev_iffalse = iffalse;
    IR::BasicBlock *next = irbuilder.function()->newBasicBlock();
    iftrue = prev_iftrue;
    iffalse = next;
    if (IR::Value *cond = std::any_cast<IR::Value *>(visit(ctx->exp(0)))) {
      if (cond->type()->isI32()) cond = irbuilder.newIneInst(cond, IR::Constant::get(0));
      if (cond->type()->isFloat()) cond = irbuilder.newFoneInst(cond, IR::Constant::get(0.f));
      irbuilder.newBrInst(cond, iftrue, iffalse);
    }
    irbuilder.set(next, next->instructions().end());
    iftrue = prev_iftrue;
    iffalse = prev_iffalse;
    if (IR::Value *cond = std::any_cast<IR::Value *>(visit(ctx->exp(1)))) {
      if (cond->type()->isI32()) cond = irbuilder.newIneInst(cond, IR::Constant::get(0));
      if (cond->type()->isFloat()) cond = irbuilder.newFoneInst(cond, IR::Constant::get(0.f));
      irbuilder.newBrInst(cond, iftrue, iffalse);
    }
    iftrue = prev_iftrue;
    iffalse = prev_iffalse;
    return static_cast<IR::Value *>(nullptr);
  }
  assert(0);
}
