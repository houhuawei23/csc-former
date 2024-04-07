/* reference: https://dl.acm.org/doi/pdf/10.1145/103135.103136
 *
 * SCC works as follows:
 *
 *     TOP: some (as yet) undetermined constant
 *     CON: constant
 *     BOT: a constant value cannot be guaranteed
 *
 * (1) initialize the FlowWorkList to contain the edges exiting the start node of the program.
 *     The SSAWorkList is initially empty.
 *     Each program flow graph edge has an associated flag, the ExecutableFlag, that controls the evaluation of
 *     phi-functions in the destination node of that edge. This flaog is initially false for all edges.
 *     Each LatticeCell is initially TOP
 * (2) Halt execution when both worklists become empty. Execution may proceed by processing items from either
 *     worklists
 * (3) If the item is a program flow graph edge from the FlowWorkList, then examine the ExecutableFlag of that edge.
 *     If the ExecutableFlag is true do nothing; otherwise:
 *     (a) Mark the ExecutableFlag of the edge as true.
 *     (b) Perform visitPhi for all of the phi-functions at the destination node.
 *     (c) If only one of the ExecutableFlags associated with the incoming program flow graph edges is true (i.e.,
 *     if this is the first time this node has been evaluated), then perform visitExpression for the expression in
 *     this node.
 *     (d) If the node only contains one outgoing flow graph edge, add that edge to the FlowWorkList.
 * (4) If the item is an SSA edge from the SSAWorkList and the destination of that edge is a phi-function, perform
 *     visitPhi.
 * (5) If the item is an SSA edge from the SSAWorkList and the destination of that edge is an expression, then
 *     examine ExecutableFlags for the program flow edges reaching that node. If any of them are true, perform
 *     visitExpression. Otherwise do nothing.
 *
 *
 * The value of the LatticeCell associated with the output of a phi-function is defined to be the meet of all
 * arguments whose corresponding in-edge has been marked executable.
 *
 *
 * visitPhi is defined as follows:
 *
 * The LatticeCells for each operand of the phi-function are defined on
 * the basis of the ExecutableFlag for the corresponding program flow edge. executable  The LatticeCell has the same
 * value as the LatticeCell at the definition end of the SSA edge. not-executable  The LatticeCell has the value TOP
 *
 *
 * visitExpression is defined as follows:
 *
 * Evaluate the expression obtaining the values of the operands from the
 * LatticeCells where they are defined and using the expression rules in Section 2.2. If this changes the value of
 * the LatticeCell of the output of the expression, do the following:
 * (1) If the expression is part of an assignment node, add to the SSAWorkList all SSA edges starting at the
 *     definition for that node.
 * (2) If the expression controls a condictional branch, some outgoing flow graph edges must be added to the
 *     FlowWorkList. If the LatticeCell has value BOT, all exit edges must be added to the FlowWorkList.
 *
 *
 * expression evaluation rules:
 * Usually, if the node is an assignment and any of the variables used in its expression portion has a value of BOT, the
 * value exiting the assignment statement for that variable is BOT.
 * If all values used in its expression portion are constant, the value of the assigned variable is the value of the
 * expression when evaluated with those constant values.
 * Otherwise the value assigned is BOT.
 *
 *
 * For certain operators, however, we can give special expression rules that yield better information.
 * (1) any || true = true
 * (2) any && false = false
 *
 *
 * A condictional branch with constant condition
 * j <- 5
 * if (1 = j) then i <- j + 1
 *
 */

#ifndef __OPTIMIZE_SCCP_HPP__
#define __OPTIMIZE_SCCP_HPP__

#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_set>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"

