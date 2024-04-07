#ifndef __ALIAS_ANALYSIS_HPP__
#define __ALIAS_ANALYSIS_HPP__
#include <stack>

#include "infrastructure.hpp"
#include "instruction.hpp"
#include "pass.hpp"
namespace Pass {
inline IR::Value* getOriginArray(IR::Value* ptr) {
  while (true) {
    if (auto load = dynamic_cast<IR::LoadInst*>(ptr)) {
      ptr = load->operand(0);
    } else {
      break;
    }
  }
  if (auto alloca = dynamic_cast<IR::AllocaInst*>(ptr)) {
    // It is must be args, we get the arg
    if (alloca->type()->isPointer())
      for (auto use : alloca->uses())
        if (auto store = dynamic_cast<IR::StoreInst*>(use->user())) ptr = store->operand(0);
    return ptr;
  } else if (auto gv = dynamic_cast<IR::GlobalAddr*>(ptr))
    return gv;
  else
    return nullptr;
}

inline bool isGlobal(IR::Value* val) {
  return dynamic_cast<IR::GlobalAddr*>(val);
}

inline bool isArray(IR::Value* val) {
  if (auto alloc = dynamic_cast<IR::AllocaInst*>(val); alloc && alloc->type()->deref(1)->isPointer()) return true;
  return false;
}

inline bool isLocal(IR::Value* val) {
  return !isGlobal(val) && !isArray(val);
}

// inline bool AliasAnalysis::isAliasByGVToArg(IR::GlobalAddr* gv, IR::AllocaInst* arg)
// {
//     std::vector<int> gvDim;
//     std::vector<int> argDim;
//     auto type = gv->type();
//     while(auto arrType = dynamic_cast<IR::ArrayType*>(type))
//     {
//         gvDim.push_back(arrType->getSize());
//         type = arrType->getInnerType();
//     }

//     type = arg->getAllocatedType()->getInnerType();
//     while(auto arrType = dynamic_cast<ArrayType*>(type))
//     {
//         argDim.push_back(arrType->getSize());
//         type = arrType->getInnerType();
//     }

//     for(auto gvIter = gvDim.rbegin(), argIter = argDim.rbegin();
//         gvIter != gvDim.rend() && argIter != argDim.rend(); gvIter++, argIter++)
//         if(*gvIter != *argIter)
//             return false;
//     return true;
// }

// inline bool AliasAnalysis::alias(IR::Value* array1, IR::Value* array2)
// {
//     // FIXME f(a, a) will faild
//     if ((isGlobal(array1) && isGlobal(array2)) || (isArray(array1) && isArray(array2)) || (isLocal(array1) &&
//     isLocal(array2)))
//         return array1 == array2;

//     if(auto gv1 = dynamic_cast<IR::GlobalAddr*>(array1))
//         if(auto arg2 = dynamic_cast<IR::AllocaInst*>(array2))
//             return isAliasByGVToArg(gv1, arg2);

//     if(auto gv2 = dynamic_cast<IR::GlobalAddr*>(array2))
//         if(auto arg1 = dynamic_cast<IR::AllocaInst*>(array1))
//             return isAliasByGVToArg(gv2, arg1);

//     return false;
// }

// inline bool AliasAnalysis::aliasAtCall(IR::Value* array, IR::CallInst* call)
// {
//     if(auto gv = dynamic_cast<<IR::GlobalAddr*>(array); gv
//         && call->getCallee()->getStoreGV().count(gv))
//         return true;
//     // for(auto arg : call->getArgs())
//     //     if(auto gep = dynamic_cast<GEPInst*>(arg); gep && alias(array, getOriginArray(gep)))
//     //         return true;
//     return false;
// }

};  // namespace Pass
#endif
