#include "core.hpp"

#include <algorithm>
#include <queue>

#include "global.hpp"
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
  for (auto& [name, value] : cu->globalVariableTable()) {
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
  // _vra(nullptr) {
  Block* entry = blocks().emplace_back(new Block(this, "entry_" + function->name())).get();
  // _vra = mana()->vreg(Reg::XREG, 8);
  // entry->insts().emplace_back(new Target::ADDI(vra(), RA, 0));
  // initArgs(entry, function);
  size_t cnt = 0;
  for (auto& bb : function->basicBlocks()) {
    IR::BasicBlock* irblock = bb.get();
    Block* block = blocks().emplace_back(new Block(this, function->name() + "_LL_" + std::to_string(cnt++))).get();
    blockInfo()[irblock] = block;
    irblockInfo()[block] = irblock;
  }
  for (auto& bb : function->basicBlocks()) {
    blockInfo()[bb.get()]->instSelect(bb.get());
    if (bb->isExit()) {
      exits.emplace_back(blockInfo()[bb.get()]);
    }
  }
  entry->succs().emplace(blockInfo()[function->entry()]);
  blockInfo()[function->entry()]->preds().emplace(entry);

  for (auto& block : blocks()) {
    for (auto it = block->insts().begin(); it != block->insts().end(); it++) {
      for (auto [c, reg] : mana()->constantReg()) {
        bool def = false;
        bool use = false;
        for (Reg* d : (*it)->defRegs())
          if (reg == d) def = true;

        for (Reg* u : (*it)->useRegs())
          if (reg == u) use = true;

        if (!use && !def) continue;
        
        if (use) {  //!
          Reg* t = mana()->vreg(reg->dtype(), reg->sizeOf());
          if (c->type()->isFloat()) {
            Reg* tt = mana()->vreg(Reg::XREG, reg->sizeOf());
            block->insts().emplace(
                it, new Pseudo::LI(tt, Util::floatToI32(*mana()->regConstant()[reg]->getField<float>())));
            block->insts().emplace(it, new Target::FMVWX(t, tt));
          } else {
            // block->insts().emplace(it, new Pseudo::LI(t, *c->getField<int32_t>()));
            // std::cout << mana()->regConstant()[reg]->getField<int32_t>() << "\n";
            if (mana()->regConstant()[reg]->getField<int32_t>())
              block->insts().emplace(it, new Pseudo::LI(t, *mana()->regConstant()[reg]->getField<int32_t>()));
            if (mana()->regConstant()[reg]->getField<bool>())
              block->insts().emplace(it, new Pseudo::LI(t, *mana()->regConstant()[reg]->getField<bool>()));
          }
          (*it)->replace(reg, t);
        }
        if (def) assert(0);
      }
      for (auto [a, reg] : mana()->allocaReg()) {
        bool def = false;
        bool use = false;
        for (Reg* d : (*it)->defRegs())
          if (reg == d) def = true;
        for (Reg* u : (*it)->useRegs())
          if (reg == u) use = true;
        if (!use && !def) continue;
        if (use) {  // TODO float
          Reg* t = mana()->vreg(reg->dtype(), reg->sizeOf());
          block->insts().emplace(it, new Pseudo::LoadStackAddr(t, stackInfo()[reg]));
          (*it)->replace(reg, t);
        }
        if (def) assert(0);
      }
      for (auto [p, reg] : mana()->paramReg()) {
        bool def = false;
        bool use = false;
        for (Reg* d : (*it)->defRegs())
          if (reg == d) def = true;
        for (Reg* u : (*it)->useRegs())
          if (reg == u) use = true;
        if (!use && !def) continue;
        if (use) {
          // std::cout << p->index() << "\n";
          if (p->atype() == IR::Argument::XARG) {
            if (p->index() < ARG_XREG_NUM) {
              (*it)->replace(reg, ARG_XREG[p->index()]);
            } else {
              Reg* ta = mana()->vreg(Reg::XREG, 8);
              Reg* t = mana()->vreg(reg->dtype(), reg->sizeOf());
              block->insts().emplace(it, new Pseudo::LoadStackAddr(ta, newCallerStackObject(t->sizeOf())));
              if (t->sizeOf() == 4) {
                block->insts().emplace(it, new Target::LW(t, ta, 0));
              } else if (t->sizeOf() == 8) {
                block->insts().emplace(it, new Target::LD(t, ta, 0));
              } else {
                assert(0);
              }
              (*it)->replace(reg, t);
            }
          } else {
            if (p->index() < ARG_FREG_NUM) {
              (*it)->replace(reg, ARG_FREG[p->index()]);
            } else {
              Reg* ta = mana()->vreg(Reg::XREG, 8);
              Reg* t = mana()->vreg(reg->dtype(), reg->sizeOf());
              block->insts().emplace(it, new Pseudo::LoadStackAddr(ta, newCallerStackObject(t->sizeOf())));
              if (t->sizeOf() == 4) {
                block->insts().emplace(it, new Target::FLW(t, ta, 0));
              } else if (t->sizeOf() == 8) {
                block->insts().emplace(it, new Target::FLD(t, ta, 0));
              } else {
                assert(0);
              }
              (*it)->replace(reg, t);
            }
          }
          // Reg* t = mana()->vreg(reg->dtype(), reg->sizeOf());
          // block->insts().emplace(it, new Pseudo::LA(t, mana()->regGlobal()[reg]->name()));
        }
        if (def) assert(0);
      }
      for (auto [g, reg] : mana()->globalReg()) {
        bool def = false;
        bool use = false;
        for (Reg* d : (*it)->defRegs())
          if (reg == d) def = true;
        for (Reg* u : (*it)->useRegs())
          if (reg == u) use = true;
        if (!use && !def) continue;
        if (use) {
          Reg* t = mana()->vreg(reg->dtype(), reg->sizeOf());
          block->insts().emplace(it, new Pseudo::LA(t, mana()->regGlobal()[reg]->name()));
          (*it)->replace(reg, t);
        }
        if (def) assert(0);
      }
    }
  }
  // initConstants(entry);
  // initGlobals(entry);
}

