// Automatically generated file, do not edit!
R"(	.file	"cmmc_sysy_rt.cpp"
	.option pic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0_zba1p0_zbb1p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.type	_ZN12_GLOBAL__N_110cmmcWorkerEPv, @function
_ZN12_GLOBAL__N_110cmmcWorkerEPv:
.LFB1259:
	.cfi_startproc
	addi	sp,sp,-192
	.cfi_def_cfa_offset 192
	sd	s0,176(sp)
	.cfi_offset 8, -16
	mv	s0,a0
	sd	ra,184(sp)
	sd	s1,168(sp)
	sd	s2,160(sp)
	sd	s3,152(sp)
	sd	s4,144(sp)
	sd	s5,136(sp)
	.cfi_offset 1, -8
	.cfi_offset 9, -24
	.cfi_offset 18, -32
	.cfi_offset 19, -40
	.cfi_offset 20, -48
	.cfi_offset 21, -56
	fence	iorw,iorw
	lw	a5,16(a0)
	fence	iorw,iorw
	li	a4,1023
	sext.w	a2,a5
	mv	s1,sp
	zext.w	a5,a5
	bgtu	a5,a4,.L2
	li	a3,1
	srli	a5,a5,6
	sll	a3,a3,a2
	sh3add	a5,a5,s1
	ld	a4,0(a5)
	or	a4,a4,a3
	sd	a4,0(a5)
.L2:
	li	a0,178
	addi	s2,s0,20
	call	syscall@plt
	addi	s3,s0,40
	mv	a2,s1
	sext.w	a0,a0
	li	a1,128
	addi	s1,s0,44
	call	sched_setaffinity@plt
	li	s4,1
	j	.L6
.L21:
	fence iorw,ow;  1: lr.w.aq a5,0(s3); bne a5,s4,1f; sc.w.aq a4,zero,0(s3); bnez a4,1b; 1:
	addiw	a5,a5,-1
	li	s5,1
	bne	a5,zero,.L4
.L7:
	fence	iorw,iorw
	lw	a5,0(s2)
	fence	iorw,iorw
	beq	a5,zero,.L5
	fence	iorw,iorw
	fence	iorw,iorw
	ld	a5,24(s0)
	fence	iorw,iorw
	fence	iorw,iorw
	lw	a0,32(s0)
	fence	iorw,iorw
	fence	iorw,iorw
	sext.w	a0,a0
	lw	a1,36(s0)
	fence	iorw,iorw
	jalr	a5
	fence	iorw,iorw
	fence iorw,ow;  1: lr.w.aq a5,0(s1); bne a5,zero,1f; sc.w.aq a4,s4,0(s1); bnez a4,1b; 1:
	sext.w	a5,a5
	bne	a5,zero,.L6
	mv	a1,s1
	li	a6,0
	li	a4,0
	li	a3,1
	li	a2,1
	li	a0,98
	call	syscall@plt
.L6:
	fence	iorw,iorw
	lw	a5,0(s2)
	fence	iorw,iorw
	bne	a5,zero,.L21
.L5:
	ld	ra,184(sp)
	.cfi_remember_state
	.cfi_restore 1
	li	a0,0
	ld	s0,176(sp)
	.cfi_restore 8
	ld	s1,168(sp)
	.cfi_restore 9
	ld	s2,160(sp)
	.cfi_restore 18
	ld	s3,152(sp)
	.cfi_restore 19
	ld	s4,144(sp)
	.cfi_restore 20
	ld	s5,136(sp)
	.cfi_restore 21
	addi	sp,sp,192
	.cfi_def_cfa_offset 0
	jr	ra
.L4:
	.cfi_restore_state
	mv	a1,s3
	li	a6,0
	li	a5,0
	li	a4,0
	li	a3,0
	li	a2,0
	li	a0,98
	call	syscall@plt
	fence iorw,ow;  1: lr.w.aq a5,0(s3); bne a5,s5,1f; sc.w.aq a4,zero,0(s3); bnez a4,1b; 1:
	addiw	a5,a5,-1
	beq	a5,zero,.L7
	j	.L4
	.cfi_endproc
