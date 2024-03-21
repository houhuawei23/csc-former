#include "sccp.hpp"
// #include "core.hpp"
// #include "inst.hpp"
// #include "typedef.hpp"
#include "typesystem.hpp"
#include "infrastructure.hpp"
#include "instruction.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <utility>

using namespace Pass;

void ConstPropagation::visitBB(BasicBlock *bb) {
  // if (bb->name() == "%exit")
  //   return;
  std::unordered_map<Value *, Constant *> predStatus;
  // 初始化predStatus=n[IN]
  if (bb != bb->function()->entry()) {
    for (auto &pre : bb->predecessors()) {
      if (pre == bb->predecessors().front()) {
        if (valueMap.count(pre)) {
          predStatus = valueMap.at(pre);
        }
      } else {
        if (valueMap.count(pre)) {
          std::unordered_map<Value *, Constant *> tempStatus =
              std::move(valueMap.at(pre));
          for (auto beg = predStatus.begin(); beg != predStatus.end();) {
            if (tempStatus.count((*beg).first)) {
              if ((*beg).second->isInt() &&
                  tempStatus.at((*beg).first)->isInt()) {
                if ((*beg).second->getIntVal() ==
                    tempStatus.at((*beg).first)->getIntVal()) {
                  beg++;
                } else {
                  // delete
                  beg = predStatus.erase(beg);
                }
              } else if ((*beg).second->isFloat() &&
                         tempStatus.at((*beg).first)->isFloat()) {
                if ((*beg).second->getFloatVal() ==
                    tempStatus.at((*beg).first)->getFloatVal()) {
                  continue;
                } else {
                  // delete
                  beg = predStatus.erase(beg);
                }
              } else {
                // delete
                beg = predStatus.erase(beg);
              }
            } else {
              // delete
              beg = predStatus.erase(beg);
            }
          }
        } else {
          predStatus.clear();
          break;
        }
      }
    }
  }
  else{
    // bb->function()->getParent()->globalVariableTable()
    // 136_rotate,138_light2d, 95_float 会卡住 莫名其妙
    // TODO 激进的方式
    // auto initFunction=bb->function()->getParent()->initFunction();
    // for (const auto &_bb : initFunction->basicBlocks()){
    //   for (auto &_inst : _bb->instructions()){
    //     auto gI=dynamic_cast<GlobalInst*>(_inst.get());
    //     if(gI&&gI->type()->deref(1)->in({Type::i32_t(), Type::float_t()})){
    //       auto op=dynamic_cast<Constant*>(gI->operand(0));
    //       if(op){
    //         if(op->isInt()){
    //           auto newConstant = new Constant(op->getIntVal());
    //           predStatus.insert(std::make_pair(gI, newConstant));
    //         }
    //         else if(op->isFloat()){
    //           auto newConstant = new Constant(op->getFloatVal());
    //           predStatus.insert(std::make_pair(gI, newConstant));
    //         }
    //       }
    //     }
    //   }
    // }
  }
  std::unordered_map<Value *, Constant *> *curStatus = &predStatus;
  bool flag = false;
  for (auto inst = bb->instructions().begin(); inst != bb->instructions().end();
       inst++) {
    bool temp = visitInst(inst->get(),
                          *curStatus); // 如果curStatus被改变了，return true
    if (temp)
      flag = true;
  }
  if (!curStatus->empty()) {
    valueMap.emplace(bb, std::move(*curStatus));
  }
  bool visited = false;
  for (auto st = visitedBB.begin(); st != visitedBB.end(); st++) {
    if (*st == bb) {
      visited = true;
      break;
    }
  }
  if (visited) {
    // 在循环内 curStatus 没改变
    if (!flag)
      return;
  } else {
    visitedBB.emplace_back(bb);
  }
  // 访问bb的后继
  for (auto it = bb->successors().begin(); it != bb->successors().end(); it++) {
    visitBB(*it);
  }
}

