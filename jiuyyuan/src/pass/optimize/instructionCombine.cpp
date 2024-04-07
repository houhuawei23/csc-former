#include "instructionCombine.hpp"
#include "infrastructure.hpp"
#include "instruction.hpp"
#include "typesystem.hpp"
#include <cstdint>
using namespace IR;
namespace Pass {
Instruction *instructionCombine::visitADD(BinaryInst *inst) {
  if (auto clhs = dynamic_cast<Constant *>(inst->lhs());
      clhs && clhs->isInt()) {
    if (auto rhs = dynamic_cast<BinaryInst *>(inst->rhs())) {
      if (rhs->itype() == ADD) {
        if (auto clhs2 = dynamic_cast<Constant *>(rhs->lhs());
            clhs2 && clhs2->isInt()) {
          // (C1+(C2+X))->X+(C1+C2)
          int32_t C1 = clhs->getIntVal();
          int32_t C2 = clhs2->getIntVal();
          return new BinaryInst(inst->basicBlock(), ADD, inst->type(), "",
                                rhs->rhs(),
                                Constant::get(static_cast<int32_t>(C1 + C2)));
        } else if (auto crhs = dynamic_cast<Constant *>(rhs->rhs());
                   crhs && crhs->isInt()) {
          // (C1+(X+C2))->X+(C1+C2)
          int32_t C1 = clhs->getIntVal();
          int32_t C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), ADD, inst->type(), "",
                                rhs->lhs(),
                                Constant::get(static_cast<int32_t>(C1 + C2)));
        }
      } else if (rhs->itype() == SUB) {
        if (auto clhs2 = dynamic_cast<Constant *>(rhs->lhs());
            clhs2 && clhs2->isInt()) {
          // (C1+(C2-X))->(C1+C2)-X
          int32_t C1 = clhs->getIntVal();
          int32_t C2 = clhs2->getIntVal();
          return new BinaryInst(inst->basicBlock(), SUB, inst->type(), "",
                                Constant::get(static_cast<int32_t>(C1 + C2)),
                                rhs->rhs());
        } else if (auto crhs = dynamic_cast<Constant *>(rhs->rhs());
                   crhs && crhs->isInt()) {
          // (C1+(X-C2))->X+(C1-C2)
          int32_t C1 = clhs->getIntVal();
          int32_t C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), SUB, inst->type(), "",
                                rhs->lhs(),
                                Constant::get(static_cast<int32_t>(C1 - C2)));
        }
      }
    }
  } else if (auto crhs = dynamic_cast<Constant *>(inst->rhs());
             crhs && crhs->isInt()) {
    if (auto lhs = dynamic_cast<BinaryInst *>(inst->lhs())) {
      if (lhs->itype() == ADD) {
        if (auto clhs = dynamic_cast<Constant *>(lhs->lhs());
            clhs && clhs->isInt()) {
          // ((C1+X)+C2)->X+(C1+C2)
          int32_t C1 = clhs->getIntVal();
          int32_t C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), ADD, inst->type(), "",
                                lhs->rhs(),
                                Constant::get(static_cast<int32_t>(C1 + C2)));
        } else if (auto crhs2 = dynamic_cast<Constant *>(lhs->rhs());
                   crhs2 && crhs2->isInt()) {
          // ((X+C1)+C2))->X+(C1+C2)
          int32_t C1 = crhs2->getIntVal();
          int32_t C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), ADD, inst->type(), "",
                                lhs->lhs(),
                                Constant::get(static_cast<int32_t>(C1 + C2)));
        }
      } else if (lhs->itype() == SUB) {
        if (auto clhs = dynamic_cast<Constant *>(lhs->lhs());
            clhs && clhs->isInt()) {
          // ((C1-X)+C2)->(C1+C2)-X
          int32_t C1 = clhs->getIntVal();
          int32_t C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), SUB, inst->type(), "",
                                Constant::get(static_cast<int32_t>(C1 + C2)),
                                lhs->rhs());
        } else if (auto crhs2 = dynamic_cast<Constant *>(lhs->rhs());
                   crhs2 && crhs2->isInt()) {
          // ((X-C1)+C2)->X+(C2-C1)
          int32_t C1 = crhs2->getIntVal();
          int32_t C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), ADD, inst->type(), "",
                                lhs->lhs(),
                                Constant::get(static_cast<int32_t>(C2 - C1)));
        }
      }
    }
  }
  if (inst->lhs() == inst->rhs()) {
    // X+X->X*2
    return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                          inst->lhs(), Constant::get(static_cast<int32_t>(2)));
  }
  if (auto mulLhs = dynamic_cast<BinaryInst *>(inst->lhs());
      mulLhs && mulLhs->itype() == MUL) {
    auto lhsLhs = mulLhs->lhs();
    auto lhsRhs = mulLhs->rhs();
    if (lhsLhs == inst->rhs()) {
      if (auto clhsRhs = dynamic_cast<Constant *>(lhsRhs);
          clhsRhs && clhsRhs->isInt()) {
        // X*C+X->X*(C+1)
        auto C = clhsRhs->getIntVal();
        return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "", lhsLhs,
                              Constant::get(static_cast<int32_t>(C + 1)));
      }
    }
    if (lhsRhs == inst->rhs()) {
      if (auto clhsLhs = dynamic_cast<Constant *>(lhsLhs);
          clhsLhs && clhsLhs->isInt()) {
        // C*X+X->X*(C+1)
        auto C = clhsLhs->getIntVal();
        return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "", lhsRhs,
                              Constant::get(static_cast<int32_t>(C + 1)));
      }
    }
    if (auto mulRhs = dynamic_cast<BinaryInst *>(inst->rhs());
        mulRhs && mulRhs->itype() == MUL) {
      // X*C1+X*C2->X*(C1+C2)
      auto rhsLhs = mulRhs->lhs();
      auto rhsRhs = mulRhs->rhs();
      if (lhsLhs == rhsLhs) {
        if (auto c1 = dynamic_cast<Constant *>(lhsRhs); c1 && c1->isInt())
          if (auto c2 = dynamic_cast<Constant *>(rhsRhs); c2 && c2->isInt()) {
            auto C1 = c1->getIntVal();
            auto C2 = c2->getIntVal();
            return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                                  lhsLhs,
                                  Constant::get(static_cast<int32_t>(C1 + C2)));
          }
      }
      if (lhsLhs == rhsRhs) {
        if (auto c1 = dynamic_cast<Constant *>(lhsRhs); c1 && c1->isInt())
          if (auto c2 = dynamic_cast<Constant *>(rhsLhs); c2 && c2->isInt()) {
            auto C1 = c1->getIntVal();
            auto C2 = c2->getIntVal();
            return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                                  lhsLhs,
                                  Constant::get(static_cast<int32_t>(C1 + C2)));
          }
      }
      if (lhsRhs == rhsLhs) {
        if (auto c1 = dynamic_cast<Constant *>(lhsLhs); c1 && c1->isInt())
          if (auto c2 = dynamic_cast<Constant *>(rhsRhs); c2 && c2->isInt()) {
            auto C1 = c1->getIntVal();
            auto C2 = c2->getIntVal();

            return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                                  lhsRhs,
                                  Constant::get(static_cast<int32_t>(C1 + C2)));
          }
      }
      if (lhsRhs == rhsRhs) {
        if (auto c1 = dynamic_cast<Constant *>(lhsLhs); c1 && c1->isInt())
          if (auto c2 = dynamic_cast<Constant *>(rhsLhs); c2 && c2->isInt()) {
            auto C1 = c1->getIntVal();
            auto C2 = c2->getIntVal();

            return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                                  lhsRhs,
                                  Constant::get(static_cast<int32_t>(C1 + C2)));
          }
      }
    }
  }
  if (auto mulRhs = dynamic_cast<BinaryInst *>(inst->rhs());
      mulRhs && mulRhs->itype() == MUL) {
    auto rhsLhs = mulRhs->lhs();
    auto rhsRhs = mulRhs->rhs();
    // X+X*C->X*(C+1)
    if (rhsLhs == inst->lhs()) {
      if (auto crhsRhs = dynamic_cast<Constant *>(rhsRhs);
          crhsRhs && crhsRhs->isInt()) {
        auto C = crhsRhs->getIntVal();
        return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "", rhsLhs,
                              Constant::get(static_cast<int32_t>(C + 1)));
      }
    }
    //X+C*X->X*(C+1)
    if (rhsRhs == inst->lhs()) {
      if (auto crhsLhs = dynamic_cast<Constant *>(rhsLhs);
          crhsLhs && crhsLhs->isInt()) {
        auto C = crhsLhs->getIntVal();
        return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "", rhsRhs,
                              Constant::get(static_cast<int32_t>(C + 1)));
      }
    }
  }
  return inst;
}

