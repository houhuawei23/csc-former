#include "visitor.hpp"

extern IR::BasicBlock *iftrue;
extern IR::BasicBlock *iffalse;

static bool is_global;
static bool is_constant;
static IR::Type *basic_type;
static IR::Type *variable_type;
static IR::Value *variable_addr;
static IR::Variable *variable;
static IR::Type *current_init_type;
static IR::Value *current_addr;
static size_t current_init_cnt;
static size_t current_zero_cnt;

std::any Visitor::visitDecl(SysYParser::DeclContext *ctx) {
  is_global = compile_unit->isGlobalScope();                   /* is global scope ? */
  is_constant = ctx->CONST();                                  /* is compile time value ? */
  basic_type = std::any_cast<IR::Type *>(visit(ctx->bType())); /* basic type int or float */
  for (const auto &var_def : ctx->varDef()) {
    std::string name = var_def->lValue()->IDENTIFIER()->getText();
    assert(!compile_unit->variable(name) && !(compile_unit->isGlobalScope() && compile_unit->function(name)));
    visit(var_def);                               /* calculate variable_type */
    variable_addr = compile_unit->isGlobalScope() /* calculate variable addr */
                        ? new IR::GlobalAddr(IR::Type::pointer_t(variable_type), name)
                        : variable_addr = irbuilder.newAllocaInst(variable_type);
    variable = compile_unit->newVariable(is_constant, name, variable_addr);
    current_init_type = IR::Type::pointer_t(variable_type); /* current init type */
    current_addr = nullptr;
    current_init_cnt = 0;
    current_zero_cnt = 0;
    if (var_def->ASSIGN()) {
      visit(var_def->init());
      if (current_zero_cnt) {
        variable->initializer().emplace_back(new IR::InitialValue(
            IR::InitialValue::ZERO, IR::Constant::get((int32_t)(current_zero_cnt * basic_type->sizeOf()))));
        if (!is_global) {
          if (!current_addr) {
            current_addr = irbuilder.newPtrtointInst(variable_addr, IR::Type::i32_t());
            current_addr = irbuilder.newInttoptrInst(current_addr, IR::Type::pointer_t(basic_type));
          }
          if (current_zero_cnt >= 256) {
            irbuilder.newCallInst(compile_unit->function("memset"),
                                  {current_addr, IR::Constant::get((int32_t)0),
                                   IR::Constant::get((int32_t)(current_zero_cnt * basic_type->sizeOf()))});
          } else {
            while (current_zero_cnt--) {
              if (current_addr->type()->deref(1)->isI32())
                irbuilder.newStoreInst(IR::Constant::get((int32_t)0), current_addr);
              if (current_addr->type()->deref(1)->isFloat())
                irbuilder.newStoreInst(IR::Constant::get((float).0f), current_addr);
              current_addr = irbuilder.newAddrAddInst(
                  current_addr, IR::Constant::get((int32_t)current_addr->type()->deref(1)->sizeOf()));
            }
          }
        }
        current_zero_cnt = 0;
      }
    } else if (compile_unit->isGlobalScope()) {
      variable->initializer().emplace_back(
          new IR::InitialValue(IR::InitialValue::ZERO, IR::Constant::get((int32_t)variable_type->sizeOf())));
    }
  }
  return {};
}

std::any Visitor::visitVarDef(SysYParser::VarDefContext *ctx) {
  variable_type = basic_type;
  for (int32_t i = ctx->lValue()->exp().size() - 1; i >= 0; i--) {
    IR::Constant *dim = static_cast<IR::Constant *>(std::any_cast<IR::Value *>(visit(ctx->lValue()->exp(i))));
    assert(dim->type()->isI32() && *(dim->getField<int32_t>()) > 0);
    variable_type = IR::Type::array_t(variable_type, *(dim->getField<int32_t>()));
  }
  return {};
}

