#include "infrastructure.hpp"
#include "instruction.hpp"
#include <cstdint>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>
#include "functionInline.hpp"
#include "userelation.hpp"
using namespace IR;
Instruction *getCopyOfInstruction(Instruction *instr,
                                  std::function<Value *(Value *)> getValue) {
  if (auto binary = dynamic_cast<BinaryInst *>(instr)) {
    auto lhs = getValue(binary->lhs());
    auto rhs = getValue(binary->rhs());

    // auto name = "cpy." + binary->name();
    return new BinaryInst(nullptr, binary->itype(), binary->type(), "", lhs,
                          rhs);
  } else if (auto icmp = dynamic_cast<IcmpInst *>(instr)) {
    auto lhs = getValue(icmp->lhs());
    auto rhs = getValue(icmp->rhs());
    // auto name = "cpy." + icmp->name();
    return new IcmpInst(nullptr, icmp->itype(), "", lhs, rhs);
  } else if (auto fcmp = dynamic_cast<FcmpInst *>(instr)) {
    auto lhs = getValue(fcmp->lhs());
    auto rhs = getValue(fcmp->rhs());
    // auto name = "cpy." + fcmp->name();
    return new FcmpInst(nullptr, fcmp->itype(), "", lhs, rhs);
  } else if (auto load = dynamic_cast<LoadInst *>(instr)) {
    auto ptr = getValue(load->addr());
    // auto name = "cpy." + load->name();
    return new LoadInst(nullptr, "", ptr);
  } else if (auto store = dynamic_cast<StoreInst *>(instr)) {
    // auto ptr = getValue(store->operand(0));
    // auto value = getValue(store->value());
    auto value=getValue(store->value());
    auto addr=getValue(store->addr());

    return new StoreInst(nullptr, value, addr);
  } else if (auto call = dynamic_cast<CallInst *>(instr)) {
    auto callee = call->callee();
    std::vector<Value *> args;
    for (auto arg : call->arguments())
      args.push_back(getValue(arg->value()));

    // auto name = "copy." + call->name();
    return new CallInst(nullptr, "", callee, args);
  } else if (auto br = dynamic_cast<BrInst *>(instr)) {
    auto cond = getValue(br->cond());
    // auto t=getValue(br->iftrue());
    auto trueBB = dynamic_cast<BasicBlock *>(getValue(br->iftrue()));
    // trueBB = dynamic_cast<BasicBlock*>(t);
    auto falseBB = dynamic_cast<BasicBlock *>(getValue(br->iffalse()));
    return new BrInst(nullptr, cond, trueBB, falseBB);

  } else if (auto jmp = dynamic_cast<JmpInst *>(instr)) {
    auto trueBB = dynamic_cast<BasicBlock *>(getValue(jmp->dest()));

    return new JmpInst(nullptr, trueBB);
  } else if (auto phi = dynamic_cast<PhiInst *>(instr)) {
    // auto name = "copy." + phi->name();
    auto ptr = new PhiInst(nullptr, phi->type(), "");
    // for (size_t i = 0; i < phi->getsizes(); i++) {
    //   ptr->addIncoming(phi->getvals(i), dynamic_cast<BasicBlock
    //   *>(phi->getblos(i)));
    // }
    return ptr;
  } else if (auto alloca = dynamic_cast<AllocaInst *>(instr)) {
    // auto name = "copy." + alloca->name();

    return new AllocaInst(nullptr, "", alloca->type()->deref(1));
  } else if (auto unary = dynamic_cast<UnaryInst *>(instr)) {
    auto value = getValue(unary->operand(0));

    // auto name = "copy." + unary->name();

    return new UnaryInst(nullptr, unary->itype(), unary->type(), "", value);
  } else if (auto ret = dynamic_cast<RetInst *>(instr)) {
    return new RetInst(nullptr, getValue(ret->retValue()));
  } else if (auto addradd = dynamic_cast<AddrAddInst *>(instr)) {
    auto addr = getValue(addradd->addr());
    auto offset = getValue(addradd->offset());
    return new AddrAddInst(nullptr, "", addr, offset);
  } else if (auto addrDerefAdd = dynamic_cast<AddrDerefAddInst *>(instr)) {
    auto addr = getValue(addrDerefAdd->addr());
    auto offset = getValue(addrDerefAdd->offset());
    return new AddrDerefAddInst(nullptr, "", addr,
                                offset);
  } else {
    return nullptr;
  }
}
IR::Function *IR::Function::functionCopy() {
  std::unordered_map<Value *, Value *> ValueCopy;
  // copy global value ?
  for(auto &[name,value]:_compile_unit->globalVariableTable()->table()){
    auto val=value.get();
    // val->isGlobalVariable()
    if(val->isConstant() && val->addr()->type()->refSize()==1){
      ValueCopy[val->addr()]=val->initializer()[0]->value();
    }
    // if(val->addr()->type()->deref(1)->isArray()){

    // }
    else
      ValueCopy[val->addr()]=val->addr();
  }

  // copy function
  auto funcCopy = new Function(compileUnit(), false, type(), name() + ".copy");
  funcCopy->clearFunction();
  // copy arguments
  for (auto &arg : _arguments) {
    // auto argCopy = new Argument(
    //     arg->type(), "", arg->index());
    // funcCopy->arguments().emplace_back(argCopy);
    auto argCopy = funcCopy->newArgument(arg->type(), "");
    ValueCopy[arg.get()] = argCopy;
  }
  // copy basicblock
  for (auto &bb : _basic_blocks) {
    // auto bbCopy =
    //     new BasicBlock(funcCopy, "");
    // funcCopy->basicBlocks().emplace_back(bbCopy);
    auto bbCopy=funcCopy->newBasicBlock();
    if(funcCopy->allocas()==nullptr){
      funcCopy->setAllocas(bbCopy);
    }
    else if(funcCopy->entry()==nullptr){
      funcCopy->setEntry(bbCopy);
    }
    ValueCopy[bb.get()] = bbCopy;
  }
  // copy pred, succ of bb
  for (auto &bb : _basic_blocks) {
    auto bbCopy = dynamic_cast<BasicBlock *>(ValueCopy[bb.get()]);
    for (auto pred : bb->predecessors()) {
      bbCopy->predecessors().emplace_back(
          dynamic_cast<BasicBlock *>(ValueCopy[pred]));
    }
    for (auto succ : bb->successors()) {
      bbCopy->successors().emplace_back(
          dynamic_cast<BasicBlock *>(ValueCopy[succ]));
    }
  }
  // copy insts per bb
  std::vector<PhiInst *> phis;
  std::unordered_set<BasicBlock *> vis;
  BasicBlock::BasicBlockDfs(allocas(), [&](BasicBlock *bb) -> bool {
    if (vis.count(bb))
      return true;
    vis.insert(bb);
    auto bbCpy = dynamic_cast<BasicBlock *>(ValueCopy[bb]);
    for (auto &instr : bb->instructions()) {
      auto instrCpy =
          getCopyOfInstruction(instr.get(), [&](Value *val) -> Value * {
            // if (auto c = dynamic_cast<Constant *>(val);c&&c->isInt()){
            //   return Constant::get(static_cast<int32_t>(c->getIntVal()));
            // }else if(auto c = dynamic_cast<Constant *>(val);c&&c->isFloat()){
            //   return Constant::get(static_cast<float>(c->getFloatVal()));
            // }else if(auto c = dynamic_cast<Constant *>(val);c&&c->isBool()){
            //   return Constant::get(static_cast<bool>(c->getBoolVal()));
            // }
            if (auto c = dynamic_cast<Constant *>(val))return c;
              // return c;
            return ValueCopy[val];
          });
      instrCpy->resetBB(bbCpy);
      ValueCopy[instr.get()] = instrCpy;
      bbCpy->instructions().emplace_back(instrCpy);
      if (auto phi = dynamic_cast<PhiInst *>(instr.get()))
        phis.emplace_back(phi);
    }
    return false;
  });

  // deal with phiInst
  for (auto phi : phis) {
    auto getValue = [&](Value *val) -> Value * {
      // if (auto c = dynamic_cast<Constant *>(val);c&&c->isInt()){
      //   return Constant::get(static_cast<int32_t>(c->getIntVal()));
      // }else if(auto c = dynamic_cast<Constant *>(val);c&&c->isFloat()){
      //   return Constant::get(static_cast<float>(c->getFloatVal()));
      // }else if(auto c = dynamic_cast<Constant *>(val);c&&c->isBool()){
      //   return Constant::get(static_cast<bool>(c->getBoolVal()));
      // }
      if (auto c = dynamic_cast<Constant *>(val))return c;
      return ValueCopy[val];
    };

    auto phiCopy = dynamic_cast<PhiInst *>(ValueCopy[phi]);
    for (size_t i = 0; i < phi->operands().size() / 2; i++) {
      if(phi->value(i)){
        assert(phi->incoming(i));
        assert(ValueCopy[phi->incoming(i)]);
      phiCopy->newIncoming(
          getValue(phi->value(i)),
          static_cast<BasicBlock *>(ValueCopy[phi->incoming(i)]));
      }
    }
  }
  return funcCopy;
}
void Pass::functionInline::run(IR::CompileUnit *compileUnit){
  std::vector<Function*>functionToremove;
  functionToremove.clear();
  // 没有调用别的函数、不是库函数、main函数，可以内联
  for(auto &func:compileUnit->functionTable()){
    if(func->getCallee().empty()&&!func->isDeclaration()&&func->name()!="main"){
      functionToremove.emplace_back(func.get());
    }
  }
  while(!functionToremove.empty()){
    auto func=functionToremove.back();
    for(auto call:func->getCallSite()){
      if(auto callInst=dynamic_cast<CallInst*>(call)){
        inlineAtCall(callInst);
      }
    }
    for(auto caller:func->getCaller()){
      caller->getCallee().erase(func);
    }
    func->getCallSite().clear();
    func->getCaller().clear();
    for(auto it=compileUnit->functionTable().begin();it!=compileUnit->functionTable().end();it++){
      if(it->get()==func){
        for(auto &bb:func->basicBlocks()){
          for(auto &inst:bb->instructions()){
            inst->removeAllUse();
            inst->unUseAll();
          }
          bb->removeAllUse();
          bb->instructions().clear();
        }
        func->basicBlocks().clear();
        func->removeAllUse();
        compileUnit->functionTable().erase(it);
        break;
      }
    }
    functionToremove.pop_back();

    if(functionToremove.empty()){
      for(auto &func:compileUnit->functionTable()){
      if(func->getCallee().empty()&&!func->isDeclaration()&&func->name()!="main"){
        bool flag=true;
        for(auto it=functionToremove.begin();it!=functionToremove.end();it++){
          if(*it==func.get()){
            flag=false;
            break;
          }
        }
        if(flag)functionToremove.emplace_back(func.get());
      }
    }
    }
  }
}
void Pass::functionInline::inlineAtCall(IR::CallInst *call){
  auto callee=call->callee();
  auto nowBB=call->basicBlock();
  auto caller=nowBB->function();
  // std::cout<<"inline "<<callee->name()<<" in "<<nowBB->function()->name()<<std::endl;
  auto retBB=new BasicBlock(caller,"");
  if(nowBB->isExit()){
    nowBB->setIsExit(false);
    retBB->setIsExit(true);
  }
  caller->basicBlocks().emplace_back(retBB);

  // 将call指令后面的指令放入新的基本块 retBB
  nowBB->rankreorder();
  for(auto inst=nowBB->instructions().begin();inst!=nowBB->instructions().end();){
    if(nowBB->getRank(inst->get())>nowBB->getRank(call)){
      auto mem=inst->release();
      mem->resetBB(retBB);
      retBB->instructions().emplace_back(mem);
      inst=nowBB->instructions().erase(inst);
    }
    else{
      inst++;
    }
  }

  for(auto succ=nowBB->successors().begin();succ!=nowBB->successors().end();){
    // 修改前驱后继
    retBB->successors().emplace_back(*succ);
    auto itOfsucc=std::find((*succ)->predecessors().begin(),(*succ)->predecessors().end(),nowBB);
    if(itOfsucc!=(*succ)->predecessors().end()){
      (*succ)->predecessors().erase(itOfsucc);
    }
    (*succ)->predecessors().emplace_back(retBB);
    // 修改phiInst
    for(auto &inst:(*succ)->instructions()){
      if(auto phi=dynamic_cast<PhiInst*>(inst.get())){
        for(size_t i=0;i<phi->operands().size()/2;i++){
          if(phi->incoming(i)==nowBB){
            assert(retBB);
            phi->newIncoming(phi->value(i), retBB);
            phi->removeIncomingByBB(nowBB);
            break;
          }
        }
      }else break;
    }

    succ=nowBB->successors().erase(succ);
  }

  auto functionCopy=callee->functionCopy();

  std::unordered_set<BasicBlock*>visitedBB;
  std::vector<std::pair<RetInst*,BasicBlock*>>retInsts;

  // 函数返回的basicblock无条件跳转到call之后的指令所在的retBB
  for(auto &bb:functionCopy->basicBlocks()){
    bb->setFunction(caller);
    if(bb->successors().empty()){
      auto lastInstr=bb->instructions().back().get();
      if (auto ret = dynamic_cast<RetInst *>(lastInstr)) {
        retInsts.emplace_back(std::make_pair(ret, bb.get()));
      }
    }
  }
  // 如果函数返回值类型不是void, 如果有多个返回值，插入phi指令
  if((!callee->type()->retType()->isVoid())&&(!retInsts.empty())){
    if(retInsts.size()>1){
      auto phi=new PhiInst(retBB,call->type(),"");
      retBB->instructions().emplace_front(phi);
      call->replaceAllUseWith(phi);
      for(auto [ret,bb]:retInsts){
        assert(bb);
        phi->newIncoming(ret->retValue(), bb);
      }
    }
    else{
      call->replaceAllUseWith(retInsts[0].first->retValue());
    }
  }

  for(auto [ret,bb]:retInsts){
    bb->successors().emplace_back(retBB);
    retBB->predecessors().emplace_back(bb);
    ret->removeAllUse();
    ret->unUseAll();
    auto jmp=new JmpInst(bb,retBB);
    bb->instructions().pop_back();
    bb->instructions().emplace_back(jmp);
  }

  for(size_t i=0;i<functionCopy->arguments().size();i++){
    auto realArg=(call->arguments().begin()+i)->get();
    auto itOfArg=functionCopy->arguments().begin();
    if(i>0){
      std::advance(itOfArg,i);
    }
    auto formalArg=itOfArg->get();
    if(!formalArg->type()->isPointer()){
      formalArg->replaceAllUseWith(realArg->value());// TODO
    }
    else{
      // TODO
      std::vector<StoreInst*>storeToRemove;
      for(auto use:formalArg->uses()){
        if(auto store=dynamic_cast<StoreInst*>(use->user())){
          auto alloca=store->addr();
          std::vector<LoadInst*>loadToReplace;
          for(auto useOfAlloca:alloca->uses()){
            if(auto load=dynamic_cast<LoadInst*>(useOfAlloca->user())){
              loadToReplace.emplace_back(load);
            }
          }
          for(auto load:loadToReplace){
            load->replaceAllUseWith(realArg->value());
            // TODO
            load->unUseAll();
            for(auto it=load->basicBlock()->instructions().begin();it!=load->basicBlock()->instructions().end();it++){
              if(it->get()==load){
                load->basicBlock()->instructions().erase(it);
                break;
              }
            }

          }

          storeToRemove.emplace_back(store);
        }
      }
      for(auto store:storeToRemove){
        store->removeAllUse();
        store->unUseAll();
        for(auto it=store->basicBlock()->instructions().begin();it!=store->basicBlock()->instructions().end();it++){
          if(it->get()==store){
            store->basicBlock()->instructions().erase(it);
            break;
          }
        }
      }
    }
  }

  auto lastCallInst=nowBB->instructions().back().get();
  // TODO
  // lastCallInst->removeAllUse();
  lastCallInst->unUseAll();
  nowBB->instructions().pop_back();

  auto jmpInst=new JmpInst(nowBB,functionCopy->allocas());
  nowBB->instructions().emplace_back(jmpInst);
  nowBB->successors().emplace_back(functionCopy->allocas());
  functionCopy->allocas()->predecessors().emplace_back(nowBB);


  // 将functionCopy allocas中的allocaInst放入caller的allocas中
  for(auto inst=functionCopy->allocas()->instructions().begin();inst!=functionCopy->allocas()->instructions().end();){
    if(dynamic_cast<AllocaInst*>(inst->get())){
      auto instr=inst->release();
      instr->resetBB(caller->allocas());
      caller->allocas()->instructions().emplace_front(instr);
      inst=functionCopy->allocas()->instructions().erase(inst);
    }
    else{
      inst++;
    }
  }

  // 将functionCopy的基本块提到caller中
  for(auto bb=functionCopy->basicBlocks().begin();bb!=functionCopy->basicBlocks().end();){
    auto _bb=bb->release();
    _bb->setFunction(caller);
    caller->basicBlocks().emplace_back(_bb);
    bb=functionCopy->basicBlocks().erase(bb);
  }
  // caller->basicBlocks().splice(caller->basicBlocks().end(),functionCopy->basicBlocks());
}
