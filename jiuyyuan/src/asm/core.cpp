#include "core.hpp"

#include <algorithm>
#include <cmath>
#include <queue>

#include "global.hpp"
#include "riscvbuilder.hpp"
#include "util.hpp"

namespace RISCV {

StackObject::StackObject(size_t size) : _size(size), _base(nullptr), _offset(0) {
}

size_t StackObject::size() {
  return _size;
}

Reg* StackObject::base() {
  return _base;
}

void StackObject::setBase(Reg* base) {
  _base = base;
}

int32_t StackObject::offset() {
  return _offset;
}

void StackObject::setOffset(int32_t offset) {
  _offset = offset;
}

Program::Program(IR::CompileUnit* cu) {
  // IR::Constant::get((bool)true)->replaceAllUseWith(IR::Constant::get((int32_t)1));
  // IR::Constant::get((bool)false)->replaceAllUseWith(IR::Constant::get((int32_t)));
  for (auto& [name, value] : cu->globalVariableTable()->table()) {
    newGlobalValue(value.get());
  }
  for (auto& f : cu->functionTable())
    if (!f->isDeclaration()) functions().emplace_back(new Function(this, f.get()));
}

std::list<std::unique_ptr<GlobalValue>>& Program::globalValues() {
  return _global_values;
}

std::list<std::unique_ptr<Function>>& Program::functions() {
  return _functions;
}

GlobalValue* Program::newGlobalValue(IR::Variable* var) {
  if (var->initializer().size() == 1 && var->initializer().front()->initialType() == IR::InitialValue::ZERO) {
    GlobalValue* global_value = new GlobalValue(GlobalValue::BSS, var->type()->sizeOf(), var->name());
    global_value->newDirective(new Directive(Directive::ZERO, var->type()->sizeOf()));
    return globalValues().emplace_back(global_value).get();
  }
  GlobalValue* global_value = new GlobalValue((var->isCompileTimeValue() ? GlobalValue::RODATA : GlobalValue::DATA),
                                              var->type()->sizeOf(), var->name());
  for (auto& init_value : var->initializer()) {
    IR::Constant* c = static_cast<IR::Constant*>(init_value->value());
    if (init_value->initialType() == IR::InitialValue::ZERO)
      global_value->newDirective(
          new Directive(Directive::ZERO, *static_cast<IR::Constant*>(init_value->value())->getField<int32_t>()));
    else {
      if (c->type()->isI32()) {
        global_value->newDirective(new Directive(Directive::WORD, *c->getField<int32_t>()));
      } else if (c->type()->isFloat()) {
        global_value->newDirective(new Directive(Directive::WORD, Util::floatToI32(*c->getField<float>())));
      }
    }
  }
  return globalValues().emplace_back(global_value).get();
}

Function* Program::newFunction(IR::Function* function) {
  functions().emplace_back(new Function(this, function));
  return functions().back().get();
}

/// @brief Function
Function::Function(Program* program, IR::Function* function)
    : _program(program),
      _name(function->name()),
      _mana(new Mana()),
      _caller_stack_size(0),
      _prologue_stack_size(0),
      _callee_stack_size(0),
      _stack_arg_size(0) {
  initialize(function);
  instSelect(function);
  eliminatePhi(function);
  initArgument(function);
  preload(function);
}

Program* Function::program() {
  return _program;
}

std::string Function::name() {
  return _name;
}

Mana* Function::mana() {
  return _mana.get();
}

size_t Function::callerStackSize() {
  return _caller_stack_size;
}

size_t Function::prologueStackSize() {
  return _prologue_stack_size;
}

size_t Function::calleeStackSize() {
  return _callee_stack_size;
}

size_t Function::stackArgSize() {
  return _stack_arg_size;
}

StackObject* Function::newStackObject(size_t size) {
  _stack_objects.emplace_back(new StackObject(size));
  return _stack_objects.back().get();
}

std::vector<StackObject*>& Function::callerStack() {
  return _caller_stack;
}

std::vector<std::unique_ptr<StackObject>>& Function::prologueStack() {
  return _prologue_stack;
}

std::vector<StackObject*>& Function::calleeStack() {
  return _callee_stack;
}

std::unordered_map<Reg*, StackObject*>& Function::stackInfo() {
  return _stack_info;
}

std::unordered_map<IR::BasicBlock*, Block*>& Function::blockInfo() {
  return _block_info;
}

std::unordered_map<Block*, IR::BasicBlock*>& Function::irblockInfo() {
  return _irblock_info;
}

Reg* Function::ra() {
  return _ra;
}

Block* Function::entry() {
  return _entry;
}

std::vector<Block*>& Function::exits() {
  return _exits;
}

std::list<std::unique_ptr<Block>>& Function::blocks() {
  return _blocks;
}

StackObject* Function::newCallerStackObject(size_t size, Reg* base, size_t offset) {
  callerStack().emplace_back(newStackObject(size));
  callerStack().back()->setBase(base);
  callerStack().back()->setOffset(offset);
  return callerStack().back();
}

StackObject* Function::newPrologueStackObject(size_t size) {
  prologueStack().emplace_back(new StackObject(size));
  return prologueStack().back().get();
}

StackObject* Function::newCalleeStackObject(size_t size) {
  calleeStack().emplace_back(newStackObject(size));
  return calleeStack().back();
}

void Function::updateStackArgSize(size_t size) {
  _stack_arg_size = std::max(_stack_arg_size, size);
}

void Function::initialize(IR::Function* function) {
  _entry = blocks().emplace_back(new Block(this, function->name())).get();
  size_t index = 0;
  for (auto& basic_block : function->basicBlocks()) {
    IR::BasicBlock* irblock = basic_block.get();
    Block* block = blocks().emplace_back(new Block(this, function->name() + "_LL_" + std::to_string(index++))).get();
    _block_info[irblock] = block;
    _irblock_info[block] = irblock;
    block->_heuristic =
        function->getLoopOfBB(basic_block.get()) ? 10 * function->getLoopOfBB(basic_block.get())->depth : 1;
    if (basic_block->isExit()) _exits.emplace_back(block);
  }
  RISCVBuilder builder(_entry, _entry->insts().end());
  builder.newInst(new Pseudo::J(_block_info[function->allocas()], _block_info[function->allocas()]->name()));
  _entry->succs().emplace(_block_info[function->allocas()]);
  _block_info[function->allocas()]->preds().emplace(_entry);
}

void Function::instSelect(IR::Function* function) {
  for (auto& basic_block : function->basicBlocks()) _block_info[basic_block.get()]->instSelect(basic_block.get());
}

void Function::eliminatePhi(IR::Function* function) {
  RISCVBuilder builder;
  for (auto& basic_block : function->basicBlocks()) {
    for (auto& instruction : basic_block->instructions()) {
      if (auto phi = dynamic_cast<IR::PhiInst*>(instruction.get())) {
        Reg* rd = mana()->vreg(phi);
        Reg* rt = mana()->vreg(rd->dtype(), rd->sizeOf());
        for (size_t i = 0; i < phi->operands().size() / 2; i++) {
          if (phi->operands()[i * 2] && phi->value(i)->type() != IR::Type::undefine_t()) {
            Reg* rs = mana()->vreg(phi->value(i));
            auto incoming = static_cast<IR::BasicBlock*>(phi->incoming(i));
            auto block = blockInfo()[incoming];
            auto it = std::prev(block->insts().end());
            if (block->insts().size() > 1 && dynamic_cast<Target::BTypeInst*>(std::prev(it)->get())) it = std::prev(it);
            builder.set(block, it);
            builder.newMove(rt, rs);
          }
        }
        builder.set(blockInfo()[basic_block.get()], blockInfo()[basic_block.get()]->insts().begin());
        builder.newMove(rd, rt);
      }
    }
  }
}

void Function::initArgument(IR::Function* function) {
  RISCVBuilder builder(_entry, std::prev(_entry->insts().end()));
  size_t offset = 0;
  for (auto& argument : function->arguments()) {
    Reg* reg = mana()->vreg(argument.get());
    if (argument->atype() == IR::Argument::XARG) {
      if (argument->index() < ARG_XREG_NUM) {
        builder.newMove(reg, ARG_XREG[argument->index()]);
      } else {
        _spilled_argument_regs.emplace_back(reg);
        offset = align(offset, reg->sizeOf());
        _stack_info[reg] = newCallerStackObject(reg->sizeOf(), S0, offset);
        offset += reg->sizeOf();
      }
    } else if (argument->atype() == IR::Argument::FARG) {
      if (argument->index() < ARG_FREG_NUM) {
        builder.newMove(reg, ARG_FREG[argument->index()]);
      } else {
        _spilled_argument_regs.emplace_back(reg);
        offset = align(offset, reg->sizeOf());
        _stack_info[reg] = newCallerStackObject(reg->sizeOf(), S0, offset);
        offset += reg->sizeOf();
      }
    } else {
      assert(0);
    }
  }
  _caller_stack_size = offset;
}

void Function::preload(IR::Function* function) {
  RISCVBuilder builder;
  for (auto& block : _blocks) {
    for (auto it = block->insts().begin(); it != block->insts().end(); it++) {
      for (Reg* reg : _spilled_argument_regs) {
        bool def = false;
        bool use = false;
        for (Reg* d : (*it)->defRegs())
          if (reg == d) def = true;
        for (Reg* u : (*it)->useRegs())
          if (reg == u) use = true;
        if (use) {
          builder.set(block.get(), it);
          Reg* rs = mana()->vreg(reg->dtype(), reg->sizeOf());
          StackObject* stack_object = _stack_info[reg];
          builder.newLoad(rs, stack_object->base(), stack_object->offset());
          (*it)->replace(reg, rs);
        }
        assert(!def);
      }
      for (auto [value, reg] : mana()->constantReg()) {
        bool def = false;
        bool use = false;
        for (Reg* d : (*it)->defRegs())
          if (reg == d) def = true;
        for (Reg* u : (*it)->useRegs())
          if (reg == u) use = true;
        if (use) {
          builder.set(block.get(), it);
          if (reg->isxreg()) {
            if (auto ptr = value->getField<int32_t>()) {
              if (*ptr == 0) {
                (*it)->replace(reg, ZERO);
              } else {
                Reg* rs = mana()->vreg(reg->dtype(), reg->sizeOf());
                builder.newInst(new Pseudo::LI(rs, *ptr));
                (*it)->replace(reg, rs);
              }
            } else if (auto ptr = value->getField<bool>()) {
              if (*ptr == 0) {
                (*it)->replace(reg, ZERO);
              } else {
                Reg* rs = mana()->vreg(reg->dtype(), reg->sizeOf());
                builder.newInst(new Pseudo::LI(rs, *ptr));
                (*it)->replace(reg, rs);
              }
            } else {
              assert(0);
            }
          } else if (reg->isfreg()) {
            if (auto ptr = value->getField<float>()) {
              if (*ptr == .0f) {
                Reg* rs = mana()->vreg(reg->dtype(), reg->sizeOf());
                if (reg->sizeOf() == 4) {
                  builder.newInst(new Target::FMVWX(rs, ZERO));
                } else if (reg->sizeOf() == 8) {
                  builder.newInst(new Target::FMVDX(rs, ZERO));
                } else {
                  assert(0);
                }
                (*it)->replace(reg, rs);
              } else {
                Reg* rt = mana()->vreg(Reg::XREG, reg->sizeOf());
                Reg* rs = mana()->vreg(reg->dtype(), reg->sizeOf());
                builder.newInst(new Pseudo::LI(rt, Util::floatToI32(*ptr)));
                if (reg->sizeOf() == 4) {
                  builder.newInst(new Target::FMVWX(rs, rt));
                } else if (reg->sizeOf() == 8) {
                  builder.newInst(new Target::FMVDX(rs, rt));
                } else {
                  assert(0);
                }
                (*it)->replace(reg, rs);
              }
            } else {
              assert(0);
            }
          } else {
            assert(0);
          }
        }
        assert(!def);
      }
      for (auto [value, reg] : mana()->allocaReg()) {
        bool def = false;
        bool use = false;
        for (Reg* d : (*it)->defRegs())
          if (reg == d) def = true;
        for (Reg* u : (*it)->useRegs())
          if (reg == u) use = true;
        if (use) {
          builder.set(block.get(), it);
          Reg* rs = mana()->vreg(reg->dtype(), reg->sizeOf());
          builder.newInst(new Pseudo::LoadStackAddr(rs, _stack_info[reg]));
          (*it)->replace(reg, rs);
        }
        assert(!def);
      }
      for (auto [value, reg] : mana()->globalReg()) {
        bool def = false;
        bool use = false;
        for (Reg* d : (*it)->defRegs())
          if (reg == d) def = true;
        for (Reg* u : (*it)->useRegs())
          if (reg == u) use = true;
        if (use) {
          builder.set(block.get(), it);
          Reg* rs = mana()->vreg(reg->dtype(), reg->sizeOf());
          builder.newInst(new Pseudo::LA(rs, value->name()));
          (*it)->replace(reg, rs);
        }
        assert(!def);
      }
    }
  }
}

void Function::initCalleeSaveReg(const std::unordered_set<Reg*>& callee_save_regs) {
  _prologue_stack.clear();
  newPrologueStackObject(S0->sizeOf());
  for (Reg* reg : callee_save_regs) {
    newPrologueStackObject(reg->sizeOf());
  }
}

void Function::scheduleCalleeStack() {
  auto calcStackObjectHeuristic = [](StackObject* stack_object) -> size_t {
    size_t heuristic = 0;
    if (stack_object->size() == 4) heuristic += 1;
    if (stack_object->size() == 8) heuristic += 2;
    return heuristic;
  };
  std::sort(_callee_stack.begin(), _callee_stack.end(), [&](StackObject* lhs, StackObject* rhs) -> bool {
    return calcStackObjectHeuristic(lhs) > calcStackObjectHeuristic(rhs);
  });
}

void Function::initStackOffset() {
  _prologue_stack_size = 0;
  _callee_stack_size = 0;
  int32_t offset = 0;
  for (auto& stack_object : prologueStack()) {
    _prologue_stack_size += stack_object->size();
    offset -= stack_object->size();
    stack_object->setBase(S0);
    stack_object->setOffset(offset);
  }
  for (auto& stack_object : calleeStack()) {
    _callee_stack_size += stack_object->size();
    offset -= stack_object->size();
    stack_object->setBase(S0);
    stack_object->setOffset(offset);
  }
}

size_t Function::stackSize() {
  size_t size = prologueStackSize() + calleeStackSize() + stackArgSize();
  return align(size, 16);
}

void Function::addCode(const std::unordered_set<Reg*>& regs) {
  // RISCVBuilder builder;
  // size_t index = 0;
  // for (Reg* reg : regs) {
  //   index++;
  //   builder.set(_entry, _entry->insts().begin());
  //   builder.newInst(new Pseudo::StoreStack(reg, prologueStack()[index].get()));
  //   for (auto exit : _exits) {
  //     builder.set(exit, std::prev(exit->insts().end()));
  //     builder.newInst(new Pseudo::LoadStack(reg, prologueStack()[index].get()));
  //   }
  // }
}

void Function::initStackPointer(const std::unordered_set<Reg*>& regs) {
  if (validShortImm(stackSize())) {
    auto entry_it = _entry->insts().begin();
    _entry->insts().emplace(entry_it, new Target::ADDI(SP, SP, -stackSize()));
    _entry->insts().emplace(entry_it, new Target::SD(SP, S0, stackSize() - 8));
    _entry->insts().emplace(entry_it, new Target::ADDI(S0, SP, stackSize()));
    size_t index = 0;
    for (Reg* reg : regs) {
      index++;
      _entry->insts().emplace(entry_it, new Pseudo::StoreStack(reg, prologueStack()[index].get()));
      for (auto e : _exits) {
        auto eit = std::prev(e->insts().end());
        e->insts().emplace(eit, new Pseudo::LoadStack(reg, prologueStack()[index].get()));
      }
    }
    for (auto e : _exits) {
      auto eit = std::prev(e->insts().end());
      e->insts().emplace(eit, new Target::LD(S0, SP, stackSize() - 8));
      e->insts().emplace(eit, new Target::ADDI(SP, SP, +stackSize()));
    }
  } else {
    auto entry_it = _entry->insts().begin();
    _entry->insts().emplace(entry_it, new Target::ADDI(SP, SP, -8));
    _entry->insts().emplace(entry_it, new Target::SD(SP, S0, 0));
    _entry->insts().emplace(entry_it, new Target::ADDI(S0, SP, 8));
    _entry->insts().emplace(entry_it, new Pseudo::LI(T0, -stackSize() + 8));
    _entry->insts().emplace(entry_it, new Target::ADD(SP, SP, T0));
    size_t index = 0;
    for (Reg* reg : regs) {
      index++;
      _entry->insts().emplace(entry_it, new Pseudo::StoreStack(reg, prologueStack()[index].get()));
      for (auto e : _exits) {
        auto eit = std::prev(e->insts().end());
        e->insts().emplace(eit, new Pseudo::LoadStack(reg, prologueStack()[index].get()));
      }
    }
    for (auto e : _exits) {
      auto eit = std::prev(e->insts().end());
      e->insts().emplace(eit, new Pseudo::LI(T0, stackSize() - 8));
      e->insts().emplace(eit, new Target::ADD(SP, SP, T0));
      e->insts().emplace(eit, new Target::LD(S0, SP, 0));
      e->insts().emplace(eit, new Target::ADDI(SP, SP, 8));
      // e->insts().emplace(eit, new Target::LD(S0, SP, stackSize() - 8));
      // e->insts().emplace(eit, new Target::ADDI(SP, SP, stackSize()));
    }
    // for (auto e : _exits) {
    //   auto eit = std::prev(e->insts().end());
    //   e->insts().emplace(entry_it, new Pseudo::LI(T0, stackSize()));
    //   e->insts().emplace(eit, new Target::ADD(SP, SP, T0));
    // }
  }
}

void Function::eliminateMove() {
  for (auto& block : _blocks) {
    for (auto it = block->insts().begin(); it != block->insts().end();) {
      if (auto mv = dynamic_cast<RISCV::Target::ADDI*>(it->get())) {
        if (mv->imm() == 0 && mv->rd() == mv->rs1()) {
          it = block->insts().erase(it);
          continue;
        }
      }
      if (auto fmv = dynamic_cast<RISCV::Target::FSGNJS*>(it->get())) {
        if (fmv->rs1() == fmv->rs2() && fmv->rd() == fmv->rs1()) {
          it = block->insts().erase(it);
          continue;
        }
      }
      it = std::next(it);
    }
  }
}

void Function::calcLive() {
  std::queue<std::pair<Block*, Reg*>> update;
  for (auto& block : blocks()) {
    block->liveUse().clear();
    block->liveDef().clear();
    for (auto it = block->insts().rbegin(); it != block->insts().rend(); ++it) {
      for (auto reg : (*it)->defRegs())
        if (reg->isnode()) {
          block->liveUse().erase(reg);
          block->liveDef().insert(reg);
        }
      for (auto reg : (*it)->useRegs())
        if (reg->isnode()) {
          block->liveDef().erase(reg);
          block->liveUse().insert(reg);
        }
    }
    for (auto reg : block->liveUse()) update.emplace(block.get(), reg);
    block->liveIn() = block->liveUse();
    block->liveOut().clear();
  }
  while (!update.empty()) {
    auto block = update.front().first;
    auto reg = update.front().second;
    update.pop();
    for (auto pred : block->preds()) {
      if (!pred->liveOut().count(reg)) {
        pred->liveOut().insert(reg);
        if (!pred->liveDef().count(reg) && !pred->liveIn().count(reg)) {
          pred->liveIn().insert(reg);
          update.emplace(pred, reg);
        }
      }
    }
  }
}
void Function::eraseUnreachableBB(){
  for(auto bb=blocks().begin();bb!=blocks().end();){
    if(bb->get()->preds().empty()&&bb->get()!=this->entry()){
      // TODO
      bb->get()->insts().clear();
      bb=blocks().erase(bb);
    }
    else{
      bb++;
    }
  }
}
void Function::basicblockReorder(){
  while(true){
    bool flag=false;
    for(auto it=this->blocks().begin();it!=this->blocks().end();it++){
      if(it==this->blocks().begin())continue;
      auto pred=std::prev(it);
      if(it->get()->preds().count(pred->get()))continue;
      for(auto pred:it->get()->preds()){
        bool flag1=false;
        for(auto succOfPred:pred->succs()){
          if(std::find(succOfPred->preds().begin(),succOfPred->preds().end(),pred)!=succOfPred->preds().end()){
            flag1=true;
            break;
          }
        }
        if(flag1)continue;

        // reorder
        bool flag2=false;
        for(auto itOfpred=this->blocks().begin();itOfpred!=this->blocks().end();itOfpred++){
          if(itOfpred->get()==pred){
            std::advance(itOfpred,1);
            auto mem=it->release();
            this->blocks().emplace(itOfpred,mem);
            this->blocks().erase(it);
            flag2=true;
            break;
          }
        }
        if(flag2){
          flag=true;
          break;
        }
      }
      if(flag)break;
    }
    if(!flag)break;
  }
}
/// @brief Block
Block::Block(Function* function, const std::string& name) : _heuristic(1.0), _function(function), _name(name) {
}

Function* Block::function() {
  return _function;
}

std::string Block::name() {
  return _name;
}

double Block::heuristic() {
  return _heuristic;
}

std::list<std::unique_ptr<Inst>>& Block::insts() {
  return _insts;
}

void Block::instSelect(IR::BasicBlock* basic_block) {
  Mana* mana = _function->mana();
  RISCVBuilder builder(this, this->insts().end());
  for (auto& instruction : basic_block->instructions()) {
    if (auto ret = dynamic_cast<IR::RetInst*>(instruction.get())) {
      if (!ret->retValue()->type()->isVoid()) {
        Reg* reg = mana->vreg(ret->retValue());
        if (reg->isxreg())
          builder.newMove(A0, reg);
        else if (reg->isfreg())
          builder.newMove(FA0, reg);
        else
          assert(0);
      }
      builder.newInst(new Target::JALR(ZERO, RA, 0));
    } else if (auto jmp = dynamic_cast<IR::JmpInst*>(instruction.get())) {
      auto dest = jmp->dest();
      builder.newInst(new Pseudo::J(function()->blockInfo()[dest], function()->blockInfo()[dest]->name()));
      succs().emplace(function()->blockInfo()[dest]);
      function()->blockInfo()[dest]->preds().emplace(this);
    } else if (auto alloca = dynamic_cast<IR::AllocaInst*>(instruction.get())) {
      Reg* reg = mana->vreg(alloca);
      StackObject* stack_object = function()->newCalleeStackObject(alloca->type()->deref(1)->sizeOf());
      function()->stackInfo()[reg] = stack_object;
    } else if (auto load = dynamic_cast<IR::LoadInst*>(instruction.get())) {
      auto rd = mana->vreg(load);
      auto rs1 = mana->vreg(load->addr());
      if (mana->isAlloca(rs1))
        builder.newInst(new Pseudo::LoadStack(rd, function()->stackInfo()[rs1]));
      else
        builder.newLoad(rd, rs1, 0);
    } else if (auto store = dynamic_cast<IR::StoreInst*>(instruction.get())) {
      auto rs1 = mana->vreg(store->addr());
      auto rs2 = mana->vreg(store->value());
      if (mana->isAlloca(rs1))
        builder.newInst(new Pseudo::StoreStack(rs2, function()->stackInfo()[rs1]));
      else
        builder.newStore(rs1, rs2, 0);
    } else if (auto addradd = dynamic_cast<IR::AddrAddInst*>(instruction.get())) {
      Reg* rd = mana->vreg(addradd);
      Reg* rs1 = mana->vreg(addradd->addr());
      if (auto coffset = dynamic_cast<IR::Constant*>(addradd->offset());
          coffset && validShortImm(*coffset->getField<int32_t>())) {
        int32_t imm = *coffset->getField<int32_t>();
        if (rd->sizeOf() == 4)
          builder.newInst(new Target::ADDIW(rd, rs1, imm));
        else if (rd->sizeOf() == 8)
          builder.newInst(new Target::ADDI(rd, rs1, imm));
        else
          assert(0);
      } else {
        Reg* rs2 = mana->vreg(addradd->offset());
        builder.newInst(new Target::ADD(rd, rs1, rs2));
      }
    } else if (auto addrderefadd = dynamic_cast<IR::AddrDerefAddInst*>(instruction.get())) {
      Reg* rd = mana->vreg(addrderefadd);
      Reg* rs1 = mana->vreg(addrderefadd->addr());
      if (auto coffset = dynamic_cast<IR::Constant*>(addrderefadd->offset());
          coffset && validShortImm(*coffset->getField<int32_t>())) {
        int32_t imm = *coffset->getField<int32_t>();
        if (rd->sizeOf() == 4)
          builder.newInst(new Target::ADDIW(rd, rs1, imm));
        else if (rd->sizeOf() == 8)
          builder.newInst(new Target::ADDI(rd, rs1, imm));
        else
          assert(0);
      } else {
        Reg* rs2 = mana->vreg(addrderefadd->offset());
        builder.newInst(new Target::ADD(rd, rs1, rs2));
      }
    } else if (auto phi = dynamic_cast<IR::PhiInst*>(instruction.get())) {
    } else if (auto call = dynamic_cast<IR::CallInst*>(instruction.get())) {
      auto callee = call->callee();
      size_t arg_xreg_num = 0;
      size_t arg_freg_num = 0;
      int32_t offset = 0;
      for (auto& argument : call->arguments()) {
        Reg* reg = mana->vreg(argument->value());
        if (reg->isxreg()) {
          if (arg_xreg_num < ARG_XREG_NUM) {
            builder.newMove(ARG_XREG[arg_xreg_num], reg);
            arg_xreg_num++;
          } else {
            offset = align(offset, reg->sizeOf());
            builder.newStore(SP, reg, offset);
            offset += reg->sizeOf();
            arg_xreg_num++;
          }
        } else if (reg->isfreg()) {
          if (arg_freg_num < ARG_FREG_NUM) {
            builder.newMove(ARG_FREG[arg_freg_num], reg);
            arg_freg_num++;
          } else {
            offset = align(offset, reg->sizeOf());
            builder.newStore(SP, reg, offset);
            offset += reg->sizeOf();
            arg_freg_num++;
          }
        } else {
          assert(0);
        }
      }
      _function->updateStackArgSize(offset);
      builder.newInst(new Pseudo::CALL(callee->name(), arg_xreg_num, arg_freg_num));
      if (!call->type()->isVoid()) {
        Reg* reg = mana->vreg(call);
        if (reg->isxreg())
          builder.newMove(reg, A0);
        else if (reg->isfreg())
          builder.newMove(reg, FA0);
        else
          assert(0);
      }
    } else if (auto unary = dynamic_cast<IR::UnaryInst*>(instruction.get())) {
      auto rd = mana->vreg(unary);
      auto rs1 = mana->vreg(unary->rhs());
      switch (unary->itype()) {
        case IR::FNEG: {
          if (rd->sizeOf() == 4)
            builder.newInst(new Target::FSGNJNS(rd, rs1, rs1));
          else if (rd->sizeOf() == 8)
            builder.newInst(new Target::FSGNJND(rd, rs1, rs1));
          else
            assert(0);
        } break;
        case IR::ZEXT: {
          builder.newMove(rd, rs1);
        } break;
        case IR::FPTOSI: {
          Reg* t = mana->vreg(Reg::XREG, 8);
          builder.newInst(new Target::ADDI(t, ZERO, 1));
          builder.newInst(new Pseudo::FSRM(t, t));
          builder.newInst(new Target::FCVTWS(rd, rs1));
          builder.newInst(new Pseudo::FSRM(t, t));
        } break;
        case IR::SITOFP: {
          builder.newInst(new Target::FCVTSW(rd, rs1));
        } break;
        case IR::PTRTOINT: {
          builder.newMove(rd, rs1);
        } break;
        case IR::INTTOPTR: {
          builder.newMove(rd, rs1);
        } break;
        default: {
          assert(0);
        } break;
      }
    } else if (auto binary = dynamic_cast<IR::BinaryInst*>(instruction.get())) {
      switch (binary->itype()) {
        case IR::ADD: {
          auto rd = mana->vreg(binary);
          if (auto clhs = dynamic_cast<IR::Constant*>(binary->lhs());
              clhs && validShortImm(clhs->getField<int32_t>() ? *clhs->getField<int32_t>() : *clhs->getField<bool>())) {
            auto rs1 = mana->vreg(binary->rhs());
            int32_t imm = clhs->getField<int32_t>() ? *clhs->getField<int32_t>() : *clhs->getField<bool>();
            if (rd->sizeOf() == 4)
              builder.newInst(new Target::ADDIW(rd, rs1, imm));
            else if (rd->sizeOf() == 8)
              builder.newInst(new Target::ADDI(rd, rs1, imm));
            else
              assert(0);
          } else if (auto crhs = dynamic_cast<IR::Constant*>(binary->rhs());
                     crhs &&
                     validShortImm(crhs->getField<int32_t>() ? *crhs->getField<int32_t>() : *crhs->getField<bool>())) {
            auto rs1 = mana->vreg(binary->lhs());
            int32_t imm = crhs->getField<int32_t>() ? *crhs->getField<int32_t>() : *crhs->getField<bool>();
            if (rd->sizeOf() == 4)
              builder.newInst(new Target::ADDIW(rd, rs1, imm));
            else if (rd->sizeOf() == 8)
              builder.newInst(new Target::ADDI(rd, rs1, imm));
            else
              assert(0);
          } else {
            auto rs1 = mana->vreg(binary->lhs());
            auto rs2 = mana->vreg(binary->rhs());
            if (rd->sizeOf() == 4)
              builder.newInst(new Target::ADDW(rd, rs1, rs2));
            else if (rd->sizeOf() == 8)
              builder.newInst(new Target::ADD(rd, rs1, rs2));
            else
              assert(0);
          }
        } break;
        case IR::FADD: {
          auto rd = mana->vreg(binary);
          auto rs1 = mana->vreg(binary->lhs());
          auto rs2 = mana->vreg(binary->rhs());
          if (rd->sizeOf() == 4)
            builder.newInst(new Target::FADDS(rd, rs1, rs2));
          else if (rd->sizeOf() == 8)
            builder.newInst(new Target::FADDD(rd, rs1, rs2));
          else
            assert(0);
        } break;
        case IR::SUB: {
          auto rd = mana->vreg(binary);
          if (auto crhs = dynamic_cast<IR::Constant*>(binary->rhs());
              crhs && validShortImm(-*crhs->getField<int32_t>())) {
            auto rs1 = mana->vreg(binary->lhs());
            int32_t imm = -*crhs->getField<int32_t>();
            if (rd->sizeOf() == 4)
              builder.newInst(new Target::ADDIW(rd, rs1, imm));
            else if (rd->sizeOf() == 8)
              builder.newInst(new Target::ADDI(rd, rs1, imm));
            else
              assert(0);
          } else {
            auto rs1 = mana->vreg(binary->lhs());
            auto rs2 = mana->vreg(binary->rhs());
            if (rd->sizeOf() == 4)
              builder.newInst(new Target::SUBW(rd, rs1, rs2));
            else if (rd->sizeOf() == 8)
              builder.newInst(new Target::SUB(rd, rs1, rs2));
            else
              assert(0);
          }
        } break;
        case IR::FSUB: {
          auto rd = mana->vreg(binary);
          auto rs1 = mana->vreg(binary->lhs());
          auto rs2 = mana->vreg(binary->rhs());
          if (rd->sizeOf() == 4)
            builder.newInst(new Target::FSUBS(rd, rs1, rs2));
          else if (rd->sizeOf() == 8)
            builder.newInst(new Target::FSUBD(rd, rs1, rs2));
          else
            assert(0);
        } break;
        case IR::MUL: {
          // TODO fast mul
          auto rd = mana->vreg(binary);
          if (auto clhs = dynamic_cast<IR::Constant*>(binary->lhs())) {
            auto rs1 = mana->vreg(binary->rhs());
            int32_t sign = clhs->getField<int32_t>() ? *clhs->getField<int32_t>() : *clhs->getField<bool>();
            if (sign == 0) {
              builder.newMove(rd, ZERO);
            } else if (sign == 1) {
              builder.newMove(rd, rs1);
            } else {
              int32_t imm = abs(sign);
              size_t shift = 0;
              while (!(imm & 1)) {
                shift++;
                imm >>= 1;
              }
              if (imm == 1) {
                if (rd->sizeOf() == 4)
                  builder.newInst(new Target::SLLIW(rd, rs1, shift));
                else if (rd->sizeOf() == 8)
                  builder.newInst(new Target::SLLI(rd, rs1, shift));
                else
                  assert(0);
                if (sign < 0) {
                  if (rd->sizeOf() == 4)
                    builder.newInst(new Target::SUBW(rd, ZERO, rd));
                  else if (rd->sizeOf() == 8)
                    builder.newInst(new Target::SUB(rd, ZERO, rd));
                  else
                    assert(0);
                }
              } else {
                auto rs2 = mana->vreg(binary->lhs());
                if (rd->sizeOf() == 4)
                  builder.newInst(new Target::MULW(rd, rs1, rs2));
                else if (rd->sizeOf() == 8)
                  builder.newInst(new Target::MUL(rd, rs1, rs2));
                else
                  assert(0);
              }
            }
          } else if (auto crhs = dynamic_cast<IR::Constant*>(binary->rhs())) {
            auto rs1 = mana->vreg(binary->lhs());
            int32_t sign = crhs->getField<int32_t>() ? *crhs->getField<int32_t>() : *crhs->getField<bool>();
            if (sign == 0) {
              builder.newMove(rd, ZERO);
            } else if (sign == 1) {
              builder.newMove(rd, rs1);
            } else if (sign == -1) {
              if (rd->sizeOf() == 4)
                builder.newInst(new Target::SUBW(rd, ZERO, rs1));
              else if (rd->sizeOf() == 8)
                builder.newInst(new Target::SUB(rd, ZERO, rs1));
              else
                assert(0);
            } else {
              int32_t imm = abs(sign);
              size_t shift = 0;
              while (!(imm & 1)) {
                shift++;
                imm >>= 1;
              }
              if (imm == 1) {
                if (rd->sizeOf() == 4)
                  builder.newInst(new Target::SLLIW(rd, rs1, shift));
                else if (rd->sizeOf() == 8)
                  builder.newInst(new Target::SLLI(rd, rs1, shift));
                else
                  assert(0);
                if (sign < 0) {
                  if (rd->sizeOf() == 4)
                    builder.newInst(new Target::SUBW(rd, ZERO, rd));
                  else if (rd->sizeOf() == 8)
                    builder.newInst(new Target::SUB(rd, ZERO, rd));
                  else
                    assert(0);
                }
              } else {
                auto rs2 = mana->vreg(binary->rhs());
                if (rd->sizeOf() == 4)
                  builder.newInst(new Target::MULW(rd, rs1, rs2));
                else if (rd->sizeOf() == 8)
                  builder.newInst(new Target::MUL(rd, rs1, rs2));
                else
                  assert(0);
              }
            }
          } else {
            auto rs1 = mana->vreg(binary->lhs());
            auto rs2 = mana->vreg(binary->rhs());
            if (rd->sizeOf() == 4)
              builder.newInst(new Target::MULW(rd, rs1, rs2));
            else if (rd->sizeOf() == 8)
              builder.newInst(new Target::MUL(rd, rs1, rs2));
            else
              assert(0);
          }
        } break;
        case IR::FMUL: {
          auto rd = mana->vreg(binary);
          auto rs1 = mana->vreg(binary->lhs());
          auto rs2 = mana->vreg(binary->rhs());
          if (rd->sizeOf() == 4)
            builder.newInst(new Target::FMULS(rd, rs1, rs2));
          else if (rd->sizeOf() == 8)
            builder.newInst(new Target::FMULD(rd, rs1, rs2));
          else
            assert(0);
        } break;
        case IR::SDIV: {
          // TODO fast div https://zhuanlan.zhihu.com/p/571939337
          auto rd = mana->vreg(binary);
          // if (auto crhs = dynamic_cast<IR::Constant*>(binary->rhs())) {
          //   auto rs1 = mana->vreg(binary->lhs());
          //   int32_t sign = *crhs->getField<int32_t>();
          //   if (sign == 1) {
          //     builder.newMove(rd, rs1);
          //   } else if (sign == -1) {
          //     if (rd->sizeOf() == 4)
          //       builder.newInst(new Target::SUBW(rd, ZERO, rs1));
          //     else if (rd->sizeOf() == 8)
          //       builder.newInst(new Target::SUB(rd, ZERO, rs1));
          //     else
          //       assert(0);
          //   } else {
          //     int32_t imm = abs(sign);
          //     size_t shift = 0;
          //     while (!(imm & 1)) {
          //       shift++;
          //       imm >>= 1;
          //     }
          //     if (imm == 1) {
          //       if (rd->sizeOf() == 4) {
          //         Reg* t = mana->vreg(rd->dtype(), rd->sizeOf());
          //         builder.newInst(new Target::SRLIW(t, rd, 31));
          //         builder.newInst(new Target::SRAIW(rd, rs1, shift));
          //         builder.newInst(new Target::ADDW(rd, rd, t));
          //       } else if (rd->sizeOf() == 8) {
          //         Reg* t = mana->vreg(rd->dtype(), rd->sizeOf());
          //         builder.newInst(new Target::SRLI(t, rd, 63));
          //         builder.newInst(new Target::SRAI(rd, rs1, shift));
          //         builder.newInst(new Target::ADD(rd, rd, t));
          //       } else
          //         assert(0);
          //       if (sign < 0) {
          //         if (rd->sizeOf() == 4)
          //           builder.newInst(new Target::SUBW(rd, ZERO, rd));
          //         else if (rd->sizeOf() == 8)
          //           builder.newInst(new Target::SUB(rd, ZERO, rd));
          //         else
          //           assert(0);
          //       }
          //     } else {
          //       auto rs2 = mana->vreg(binary->rhs());
          //       if (rd->sizeOf() == 4)
          //         builder.newInst(new Target::DIVW(rd, rs1, rs2));
          //       else if (rd->sizeOf() == 8)
          //         builder.newInst(new Target::DIV(rd, rs1, rs2));
          //       else
          //         assert(0);
          //     }
          //   }
          // } else {
          auto rs1 = mana->vreg(binary->lhs());
          auto rs2 = mana->vreg(binary->rhs());
          if (rd->sizeOf() == 4)
            builder.newInst(new Target::DIVW(rd, rs1, rs2));
          else if (rd->sizeOf() == 8)
            builder.newInst(new Target::DIV(rd, rs1, rs2));
          else
            assert(0);
          // }
        } break;
        case IR::FDIV: {
          auto rd = mana->vreg(binary);
          auto rs1 = mana->vreg(binary->lhs());
          auto rs2 = mana->vreg(binary->rhs());
          if (rd->sizeOf() == 4)
            builder.newInst(new Target::FDIVS(rd, rs1, rs2));
          else if (rd->sizeOf() == 8)
            builder.newInst(new Target::FDIVD(rd, rs1, rs2));
          else
            assert(0);
        } break;
        case IR::SREM: {
          auto rd = mana->vreg(binary);
          auto rs1 = mana->vreg(binary->lhs());
          auto rs2 = mana->vreg(binary->rhs());
          if (rd->sizeOf() == 4)
            builder.newInst(new Target::REMW(rd, rs1, rs2));
          else if (rd->sizeOf() == 8)
            builder.newInst(new Target::REM(rd, rs1, rs2));
          else
            assert(0);
        } break;
        default: {
          assert(0);
        } break;
      }
    } else if (auto br = dynamic_cast<IR::BrInst*>(instruction.get())) {
      auto cond = br->cond();
      auto iftrue = br->iftrue();
      auto iffalse = br->iffalse();
      if (auto icmp = dynamic_cast<IR::IcmpInst*>(cond)) {
        Reg* rs1 = mana->vreg(icmp->lhs());
        Reg* rs2 = mana->vreg(icmp->rhs());
        switch (icmp->itype()) {
          case IR::IEQ: {
            builder.newInst(new Target::BEQ(rs1, rs2, function()->blockInfo()[iftrue]->name()));
          } break;
          case IR::INE: {
            builder.newInst(new Target::BNE(rs1, rs2, function()->blockInfo()[iftrue]->name()));
          } break;
          case IR::ISGT: {
            builder.newInst(new Target::BLT(rs2, rs1, function()->blockInfo()[iftrue]->name()));
          } break;
          case IR::ISGE: {
            builder.newInst(new Target::BGE(rs1, rs2, function()->blockInfo()[iftrue]->name()));
          } break;
          case IR::ISLT: {
            builder.newInst(new Target::BLT(rs1, rs2, function()->blockInfo()[iftrue]->name()));
          } break;
          case IR::ISLE: {
            builder.newInst(new Target::BGE(rs2, rs1, function()->blockInfo()[iftrue]->name()));
          } break;
          default: {
            assert(0);
          } break;
        }
        builder.newInst(new Pseudo::J(function()->blockInfo()[iffalse], function()->blockInfo()[iffalse]->name()));
      } else {
        Reg* rs1 = mana->vreg(cond);
        builder.newInst(new Target::BNE(rs1, ZERO, function()->blockInfo()[iftrue]->name()));
        builder.newInst(new Pseudo::J(function()->blockInfo()[iffalse], function()->blockInfo()[iffalse]->name()));
      }
      succs().emplace(function()->blockInfo()[iftrue]);
      function()->blockInfo()[iftrue]->preds().emplace(this);
      succs().emplace(function()->blockInfo()[iffalse]);
      function()->blockInfo()[iffalse]->preds().emplace(this);
    } else if (auto icmp = dynamic_cast<IR::IcmpInst*>(instruction.get())) {
      if (icmp->uses().size() == 1 && dynamic_cast<IR::BrInst*>(icmp->uses().front()->user())) continue;
      auto rd = mana->vreg(icmp);
      auto rs1 = mana->vreg(icmp->lhs());
      auto rs2 = mana->vreg(icmp->rhs());
      assert(rs1->sizeOf() == rs2->sizeOf());
      size_t size_of = rs1->sizeOf();
      if (size_of == 4)
        builder.newInst(new Target::SUBW(rd, rs1, rs2));
      else if (size_of == 8)
        builder.newInst(new Target::SUB(rd, rs1, rs2));
      else
        assert(0);
      switch (icmp->itype()) {
        case IR::IEQ: {
          builder.newInst(new Target::SLTIU(rd, rd, 1));
        } break;
        case IR::INE: {
          builder.newInst(new Target::SLTU(rd, ZERO, rd));
        } break;
        case IR::ISGT: {
          builder.newInst(new Target::SLT(rd, ZERO, rd));
        } break;
        case IR::ISGE: {
          builder.newInst(new Target::SLT(rd, rd, ZERO));
          builder.newInst(new Target::XORI(rd, rd, 1));
        } break;
        case IR::ISLT: {
          builder.newInst(new Target::SLT(rd, rd, ZERO));
        } break;
        case IR::ISLE: {
          builder.newInst(new Target::SLT(rd, ZERO, rd));
          builder.newInst(new Target::XORI(rd, rd, 1));
        } break;
        default: {
          assert(0);
        } break;
      }
    } else if (auto fcmp = dynamic_cast<IR::FcmpInst*>(instruction.get())) {
      auto rd = mana->vreg(fcmp);
      auto rs1 = mana->vreg(fcmp->lhs());
      auto rs2 = mana->vreg(fcmp->rhs());
      assert(rs1->sizeOf() == rs2->sizeOf());
      size_t size_of = rs1->sizeOf();
      switch (fcmp->itype()) {
        case IR::FOEQ: {
          if (size_of == 4)
            builder.newInst(new Target::FEQS(rd, rs1, rs2));
          else if (size_of == 8)
            builder.newInst(new Target::FEQD(rd, rs1, rs2));
          else
            assert(0);
        } break;
        case IR::FONE: {
          if (size_of == 4)
            builder.newInst(new Target::FEQS(rd, rs1, rs2));
          else if (size_of == 8)
            builder.newInst(new Target::FEQD(rd, rs1, rs2));
          else
            assert(0);
          builder.newInst(new Target::XORI(rd, rd, 1));
        } break;
        case IR::FOGT: {
          if (size_of == 4)
            builder.newInst(new Target::FLTS(rd, rs2, rs1));
          else if (size_of == 8)
            builder.newInst(new Target::FLTD(rd, rs2, rs1));
          else
            assert(0);
        } break;
        case IR::FOGE: {
          if (size_of == 4)
            builder.newInst(new Target::FLES(rd, rs2, rs1));
          else if (size_of == 8)
            builder.newInst(new Target::FLED(rd, rs2, rs1));
          else
            assert(0);
        } break;
        case IR::FOLT: {
          if (size_of == 4)
            builder.newInst(new Target::FLTS(rd, rs1, rs2));
          else if (size_of == 8)
            builder.newInst(new Target::FLTD(rd, rs1, rs2));
          else
            assert(0);
        } break;
        case IR::FOLE: {
          if (size_of == 4)
            builder.newInst(new Target::FLES(rd, rs1, rs2));
          else if (size_of == 8)
            builder.newInst(new Target::FLED(rd, rs1, rs2));
          else
            assert(0);
        } break;
        default: {
          assert(0);
        } break;
      }
    } else {
      assert(0);
    }
  }
}

std::unordered_set<Block*>& Block::preds() {
  return _preds;
}

std::unordered_set<Block*>& Block::succs() {
  return _succs;
}

std::unordered_set<Reg*>& Block::liveUse() {
  return _live_use;
}

std::unordered_set<Reg*>& Block::liveDef() {
  return _live_def;
}

std::unordered_set<Reg*>& Block::liveIn() {
  return _live_in;
}

std::unordered_set<Reg*>& Block::liveOut() {
  return _live_out;
}

void Block::calcLiveUseDef() {
  liveUse().clear();
  liveDef().clear();
  for (auto it = insts().rbegin(); it != insts().rend(); ++it) {
    for (auto reg : (*it)->defRegs())
      if (reg->isnode()) {
        liveUse().erase(reg);
        liveDef().insert(reg);
      }
    for (auto reg : (*it)->useRegs())
      if (reg->isnode()) {
        liveDef().erase(reg);
        liveUse().insert(reg);
      }
  }
}

void Block::initLiveInOut() {
  liveIn() = liveUse();
  liveOut().clear();
}

}  // namespace RISCV