std::any Visitor::visitScalarInit(SysYParser::ScalarInitContext *ctx) {
  current_init_cnt += 1;
  IR::BasicBlock *prev_iftrue = iftrue;
  IR::BasicBlock *prev_iffalse = iffalse;
  iftrue = nullptr;
  iffalse = nullptr;
  IR::Value *value = std::any_cast<IR::Value *>(visit(ctx->exp()));
  iftrue = prev_iftrue;
  iffalse = prev_iffalse;
  IR::Constant *c = dynamic_cast<IR::Constant *>(value);
  if ((is_constant || compile_unit->isGlobalScope()) && !c) assert(0);
  if (c && ((c->type()->isI32() && *c->getField<int32_t>() == 0) ||
            (c->type()->isFloat() && *c->getField<float>() == 0.0f))) {
    current_zero_cnt += 1;
    return {};
  }
  if (current_zero_cnt) {
    variable->initializer().emplace_back(new IR::InitialValue(
        IR::InitialValue::ZERO, IR::Constant::get((int32_t)(current_zero_cnt * basic_type->sizeOf()))));
    if (!is_global) {
      if (!current_addr) {
        current_addr = irbuilder.newPtrtointInst(variable_addr, IR::Type::i32_t());
        current_addr = irbuilder.newInttoptrInst(current_addr, IR::Type::pointer_t(basic_type));
      }
      if (current_zero_cnt >= 256) {
        irbuilder.newCallInst(compile_unit->function("memset"),
                              {current_addr, IR::Constant::get((int32_t)0),
                               IR::Constant::get((int32_t)(current_zero_cnt * basic_type->sizeOf()))});
      } else {
        while (current_zero_cnt--) {
          if (current_addr->type()->deref(1)->isI32())
            irbuilder.newStoreInst(IR::Constant::get((int32_t)0), current_addr);
          if (current_addr->type()->deref(1)->isFloat())
            irbuilder.newStoreInst(IR::Constant::get((float).0f), current_addr);
          current_addr = irbuilder.newAddrAddInst(current_addr,
                                                  IR::Constant::get((int32_t)current_addr->type()->deref(1)->sizeOf()));
        }
      }
    }
    current_zero_cnt = 0;
  }
  if (c && c->type() != basic_type) {
    if (basic_type->isI32())
      variable->initializer().emplace_back(
          new IR::InitialValue(IR::InitialValue::VALUE, IR::Constant::get((int32_t)*c->getField<float>())));
    if (basic_type->isFloat())
      variable->initializer().emplace_back(
          new IR::InitialValue(IR::InitialValue::VALUE, IR::Constant::get((int32_t)*c->getField<int32_t>())));
  } else {
    variable->initializer().emplace_back(new IR::InitialValue(IR::InitialValue::VALUE, value));
  }
  if (!is_global) {
    if (!current_addr) {
      current_addr = irbuilder.newPtrtointInst(variable_addr, IR::Type::i32_t());
      current_addr = irbuilder.newInttoptrInst(current_addr, IR::Type::pointer_t(basic_type));
    }
    if (current_addr->type()->deref(1) != value->type()) {
      if (value->type()->isFloat()) {
        value = irbuilder.newFptosiInst(value, IR::Type::i32_t());
      } else {
        value = irbuilder.newSitofpInst(value, IR::Type::float_t());
      }
    }

    irbuilder.newStoreInst(value, current_addr);
    current_addr =
        irbuilder.newAddrAddInst(current_addr, IR::Constant::get((int32_t)current_addr->type()->deref(1)->sizeOf()));
  }
  return {};
}

std::any Visitor::visitArrayInit(SysYParser::ArrayInitContext *ctx) {
  IR::Type *prev_init_type = current_init_type;
  do current_init_type = current_init_type->deref(1);
  while (current_init_type->isArray() && current_init_cnt % current_init_type->size());
  assert(current_init_type->isArray());
  size_t current_init_cnt_max = current_init_cnt + current_init_type->size();
  for (const auto &init : ctx->init()) visit(init);
  assert(current_init_cnt <= current_init_cnt_max);
  current_zero_cnt += current_init_cnt_max - current_init_cnt; /* fill rest with zero */
  current_init_cnt = current_init_cnt_max;
  current_init_type = prev_init_type;
  return nullptr;
}
