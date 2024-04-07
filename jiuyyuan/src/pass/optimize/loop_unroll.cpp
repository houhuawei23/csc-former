#include "loop_unroll.hpp"

#include <cstddef>
#include <queue>
#include <stack>
#include <vector>

#include "SCEV.hpp"
#include "infrastructure.hpp"
#include "typesystem.hpp"
using namespace Pass;
void SCEV_Analyzer::BIV_to_SCEV(IR::Cycle* loop, IR::PhiInst* phi) {
  std::stack<IR::BinaryInst*> stack;
  std::set<IR::Value*> add_Invariant;
  std::set<IR::Value*> sub_Invariant;

  for (auto use : phi->uses()) {
    auto user = use->user();
    auto inst = dynamic_cast<IR::BinaryInst*>(user);
    if (inst && inst->basicBlock() && (inst->itype() == IR::ADD || inst->itype() == IR::SUB)) {
      stack.push(inst);
    }
  }

  while (!stack.empty()) {
    auto binary = stack.top();
    stack.pop();
    if (binary->itype() == IR::ADD) {
      if (loop->isLoopInvariant(binary->lhs())) {
        add_Invariant.insert(binary->lhs());
      } else if (loop->isLoopInvariant(binary->rhs())) {
        add_Invariant.insert(binary->rhs());
      } else
        return;
    } else if (binary->itype() == IR::SUB) {
      if (loop->isLoopInvariant(binary->rhs())) {
        sub_Invariant.insert(binary->rhs());
      } else
        return;
    }
    for (auto use : binary->uses()) {
      auto user = use->user();
      if (user == phi) {
        BIV2SCEV(loop, phi, add_Invariant, sub_Invariant);
        return;
      } else if (auto instr = dynamic_cast<IR::BinaryInst*>(user);
                 instr && (instr->itype() == IR::ADD || instr->itype() == IR::SUB))
        stack.push(instr);
    }
  }
}

void SCEV_Analyzer::BIV2SCEV(IR::Cycle* loop, IR::PhiInst* phi, std::set<IR::Value*>& adds,
                             std::set<IR::Value*>& subs) {
  IR::Value* initial = nullptr;
  for (size_t size = 0; size < phi->operands().size() / 2; size++) {
    auto val = phi->value(size);
    // auto pred=phi->basicBlock(size);
    if (loop->isLoopInvariant(val) && val) initial = val;
  }
  if (!initial) return;
  if (!adds.empty()) {
    auto step = *adds.begin();
    adds.erase(step);
    std::set<IR::BinaryInst*> binaryStore;
    for (auto sub : subs) {
      auto binary = new IR::BinaryInst(nullptr, IR::SUB, step->type(), "", step, sub);
      binaryStore.insert(binary);
      step = binary;
    }
    for (auto add : adds) {
      auto binary = new IR::BinaryInst(nullptr, IR::ADD, step->type(), "", step, add);
      binaryStore.insert(binary);
      step = binary;
    }
    IR::SCEV scev(initial, step, std::move(binaryStore));
    loop->logupSCEV(phi, scev);
    return;
  }
  auto sub = *subs.begin();
  subs.erase(sub);
  std::set<IR::BinaryInst*> binaryStore;
  auto step = new IR::BinaryInst(nullptr, IR::SUB, IR::Type::i32_t(), "", IR::Constant::get((int32_t)0), sub);

  binaryStore.insert(step);
  for (auto sub : subs) {
    step = new IR::BinaryInst(nullptr, IR::SUB, IR::Type::i32_t(), "", IR::Constant::get((int32_t)0), sub);

    binaryStore.insert(step);
  }
  IR::SCEV scev(initial, step, std::move(binaryStore));
  loop->logupSCEV(phi, scev);
}

void SCEV_Analyzer::findBIV(IR::Cycle* loop) {
  auto header = loop->Header();
  std::vector<IR::PhiInst*> phis;
  std::stack<IR::Instruction*> phi_user;
  for (auto& insts : header->instructions()) {
    auto inst = dynamic_cast<IR::PhiInst*>(insts.get());
    if (inst) {
      phis.push_back(inst);
    } else
      break;
  }
  for (auto phi : phis) {
    std::stack<IR::Instruction*> insts;
    for (auto use : phi->uses()) {
      auto instr = dynamic_cast<IR::Instruction*>(use->user());
      if (instr) insts.push(instr);
    }
    while (!insts.empty()) {
      auto instr = insts.top();
      auto inst = dynamic_cast<IR::PhiInst*>(instr);
      insts.pop();
      if (instr == phi) {
        BIV_to_SCEV(loop, phi);
        break;
      }
      if (inst) break;
      if (loop->isLoopInvariant(instr)) continue;
      for (auto use : instr->uses()) {
        auto user = use->user();
        if (auto inst = dynamic_cast<IR::Instruction*>(user)) {
          insts.push(inst);
        }
      }
    }
  }
}

