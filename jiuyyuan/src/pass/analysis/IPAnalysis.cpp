#include "IPAnalysis.hpp"
#include <unordered_set>
#include "AliasAnalysis.hpp"

using namespace IR;

namespace Pass {


void IPAnalysis::run(IR::CompileUnit* pass_unit) {
  for(auto &func : pass_unit->functionTable()){
    if(func->isDeclaration())continue;
    func->getCaller().clear();
    func->getCallee().clear();
    func->getCallSite().clear();
    func->getloadG().clear();
    func->getstoreG().clear();
  }

  std::unordered_set<IR::Function *>side_ef;



  for(auto &func : pass_unit->functionTable()){
    if(func->isDeclaration())continue;
    for(auto &bb : func->basicBlocks()){
      for(auto &inst : bb->instructions()){
        if(auto li = dynamic_cast<LoadInst *>(inst.get())){
          auto ptr = li->addr();
          if(auto addrdef = dynamic_cast<AddrDerefAddInst *>(ptr)){
            auto array =  getOriginArray(addrdef);
            if(auto ga = dynamic_cast<GlobalAddr *>(array)){
              func->getloadG().insert(ga);
            }
          }
        }else if(auto si = dynamic_cast<StoreInst *>(inst.get())){

          auto ptr = si->addr();
          if(auto addrdef = dynamic_cast<AddrDerefAddInst *>(ptr)){
            auto array = getOriginArray(addrdef);
            if(auto ga = dynamic_cast<GlobalAddr *>(array)){
              func->getstoreG().insert(ga);
            }else if(isArray(array)){
              side_ef.insert(func.get());
            }
          }
        }else if(auto ci = dynamic_cast<CallInst *>(inst.get())){
          auto callee = ci->callee();
          if(callee->isDeclaration()){
            side_ef.insert(func.get());
            continue;
          }
          func->getCallee().insert(callee);
          callee->getCaller().insert(func.get());
          callee->getCallSite().push_back(ci);
          if(func.get() == callee){
            func.get()->setredosilf();
          }
        }
      }
    }
  }

  bool changed;
  do
  {
    changed = true;
    for(auto &func : pass_unit->functionTable()){
      if(func->isDeclaration())continue;
      auto calleeset = std::set<Function *>(func->getCallee());
      for(auto callee : calleeset){
        auto pre_loadsize = func->getloadG().size();
        auto pre_storesize = func->getstoreG().size();

        std::set_union(func->getloadG().begin(),func->getloadG().end(),
            callee->getloadG().begin(),callee->getloadG().end(),
            std::inserter(func->getloadG(),func->getloadG().begin()));
        std::set_union(func->getstoreG().begin(),func->getstoreG().end(),
            callee->getstoreG().begin(),callee->getstoreG().end(),
            std::inserter(func->getstoreG(),func->getstoreG().begin()));

        auto now_loadsize = func->getloadG().size();
        auto now_storesize = func->getstoreG().size();
        if(pre_loadsize != now_loadsize || pre_storesize != now_storesize){
          changed = false;
        }
      }
    }
    /* code */
  } while (!changed);

  do
  {
    changed = true;
    for(auto &func : pass_unit->functionTable()){
      if(func->isDeclaration())continue;
      auto calleeSet = std::set<Function *>(func->getCallee());

      auto presize = side_ef.size();
      for(auto cale : calleeSet){
        if(side_ef.count(cale))side_ef.insert(func.get());
      }
      if(side_ef.size()!=presize)changed = false;
    }
  } while (!changed);

  for(auto &func : pass_unit->functionTable()){
    if(func->isDeclaration())continue;
    if(func->getstoreG().empty() && !side_ef.count(func.get()))func->nosideef();
  }
}

}  // namespace Pass
