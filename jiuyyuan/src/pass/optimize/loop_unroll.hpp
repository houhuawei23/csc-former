#ifndef __PASS_UNROLL_HPP__
#define __PASS_UNROLL_HPP__

#include <queue>
#include <vector>
#include <stack>
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"

namespace Pass {
constexpr int maxCount = 90;
class SCEV_Analyzer : public FunctionPass {
private:
  bool flag;
  void BIV_to_SCEV(IR::Cycle* loop, IR::PhiInst* phi);
  void create_SCEV(IR::Cycle* loop, IR::PhiInst* phi, std::set<IR::Value*>& adds, std::set<IR::Value*>& subs);
  void findBIV(IR::Cycle* loop);
  void BIV2SCEV(IR::Cycle* loop, IR::PhiInst* phi, std::set<IR::Value*>& adds, std::set<IR::Value*>& subs);
  void BinaryInst_to_SCEV(IR::Cycle* loop, IR::BinaryInst* inst);

public:
  std::string_view name() override {
    return "SCEV_Analyzer";
  }
  void runOnLoop(IR::Cycle* loop);
  void run(IR::Function* func) override {
    for (auto loop : func->getTopLoops()) {
      runOnLoop(loop);
    }
  };
};

class SCEV_Clean : public FunctionPass {
private:
public:
  void runOnLoop(IR::Cycle* loop);
  std::string_view name() override {
    return "SCEV_Clean";
  }
  void run(IR::Function* func) override {
    for (auto loop : func->getTopLoops()) {
      runOnLoop(loop);
    }
  }
};
class Loop_Unroll : public FunctionPass {
public:
  std::string_view name() override {
    return "Loop_Unroll";
  }

