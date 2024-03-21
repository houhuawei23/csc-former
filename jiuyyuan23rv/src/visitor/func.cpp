#include "visitor.hpp"

IR::Type *ret_type;
static std::vector<IR::Type *> argument_types;
static std::vector<std::string> argument_names;

std::any Visitor::visitFuncDef(SysYParser::FuncDefContext *ctx) {
  assert(compile_unit->isGlobalScope());
  argument_names.clear();
  argument_types.clear();
  ret_type = std::any_cast<IR::Type *>(visit(ctx->returnType()));
  if (ctx->funcFParams()) visit(ctx->funcFParams());
  IR::Function *function =
      compile_unit->newFunction(false, IR::Type::function_t(ret_type, argument_types), ctx->IDENTIFIER()->getText());
  compile_unit->enterScope();
  irbuilder.set(function->entry(), function->entry()->instructions().end());
  for (size_t i = 0; i < argument_names.size(); i++) {
    IR::Argument *argument = function->newArgument(argument_types[i], argument_names[i]);
    IR::Value *addr = irbuilder.newAllocaInst(argument_types[i]);
    irbuilder.newStoreInst(argument, addr);
    auto variable = compile_unit->newVariable(false, argument_names[i], addr);
    variable->initializer().emplace_back(new IR::InitialValue(IR::InitialValue::VALUE, argument));
  }
  visit(ctx->blockStmt());
  if (irbuilder.basicBlock()->instructions().empty() || !irbuilder.basicBlock()->instructions().back()->isTerminator())
    irbuilder.newRetInst(IR::Constant::get());
  compile_unit->leaveScope();
  return nullptr;
}

std::any Visitor::visitFuncFParams(SysYParser::FuncFParamsContext *ctx) {
  for (auto &param : ctx->funcFParam()) visit(param);
  return {};
}

std::any Visitor::visitFuncFParam(SysYParser::FuncFParamContext *ctx) {
  argument_names.emplace_back(ctx->IDENTIFIER()->getText());
  IR::Type *argument_type = std::any_cast<IR::Type *>(visit(ctx->bType()));
  if (ctx->LBRACKET().empty()) {
    argument_types.emplace_back(argument_type);
    return {};
  }
  for (int32_t i = ctx->exp().size() - 1; i >= 0; i--) {
    auto *dim = static_cast<IR::Constant *>(std::any_cast<IR::Value *>(visit(ctx->exp(i))));
    assert(dim->type()->isI32() && *(dim->getField<int32_t>()) > 0);
    argument_type = IR::Type::array_t(argument_type, *(dim->getField<int32_t>()));
  }
  argument_types.emplace_back(IR::Type::pointer_t(IR::Type::array_t(argument_type, 0)));
  return {};
}