.LFE1259:
	.size	_ZN12_GLOBAL__N_110cmmcWorkerEPv, .-_ZN12_GLOBAL__N_110cmmcWorkerEPv
	.section	.text.startup,"ax",@progbits
	.align	1
	.globl	cmmcInitRuntime
	.type	cmmcInitRuntime, @function
cmmcInitRuntime:
.LFB1260:
	.cfi_startproc
	addi	sp,sp,-64
	.cfi_def_cfa_offset 64
	sd	s2,32(sp)
	.cfi_offset 18, -32
	li	s2,331776
	sd	s3,24(sp)
	.cfi_offset 19, -40
	li	s3,131072
	addi	s3,s3,34
	addi	s2,s2,-256
	sd	s0,48(sp)
	.cfi_offset 8, -16
	lla	s0,.LANCHOR0
	sd	s1,40(sp)
	.cfi_offset 9, -24
	li	s1,0
	sd	s4,16(sp)
	.cfi_offset 20, -48
	li	s4,4
	sd	s5,8(sp)
	.cfi_offset 21, -56
	lla	s5,_ZN12_GLOBAL__N_110cmmcWorkerEPv
	sd	s6,0(sp)
	.cfi_offset 22, -64
	li	s6,1
	sd	ra,56(sp)
	.cfi_offset 1, -8
.L23:
	addi	a5,s0,20
	fence iorw,ow; amoswap.w.aq zero,s6,0(a5)
	mv	a3,s3
	li	a5,0
	li	a4,-1
	li	a2,3
	li	a1,1048576
	li	a0,0
	call	mmap@plt
	sd	a0,8(s0)
	addi	a5,s0,16
	fence iorw,ow; amoswap.w.aq zero,s1,0(a5)
	li	a5,1048576
	mv	a3,s0
	ld	a1,8(s0)
	mv	a2,s2
	add	a1,a1,a5
	mv	a0,s5
	addi	s0,s0,48
	addiw	s1,s1,1
	call	clone@plt
	sw	a0,-48(s0)
	bne	s1,s4,.L23
	ld	ra,56(sp)
	.cfi_restore 1
	ld	s0,48(sp)
	.cfi_restore 8
	ld	s1,40(sp)
	.cfi_restore 9
	ld	s2,32(sp)
	.cfi_restore 18
	ld	s3,24(sp)
	.cfi_restore 19
	ld	s4,16(sp)
	.cfi_restore 20
	ld	s5,8(sp)
	.cfi_restore 21
	ld	s6,0(sp)
	.cfi_restore 22
	addi	sp,sp,64
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1260:
	.size	cmmcInitRuntime, .-cmmcInitRuntime
	.section	.init_array,"aw"
	.align	3
	.dword	cmmcInitRuntime
	.section	.text.exit,"ax",@progbits
	.align	1
	.globl	cmmcUninitRuntime
	.type	cmmcUninitRuntime, @function
cmmcUninitRuntime:
.LFB1261:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sd	s0,16(sp)
	.cfi_offset 8, -16
	lla	s0,.LANCHOR0+40
	sd	s1,8(sp)
	.cfi_offset 9, -24
	li	s1,1
	sd	s2,0(sp)
	.cfi_offset 18, -32
	lla	s2,.LANCHOR0+232
	sd	ra,24(sp)
	.cfi_offset 1, -8
.L30:
	addi	a5,s0,-20
	fence iorw,ow; amoswap.w.aq zero,zero,0(a5)
	fence iorw,ow;  1: lr.w.aq a7,0(s0); bne a7,zero,1f; sc.w.aq a5,s1,0(s0); bnez a5,1b; 1:
	sext.w	a7,a7
	mv	a1,s0
	li	a6,0
	li	a5,0
	li	a4,0
	li	a3,1
	li	a2,1
	li	a0,98
	bne	a7,zero,.L27
	addi	s0,s0,48
	call	syscall@plt
	li	a2,0
	li	a1,0
	lw	a0,-88(s0)
	call	waitpid@plt
	bne	s2,s0,.L30
