#include "riscvbuilder.hpp"

namespace RISCV {

RISCVBuilder::RISCVBuilder(Block* block, std::list<std::unique_ptr<Inst>>::iterator it) : block(block), it(it) {
}

void RISCVBuilder::set(Block* block, std::list<std::unique_ptr<Inst>>::iterator it) {
  this->block = block;
  this->it = it;
}

}  // namespace RISCV
