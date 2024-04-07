#include "ConstFlod.hpp"
#include "instruction.hpp"
#include "simplifyInstruction.hpp"
#include "typesystem.hpp"
#include <cstdint>
namespace Pass{
  void ConstFlod::run(Function *pass_unit){
    for(auto &bb:pass_unit->basicBlocks()){
      // for(auto inst=bb->instructions().begin();inst!=bb->instructions().end();inst++){
      for(auto inst=bb->instructions().begin();inst!=bb->instructions().end();){
        if(auto binaryInst=dynamic_cast<BinaryInst*>(inst->get())){
          if(auto cf=constFlod(binaryInst);cf&&cf!=binaryInst){
            binaryInst->replaceAllUseWith(cf);
            binaryInst->unUseAll();
            inst=bb->instructions().erase(inst);
          }
          // simplifyInstruction
          else if(auto si=simplifyInstruction(binaryInst);si&&si!=binaryInst){
            binaryInst->replaceAllUseWith(si);
            binaryInst->unUseAll();
            inst=bb->instructions().erase(inst);
          }
          else{
            inst++;
          }
        }
        else if(auto icmpInst=dynamic_cast<IcmpInst*>(inst->get())){
          if(auto cf=constFlod(icmpInst);cf&&cf!=icmpInst){
            icmpInst->replaceAllUseWith(cf);
            icmpInst->unUseAll();
            inst=bb->instructions().erase(inst);
          }
          else if(auto si=simplifyInstruction(icmpInst);si&&si!=icmpInst){
            icmpInst->replaceAllUseWith(si);
            icmpInst->unUseAll();
            inst=bb->instructions().erase(inst);
          }
          else{
            inst++;
          }
        }
        else if(auto fcmpInst=dynamic_cast<FcmpInst*>(inst->get())){
          if(auto cf=constFlod(fcmpInst);cf&&cf!=fcmpInst){
            fcmpInst->replaceAllUseWith(cf);
            fcmpInst->unUseAll();
            inst=bb->instructions().erase(inst);
          }
          else{
            inst++;
          }
        }
        else if(auto unaryInst=dynamic_cast<UnaryInst*>(inst->get())){
          if(auto cf=constFlod(unaryInst);cf&&cf!=unaryInst){
            unaryInst->replaceAllUseWith(cf);
            unaryInst->unUseAll();
            inst=bb->instructions().erase(inst);
          }
          else{
            inst++;
          }
        }
        else{
          inst++;
        }
      }
    }
  }
  Value* ConstFlod::constFlod(BinaryInst* inst){
    if(auto clhs=dynamic_cast<Constant*>(inst->lhs())){
      if(auto crls=dynamic_cast<Constant*>(inst->rhs())){
        if(clhs->isInt()&&crls->isInt()){
          switch (inst->itype()) {
            case IR::ADD:{
              return Constant::get(static_cast<int32_t>(clhs->getIntVal()+crls->getIntVal()));
            }break;
            case IR::SUB:{
              return Constant::get(static_cast<int32_t>(clhs->getIntVal()-crls->getIntVal()));
            }break;
            case IR::MUL:{
              return Constant::get(static_cast<int32_t>(clhs->getIntVal()*crls->getIntVal()));
            }break;
            case IR::SDIV:{
              return Constant::get(static_cast<int32_t>(clhs->getIntVal()/crls->getIntVal()));
            }break;
            case IR::SREM:{
              return Constant::get(static_cast<int32_t>(clhs->getIntVal()%crls->getIntVal()));
            }break;
            default:{
              return nullptr;
            }break;
          }
        }
        else if(clhs->isFloat()&&crls->isFloat()){
          switch (inst->itype()) {
            case IR::FADD:{
              return Constant::get(static_cast<float>(clhs->getFloatVal()+crls->getFloatVal()));
            }break;
            case IR::FSUB:{
              return Constant::get(static_cast<float>(clhs->getFloatVal()-crls->getFloatVal()));
            }break;
            case IR::FMUL:{
              return Constant::get(static_cast<float>(clhs->getFloatVal()*crls->getFloatVal()));
            }break;
            case IR::FDIV:{
              return Constant::get(static_cast<float>(clhs->getFloatVal()/crls->getFloatVal()));
            }break;
            default:{
              return nullptr;
            }
          }
        }
      }
    }
    return nullptr;
  }
  Value *ConstFlod::constFlod(UnaryInst *inst) {
    if(auto chs=dynamic_cast<Constant*>(inst->rhs())){
      switch (inst->itype()) {
        case IR::ZEXT:{
          if(chs->isBool()){
            return Constant::get(static_cast<int32_t>(chs->getBoolVal()));
          }
          else if(chs->isInt()){
            return Constant::get(static_cast<int32_t>(chs->getIntVal()));
          }
        }break;
        case IR::SITOFP:{
          if(chs->isBool()){
            return Constant::get(static_cast<float>(chs->getBoolVal()));
          }
          // else if(chs->isInt()){
          //   // TODO
          //   return Constant::get(static_cast<float>(chs->getIntVal()));
          // }
        }break;
        case IR::FPTOSI:{
          return Constant::get(static_cast<int32_t>(chs->getFloatVal()));
        }break;
        case IR::FNEG:{
          return Constant::get(static_cast<float>(-chs->getFloatVal()));
        }break;
        default:{
          return nullptr;
        }break;
      }
    }
    return nullptr;
  }
  Value *ConstFlod::constFlod(IcmpInst *inst) {
    if(auto clhs=dynamic_cast<Constant*>(inst->lhs())){
      if(auto crls=dynamic_cast<Constant*>(inst->rhs())){
        if(clhs->isInt()&&crls->isInt()){
          switch (inst->itype()) {
            case IR::IEQ:{
              return Constant::get(static_cast<bool>(clhs->getIntVal()==crls->getIntVal()));
            }break;
            case IR::INE:{
              return Constant::get(static_cast<bool>(clhs->getIntVal()!=crls->getIntVal()));
            }break;
            case IR::ISLT:{
              return Constant::get(static_cast<bool>(clhs->getIntVal()<crls->getIntVal()));
            }break;
            case IR::ISGT:{
              return Constant::get(static_cast<bool>(clhs->getIntVal()>crls->getIntVal()));
            }break;
            case IR::ISLE:{
              return Constant::get(static_cast<bool>(clhs->getIntVal()<=crls->getIntVal()));
            }break;
            case IR::ISGE:{
              return Constant::get(static_cast<bool>(clhs->getIntVal()>=crls->getIntVal()));
            }break;
            default:{
              return nullptr;
            }break;
          }
        }
      }
    }
    return nullptr;
  }
  Value *ConstFlod::constFlod(FcmpInst* inst){
    if(auto clhs=dynamic_cast<Constant*>(inst->lhs())){
      if(auto crls=dynamic_cast<Constant*>(inst->rhs())){
        if(clhs->isFloat()&&crls->isFloat()){
          switch (inst->itype()) {
            case IR::FOEQ:{
              return Constant::get(static_cast<bool>(clhs->getFloatVal()==crls->getFloatVal()));
            }break;
            case IR::FONE:{
              return Constant::get(static_cast<bool>(clhs->getFloatVal()!=crls->getFloatVal()));
            }break;
            case IR::FOLT:{
              return Constant::get(static_cast<bool>(clhs->getFloatVal()<crls->getFloatVal()));
            }break;
            case IR::FOGT:{
              return Constant::get(static_cast<bool>(clhs->getFloatVal()>crls->getFloatVal()));
            }break;
            case IR::FOLE:{
              return Constant::get(static_cast<bool>(clhs->getFloatVal()<=crls->getFloatVal()));
            }break;
            case IR::FOGE:{
              return Constant::get(static_cast<bool>(clhs->getFloatVal()>=crls->getFloatVal()));
            }break;
            default:{
              return nullptr;
            }
          }
        }
      }
    }
    return nullptr;
  }
}
