#include "loop.hpp"

#include "instruction.hpp"
using namespace Pass;

void connectSubloopsToLoop(IR::Cycle *loop, IR::Function *func, std::stack<IR::BasicBlock *> &BackedgeTo) {
  while (!BackedgeTo.empty()) {
    auto pred = BackedgeTo.top();
    BackedgeTo.pop();
    auto subLoop = func->getLoopOfBB(pred);
    if (!subLoop) {
      func->linkBBToLoop(pred, loop);
      if (pred == loop->Header()) continue;
      for (auto predOfPred : pred->predecessors()) BackedgeTo.push(predOfPred);
    } else {
      while (auto parent = subLoop->parentCycle) subLoop = parent;
      if (subLoop == loop) continue;
      subLoop->parentCycle = loop;
      pred = subLoop->Header();
      for (auto predOfPred : pred->predecessors())
        if (!func->getLoopOfBB(predOfPred) || func->getLoopOfBB(predOfPred) != subLoop) BackedgeTo.push(predOfPred);
    }
  }
}

void computeLatch(IR::Function *func) {
  for (auto loop : func->cycles()) {
    IR::BasicBlock *latch = nullptr;
    for (auto pred : loop->Header()->predecessors()) {
      if (loop->bb_sets.count(pred)) {
        latch = pred;
        break;
      }
    }
    loop->setLatch(latch);
  }
}

void compute_cycle_info(IR::Function *func) {
  for (auto loop : func->cycles()) {
    // auto a=it->nodes;
    //   auto loop=*it;
    for (auto node : loop->nodes) {
      auto &last_inst = *(--node->instructions().end());
      if (auto inst = dynamic_cast<IR::BrInst *>(last_inst.get())) {
        auto bb1 = inst->iftrue();
        auto bb2 = inst->iffalse();
        if (!loop->bb_sets.count(bb1) || !loop->bb_sets.count(bb2)) loop->ExitingBlocks.insert(node);
      }
      // else if(auto inst = dynamic_cast<IR::JmpInst *>(last_inst.get())){
      // auto bb1=inst->dest();
      // if(!loop->bb_sets.count(bb1))
      // loop->ExitingBlocks.insert(node);
      // }
      for (auto succ : node->successors()) {
        if (!loop->bb_sets.count(succ)) loop->ExitBlocks.insert(succ);
      }
      // auto last_inst = *last_it;
    }
    // IR::BasicBlock *latch = nullptr;
    // for (auto pred : loop->Header()->predecessors()) {
    //   if (loop->bb_sets.count(pred)) {
    //     latch = pred;
    //     break;
    //   }
    // }
    // loop->setLatch(latch);
  }
}

// void compute_sub_loop(IR::Function *func) {
//   for (auto loop : func->cycles()) {
//     if (loop->parentCycle != NULL) {
//       auto parent = loop->parentCycle;
//       auto res = find(parent->subLoops.begin(), parent->subLoops.end(), loop);
//       if (res != parent->subLoops.end()) {
//         continue;
//       } else {
//         parent->subLoops.push_back(loop);
//       }
//     } else {
//       continue;
//     }
//   }
// }

