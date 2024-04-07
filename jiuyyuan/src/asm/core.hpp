#ifndef __RISCV_CORE_HPP__
#define __RISCV_CORE_HPP__

#include <cassert>

#include "directive.hpp"
#include "inst.hpp"
#include "mana.hpp"
#include "reg.hpp"

namespace RISCV {

class StackObject;
class Program;
class Function;
class Block;

class StackObject {
protected:
  size_t _size;
  Reg* _base;
  int32_t _offset;

public:
  StackObject(size_t size);
  size_t size();
  Reg* base();
  int32_t offset();
  void setBase(Reg* base);
  void setOffset(int32_t offset);
};

class Program {
protected:
  std::list<std::unique_ptr<GlobalValue>> _global_values;
  std::list<std::unique_ptr<Function>> _functions;

public:
  Program(IR::CompileUnit* compile_unit);
  std::list<std::unique_ptr<GlobalValue>>& globalValues();
  std::list<std::unique_ptr<Function>>& functions();
  GlobalValue* newGlobalValue(IR::Variable* global);
  Function* newFunction(IR::Function* function);
};

class Function {
protected:
  Program* _program;
  std::string _name;
  std::unique_ptr<Mana> _mana;
  size_t _caller_stack_size;
  size_t _prologue_stack_size;
  size_t _callee_stack_size;
  size_t _stack_arg_size;
  std::vector<std::unique_ptr<StackObject>> _stack_objects;
  std::vector<StackObject*> _caller_stack;
  std::vector<std::unique_ptr<StackObject>> _prologue_stack;
  std::vector<StackObject*> _callee_stack;
  std::unordered_map<Reg*, StackObject*> _stack_info;
  std::unordered_map<IR::BasicBlock*, Block*> _block_info;
  std::unordered_map<Block*, IR::BasicBlock*> _irblock_info;
  Reg* _ra;
  std::vector<Reg*> _spilled_argument_regs;
  Block* _entry;
  std::vector<Block*> _exits;
  std::list<std::unique_ptr<Block>> _blocks;

public:
  Program* program();
  std::string name();
  Mana* mana();
  size_t callerStackSize();
  size_t prologueStackSize();
  size_t calleeStackSize();
  size_t stackArgSize();
  size_t stackSize();
  StackObject* newStackObject(size_t size);
  std::vector<StackObject*>& callerStack();
  std::vector<std::unique_ptr<StackObject>>& prologueStack();
  std::vector<StackObject*>& calleeStack();
  std::unordered_map<Reg*, StackObject*>& stackInfo();
  std::unordered_map<IR::BasicBlock*, Block*>& blockInfo();
  std::unordered_map<Block*, IR::BasicBlock*>& irblockInfo();
  Reg* ra();
  Block* entry();
  std::vector<Block*>& exits();
  std::list<std::unique_ptr<Block>>& blocks();
  StackObject* newCallerStackObject(size_t size, Reg* base, size_t offset);
  StackObject* newPrologueStackObject(size_t size);
  StackObject* newCalleeStackObject(size_t size);
  void updateStackArgSize(size_t size);
  void addCode(const std::unordered_set<Reg*>& regs);

  Function(Program* program, IR::Function* function);
  void initialize(IR::Function* function);
  void instSelect(IR::Function* function);
  void eliminatePhi(IR::Function* function);
  void initArgument(IR::Function* function);
  void preload(IR::Function* function);
  void initCalleeSaveReg(const std::unordered_set<Reg*>& callee_save_regs);
  void scheduleCalleeStack();
  void initStackOffset();
  void initStackPointer(const std::unordered_set<Reg*>& regs);
  void eliminateMove();
  void calcLive();
  void eraseUnreachableBB();
  void basicblockReorder();
};

class Block {
public:
  double _heuristic;

protected:
  Function* _function;
  std::string _name;
  std::list<std::unique_ptr<Inst>> _insts;
  std::unordered_set<Block*> _preds;
  std::unordered_set<Block*> _succs;
  std::unordered_set<Reg*> _live_use;
  std::unordered_set<Reg*> _live_def;
  std::unordered_set<Reg*> _live_in;
  std::unordered_set<Reg*> _live_out;

public:
  Block(Function* function, const std::string& name);
  Function* function();
  std::string name();
  double heuristic();
  std::list<std::unique_ptr<Inst>>& insts();
  void instSelect(IR::BasicBlock* basic_block);
  std::unordered_set<Block*>& preds();
  std::unordered_set<Block*>& succs();
  std::unordered_set<Reg*>& liveUse();
  std::unordered_set<Reg*>& liveDef();
  std::unordered_set<Reg*>& liveIn();
  std::unordered_set<Reg*>& liveOut();
  void calcLiveUseDef();
  void initLiveInOut();
};

}  // namespace RISCV