.L26:
	ld	ra,24(sp)
	.cfi_remember_state
	.cfi_restore 1
	ld	s0,16(sp)
	.cfi_restore 8
	ld	s1,8(sp)
	.cfi_restore 9
	ld	s2,0(sp)
	.cfi_restore 18
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
.L27:
	.cfi_restore_state
	lw	a0,-40(s0)
	li	a2,0
	addi	s0,s0,48
	li	a1,0
	call	waitpid@plt
	bne	s0,s2,.L30
	j	.L26
	.cfi_endproc
.LFE1261:
	.size	cmmcUninitRuntime, .-cmmcUninitRuntime
	.section	.fini_array,"aw"
	.align	3
	.dword	cmmcUninitRuntime
	.text
	.align	1
	.globl	cmmcParallelFor
	.type	cmmcParallelFor, @function
cmmcParallelFor:
.LFB1265:
	.cfi_startproc
	bge	a0,a1,.L116
	addi	sp,sp,-144
	.cfi_def_cfa_offset 144
	subw	t4,a1,a0
	li	a5,15
	sd	s2,112(sp)
	.cfi_offset 18, -32
	mv	s2,a1
	sd	s3,104(sp)
	.cfi_offset 19, -40
	mv	s3,a2
	sd	s5,88(sp)
	.cfi_offset 21, -56
	mv	s5,t4
	sd	s11,40(sp)
	.cfi_offset 27, -104
	mv	s11,a0
	sd	ra,136(sp)
	sd	s0,128(sp)
	sd	s1,120(sp)
	sd	s4,96(sp)
	sd	s6,80(sp)
	sd	s7,72(sp)
	sd	s8,64(sp)
	sd	s9,56(sp)
	sd	s10,48(sp)
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	.cfi_offset 9, -24
	.cfi_offset 20, -48
	.cfi_offset 22, -64
	.cfi_offset 23, -72
	.cfi_offset 24, -80
	.cfi_offset 25, -88
	.cfi_offset 26, -96
	bgt	t4,a5,.L34
	ld	ra,136(sp)
	.cfi_remember_state
	.cfi_restore 1
	ld	s0,128(sp)
	.cfi_restore 8
	ld	s1,120(sp)
	.cfi_restore 9
	ld	s2,112(sp)
	.cfi_restore 18
	ld	s3,104(sp)
	.cfi_restore 19
	ld	s4,96(sp)
	.cfi_restore 20
	ld	s5,88(sp)
	.cfi_restore 21
	ld	s6,80(sp)
	.cfi_restore 22
	ld	s7,72(sp)
	.cfi_restore 23
	ld	s8,64(sp)
	.cfi_restore 24
	ld	s9,56(sp)
	.cfi_restore 25
	ld	s10,48(sp)
	.cfi_restore 26
	ld	s11,40(sp)
	.cfi_restore 27
	addi	sp,sp,144
	.cfi_def_cfa_offset 0
	jr	a2
.L34:
	.cfi_restore_state
	lla	a7,.LANCHOR0
	li	a3,16
	lw	a4,1088(a7)
	li	a1,0
	lla	a2,.LANCHOR0+192
	li	t3,16
.L39:
	beq	a4,t3,.L80
	zext.w	a6,a4
	slli.uw	a5,a4,3
	sub	a5,a5,a6
	sh3add	s0,a5,a2
.L35:
	slli	a5,a6,3
	addiw	a3,a3,-1
	sub	a5,a5,a6
	sh3add	a5,a5,a7
	lbu	t1,204(a5)
	beq	t1,zero,.L36
	ld	t1,192(a5)
	beq	t1,s3,.L119