std::string Function::name() {
  return _name;
}

Program* Function::program() {
  return _program;
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

std::vector<std::unique_ptr<StackObject>>& Function::callerStack() {
  return _caller_stack;
}

std::vector<std::unique_ptr<StackObject>>& Function::prologueStack() {
  return _prologue_stack;
}

std::vector<std::unique_ptr<StackObject>>& Function::calleeStack() {
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

// Reg* Function::vra() {
//   return _vra;
// }

std::list<std::unique_ptr<Block>>& Function::blocks() {
  return _blocks;
}

StackObject* Function::newCallerStackObject(size_t size) {
  callerStack().emplace_back(new StackObject(size));
  return callerStack().back().get();
}

StackObject* Function::newPrologueStackObject(size_t size) {
  prologueStack().emplace_back(new StackObject(size));
  return prologueStack().back().get();
}

StackObject* Function::newCalleeStackObject(size_t size) {
  calleeStack().emplace_back(new StackObject(size));
  return calleeStack().back().get();
}

void Function::updateStackArgSize(IR::Function* callee) {
  size_t arg_xreg_num = 0;
  size_t arg_freg_num = 0;
  size_t spill_size = 0;
  for (auto& param : callee->arguments()) {
    Reg* reg = mana()->vreg(param.get());
    if (reg->isxreg() && arg_xreg_num < ARG_XREG_NUM)
      arg_xreg_num++;
    else if (reg->isfreg() && arg_freg_num < ARG_FREG_NUM)
      arg_freg_num++;
    else  // spill_size += reg->sizeOf();
      spill_size += 8;
  }
  _stack_arg_size = std::max(stackArgSize(), spill_size);
}

Block* Function::newBlock(Block* block) {
  blocks().emplace_back(block);
  return blocks().back().get();
}

// void Function::initCallerStack(IR::Function* function) {
//   size_t arg_xreg_num = 0;
//   size_t arg_freg_num = 0;
//   // int32_t offset = 0;
//   for (auto& param : function->params()) {
//     Reg* reg = mana()->vreg(param.get());
//     if (reg->isxreg() && arg_xreg_num < ARG_XREG_NUM)
//       arg_xreg_num++;
//     else if (reg->isfreg() && arg_freg_num < ARG_FREG_NUM)
//       arg_freg_num++;
//     else {
//       // offset += reg->sizeOf();
//     }
//   }
// }

void Function::initArgs(Block* entry, IR::Function* function) {
  size_t arg_xreg_num = 0;
  size_t arg_freg_num = 0;
  for (auto& param : function->arguments()) {
    Reg* reg = mana()->vreg(param.get());
    if (reg->isxreg() && arg_xreg_num < ARG_XREG_NUM) {
      entry->newMove(reg, ARG_XREG[arg_xreg_num]);
      arg_xreg_num++;
    } else if (reg->isfreg() && arg_freg_num < ARG_FREG_NUM) {
      entry->newMove(reg, ARG_FREG[arg_freg_num]);
      arg_freg_num++;
    } else {
      StackObject* stack_object = newCallerStackObject(reg->sizeOf());
      entry->newInst(new Pseudo::LoadStack(reg, stack_object));
      // entry->newInst(new Pseudo::StoreStack(reg, ));
    }
  }
}

void Function::initGlobals(Block* entry) {
  for (auto [g, reg] : mana()->globalReg()) {
    assert(reg->isxreg());
    entry->insts().emplace_back(new Pseudo::LA(reg, g->name()));
  }
}

void Function::initConstants(Block* entry) {
  // unused
  for (auto [c, reg] : mana()->constantReg())
    if (reg->isxreg())
      entry->insts().emplace_back(new Pseudo::LI(reg, *c->getField<int32_t>()));
    else if (reg->isfreg())  // TODO
      entry->insts().emplace_back(new Pseudo::LI(reg, Util::floatToI32(*c->getField<float>())));
    else
      assert(0);
}

// void Function::initFP(Block* entry) {
//   auto it = entry->insts().begin();
//   entry->newInst(new Target::ADDI(FP, SP, ));
// }

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

void Function::loadStoreCalleeSaveReg(Block* entry, std::vector<Block*>& exits,
                                      const std::unordered_set<Reg*> callee_save_regs) {
  auto entry_it = entry->insts().begin();
  // auto exit_it = std::prev(exit->insts().end());
  newPrologueStackObject(S0->sizeOf());  // 一定是第一个
  // entry->insts().emplace(entry_it, new Target::SD(SP, S0, 0));
  for (Reg* reg : callee_save_regs) {
    StackObject* stack_object = newPrologueStackObject(reg->sizeOf());
    entry->insts().emplace(entry_it, new Pseudo::StoreStack(reg, stack_object));
    for (auto e : exits) {
      auto eit = std::prev(e->insts().end());
      e->insts().emplace(eit, new Pseudo::LoadStack(reg, stack_object));
    }
  }
  // exit->insts().emplace(exit_it, new Pseudo::LoadStack(S0, stack_object));
}

void Function::calcStackOffset() {
  _prologue_stack_size = 0;
  _caller_stack_size = 0;
  _callee_stack_size = 0;
  int32_t offset = 0;
  // std::cout << "in function " << name() << ":\n";
  // std::cout << "caller stack:\n";
  for (auto& stack_object : callerStack()) {
    _caller_stack_size += stack_object->size();
    stack_object->setBase(S0);
    stack_object->setOffset(offset);
    // offset += stack_object->size();
    offset += 8;
    // std::cout << stack_object->base()->name() << " " << stack_object->offset() << " " << stack_object->size() <<
    // "\n";
  }
  offset = 0;
  // std::cout << "prologue stack:\n";
  for (auto& stack_object : prologueStack()) {
    _prologue_stack_size += stack_object->size();
    offset -= stack_object->size();
    stack_object->setBase(S0);
    stack_object->setOffset(offset);
    // std::cout << stack_object->base()->name() << " " << stack_object->offset() << " " << stack_object->size() <<
    // "\n";
  }
  std::sort(_callee_stack.begin(), _callee_stack.end(), [&](const auto& l, const auto& r) -> bool {
    size_t w_l;
    if (l->size() == 8)
      w_l = 0;
    else if (l->size() == 4)
      w_l = 1;
    else
      w_l = 2;
    size_t w_r;
    if (r->size() == 8)
      w_r = 0;
    else if (r->size() == 4)
      w_r = 1;
    else
      w_r = 2;
    return w_l < w_r;
  });
  // std::cout << "callee stack:\n";
  for (auto& stack_object : calleeStack()) {
    _callee_stack_size += stack_object->size();
    offset -= stack_object->size();
    stack_object->setBase(S0);
    stack_object->setOffset(offset);
    // std::cout << stack_object->base()->name() << " " << stack_object->offset() << " " << stack_object->size() <<
    // "\n";
  }
}

size_t Function::stackSize() {
  size_t size = prologueStackSize() + calleeStackSize() + stackArgSize();
  if (size % 16) size = ((size / 16) + 1) * 16;
  return size;
}

void Function::prologue(Block* entry, std::vector<Block*>& exits) {
  // prologueStack().front()->setBase(SP);
  // prologueStack().front()->setOffset(stackSize() - 8);
  auto entry_it = entry->insts().begin();
  // auto exit_it = std::prev(exit->insts().end());
  if (validShortImm(stackSize())) {
    entry->insts().emplace(entry_it, new Target::SD(SP, S0, -8));
    entry->insts().emplace(entry_it, new Target::ADDI(S0, SP, 0));
    entry->insts().emplace(entry_it, new Target::ADDI(SP, SP, -stackSize()));
    for (auto e : exits) {
      auto eit = std::prev(e->insts().end());
      e->insts().emplace(eit, new Target::ADDI(SP, S0, 0));
      e->insts().emplace(eit, new Target::LD(S0, S0, -8));
    }
  } else {
    entry->insts().emplace(entry_it, new Target::SD(SP, S0, -8));
    entry->insts().emplace(entry_it, new Target::ADDI(S0, SP, 0));
    entry->insts().emplace(entry_it, new Pseudo::LI(SP, -stackSize()));
    entry->insts().emplace(entry_it, new Target::ADD(SP, S0, SP));
    for (auto e : exits) {
      auto eit = std::prev(e->insts().end());
      e->insts().emplace(eit, new Target::ADDI(SP, S0, 0));
      e->insts().emplace(eit, new Target::LD(S0, S0, -8));
    }
  }
  // for (auto it = entry->insts().begin(); it != entry->insts().end(); it++) {
  //   if (auto i = dynamic_cast<Pseudo::StoreStack*>(it->get())) {
  //     if (i->rs2() == S0) {
  //       auto nxt = std::next(it);
  //       entry->insts().emplace(nxt, new Target::ADDI(S0, SP, stackSize()));
  //       break;
  //     }
  //   }
  // }
}

/// @brief Block
Block::Block(Function* function, const std::string& name) : _function(function), _name(name), _heuristic(1.0) {
}

std::string Block::name() {
  return _name;
}

Function* Block::function() {
  return _function;
}

std::list<std::unique_ptr<Inst>>& Block::insts() {
  return _insts;
}

Inst* Block::newInst(Inst* inst) {
  insts().emplace_back(inst);
  return insts().back().get();
}

double Block::heuristic() {
  return _heuristic;
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

// void Function::updatePrologueStack(Block* entry, Block* exit, std::unordered_set<Reg*> callee_save_reg) {
//   // entry->newMove(FP, SP);
//   // entry->newInst();
//   size_t offset = 0;
//   for (Reg* reg : callee_save_reg) {
//     StackObject* stack_object = newPrologueStackObject(reg->sizeOf(), S0, offset);
//     offset += reg->sizeOf();
//     entry->insts().emplace_back(new Pseudo::StoreStack(reg, stack_object));
//   }
// }

}  // namespace RISCV