#endif

// void instSelect(IR::BasicBlock* bb) {
//   Mana* mana = function()->mana();
//   for (auto& inst : bb->instructions()) {
//     if (auto ret = dynamic_cast<IR::RetInst*>(inst.get())) {
//       if (!ret->retValue()->type()->isVoid()) {
//         Reg* reg = mana->vreg(ret->retValue());
//         if (reg->isxreg())
//           newMove(A0, reg);
//         else if (reg->isfreg())
//           newMove(FA0, reg);
//         else
//           assert(0);
//       }
//       // newMove(RA, function()->vra());
//       newInst(new Target::JALR(ZERO, RA, 0));
//     } else if (auto jmp = dynamic_cast<IR::JmpInst*>(inst.get())) {
//       auto dest = jmp->dest();
//       newInst(new Pseudo::J(function()->blockInfo()[dest]->name()));
//       succs().emplace(function()->blockInfo()[dest]);
//       function()->blockInfo()[dest]->preds().emplace(this);
//     } else if (auto br = dynamic_cast<IR::BrInst*>(inst.get())) {
//       auto rs1 = mana->vreg(br->cond());
//       auto iftrue = br->iftrue();
//       auto iffalse = br->iffalse();
//       newInst(new Target::BEQ(rs1, ZERO, function()->blockInfo()[iffalse]->name()));
//       succs().emplace(function()->blockInfo()[iffalse]);
//       function()->blockInfo()[iffalse]->preds().emplace(this);
//       newInst(new Pseudo::J(function()->blockInfo()[iftrue]->name()));
//       succs().emplace(function()->blockInfo()[iftrue]);
//       function()->blockInfo()[iftrue]->preds().emplace(this);
//       // TODO
//       // } else if (auto global = dynamic_cast<IR::GlobalInst*>(inst.get())) {
//       //   mana->vreg(global);
//       //   function()->program()->newGlobalValue(global);
//     } else if (auto alloca = dynamic_cast<IR::AllocaInst*>(inst.get())) {
//       Reg* reg = mana->vreg(alloca);
//       StackObject* stack_object = function()->newCalleeStackObject(alloca->type()->deref(1)->sizeOf());
//       function()->stackInfo()[reg] = stack_object;
//       // newInst(new Pseudo::LoadStackAddr(reg, stack_object));
//     } else if (auto load = dynamic_cast<IR::LoadInst*>(inst.get())) {
//       auto rd = mana->vreg(load);
//       auto rs1 = mana->vreg(load->addr());
//       if (load->type()->isArray()) {
//         newMove(rd, rs1);
//       } else {
//         if (rd->isxreg())
//           if (rd->sizeOf() == 4)
//             newInst(new Target::LW(rd, rs1, 0));
//           else if (rd->sizeOf() == 8)
//             newInst(new Target::LD(rd, rs1, 0));
//           else
//             assert(0);
//         else if (rd->isfreg())
//           if (rd->sizeOf() == 4)
//             newInst(new Target::FLW(rd, rs1, 0));
//           else if (rd->sizeOf() == 8)
//             newInst(new Target::FLD(rd, rs1, 0));
//           else
//             assert(0);
//         else
//           assert(0);
//       }
//     } else if (auto store = dynamic_cast<IR::StoreInst*>(inst.get())) {
//       auto rs1 = mana->vreg(store->addr());
//       auto rs2 = mana->vreg(store->value());
//       if (rs2->isxreg())
//         if (rs2->sizeOf() == 4)
//           newInst(new Target::SW(rs1, rs2, 0));
//         else if (rs2->sizeOf() == 8)
//           newInst(new Target::SD(rs1, rs2, 0));
//         else
//           assert(0);
//       else if (rs2->isfreg())
//         if (rs2->sizeOf() == 4)
//           newInst(new Target::FSW(rs1, rs2, 0));
//         else if (rs2->sizeOf() == 8)
//           newInst(new Target::FSD(rs1, rs2, 0));
//         else
//           assert(0);
//       else
//         assert(0);
//       // } else if (auto getelementptr = dynamic_cast<IR::GetelementptrInst*>(inst.get())) {
//       // IR::Type* type = getelementptr->addr()->type()->deref(1);
//       // auto rd = mana->vreg(getelementptr);
//       // auto rt = mana->vreg(Reg::XREG, 8);
//       // auto rs1 = mana->vreg(getelementptr->addr());
//       // auto rs2 = mana->vreg(getelementptr->index(0));
//       // auto rs3 = mana->vreg(IR::Constant::get((int32_t)type->sizeOf()));
//       // newInst(new Target::MUL(rt, rs2, rs3));
//       // for (size_t i = 1; i < getelementptr->indexs().size(); i++) {
//       //   rt = mana->vreg(Reg::XREG, 8);
//       //   rs1 = mana->vreg(getelementptr->index(0));
//       //   rs2 = mana->vreg(IR::Constant::get((int32_t)type->sizeOf()));
//       //   newInst(new Target::MUL(rt, rs2, rs3));
//       //   type = type->deref(1);
//       // }
//       // newInst(new Target::ADD(rd, rs1, rt));
//     } else if (auto getptr = dynamic_cast<IR::AddrDerefAddInst*>(inst.get())) {
//       Reg* rd = mana->vreg(getptr);
//       Reg* rs1 = mana->vreg(getptr->addr());
//       Reg* rs2 = mana->vreg(getptr->offset());
//       newInst(new Target::ADD(rd, rs1, rs2));
//     } else if (auto addradd = dynamic_cast<IR::AddrAddInst*>(inst.get())) {
//       Reg* rd = mana->vreg(addradd);
//       Reg* rs1 = mana->vreg(addradd->addr());
//       Reg* rs2 = mana->vreg(addradd->offset());
//       newInst(new Target::ADD(rd, rs1, rs2));
//     } else if (auto phi = dynamic_cast<IR::PhiInst*>(inst.get())) {
//       // for (size_t i = 0; phi->operands().size() / 2; i++) {  // e phi
//       //   Reg* t = mana->vreg(phi);
//       //   Reg* valreg = mana->vreg(phi->getvals(i));
//       //   auto b = function()->blockInfo()[static_cast<IR::BasicBlock*>(phi->getblos(i))];
//       //   auto it = std::prev(b->insts().end());
//       //   if (t->isxreg()) {
//       //     b->insts().emplace(it, new Target::ADDI(t, valreg, 0));
//       //   } else if (t->isfreg()) {
//       //     b->insts().emplace(it, new Target::FSGNJS(t, valreg, valreg));
//       //   }
//       // }
//     } else if (auto call = dynamic_cast<IR::CallInst*>(inst.get())) {
//       auto callee = call->callee();
//       function()->updateStackArgSize(callee);
//       auto label = callee->name();
//       size_t arg_xreg_num = 0;
//       size_t arg_freg_num = 0;
//       int32_t offset = 0;
//       for (auto& param : call->arguments()) {
//         Reg* reg = mana->vreg(param->value());
//         if (reg->isxreg()) {
//           if (arg_xreg_num < ARG_XREG_NUM) {
//             newMove(ARG_XREG[arg_xreg_num], reg);
//           } else {
//             if (reg->sizeOf() == 4) {
//               if (RISCV::validShortImm(offset)) {
//                 newInst(new Target::SW(SP, reg, offset));
//               } else {
//                 Reg* ta = mana->vreg(Reg::XREG, 8);
//                 newInst(new Pseudo::LI(ta, offset));
//                 newInst(new Target::ADD(ta, ta, SP));
//                 newInst(new Target::SW(ta, reg, 0));
//               }
//             } else if (reg->sizeOf() == 8) {
//               if (RISCV::validShortImm(offset)) {
//                 newInst(new Target::SD(SP, reg, offset));
//               } else {
//                 Reg* ta = mana->vreg(Reg::XREG, 8);
//                 newInst(new Pseudo::LI(ta, offset));
//                 newInst(new Target::ADD(ta, ta, SP));
//                 newInst(new Target::SD(ta, reg, 0));
//               }
//             } else {
//               assert(0);
//             }
//             offset += 8;
//           }
//           arg_xreg_num++;
//         } else if (reg->isfreg()) {
//           if (arg_freg_num < ARG_FREG_NUM) {
//             newMove(ARG_FREG[arg_freg_num], reg);
//           } else {
//             if (reg->sizeOf() == 4) {
//               if (RISCV::validShortImm(offset)) {
//                 newInst(new Target::FSW(SP, reg, offset));
//               } else {
//                 Reg* ta = mana->vreg(Reg::XREG, 8);
//                 newInst(new Pseudo::LI(ta, offset));
//                 newInst(new Target::ADD(ta, ta, SP));
//                 newInst(new Target::FSW(ta, reg, 0));
//               }
//             } else if (reg->sizeOf() == 8) {
//               if (RISCV::validShortImm(offset)) {
//                 newInst(new Target::FSD(SP, reg, offset));
//               } else {
//                 Reg* ta = mana->vreg(Reg::XREG, 8);
//                 newInst(new Pseudo::LI(ta, offset));
//                 newInst(new Target::ADD(ta, ta, SP));
//                 newInst(new Target::FSD(ta, reg, 0));
//               }
//             } else {
//               assert(0);
//             }
//             offset += 8;
//           }
//           arg_freg_num++;
//         } else {
//           assert(0);
//         }
//       }
//       newInst(new Pseudo::CALL(label, arg_xreg_num, arg_freg_num));
//       if (!call->type()->isVoid()) {
//         Reg* reg = mana->vreg(call);
//         if (reg->isxreg())
//           newMove(reg, A0);
//         else if (reg->isfreg())
//           newMove(reg, FA0);
//         else
//           assert(0);
//       }
//     } else if (auto unary = dynamic_cast<IR::UnaryInst*>(inst.get())) {
//       auto rd = mana->vreg(unary);
//       auto rs1 = mana->vreg(unary->rhs());
//       switch (unary->itype()) {
//         case IR::FNEG: {
//           newInst(new Target::FSGNJNS(rd, rs1, rs1));
//         } break;
//         case IR::ZEXT: {
//           //! TODO mv
//           newInst(new Target::ADDI(rd, rs1, 0));
//         } break;
//         case IR::FPTOSI: {
//           Reg* t = mana->vreg(Reg::XREG, 8);
//           newInst(new Target::ADDI(t, ZERO, 1));
//           newInst(new Pseudo::FSRM(t, t));
//           newInst(new Target::FCVTWS(rd, rs1));
//           newInst(new Pseudo::FSRM(t, t));
//         } break;
//         case IR::SITOFP: {
//           newInst(new Target::FCVTSW(rd, rs1));
//         } break;
//         case IR::PTRTOINT: {
//           newMove(rd, rs1);
//         } break;
//         case IR::INTTOPTR: {
//           newMove(rd, rs1);
//         } break;
//         default: {
//           assert(0);
//         } break;
//       }
//     } else if (auto binary = dynamic_cast<IR::BinaryInst*>(inst.get())) {
//       auto rd = mana->vreg(binary);
//       auto rs1 = mana->vreg(binary->lhs());
//       auto rs2 = mana->vreg(binary->rhs());
//       switch (binary->itype()) {
//         case IR::ADD: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::ADD(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::ADDW(rd, rs1, rs2));
//           else
//             assert(0);
//         } break;
//         case IR::FADD: {
//           newInst(new Target::FADDS(rd, rs1, rs2));
//         } break;
//         case IR::SUB: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::SUB(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::SUBW(rd, rs1, rs2));
//         } break;
//         case IR::FSUB: {
//           newInst(new Target::FSUBS(rd, rs1, rs2));
//         } break;
//         case IR::MUL: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::MUL(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::MULW(rd, rs1, rs2));
//         } break;
//         case IR::FMUL: {
//           newInst(new Target::FMULS(rd, rs1, rs2));
//         } break;
//         case IR::SDIV: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::DIV(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::DIVW(rd, rs1, rs2));
//         } break;
//         case IR::FDIV: {
//           newInst(new Target::FDIVS(rd, rs1, rs2));
//         } break;
//         case IR::SREM: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::REM(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::REMW(rd, rs1, rs2));
//         } break;
//         default: {
//           assert(0);
//         } break;
//       }
//     } else if (auto icmp = dynamic_cast<IR::IcmpInst*>(inst.get())) {
//       auto rd = mana->vreg(icmp);
//       auto rs1 = mana->vreg(icmp->lhs());
//       auto rs2 = mana->vreg(icmp->rhs());
//       switch (icmp->itype()) {
//         case IR::IEQ: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::SUB(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::SUBW(rd, rs1, rs2));
//           newInst(new Target::SLTIU(rd, rd, 1));
//         } break;
//         case IR::INE: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::SUB(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::SUBW(rd, rs1, rs2));
//           newInst(new Target::SLTU(rd, ZERO, rd));
//         } break;
//         case IR::ISGT: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::SUB(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::SUBW(rd, rs1, rs2));
//           newInst(new Target::SLT(rd, ZERO, rd));
//         } break;
//         case IR::ISGE: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::SUB(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::SUBW(rd, rs1, rs2));
//           newInst(new Target::SLT(rd, rd, ZERO));
//           newInst(new Target::XORI(rd, rd, 1));
//         } break;
//         case IR::ISLT: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::SUB(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::SUBW(rd, rs1, rs2));
//           newInst(new Target::SLT(rd, rd, ZERO));
//         } break;
//         case IR::ISLE: {
//           if (rd->sizeOf() == 8)
//             newInst(new Target::SUB(rd, rs1, rs2));
//           else if (rd->sizeOf() == 4)
//             newInst(new Target::SUBW(rd, rs1, rs2));
//           newInst(new Target::SLT(rd, ZERO, rd));
//           newInst(new Target::XORI(rd, rd, 1));
//         } break;
//         default: {
//           assert(0);
//         } break;
//       }
//     } else if (auto fcmp = dynamic_cast<IR::FcmpInst*>(inst.get())) {
//       auto rd = mana->vreg(fcmp);
//       auto rs1 = mana->vreg(fcmp->lhs());
//       auto rs2 = mana->vreg(fcmp->rhs());
//       switch (fcmp->itype()) {
//         case IR::FOEQ: {
//           newInst(new Target::FEQS(rd, rs1, rs2));
//         } break;
//         case IR::FONE: {
//           newInst(new Target::FEQS(rd, rs1, rs2));
//           newInst(new Target::XORI(rd, rd, 1));
//         } break;
//         case IR::FOGT: {
//           newInst(new Target::FLTS(rd, rs2, rs1));
//         } break;
//         case IR::FOGE: {
//           newInst(new Target::FLES(rd, rs2, rs1));
//         } break;
//         case IR::FOLT: {
//           newInst(new Target::FLTS(rd, rs1, rs2));
//         } break;
//         case IR::FOLE: {
//           newInst(new Target::FLES(rd, rs1, rs2));
//         } break;
//         default: {
//           assert(0);
//         } break;
//       }
//     }
//   }
// }
