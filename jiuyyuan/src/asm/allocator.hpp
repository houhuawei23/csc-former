#ifndef __RISCV_ALLOCATOR_HPP__
#define __RISCV_ALLOCATOR_HPP__

#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

#include "core.hpp"
#include "riscvbuilder.hpp"
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
    function->calcLive();
    for (auto& block : function->blocks()) {
      double heuristic = block->heuristic();
      auto live(block->liveOut());
      for (auto it = block->insts().rbegin(); it != block->insts().rend(); it++) {
        Inst* inst = (*it).get();
        if (Target::ADDI* mv = dynamic_cast<Target::ADDI*>(inst)) {
          if (mv->imm() == 0) {
            for (Reg* reg : inst->useRegs())
              if (reg->isnode()) live.erase(reg);
            assert(mv->rd()->dtype() == mv->rs1()->dtype());
            if (mv->rd() != mv->rs1())
              if (mv->rd()->isnode() && mv->rs1()->isnode()) {
                move[mv->rd()][mv->rs1()]++;
                move[mv->rs1()][mv->rd()]++;
              }
          }
        }
        if (Target::FSGNJS* fmv = dynamic_cast<Target::FSGNJS*>(inst)) {
          if (fmv->rs1() == fmv->rs2()) {
            for (Reg* reg : inst->useRegs())
              if (reg->isnode()) live.erase(reg);
            assert(fmv->rd()->dtype() == fmv->rs1()->dtype());
            if (fmv->rd() != fmv->rs1())
              if (fmv->rd()->isnode() && fmv->rs1()->isnode()) {
                move[fmv->rd()][fmv->rs1()]++;
                move[fmv->rs1()][fmv->rd()]++;
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
      double heuristic = 0.0;
      const double eps = 1e-7;
      if (function->mana()->isConstant(reg)) {
        heuristic = static_cast<double>(conflict[reg].size()) / (load_heuristic[reg] * 1 + eps);
      } else if (function->mana()->isAlloca(reg)) {
        heuristic = static_cast<double>(conflict[reg].size()) / (load_heuristic[reg] * 1 + eps);
      } else if (function->mana()->isGlobal(reg)) {
        heuristic = static_cast<double>(conflict[reg].size()) / (load_heuristic[reg] * 2 + eps);
      } else if (function->mana()->isVariable(reg)) {
        heuristic =
            static_cast<double>(conflict[reg].size()) / (load_heuristic[reg] * 5 + store_heuristic[reg] * 5 + eps);
      } else {
        heuristic = 0;
      }
      if (!selected || heuristic > selected_heuristic) {
        selected = reg;
        selected_heuristic = heuristic;
      }
    }
    assert(selected);
    std::vector<Reg*> oths;
    for (Reg* oth : conflict[selected]) {
      oths.emplace_back(oth);
      conflict[oth].erase(selected);
    }
    select.emplace_back(selected, oths);
    conflict[selected].clear();
    uncolored.erase(selected);
    for (auto [oth, w] : move[selected]) move[oth].erase(selected);
    move[selected].clear();
    return selected;
  }

  void rewrite(const std::vector<Reg*>& spills) {
    RISCVBuilder builder;
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
            if (def) {
              it = block->insts().erase(it);
              it = std::prev(it);
              goto next_inst;
            }
            if (use) {
              builder.set(block.get(), it);
              Reg* rs = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              if (reg->isxreg()) {
                builder.newLoadImm(rs, *function->mana()->regConstant()[reg]->getField<int32_t>());
                (*it)->replace(reg, rs);
              } else if (reg->isfreg()) {
                Reg* rt = function->mana()->vreg(Reg::XREG, 8);
                builder.newLoadImm(rs, rt, *function->mana()->regConstant()[reg]->getField<float>());
                (*it)->replace(reg, rs);
              } else {
                assert(0);
              }
            }
          } else if (function->mana()->isAlloca(reg)) {
            if (def) {
              it = block->insts().erase(it);
              it = std::prev(it);
              goto next_inst;
            }
            if (use) {
              builder.set(block.get(), it);
              Reg* rs = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              block->insts().emplace(it, new Pseudo::LoadStackAddr(rs, function->stackInfo()[reg]));
              (*it)->replace(reg, rs);
            }
          } else if (function->mana()->isGlobal(reg)) {
            if (def) {
              it = block->insts().erase(it);
              it = std::prev(it);
              goto next_inst;
            }
            if (use) {
              builder.set(block.get(), it);
              Reg* rs = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              block->insts().emplace(it, new Pseudo::LA(rs, function->mana()->regGlobal()[reg]->name()));
              (*it)->replace(reg, rs);
            };
          } else {
            if (use) {
              builder.set(block.get(), it);
              Reg* rs = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              builder.newInst(new Pseudo::LoadStack(rs, spill_stack_info[reg]));
              (*it)->replace(reg, rs);
            }
            if (def) {
              builder.set(block.get(), std::next(it));
              Reg* rs = function->mana()->vreg(reg->dtype(), reg->sizeOf());
              builder.newInst(new Pseudo::StoreStack(rs, spill_stack_info[reg]));
              (*it)->replace(reg, rs);
            }
          }
        }
      next_inst:;
      }
    }
  }

  bool color(std::vector<Reg*>& spills) {
    bool ret = true;
    colorinfo.clear();
    for (Reg* reg : CALLEE_SAVE_REG) colorinfo[reg] = reg;
    for (Reg* reg : CALLER_SAVE_REG) colorinfo[reg] = reg;
    while (select.size()) {
      Reg* reg = select.back().first;
      assert(reg->isvreg());
      std::vector<Reg*> oths = select.back().second;
      select.pop_back();
      std::unordered_map<Reg*, double> heuristic;
      for (Reg* reg : CALLER_SAVE_REG) heuristic[reg] = 0.0;  // TODO
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
      if (!selected) {
        spills.emplace_back(reg);
        ret = false;
      }
      colorinfo[getLeader(reg)] = selected;
    }
    return ret;
  }

  std::unordered_set<Reg*> calleeSaveRegUsed() {
    std::unordered_set<Reg*> callee_save_reg;
    for (auto& block : function->blocks())
      for (auto& inst : block->insts())
        for (Reg* reg : inst->defRegs())
          if (Reg* p = colorinfo[getLeader(reg)]; p && p->calleeSave()) callee_save_reg.insert(p);
    return callee_save_reg;
  }

  void apply() {
    for (auto& block : function->blocks())
      for (auto& inst : block->insts()) {
        for (Reg* reg : inst->defRegs())
          if (reg->isvreg())
            if (Reg* p = colorinfo[getLeader(reg)]) inst->replace(reg, p);
        for (Reg* reg : inst->useRegs())
          if (reg->isvreg())
            if (Reg* p = colorinfo[getLeader(reg)]) inst->replace(reg, p);
      }
  }

  bool checkShortImm() {
    bool res = true;
    RISCVBuilder builder;
    for (auto& block : function->blocks())
      for (auto it = block->insts().begin(); it != block->insts().end();) {
        if (auto load_stack = dynamic_cast<Pseudo::LoadStack*>(it->get());
            load_stack && !validShortImm(load_stack->stackObject()->offset())) {
          builder.set(block.get(), it);
          Reg* rt = function->mana()->vreg(Reg::XREG, 8);
          builder.newInst(new Pseudo::LoadStackAddr(rt, load_stack->stackObject()));
          builder.newLoad(load_stack->rd(), rt, 0);
          it = block->insts().erase(it);
          res = false;
        } else if (auto store_stack = dynamic_cast<Pseudo::StoreStack*>(it->get());
                   store_stack && !validShortImm(store_stack->stackObject()->offset())) {
          builder.set(block.get(), it);
          Reg* rt = function->mana()->vreg(Reg::XREG, 8);
          builder.newInst(new Pseudo::LoadStackAddr(rt, store_stack->stackObject()));
          builder.newStore(rt, store_stack->rs2(), 0);
          it = block->insts().erase(it);
          res = false;
        } else {
          it++;
        }
      }
    return res;
  }

  void allocate() {
    while (true) {
      build();
      std::vector<Reg*> spills;
      while (uncolored.size()) {
        simplify();
        if (!uncolored.size()) break;
        if (coalesce()) continue;
        if (freeze()) continue;
        spill();
      }
      if (color(spills)) break;
      if (spills.size()) {
        rewrite(spills);
      }
    }
  }

};

};  // namespace RISCV

#endif