void compute_loop_index_info(IR::Function *func) {
  for (auto loop : func->cycles()) {
    auto latch = loop->Header();
    auto inst = (--latch->instructions().end())->get();
    // auto inst = &insts;
    auto br = dynamic_cast<IR::BrInst *>(inst);
    // auto jmp=dynamic_cast<IR::JmpInst*>(inst);
    // if(jmp)continue;
    if (br) {
      auto icmp = dynamic_cast<IR::IcmpInst *>(br->cond());
      if (!icmp) continue;
      loop->icmp = icmp;
      std::function<IR::PhiInst *(IR::Instruction *)> getPhi = [&](IR::Instruction *instr) -> IR::PhiInst * {
        if (auto phi = dynamic_cast<IR::PhiInst *>(instr))
          return phi;
        else if (auto binary = dynamic_cast<IR::BinaryInst *>(instr)) {
          if (auto defInstr = dynamic_cast<IR::Instruction *>(binary->lhs());
              defInstr && !loop->isLoopInvariant(defInstr)) {
            if (auto phi = getPhi(defInstr)) return phi;
          } else if (auto defInstr = dynamic_cast<IR::Instruction *>(binary->rhs());
                     defInstr && !loop->isLoopInvariant(defInstr))
            if (auto phi = getPhi(defInstr)) return phi;
        }
        return nullptr;
      };
      if (loop->isLoopInvariant(icmp->lhs())) {
        loop->end = icmp->lhs();
        if (auto instr = dynamic_cast<IR::Instruction *>(icmp->rhs()); instr && !loop->isLoopInvariant(instr)) {
          auto phi = getPhi(instr);
          if (phi) loop->phi = phi;
        }
      } else if (loop->isLoopInvariant(icmp->rhs())) {
        loop->end = icmp->rhs();
        if (auto instr = dynamic_cast<IR::Instruction *>(icmp->lhs()); instr && !loop->isLoopInvariant(instr)) {
          auto phi = getPhi(instr);
          if (phi) loop->phi = phi;
        }
      }
    }
  }
}

int getLoopDepth(IR::BasicBlock *bb) {
  auto func = bb->function();
  if (auto loop = func->getLoopOfBB(bb)) return loop->depth;
  return 0;
}

void computePreHeader(IR::Function *func) {
  for (auto loop : func->cycles()) {
    IR::BasicBlock *preHeader = nullptr;
    for (auto pred : loop->Header()->predecessors()) {
      if (getLoopDepth(pred) != loop->depth) {
        preHeader = pred;
        break;
      }
    }
    loop->setPre_Header(preHeader);
  }
}

void Loop_Analyzer::run(IR::Function *func) {
  func->clearLinkOfBBToLoop();
  func->getTopLoops().clear();
  func->cycles().clear();
  std::vector<IR::BasicBlock *> WorkList;
  std::unordered_set<IR::BasicBlock *> vis;
  IR::BasicBlock::DomTreeDfsPost(
      func->entry(),
      [&](IR::BasicBlock *bb) -> bool {
        if (vis.count(bb)) return true;
        vis.insert(bb);
        return false;
      },
      [&](IR::BasicBlock *bb) -> void {
        WorkList.push_back(bb);
      });

  std::stack<IR::BasicBlock *> BackedgeTo;
  for (auto header : WorkList) {
    for (auto pred : header->predecessors())
      if (pred->dom.count(header)) {
        BackedgeTo.push(pred);
      }
    if (!BackedgeTo.empty()) {
      auto loop = new IR::Cycle(header);
      connectSubloopsToLoop(loop, func, BackedgeTo);
    }
  }

  vis.clear();
  IR::BasicBlock::BasicBlockDfsPost(
      func->entry(),
      [&](IR::BasicBlock *bb) -> bool {
        if (vis.count(bb)) return true;
        vis.insert(bb);
        return false;
      },
      [&](IR::BasicBlock *bb) -> void {
        auto subLoop = func->getLoopOfBB(bb);
        if (subLoop && bb == subLoop->Header()) {
          if (subLoop->parentCycle)
            subLoop->parentCycle->subLoops.push_back(subLoop);
          else {
            func->getTopLoops().push_back(subLoop);
            subLoop->depth = 1;
          }
          std::reverse(subLoop->nodes.begin() + 1, subLoop->nodes.end());
          std::reverse(subLoop->subLoops.begin(), subLoop->subLoops.end());
          subLoop = subLoop->parentCycle;
        }

        for (; subLoop; subLoop = subLoop->parentCycle) {
          subLoop->nodes.push_back(bb);
          subLoop->bb_sets.insert(bb);
        }
      });

  std::stack<IR::Cycle *, std::vector<IR::Cycle *>> Stack(func->getTopLoops());
  while (!Stack.empty()) {
    auto loop = Stack.top();
    Stack.pop();
    func->cycles().push_back(loop);
    for (auto subLoop : loop->subLoops) {
      subLoop->depth = loop->depth + 1;
      Stack.push(subLoop);
    }
  }
  compute_cycle_info(func);
  computePreHeader(func);
  computeLatch(func);
  compute_loop_index_info(func);
}
