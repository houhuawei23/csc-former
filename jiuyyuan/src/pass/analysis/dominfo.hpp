#ifndef __ANALYSIS_DOMINFO__
#define __ANALYSIS_DOMINFO__

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "pass.hpp"

namespace Pass {

class DomInfo : public FunctionPass {
private:
  std::unordered_set<IR::BasicBlock*> _vis;
  std::vector<IR::BasicBlock*> _preorder;
  std::unordered_map<IR::BasicBlock*, size_t> _dfn;
  std::unordered_map<IR::BasicBlock*, IR::BasicBlock*> _dfa;
  std::unordered_map<IR::BasicBlock*, IR::BasicBlock*> _sdom;
  std::unordered_map<IR::BasicBlock*, IR::BasicBlock*> _idom;
  std::unordered_map<IR::BasicBlock*, std::unordered_set<IR::BasicBlock*>> _df;
  std::unordered_map<IR::BasicBlock*, std::unordered_set<IR::BasicBlock*>> _doms;

public:
  std::string_view name() override {
    return "DomInfo";
  }
  /* dfs from entry, and set dfn, return preorder */
  void calcDfn(IR::BasicBlock* cur, IR::BasicBlock* dfa = nullptr, size_t dfn = 1) {
    if (_vis.count(cur)) return;
    _vis.emplace(cur);
    _preorder.emplace_back(cur);
    _dfn[cur] = dfn;
    _dfa[cur] = dfa;
    for (IR::BasicBlock* successor : cur->successors()) {
      calcDfn(successor, cur, ++dfn);
    }
  }
  IR::BasicBlock* eval(IR::BasicBlock* bb) {
    IR::BasicBlock* ans = bb;
    if (_dfn[ans] < _dfn[_dfa[bb]]) ans = _dfa[bb];
    for (auto pred : bb->predecessors())
      if (_sdom[pred] != pred)
        if (_dfn[ans] < _dfn[pred]) ans = pred;
    return ans;
  }
  void calcSdom(IR::BasicBlock* entry) {
    for (auto bb : _preorder) _sdom[bb] = bb;
    for (auto it = _preorder.rbegin(); it != _preorder.rend(); it++)
      if (*it != entry)
        for (auto pred : (*it)->predecessors()) {
          IR::BasicBlock* u = eval(pred);
          if (_dfn[_sdom[u]] < _dfn[_sdom[*it]]) _sdom[*it] = _sdom[u];
        }
  }
  void calcIdom(IR::BasicBlock* entry) {
    for (auto bb : _preorder)
      if (bb != entry) {
        IR::BasicBlock* ans = _dfa[bb];
        while (ans && _dfn[ans] > _dfn[_sdom[bb]]) ans = _idom[ans];
        _idom[bb] = ans;
      }
  }
  void calcDoms() {
    for (auto bb : _preorder) _doms[_idom[bb]].emplace(bb);
  }
  void calcDf() {
    for (auto bb : _preorder) _df[bb].clear();
    for (auto bb : _preorder)
      if (bb->predecessors().size() >= 2)
        for (auto pred : bb->predecessors()) {
          IR::BasicBlock* runner = pred;
          while (runner != _idom[bb]) {
            _df[runner].insert(bb);
            runner = _idom[runner];
          }
        }
  }
  void run(IR::Function* pass_unit) override {
    _vis.clear();
    _preorder.clear();
    _dfn.clear();
    _dfa.clear();
    _sdom.clear();
    _idom.clear();
    _df.clear();
    calcDfn(pass_unit->allocas());
    calcSdom(pass_unit->allocas());
    calcIdom(pass_unit->allocas());
    calcDoms();
    calcDf();
  }
  const std::unordered_set<IR::BasicBlock*>& df(IR::BasicBlock* basic_block) {
    return _df[basic_block];
  }
  std::unordered_map<IR::BasicBlock*, std::unordered_set<IR::BasicBlock*>> doms();

};
}  // namespace Pass

#endif
