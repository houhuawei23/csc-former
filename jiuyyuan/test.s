  .file "test.c"
  .option nopic
  .text
  .align 1
  .globl main
  .type main, @function
main:
  addi sp, sp, -16
  sd s0, 8(sp)
  addi s0, sp, 16
  addi a0, zero, 0
  ld s0, 8(sp)
  addi sp, sp, 16
  jalr zero, 0(ra)

