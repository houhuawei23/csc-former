#ifndef __OPTIMIZE_MEM2REG_HPP__
#define __OPTIMIZE_MEM2REG_HPP__

#include <queue>
#include <string>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"
#include <map>
#include <stack>
#include <set>

namespace Pass {

class Mem2Reg : public FunctionPass {
public:
  std::string_view name() override {
    return "mem2reg";
  }

  //判断指令是否可以被删除
  //中间少了一步判断指令是否为constant
  bool promotable(IR::AllocaInst *alloca) {
    for (const auto &use : alloca->uses()) {
      // auto f = alloca->basicBlock()->function();
      // if (istrueuse(use, f)) {
      if (auto store = dynamic_cast<IR::StoreInst *>(use->user())) {
        if (store->value() == alloca || store->value()->type() != alloca->type()->deref(1)) return false;
      } else if (auto load = dynamic_cast<IR::LoadInst *>(use->user())) {
        if (load->type() != alloca->type()->deref(1)) return false;
      } else {
        return false;
      }
      // }
    }
    return true;
  }

  //判断是否为有效use
  bool istrueuse(IR::Use *use, IR::Function *f) {
    for (auto &ib : f->basicBlocks()) {
      for (auto &ins : ib->instructions()) {
        if (use->user() == ins.get()) return true;
      }
    }
    return false;
  }
  //找出所有定义ai的基本块
  std::queue<IR::BasicBlock *> defs(IR::AllocaInst *ai) {
    std::queue<IR::BasicBlock *> ans;
    for (const auto &use : ai->uses()) {
      // auto f = ai->bb()->function();
      // if (istrueuse(use, f)) {
      if (auto si = dynamic_cast<IR::StoreInst *>(use->user())) ans.push(si->basicBlock());
      // }
    }
    return ans;
  }

  //在基本快中插入phi指令
  void insertPhi(IR::AllocaInst *AI, std::vector<IR::BasicBlock *> DenfBlocks,
                 std::map<IR::PhiInst *, IR::AllocaInst *> &AllocaToPhi) {
    for (auto *bb : DenfBlocks) {
      if (AI->basicBlock() == bb) break;
      for (auto ins = bb->instructions().begin(); ins != bb->instructions().end(); ins++) {
        auto &inst = *ins;
        if (dynamic_cast<IR::PhiInst *>(inst.get()) && inst->name() == AI->name())
          break;
        else {
          auto phiInst = new IR::PhiInst(bb, AI->type(), AI->name(), {}, {});
          // auto it = dynamic_cast<IR::PhiInst*>(phiInst);
          bb->instructions().emplace_front(phiInst);
          AllocaToPhi.emplace(std::make_pair(phiInst, AI));
          break;
        }
      }
    }
  }

  //即时修正use
  void checkuse(IR::Instruction *inst, IR::Function *f) {
    inst->uses().clear();
    for (auto &ib : f->basicBlocks()) {
      for (auto &ins : ib->instructions()) {
        for (auto op = ins.get()->operands().begin(); op != ins.get()->operands().end(); op++) {
          auto &opt = *op;
          if (inst == dynamic_cast<IR::Instruction *>(opt.value())) {
            inst->uses().push_back(&opt);
          }
        }
      }
    }
  }

