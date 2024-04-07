
#include "loop_parallel.hpp"

#include <unordered_map>
#include <unordered_set>

#include "global.hpp"
#include "simplifyInstruction.hpp"
#include "typesystem.hpp"
#include "userelation.hpp"
#include "analysis/AliasAnalysis.hpp"
using namespace IR;

namespace Pass{

  bool LoopParallel::Parallelizable(Cycle* loop){
    if(loop->ExitingBlocks.size() != 1 || loop->ExitBlocks.size() != 1 ){
      return false;
    }

    // if(loop->Latch() != *loop->ExitingBlocks.begin()){
    //   return false;
    // }

    auto index = loop->phi;
    if(!index || !loop->hasSCEV(index)){
      return false;
    }

    if(auto loopend = loop->end;!loopend || !loop->isLoopInvariant(loopend)){
      return false;
    }

    if(auto trip = loop->iterationCount;trip && trip < 400){
      return false;
    }

    if(auto c = dynamic_cast<Constant *>(loop->getSCEV(index).at(1));!c){
      return false;
    }

    for(auto bb : loop->nodes){
      for(auto &inst : bb->instructions()){
        if(auto call = dynamic_cast<CallInst *>(inst.get()); call && (!call->purecall() || call->callee()->isrecursive())){
          return false;
        }
      }
    }

    std::vector<Value*>arrays;
    std::unordered_map<Value*,AddrDerefAddInst*>ArrayIndex;
    std::unordered_map<Value*,std::multiset<AddrDerefAddInst*>>addrUseByStore;
    for(auto bb : loop->nodes){
      for(auto &inst : bb->instructions()){
        if(auto li = dynamic_cast<LoadInst*>(inst.get())){
          auto ptr = li->addr();
          if(auto ai = dynamic_cast<AllocaInst*>(ptr);ai &&
            !(ai->type()->deref(1)->isArray() && ai->type()->deref(1)->isPointer())){
            continue;;
          }
          if(auto gv = dynamic_cast<GlobalAddr *>(ptr);gv && !gv->type()->isArray()){
            continue;
          }
          auto array = getOriginArray(ptr);
          if(auto addri = dynamic_cast<AddrDerefAddInst*>(ptr)){
            if(ArrayIndex.count(array) && ArrayIndex[array]->addr() != addri->addr()){
              return false;
            }else{
              ArrayIndex[array] = addri;
            }
          }
          }
          else if(auto si = dynamic_cast<StoreInst*>(inst.get())){
            auto ptr = si->addr();
            auto val = si->value();
            if(!loop -> isLoopInvariant(val) && !isPureStore(si,loop) ){
              return false;
            }
            if(auto ai = dynamic_cast<AllocaInst*>(ptr); ai &&
              !(ai->type()->deref(1)->isArray() && ai->type()->deref(1)->isPointer())){
                continue;
              }
            if(auto gv = dynamic_cast<GlobalAddr*>(ptr);gv &&
            !gv->type()->isArray()){
              return false;
            }
            auto array = getOriginArray(ptr);
            if(auto addri = dynamic_cast<AddrDerefAddInst*>(ptr)){
              if(ArrayIndex.count(array) && ArrayIndex[array]->addr() != addri->addr()){
                return false;
              }
              else{
                ArrayIndex[array] = addri;
              }
              addrUseByStore[array].insert(addri);

            }
          }
        }
      }

    for(auto& [array , set] : addrUseByStore){
      if(set.size()>1)return false;
    }

    for(auto &instr : (*loop->ExitBlocks.begin())->instructions()){
      if(auto phi = dynamic_cast<PhiInst*>(instr.get()))return false;
      else break;
    }

    return true;

  }

