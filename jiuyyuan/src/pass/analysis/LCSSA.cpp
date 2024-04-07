#include "LCSSA.hpp"

#include "infrastructure.hpp"
#include "instruction.hpp"
using namespace Pass;

void collectLoopLiveOuts(IR::Cycle* loop, std::unordered_set<IR::Instruction*>& LoopLiveOuts) {
  for (auto bb : loop->nodes) {
    for (auto& insts : bb->instructions()) {
      auto inst = insts.get();
      for (auto use : inst->uses()) {
        auto uesr = use->user();
        if (auto userInst = dynamic_cast<IR::Instruction*>(uesr)) {
          auto user_bb = userInst->basicBlock();
          if (auto phi = dynamic_cast<IR::PhiInst*>(userInst)) {
            for (size_t size = 0; size < phi->operands().size() / 2; size++) {
              auto value = phi->value(size);
              auto pred = phi->basicBlock();
              if (value == inst) {
                user_bb = pred;
              }
            }
          }
          if (bb != user_bb && !loop->bb_sets.count(user_bb)) {
            // PrintMsg(instr->getSignature());
            LoopLiveOuts.insert(inst);
            break;
          }
        }
      }
    }
  }
}

// 可能存在的问题：bb不存在的情况未考虑
IR::Value* createLCSSAPhiForInstrInLoop(IR::BasicBlock* bb, IR::Instruction* instr,
                                        std::unordered_map<IR::BasicBlock*, IR::PhiInst*>& BBToPhi, IR::Cycle* loop) {
  if (BBToPhi.count(bb)) return BBToPhi[bb];
  if (!bb) {
    return IR::Constant::getUndefine();
  }
  auto idom = bb->idom;
  if (!loop->bb_sets.count(idom) && idom) {
    auto value = createLCSSAPhiForInstrInLoop(idom, instr, BBToPhi, loop);
    return value;
  }

  auto phi = new IR::PhiInst(bb, instr->type(), "");
  bb->instructions().emplace_front(phi);
  BBToPhi[bb] = phi;

  for (size_t size = 0; size < phi->operands().size() / 2; size++) {
    // auto value = phi->value(size);
    auto pred = phi->basicBlock();
    phi->newIncoming(createLCSSAPhiForInstrInLoop(pred, instr, BBToPhi, loop), pred);
  }
  return phi;
}

void replaceInstrUsesWithLCSSAPhisInLoop(IR::Cycle* loop, IR::Instruction* instr) {
  std::unordered_map<IR::BasicBlock*, IR::PhiInst*> BBToPhi;
  auto bb = instr->basicBlock();

  for (auto exit : loop->ExitBlocks) {
    if (!BBToPhi.count(exit) && exit->dom.count(bb)) {
      auto phi = new IR::PhiInst(exit, instr->type(), "");
      exit->instructions().emplace_front(phi);
      BBToPhi[exit] = phi;
      for (auto pred : exit->predecessors()) phi->newIncoming(instr, pred);
    }
  }

  std::vector<IR::Value*> users;
  for (auto use : instr->uses()) users.push_back(use->user());

  for (auto user : users) {
    if (auto userInstr = dynamic_cast<IR::Instruction*>(user)) {
      auto userBB = userInstr->basicBlock();
      auto phi = dynamic_cast<IR::PhiInst*>(userInstr);
      if (phi) {
        for (size_t size = 0; size < phi->operands().size() / 2; size++) {
          auto value = phi->value(size);
          auto pred = phi->basicBlock();
          if (value == instr) userBB = pred;
        }
      }
      if (userBB == bb || loop->bb_sets.count(userBB)) continue;

      auto value = createLCSSAPhiForInstrInLoop(userBB, instr, BBToPhi, loop);
      for (auto i = 0; i < userInstr->operands().size(); i++) {
        if (userInstr->operands().at(i))
          if (userInstr->operands().at(i)->value() == instr && !phi) userInstr->replaceOpeandWith(i, value);
      }
    }
  }
}

void LCSSA_Analyzer::runOnLoop(IR::Cycle* loop) {
  if (!loop) return;
  for (auto subLoop : loop->subLoops) runOnLoop(subLoop);

  std::unordered_set<IR::Instruction*> DefInUseOut;
  collectLoopLiveOuts(loop, DefInUseOut);

  if (DefInUseOut.empty()) return;

  if (loop->ExitBlocks.empty()) return;

  for (auto instr : DefInUseOut) replaceInstrUsesWithLCSSAPhisInLoop(loop, instr);
}