void SCEV_Analyzer::BinaryInst_to_SCEV(IR::Cycle* loop, IR::BinaryInst* inst) {
  auto lhs = dynamic_cast<IR::Instruction*>(inst->lhs());
  auto rhs = dynamic_cast<IR::Instruction*>(inst->rhs());
  bool lhsisSCEV = loop->hasSCEV(lhs);
  bool rhsisSCEV = loop->hasSCEV(rhs);
  bool lhsisInvariant = loop->isLoopInvariant(inst->lhs());
  bool rhsisInvariant = loop->isLoopInvariant(inst->rhs());
  if ((lhsisSCEV && rhsisSCEV) || (lhsisInvariant && rhsisSCEV) || (lhsisSCEV && rhsisInvariant)) {
    IR::SCEV scev;
    if (inst->itype() == IR::ADD) {
      if (rhsisInvariant) {
        scev = inst->rhs() + loop->getSCEV(lhs);
      } else if (lhsisInvariant) {
        scev = inst->lhs() + loop->getSCEV(rhs);
      } else {
        scev = loop->getSCEV(lhs) + loop->getSCEV(rhs);
      }
    } else if (inst->itype() == IR::SUB) {
      if (rhsisInvariant) {
        scev = loop->getSCEV(lhs) - inst->rhs();
      } else if (!rhsisInvariant && !lhsisInvariant) {
        scev = loop->getSCEV(lhs) - loop->getSCEV(rhs);
      }
    } else if (inst->itype() == IR::MUL) {
      // scev=inst.lhs()*inst.rhs();
      if (rhsisInvariant) {
        scev = inst->rhs() * loop->getSCEV(lhs);
      } else if (lhsisInvariant) {
        scev = inst->lhs() * loop->getSCEV(rhs);
      }
    }
    // TO DO
    loop->logupSCEV(inst, scev);
    flag = false;
    return;
  }
}

void SCEV_Analyzer::runOnLoop(IR::Cycle* loop) {
  if (!loop) return;
  for (auto subloop : loop->subLoops) {
    runOnLoop(subloop);
  }
  // loop->cleanSCEV();
  loop->SCEVCheck.clear();
  findBIV(loop);
  do {
    flag = true;
    for (auto bb : loop->nodes) {
      for (auto& insts : bb->instructions()) {
        if (loop->hasSCEV(insts.get())) continue;
        auto inst = dynamic_cast<IR::BinaryInst*>(insts.get());
        if (inst && (inst->itype() == IR::ADD || inst->itype() == IR::SUB || inst->itype() == IR::MUL)) {
          BinaryInst_to_SCEV(loop, inst);
        }
      }
    }
  } while (!flag);
  if (loop->phi && loop->hasSCEV(loop->phi)) {
    // if (loop->phi) {
    auto phi = loop->phi;
    auto& scev = loop->getSCEV(phi);

    if (auto End = dynamic_cast<IR::Constant*>(loop->end))
      if (auto Initial = dynamic_cast<IR::Constant*>(scev.at(0)))
        if (auto Step = dynamic_cast<IR::Constant*>(scev.at(1))) {
          int c;
          if (loop->icmp->itype() == IR::IEQ || loop->icmp->itype() == IR::ISGE || loop->icmp->itype() == IR::ISLE)
            c = (End->getIntVal() + 1 - Initial->getIntVal()) / Step->getIntVal();
          else
            // c = (cEnd->getIntVal() - cInitial->getIntVal()) / cStep->getIntVal();
            if (((End->getIntVal() - Initial->getIntVal()) % Step->getIntVal()) == 0)
              c = (End->getIntVal() - Initial->getIntVal()) / Step->getIntVal();
            else
              c = (End->getIntVal() - Initial->getIntVal()) / Step->getIntVal() + 1;
          loop->iterationCount = c;
        }
  }
}

void SCEV_Clean::runOnLoop(IR::Cycle* loop) {
  for (auto subloop : loop->subLoops) {
    runOnLoop(subloop);
  }
  for (auto& [inst, scev] : loop->getSCEV()) {
    scev.clear();
    // inst->removeAllUse();
    // inst->unUseAll();
  }
}
