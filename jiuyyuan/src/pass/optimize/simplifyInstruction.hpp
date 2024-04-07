#ifndef __OPTIMIZE_simplifyInstruction_HPP__
#define __OPTIMIZE_simplifyInstruction_HPP__
#include "instruction.hpp"
namespace IR {
Value* simplifyInstruction(Instruction* inst);
Value* simplifyInstruction(BinaryInst* inst);
Value* simplifyInstruction(UnaryInst* inst);
Value* simplifyInstruction(IcmpInst* inst);
} // namespace ir
#endif
