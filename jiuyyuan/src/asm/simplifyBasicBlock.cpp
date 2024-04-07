#include "simplifyBasicBlock.hpp"

#include <iostream>

#include "inst.hpp"
namespace RISCV {
void mergeBB(Function *func) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (auto &bb : func->blocks()) {
      auto lastInst = bb->insts().back().get();
      if (auto jInst = dynamic_cast<Pseudo::J *>(lastInst)) {
        auto target = jInst->_block;
        if (target->preds().size() == 1 && bb->succs().size() == 1) {
          // mergeBB
          flag = true;
          if (bb->insts().size() >= 2) {
            if (auto beq = dynamic_cast<Target::BTypeInst *>((--(--bb->insts().end()))->get());
                beq && beq->label() == jInst->label())
                bb->insts().pop_back();
          }
          bb->insts().pop_back();
          // move insts
          for (auto &inst : target->insts()) {
            auto mem = inst.release();
            bb->insts().emplace_back(mem);
          }
          // 修改前驱后继
          bb->succs().clear();
          target->preds().clear();
          for (auto succOfsucc = target->succs().begin(); succOfsucc != target->succs().end(); succOfsucc++) {
            bb->succs().emplace(*succOfsucc);
            for (auto predOfsucc = (*succOfsucc)->preds().begin(); predOfsucc != (*succOfsucc)->preds().end();
                 predOfsucc++) {
              if (*predOfsucc == target) {
                (*succOfsucc)->preds().erase(predOfsucc);
                break;
              }
            }
            (*succOfsucc)->preds().emplace(bb.get());
          }
        }
      }
    }
    func->eraseUnreachableBB();
  }
  func->eraseUnreachableBB();
}

void removeBranch(Function *func) {
  // basicblock reorder
  func->basicblockReorder();
  // remove j inst
  for (auto it = func->blocks().begin(); it != func->blocks().end(); it++) {
    auto next = std::next(it);
    if (next == func->blocks().end()) break;
    auto inst = it->get()->insts().back().get();
    if (auto jInst = dynamic_cast<Pseudo::J *>(inst)) {
      if (jInst->_block == next->get()) {
        it->get()->insts().pop_back();
      }
    }
  }
}
}  // namespace RISCV
