#include "SimplifyCFG.hpp"

#include <cstddef>
#include <cstdio>
#include <unordered_set>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "irgenerator.hpp"
namespace Pass {
void SimplifyCFG::run(Function *pass_unit) {
  findBrToJmp(pass_unit);
  // 找到所有可达的基本块
  bool end = false;
  do {
    end = false;
    end |= findJmpToDel(pass_unit);
    eraseUnreachableBB(pass_unit);
    end |= mergeBB(pass_unit);
    // eraseUnreachableBB(pass_unit);
    end |= simplifyPhiInst(pass_unit);
  } while (end);
  // 删除不可达基本块
  // eraseUnreachableBB(pass_unit);
}
// 将条件已知的br指令替换为jmp指令
void SimplifyCFG::findBrToJmp(Function *pass_unit) {
  for (auto bb = pass_unit->basicBlocks().begin(); bb != pass_unit->basicBlocks().end(); ++bb) {
    auto _bb = bb->get();
    auto lastInst = _bb->instructions().back().get();
    if (auto brInst = dynamic_cast<BrInst *>(lastInst)) {
      if (auto cond = dynamic_cast<Constant *>(brInst->cond()); cond && cond->isBool()) {
        if (cond->getBoolVal() == true) {
          // 删除前驱后继
          auto falseBB = brInst->iffalse();
          auto it1 = std::find(_bb->successors().begin(), _bb->successors().end(), falseBB);
          if (it1 != _bb->successors().end()) {
            _bb->successors().erase(it1);
          }
          auto it2 = std::find(falseBB->predecessors().begin(), falseBB->predecessors().end(), _bb);
          if (it2 != falseBB->predecessors().end()) {
            falseBB->predecessors().erase(it2);
          }
          // 如果有phi指令，修改phi指令
          for (auto &inst : falseBB->instructions()) {
            if (auto phi = dynamic_cast<PhiInst *>(inst.get())) {
              phi->removeIncomingByBB(_bb);
            } else
              break;
          }
          // 将brInst替换为jmpInst
          auto jmpInst = new JmpInst(_bb, brInst->iftrue());
          brInst->removeAllUse();
          brInst->unUseAll();
          _bb->instructions().pop_back();
          _bb->instructions().emplace_back(jmpInst);
        } else if (cond->getBoolVal() == false) {
          // 删除前驱后继
          auto trueBB = brInst->iftrue();
          auto it1 = std::find(_bb->successors().begin(), _bb->successors().end(), trueBB);
          if (it1 != _bb->successors().end()) {
            _bb->successors().erase(it1);
          }
          auto it2 = std::find(trueBB->predecessors().begin(), trueBB->predecessors().end(), _bb);
          if (it2 != trueBB->predecessors().end()) {
            trueBB->predecessors().erase(it2);
          }
          // 如果有phi指令，修改phi指令
          for (auto &inst : trueBB->instructions()) {
            if (auto phi = dynamic_cast<PhiInst *>(inst.get())) {
              phi->removeIncomingByBB(_bb);
            } else
              break;
          }
          // 将brInst替换为jmpInst
          auto jmpInst = new JmpInst(_bb, brInst->iffalse());
          brInst->removeAllUse();
          brInst->unUseAll();
          _bb->instructions().pop_back();
          _bb->instructions().emplace_back(jmpInst);
        }
      }
    }
  }
}
// 将只有一条jmp指令的基本块删除
bool SimplifyCFG::findJmpToDel(Function *pass_unit) {
  bool flag = false;
  std::vector<BasicBlock *> reachableBB;
  std::unordered_set<BasicBlock *> vis;
  vis.clear();
  reachableBB.clear();
  BasicBlock::BasicBlockDfsPost(
      pass_unit->allocas(),
      [&vis](BasicBlock *bb) -> bool {
        if (vis.count(bb)) return true;
        vis.insert(bb);
        return false;
      },
      [&](BasicBlock *bb) -> void {
        reachableBB.emplace_back(bb);
      });
  // 遍历所有可达的基本块
  for (auto bb : reachableBB) {
    if (bb == bb->function()->allocas()) continue;
    if (bb->instructions().size() == 1) {
      auto lastInst = bb->instructions().back().get();
      if (auto jmpInst = dynamic_cast<JmpInst *>(lastInst)) {
        auto succ = jmpInst->dest();
        // 判断能不能删
        bool canDel = true;
        for (auto &inst : succ->instructions()) {
          if (inst.get()->itype() == IR::PHI) {
            std::set<BasicBlock *> succPred(succ->predecessors().begin(), succ->predecessors().end());
            std::set<BasicBlock *> pred(bb->predecessors().begin(), bb->predecessors().end());
            std::set<BasicBlock *> ans;
            std::set_intersection(pred.begin(), pred.end(), succPred.begin(), succPred.end(),
                                  std::inserter(ans, ans.begin()));
            if (!ans.empty()) {
              canDel = false;
              break;
            }
          } else {
            break;
          }
        }
        if (!canDel) continue;

        // 修改前驱、后继
        // 删除后继的前驱中bb
        for (auto predOfsucc = succ->predecessors().begin(); predOfsucc != succ->predecessors().end(); predOfsucc++) {
          if (*predOfsucc == bb) {
            succ->predecessors().erase(predOfsucc);
            break;
          }
        }
        for (auto pred : bb->predecessors()) {
          // 修改前驱的后继
          for (auto succOfpred = pred->successors().begin(); succOfpred != pred->successors().end(); succOfpred++) {
            if (*succOfpred == bb) {
              *succOfpred = succ;
              break;
            }
          }
          // 修改前驱br/jmp指令的操作数
          auto lastInstOfpred = pred->instructions().back().get();
          if (auto brInstOfpred = dynamic_cast<BrInst *>(lastInstOfpred)) {
            if (brInstOfpred->iftrue() == bb) {
              auto newBrInst = new BrInst(pred, brInstOfpred->cond(), succ, brInstOfpred->iffalse());
              brInstOfpred->removeAllUse();
              brInstOfpred->unUseAll();
              pred->instructions().pop_back();
              pred->instructions().emplace_back(newBrInst);
              flag = true;
            } else if (brInstOfpred->iffalse() == bb) {
              auto newBrInst = new BrInst(pred, brInstOfpred->cond(), brInstOfpred->iftrue(), succ);
              brInstOfpred->removeAllUse();
              brInstOfpred->unUseAll();
              pred->instructions().pop_back();
              pred->instructions().emplace_back(newBrInst);
              flag = true;
            }
          } else if (auto jmpInstOfpred = dynamic_cast<JmpInst *>(lastInstOfpred)) {
            if (jmpInstOfpred->dest() == bb) {
              auto newJmpInst = new JmpInst(pred, succ);
              jmpInstOfpred->removeAllUse();
              jmpInstOfpred->unUseAll();
              pred->instructions().pop_back();
              pred->instructions().emplace_back(newJmpInst);
              flag = true;
            }
          }
          // 修改后继的前驱
          succ->predecessors().emplace_back(pred);
          // 修改phi指令
          for (auto &inst : succ->instructions()) {
            if (inst.get()->itype() == IR::PHI) {
              auto phi = dynamic_cast<PhiInst *>(inst.get());
              Value *income = Constant::getUndefine();
              for (size_t index = 0; index < phi->operands().size() / 2; index++) {
                if (phi->incoming(index) == bb) {
                  income = phi->value(index);
                  break;
                }
              }
              phi->newIncoming(income, pred);
            } else
              break;
          }
        }
        for (auto &inst : succ->instructions()) {
          if (auto phi = dynamic_cast<PhiInst *>(inst.get())) {
            phi->removeIncomingByBB(bb);
          } else
            break;
        }
      }
    }
  }
  return flag;
}
bool SimplifyCFG::mergeBB(Function *pass_unit) {
  std::vector<BasicBlock *> reachableBB;
  std::unordered_set<BasicBlock *> vis;
  vis.clear();
  reachableBB.clear();

  BasicBlock::BasicBlockDfsPost(
      pass_unit->allocas(),
      [&vis](BasicBlock *bb) -> bool {
        if (vis.count(bb)) return true;
        vis.insert(bb);
        return false;
      },
      [&](BasicBlock *bb) -> void {
        reachableBB.emplace_back(bb);
      });

  bool flag = false;
  for (auto bb : reachableBB) {
    if (bb == pass_unit->allocas()) continue;
    if (bb->successors().size() == 1) {
      auto succ = bb->successors().back();
      if (succ->predecessors().size() == 1) {
        // 合并
        // bb的后继替换为succ的后继，succ的后继的前驱替换为bb
        for (auto succOfsucc : succ->successors()) {
          for (auto pred = succOfsucc->predecessors().begin(); pred != succOfsucc->predecessors().end(); pred++) {
            if (*pred == succ) {
              *pred = bb;
              break;
            }
          }
          bb->successors().emplace_front(succOfsucc);
          // 修改phiInst
          for (auto &inst : succOfsucc->instructions()) {
            if (inst.get()->itype() == IR::PHI) {
              auto phi = dynamic_cast<PhiInst *>(inst.get());
              Value *income = Constant::getUndefine();
              for (size_t index = 0; index < phi->operands().size() / 2; index++) {
                if (phi->incoming(index) == succ) {
                  income = phi->value(index);
                  break;
                }
              }
              phi->newIncoming(income, bb);
            } else
              break;
          }
          for (auto &inst : succOfsucc->instructions()) {
            if (auto phi = dynamic_cast<PhiInst *>(inst.get())) {
              phi->removeIncomingByBB(succ);
            } else
              break;
          }
        }
        // 将succ的指令提到bb中
        auto lastInstOfbb = bb->instructions().back().get();
        lastInstOfbb->removeAllUse();
        lastInstOfbb->unUseAll();
        bb->instructions().pop_back();
        for (auto &inst : succ->instructions()) {
          auto mem = inst.release();
          bb->instructions().emplace_back(mem);
        }
        if (succ->isExit()) {
          bb->setIsExit(true);
        }
        succ->instructions().clear();
        bb->successors().pop_back();
        succ->predecessors().pop_back();
        flag = true;
      }
    }
  }
  return flag;
}
bool SimplifyCFG::simplifyPhiInst(Function *pass_unit) {
  bool flag = false;
  for (auto &bb : pass_unit->basicBlocks()) {
    std::vector<PhiInst *> phiToRemove;
    // phi指令只有一对val-bb 这条phi指令可以去除
    for (auto &inst : bb->instructions()) {
      if (auto phi = dynamic_cast<PhiInst *>(inst.get())) {
        size_t num = 0;
        size_t index = 0;
        for (size_t i = 0; i < phi->operands().size() / 2; i++) {
          if (phi->value(i) != nullptr) {
            num++;
            index = i;
          }
        }
        if (num == 1) {
          // TODO
          phi->replaceAllUseWith(phi->value(index));
          // phi->removeAllUse();
          // phi->unUseAll();
          phiToRemove.emplace_back(phi);
          flag = true;
        }
      }
      // else break;
    }
    for (auto phi : phiToRemove) {
      for (auto it = bb->instructions().begin(); it != bb->instructions().end(); it++) {
        if (it->get() == phi) {
          phi->removeAllUse();
          // TODO
          phi->unUseAll();
          bb->instructions().erase(it);
          break;
        }
      }
    }
  }
  return flag;
}
void SimplifyCFG::eraseUnreachableBB(Function *pass_unit) {
  std::unordered_set<BasicBlock *> vis;
  BasicBlock::BasicBlockDfs(pass_unit->allocas(), [&](BasicBlock *bb) -> bool {
    if (vis.count(bb)) return true;
    vis.insert(bb);
    return false;
  });
  std::vector<BasicBlock *> deadBB;
  for (auto &bb : pass_unit->basicBlocks()) {
    if (!vis.count(bb.get())) {
      deadBB.emplace_back(bb.get());
    }
  }
  for (auto bb : deadBB) {
    // 删除从pred->bb的边
    for (auto pred : bb->predecessors()) {
      for (auto it = pred->successors().begin(); it != pred->successors().end(); it++) {
        if (*it == bb) {
          pred->successors().erase(it);
          break;
        }
      }
    }
    for (auto succ : bb->successors()) {
      for (auto it = succ->predecessors().begin(); it != succ->predecessors().end(); it++) {
        if (*it == bb) {
          succ->predecessors().erase(it);
          break;
        }
      }
      //如果有phi指令，修改phi指令
      for (auto &inst : succ->instructions()) {
        if (auto phi = dynamic_cast<PhiInst *>(inst.get())) {
          phi->removeIncomingByBB(bb);
        } else
          break;
      }
    }
    for (auto &inst : bb->instructions()) {
      inst->removeAllUse();
      inst->unUseAll();
    }
    bb->instructions().clear();
  }
  for (auto bb : deadBB) {
    for (auto it = pass_unit->basicBlocks().begin(); it != pass_unit->basicBlocks().end(); it++) {
      if (it->get() == bb) {
        // TODO
        for (auto use : bb->uses()) {
          if (auto phi = dynamic_cast<IR::PhiInst *>(use->user())) {
            phi->removeIncomingByBB(bb);
            break;
          }
        }
        bb->removeAllUse();
        pass_unit->basicBlocks().erase(it);
        break;
      }
    }
  }
  deadBB.clear();
}
}  // namespace Pass