  //重命名
  void rename(IR::BasicBlock *en, IR::Function *f, std::map<IR::AllocaInst *, std::stack<IR::Value *>> allocastack,
              std::map<IR::PhiInst *, IR::AllocaInst *> AllocaToPhi) {
    auto childnode = en->domTree;

    for (auto inst = en->instructions().begin(); inst != en->instructions().end(); inst++) {
      auto &ins = *inst;
      if (auto si = dynamic_cast<IR::StoreInst *>(ins.get())) {
        auto *AI = dynamic_cast<IR::AllocaInst *>(si->addr());
        if (!AI || !allocastack.count(AI)) {
          continue;
        }
        allocastack.find(AI)->second.push(si->operand(0));
      } else if (auto pi = dynamic_cast<IR::PhiInst *>(ins.get())) {
        auto I = AllocaToPhi.find(pi);
        if (I == AllocaToPhi.end()) {
          continue;
        }
        allocastack.find(I->second)->second.push(pi);
      } else if (auto li = dynamic_cast<IR::LoadInst *>(ins.get())) {
        IR::AllocaInst *AI = dynamic_cast<IR::AllocaInst *>(li->operand(0));
        if (!AI || !allocastack.count(AI)) {
          continue;
        }
        if (auto x = dynamic_cast<IR::Constant *>(allocastack.find(AI)->second.top())) {
          // checkuse(li, f);
          if (auto l = x->getField<int32_t>()) {
            // auto newConstant = new IR::Constant(x->getIntVal());
            li->replaceAllUseWith(IR::Constant::get((int32_t)*l));
          } else if (auto l = x->getField<float>()) {
            // auto newConstant = new IR::Constant(x->getFloatVal());
            li->replaceAllUseWith(IR::Constant::get((float)*l));
          }
        } else {
          // checkuse(li, f);
          li->replaceAllUseWith(allocastack.find(AI)->second.top());
        }
        // li->replace_all_use_with(allocastack.find(AI)->second.top());
        inst = en->instructions().erase(inst);
        inst--;
      }
    }

    for (auto *S : en->successors()) {
      for (auto inst = S->instructions().begin(); inst != S->instructions().end(); inst++) {
        auto &ins = *inst;
        if (auto phi = dynamic_cast<IR::PhiInst *>(ins.get())) {
          auto I = AllocaToPhi.find(phi);
          if (I != AllocaToPhi.end()) {
            phi->addIncoming(allocastack.find(I->second)->second.top(), en);
          } else
            break;
        } else
          break;
      }
    }

    for (auto *c : childnode) {
      rename(c, f, allocastack, AllocaToPhi);
    }

    for (auto inst = en->instructions().begin(); inst != en->instructions().end(); inst++) {
      auto &ins = *inst;
      if (auto si = dynamic_cast<IR::StoreInst *>(ins.get())) {
        IR::AllocaInst *AI = dynamic_cast<IR::AllocaInst *>(si->operand(1));
        if (!AI || !allocastack.count(AI)) {
          continue;
        }
        allocastack.find(AI)->second.pop();
        inst = en->instructions().erase(inst);
        inst--;
      } else if (auto pi = dynamic_cast<IR::PhiInst *>(ins.get())) {
        auto i = AllocaToPhi.find(pi);
        if (i == AllocaToPhi.end()) {
          continue;
        }
        allocastack.find(i->second)->second.pop();
      }
    }
  }

  //删除可以去除的指令

  void promote(IR::Function *f, std::vector<IR::AllocaInst *> Allocas) {
    std::map<IR::PhiInst *, IR::AllocaInst *> AllocaToPhi;

    for (auto *AI : Allocas) {
      std::queue<IR::BasicBlock *> DenfBlocks;
      std::vector<IR::BasicBlock *> insBlocks;
      std::set<IR::BasicBlock *> vis;
      DenfBlocks = defs(AI);  //记录所有的定义基本块
      while (!DenfBlocks.empty()) {
        auto bx = DenfBlocks.front();
        DenfBlocks.pop();
        insBlocks = bx->domFrontier;
        insertPhi(AI, insBlocks, AllocaToPhi);
      }  //在基本块开始插入了phi指令
    }
    std::map<IR::AllocaInst *, std::stack<IR::Value *>> allocastack;
    for (unsigned I = 0, E = Allocas.size(); I != E; I++) {
      allocastack[Allocas[I]].push(Allocas[I]);
    }
    rename(f->entry(), f, allocastack, AllocaToPhi);

    for (auto inst = Allocas.begin(); inst != Allocas.end(); inst++) {
      // auto ins = dynamic_cast<IR::Instruction* >(*inst);
      if (*inst && (*inst)->itype() == IR::IType::ALLOCA) {
        auto bb = (*inst)->basicBlock();
        bool flag = false;
        for (auto i = bb->instructions().begin(); i != bb->instructions().end(); i++) {
          if ((*inst) == (*i).get()) {
            bb->instructions().erase(i);
            flag = true;
            break;
          }
        }
        if (flag) continue;
        ;
      }
    }
    return;
  }

  void run(IR::Function *pass_unit) override {
    //存放alloca指令
    std::vector<IR::AllocaInst *> Allocas;
    while (true) {
      Allocas.clear();
      for (auto &inst : pass_unit->entry()->instructions()) {
        if (auto *ai = dynamic_cast<IR::AllocaInst *>(inst.get())) {
          if (ai->type()->deref(1)->in({IR::Type::i32_t(), IR::Type::float_t()})) {
            if (promotable(ai)) Allocas.push_back(ai);
          }
        }
      }
      if (Allocas.empty()) break;
      promote(pass_unit, Allocas);
    }
  }
};
}  // namespace Pass
#endif
