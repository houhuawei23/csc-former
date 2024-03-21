#ifndef __PASS_HPP__
#define __PASS_HPP__

#include "infrastructure.hpp"

namespace Pass {

#define PassType(unit)                         \
  class unit##Pass {                           \
  public:                                      \
    virtual ~unit##Pass() = default;           \
    virtual std::string_view name() = 0;       \
    virtual void run(IR::unit* pass_unit) = 0; \
  }

#define PassManaType(unit)                             \
  class unit##PassMana : public unit##Pass {           \
  protected:                                           \
    std::vector<unit##Pass*> _passes;                  \
                                                       \
  public:                                              \
    virtual ~unit##PassMana() = default;               \
    virtual std::string_view name() override {         \
      return "unit##PassMana";                         \
    }                                                  \
    virtual void run(IR::unit* pass_unit) override {   \
      for (auto& pass : _passes) pass->run(pass_unit); \
    }                                                  \
    std::vector<unit##Pass*>& passes() {               \
      return _passes;                                  \
    }                                                  \
    void newPass(unit##Pass* pass) {                   \
      _passes.emplace_back(pass);                      \
    }                                                  \
  };

PassType(CompileUnit);
PassType(Function);
PassType(BasicBlock);
PassManaType(CompileUnit);
PassManaType(Function);
PassManaType(BasicBlock);

extern CompileUnitPassMana compile_unit_pass_mana;
extern FunctionPassMana function_pass_mana;
extern BasicBlockPassMana basic_block_pass_mana;

}  // namespace Pass

#endif
