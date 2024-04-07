#ifndef __OPTIMISE_TRE_HPP__
#define __OPTIMISE_TRE_HPP__

#include "instruction.hpp"
#include "pass.hpp"

namespace Pass {

class TRE : public FunctionPass {
public:
  std::string_view name() override {
    return "TRE";
  }
  void run(IR::Function* pass_unit) override {
    std::vector<IR::BasicBlock*> basic_blocks;
    std::vector<IR::CallInst*> calls;
    std::vector<std::list<std::unique_ptr<IR::Instruction>>::iterator> callits;
    std::vector<IR::RetInst*> rets;
    std::vector<std::list<std::unique_ptr<IR::Instruction>>::iterator> retits;
    for (auto& basic_block : pass_unit->basicBlocks()) {
      for (auto it = basic_block->instructions().begin(); it != basic_block->instructions().end(); it++) {
        auto instruction = it->get();
        if (auto call = dynamic_cast<IR::CallInst*>(instruction)) {
          if (call->callee()->name() == this->name()) {
            if (call->uses().size() == 1) {
              if (auto ret = dynamic_cast<IR::RetInst*>(call->uses().front()->user())) {
                if (call->basicBlock() == ret->basicBlock()) {
                  basic_blocks.emplace_back(basic_block.get());
                  calls.emplace_back(call);
                  callits.emplace_back(it);
                  auto xit = it;
                  while (xit != basic_block->instructions().end()) {
                    if (xit->get() == ret) {
                      retits.emplace_back(xit);
                      break;
                    }
                    xit++;
                  }
                  rets.emplace_back(ret);
                  basic_block->insertBeforeTerminal(new IR::JmpInst(basic_block.get(), pass_unit->entry()));
                  basic_block->setIsExit(false);
                  basic_block->successors().emplace_back(pass_unit->entry());
                  pass_unit->entry()->predecessors().emplace_back(basic_block.get());
                  break;
                }
              }
            }
          }
        }
      }
    }
    if (basic_blocks.size()) {
      size_t index = 0;
      for (auto& argument : pass_unit->arguments()) {
        // std::cout << calls[index]->callee()->name() << std::endl;
        auto phi = new IR::PhiInst(pass_unit->entry(), argument->type(), "");
        // std::cout << phi->type()->name() << std::endl;
        pass_unit->entry()->insertAfterPhi(phi);
        argument->replaceAllUseWith(phi);
        phi->newIncoming(argument.get(), pass_unit->allocas());
        for (size_t i = 0; i < basic_blocks.size(); i++) {
          // std::cout << calls[i]->operands()[index + 1]->value()->name() << std::endl;
          phi->newIncoming(calls[i]->operands()[index + 1]->value(), basic_blocks[i]);
        }
        index++;
      }
    }
    if (rets.size())
      for (auto ret : rets) {
        ret->removeAllUse();
        ret->unUseAll();
      }
    if (calls.size())
      for (auto call : calls) {
        call->removeAllUse();
        call->unUseAll();
      }
    if (retits.size()) {
      for (auto retit : retits) {
        (*retit)->basicBlock()->instructions().erase(retit);
      }
    }
    if (callits.size()) {
      for (auto callit : callits) {
        (*callit)->basicBlock()->instructions().erase(callit);
      }
    }
  }
};

}  // namespace Pass

#endif
