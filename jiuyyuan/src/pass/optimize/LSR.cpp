#include "LSR.hpp"

#include "infrastructure.hpp"
#include "typesystem.hpp"
using namespace Pass;

void LSR::collectAllLoopInvariantMultiplications(IR::Cycle* loop) {
  Multiplies.clear();
  for (auto bb : loop->nodes)
    for (auto& instr : bb->instructions())
      if (auto multi = dynamic_cast<IR::BinaryInst*>(instr.get()); multi && multi->itype() == IR::MUL)
        if (loop->hasSCEV(multi)) Multiplies.push_back(multi);
}
void LSR::replaceSingleMulWithPhi(IR::Cycle* loop, IR::BinaryInst* mul) {
  auto& scev = loop->getSCEV(mul);

  auto initial = scev.at(0);
  std::vector<IR::BinaryInst*> initialVal;
  scev.getInstructionChainOfElement(0, initialVal);
  for (auto init : initialVal) {
    loop->Pre_Header()->insertBeforeTerminal(init);
  }

  auto step = scev.at(1);
  std::vector<IR::BinaryInst*> stepVal;
  scev.getInstructionChainOfElement(1, stepVal);
  for (auto step : stepVal) {
    loop->Pre_Header()->insertBeforeTerminal(step);
  }

  auto phi = new IR::PhiInst(loop->Header(), initial->type(), "");
  loop->Header()->instructions().emplace_front(phi);

  auto binary = new IR::BinaryInst(loop->Latch(), IR::ADD, step->type(), "", phi, step);
  loop->Latch()->insertBeforeTerminal(binary);

  phi->newIncoming(initial, loop->Pre_Header());
  phi->newIncoming(binary, loop->Latch());
  mul->replaceAllUseWith(phi);
  mul->unUseAll();
  for (auto it = mul->basicBlock()->instructions().begin(); it != mul->basicBlock()->instructions().end();) {
    if (it->get() == mul) {
      it = mul->basicBlock()->instructions().erase(it);
    } else
      it++;
  }
}

void LSR::runOnLoop(IR::Cycle* loop) {
  if (!loop) return;

  for (auto subLoop : loop->subLoops) runOnLoop(subLoop);

  collectAllLoopInvariantMultiplications(loop);

  for (auto mul : Multiplies) replaceSingleMulWithPhi(loop, mul);
}
void LSR::run(IR::Function* func) {
  for (auto loop : func->getTopLoops()) runOnLoop(loop);
}
