
#include "RecursiveCache.hpp"

#include <unordered_map>
#include <unordered_set>

#include "functionInline.hpp"
#include "global.hpp"
#include "simplifyInstruction.hpp"
#include "typesystem.hpp"
#include "userelation.hpp"

using namespace IR;
namespace Pass {

void RecursiveCache::run(IR::CompileUnit *pass_unit) {
  std::unordered_map<Function *, std::vector<Variable *>> funcToList;

  for (auto &f : pass_unit->functionTable()) {
    if (!f->isDeclaration()) {
      // if(!f->sideEffect() && f->arguments().size() <=2 &&f->arguments().size()>0){
      if (!f->sideEffect() && f->arguments().size() == 2 && f->isrecursive() && !f->type()->retType()->isVoid() &&
          f->getCallee().size() == 1) {
        for (auto &argument : f->arguments()) {
          if (!(argument->type()->isI32() || argument->type()->isFloat())) goto next;
        }
        size_t call_cnt = 0;
        for (auto &basic_block : f->basicBlocks()) {
          for (auto &instruction : basic_block->instructions()) {
            if (auto call = dynamic_cast<IR::CallInst *>(instruction.get())) {
              if (call->callee()->name() == f->name()) {
                call_cnt++;
              }
            }
          }
        }
        if (call_cnt < 2) goto next;
        int i = 0;
        for (auto &argument : f->arguments()) {
          auto addr = new IR::GlobalAddr(IR::Type::pointer_t(Type::array_t(argument->type(), 1024)),
                                         f->name() + std::to_string(i));
          auto var = pass_unit->newVariable(false, f->name() + std::to_string(i++), addr);
          var->initializer().emplace_back(new IR::InitialValue(
              IR::InitialValue::ZERO, IR::Constant::get((int32_t)addr->type()->deref(1)->sizeOf())));
          funcToList[f.get()].emplace_back(var);
        }
        auto addr = new IR::GlobalAddr(IR::Type::pointer_t(Type::array_t(f->type()->retType(), 1024)),
                                       f->name() + std::to_string(i));
        auto var = pass_unit->newVariable(false, f->name() + std::to_string(i), addr);
        var->initializer().emplace_back(
            new IR::InitialValue(IR::InitialValue::ZERO, IR::Constant::get((int32_t)addr->type()->deref(1)->sizeOf())));
        funcToList[f.get()].emplace_back(var);
        // size
        auto addr1 = new IR::GlobalAddr(IR::Type::pointer_t(Type::i32_t()), f->name() + "Size");
        auto var1 = pass_unit->newVariable(false, f->name() + "Size", addr1);
        var1->initializer().emplace_back(new IR::InitialValue(IR::InitialValue::VALUE, IR::Constant::get((int32_t)0)));
        funcToList[f.get()].emplace_back(var1);
      }
    }
  next:;
  }

  for (auto &f : pass_unit->functionTable()) {
    if (f->isDeclaration()) continue;
    if (funcToList.count(f.get())) {
      auto bb0 = new BasicBlock(f.get(), "");
      auto bb1 = new BasicBlock(f.get(), "");
      auto bb2 = new BasicBlock(f.get(), "");
      auto bb3 = new BasicBlock(f.get(), "");
      auto bb4 = new BasicBlock(f.get(), "");
      auto bb5 = new BasicBlock(f.get(), "");
      f.get()->basicBlocks().emplace_back(bb0);
      f.get()->basicBlocks().emplace_back(bb1);
      f.get()->basicBlocks().emplace_back(bb2);
      f.get()->basicBlocks().emplace_back(bb3);
      f.get()->basicBlocks().emplace_back(bb4);

      // auto bb6 = new BasicBlock(f.get(),"");
      // auto bb7 = new BasicBlock(f.get(),"");
      // auto bb8 = new BasicBlock(f.get(),"");
      // auto bb9 = new BasicBlock(f.get(),"");

      auto allocai = new AllocaInst(f->allocas(), "", Type::i32_t());  // i
      f->allocas()->instructions().emplace_front(allocai);
      auto lastInstOfalloca = f->allocas()->instructions().back().get();
      // lastInstOfalloca->removeAllUse();
      auto destOfalloca = dynamic_cast<JmpInst *>(lastInstOfalloca)->dest();
      for (auto it = destOfalloca->predecessors().begin(); it != destOfalloca->predecessors().end(); it++) {
        if (*it == f->allocas()) {
          destOfalloca->predecessors().erase(it);
          break;
        }
      }
      lastInstOfalloca->unUseAll();
      f->allocas()->instructions().pop_back();
      f->allocas()->successors().clear();
      auto allocabr = new JmpInst(f->allocas(), bb0);
      f->allocas()->instructions().emplace_back(allocabr);
      f->allocas()->successors().emplace_back(bb0);
      bb0->predecessors().emplace_back(f->allocas());
      f.get()->setEntry(bb0);
      // bb0
      auto st0 = new StoreInst(bb0, Constant::get((int)0), allocai);
      bb0->instructions().emplace_back(st0);
      auto jmp0 = new JmpInst(bb0, bb1);
      bb0->instructions().emplace_back(jmp0);
      bb0->successors().emplace_back(bb1);
      bb1->predecessors().emplace_back(bb0);
      // bb1
      auto lo1 = new LoadInst(bb1, "", allocai);
      bb1->instructions().emplace_back(lo1);
      auto l011 = new LoadInst(bb1, "", funcToList[f.get()][3]->addr());  // size
      bb1->instructions().emplace_back(l011);
      auto icmp1 = new IcmpInst(bb1, ISLT, "", lo1, l011);  // i<size
      bb1->instructions().emplace_back(icmp1);
      auto br1 = new BrInst(bb1, icmp1, bb2, destOfalloca);
      bb1->instructions().emplace_back(br1);
      bb1->successors().emplace_back(bb2);
      bb1->successors().emplace_back(destOfalloca);
      bb2->predecessors().emplace_back(bb1);
      destOfalloca->predecessors().emplace_back(bb1);
      // bb2
      auto lo2 = new LoadInst(bb2, "", allocai);
      bb2->instructions().emplace_back(lo2);
      auto mul2 = new BinaryInst(bb2, MUL, Type::i32_t(), "", lo2, Constant::get(int(4)));
      bb2->instructions().emplace_back(mul2);
      auto addradd2 = new AddrDerefAddInst(bb2, "", funcToList[f.get()][0]->addr(), mul2);
      bb2->instructions().emplace_back(addradd2);
      auto lo22 = new LoadInst(bb2, "", addradd2);  // func0[i]
      bb2->instructions().emplace_back(lo22);
      auto arg2 = f.get()->arguments().begin();
      if ((*arg2).get()->type()->isFloat()) {
        auto fcmp2 = new FcmpInst(bb2, FOEQ, "", lo22, (*arg2).get());
        bb2->instructions().emplace_back(fcmp2);
      } else if ((*arg2).get()->type()->isI32()) {
        auto icmp2 = new IcmpInst(bb2, IEQ, "", lo22, (*arg2).get());
        bb2->instructions().emplace_back(icmp2);
      } else {
        assert(0);
      }
      auto br2 = new BrInst(bb2, bb2->instructions().back().get(), bb3, bb4);
      bb2->instructions().emplace_back(br2);
      bb2->successors().emplace_back(bb3);
      bb2->successors().emplace_back(bb4);
      bb3->predecessors().emplace_back(bb2);
      bb4->predecessors().emplace_back(bb2);
      // bb3
      auto lo3 = new LoadInst(bb3, "", allocai);
      bb3->instructions().emplace_back(lo3);
      auto mul3 = new BinaryInst(bb3, MUL, Type::i32_t(), "", lo3, Constant::get(int(4)));
      bb3->instructions().emplace_back(mul3);
      auto addradd3 = new AddrDerefAddInst(bb3, "", funcToList[f.get()][1]->addr(), mul3);
      bb3->instructions().emplace_back(addradd3);
      auto lo31 = new LoadInst(bb3, "", addradd3);  // func1[i]
      bb3->instructions().emplace_back(lo31);
      auto arg3 = f.get()->arguments().begin();
      std::advance(arg3, 1);
      if ((*arg3).get()->type()->isFloat()) {
        auto fcmp3 = new FcmpInst(bb3, FOEQ, "", lo31, (*arg3).get());
        bb3->instructions().emplace_back(fcmp3);
      } else if ((*arg3).get()->type()->isI32()) {
        auto icmp3 = new IcmpInst(bb3, IEQ, "", lo31, (*arg3).get());
        bb3->instructions().emplace_back(icmp3);
      } else {
        assert(0);
      }
      auto br3 = new BrInst(bb3, bb3->instructions().back().get(), bb5, bb4);
      bb3->instructions().emplace_back(br3);
      bb3->successors().emplace_back(bb4);
      bb3->successors().emplace_back(bb5);
      bb4->predecessors().emplace_back(bb3);
      bb5->predecessors().emplace_back(bb3);
      // bb4
      auto lo4 = new LoadInst(bb4, "", allocai);
      bb4->instructions().emplace_back(lo4);
      auto add4 = new BinaryInst(bb4, ADD, Type::i32_t(), "", lo4, Constant::get(int(1)));
      bb4->instructions().emplace_back(add4);
      auto st4 = new StoreInst(bb4, add4, allocai);
      bb4->instructions().emplace_back(st4);
      auto br4 = new JmpInst(bb4, bb1);
      bb4->instructions().emplace_back(br4);
      bb4->successors().emplace_back(bb1);
      bb1->predecessors().emplace_back(bb4);
      // bb5
      auto lo5 = new LoadInst(bb5, "", allocai);
      bb5->instructions().emplace_back(lo5);
      auto mul5 = new BinaryInst(bb5, MUL, Type::i32_t(), "", lo5, Constant::get(int(4)));
      bb5->instructions().emplace_back(mul5);
      auto addradd5 = new AddrDerefAddInst(bb5, "", funcToList[f.get()][2]->addr(), mul5);
      bb5->instructions().emplace_back(addradd5);
      auto lo51 = new LoadInst(bb5, "", addradd5);  // func0[i]
      bb5->instructions().emplace_back(lo51);
      auto ret5 = new RetInst(bb5, lo51);
      bb5->instructions().emplace_back(ret5);
      bb5->setIsExit(true);
      // bb6
      std::vector<BasicBlock *> retBBs;
      for (auto &bb : f->basicBlocks()) {
        auto lastInst = bb.get()->instructions().back().get();
        if (auto ret = dynamic_cast<RetInst *>(lastInst)) {
          if (dynamic_cast<Constant *>(ret->retValue())) {
            continue;
          }
          // else if(autodynamic_cast<UnaryInst*>(ret->retValue());)
          retBBs.emplace_back(bb.get());
        }
      }
      f.get()->basicBlocks().emplace_back(bb5);
      for (auto bb : retBBs) {
        auto bb6 = new BasicBlock(f.get(), "");
        auto bb7 = new BasicBlock(f.get(), "");
        f.get()->basicBlocks().emplace_back(bb6);
        f.get()->basicBlocks().emplace_back(bb7);

        auto it = (--bb->instructions().end());
        auto mem = it->release();
        bb->instructions().erase(it);
        auto jmpBB = new JmpInst(bb, bb6);
        bb->instructions().emplace_back(jmpBB);
        bb->successors().clear();
        bb->successors().emplace_back(bb6);
        bb6->predecessors().emplace_back(bb);
        bb->setIsExit(false);

        auto newRetBB = new BasicBlock(f.get(), "");
        mem->resetBB(newRetBB);
        auto newRet = dynamic_cast<RetInst *>(mem);
        newRetBB->instructions().emplace_back(newRet);
        f.get()->basicBlocks().emplace_back(newRetBB);
        newRetBB->setIsExit(true);

        auto icmp6 = new IcmpInst(bb6, ISLT, "", l011, Constant::get(int(1024)));
        bb6->instructions().emplace_back(icmp6);
        auto br6 = new BrInst(bb6, icmp6, bb7, newRetBB);
        bb6->instructions().emplace_back(br6);
        bb6->successors().emplace_back(bb7);
        bb6->successors().emplace_back(newRetBB);
        bb7->predecessors().emplace_back(bb6);
        newRetBB->predecessors().emplace_back(bb6);

        auto mul7 = new BinaryInst(bb7, MUL, Type::i32_t(), "", l011, Constant::get(int(4)));
        bb7->instructions().emplace_back(mul7);
        auto addr70 = new AddrDerefAddInst(bb7, "", funcToList[f.get()][0]->addr(), mul7);
        bb7->instructions().emplace_back(addr70);
        auto st70 = new StoreInst(bb7, (*arg2).get(), addr70);
        bb7->instructions().emplace_back(st70);
        auto addr71 = new AddrDerefAddInst(bb7, "", funcToList[f.get()][1]->addr(), mul7);
        bb7->instructions().emplace_back(addr71);
        auto st71 = new StoreInst(bb7, (*arg3).get(), addr71);
        bb7->instructions().emplace_back(st71);
        auto addr72 = new AddrDerefAddInst(bb7, "", funcToList[f.get()][2]->addr(), mul7);
        bb7->instructions().emplace_back(addr72);
        auto st72 = new StoreInst(bb7, newRet->retValue(), addr72);
        bb7->instructions().emplace_back(st72);
        auto add7 = new BinaryInst(bb7, ADD, Type::i32_t(), "", l011, Constant::get(int(1)));
        bb7->instructions().emplace_back(add7);
        auto st7 = new StoreInst(bb7, add7, funcToList[f.get()][3]->addr());
        bb7->instructions().emplace_back(st7);
        auto jmp7 = new JmpInst(bb7, newRetBB);
        bb7->instructions().emplace_back(jmp7);
        bb7->successors().emplace_back(newRetBB);
        newRetBB->predecessors().emplace_back(bb7);
      }
    }
  }

  // for(auto &f:pass_unit->functionTable()){
  //   if(f->isDeclaration())continue;
  //   std::vector<CallInst*>calltable;
  //   std::vector<std::pair<BasicBlock*,BasicBlock*>>nowToRet;
  //   calltable.clear();
  //   nowToRet.clear();
  //   // std::vector<BasicBlock*>bbs;
  //   bool flag=true;
  //   while(flag){
  //     flag=false;
  //     for(auto &bb : f->basicBlocks()){
  //       bool flag1=true;
  //       for(auto &in : bb->instructions()){
  //         if(auto calli = dynamic_cast<CallInst*>(in.get());calli && funcToList.count(calli->callee())){
  //           // calltable.emplace_back(calli);
  //           calli->basicBlock()->rankreorder();
  //           auto retBB=new BasicBlock(f.get(),"");
  //           for(auto it=calli->basicBlock()->instructions().begin();it!=calli->basicBlock()->instructions().end();){
  //             if(it->get() == calli){
  //               it++;
  //               while(it!=calli->basicBlock()->instructions().end()){
  //                 auto mem=it->release();
  //                 mem->resetBB(retBB);
  //                 retBB->instructions().emplace_back(mem);
  //                 it=calli->basicBlock()->instructions().erase(it);
  //               }
  //               break;
  //             }
  //             it++;
  //           }
  //           auto nowBB=calli->basicBlock();
  //           auto itOfcall=nowBB->instructions().end();
  //           itOfcall--;
  //           calltable.emplace_back(dynamic_cast<CallInst*>(itOfcall->release()));
  //           nowBB->instructions().erase(itOfcall);
  //           // 修改前驱后继
  //           for(auto succ=nowBB->successors().begin();succ!=nowBB->successors().end();){
  //             retBB->successors().emplace_back(*succ);
  //             auto itOfsucc=std::find((*succ)->predecessors().begin(),(*succ)->predecessors().end(),nowBB);
  //             if(itOfsucc!=(*succ)->predecessors().end()){
  //               (*succ)->predecessors().erase(itOfsucc);
  //             }
  //             (*succ)->predecessors().emplace_back(retBB);
  //             // 修改phiInst
  //             for(auto &inst:(*succ)->instructions()){
  //               if(auto phi=dynamic_cast<PhiInst*>(inst.get())){
  //                 for(size_t i=0;i<phi->operands().size()/2;i++){
  //                   if(phi->incoming(i)==nowBB){
  //                     assert(retBB);
  //                     phi->newIncoming(phi->value(i), retBB);
  //                     phi->removeIncomingByBB(nowBB);
  //                     break;
  //                   }
  //                 }
  //               }else break;
  //             }
  //             succ=nowBB->successors().erase(succ);
  //           }
  //           if(nowBB->isExit()){
  //             nowBB->setIsExit(false);
  //             retBB->setIsExit(true);
  //           }
  //           f.get()->basicBlocks().emplace_back(retBB);
  //           nowToRet.emplace_back(std::make_pair(nowBB,retBB));
  //           flag1=false;
  //           break;
  //         }
  //       }
  //       if(!flag1){
  //         flag=true;
  //         break;
  //       }
  //     }
  //   }
  //   for(size_t i=0;i<calltable.size();i++){
  //     auto call=calltable[i];
  //     auto fun=call->basicBlock()->function();
  //     auto callee=call->callee();
  //     if(funcToList.count(call->callee())){
  //       auto nowBB=nowToRet[i].first;
  //       auto retBB=nowToRet[i].second;
  //       {
  //         auto bb0=new BasicBlock(fun,"");
  //         auto bb1=new BasicBlock(fun,"");//while condition
  //         auto bb2 = new BasicBlock(fun,"");//while true
  //         auto bb3 = new BasicBlock(fun,"");//i=i+1
  //         auto bb4 = new BasicBlock(fun,"");
  //         auto bb5 = new BasicBlock(fun,"");
  //         auto bb6 = new BasicBlock(fun,"");
  //         auto bb7 = new BasicBlock(fun,"");
  //         auto bb8 = new BasicBlock(fun,"");
  //         auto bb9 = new BasicBlock(fun,"");
  //         // f.get()->basicBlocks().emplace_back(retBB);
  //         fun->basicBlocks().emplace_back(bb0);
  //         fun->basicBlocks().emplace_back(bb1);
  //         fun->basicBlocks().emplace_back(bb2);
  //         fun->basicBlocks().emplace_back(bb3);
  //         fun->basicBlocks().emplace_back(bb4);
  //         fun->basicBlocks().emplace_back(bb5);
  //         fun->basicBlocks().emplace_back(bb6);
  //         fun->basicBlocks().emplace_back(bb7);
  //         fun->basicBlocks().emplace_back(bb8);
  //         fun->basicBlocks().emplace_back(bb9);
  //         // init bb0
  //         // auto inst0=new  AddrDerefAddInst(bb0,"",funcToList[callee][3]->addr(),Constant::get((int)0));
  //         // bb0->instructions().emplace_back(inst0);
  //         auto size=new LoadInst(bb0,"",funcToList[callee][3]->addr());
  //         bb0->instructions().emplace_back(size);
  //         auto ialloca=new AllocaInst(fun->allocas(),"",Type::i32_t());
  //         fun->allocas()->instructions().emplace_front(ialloca);
  //         auto stI=new StoreInst(bb0,Constant::get((int)0),ialloca);
  //         bb0->instructions().emplace_back(stI);
  //         auto jmpInst=new JmpInst(bb0,bb1);
  //         bb0->instructions().emplace_back(jmpInst);
  //         bb0->successors().emplace_back(bb1);
  //         bb1->predecessors().emplace_back(bb0);
  //         // while cond bb1
  //         auto i1=new LoadInst(bb1,"",ialloca);
  //         bb1->instructions().emplace_back(i1);
  //         auto icmp1 = new IcmpInst(bb1,ISLT,"",i1,size);
  //         bb1->instructions().emplace_back(icmp1);
  //         auto br1 = new BrInst(bb1,icmp1,bb2,bb5);
  //         bb1->instructions().emplace_back(br1);
  //         bb1->successors().emplace_back(bb2);
  //         bb1->successors().emplace_back(bb5);
  //         bb2->predecessors().emplace_back(bb1);
  //         bb5->predecessors().emplace_back(bb1);
  //         // while true if bb2
  //         auto mul2 = new BinaryInst(bb2,MUL,Type::i32_t(),"",i1,Constant::get(int(4)));
  //         bb2->instructions().emplace_back(mul2);
  //         auto x2 = new  AddrDerefAddInst(bb2,"",funcToList[callee][0]->addr(),mul2);
  //         bb2->instructions().emplace_back(x2);
  //         auto lo2 = new LoadInst(bb2,"",x2);
  //         bb2->instructions().emplace_back(lo2);
  //         if(call->operand(1)->type()->isFloat()){
  //           auto fcmp2 = new FcmpInst(bb2,FOEQ,"",lo2,call->operand(1));
  //           bb2->instructions().emplace_back(fcmp2);
  //         }
  //         else if(call->operand(1)->type()->isI32()){
  //           auto icmp2 = new IcmpInst(bb2,IEQ,"",lo2,call->operand(1));
  //           bb2->instructions().emplace_back(icmp2);
  //         }
  //         else{
  //           assert(0);
  //         }
  //         auto br2 = new BrInst(bb2,bb2->instructions().back().get(),bb4,bb3);
  //         bb2->instructions().emplace_back(br2);
  //         bb2->successors().emplace_back(bb3);
  //         bb2->successors().emplace_back(bb4);
  //         bb4->predecessors().emplace_back(bb2);
  //         bb3->predecessors().emplace_back(bb2);
  //         // bb3
  //         auto i3 = new BinaryInst(bb3,ADD,Type::i32_t(),"",i1,Constant::get(int(1)));
  //         bb3->instructions().emplace_back(i3);
  //         auto store3 = new StoreInst(bb3,i3,ialloca);
  //         bb3->instructions().emplace_back(store3);
  //         auto jmp3=new JmpInst(bb3,bb6);
  //         bb3->instructions().emplace_back(jmp3);
  //         bb3->successors().emplace_back(bb6);
  //         bb6->predecessors().emplace_back(bb3);
  //         // bb4
  //         auto y4=new  AddrDerefAddInst(bb4,"",funcToList[callee][1]->addr(),mul2);
  //         bb4->instructions().emplace_back(y4);
  //         auto lo4 = new LoadInst(bb4,"",y4);
  //         bb4->instructions().emplace_back(lo4);
  //         if(call->operand(2)->type()->isFloat()){
  //           auto fcmp4 = new FcmpInst(bb4,FOEQ,"",lo4,call->operand(2));
  //           bb4->instructions().emplace_back(fcmp4);
  //         }
  //         else if(call->operand(2)->type()->isI32()){
  //           auto icmp4 = new IcmpInst(bb4,IEQ,"",lo4,call->operand(2));
  //           bb4->instructions().emplace_back(icmp4);
  //         }
  //         else{
  //           assert(0);
  //         }
  //         auto br4=new BrInst(bb4,bb4->instructions().back().get(),bb5,bb3);
  //         bb4->instructions().emplace_back(br4);
  //         bb4->successors().emplace_back(bb3);
  //         bb4->successors().emplace_back(bb5);
  //         bb3->predecessors().emplace_back(bb4);
  //         bb5->predecessors().emplace_back(bb4);
  //         // bb5
  //         auto lo5 = new LoadInst(bb5,"",ialloca);
  //         bb5->instructions().emplace_back(lo5);
  //         auto icmp5 = new IcmpInst(bb5,ISLT,"",lo5,size);
  //         bb5->instructions().emplace_back(icmp5);
  //         auto jmp5=new BrInst(bb5,icmp5,bb6,bb7);
  //         bb5->instructions().emplace_back(jmp5);
  //         bb5->successors().emplace_back(bb6);
  //         bb5->successors().emplace_back(bb7);
  //         bb6->predecessors().emplace_back(bb5);
  //         bb7->predecessors().emplace_back(bb5);
  //         // bb6
  //         auto mul6 = new BinaryInst(bb6,MUL,Type::i32_t(),"",lo5,Constant::get(int(4)));
  //         bb6->instructions().emplace_back(mul6);
  //         auto x6 = new  AddrDerefAddInst(bb6,"",funcToList[callee][2]->addr(),mul6);
  //         bb6->instructions().emplace_back(x6);
  //         auto lo6 = new LoadInst(bb6,"",x6);
  //         bb6->instructions().emplace_back(lo6);
  //         auto jmp6 = new JmpInst(bb6,retBB);
  //         bb6->instructions().emplace_back(jmp6);
  //         bb6->successors().emplace_back(retBB);
  //         retBB->predecessors().emplace_back(bb6);
  //         // call->replaceAllUseWith(lo6);
  //         // call->unUseAll();
  //         //bb 7
  //         auto call7 = new CallInst(bb7,"",call->callee(),{});
  //         std::vector<std::shared_ptr<IR::Use>>args;
  //         for(auto itOfArgs=call->arguments().begin();itOfArgs!=call->arguments().end();itOfArgs++){
  //           call7->newOperand(itOfArgs->get()->value());
  //         }
  //         bb7->instructions().emplace_back(call7);
  //         auto add7=new BinaryInst(bb7,ADD,Type::i32_t(),"",size,Constant::get((int)1));
  //         bb7->instructions().emplace_back(add7);
  //         auto icmp7 = new IcmpInst(bb7,ISLT,"",add7,Constant::get(int(1023)));
  //         bb7->instructions().emplace_back(icmp7);
  //         auto br7 = new BrInst(bb7,icmp7,bb8,bb9);
  //         bb7->instructions().emplace_back(br7);
  //         bb7->successors().emplace_back(bb8);
  //         bb7->successors().emplace_back(bb9);
  //         bb8->predecessors().emplace_back(bb7);
  //         bb9->predecessors().emplace_back(bb7);
  //         // bb8
  //         auto mul8=new BinaryInst(bb8,MUL,Type::i32_t(),"",add7,Constant::get((int)4));
  //         bb8->instructions().emplace_back(mul8);
  //         auto store8=new StoreInst(bb8,add7,funcToList[callee][3]->addr());
  //         bb8->instructions().emplace_back(store8);
  //         auto addrefadd8=new  AddrDerefAddInst(bb8,"",funcToList[callee][2]->addr(),mul8);
  //         bb8->instructions().emplace_back(addrefadd8);
  //         auto store8_=new StoreInst(bb8,call7,addrefadd8);
  //         bb8->instructions().emplace_back(store8_);
  //         auto addrefadd81=new  AddrDerefAddInst(bb8,"",funcToList[callee][1]->addr(),mul8);
  //         bb8->instructions().emplace_back(addrefadd81);
  //         auto store81_=new StoreInst(bb8,call->operand(2),addrefadd81);
  //         bb8->instructions().emplace_back(store81_);
  //         auto addrefadd82=new  AddrDerefAddInst(bb8,"",funcToList[callee][0]->addr(),mul8);
  //         bb8->instructions().emplace_back(addrefadd82);
  //         auto store82_=new StoreInst(bb8,call->operand(1),addrefadd82);
  //         bb8->instructions().emplace_back(store82_);
  //         auto jmp8=new JmpInst(bb8,bb9);
  //         bb8->instructions().emplace_back(jmp8);
  //         bb8->successors().emplace_back(bb9);
  //         bb9->predecessors().emplace_back(bb8);
  //         // bb9
  //         auto jmp9 = new JmpInst(bb9,retBB);
  //         bb9->instructions().emplace_back(jmp9);
  //         bb9->successors().emplace_back(retBB);
  //         retBB->predecessors().emplace_back(bb9);
  //         // nowBB retBB
  //         auto phi=new PhiInst(retBB,call->type(),"");
  //         phi->newIncoming(lo6,bb6);
  //         phi->newIncoming(call7,bb9);
  //         retBB->instructions().emplace_front(phi);
  //         call->replaceAllUseWith(phi);
  //         call->unUseAll();
  //         // nowBB->instructions().pop_back();// delete call
  //         auto jmpNow=new JmpInst(nowBB,bb0);
  //         nowBB->instructions().emplace_back(jmpNow);
  //         nowBB->successors().emplace_back(bb0);
  //         bb0->predecessors().emplace_back(nowBB);
  //       }
  //     }
  //   }
  // }
}

}  // namespace Pass
