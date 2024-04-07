#ifndef __OPTIMIZE_LSLIVE_HPP__
#define __OPTIMIZE_LSLIVE_HPP__

#include "pass.hpp"

namespace Pass {

// struct ArrayElement {
//   Value* base;
//   size_t offset;
//   bool is_any;
// };

// Value* findArrayBase(IR::Value* addr) {
//   while (auto load = dynamic_cast<IR::LoadInst*>(addr)) {
//     addr = load->addr();
//   }
//   if (auto alloca = dynamic_cast<IR::AllocaInst*>(addr)) {
//     if (alloca->type()->isPointer())
//       for (auto use : alloca->uses())
//         if (auto store = dynamic_cast<IR::StoreInst*>(use->user())) addr = store->addr();
//     return addr;
//   } else if (auto gaddr = dynamic_cast<IR::GlobalAddr*>(addr))
//     return gaddr;
//   else
//     return nullptr;
// }

// ArrayElement findArrayElement(IR::Value* addr) {
//   if (dynamic_cast<IR::AllocaInst*>(addr)) {
//     return {addr, 0, false};
//   }
//   if (dynamic_cast<IR::GlobalAddr*>(addr)) {
//     return {addr, 0, false};
//   }
//   if (auto addrderefadd = dynamic_cast<IR::AddrDerefAddInst*>(addr)) {
//     auto array = findArrayElement(addrderefadd->addr());
//     if (auto coffset = dynamic_cast<IR::Constant*>(addrderefadd->offset()); coffset && !array.is_any) {
//       return {array.base, array.offset + *coffset->getField<int32_t>(), false};
//     } else {
//       return {array.base, 0, true};
//     }
//   }
//   if (auto addradd = dynamic_cast<IR::AddrAddInst*>(addr)) {
//     auto array = findArrayElement(addradd->addr());
//     if (auto coffset = dynamic_cast<IR::Constant*>(addradd->offset()); coffset && !array.is_any) {
//       return {array.base, array.offset + *coffset->getField<int32_t>(), false};
//     } else {
//       return {array.base, 0, true};
//     }
//   }
//   // size_t offset = 0;
//   // Value* base = findArrayBase(addr);
//   // bool is_any = false;
//   // if (auto addrderefadd = dynamic_cast<IR::AddrDerefAddInst*>(addr)) {
//   // if (auto coffset = dynamic_cast<IR::Constant*>(addrderefadd->offset())) {
//   // } else {
//   // is_any = false;
//   // }
//   // } else if (auto addradd = dynamic_cast<IR::AddrAddInst*>(addr)) {
//   // if (auto coffset = dynamic_cast<IR::Constant*>(addradd->offset())) {
//   // } else {
//   // is_any = false;
//   // }
//   // } else {
//   // }
// }

class LSLive : public FunctionPass {
public:
  std::unordered_map<IR::Value *, std::unordered_set<IR::Value *>> usedefchains;
  std::string_view name() override {
    return "LSLive";
  }
  std::pair<IR::Value *, size_t> getDef(IR::StoreInst *def) {
    if (auto i = dynamic_cast<IR::AddrDerefAddInst *>(def->addr())) {
      if (dynamic_cast<IR::AllocaInst *>(i->addr()) && dynamic_cast<IR::Constant *>(i->offset())) {
        auto coffset = *dynamic_cast<IR::Constant *>(i->offset())->getField<int32_t>();
        return {i->addr(), coffset};
      } else {
        return {nullptr, 0};
      }
    } else {
      return {nullptr, 0};
    }
  }
  std::pair<IR::Value *, size_t> getUse(IR::LoadInst *use) {
    if (auto i = dynamic_cast<IR::AddrDerefAddInst *>(use->addr())) {
      if (dynamic_cast<IR::AllocaInst *>(i->addr()) && dynamic_cast<IR::Constant *>(i->offset())) {
        auto coffset = *dynamic_cast<IR::Constant *>(i->offset())->getField<int32_t>();
        return {i->addr(), coffset};
      } else {
        return {nullptr, 0};
      }
    } else {
      return {nullptr, 0};
    }
  }

  void run(IR::Function *pass_unit) override {
    pass_unit->calcLive();
    // for (auto &basic_block : pass_unit->basicBlocks()) {
    //   for (auto defit = basic_block->instructions().begin(); defit != basic_block->instructions().end(); defit++) {
    //     if (auto def = dynamic_cast<IR::StoreInst *>(defit->get())) {
    //       auto cdef = getDef(def);
    //       for (auto useit = defit; useit != basic_block->instructions().end(); useit++) {
    //         if (auto use = dynamic_cast<IR::LoadInst *>(useit->get())) {
    //           auto cuse = getUse(use);
    //           if ()
    //         }
    //       }
    //     }
    //   }
    // }
    // for (auto &basic_block : pass_unit->basicBlocks()) {
    //       auto cdef = getDef(def);
    //       for (auto useit = defit; useit != basic_block->instructions().end(); useit++) {
    //         if (auto use = dynamic_cast<IR::LoadInst *>(useit->get())) {
    //           auto cuse = getUse(use);
    //           if (cdef == cuse) {
    //             usedefchains[use].insert(def);
    //           }
    //         }
    //         if (auto ndef = dynamic_cast<IR::StoreInst *>(useit->get())) {
    //           auto ndef_ = getDef(ndef);
    //           if (cdef == ndef_) {
    //             goto next;
    //           }
    //         }
    //       }
    //       for (auto use : basic_block->liveout) {
    //         if (cdef == use) {

    //         }
    //       }
    //     next:;
    //     }
    //   }
    // bool hasdef = false;
    // std::pair<IR::Value *, size_t> cdef;
    //   if (auto def = dynamic_cast<IR::StoreInst *>(instruction.get())) {
    //     hasdef = true;
    //     cdef = getDef(def);
    //   } else if (auto use = dynamic_cast<IR::LoadInst *>(instruction.get())) {
    //     if (hasdef) {
    //       std::pair<IR::Value *, size_t> cuse = getUse(use);
    //       // if (cdef == cuse)
    //       // defs[use].insert();
    //     }
    //   }
    // if (hasdef) {
    // }
    // }
  }
};

}  // namespace Pass

#endif
