
#include "GVN.hpp"

#include <unordered_map>
#include <unordered_set>

#include "global.hpp"
#include "simplifyInstruction.hpp"
#include "typesystem.hpp"
#include "userelation.hpp"

using namespace IR;
namespace Pass {

static bool change;
static std::unordered_map<Value *, Value *> ValueNum;
static std::vector<Instruction *> InsToRemove;

BasicBlock *lcaCompute(BasicBlock *bb1, BasicBlock *bb2) {
  while (bb1->domLevel > bb2->domLevel) bb1 = bb1->idom;
  while (bb2->domLevel > bb1->domLevel) bb2 = bb2->idom;

  while (bb1 != bb2) {
    bb1 = bb1->idom;
    bb2 = bb2->idom;
  }
  return bb1;
}
void BasicBlockDfsPost(BasicBlock *bb, std::function<bool(BasicBlock *)> cond,
                       std::function<void(BasicBlock *)> action) {
  if (cond(bb)) return;
  for (auto succ : bb->successors()) BasicBlockDfsPost(succ, cond, action);
  action(bb);
}

void replace(Instruction *inst, Value *val) {
  if (inst == val) return;
  change = false;
  if (auto rootInstr = dynamic_cast<Instruction *>(val)) {
    auto rootBB = rootInstr->basicBlock();
    auto instrBB = inst->basicBlock();
    if (rootBB == instrBB &&
        instrBB->getRank(inst) < rootBB->getRank(rootInstr)) {  // inst ... ... rootInstr -> rootInstr ... ...
      auto diter = rootBB->instructions().begin();
      auto iter = instrBB->instructions().begin();
      while (diter != rootBB->instructions().end() && diter->get() != rootInstr) ++diter;
      while (iter != instrBB->instructions().end() && iter->get() != inst) ++iter;
      diter->release();
      iter->release();
      diter->reset(inst);
      iter->reset(rootInstr);
      rootInstr->setBasicBlock(instrBB);
      instrBB->setrank(rootInstr, instrBB->getRank(inst));
      inst->replaceAllUseWith(rootInstr);
      inst->unUseAll();
      InsToRemove.emplace_back(inst);
      // for (auto diter = rootBB->instructions().begin(); diter != rootBB->instructions().end(); diter++) {
      //   if (diter->get() == rootInstr) {
      //     diter->release();
      //     // diter = rootBB->instructions().erase(diter);
      //     rootInstr->setBasicBlock(instrBB);
      //     instrBB->setrank(rootInstr, instrBB->getRank(inst));
      //     break;
      //   }
      // }
      // for (auto iter = instrBB->instructions().begin(); iter != instrBB->instructions().end(); iter++) {
      //   if (iter->get() == inst) {
      //     iter->release();
      //     inst->replaceAllUseWith(rootInstr);
      //     inst->unUseAll();
      //     // iter = instrBB->instructions().erase(iter);
      //     InsToRemove.emplace_back(iter->get());
      //     iter->reset(rootInstr);
      //     // iter->reset(rootInstr);
      //     break;
      //   }
      // }
      ValueNum.erase(inst);
      return;
    } else if (auto phi = dynamic_cast<PhiInst *>(inst)) {
      ValueNum.erase(inst);
      inst->replaceAllUseWith(val);
      InsToRemove.push_back(inst);
      inst->unUseAll();
      return;
    } else if (rootBB != instrBB && !instrBB->dom.count(rootBB)) {
      if (rootBB->dom.count(instrBB)) {
        auto diter = rootBB->instructions().begin();
        auto iter = instrBB->instructions().begin();
        while (diter != rootBB->instructions().end() && diter->get() != rootInstr) ++diter;
        while (iter != instrBB->instructions().end() && iter->get() != inst) ++iter;
        diter->release();
        iter->release();
        diter->reset(inst);
        iter->reset(rootInstr);
        rootInstr->setBasicBlock(instrBB);
        instrBB->setrank(rootInstr, instrBB->getRank(inst));
        inst->replaceAllUseWith(rootInstr);
        inst->unUseAll();
        InsToRemove.emplace_back(inst);
        // for (auto diter = rootBB->instructions().begin(); diter != rootBB->instructions().end(); diter++) {
        //   if (diter->get() == rootInstr) {
        //     diter->release();
        //     diter = rootBB->instructions().erase(diter);
        //     break;
        //   }
        // }
        // for (auto iter = instrBB->instructions().begin(); iter != instrBB->instructions().end(); iter++) {
        //   if (iter->get() == inst) {
        //     instrBB->setrank(rootInstr, instrBB->getRank(inst));
        //     inst->replaceAllUseWith(rootInstr);
        //     inst->unUseAll();
        //     iter = instrBB->instructions().erase(iter);
        //     instrBB->instructions().emplace(iter, rootInstr);
        //     break;
        //   }
        // }
        // rootInstr->setBasicBlock(instrBB);
        ValueNum.erase(inst);
        return;
      }
      auto lca = lcaCompute(rootBB, instrBB);
      for (auto diter = rootBB->instructions().begin(); diter != rootBB->instructions().end(); diter++) {
        if (diter->get() == rootInstr) {
          diter->release();
          diter = rootBB->instructions().erase(diter);
          break;
        }
      }
      lca->insertBeforeTerminal(rootInstr);
    }
  }
  ValueNum.erase(inst);
  inst->replaceAllUseWith(val);
  InsToRemove.push_back(inst);
  inst->unUseAll();
}

Value *Gvnum::checkoutTable(Value *val) {
  if (auto number = ValueNum.find(val); number != ValueNum.end()) return number->second;
  if (auto cVal = dynamic_cast<Constant *>(val); cVal && cVal->isInt()) {
    for (auto [key, value] : ValueNum)
      if (auto cKey = dynamic_cast<Constant *>(key); cKey && cKey->isInt() && cKey->getIntVal() == cVal->getIntVal())
        return value;
  } else if (auto cVal = dynamic_cast<Constant *>(val); cVal && cVal->isFloat()) {
    for (auto [key, value] : ValueNum)
      if (auto cKey = dynamic_cast<Constant *>(key);
          cKey && cKey->isFloat() && cKey->getFloatVal() == cVal->getFloatVal())
        return value;
  }

  if (auto instr = dynamic_cast<Instruction *>(val))
    if (auto value = getValueNumber(instr)) {
      ValueNum[val] = value;
      return value;
    }
  ValueNum[val] = val;
  return val;
}

// Value *Gvnum::checkoutLocalTable(Value *val) {
//   if (auto number =) }

Value *Gvnum::getValueNumber(Instruction *instr) {
  if (auto binary = dynamic_cast<BinaryInst *>(instr))
    return getValueNumber(binary);
  else if (auto unary = dynamic_cast<UnaryInst *>(instr))
    return getValueNumber(unary);
  else if (auto phi = dynamic_cast<PhiInst *>(instr))
    return getValueNumber(phi);
  else if (auto call = dynamic_cast<CallInst *>(instr))
    return getValueNumber(call);
  else if(auto addr = dynamic_cast<AddrAddInst *>(instr))
    return getValueNumber(addr);
  else if(auto addrderef = dynamic_cast<AddrDerefAddInst*>(instr))
    return getValueNumber(addrderef);
  else if(auto alloca = dynamic_cast<AllocaInst *>(instr))
    return getValueNumber(alloca);
  else
    return nullptr;
}
Value *Gvnum::getValueNumber(BinaryInst *binary) {
  auto lhs = checkoutTable(binary->operand(0));
  auto rhs = checkoutTable(binary->operand(1));
  for (auto [key, value] : ValueNum) {
    if (auto binKey = dynamic_cast<BinaryInst *>(key)) {
      auto keyLhs = checkoutTable(binKey->operand(0));
      auto keyRhs = checkoutTable(binKey->operand(1));
      if (binary->itype() == binKey->itype() &&
          ((lhs == keyLhs && rhs == keyRhs) || (binary->isCommutative() && lhs == keyRhs && rhs == keyLhs)))
        return value;
      else if (Instruction::isReverse(binary, binKey) && keyLhs == rhs && keyRhs == lhs)
        return value;
    }
  }
  return binary;
}

Value *Gvnum::getValueNumber(AddrAddInst *addr){
  auto lhs = checkoutTable(addr->operand(0));
  auto rhs = checkoutTable(addr->operand(1));
  for (auto [key, value] : ValueNum) {
    if (auto addrKey = dynamic_cast<AddrAddInst *>(key)) {
      auto keyLhs = checkoutTable(addrKey->operand(0));
      auto keyRhs = checkoutTable(addrKey->operand(1));
      if (addr->itype() == addrKey->itype() &&
          (lhs == keyLhs && rhs == keyRhs))
        return value;
    }
  }
  return addr;
}

Value *Gvnum::getValueNumber(AddrDerefAddInst *addrderef){
  auto lhs = checkoutTable(addrderef->operand(0));
  auto rhs = checkoutTable(addrderef->operand(1));
  for (auto [key, value] : ValueNum) {
    if (auto addrderefKey = dynamic_cast<AddrDerefAddInst *>(key)) {
      auto keyLhs = checkoutTable(addrderefKey->operand(0));
      auto keyRhs = checkoutTable(addrderefKey->operand(1));
      if (addrderef->itype() == addrderefKey->itype() &&
          (lhs == keyLhs && rhs == keyRhs))
        return value;
    }
  }
  return addrderef;
}

Value *Gvnum::getValueNumber(UnaryInst *unary) {
  auto val = checkoutTable(unary->rhs());
  for (auto [key, value] : ValueNum) {
    if (auto unaryKey = dynamic_cast<UnaryInst *>(key)) {
      auto keyVal = checkoutTable(unaryKey->rhs());
      if (unary->itype() == unaryKey->itype() && val == keyVal) return value;
    }
  }
  return unary;
}
Value *Gvnum::getValueNumber(PhiInst *phi) {
  for (auto [key, value] : ValueNum) {
    if (auto keyPhi = dynamic_cast<PhiInst *>(key); keyPhi && keyPhi->basicBlock() == phi->basicBlock()) {
      bool same = phi->operands().size() == keyPhi->operands().size();
      if (same)
        for (size_t i = 0; i < (phi->operands().size()) / 2; i++) {
          auto income1 = phi->value(i);
          auto income2 = keyPhi->value(i);
          if (income1 != income2) {
            same = false;
            break;
          }
        }
      if (same) {
        return value;
      }
    }
  }
  return phi;
}
Value *Gvnum::getValueNumber(CallInst *cal) {
  return cal;
}
Value *Gvnum::getValueNumber(AllocaInst *alloca) {
  return alloca;
}

void Gvnum::visitInst(IR::Instruction *inst) {
  auto val = simplifyInstruction(inst);
  if (auto simpleInst = dynamic_cast<Instruction *>(val); !simpleInst) {
    replace(inst, val);
    return;
  } else {
    if (auto store = dynamic_cast<StoreInst *>(inst)) {
      if (!store->value()->type()->isPointer()) {
        ValueNum[store] = store;
        return;
      }
    } else if (auto phi = dynamic_cast<PhiInst *>(inst)) {
      bool same = true;
      auto first = checkoutTable(phi->value(0));
      for (size_t i = 0; i < (phi->operands().size()) / 2; i++) {
        if (checkoutTable(phi->value(i)) != first) {
          same = false;
          break;
        }
      }
      if (same) {
        replace(inst, first);
        return;
      }
      return;
    }
    bool useByBranch = false;
    for (auto use : inst->uses()) {
      auto user = use->user();
      if (auto br = dynamic_cast<BrInst *>(user)) {
        useByBranch = true;
        break;
      }
    }
    if (useByBranch) return;
    auto value = checkoutTable(simpleInst);
    if (inst != value) {
      replace(inst, value);
      return;
    }
  }
}
// void Gvnum::visitload(IR::Instruction *inst) {
//   if (auto li = dynamic_cast<IR::LoadInst *>(inst)) {
//     auto first = checkoutTable(li);
//   }
// }
void Gvnum::run(IR::Function *pass_unit) {
  std::vector<BasicBlock *> workList;
  std::unordered_set<BasicBlock *> visitedBB;

  BasicBlockDfsPost(
      pass_unit->allocas(),
      [&](BasicBlock *bb) -> bool {
        if (visitedBB.count(bb)) return true;
        bb->rankreorder();
        visitedBB.insert(bb);
        return false;
      },
      [&](BasicBlock *bb) -> void {
        workList.push_back(bb);
      });

   for (auto bb = workList.rbegin(); bb != workList.rend(); bb++) {
    std::unordered_map<Value *, Value *> LoaclValueNum;
    InsToRemove.clear();
    for (auto &instr : (*bb)->instructions()) {
      if (auto load = dynamic_cast<IR::LoadInst *>(instr.get())) {
        if (LoaclValueNum.find(load->addr()) != LoaclValueNum.end()) {
          load->replaceAllUseWith(LoaclValueNum[load->addr()]);
          load->unUseAll();
          InsToRemove.emplace_back(load);
        } else {
          LoaclValueNum[load->addr()] = load;
        }
      } else if (auto store = dynamic_cast<IR::StoreInst *>(instr.get())) {
        LoaclValueNum.erase(store->addr());
      } else if (auto call = dynamic_cast<IR::CallInst *>(instr.get())) {
        LoaclValueNum.clear();
      }
    }
    for (auto inst = (*bb)->instructions().begin(); inst != (*bb)->instructions().end(); inst++) {
      if (count(InsToRemove.begin(), InsToRemove.end(), inst->get())) {
        (*inst)->removeAllUse();
        (*inst)->unUseAll();
        inst = (*bb)->instructions().erase(inst);
        inst--;
      }
    }
  }

  ValueNum.clear();
  do {
    change = true;
    for (auto bb = workList.rbegin(); bb != workList.rend(); bb++) {
      InsToRemove.clear();

      for (auto &instr : (*bb)->instructions()) {
        visitInst(instr.get());
      }
      for (auto inst = (*bb)->instructions().begin(); inst != (*bb)->instructions().end(); inst++) {
        if (count(InsToRemove.begin(), InsToRemove.end(), inst->get())) {
          (*inst)->removeAllUse();
          (*inst)->unUseAll();
          inst = (*bb)->instructions().erase(inst);
          inst--;
        }
      }
      InsToRemove.clear();
    }
  } while (!change);


}

}  // namespace Pass