Instruction *instructionCombine::visitSUB(BinaryInst *inst) {
  if (auto clhs = dynamic_cast<Constant *>(inst->lhs());
      clhs && clhs->isInt()) {
    if (auto rhs = dynamic_cast<BinaryInst *>(inst->rhs())) {
      if (rhs->itype() == ADD) {
        // (C1-(C2 + X))->(C1-C2)-X
        if (auto crhsLhs = dynamic_cast<Constant *>(rhs->lhs());
            crhsLhs && crhsLhs->isInt()) {
          int C1 = clhs->getIntVal();
          int C2 = crhsLhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), SUB, inst->type(), "",
                                Constant::get(static_cast<int32_t>(C1 - C2)),
                                rhs->rhs());
        }
        // (C1-(X + C2))->(C1-C2)-X
        else if (auto crhsRhs = dynamic_cast<Constant *>(rhs->rhs());
                 crhsRhs && crhsRhs->isInt()) {
          int C1 = clhs->getIntVal();
          int C2 = crhsRhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), SUB, inst->type(), "",
                                Constant::get(static_cast<int32_t>(C1 - C2)),
                                rhs->lhs());
        }
      } else if (rhs->itype() == SUB) {
        // (C1 - (C2 - X)) ->  (C1 - C2) + X
        if (auto crhsLhs = dynamic_cast<Constant *>(rhs->lhs());
            crhsLhs && crhsLhs->isInt()) {
          int C1 = clhs->getIntVal();
          int C2 = crhsLhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), ADD, inst->type(), "",
                                Constant::get(static_cast<int32_t>(C1 - C2)),
                                rhs->rhs());
        }
        // (C1 - (X - C2)) -> (C1 + C2) - X
        else if (auto crhsRhs = dynamic_cast<Constant *>(rhs->rhs());
                 crhsRhs && crhsRhs->isInt()) {
          int C1 = clhs->getIntVal();
          int C2 = crhsRhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), SUB, inst->type(), "",
                                Constant::get(static_cast<int32_t>(C1 + C2)),
                                rhs->lhs());
        }
      }
    }
  } else if (auto crhs = dynamic_cast<Constant *>(inst->rhs());
             crhs && crhs->isInt()) {
    if (auto lhs = dynamic_cast<BinaryInst *>(inst->lhs())) {
      if (lhs->itype() == ADD) {
        // ((C1 + X) - C2) -> X + (C1 - C2)
        if (auto clhsLhs = dynamic_cast<Constant *>(lhs->lhs());
            clhsLhs && clhsLhs->isInt()) {
          int C1 = clhsLhs->getIntVal();
          int C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), ADD, inst->type(), "",
                                lhs->rhs(),
                                Constant::get(static_cast<int32_t>(C1 - C2)));
        }
        // ((X + C1) - C2)) -> X + (C1 - C2)
        else if (auto clhsRhs = dynamic_cast<Constant *>(lhs->rhs());
                 clhsRhs && clhsRhs->isInt()) {
          int C1 = clhsRhs->getIntVal();
          int C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), ADD, inst->type(), "",
                                lhs->lhs(),
                                Constant::get(static_cast<int32_t>(C1 - C2)));
        }
      } else if (lhs->itype() == SUB) {
        // ((C1 - X) - C2) ->  (C1 - C2) - X
        if (auto clhsLhs = dynamic_cast<Constant *>(lhs->lhs());
            clhsLhs && clhsLhs->isInt()) {
          int C1 = clhsLhs->getIntVal();
          int C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), SUB, inst->type(), "",
                                Constant::get(static_cast<int32_t>(C1 - C2)),
                                lhs->rhs());
        }
        // ((X - C1) - C2) -> X - (C1 + C2)
        else if (auto clhsRhs = dynamic_cast<Constant *>(lhs->rhs());
                 clhsRhs && clhsRhs->isInt()) {
          int C1 = clhsRhs->getIntVal();
          int C2 = crhs->getIntVal();
          return new BinaryInst(inst->basicBlock(), SUB, inst->type(), "",
                                lhs->lhs(),
                                Constant::get(static_cast<int32_t>(C1 + C2)));
        }
      }
    }
  }

  if (auto mulLhs = dynamic_cast<BinaryInst *>(inst->lhs());
      mulLhs && mulLhs->itype() == MUL) {
    auto lhsLhs = mulLhs->lhs();
    auto lhsRhs = mulLhs->rhs();
    // X * C - X -> X * (C - 1)
    if (lhsLhs == inst->rhs()) {
      if (auto clhsRhs = dynamic_cast<Constant *>(lhsRhs);
          clhsRhs && clhsRhs->isInt()) {
        auto C = clhsRhs->getIntVal();
        return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "", lhsLhs,
                              Constant::get(static_cast<int32_t>(C - 1)));
      }
    }
    // C * X - X -> X * (C - 1)
    if (lhsRhs == inst->rhs()) {
      if (auto clhsLhs = dynamic_cast<Constant *>(lhsLhs);
          clhsLhs && clhsLhs->isInt()) {
        auto C = clhsLhs->getIntVal();
        return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "", lhsRhs,
                              Constant::get(static_cast<int32_t>(C - 1)));
      }
    }

    // X * C1 - X * C2 -> X * (C1 - C2)
    if (auto mulRhs = dynamic_cast<BinaryInst *>(inst->rhs());
        mulRhs && mulLhs->itype() == MUL) {
      auto rhsLhs = mulRhs->lhs();
      auto rhsRhs = mulRhs->rhs();

      if (lhsLhs == rhsLhs) {
        if (auto c1 = dynamic_cast<Constant *>(lhsRhs); c1 && c1->isInt())
          if (auto c2 = dynamic_cast<Constant *>(rhsRhs); c2 && c2->isInt()) {
            auto C1 = c1->getIntVal();
            auto C2 = c2->getIntVal();
            return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                                  lhsLhs,
                                  Constant::get(static_cast<int32_t>(C1 - C2)));
          }
      }
      if (lhsLhs == rhsRhs) {
        if (auto c1 = dynamic_cast<Constant *>(lhsRhs); c1 && c1->isInt())
          if (auto c2 = dynamic_cast<Constant *>(rhsLhs); c2 && c2->isInt()) {
            auto C1 = c1->getIntVal();
            auto C2 = c2->getIntVal();
            return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                                  lhsLhs,
                                  Constant::get(static_cast<int32_t>(C1 - C2)));
          }
      }
      if (lhsRhs == rhsLhs) {
        if (auto c1 = dynamic_cast<Constant *>(lhsLhs); c1 && c1->isInt())
          if (auto c2 = dynamic_cast<Constant *>(rhsRhs); c2 && c2->isInt()) {
            auto C1 = c1->getIntVal();
            auto C2 = c2->getIntVal();
            return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                                  lhsRhs,
                                  Constant::get(static_cast<int32_t>(C1 - C2)));
          }
      }
      if (lhsRhs == rhsRhs) {
        if (auto c1 = dynamic_cast<Constant *>(lhsLhs); c1 && c1->isInt())
          if (auto c2 = dynamic_cast<Constant *>(rhsLhs); c2 && c2->isInt()) {
            auto C1 = c1->getIntVal();
            auto C2 = c2->getIntVal();
            return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "",
                                  lhsRhs,
                                  Constant::get(static_cast<int32_t>(C1 - C2)));
          }
      }
    }
  }
  if (auto mulRhs = dynamic_cast<BinaryInst *>(inst->rhs());
      mulRhs && mulRhs->itype() == MUL) {
    auto rhsLhs = mulRhs->lhs();
    auto rhsRhs = mulRhs->rhs();
    // X - X * C -> X * (1 - C)
    if (rhsLhs == inst->lhs()) {
      if (auto crhsRhs = dynamic_cast<Constant *>(rhsRhs);
          crhsRhs && crhsRhs->isInt()) {
        auto C = crhsRhs->getIntVal();
        return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "", rhsLhs,
                              Constant::get(static_cast<int32_t>(1 - C)));
      }
    }
    // X - C * X -> X * (C + 1)
    if (rhsRhs == inst->lhs()) {
      if (auto crhsLhs = dynamic_cast<Constant *>(rhsLhs);
          crhsLhs && crhsLhs->isInt()) {
        auto C = crhsLhs->getIntVal();
        return new BinaryInst(inst->basicBlock(), MUL, inst->type(), "", rhsRhs,
                              Constant::get(static_cast<int32_t>(1 - C)));
      }
    }
  }

  return inst;
}
Instruction *instructionCombine::visitBinary(BinaryInst *inst) {
  if (inst->itype() == ADD) {
    return visitADD(inst);
  }
  if (inst->itype() == SUB) {
    return visitSUB(inst);
  }
  return inst;
}
} // namespace Pass
