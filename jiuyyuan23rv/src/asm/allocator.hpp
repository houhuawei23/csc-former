#ifndef __RISCV_ALLOCATOR_HPP__
#define __RISCV_ALLOCATOR_HPP__

#include <tuple>

#include "core.hpp"

#include <queue>
#include <algorithm>
#include "util.hpp"

namespace RISCV {

class Allocator {
public:
  const size_t ALLOCABLE_XREG_MAX = 32 - 5;
  const size_t ALLOCABLE_FREG_MAX = 32;
  Function* function;
  std::unordered_map<Reg*, Reg*> leader;
  std::unordered_set<Reg*> precolored;
  std::unordered_set<Reg*> uncolored;
  std::unordered_map<Reg*, std::unordered_set<Reg*>> conflict;
  std::unordered_map<Reg*, std::unordered_map<Reg*, size_t>> move;
  std::vector<std::pair<Reg*, std::vector<Reg*>>> select;
  std::unordered_map<Reg*, Reg*> colorinfo;
  std::unordered_map<Reg*, double> load_heuristic, store_heuristic;
  std::unordered_set<Reg*> spilled;
  Allocator(Function* function) : function(function) {
  }
  Reg* getLeader(Reg* reg) {
    return leader[reg] == reg ? reg : leader[reg] = getLeader(leader[reg]);
  }
  void build() {
    leader.clear();
    precolored.clear();
    uncolored.clear();
    conflict.clear();
    move.clear();
    select.clear();
    colorinfo.clear();
    load_heuristic.clear();
    store_heuristic.clear();
    spilled.clear();
    function->calcLive();
    for (auto& block : function->blocks()) {
      double heuristic = block->heuristic();
      auto live(block->liveOut());
      for (auto it = block->insts().rbegin(); it != block->insts().rend(); it++) {
        Inst* inst = (*it).get();
        if (Target::ADDI* addi = dynamic_cast<Target::ADDI*>(inst)) {
          if (addi->imm() == 0) {
            for (Reg* reg : inst->useRegs())
              if (reg->isnode()) live.erase(reg);
            assert(addi->rd()->dtype() == addi->rs1()->dtype());
            if (addi->rd() != addi->rs1())
              if (addi->rd()->isnode() && addi->rs1()->isnode()) {
                move[addi->rd()][addi->rs1()]++;
                move[addi->rs1()][addi->rd()]++;
              }
          }
        }
        if (Target::FSGNJS* fsgnjs = dynamic_cast<Target::FSGNJS*>(inst)) {
          if (fsgnjs->rs1() == fsgnjs->rs2()) {
            for (Reg* reg : inst->useRegs())
              if (reg->isnode()) live.erase(reg);
            assert(fsgnjs->rd()->dtype() == fsgnjs->rs1()->dtype());
            if (fsgnjs->rd() != fsgnjs->rs1())
              if (fsgnjs->rd()->isnode() && fsgnjs->rs1()->isnode()) {
                move[fsgnjs->rd()][fsgnjs->rs1()]++;
                move[fsgnjs->rs1()][fsgnjs->rd()]++;
              }
          }
        }
        for (Reg* reg : inst->defRegs())
          if (reg->isnode()) live.insert(reg);
        for (Reg* d : inst->defRegs())
          if (d->isnode())
            for (Reg* l : live)
              if (d != l && d->dtype() == l->dtype()) {
                assert(d->isnode() && l->isnode());
                conflict[d].insert(l);
                conflict[l].insert(d);
              }
        for (Reg* reg : inst->defRegs())
          if (reg->isnode()) live.erase(reg);
        for (Reg* reg : inst->useRegs())
          if (reg->isnode()) live.insert(reg);
        for (Reg* reg : inst->defRegs()) {
          if (reg->isvreg()) {
            uncolored.insert(reg);
            store_heuristic[reg] += heuristic;
          } else if (reg->allocable())
            precolored.insert(reg);
          else
            ;
        }
        for (Reg* reg : inst->useRegs()) {
          if (reg->isvreg()) {
            uncolored.insert(reg);
            load_heuristic[reg] += heuristic;
          } else if (reg->allocable())
            precolored.insert(reg);
          else
            ;
        }
      }
    }
    for (Reg* reg : uncolored)
      for (Reg* oth : conflict[reg]) {
        move[reg].erase(oth);
        move[oth].erase(reg);
      }
    for (Reg* reg : precolored) leader[reg] = reg;
    for (Reg* reg : uncolored) leader[reg] = reg;
  }
  void simplify() {
    std::queue<Reg*> que;
    for (Reg* reg : uncolored) {
      if (!move[reg].size() && reg->isxreg() && conflict[reg].size() < ALLOCABLE_XREG_MAX) que.push(reg);
      if (!move[reg].size() && reg->isfreg() && conflict[reg].size() < ALLOCABLE_FREG_MAX) que.push(reg);
    }
    while (que.size()) {
      std::vector<Reg*> oths;
      Reg* reg = que.front();
      que.pop();
      for (Reg* oth : conflict[reg]) {
        oths.emplace_back(oth);
        conflict[oth].erase(reg);
        if (oth->isvreg() && !move[oth].size() && oth->isxreg() && conflict[oth].size() == ALLOCABLE_XREG_MAX - 1)
          que.push(oth);
        if (oth->isvreg() && !move[oth].size() && oth->isfreg() && conflict[oth].size() == ALLOCABLE_FREG_MAX - 1)
          que.push(oth);
      }
      select.emplace_back(reg, oths);
      conflict[reg].clear();
      uncolored.erase(reg);
    }
  }
  bool briggs(Reg* reg0, Reg* reg1) {
    size_t cnt = 0;
    std::unordered_set<Reg*> oths;
    for (Reg* reg : conflict[reg0])
      if (reg != reg1) oths.insert(reg);
    for (Reg* reg : conflict[reg1])
      if (reg != reg0) oths.insert(reg);
    for (Reg* reg : oths) {
      size_t d = conflict[reg].size();
      if ((conflict[reg0].count(reg) && conflict[reg1].count(reg))) {
        if (reg->isxreg() && d > ALLOCABLE_XREG_MAX) {
          ++cnt;
        } else if (reg->isfreg() && d > ALLOCABLE_FREG_MAX) {
          ++cnt;
        }
      } else if ((!conflict[reg0].count(reg) || !conflict[reg1].count(reg))) {
        if (reg->isxreg() && d >= ALLOCABLE_XREG_MAX) {
          ++cnt;
        }
        if (reg->isfreg() && d >= ALLOCABLE_FREG_MAX) {
          ++cnt;
        }
      }
    }
    if (reg0->isxreg())
      return cnt < ALLOCABLE_XREG_MAX;
    else
      return cnt < ALLOCABLE_FREG_MAX;
  }
  bool coalesce() {
    std::vector<std::tuple<Reg*, Reg*, size_t>> pairs;
    for (Reg* reg : precolored)
      for (auto [oth, w] : move[reg])
        if (reg < oth) pairs.emplace_back(reg, oth, w);
    for (Reg* reg : uncolored)
      for (auto [oth, w] : move[reg])
        if (reg < oth) pairs.emplace_back(reg, oth, w);
    std::sort(pairs.begin(), pairs.end(),
              [](const std::tuple<Reg*, Reg*, size_t>& l, const std::tuple<Reg*, Reg*, size_t>& r) -> bool {
                return std::get<2>(l) > std::get<2>(r);
              });
    size_t ret = 0;
    for (auto& pair : pairs) {
      Reg* u = getLeader(std::get<0>(pair));
      Reg* v = getLeader(std::get<1>(pair));
      if (u == v) {
        ret += std::get<2>(pair);
        continue;
      }
      if (precolored.count(u) && precolored.count(v)) continue;
      if (!conflict[u].count(v) && briggs(u, v)) {
        if (precolored.count(v)) std::swap(u, v);
        leader[v] = u;
        uncolored.erase(v);
        for (Reg* reg : conflict[v]) {
          conflict[reg].erase(v);
          conflict[reg].insert(u);
          conflict[u].insert(reg);
        }
        conflict[v].clear();
        for (auto [reg, w] : move[v]) {
          move[reg].erase(v);
          if (reg != u) {
            move[reg][u] += w;
            move[u][reg] += w;
          }
        }
        move[v].clear();
        ret += std::get<2>(pair);
      }
    }
    return ret;
  }

