#ifndef __OPTIMIZE_GCM_HPP__
#define __OPTIMIZE_GCM_HPP__

#include <cassert>

#include "analysis/postorder.hpp"
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"

namespace Pass {

class GCM : public FunctionPass {
private:
  std::unordered_set<IR::Instruction*> _vis;

public:
  std::string_view name() override {
    return "GCM";
  }
  void scheduleEarly(IR::Instruction* instruction) {
    if (_vis.count(instruction) || !isPinned(instruction)) return;
    _vis.emplace(instruction);

    auto dest = instruction->basicBlock()->function()->allocas();

    for (auto it = instruction->basicBlock()->instructions().begin();
         it != instruction->basicBlock()->instructions().end(); it++) {
      if (instruction == it->get()) {
        instruction = it->release();
        instruction->basicBlock()->instructions().erase(it);
        break;
      }
    }
    dest->instructions().emplace(std::prev(dest->instructions().end()), instruction);
    instruction->setBasicBlock(dest);

    for (auto operand : instruction->operands()) {
      if (operand && dynamic_cast<IR::Instruction*>(operand->value())) {
        auto op = static_cast<IR::Instruction*>(operand->value());
        scheduleEarly(op);
        if (!instruction->basicBlock()->dom.count(op->basicBlock())) {
          dest = op->basicBlock();
          for (auto it = instruction->basicBlock()->instructions().begin();
               it != instruction->basicBlock()->instructions().end(); it++) {
            if (instruction == it->get()) {
              instruction = it->release();
              instruction->basicBlock()->instructions().erase(it);
              break;
            }
          }
          dest->instructions().emplace(std::prev(dest->instructions().end()), instruction);
          instruction->setBasicBlock(dest);
        }
      }
    }
  }
  IR::BasicBlock* LCA(IR::BasicBlock* lhs, IR::BasicBlock* rhs) {
    if (!lhs) return rhs;
    if (!rhs) return lhs;
    while (lhs->domLevel > rhs->domLevel) lhs = lhs->idom;
    while (lhs->domLevel < rhs->domLevel) rhs = rhs->idom;
    while (lhs != rhs) {
      lhs = lhs->idom;
      rhs = rhs->idom;
    }
    return lhs;
  }
  void scheduleLate(IR::Instruction* instruction) {
    if (_vis.count(instruction) || !isPinned(instruction)) return;
    _vis.emplace(instruction);

    IR::BasicBlock* dest = nullptr;
    for (auto use : instruction->uses()) {
      if (auto user = dynamic_cast<IR::Instruction*>(use->user())) {
        scheduleLate(user);
        if (auto phi = dynamic_cast<IR::PhiInst*>(user)) {
          for (size_t i = 0; i < phi->operands().size() / 2; i++) {
            if (auto value = dynamic_cast<IR::Instruction*>(phi->value(i)); value && value == instruction) {
              dest = LCA(dest, static_cast<IR::BasicBlock*>(phi->incoming(i)));
            }
          }
        } else {
          dest = LCA(dest, user->basicBlock());
        }
      }
    }
    if (!dest) return;

    // TODO Loop
    auto func = instruction->basicBlock()->function();
    IR::BasicBlock* best = dest;
    auto getBBDepth = [&func](IR::BasicBlock* bb) -> int {
      if (auto loop = func->getLoopOfBB(bb)) return loop->depth;
      return 0;
    };
    size_t depth = getBBDepth(best);
    while (dest != instruction->basicBlock()) {
      dest = dest->idom;
      auto currDepth = getBBDepth(dest);
      if (currDepth < depth) {
        best = dest;
        depth = currDepth;
      }
    }

    for (auto it = instruction->basicBlock()->instructions().begin();
         it != instruction->basicBlock()->instructions().end(); it++) {
      if (instruction == it->get()) {
        instruction = it->release();
        instruction->basicBlock()->instructions().erase(it);
        break;
      }
    }
    best->instructions().emplace(std::prev(best->instructions().end()), instruction);
    instruction->setBasicBlock(best);

    for (auto use : instruction->uses()) {
      auto user = use->user();
      if (dynamic_cast<IR::PhiInst*>(user)) continue;
      if (auto userInst = dynamic_cast<IR::Instruction*>(user); userInst && userInst->basicBlock() == best) {
        for (auto it = best->instructions().begin(); it != best->instructions().end(); it++) {
          if (it->get() == instruction) break;
          if (it->get() == userInst) {
            for (auto it1 = instruction->basicBlock()->instructions().begin();
                 it1 != instruction->basicBlock()->instructions().end(); it1++) {
              if (instruction == it1->get()) {
                instruction = it1->release();
                instruction->basicBlock()->instructions().erase(it1);
                break;
              }
            }
            best->instructions().emplace(it, instruction);
            instruction->setBasicBlock(best);
          }
        }
      }
    }

    // for (auto it = instruction->basicBlock()->instructions().begin();
    //      it != instruction->basicBlock()->instructions().end(); it++) {
    //   for (auto use : instruction->uses()) {
    //     if (auto user = dynamic_cast<IR::Instruction*>(use->user()); user && user == it->get()) {
    //       if (dynamic_cast<IR::PhiInst*>(user)) continue;
    //       for (auto it = instruction->basicBlock()->instructions().begin();  // TODO
    //            it != instruction->basicBlock()->instructions().end(); it++) {
    //         if (instruction == it->get()) {
    //           instruction = it->release();
    //           instruction->basicBlock()->instructions().erase(it);
    //           break;
    //         }
    //       }
    //       best->instructions().emplace(it, instruction);
    //       instruction->setBasicBlock(best);
    //     }
    //   }
    //   if (instruction == it->get()) {
    //     break;
    //   }
    // }
    
  }
  bool isPinned(IR::Instruction* instruction) {
    if (dynamic_cast<IR::BinaryInst*>(instruction))
      return true;
    else if (dynamic_cast<IR::UnaryInst*>(instruction))
      return true;
    else if (dynamic_cast<IR::AddrAddInst*>(instruction))
      return true;
    else if (dynamic_cast<IR::AddrDerefAddInst*>(instruction))
      return true;
    else if (dynamic_cast<IR::CallInst*>(instruction))
      return false;  // TODO
    else
      return false;
  }
  void run(IR::Function* pass_unit) override {
    std::vector<IR::Instruction*> pinned;
    Postorder* postorder = new Postorder();
    postorder->run(pass_unit);
    for (auto basic_block : postorder->postorder())
      for (auto& instruction : basic_block->instructions())
        if (isPinned(instruction.get())) pinned.emplace_back(instruction.get());

    _vis.clear();
    for (auto instruction : pinned) {
      scheduleEarly(instruction);
      // _vis.emplace(instruction);
      // for (auto operand : instruction->operands()) {
      //   if (operand && dynamic_cast<IR::Instruction*>(operand->value())) {
      //     scheduleEarly(static_cast<IR::Instruction*>(operand->value()));
      //   }
      // }
    }

    _vis.clear();
    for (auto instruction : pinned) {
      scheduleLate(instruction);
      // _vis.emplace(instruction);
      // for (auto use : instruction->uses()) {
      //   if (use && dynamic_cast<IR::Instruction*>(use->user())) {
      //     scheduleLate(static_cast<IR::Instruction*>(use->user()));
      //   }
      // }
    }
  }
};

}  // namespace Pass

#endif
