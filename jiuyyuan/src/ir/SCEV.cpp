#include "SCEV.hpp"

#include <unordered_map>
#include <utility>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "typesystem.hpp"
#include "userelation.hpp"
namespace IR {

SCEV::SCEV(Value *initial, Value *step) {
  scevVector.push_back(initial);
  scevVector.push_back(step);
}
SCEV::SCEV(Value *initial, const SCEV &innerSCEV) {
  scevVector.push_back(initial);

  for (auto iter = innerSCEV.scevVector.begin(); iter != innerSCEV.scevVector.end(); iter++)

    for (auto val : innerSCEV.scevVector) scevVector.push_back(val);

  std::set_union(instCaculated.begin(), instCaculated.end(), innerSCEV.instCaculated.begin(),
                 innerSCEV.instCaculated.end(), std::inserter(instCaculated, instCaculated.begin()));
}
SCEV::SCEV(const std::vector<Value *> &vec) {
  for (auto val : vec) scevVector.push_back(val);
}
SCEV::SCEV(Value *initial, Value *step, std::set<BinaryInst *> &&binarys) : instCaculated(binarys) {
  scevVector.push_back(initial);
  scevVector.push_back(step);
}

void SCEV::getInstructionChainOfElement(unsigned i, std::vector<BinaryInst *> &instrChain) {
  auto value = scevVector.at(i);
  if (auto instr = dynamic_cast<BinaryInst *>(value); instr && instCaculated.count(instr)) {
    std::function<void(BinaryInst *)> postTravel = [&](BinaryInst *binary) -> void {
      if (auto lhs = dynamic_cast<BinaryInst *>(binary->operand(0)); lhs && instCaculated.count(lhs)) postTravel(lhs);
      if (auto rhs = dynamic_cast<BinaryInst *>(binary->operand(1)); rhs && instCaculated.count(rhs)) postTravel(rhs);
      instrChain.push_back(binary);
    };
    postTravel(instr);
  }
}
void SCEV::clear() {
  for (auto bI : instCaculated) {
    if (!bI->basicBlock()) {
      for (auto op : bI->operands()) {
        op->value()->uses().remove(op);
      }
      bI->operands().clear();
    }
  }
  instCaculated.clear();
  scevVector.clear();
}

SCEV operator+(Value *lhs, const SCEV &rhs) {
  auto add = new IR::BinaryInst(nullptr, IR::ADD, lhs->type(), "scevtmpadd", lhs, rhs.at(0));
  std::vector<Value *> initialVals;
  initialVals.push_back(add);
  for (int i = 1; i < rhs.size(); i++) initialVals.push_back(rhs.at(i));
  auto res = SCEV(initialVals);
  res.instCaculated = rhs.instCaculated;
  res.instCaculated.insert(add);
  return res;
}
SCEV operator+(const SCEV &lhs, const SCEV &rhs) {
  auto maxSize = std::max(lhs.size(), rhs.size());
  std::vector<BinaryInst *> binaryHasBeenCreated;
  std::vector<Value *> initialVals;
  for (auto i = 0; i < maxSize; i++) {
    if (i < lhs.size() && i < rhs.size()) {
      if (auto clhs = dynamic_cast<Constant *>(lhs.at(i)); clhs->isInt())
        if (auto crhs = dynamic_cast<Constant *>(rhs.at(i))) {
          initialVals.push_back(Constant::get(clhs->getIntVal() + crhs->getIntVal()));
          continue;
        }
      auto add = new BinaryInst(nullptr, IR::ADD, lhs.at(i)->type(), "scevtmpadd", lhs.at(i), rhs.at(i));
      binaryHasBeenCreated.push_back(add);
      initialVals.push_back(add);
    } else if (i < lhs.size())
      initialVals.push_back(lhs.at(i));
    else if (i < rhs.size())
      initialVals.push_back(rhs.at(i));
  }
  auto res = SCEV(initialVals);
  std::set_union(lhs.instCaculated.begin(), lhs.instCaculated.end(), rhs.instCaculated.begin(), rhs.instCaculated.end(),
                 std::inserter(res.instCaculated, res.instCaculated.begin()));
  for (auto binary : binaryHasBeenCreated) res.instCaculated.insert(binary);
  return res;
}
SCEV operator-(const SCEV &lhs, Value *rhs) {
  auto sub = new BinaryInst(nullptr, IR::SUB, rhs->type(), "scevtmpadd", lhs.at(0), rhs);
  std::vector<Value *> initialVals;
  initialVals.push_back(sub);
  for (int i = 1; i < lhs.size(); i++) initialVals.push_back(lhs.at(i));
  auto res = SCEV(initialVals);
  res.instCaculated = lhs.instCaculated;
  res.instCaculated.insert(sub);
  return res;
}
SCEV operator-(const SCEV &lhs, const SCEV &rhs) {
  auto maxSize = std::max(lhs.size(), rhs.size());
  std::vector<BinaryInst *> binaryHasBeenCreated;
  std::vector<Value *> initialVals;
  for (auto i = 0; i < maxSize; i++) {
    if (i < lhs.size() && i < rhs.size()) {
      if (auto clhs = dynamic_cast<Constant *>(lhs.at(i)); clhs->isInt())
        if (auto crhs = dynamic_cast<Constant *>(rhs.at(i))) {
          initialVals.push_back(Constant::get(clhs->getIntVal() - crhs->getIntVal()));
          continue;
        }
      auto add = new BinaryInst(nullptr, IR::SUB, lhs.at(i)->type(), "scevtmpadd", lhs.at(i), rhs.at(i));
      binaryHasBeenCreated.push_back(add);
      initialVals.push_back(add);
    } else if (i < lhs.size())
      initialVals.push_back(lhs.at(i));
    else if (i < rhs.size())
      initialVals.push_back(rhs.at(i));
  }
  auto res = SCEV(initialVals);
  std::set_union(lhs.instCaculated.begin(), lhs.instCaculated.end(), rhs.instCaculated.begin(), rhs.instCaculated.end(),
                 std::inserter(res.instCaculated, res.instCaculated.begin()));
  for (auto binary : binaryHasBeenCreated) res.instCaculated.insert(binary);
  return res;
}
SCEV operator*(Value *lhs, const SCEV &rhs) {
  std::vector<BinaryInst *> binaryHasBeenCreated;
  std::vector<Value *> initialVals;
  for (auto initem : rhs.scevVector) {
    if (auto clhs = dynamic_cast<Constant *>(lhs))
      if (auto crhs = dynamic_cast<Constant *>(initem)) {
        initialVals.push_back(Constant::get(clhs->getIntVal() * crhs->getIntVal()));
        continue;
      }
    auto mul = new BinaryInst(nullptr, IR::MUL, lhs->type(), "scevtmpmul", lhs, initem);
    binaryHasBeenCreated.push_back(mul);
    initialVals.push_back(mul);
  }
  auto res = SCEV(initialVals);
  res.instCaculated = rhs.instCaculated;
  for (auto binary : binaryHasBeenCreated) res.instCaculated.insert(binary);
  return res;
}

SCEV &Cycle::getSCEV(Instruction *inst) {
  for (auto &pair : SCEVCheck) {
    // 如果当前元素的 Instruction* 与 Instruction 相等
    if (pair.first == inst) {
      // 返回对应的 SCEV
      return pair.second;
    }
  }
  SCEV *temp = new SCEV();
  return *temp;
}
bool Cycle::hasSCEV(Instruction *inst) {
  for (auto &pair : SCEVCheck) {
    // 如果当前元素的 Instruction* 与 Instruction 相等
    if (pair.first == inst) {
      // 返回对应的 SCEV
      return true;
    }
  }
  return false;
}
void Cycle::logupSCEV(Instruction *inst, SCEV scev) {
  SCEVCheck.emplace_back(std::make_pair(inst, scev));
}
bool Cycle::isLoopInvariant(Value *value) {
  if (auto inst = dynamic_cast<Instruction *>(value)) {
    BasicBlock *bb = inst->basicBlock();
    return !this->bb_sets.count(bb);
  }
  return true;
}

Instruction *getCopyOfInstruction(Instruction *instr, std::function<Value *(Value *)> getValue) {
  if (auto binary = dynamic_cast<BinaryInst *>(instr)) {
    auto lhs = getValue(binary->lhs());
    auto rhs = getValue(binary->rhs());

    return new BinaryInst(nullptr, binary->itype(), binary->type(), "", lhs, rhs);
  } else if (auto icmp = dynamic_cast<IcmpInst *>(instr)) {
    auto lhs = getValue(icmp->lhs());
    auto rhs = getValue(icmp->rhs());
    return new IcmpInst(nullptr, icmp->itype(), "", lhs, rhs);
  } else if (auto fcmp = dynamic_cast<FcmpInst *>(instr)) {
    auto lhs = getValue(fcmp->lhs());
    auto rhs = getValue(fcmp->rhs());
    return new FcmpInst(nullptr, fcmp->itype(), "", lhs, rhs);
  } else if (auto load = dynamic_cast<LoadInst *>(instr)) {
    auto ptr = getValue(load->addr());
    return new LoadInst(nullptr, "", ptr);
  } else if (auto store = dynamic_cast<StoreInst *>(instr)) {
    auto value = getValue(store->value());
    auto addr = getValue(store->addr());

    return new StoreInst(nullptr, value, addr);
  } else if (auto call = dynamic_cast<CallInst *>(instr)) {
    auto callee = call->callee();
    std::vector<Value *> args;
    for (auto arg : call->arguments()) args.push_back(getValue(arg->value()));

    return new CallInst(nullptr, "", callee, args);
  } else if (auto br = dynamic_cast<BrInst *>(instr)) {
    auto cond = getValue(br->cond());
    auto trueBB = dynamic_cast<BasicBlock *>(getValue(br->iftrue()));
    auto falseBB = dynamic_cast<BasicBlock *>(getValue(br->iffalse()));
    return new BrInst(nullptr, cond, trueBB, falseBB);

  } else if (auto jmp = dynamic_cast<JmpInst *>(instr)) {
    auto trueBB = dynamic_cast<BasicBlock *>(getValue(jmp->dest()));

    return new JmpInst(nullptr, trueBB);
  } else if (auto phi = dynamic_cast<PhiInst *>(instr)) {
    auto ptr = new PhiInst(nullptr, phi->type(), "");
    return ptr;
  } else if (auto alloca = dynamic_cast<AllocaInst *>(instr)) {
    return new AllocaInst(nullptr, "", alloca->type()->deref(1));
  } else if (auto unary = dynamic_cast<UnaryInst *>(instr)) {
    auto value = getValue(unary->operand(0));

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
    return new AddrDerefAddInst(nullptr, "", addr, offset);
  } else {
    return nullptr;
  }
}

Cycle *Cycle::getLoopCopy(Cycle *loop, std::unordered_map<Value *, Value *> &LoopValueCpy,
                          std::unordered_map<PhiInst *, Value *> &CurrentIncomingValue) {
  auto headerCpy = new BasicBlock(loop->parentFunc, "");

  auto latchCpy = (loop->Header() == loop->Latch()) ? headerCpy : new BasicBlock(loop->parentFunc, "");
  auto loopCpy = new Cycle(headerCpy);

  loopCpy->setLatch(latchCpy);

  auto getValue = [&](Value *val) -> Value * {
    if (auto phi = dynamic_cast<PhiInst *>(val); phi && CurrentIncomingValue.count(phi))
      return CurrentIncomingValue.at(phi);
    if (auto instr = dynamic_cast<Instruction *>(val); instr && LoopValueCpy.count(instr)) return LoopValueCpy[instr];
    if (auto bb = dynamic_cast<BasicBlock *>(val); bb && LoopValueCpy.count(bb))
      return LoopValueCpy[bb];
    else
      return val;
  };

  std::unordered_map<BasicBlock *, BasicBlock *> bbToLoop;
  std::unordered_map<PhiInst *, PhiInst *> phiQueue;

  for (auto bb : loop->nodes)
    if (bb == loop->Header()) {
      bbToLoop[bb] = headerCpy;
      LoopValueCpy[bb] = headerCpy;
    } else if (bb == loop->Latch()) {
      bbToLoop[bb] = latchCpy;
      LoopValueCpy[bb] = latchCpy;
      loopCpy->nodes.push_back(latchCpy);
      loopCpy->bb_sets.insert(latchCpy);
    } else if (bb != loop->Header() && bb != loop->Latch()) {
      auto loopBodyCpy = new BasicBlock(loop->parentFunc, "");
      bbToLoop[bb] = loopBodyCpy;
      LoopValueCpy[bb] = loopBodyCpy;
      loopCpy->nodes.push_back(loopBodyCpy);
      loopCpy->bb_sets.insert(loopBodyCpy);
    }

  for (auto bb : loop->nodes) {
    if (bb == loop->Header()) {
      for (auto &instr : bb->instructions()) {
        if (auto phi = dynamic_cast<PhiInst *>(instr.get())) continue;
        auto instrCpy = getCopyOfInstruction(instr.get(), getValue);
        auto inst = instr.get();
        LoopValueCpy[inst] = instrCpy;
        headerCpy->instructions().emplace_back(instrCpy);

        instrCpy->setBasicBlock(headerCpy);
      }
    } else if (bb == loop->Latch()) {
      for (auto &instr : bb->instructions()) {
        auto instrCpy = getCopyOfInstruction(instr.get(), getValue);
        auto inst = instr.get();
        LoopValueCpy[inst] = instrCpy;
        latchCpy->instructions().emplace_back(instrCpy);
        instrCpy->setBasicBlock(latchCpy);
        if (auto phi = dynamic_cast<PhiInst *>(inst))
          if (auto phiCpy = dynamic_cast<PhiInst *>(instrCpy)) phiQueue[phi] = phiCpy;
      }
    } else {
      for (auto &instr : bb->instructions()) {
        auto instrCpy = getCopyOfInstruction(instr.get(), getValue);
        auto inst = instr.get();
        LoopValueCpy[inst] = instrCpy;
        auto loopBodyCpy = bbToLoop[bb];
        loopBodyCpy->instructions().emplace_back(instrCpy);
        instrCpy->setBasicBlock(loopBodyCpy);
        if (auto phi = dynamic_cast<PhiInst *>(inst))
          if (auto phiCpy = dynamic_cast<PhiInst *>(instrCpy)) phiQueue[phi] = phiCpy;
      }
    }
  }

  for (auto [bb, bbCpy] : bbToLoop) {
    if (bb != loop->Header())
      for (auto pred : bb->predecessors()) {
        if (bbToLoop.count(pred)) {
          bbCpy->predecessors().push_back(bbToLoop[pred]);
          int flag = 1;
          for (auto it = loop->parentFunc->basicBlocks().begin(); it != loop->parentFunc->basicBlocks().end(); it++) {
            auto bb = it->get();
            if (bb == bbToLoop[pred]) {
              flag = 0;
            }
          }
          if (flag == 1) loop->parentFunc->basicBlocks().emplace_back(bbToLoop[pred]);
        }
      }
    if (bb != loop->Latch())
      for (auto succ : bb->successors()) {
        if (bbToLoop.count(succ)) {
          bbCpy->successors().push_back(bbToLoop[succ]);
          int flag = 1;
          for (auto it = loop->parentFunc->basicBlocks().begin(); it != loop->parentFunc->basicBlocks().end(); it++) {
            auto bb = it->get();
            if (bb == bbToLoop[succ]) {
              flag = 0;
            }
          }
          if (flag == 1) loop->parentFunc->basicBlocks().emplace_back(bbToLoop[succ]);
        }
      }
  }

  for (auto [phi, phiCpy] : phiQueue) {
    for (size_t size = 0; size < phi->operands().size() / 2; size++) {
      auto val = phi->value(size);
      auto pred = dynamic_cast<BasicBlock *>(phi->incoming(size));
      if (val) {
        phiCpy->newIncoming(getValue(val), bbToLoop[pred]);
      }
    }
  }

  std::unordered_map<PhiInst *, Value *> phiAssignLater;
  for (auto &instr : loop->Header()->instructions()) {
    if (auto phi = dynamic_cast<PhiInst *>(instr.get())) {
      for (size_t size = 0; size < phi->operands().size() / 2; size++) {
        auto val = phi->value(size);
        auto pred = dynamic_cast<BasicBlock *>(phi->incoming(size));
        if (pred == loop->Latch()) phiAssignLater[phi] = getValue(val);
      }
    } else
      break;
  }
  for (auto [phi, val] : phiAssignLater) CurrentIncomingValue[phi] = val;

  return loopCpy;
  // return nullptr;
}

}  // namespace IR
