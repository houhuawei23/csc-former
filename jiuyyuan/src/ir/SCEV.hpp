#ifndef __IR_SCEV_HPP__
#define __IR_SCEV_HPP__
#include <set>

#include "userelation.hpp"
// #include "instruction.hpp"
// #include "cycle.hpp"
namespace IR {
class BinaryInst;
// class SCEV;
// class Cycle {
// private:
//   IR::BasicBlock *header;
//   IR::BasicBlock *latchBlock;
//   // IR::BasicBlock* pre_header;
// public:
//   int id;
//   int iterationCount;
//   IR::PhiInst *phi;
//   IR::Value *end;
//   IR::Instruction *icmp;
//   std::vector<IR::BasicBlock *> nodes;
//   Cycle *parentCycle;
//   Function *parentFunc;
//   int depth;
//   // 退出基本块
//   std::unordered_set<BasicBlock *> ExitingBlocks;
//   // 后继基本块
//   std::unordered_set<BasicBlock *> ExitBlocks;
//   std::unordered_set<BasicBlock *> bb_sets;

//   std::vector<Cycle *> subLoops;
//   std::vector<std::pair<Instruction *, SCEV>> SCEVCheck;
//   // Default constructor
//   Cycle(BasicBlock *Header)
//       : header(Header),
//         iterationCount(0),
//         phi(nullptr),
//         end(nullptr),
//         icmp(nullptr),
//         parentCycle(nullptr),
//         parentFunc(Header->function()) {
//     nodes.push_back(Header);
//     bb_sets.insert(Header);
//   }
//   Cycle() {
//     id = -1;
//     parentCycle = NULL;
//     depth = 0;
//   }

//   // Parameterized constructor
//   Cycle(int id, std::vector<IR::BasicBlock *> nodes, Cycle *parentCycle, int depth) {
//     this->id = id;
//     this->nodes = nodes;
//     this->parentCycle = parentCycle;
//     this->depth = depth;
//   }
//   void setHeader(BasicBlock *Header) {
//     header = Header;
//   }
//   void setLatch(BasicBlock *latch) {
//     latchBlock = latch;
//   }
//   BasicBlock *Header() {
//     return header;
//   }
//   BasicBlock *Latch() {
//     return latchBlock;
//   }
//   SCEV &getSCEV(Instruction *instr);
//   bool hasSCEV(Instruction *instr);
//   bool isLoopInvariant(Value *val);
//   void logupSCEV(Instruction *inst, SCEV scev);
//   Cycle *getLoopCopy(Cycle *loop, std::unordered_map<Value *, Value *> &LoopValueCpy,
//                      std::unordered_map<PhiInst *, Value *> &CurrentIncomingValue);
// };

// using Cycles = typename std::vector<Cycle *>;

class SCEV {
private:
  std::vector<Value*> scevVector;
  std::set<IR::BinaryInst*> instCaculated;

public:
  SCEV(){};
  SCEV(Value* initial, Value* step);
  SCEV(Value* initial, const SCEV& innerSCEV);
  SCEV(const std::vector<Value*>& vec);
  SCEV(Value* initial, Value* step, std::set<IR::BinaryInst*>&& binarys);

  friend SCEV operator*(Value* lhs, const SCEV& rhs);

  Value*& at(unsigned i) {
    return scevVector.at(i);
  }

  size_t size() {
    return scevVector.size();
  }

  Value* at(unsigned i) const {
    return scevVector.at(i);
  }

  size_t size() const {
    return scevVector.size();
  }

  void getInstructionChainOfElement(unsigned i, std::vector<BinaryInst*>& instrChain);

  void clear();

  friend SCEV operator+(Value* lhs, const SCEV& rhs);
  friend SCEV operator+(const SCEV& lhs, const SCEV& rhs);
  friend SCEV operator-(const SCEV& lhs, Value* rhs);
  friend SCEV operator-(const SCEV& lhs, const SCEV& rhs);
};
}  // namespace IR

#endif