  void runOnLoop(IR::Cycle* loop) {
    // if(loop->get)
    auto legal_loop = [&](IR::Cycle* loop) -> bool {
      if (loop->ExitBlocks.size() != 1 || loop->ExitingBlocks.size() != 1) {
        return false;
      }
      if(loop->nodes.size()>100)return false;
      for(auto bb:loop->Header()->successors()){
        for(auto &instr:bb->instructions()){
          if(auto inst=dynamic_cast<IR::IcmpInst*>(instr.get())){
            return false;
          }
        }
      }
      if (auto count = loop->iterationCount; !count)
        return false;
      else if (count > maxCount)
        return false;
      for (auto bb : loop->nodes) {
        for (auto& insts : bb->instructions()) {
          auto inst = dynamic_cast<IR::CallInst*>(insts.get());
          if (inst) return false;
        }
      }
      return true;
    };
    if (!legal_loop(loop)) return;
    auto header = loop->Header();
    auto latch = loop->Latch();
    auto exit = *loop->ExitBlocks.begin();
    std::unordered_map<IR::PhiInst*, IR::Value*> CurrentIncomingValue;
    std::unordered_map<IR::PhiInst*,IR::PhiInst*> OutLoopPhiReplace;
    std::vector<IR::PhiInst*> header_phi;
    for (auto& inst : header->instructions()) {
      auto phi = dynamic_cast<IR::PhiInst*>(inst.get());
      if (phi) {
        header_phi.push_back(phi);
        for (size_t size = 0; size < phi->operands().size() / 2; size++) {
          auto value = phi->value(size);
          auto pred = dynamic_cast<IR::BasicBlock*>(phi->incoming(size));
          if (pred == latch) CurrentIncomingValue[phi] = value;
        }
      } else
        break;
    }
    auto latchBr = (--latch->instructions().end())->get();
    // latch->instructions().erase(latchBr);
    for (auto it = latch->instructions().begin(); it != latch->instructions().end();) {
      auto& insts = *it;
      auto inst = insts.get();
      if (inst == latchBr) {
        inst->removeAllUse();
        inst->unUseAll();
        it = latch->instructions().erase(it);
      } else
        it++;
    }
    // latchBr->unUseAll();
    // for (auto op : latchBr->operands()) {
    //   op->value()->uses().remove(op);
    // }
    // latchBr->operands().clear();
    latch->successors().clear();

    std::vector<std::pair<IR::BasicBlock*, IR::BasicBlock*>> latchHeaderEdge;
    IR::BasicBlock* preLatch = latch;
    IR::BasicBlock* nowHeader = nullptr;
    std::unordered_map<IR::Value*, IR::Value*> copyMap;
    for (int i = 1; i < loop->iterationCount; i++) {
      copyMap.clear();
      auto loopCpy = loop->getLoopCopy(loop, copyMap, CurrentIncomingValue);
      auto headerCpy = loopCpy->Header();
      auto latchCpy = loopCpy->Latch();

      nowHeader = headerCpy;
      latchHeaderEdge.push_back(std::make_pair(preLatch, nowHeader));
      preLatch = latchCpy;
    }
    latchHeaderEdge.push_back(std::make_pair(preLatch, exit));
    // auto phi=new IR::PhiInst(exit,nullptr,"");
    // IR::Value* VAL;
    for (auto& instr : exit->instructions()) {
      if (auto phi = dynamic_cast<IR::PhiInst*>(instr.get())) {
        for (size_t size = 0; size < phi->operands().size() / 2; size++) {
          IR::Value* incomingVal = nullptr;
          auto value = phi->value(size);
          auto pred = dynamic_cast<IR::BasicBlock*>(phi->incoming(size));
          if (pred == header) {
            incomingVal = value;
            for (auto& head_instr : header->instructions()) {
              if (auto head_phi = dynamic_cast<IR::PhiInst*>(head_instr.get())) {
                for (size_t i = 0; i < head_phi->operands().size() / 2; i++) {
                  auto head_value = head_phi->value(i);
                  auto head_pred = dynamic_cast<IR::BasicBlock*>(head_phi->incoming(i));
                  if (head_pred == latch && incomingVal == head_instr.get()) {
                    // if (copyMap[head_value]) {
                    phi->newIncoming(copyMap[head_value], preLatch);
                    OutLoopPhiReplace[head_phi]=phi;
                    for (auto succ : exit->successors()) {
                      for (auto& succ_instr : succ->instructions()) {
                        if (auto succ_phi = dynamic_cast<IR::PhiInst*>(succ_instr.get())) {
                          for (size_t succ_i = 0; succ_i < succ_phi->operands().size() / 2; succ_i++) {
                            // auto succ_value=succ_phi->value(i);
                            auto succ_pred = dynamic_cast<IR::BasicBlock*>(succ_phi->incoming(succ_i));
                            if (succ_pred == exit) {
                              succ_phi->replaceOpeandWith(succ_i * 2, phi);
                            }
                          }
                        }
                      }
                    }
                    // VAL=value;
                    break;
                    // }
                  }
                }
              }
            }
          }
        }
      }
    }
    for (auto& bb : loop->parentFunc->basicBlocks()) {
      auto BB = bb.get();
      if (!loop->bb_sets.count(BB))
        for (auto& instr : BB->instructions()) {
          auto inst = instr.get();
          if (auto phi = dynamic_cast<IR::PhiInst*>(inst)) {
            for (size_t size = 0; size < phi->operands().size() / 2; size++) {
              auto value = phi->value(size);
              auto pred = dynamic_cast<IR::BasicBlock*>(phi->incoming(size));
              for (auto head_phi : header_phi) {
                if (head_phi == dynamic_cast<IR::PhiInst*>(value)) {
                  phi->removeIncomingByBB(pred);
                  phi->newIncoming(OutLoopPhiReplace[head_phi], pred);
                }
              }
            }
          }
        }
    }
    for (auto phi : header_phi) {
      for (size_t size = 0; size < phi->operands().size() / 2; size++) {
        auto value = phi->value(size);
        auto pred = dynamic_cast<IR::BasicBlock*>(phi->incoming(size));
        if (pred == loop->Pre_Header()) {
          phi->replaceAllUseWith(value);
          phi->unUseAll();

          for (auto& instr : phi->basicBlock()->instructions()) {
            if (auto phi = dynamic_cast<IR::PhiInst*>(instr.get())) {
              phi->basicBlock()->instructions().remove(instr);
              break;
            }
          }
          break;
        }
      }
    }

    auto tmp = std::find(exit->predecessors().begin(), exit->predecessors().end(), latch);
    if (tmp != exit->predecessors().end()) exit->predecessors().erase(tmp);

    for (auto [latch, header] : latchHeaderEdge) {
      latch->successors().push_back(header);
      header->predecessors().push_back(latch);
      int f = 1;
      int flag = 1;
      for (auto it = loop->parentFunc->basicBlocks().begin(); it != loop->parentFunc->basicBlocks().end(); it++) {
        auto bb = it->get();
        if (bb == latch) {
          flag = 0;
        }
        if (bb == header) {
          f = 0;
        }
      }

      if (flag == 1) loop->parentFunc->basicBlocks().emplace_back(latch);
      if (f == 1) loop->parentFunc->basicBlocks().emplace_back(header);
      auto jmp = new IR::JmpInst(latch, header);
      latch->instructions().emplace_back(jmp);
    }
    tmp = std::find(header->predecessors().begin(), header->predecessors().end(), latch);
    if (tmp != header->predecessors().end()) header->predecessors().erase(tmp);
  }
  void run(IR::Function* func) override {
    std::stack<IR::Cycle*> QueWorkList;
    for (auto loop : func->getTopLoops()) QueWorkList.push(loop);

    while (!QueWorkList.empty()) {
      auto loop = QueWorkList.top();
      QueWorkList.pop();
      runOnLoop(loop);
      // break;
      // for (auto subLoop : loop->subLoops) QueWorkList.push(subLoop);
    }
  }
};
}  // namespace Pass
#endif