  bool freeze() {
    Reg* reg = nullptr;
    for (Reg* oth : uncolored) {
      if (oth->isxreg() && conflict[oth].size() < ALLOCABLE_XREG_MAX) {
        if (!reg || conflict[reg].size() < conflict[oth].size()) reg = oth;
      }
      if (oth->isfreg() && conflict[oth].size() < ALLOCABLE_FREG_MAX) {
        if (!reg || conflict[reg].size() < conflict[oth].size()) reg = oth;
      }
    }
    if (!reg) return false;
    for (auto [oth, w] : move[reg]) move[oth].erase(reg);
    move[reg].clear();
    return true;
  }

  Reg* spill() {
    Reg* selected = nullptr;
    double selected_heuristic = 0.0;
    for (Reg* reg : uncolored) {
      if (!spilled.count(reg)) {
        double heuristic = 0.0;
        const double eps = 1e-7;
        if (function->mana()->isConstant(reg)) {
          heuristic = static_cast<double>(conflict[reg].size()) / (load_heuristic[reg] * 1 + eps);
        } else if (function->mana()->isAlloca(reg)) {
          heuristic = static_cast<double>(conflict[reg].size()) / (load_heuristic[reg] * 1 + eps);
        } else if (function->mana()->isGlobal(reg)) {
          heuristic = static_cast<double>(conflict[reg].size()) / (load_heuristic[reg] * 2 + eps);
        } else {
          heuristic =
              static_cast<double>(conflict[reg].size()) / (load_heuristic[reg] * 10 + store_heuristic[reg] * 10 + eps);
        }
        if (!selected || heuristic > selected_heuristic) {
          selected = reg;
          selected_heuristic = heuristic;
        }
      }
    }
    assert(selected);
    return selected;
  }