.L36:
	addiw	a4,a4,1
	li	a1,1
	bne	a3,zero,.L39
	lbu	a5,204(a7)
	beq	a5,zero,.L40
	lbu	a5,260(a7)
	beq	a5,zero,.L81
	lbu	a5,316(a7)
	beq	a5,zero,.L82
	lbu	a5,372(a7)
	beq	a5,zero,.L83
	lbu	a5,428(a7)
	beq	a5,zero,.L84
	lbu	a5,484(a7)
	beq	a5,zero,.L85
	lbu	a5,540(a7)
	beq	a5,zero,.L86
	lbu	a5,596(a7)
	beq	a5,zero,.L87
	lbu	a5,652(a7)
	beq	a5,zero,.L88
	lbu	a5,708(a7)
	beq	a5,zero,.L89
	lbu	a5,764(a7)
	beq	a5,zero,.L90
	lbu	a5,820(a7)
	beq	a5,zero,.L91
	lbu	a5,876(a7)
	beq	a5,zero,.L92
	lbu	a5,932(a7)
	beq	a5,zero,.L93
	lbu	a5,988(a7)
	beq	a5,zero,.L94
	lbu	a5,1044(a7)
	li	a3,15
	beq	a5,zero,.L40
	lw	a1,264(a7)
	lw	a5,208(a7)
	lw	a6,320(a7)
	sgtu	a3,a5,a1
	lw	t1,376(a7)
	bleu a5,a1,1f; mv a5,a1; 1: # movcc
	mv	a0,a5
	bgeu a6,a5,1f; mv a0,a6; 1: # movcc
	lw	a4,432(a7)
	bgeu a6,a5,1f; li a3,2; 1: # movcc
	mv	a5,a0
	bgeu t1,a0,1f; mv a5,t1; 1: # movcc
	lw	a1,488(a7)
	bgeu t1,a0,1f; li a3,3; 1: # movcc
	mv	a0,a5
	bgeu a4,a5,1f; mv a0,a4; 1: # movcc
	lw	a6,544(a7)
	bgeu a4,a5,1f; li a3,4; 1: # movcc
	mv	a5,a0
	bleu a0,a1,1f; mv a5,a1; 1: # movcc
	lw	t1,600(a7)
	bleu a0,a1,1f; li a3,5; 1: # movcc
	mv	a0,a5
	bgeu a6,a5,1f; mv a0,a6; 1: # movcc
	lw	a4,656(a7)
	bgeu a6,a5,1f; li a3,6; 1: # movcc
	mv	a6,a0
	bgeu t1,a0,1f; mv a6,t1; 1: # movcc
	lw	a1,712(a7)
	bgeu t1,a0,1f; li a3,7; 1: # movcc
	mv	t1,a6
	bleu a6,a4,1f; mv t1,a4; 1: # movcc
	lw	a5,768(a7)
	bleu a6,a4,1f; li a3,8; 1: # movcc
	mv	a6,t1
	bleu t1,a1,1f; mv a6,a1; 1: # movcc
	lw	a0,824(a7)
	bleu t1,a1,1f; li a3,9; 1: # movcc
	mv	t1,a6
	bleu a6,a5,1f; mv t1,a5; 1: # movcc
	lw	a4,880(a7)
	bleu a6,a5,1f; li a3,10; 1: # movcc
	mv	a6,t1
	bleu t1,a0,1f; mv a6,a0; 1: # movcc
	lw	a1,936(a7)
	bleu t1,a0,1f; li a3,11; 1: # movcc
	mv	a0,a6
	bleu a6,a4,1f; mv a0,a4; 1: # movcc
	lw	a5,992(a7)
	bleu a6,a4,1f; li a3,12; 1: # movcc
	mv	a4,a0
	bleu a0,a1,1f; mv a4,a1; 1: # movcc
	lw	t1,1048(a7)
	bleu a0,a1,1f; li a3,13; 1: # movcc
	mv	a1,a4
	bleu a4,a5,1f; mv a1,a5; 1: # movcc
	bleu a4,a5,1f; li a3,14; 1: # movcc
	bgeu t1,a1,1f; li a3,15; 1: # movcc
	slli	a5,a3,3
	sub	a5,a5,a3
	sh3add	a4,a5,a7
	sh3add	s0,a5,a2
	li	a5,1
	sw	a3,1088(a7)
	sd	s3,192(a4)
	sw	s5,200(a4)
	sw	a5,208(a4)
