#include "util.hpp"
#include "visitor.hpp"

std::any Visitor::visitNumber(SysYParser::NumberContext *ctx) {
  if (ctx->INTLITERAL())
    return static_cast<IR::Value *>(IR::Constant::get(Util::parseInt(ctx->INTLITERAL()->getText())));
  if (ctx->FLOATLITERAL())
    return static_cast<IR::Value *>(IR::Constant::get((float)atof(ctx->FLOATLITERAL()->getText().c_str())));
  assert(0);
}

std::any Visitor::visitString(SysYParser::StringContext *ctx) {
  return static_cast<IR::Value *>(IR::Constant::getVoid());
}
