#include <cassert>

#include "visitor.hpp"

std::any Visitor::visitBType(SysYParser::BTypeContext *ctx) {
  if (ctx->INT()) return IR::Type::i32_t();
  if (ctx->FLOAT()) return IR::Type::float_t();
  assert(0);
}

std::any Visitor::visitReturnType(SysYParser::ReturnTypeContext *ctx) {
  if (ctx->VOID()) return IR::Type::void_t();
  if (ctx->INT()) return IR::Type::i32_t();
  if (ctx->FLOAT()) return IR::Type::float_t();
  assert(0);
}