.L38:
	lw	s6,16(s0)
	li	a5,99
	bleu	s6,a5,.L57
	li	a5,159
	bleu	s6,a5,.L120
	lw	s6,48(s0)
	beq	s6,zero,.L60
	li	t3,1
	sllw	s1,t3,s6
	mv	s8,s1
.L61:
	sd	zero,0(sp)
.L59:
	li	a5,1
	bne	s8,a5,.L64
	mv	a1,s2
	mv	a0,s11
	jalr	s3
	ld	a5,0(sp)
	bne	a5,zero,.L121
.L32:
	ld	ra,136(sp)
	.cfi_remember_state
	.cfi_restore 1
	ld	s0,128(sp)
	.cfi_restore 8
	ld	s1,120(sp)
	.cfi_restore 9
	ld	s2,112(sp)
	.cfi_restore 18
	ld	s3,104(sp)
	.cfi_restore 19
	ld	s4,96(sp)
	.cfi_restore 20
	ld	s5,88(sp)
	.cfi_restore 21
	ld	s6,80(sp)
	.cfi_restore 22
	ld	s7,72(sp)
	.cfi_restore 23
	ld	s8,64(sp)
	.cfi_restore 24
	ld	s9,56(sp)
	.cfi_restore 25
	ld	s10,48(sp)
	.cfi_restore 26
	ld	s11,40(sp)
	.cfi_restore 27
	addi	sp,sp,144
	.cfi_def_cfa_offset 0
	jr	ra
.L80:
	.cfi_restore_state
	mv	s0,a2
	li	a6,0
	li	a1,1
	li	a4,0
	j	.L35
.L119:
	lw	a5,200(a5)
	bne	a5,t4,.L36
	beq	a1,zero,.L37
	sw	a4,1088(a7)
.L37:
	slli	a5,a6,3
	sub	a5,a5,a6
	sh3add	a5,a5,a7
	lw	a4,208(a5)
	addiw	a4,a4,1
	sw	a4,208(a5)
	j	.L38
.L116:
	.cfi_def_cfa_offset 0
	.cfi_restore 1
	.cfi_restore 8
	.cfi_restore 9
	.cfi_restore 18
	.cfi_restore 19
	.cfi_restore 20
	.cfi_restore 21
	.cfi_restore 22
	.cfi_restore 23
	.cfi_restore 24
	.cfi_restore 25
	.cfi_restore 26
	.cfi_restore 27
	ret
.L60:
	.cfi_def_cfa_offset 144
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	.cfi_offset 9, -24
	.cfi_offset 18, -32
	.cfi_offset 19, -40
	.cfi_offset 20, -48
	.cfi_offset 21, -56
	.cfi_offset 22, -64
	.cfi_offset 23, -72
	.cfi_offset 24, -80
	.cfi_offset 25, -88
	.cfi_offset 26, -96
	.cfi_offset 27, -104
	ld	a5,24(s0)
	li	s8,1
	ld	a4,32(s0)
	li	s1,1
	bge	a4,a5,.L62
	mv	a5,a4
	li	s8,2
	li	s1,2
	li	s6,1
.L62:
	ld	a4,40(s0)
	ble	a5,a4,.L63
	li	a5,2
	sw	a5,48(s0)
.L57:
	fence	iorw,iorw
	srliw	s5,s5,2
	li	s6,2
	addiw	s5,s5,3
	li	s8,4
	andi	s5,s5,-4
	li	s1,4
	sext.w	s5,s5
	sd	zero,0(sp)
	sw	zero,16(sp)
.L79:
	addiw	s7,s8,-1
	sext.w	s11,s11
	addi	s9,sp,16
	lla	s4,.LANCHOR0+40
	li	s10,0