  void rewrite(const std::vector<Reg*>& spills) {
    std::unordered_map<Reg*, StackObject*> spill_stack_info;
    for (Reg* reg : spills) {
      if (function->mana()->isConstant(reg)) {
      } else if (function->mana()->isAlloca(reg)) {
      } else if (function->mana()->isGlobal(reg)) {
      } else {
        spill_stack_info[reg] = function->newCalleeStackObject(reg->sizeOf());
      }
    }
    for (auto& block : function->blocks()) {
      for (auto it = block->insts().begin(); it != block->insts().end(); it++) {
        for (Reg* reg : spills) {
          bool def = false;
          bool use = false;
          for (Reg* d : (*it)->defRegs())
            if (reg == d) def = true;
          for (Reg* u : (*it)->useRegs())
            if (reg == u) use = true;
          if (!use && !def) continue;
          if (function->mana()->isConstant(reg)) {
            if (use) {
              // TODO float
              Reg* t = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              if (function->mana()->regConstant()[reg]->type()->isFloat()) {
                Reg* tt = function->mana()->vreg(Reg::XREG, reg->sizeOf());
                block->insts().emplace(
                    it, new Pseudo::LI(tt, Util::floatToI32(*function->mana()->regConstant()[reg]->getField<float>())));
                block->insts().emplace(it, new Target::FMVWX(t, tt));
              } else {
                block->insts().emplace(it, new Pseudo::LI(t, *function->mana()->regConstant()[reg]->getField<int32_t>()));
              }
              (*it)->replace(reg, t);
              spilled.insert(t);
            }
            if (def) {
              it = block->insts().erase(it);
              it = std::prev(it);
            }
          } else if (function->mana()->isAlloca(reg)) {
            if (use) {
              Reg* t = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              block->insts().emplace(it, new Pseudo::LoadStackAddr(t, function->stackInfo()[reg]));
              (*it)->replace(reg, t);
              spilled.insert(t);
            }
            if (def) {
              it = block->insts().erase(it);
              it = std::prev(it);
            }
          } else if (function->mana()->isGlobal(reg)) {
            if (use) {
              Reg* t = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              block->insts().emplace(it, new Pseudo::LA(t, function->mana()->regGlobal()[reg]->name()));
              (*it)->replace(reg, t);
              spilled.insert(t);
            };
            if (def) {
              it = block->insts().erase(it);
              it = std::prev(it);
            }
          } else {
            if (use) {
              Reg* t = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              block->insts().emplace(it, new Pseudo::LoadStack(t, spill_stack_info[reg]));
              (*it)->replace(reg, t);
              spilled.insert(t);
            }
            if (def) {
              Reg* t = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              block->insts().emplace(std::next(it), new Pseudo::StoreStack(t, spill_stack_info[reg]));
              (*it)->replace(reg, t);
              spilled.insert(t);
            }
          }
        }
      }
    }
  }
  bool color() {
    colorinfo.clear();
    for (Reg* reg : CALLEE_SAVE_REG) colorinfo[reg] = reg;
    for (Reg* reg : CALLER_SAVE_REG) colorinfo[reg] = reg;
    while (select.size()) {
      Reg* reg = select.back().first;
      assert(reg->isvreg());
      std::vector<Reg*> oths = select.back().second;
      select.pop_back();
      std::unordered_map<Reg*, double> heuristic;
      for (Reg* reg : CALLER_SAVE_REG) heuristic[reg] = 0.0;
      for (Reg* reg : CALLEE_SAVE_REG) heuristic[reg] = 0.0;
      for (Reg* reg : CALLER_SAVE_REG) heuristic[reg] += 2.0;
      for (Reg* reg : CALLEE_SAVE_REG)
        if (precolored.count(reg)) heuristic[reg] += 1.0;
      heuristic[RA] -= 1.0;
      Reg* selected = nullptr;
      for (size_t i = 0; i < REG_NUM; i++) {
        Reg* p = &PHYSIC_REG[i];
        if (p->allocable() && p->dtype() == reg->dtype() &&
            !std::any_of(oths.begin(), oths.end(), [p, this](Reg* oth) -> bool {
              return p == this->colorinfo[getLeader(oth)];
            })) {
          if ((!selected) || (heuristic[p] > heuristic[selected])) {
            selected = p;
          }
        }
      }
      if (!selected) return false;
      colorinfo[getLeader(reg)] = selected;
    }
    return true;
  }
  std::unordered_set<Reg*> apply() {
    std::unordered_set<Reg*> callee_save_reg;
    for (auto& block : function->blocks())
      for (auto& inst : block->insts()) {
        for (Reg* reg : inst->defRegs()) {
          if (reg->isvreg()) {
            if (Reg* p = colorinfo[getLeader(reg)]) {
              if (p->calleeSave()) callee_save_reg.insert(p);
              inst->replace(reg, p);
            }
          } else if (reg->allocable()) {
            if (reg->calleeSave()) callee_save_reg.insert(reg);
          }
        }
        for (Reg* reg : inst->useRegs()) {
          if (reg->isvreg()) {
            if (Reg* p = colorinfo[getLeader(reg)]) {
              inst->replace(reg, p);
            }
          }
        }
      }
    return callee_save_reg;
  }
  void allocate() {
    while (true) {
    b:
      build();
      std::vector<Reg*> spills;
      while (uncolored.size()) {
        simplify();
        if (!uncolored.size()) break;
        if (coalesce()) continue;
        if (freeze()) continue;
        spills.emplace_back(spill());
        if (spills.size()) {
          rewrite(spills);
          goto b;
        }
      }
      if (color())
        break;
      else
        assert(0);
    }
  }
};
};  // namespace RISCV

#endif
