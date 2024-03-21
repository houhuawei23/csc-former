#ifndef __PASS_DOM_HPP__
#define __PASS_DOM_HPP__

#include "instruction.hpp"
#include "pass.hpp"

namespace Pass {
// class Dom : public Pass::FunctionPass {
// public:
//   std::string name() override {
//     return "dom";
//   }
// //   /* dfs from entry, and set dfn, return preorder */
// //   void calcDfn(IR::BasicBlock* entry, std::vector<IR::BasicBlock*>& preorder) {
// //     size_t dfn = 0;

// //     std::stack<IR::BasicBlock*>s;
// //     std::unordered_set<IR::BasicBlock*>visited;

// //     s.push(entry);
// //     visited.insert(entry);

// //     while(!s.empty()){
// //       IR::BasicBlock* cur = s.top();
// //       s.pop();
// //       cur->setDfn(dfn++);
// //       preorder.emplace_back(cur);

// //       for(auto succ : cur->succs()){
// //         if(visited.count(succ) == 0){
// //           s.push(succ);
// //           visited.insert(succ);
// //         }
// //       }
// //     }
// //   }

// //   void getfather(std::vector<IR::BasicBlock*>& preorder) {
// //      for (const auto& bb : preorder){
// //       IR::BasicBlock* idom = bb->idom();
// //       IR::BasicBlock* father = preorder.front();
// //       for(auto it = preorder.begin() ; it != preorder.end() ; it ++){
// //         IR::BasicBlock* u = *it;
// //         if(u->dfn() <= idom->dfn()){
// //           father = u;
// //           break;
// //         }
// //       }
// //       bb -> setFather(father);
// //      }
// //   }

// //   IR::BasicBlock* eval(IR::BasicBlock* bb) {
// //     IR::BasicBlock* ans = bb;
// //     if (ans->dfn() < bb->father()->dfn()) ans = bb->father();
// //     for (const auto& pred : bb->preds())
// //       if (pred->sdom() != pred)
// //         if (ans->dfn() < pred->dfn()) ans = pred;
// //     return ans;
// //   }
// //   //找到先序集合中最小的dfn基本块
// //   IR::BasicBlock* minpdf(std::vector<IR::BasicBlock*>& preorder){
// //     IR::BasicBlock* ans = preorder.front();
// //     for(auto &bb : preorder){
// //       if(ans->dfn() >= bb->dfn())ans=bb;
// //     }
// //     return ans;
// //   }
// //   void calcSdom(IR::BasicBlock* entry, std::vector<IR::BasicBlock*>& preorder) {
// //     for (auto& bb : preorder) bb->setSdom(bb);
// //     for (auto it = preorder.rbegin(); it != preorder.rend(); it++)
// //       if (*it != entry)
// //         for (const auto& bb : (*it)->preds()) {
// //           IR::BasicBlock* u = eval(bb);
// //           if (u->sdom()->dfn() < (*it)->sdom()->dfn()) (*it)->setSdom(u->sdom());
// //         }
// //   }
// //   void calcIdom(IR::BasicBlock* entry, std::vector<IR::BasicBlock*>& preorder) {
// //     for (const auto& bb : preorder)
// //       if (bb != entry) {
// //         IR::BasicBlock* ans = bb->father();
// //         while (ans && ans->dfn() > bb->sdom()->dfn()) ans = ans->idom();
// //         bb->setIdom(ans);
// //       }
// //   }
// // //查找迭代支配边界
// // //找到先序集合中dfn最小的基本块，
// //   std::vector<IR::BasicBlock*> calcDf(std::vector<IR::BasicBlock*>& preorder) {
// //     IR::BasicBlock* x = minpdf(preorder);
// //     std::vector<IR::BasicBlock*> ans;
// //     ans.push_back(x);
// //     while(true){
// //       bool changed = false;
// //       for(auto& bb : preorder){
// //         if(bb == x)continue;
// //         IR::BasicBlock* z = bb;
// //         while(z != z->idom()){
// //           z = z->idom();
// //           auto it = std::find(ans.begin(),ans.end(),z);
// //           if(it != ans.end())break;
// //           else{
// //             ans.push_back(z);
// //             changed = true;
// //           }
// //         }
// //       }
// //       if(!changed)break;
// //     }
// //     return ans;

// //   }

// //   std::vector<IR::BasicBlock*> findchild(IR::BasicBlock* bb,IR::Function* f){
// //     std::vector<IR::BasicBlock*>child;
// //     for(auto &ib : f->basicBlocks()){
// //       if(ib->idom()==bb){
// //         child.push_back(ib.get());
// //       }
// //     }
// //     return child;
// //   }

//   void run(IR::Function* pass_unit) override {
//     // std::vector<IR::BasicBlock*> preorder;
//     // calcDfn(pass_unit->entry(), preorder);
//     // calcSdom(pass_unit->entry(), preorder);
//     // calcIdom(pass_unit->entry(), preorder);

//   }
// };

class IdomGen : public FunctionPass {
private:
  void getDfnum(IR::Function* func);
  void compress(IR::BasicBlock* v);
  IR::BasicBlock* eval(IR::BasicBlock* v);
  void link(IR::BasicBlock* pre, IR::BasicBlock* now);

public:
  void run(IR::Function* func) override;
  std::string_view name() override;
};

class DomTreeGen : public FunctionPass {
private:
  void computeDomLevel(IR::BasicBlock* bb, int level);
  void computeAllDom(IR::BasicBlock* bb);

public:
  void run(IR::Function* func) override;
  std::string_view name() override {
    return "domTree";
  }
};

class DomFrontierGen : public FunctionPass {
private:
  void computeDF(IR::BasicBlock* bb);

public:
  void run(IR::Function* func) override;
  std::string_view name() override {
    return "domFrontier";
  }
};

}  // namespace Pass
#endif