.L72:
	sext.w	a4,s11
	addw	s11,s5,s11
	min	a5,s11,s2
	bne s7,s10,1f; mv a5,s2; 1: # movcc
	ble	a5,a4,.L70
	addi	a3,s4,-16
	fence iorw,ow; amoswap.d.aq zero,s3,0(a3)
	addi	a3,s4,-8
	fence iorw,ow; amoswap.w.aq zero,a4,0(a3)
	addi	a4,s4,-4
	fence iorw,ow; amoswap.w.aq zero,a5,0(a4)
	li	a4,1
	fence iorw,ow;  1: lr.w.aq t5,0(s4); bne t5,zero,1f; sc.w.aq a5,a4,0(s4); bnez a5,1b; 1:
	sext.w	t5,t5
	mv	a1,s4
	li	a6,0
	li	a5,0
	li	a4,0
	li	a3,1
	li	a2,1
	li	a0,98
	bne	t5,zero,.L71
	call	syscall@plt
.L71:
	li	a5,1
	sb	a5,0(s9)
.L70:
	addiw	s10,s10,1
	addi	s9,s9,1
	addi	s4,s4,48
	bne	s1,s10,.L72
.L73:
	beq	s8,zero,.L68
	lla	s3,.LANCHOR0+44
	li	s4,1
	addi	s2,sp,16
	add.uw	s8,s8,s2
.L75:
	lbu	a5,0(s2)
	bne	a5,zero,.L74
.L76:
	addi	s2,s2,1
	addi	s3,s3,48
	bne	s2,s8,.L75
.L68:
	fence	iorw,iorw
	ld	a5,0(sp)
	beq	a5,zero,.L32
.L121:
	addi	a1,sp,16
	li	a0,1
	sh3add.uw	s6,s6,s0
	call	clock_gettime@plt
	ld	a5,16(sp)
	li	a4,1000001536
	addi	a4,a4,-1536
	ld	a3,24(sp)
	mul	a5,a5,a4
	ld	a4,24(s6)
	add	a5,a5,a3
	ld	a3,8(sp)
	sub	a5,a5,a3
	add	a5,a4,a5
	sd	a5,24(s6)
	j	.L32
.L74:
	fence iorw,ow;  1: lr.w.aq a5,0(s3); bne a5,s4,1f; sc.w.aq a4,zero,0(s3); bnez a4,1b; 1:
	addiw	a5,a5,-1
	beq	a5,zero,.L76
	li	s5,1
.L77:
	mv	a1,s3
	li	a6,0
	li	a5,0
	li	a4,0
	li	a3,0
	li	a2,0
	li	a0,98
	call	syscall@plt
	fence iorw,ow;  1: lr.w.aq a5,0(s3); bne a5,s5,1f; sc.w.aq a4,zero,0(s3); bnez a4,1b; 1:
	addiw	a5,a5,-1
	beq	a5,zero,.L76
	j	.L77
.L81:
	li	a3,1
.L40:
	li	a4,1
	zext.w	a1,a3
	sw	a3,1088(a7)
	slli.uw	a5,a3,3
	sub	a5,a5,a1
	sh3add	a7,a5,a7
	sh3add	s0,a5,a2
	sb	a4,204(a7)
	sd	s3,192(a7)
	sw	s5,200(a7)
	sw	a4,208(a7)
	j	.L38
.L120:
	addiw	s6,s6,-100
	li	a5,20
	addi	a1,sp,16
	li	a0,1
	divuw	s6,s6,a5
	li	a5,1
	sd	a5,0(sp)
	call	clock_gettime@plt
	li	a5,1000001536
	li	t3,1
	ld	s1,16(sp)
	addi	a5,a5,-1536
	mul	s1,s1,a5
	ld	a5,24(sp)
	add	a5,s1,a5
	sd	a5,8(sp)
	sllw	s1,t3,s6
	mv	s8,s1
	j	.L59
.L64:
	fence	iorw,iorw
	sw	zero,16(sp)
	ble	s1,zero,.L73
	srlw	s5,s5,s6
	addiw	s5,s5,3
	andi	s5,s5,-4
	sext.w	s5,s5
	j	.L79
.L63:
	sw	s6,48(s0)
	j	.L61
.L85:
	li	a3,5
	j	.L40
.L82:
	li	a3,2
	j	.L40
.L83:
	li	a3,3
	j	.L40
.L84:
	li	a3,4
	j	.L40
.L86:
	li	a3,6
	j	.L40
