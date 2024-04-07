#include "global.hpp"
#include "visitor.hpp"

using namespace IR;

std::any Visitor::visitComp(SysYParser::CompContext *ctx) {
  compile_unit->newFunction(true, Type::function_t(Type::i32_t(), {}), "getint");
  compile_unit->newFunction(true, Type::function_t(Type::i32_t(), {}), "getch");
  compile_unit->newFunction(true, Type::function_t(Type::float_t(), {}), "getfloat");
  compile_unit->newFunction(true, Type::function_t(Type::i32_t(), {Type::pointer_t(Type::array_t(Type::i32_t(), 0))}),
                            "getarray");
  compile_unit->newFunction(true, Type::function_t(Type::i32_t(), {Type::pointer_t(Type::array_t(Type::float_t(), 0))}),
                            "getfarray");
  compile_unit->newFunction(true, Type::function_t(Type::void_t(), {Type::i32_t()}), "putint");
  compile_unit->newFunction(true, Type::function_t(Type::void_t(), {Type::i32_t()}), "putch");
  compile_unit->newFunction(true, Type::function_t(Type::void_t(), {Type::float_t()}), "putfloat");
  compile_unit->newFunction(
      true, Type::function_t(Type::void_t(), {Type::i32_t(), Type::pointer_t(Type::array_t(Type::i32_t(), 0))}),
      "putarray");
  compile_unit->newFunction(
      true, Type::function_t(Type::void_t(), {Type::i32_t(), Type::pointer_t(Type::array_t(Type::float_t(), 0))}),
      "putfarray");
  compile_unit->newFunction(true, Type::function_t(Type::void_t(), {}), "putf");
  compile_unit->newFunction(true, Type::function_t(Type::void_t(), {Type::i32_t()}), "_sysy_starttime");
  compile_unit->newFunction(true, Type::function_t(Type::void_t(), {Type::i32_t()}), "_sysy_stoptime");
  compile_unit->newFunction(
      true, Type::function_t(Type::void_t(), {Type::pointer_t(Type::void_t()), Type::i32_t(), Type::i32_t()}),
      "memset");
  visitChildren(ctx);
  compile_unit->newFunction(true,Type::function_t(Type::i32_t(),{}),"__thread_create");
  compile_unit->newFunction(true,Type::function_t(Type::void_t(),{Type::i32_t()}),"__thread_join");
  Function *main_function = compile_unit->function("main");
  if (!main_function || main_function->type() != Type::function_t(Type::i32_t(), {})) assert(0);
  return {};
}