namespace Pass {

class SCCP : public FunctionPass {
private:
  typedef enum : size_t { TOP, CON, BOT } Lattice;
  std::deque<std::pair<IR::Value*, IR::Value*>> worklist;
  std::unordered_map<IR::BasicBlock*, std::unordered_map<IR::BasicBlock*, bool>> ExecutableFlag;
  std::unordered_map<IR::Value*, Lattice> LatticeCell;
  std::unordered_map<IR::Value*, IR::Constant*> SCCPInfo;

public:
  std::string_view name() override {
    return "SCCP";
  }
  Lattice getLattice(IR::Value* value) {
    if (dynamic_cast<IR::Constant*>(value)) return CON;
    // if (dynamic_cast<IR::AllocaInst*>(value)) return BOT;
    return LatticeCell[value];
  }
  void run(IR::Function* pass_unit) override {
    std::unordered_set<IR::BasicBlock*> vis;
    worklist.clear();
    ExecutableFlag.clear();
    LatticeCell.clear();
    SCCPInfo.clear();
    for (auto successor : pass_unit->allocas()->successors()) worklist.emplace_back(pass_unit->allocas(), successor);
    while (worklist.size()) {
      auto [t0, t1] = worklist.front();
      worklist.pop_front();
      if (auto [src, dest] = isFlowEdge(t0, t1); src && dest) {
        if (ExecutableFlag[src][dest] == true)
          continue;
        else {
          ExecutableFlag[src][dest] = true;
          for (auto& instruction : dest->instructions())
            if (auto phi = dynamic_cast<IR::PhiInst*>(instruction.get())) visitPhi(phi);
          if (!vis.count(dest)) {
            vis.emplace(dest);
            visitExpression(dest);
          }
          if (dest->successors().size() == 1) worklist.emplace_back(pass_unit, dest->successors().front());
        }
      }
      if (auto [src, dest] = isSSAEdge(t0, t1); src && dest) {
        if (auto phi = dynamic_cast<IR::PhiInst*>(dest))
          visitPhi(phi);
        else
          for (auto predecessor : dest->basicBlock()->predecessors())
            if (ExecutableFlag[predecessor][dest->basicBlock()] == true) {
              visitExpression(dest->basicBlock());
              break;
            }
      }
    }
    // for (auto [value, con] : SCCPInfo) {
    //   assert(con);
    //   value->replaceAllUseWith(con);
    // }
  }
  std::pair<IR::BasicBlock*, IR::BasicBlock*> isFlowEdge(IR::Value* src, IR::Value* dest) {
    return {dynamic_cast<IR::BasicBlock*>(src), dynamic_cast<IR::BasicBlock*>(dest)};
  }
  std::pair<IR::Instruction*, IR::Instruction*> isSSAEdge(IR::Value* src, IR::Value* dest) {
    return {dynamic_cast<IR::Instruction*>(src), dynamic_cast<IR::Instruction*>(dest)};
  }
  Lattice meet(Lattice lhs, Lattice rhs) {
    if (lhs == TOP) return rhs;
    if (rhs == TOP || lhs == rhs) return lhs;
    return BOT;
  }
  void visitPhi(IR::PhiInst* phi) {
    Lattice acc = TOP;
    for (size_t i = 0; i < phi->operands().size() / 2; i++)
      if (ExecutableFlag[static_cast<IR::BasicBlock*>(phi->incoming(i))][phi->basicBlock()] == true)
        acc = meet(acc, getLattice(phi->value(i)));
      else
        acc = meet(acc, TOP);
    LatticeCell[phi] = acc;
  }
  Lattice evaluateExpression(IR::Instruction* instruction) {
    Lattice acc;
    if (dynamic_cast<IR::RetInst*>(instruction)) {
      assert(0);
    } else if (dynamic_cast<IR::JmpInst*>(instruction)) {
      assert(0);
    } else if (dynamic_cast<IR::BrInst*>(instruction)) {
      assert(0);
    } else if (dynamic_cast<IR::AllocaInst*>(instruction)) {
      acc = BOT;
    } else if (auto load = dynamic_cast<IR::LoadInst*>(instruction)) {
      acc = BOT;
    } else if (dynamic_cast<IR::StoreInst*>(instruction)) {
      assert(0);
    } else if (dynamic_cast<IR::AddrAddInst*>(instruction)) {
      acc = BOT;
    } else if (dynamic_cast<IR::AddrDerefAddInst*>(instruction)) {
      acc = BOT;
    } else if (dynamic_cast<IR::PhiInst*>(instruction)) {
      assert(0);
    } else if (dynamic_cast<IR::CallInst*>(instruction)) {  // TODO
      acc = BOT;
    } else if (auto unary = dynamic_cast<IR::UnaryInst*>(instruction)) {
      IR::Constant* rhs = dynamic_cast<IR::Constant*>(unary->rhs());
      if (rhs) {
        acc = CON;
        switch (unary->itype()) {
          case IR::ZEXT: {
            SCCPInfo[unary] = IR::Constant::get((int32_t)(*rhs->getField<bool>()));
          } break;
          case IR::SITOFP: {
            SCCPInfo[unary] = IR::Constant::get((float)(*rhs->getField<int32_t>()));
          } break;
          case IR::FPTOSI: {
            SCCPInfo[unary] = IR::Constant::get((int32_t)(*rhs->getField<float>()));
          } break;
          case IR::FNEG: {
            SCCPInfo[unary] = IR::Constant::get((float)(-*rhs->getField<float>()));
          } break;
          default: {
            assert(0);
          } break;
        }
        unary->replaceAllUseWith(SCCPInfo[unary]);
      } else {
        acc = BOT;
      }
    } else if (auto binary = dynamic_cast<IR::BinaryInst*>(instruction)) {
      IR::Constant* lhs = dynamic_cast<IR::Constant*>(binary->lhs());
      IR::Constant* rhs = dynamic_cast<IR::Constant*>(binary->rhs());
      if (lhs && rhs) {
        acc = CON;
        switch (binary->itype()) {
          case IR::ADD: {
            SCCPInfo[binary] = IR::Constant::get((int32_t)((*lhs->getField<int32_t>()) + (*rhs->getField<int32_t>())));
          } break;
          case IR::SUB: {
            SCCPInfo[binary] = IR::Constant::get((int32_t)((*lhs->getField<int32_t>()) - (*rhs->getField<int32_t>())));
          } break;
          case IR::MUL: {
            SCCPInfo[binary] = IR::Constant::get((int32_t)((*lhs->getField<int32_t>()) * (*rhs->getField<int32_t>())));
          } break;
          case IR::SDIV: {
            SCCPInfo[binary] = IR::Constant::get((int32_t)((*lhs->getField<int32_t>()) / (*rhs->getField<int32_t>())));
          } break;
          case IR::SREM: {
            SCCPInfo[binary] = IR::Constant::get((int32_t)((*lhs->getField<int32_t>()) % (*rhs->getField<int32_t>())));
          } break;
          case IR::FADD: {
            SCCPInfo[binary] = IR::Constant::get((float)((*lhs->getField<float>()) + (*rhs->getField<float>())));
          } break;
          case IR::FSUB: {
            SCCPInfo[binary] = IR::Constant::get((float)((*lhs->getField<float>()) - (*rhs->getField<float>())));
          } break;
          case IR::FMUL: {
            SCCPInfo[binary] = IR::Constant::get((float)((*lhs->getField<float>()) * (*rhs->getField<float>())));
          } break;
          case IR::FDIV: {
            SCCPInfo[binary] = IR::Constant::get((float)((*lhs->getField<float>()) / (*rhs->getField<float>())));
          } break;
          default: {
            assert(0);
          } break;
        }
        binary->replaceAllUseWith(SCCPInfo[binary]);
      } else {
        acc = BOT;
      }
    } else if (auto icmp = dynamic_cast<IR::IcmpInst*>(instruction)) {
      IR::Constant* lhs = dynamic_cast<IR::Constant*>(icmp->lhs());
      IR::Constant* rhs = dynamic_cast<IR::Constant*>(icmp->rhs());
      if (lhs && rhs) {
        acc = CON;
        switch (icmp->itype()) {
          case IR::IEQ: {
            SCCPInfo[icmp] = IR::Constant::get((bool)((*lhs->getField<int32_t>()) == (*rhs->getField<int32_t>())));
          } break;
          case IR::INE: {
            SCCPInfo[icmp] = IR::Constant::get((bool)((*lhs->getField<int32_t>()) != (*rhs->getField<int32_t>())));
          } break;
          case IR::ISGT: {
            SCCPInfo[icmp] = IR::Constant::get((bool)((*lhs->getField<int32_t>()) > (*rhs->getField<int32_t>())));
          } break;
          case IR::ISGE: {
            SCCPInfo[icmp] = IR::Constant::get((bool)((*lhs->getField<int32_t>()) >= (*rhs->getField<int32_t>())));
          } break;
          case IR::ISLT: {
            SCCPInfo[icmp] = IR::Constant::get((bool)((*lhs->getField<int32_t>()) < (*rhs->getField<int32_t>())));
          } break;
          case IR::ISLE: {
            SCCPInfo[icmp] = IR::Constant::get((bool)((*lhs->getField<int32_t>()) <= (*rhs->getField<int32_t>())));
          } break;
          default: {
            assert(0);
          } break;
        }
        icmp->replaceAllUseWith(SCCPInfo[icmp]);
      } else {
        acc = BOT;
      }
    } else if (auto fcmp = dynamic_cast<IR::FcmpInst*>(instruction)) {
      IR::Constant* lhs = dynamic_cast<IR::Constant*>(fcmp->operand(0));
      IR::Constant* rhs = dynamic_cast<IR::Constant*>(fcmp->operand(1));
      if (lhs && rhs) {
        acc = CON;
        switch (fcmp->itype()) {
          case IR::FOEQ: {
            SCCPInfo[fcmp] = IR::Constant::get((bool)((*lhs->getField<float>()) == (*rhs->getField<float>())));
          } break;
          case IR::FONE: {
            SCCPInfo[fcmp] = IR::Constant::get((bool)((*lhs->getField<float>()) != (*rhs->getField<float>())));
          } break;
          case IR::FOGT: {
            SCCPInfo[fcmp] = IR::Constant::get((bool)((*lhs->getField<float>()) > (*rhs->getField<float>())));
          } break;
          case IR::FOGE: {
            SCCPInfo[fcmp] = IR::Constant::get((bool)((*lhs->getField<float>()) >= (*rhs->getField<float>())));
          } break;
          case IR::FOLT: {
            SCCPInfo[fcmp] = IR::Constant::get((bool)((*lhs->getField<float>()) < (*rhs->getField<float>())));
          } break;
          case IR::FOLE: {
            SCCPInfo[fcmp] = IR::Constant::get((bool)((*lhs->getField<float>()) <= (*rhs->getField<float>())));
          } break;
          default: {
            assert(0);
          } break;
        }
        fcmp->replaceAllUseWith(SCCPInfo[fcmp]);
      } else {
        acc = BOT;
      }
    } else
      assert(0);
    return acc;
  }
  void visitExpression(IR::BasicBlock* basic_block) {
    for (auto& instruction : basic_block->instructions()) {
      if(dynamic_cast<IR::PhiInst*>(instruction.get()))continue;
      if (!instruction->type()->isVoid()) {
        Lattice tmp = evaluateExpression(instruction.get());
        if (getLattice(instruction.get()) != tmp) {
          LatticeCell[instruction.get()] = tmp;
          for (auto use : instruction->uses())
            if (use) worklist.emplace_back(instruction.get(), use->user());
        }
      } else if (auto br = dynamic_cast<IR::BrInst*>(instruction.get())) {
        Lattice tmp = getLattice(br->cond());
        if (tmp == BOT)
          for (auto successor : br->basicBlock()->successors()) worklist.emplace_back(br->basicBlock(), successor);
        else if (tmp == CON) {
          if (auto c = dynamic_cast<IR::Constant*>(br->cond())) {
            if (*c->getField<bool>() == true) {
              worklist.emplace_back(br->basicBlock(), br->iftrue());
            } else {
              worklist.emplace_back(br->basicBlock(), br->iffalse());
            }
          } else {
            if (*SCCPInfo[br->cond()]->getField<bool>() == true)
              worklist.emplace_back(br->basicBlock(), br->iftrue());
            else
              worklist.emplace_back(br->basicBlock(), br->iffalse());
          }
        }
      }
    }
  }
};

}  // namespace Pass

#endif