.L87:
	li	a3,7
	j	.L40
.L88:
	li	a3,8
	j	.L40
.L89:
	li	a3,9
	j	.L40
.L90:
	li	a3,10
	j	.L40
.L91:
	li	a3,11
	j	.L40
.L92:
	li	a3,12
	j	.L40
.L93:
	li	a3,13
	j	.L40
.L94:
	li	a3,14
	j	.L40
	.cfi_endproc
.LFE1265:
	.size	cmmcParallelFor, .-cmmcParallelFor
	.align	1
	.globl	cmmcCacheLookup
	.type	cmmcCacheLookup, @function
cmmcCacheLookup:
.LFB1267:
	.cfi_startproc
	slli	a1,a1,32
	li	a5,1021
	or	a2,a1,a2
	remu	a5,a2,a5
	slli	a5,a5,4
	add	a0,a0,a5
	lw	a5,12(a0)
	beq	a5,zero,.L125
	ld	a5,0(a0)
	beq	a5,a2,.L122
	sw	zero,12(a0)
.L125:
	sd	a2,0(a0)
.L122:
	ret
	.cfi_endproc
.LFE1267:
	.size	cmmcCacheLookup, .-cmmcCacheLookup
	.align	1
	.globl	cmmcAddRec3SRem
	.type	cmmcAddRec3SRem, @function
cmmcAddRec3SRem:
.LFB1268:
	.cfi_startproc
	addi	a5,a0,-1
	mul	a5,a5,a0
	srli	a0,a5,63
	add	a0,a0,a5
	srai	a0,a0,1
	rem	a0,a0,a1
	sext.w	a0,a0
	ret
	.cfi_endproc
.LFE1268:
	.size	cmmcAddRec3SRem, .-cmmcAddRec3SRem
	.align	1
	.globl	cmmcReduceAddI32
	.type	cmmcReduceAddI32, @function
cmmcReduceAddI32:
.LFB1269:
	.cfi_startproc
	fence iorw,ow; amoadd.w.aq zero,a1,0(a0)
	ret
	.cfi_endproc
.LFE1269:
	.size	cmmcReduceAddI32, .-cmmcReduceAddI32
	.align	1
	.globl	cmmcReduceAddF32
	.type	cmmcReduceAddF32, @function
cmmcReduceAddF32:
.LFB1270:
	.cfi_startproc
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	fence	iorw,iorw
	lw	a5,0(a0)
	fence	iorw,iorw
	fmv.w.x	fa5,a5
	addi	a2,sp,12
	sw	a5,12(sp)
.L131:
	fadd.s	fa5,fa0,fa5
	lw	a5,0(a2)
	fmv.x.w	a4,fa5
	fence iorw,ow;  1: lr.w.aq a3,0(a0); bne a3,a5,1f; sc.w.aq a6,a4,0(a0); bnez a6,1b; 1:
	subw	a5,a3,a5
	seqz	a4,a5
	beq	a5,zero,.L129
	sw	a3,0(a2)
.L129:
	zext.w	a5,a4
	beq	a5,zero,.L133
	addi	sp,sp,16
	.cfi_remember_state
	.cfi_def_cfa_offset 0
	jr	ra
.L133:
	.cfi_restore_state
	flw	fa5,12(sp)
	j	.L131
	.cfi_endproc
.LFE1270:
	.size	cmmcReduceAddF32, .-cmmcReduceAddF32
	.bss
	.align	3
	.set	.LANCHOR0,. + 0
	.type	_ZN12_GLOBAL__N_17workersE, @object
	.size	_ZN12_GLOBAL__N_17workersE, 192
_ZN12_GLOBAL__N_17workersE:
	.zero	192
	.type	_ZL13parallelCache, @object
	.size	_ZL13parallelCache, 896
_ZL13parallelCache:
	.zero	896
	.type	_ZL9lookupPtr, @object
	.size	_ZL9lookupPtr, 4
_ZL9lookupPtr:
	.zero	4
	.ident	"GCC: (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0"
	.section	.note.GNU-stack,"",@progbits
)"