// 后期考虑对全局变量的折叠
bool ConstPropagation::visitInst(
    Instruction *inst, std::unordered_map<Value *, Constant *> &curStatus) {
  if (inst->itype()==BR && inst->operands().size() == 3) {
    if (curStatus.count(inst->operand(0))) {
      auto num = curStatus.at(inst->operand(0));
      if (num->isInt()) {
        if (num->getIntVal() != 0) {
          inst->setItype(JMP);
          inst->setOperand(0, inst->operand(1));
          auto falseBB = dynamic_cast<BasicBlock *>(inst->operand(2));
          // 删除前驱后继
          auto eraseIt = std::find(inst->basicBlock()->successors().begin(),
                                   inst->basicBlock()->successors().end(), falseBB);
          inst->basicBlock()->successors().erase(eraseIt);
          auto eraseJt = std::find(falseBB->predecessors().begin(),
                                   falseBB->predecessors().end(), inst->basicBlock());
          falseBB->predecessors().erase(eraseJt);
          // delBBList.emplace_back(falseBB);

          inst->operands().pop_back();
          inst->operands().pop_back();
          return true;
        } else {
          inst->setItype(JMP);
          inst->setOperand(0, inst->operand(2));
          auto trueBB = dynamic_cast<BasicBlock *>(inst->operand(1));
          auto eraseIt = std::find(inst->basicBlock()->successors().begin(),
                                   inst->basicBlock()->successors().end(), trueBB);
          inst->basicBlock()->successors().erase(eraseIt);
          auto eraseJt = std::find(trueBB->predecessors().begin(),
                                   trueBB->predecessors().end(), inst->basicBlock());
          trueBB->predecessors().erase(eraseJt);
          // delBBList.emplace_back(trueBB);
          inst->operands().pop_back();
          inst->operands().pop_back();
          return true;
        }
      }
    } else if (dynamic_cast<Constant *>(inst->operand(0))) {
      auto num = dynamic_cast<Constant *>(inst->operand(0));
      if (num->isInt()){
        if (num->getIntVal() != 0) {
          inst->setItype(JMP);
          inst->setOperand(0, inst->operand(1));
          auto falseBB = dynamic_cast<BasicBlock *>(inst->operand(2));
          auto eraseIt = std::find(inst->basicBlock()->successors().begin(),
                                   inst->basicBlock()->successors().end(), falseBB);
          inst->basicBlock()->successors().erase(eraseIt);
          auto eraseJt = std::find(falseBB->predecessors().begin(),
                                   falseBB->predecessors().end(), inst->basicBlock());
          falseBB->predecessors().erase(eraseJt);
          // delBBList.emplace_back(falseBB);
          inst->operands().pop_back();
          inst->operands().pop_back();
          return true;
        }
        else {
          inst->setItype(JMP);
          inst->setOperand(0, inst->operand(2));
          auto trueBB = dynamic_cast<BasicBlock *>(inst->operand(1));
          auto eraseIt = std::find(inst->basicBlock()->successors().begin(),
                                   inst->basicBlock()->successors().end(), trueBB);
          inst->basicBlock()->successors().erase(eraseIt);
          auto eraseJt = std::find(trueBB->predecessors().begin(),
                                   trueBB->predecessors().end(), inst->basicBlock());
          trueBB->predecessors().erase(eraseJt);
          // delBBList.emplace_back(trueBB);
          inst->operands().pop_back();
          inst->operands().pop_back();
          return true;
        }
      }
      // { if (auto l = num->getField<int32_t>()) {
      //   *l;
      // }

      }
    }

  else if (inst->isUnary()) {
    auto uInst = static_cast<UnaryInst *>(inst);
    //
    // if((!curStatus.count(uInst->operand(0)))&&(!dynamic_cast<Constant*>(uInst->operand(0))))
    //   return false;
    // Constant *num;
    // if(curStatus.count(uInst->operand(0))){
    //   num=curStatus.at(uInst->operand(0));
    // }
    // else if(dynamic_cast<Constant*>(uInst->operand(0))){
    //   num=dynamic_cast<Constant*>(uInst->operand(0));
    // }
    // TODO 135_math 会卡住
    if (!curStatus.count(uInst->operand(0)))
      return false;
    auto num = curStatus.at(uInst->operand(0));

    switch (uInst->itype()) {
    case ZEXT: {
      curStatus[uInst] = Constant::get(static_cast<int32_t>(num->getIntVal()));
      break;
    }
    case SITOFP: {
      curStatus[uInst] =Constant::get(static_cast<float>(num->getIntVal()));
      break;
    }
    case FPTOSI: {
      curStatus[uInst] = Constant::get(static_cast<int32_t>(num->getFloatVal()));
      break;
    }
    case FNEG: {
      curStatus[uInst] = Constant::get(-num->getFloatVal());
      break;
    }
    default:
      return false;
    }
    delInstList.emplace_back(uInst);
    return true;
  } else if (inst->isMath()) {
    auto bInst = dynamic_cast<BinaryInst *>(inst);
    auto allConst = false;
    if ((!curStatus.count(bInst->operand(0))) ||
        (!curStatus.count(bInst->operand(1)))) {
      if (curStatus.count(bInst->operand(0))) {
        auto num = curStatus.at(bInst->operand(0));
        bInst->setOperand(0, num);
        if (dynamic_cast<Constant *>(bInst->operand(1))) {
          allConst = true;
        }
        if (!allConst)
          return true;
      }
      if (curStatus.count(bInst->operand(1))) {
        auto num = curStatus.at(bInst->operand(1));
        bInst->setOperand(1, num);
        if (dynamic_cast<Constant *>(bInst->operand(0))) {
          allConst = true;
        }
        if (!allConst)
          return true;
      }
      if (!allConst)
        return false;
    }
    Constant *num1;
    Constant *num2;
    if (allConst) {
      num1 = dynamic_cast<Constant *>(bInst->operand(0));
      num2 = dynamic_cast<Constant *>(bInst->operand(1));
    } else {
      num1 = curStatus.at(bInst->operand(0));
      num2 = curStatus.at(bInst->operand(1));
    }
    switch (bInst->itype()) {
    case ADD: {
      curStatus[bInst] = Constant::get(num1->getIntVal() + num2->getIntVal());
      break;
    }
    case SUB: {
      curStatus[bInst] = Constant::get(num1->getIntVal() - num2->getIntVal());
      break;
    }
    case MUL: {
      curStatus[bInst] = Constant::get(num1->getIntVal() * num2->getIntVal());
      break;
    }
    case SDIV: {
      curStatus[bInst] = Constant::get(num1->getIntVal() / num2->getIntVal());
      break;
    }
    case SREM: {
      curStatus[bInst] = Constant::get(num1->getIntVal() % num2->getIntVal());
      break;
    }
    case FADD: {
      curStatus[bInst] =
          Constant::get(num1->getFloatVal() + num2->getFloatVal());
      break;
    }
    case FSUB: {
      curStatus[bInst] =
          Constant::get(num1->getFloatVal() - num2->getFloatVal());
      break;
    }
    case FMUL: {
      curStatus[bInst] =
          Constant::get(num1->getFloatVal() * num2->getFloatVal());
      break;
    }
    case FDIV: {
      curStatus[bInst] =
          Constant::get(num1->getFloatVal() / num2->getFloatVal());
      break;
    }
    default:
      return false;
    }
    delInstList.emplace_back(bInst);
    return true;
  } else if (inst->isCompare()) {
    if (dynamic_cast<IcmpInst *>(inst)) {
      auto icmpInst = dynamic_cast<IcmpInst *>(inst);
      bool allConst = false;
      if ((!curStatus.count(icmpInst->operand(0))) ||
          (!curStatus.count(icmpInst->operand(1)))) {
        if (curStatus.count(icmpInst->operand(0))) {
          auto num = curStatus.at(icmpInst->operand(0));
          icmpInst->setOperand(0, num);
          if (dynamic_cast<Constant *>(icmpInst->operand(1))) {
            allConst = true;
          }
          if (!allConst)
            return true;
        }
        if (curStatus.count(icmpInst->operand(1))) {
          auto num = curStatus.at(icmpInst->operand(1));
          icmpInst->setOperand(1, num);
          if (dynamic_cast<Constant *>(icmpInst->operand(0))) {
            allConst = true;
          }
          if (!allConst)
            return true;
        }
        if (dynamic_cast<Constant *>(icmpInst->operand(0)) &&
            dynamic_cast<Constant *>(icmpInst->operand(1))) {
          allConst = true;
        }
        if (!allConst)
          return false;
      }
      Constant *num1;
      Constant *num2;
      if (allConst) {
        num1 = dynamic_cast<Constant *>(icmpInst->operand(0));
        num2 = dynamic_cast<Constant *>(icmpInst->operand(1));
      } else {
        num1 = curStatus.at(icmpInst->operand(0));
        num2 = curStatus.at(icmpInst->operand(1));
      }
      switch (inst->itype()) {
      case IEQ: {
        curStatus[icmpInst] =
            Constant::get(num1->getIntVal() == num2->getIntVal());
        break;
      }
      case INE: {
        curStatus[icmpInst] =
            Constant::get(num1->getIntVal() != num2->getIntVal());
        break;
      }
      case ISGT: {
        curStatus[icmpInst] =
            Constant::get(num1->getIntVal() > num2->getIntVal());
        break;
      }
      case ISGE: {
        curStatus[icmpInst] =
            Constant::get(num1->getIntVal() >= num2->getIntVal());
        break;
      }
      case ISLT: {
        curStatus[icmpInst] =
            Constant::get(num1->getIntVal() < num2->getIntVal());
        break;
      }
      case ISLE: {
        curStatus[icmpInst] =
            Constant::get(num1->getIntVal() <= num2->getIntVal());
        break;
      }
      default:
        return false;
      }
      delInstList.emplace_back(icmpInst);
      return true;
    }
    if (dynamic_cast<FcmpInst *>(inst)) {
      auto fcmpInst = dynamic_cast<FcmpInst *>(inst);
      bool allConst = false;
      if ((!curStatus.count(fcmpInst->operand(0))) ||
          (!curStatus.count(fcmpInst->operand(1)))) {
        if (curStatus.count(fcmpInst->operand(0))) {
          auto num = curStatus.at(fcmpInst->operand(0));
          fcmpInst->setOperand(0, num);
          if (dynamic_cast<Constant *>(fcmpInst->operand(1))) {
            allConst = true;
          }
          if (!allConst)
            return true;
        }
        if (curStatus.count(fcmpInst->operand(1))) {
          auto num = curStatus.at(fcmpInst->operand(1));
          fcmpInst->setOperand(1, num);
          if (dynamic_cast<Constant *>(fcmpInst->operand(0))) {
            allConst = true;
          }
          if (!allConst)
            return true;
        }
        if (dynamic_cast<Constant *>(fcmpInst->operand(0)) &&
            dynamic_cast<Constant *>(fcmpInst->operand(1))) {
          allConst = true;
        }
        if (!allConst)
          return false;
      }
      Constant *num1;
      Constant *num2;
      if (allConst) {
        num1 = dynamic_cast<Constant *>(fcmpInst->operand(0));
        num2 = dynamic_cast<Constant *>(fcmpInst->operand(1));
      } else {
        num1 = curStatus.at(fcmpInst->operand(0));
        num2 = curStatus.at(fcmpInst->operand(1));
      }
      switch (inst->itype()) {
      case FOEQ: {
        curStatus[fcmpInst] =
            Constant::get(num1->getFloatVal() == num2->getFloatVal());
        break;
      }
      case FONE: {
        curStatus[fcmpInst] =
            Constant::get(num1->getFloatVal() != num2->getFloatVal());
        break;
      }
      case FOGT: {
        curStatus[fcmpInst] =
            Constant::get(num1->getFloatVal() > num2->getFloatVal());
        break;
      }
      case FOGE: {
        curStatus[fcmpInst] =
            Constant::get(num1->getFloatVal() >= num2->getFloatVal());
        break;
      }
      case FOLT: {
        curStatus[fcmpInst] =
            Constant::get(num1->getFloatVal() < num2->getFloatVal());
        break;
      }
      case FOLE: {
        curStatus[fcmpInst] =
           Constant::get(num1->getFloatVal() <= num2->getFloatVal());
        break;
      }
      default:
        return false;
      }
      delInstList.emplace_back(fcmpInst);
      return true;
    }
  } else if (inst->itype() == LOAD) {
    // 如果load的是一个constant 将使用它的use.value 变为该constant 并删除该指令
    if ((!curStatus.count(inst->operand(0)))) {
      // load 常量
      if (dynamic_cast<Constant *>(inst->operand(0))) {
        auto gV = dynamic_cast<Constant *>(inst->operand(0));
        if (gV->isInt()) {
          auto newConstant = Constant::get(gV->getIntVal());
          curStatus.insert(std::make_pair(inst, newConstant));
          delInstList.emplace_back(inst);
        } else if (gV->isFloat()) {
          auto newConstant = Constant::get(gV->getFloatVal());
          curStatus.insert(std::make_pair(inst, newConstant));
          delInstList.emplace_back(inst);
        }
        return true;
      }
      return false;
    }
    auto num = curStatus.at(inst->operand(0));
    if (num->isInt()) {
      auto newConstant = Constant::get(num->getIntVal());
      curStatus.insert(std::make_pair(inst, newConstant));
      delInstList.emplace_back(inst);
    } else if (num->isFloat()) {
      auto newConstant = Constant::get(num->getFloatVal());
      curStatus.insert(std::make_pair(inst, newConstant));
      delInstList.emplace_back(inst);
    }
    return true;
  } else if (inst->itype() == STORE) {
    // 向map中插入
    auto val = inst->operand(0);
    auto addr = inst->operand(1);
    for (auto param = inst->basicBlock()->function()->arguments().begin();
         param != inst->basicBlock()->function()->arguments().end(); param++) {
      // 凡是函数参数，都是未知量
      if (param->get() == val) {
        if (curStatus.count(addr)) {
          curStatus.erase(addr);
        }
        return false;
      }
    }
    if (dynamic_cast<CallInst *>(val)) {
      if (curStatus.count(addr)) {
        curStatus.erase(addr);
      }
      return false;
    }
    if (dynamic_cast<Constant *>(val)) {
      curStatus.insert(std::make_pair(addr, dynamic_cast<Constant *>(val)));
      return true;
    } else if (curStatus.count(val)) {
      auto num = curStatus.at(val);
      curStatus.insert(std::make_pair(addr, num));
      inst->setOperand(0, num);
      return true;
    }
    if (curStatus.count(addr)) {
      curStatus.erase(addr);
    }
    return false;
  } else if (inst->itype() == RET) {
    auto num = inst->operand(0);
    if (curStatus.count(num)) {
      auto retValue = curStatus.at(num);
      inst->setOperand(0, retValue);
      return true;
    }
  } else if (inst->itype() == CALL) {
    bool callFlag = false;
    for (size_t param = 0; param < inst->operands().size(); param++) {
      if (curStatus.count(inst->operand(param))) {
        inst->setOperand(param, curStatus.at(inst->operand(param)));
        callFlag = true;
      }
    }
    return callFlag;
  }
  // else if (inst->itype() == GETELEMENTPTR) {
  //   auto getInst = dynamic_cast<GetelementptrInst *>(inst);
  //   bool getFlag = false;
  //   for (size_t op = 1; op < getInst->operands().size(); op++) {
  //     if (curStatus.count(getInst->operand(op))) {
  //       getInst->setOperand(op, curStatus.at(getInst->operand(op)));
  //       getFlag = true;
  //     }
  //   }
  //   return getFlag;
  // }
  else if (inst->itype()==PHI) {
    // ??
    return false;
  }
  return false;
}
void ConstPropagation::delInst() {
  for (auto inst = delInstList.begin(); inst != delInstList.end(); inst++) {
    auto bb = (*inst)->basicBlock();
    for (auto it = bb->instructions().begin(); it != bb->instructions().end();
         it++) {
      if (it->get() == (*inst)) {
        bb->instructions().erase(it);
        break;
      }
    }
  }
}
// // 删除只有jmp的基本块
void ConstPropagation::delBB(Function *f) {
  std::list<BasicBlock *> toDelBB;
  for (auto &bb : f->basicBlocks()) {
    if (bb->instructions().size() == 1 &&
        bb->instructions().back()->itype() == JMP) {
      toDelBB.emplace_back(bb.get());
      auto succ_bb = bb->successors().back();
      // 将前驱的后继改为JMP的后继
      for (auto &pred_bb : bb->predecessors()) {
        for (auto succ_pre = pred_bb->successors().begin();
             succ_pre != pred_bb->successors().end(); succ_pre++) {
          if (bb.get() == (*succ_pre)) {
            // pred_bb->succs().insert(succ_pre,succ_bb);//
            *succ_pre = succ_bb;
            break;
          }
        }
        // 将前驱中的最后一条指令(BR||JMP)的操作数替换为JMP的后继
        if (dynamic_cast<BrInst *>(pred_bb->instructions().rbegin()->get())) {
          auto lastInst =
              dynamic_cast<BrInst *>(pred_bb->instructions().rbegin()->get());
          for (size_t i = 0; i < lastInst->operands().size(); i++) {
            if (lastInst->operand(i) == bb.get()) {
              lastInst->setOperand(i, succ_bb);
            }
          }
        } else if (dynamic_cast<JmpInst *>(
                       pred_bb->instructions().rbegin()->get())) {
          auto lastInst =
              dynamic_cast<JmpInst *>(pred_bb->instructions().rbegin()->get());
          lastInst->setOperand(0, succ_bb);
        }
      }
      // 将后继的前驱改为JMP的前驱
      std::list<BasicBlock *> other;
      while (succ_bb->predecessors().back() != bb.get()) {
        other.push_back(succ_bb->predecessors().back());
        succ_bb->predecessors().pop_back();
      }
      succ_bb->predecessors().pop_back();
      for (auto &pre : bb->predecessors()) {
        succ_bb->predecessors().push_back(pre);
      }
      while (!other.empty()) {
        succ_bb->predecessors().push_back(other.back());
        other.pop_back();
      }
    }
  }
  for (auto &bb : toDelBB) {
    for (auto it = f->basicBlocks().begin(); it != f->basicBlocks().end();
         it++) {
      if (bb == (*it).get()) {
        f->basicBlocks().erase(it);
        break;
      }
    }
  }
}
// 基本块融合
// a->b, b->c b中有指令
// void ConstPropagation::mergeBlocks(Function* f){
//   for(auto it=f->basicBlocks().begin();it!=f->basicBlocks().end();){
//     bool flag=false;
//     if(it->get()!=f->entry()&&it->get()!=f->exit()){
//       if(it->get()->predecessors().size()==1&&it->get()->predecessors().back()->succs().size()==1){
//         auto pred=it->get()->predecessors().back();
//         pred->instructions().pop_back();// 将jmp指令弹出
//         pred->succs().clear();
//         for(auto &inst:it->get()->instructions()){
//           pred->instructions().emplace_back(inst.get());
//         }
//         for(auto bb:it->get()->succs()){
//           pred->succs().emplace_back(bb);
//         }
//         it=f->basicBlocks().erase(it);
//         flag=true;
//       }
//     }
//     if(!flag)it++;
//   }
// }