  bool LoopParallel::isPureStore(StoreInst* store,Cycle* loop){
    if(store->value() == loop->phi)return true;
    else if(auto loadInst=dynamic_cast<LoadInst*>(store->value())){
      if(loadInst->addr()==store->addr())return true;
      // else if()
    }
    else if(auto binaryInst=dynamic_cast<BinaryInst*>(store->value())){
      return this->isPureBinary(binaryInst,store,loop);
    }
    return false;
  }
  bool LoopParallel::isPureBinary(BinaryInst* binary,StoreInst* store,Cycle* loop){
    auto klhs = binary->lhs();
    auto krhs = binary->rhs();
    if(auto blhs=dynamic_cast<BinaryInst*>(klhs)){
      if(isPureBinary(blhs,store,loop));
      else return false;
    }else if(!dynamic_cast<Constant *>(klhs) || klhs != loop->phi){
      if(auto li = dynamic_cast<LoadInst *>(klhs)){
        if(li->addr() == store->addr());
        else return false;
      }
    }

    if(auto brhs=dynamic_cast<BinaryInst*>(krhs)){
      if(isPureBinary(brhs,store,loop));
      else return false;
    }else if(!dynamic_cast<Constant *>(krhs) || krhs != loop->phi){
      if(auto li = dynamic_cast<LoadInst *>(krhs)){
        if(li->addr() == store->addr());
        else return false;
      }
    }

    return true;
  }
  void LoopParallel::runOnloop(Cycle* loop){
    if(!Parallelizable(loop)){
      return ;

    }

    auto &scev = loop ->getSCEV(loop->phi);

    auto preheader = loop->Pre_Header();

    auto start = scev.at(0);
    auto end = loop->end;
    // auto step = scev.at(1);

    auto __thread_create = loop->parentFunc->compileUnit()->getFuncByName("__thread_create");
    auto tid = new CallInst(preheader,"",__thread_create,{});
    preheader->insertBeforeTerminal(tid);

    auto subtmp = new BinaryInst(preheader,IType::SUB,Type::i32_t(),"",end,start);
    preheader->insertBeforeTerminal(subtmp);

    auto divtmp = new BinaryInst(preheader,IType::SDIV,Type::i32_t(),"",subtmp,Constant::get( 4));
    preheader->insertBeforeTerminal(divtmp);

    auto multmp = new BinaryInst(preheader,IType::MUL,Type::i32_t(),"",tid,divtmp);
    preheader->insertBeforeTerminal(multmp);

    auto localstart = new BinaryInst(preheader,IType::ADD,Type::i32_t(),"",start,multmp);
    preheader->insertBeforeTerminal(localstart);

    auto addtmp = new BinaryInst(preheader,IType::ADD,Type::i32_t(),"",tid,Constant::get(1));
    preheader->insertBeforeTerminal(addtmp);

    auto multmp1 = new BinaryInst(preheader,IType::MUL,Type::i32_t(),"",addtmp,divtmp);
    preheader->insertBeforeTerminal(multmp1);

    auto localend = new BinaryInst(preheader,IType::ADD,Type::i32_t(),"",start,multmp1);
    preheader->insertBeforeTerminal(localend);

    auto phi = loop->phi;
    for (size_t i = 0; i < (phi->operands().size()) / 2; i++) {
      if (phi->incoming(i)==preheader) {
        phi->removeIncomingByBB(preheader);
        phi->newIncoming(localstart,preheader);
        break;
      }
    }

    auto icmpins = loop->icmp;
    if(icmpins->operand(0) == end){
      icmpins->setOperand(0,localend);
    }
    else{
      icmpins->setOperand(1,localend);
    }
    auto exit = *loop->ExitBlocks.begin();

    auto __thread_join = loop->parentFunc->compileUnit()->getFuncByName("__thread_join");
    auto join = new CallInst(exit,"",__thread_join,{tid});
    exit->insertAfterPhi(join);
  }

  void LoopParallel::run(Function* func){
    if(func ->isDeclaration())return;
    for(auto loop : func->getTopLoops()){
      runOnloop(loop);
    }
  }
}
