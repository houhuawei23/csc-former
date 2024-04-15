// Automatically generated file, do not edit!
R"(	.arch armv7
	.fpu vfpv4
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"cmmc_sysy_rt.cpp"
	.text
	.align	1
	.p2align 2,,3
	.syntax unified
	.thumb
	.thumb_func
	.type	_ZN12_GLOBAL__N_110cmmcWorkerEPv, %function
_ZN12_GLOBAL__N_110cmmcWorkerEPv:
	.fnstart
.LFB1238:
	@ args = 0, pretend = 0, frame = 128
	@ frame_needed = 0, uses_anonymous_args = 0
	.save {r4, r5, r6, r7, r8, r9, r10, lr}
	strd	r4, r5, [sp, #-32]!
	mov	r5, r0
	strd	r6, r7, [sp, #8]
	strd	r8, r9, [sp, #16]
	strd	r10, lr, [sp, #24]
	dmb	ish
	.pad #144
	sub	sp, sp, #144
	ldr	r3, [r0, #8]
	dmb	ish
	cmp	r3, #1024
	it	cs
	addcs	r4, sp, #16
	bcs	.L2
	lsr	r1, r3, #5
	add	r4, sp, #16
	and	r3, r3, #31
	mov	r2, #1
	lsl	r2, r2, r3
	ldr	r3, [r4, r1, lsl #2]
	orr	r3, r3, r2
	str	r3, [r4, r1, lsl #2]
.L2:
	mov	r0, #224
	add	r7, r5, #12
	bl	syscall(PLT)
	mov	r2, r4
	mov	r1, #128
	add	r8, r5, #28
	mov	r4, #0
	add	r6, r5, #32
	bl	sched_setaffinity(PLT)
	b	.L6
.L28:
	dmb	ish
.L20:
	ldrex	r3, [r8]
	cmp	r3, #1
	bne	.L21
	strex	r2, r4, [r8]
	cmp	r2, #0
	bne	.L20
.L21:
	ite	ne
	movne	r9, #0
	moveq	r9, #1
	dmb	ish
	it	ne
	movne	r10, r9
	bne	.L4
.L7:
	dmb	ish
	ldr	r3, [r7]
	dmb	ish
	cbz	r3, .L5
	dmb	ish
	dmb	ish
	ldr	r3, [r5, #16]
	dmb	ish
	dmb	ish
	ldr	r0, [r5, #20]
	dmb	ish
	dmb	ish
	ldr	r1, [r5, #24]
	dmb	ish
	blx	r3
	dmb	ish
	dmb	ish
	mov	r3, #1
.L22:
	ldrex	r2, [r6]
	cmp	r2, #0
	bne	.L23
	strex	r1, r3, [r6]
	cmp	r1, #0
	bne	.L22
.L23:
	dmb	ish
	bne	.L6
	mov	r2, r3
	mov	r1, r6
	strd	r4, r4, [sp]
	mov	r0, #240
	str	r4, [sp, #8]
	bl	syscall(PLT)
.L6:
	dmb	ish
	ldr	r3, [r7]
	dmb	ish
	cmp	r3, #0
	bne	.L28
.L5:
	mov	r0, #0
	add	sp, sp, #144
	ldrd	r4, r5, [sp]
	@ sp needed
	ldrd	r6, r7, [sp, #8]
	ldrd	r8, r9, [sp, #16]
	add	sp, sp, #24
	pop	{r10, pc}
.L4:
	mov	r3, #0
	mov	r1, r8
	strd	r9, r9, [sp]
	mov	r0, #240
	mov	r2, r3
	str	r9, [sp, #8]
	bl	syscall(PLT)
	dmb	ish
.L24:
	ldrex	r3, [r8]
	cmp	r3, #1
	bne	.L25
	strex	r2, r10, [r8]
	cmp	r2, #0
	bne	.L24
.L25:
	dmb	ish
	beq	.L7
	b	.L4
	.fnend
	.size	_ZN12_GLOBAL__N_110cmmcWorkerEPv, .-_ZN12_GLOBAL__N_110cmmcWorkerEPv
	.section	.text.startup,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	cmmcInitRuntime
	.syntax unified
	.thumb
	.thumb_func
	.type	cmmcInitRuntime, %function
cmmcInitRuntime:
	.fnstart
.LFB1239:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	strd	r4, r5, [sp, #-24]!
	mov	r5, #0
	ldr	r4, .L33
	strd	r6, r7, [sp, #8]
	mov	r7, #34
	movt	r7, 2
	strd	r8, lr, [sp, #16]
	mov	r6, #3840
	movt	r6, 5
	ldr	r8, .L33+4
	sub	sp, sp, #8
.LPIC0:
	add	r4, pc
	add	r4, r4, #12
.LPIC1:
	add	r8, pc
.L30:
	mov	lr, #1
	mov	ip, #-1
	dmb	ish
	mov	r0, #0
	mov	r3, r7
	mov	r2, #3
	mov	r1, #1048576
	str	lr, [r4]
	dmb	ish
	strd	ip, r0, [sp]
	bl	mmap(PLT)
	mov	r1, r0
	sub	r3, r4, #12
	mov	r2, r6
	mov	r0, r8
	str	r1, [r4, #-8]
	dmb	ish
	add	r4, r4, #36
	str	r5, [r4, #-40]
	dmb	ish
	add	r5, r5, #1
	ldr	r1, [r4, #-44]
	add	r1, r1, #1048576
	bl	clone(PLT)
	cmp	r5, #4
	str	r0, [r4, #-48]
	bne	.L30
	add	sp, sp, #8
	ldrd	r4, r5, [sp]
	@ sp needed
	ldrd	r6, r7, [sp, #8]
	add	sp, sp, #16
	pop	{r8, pc}
.L34:
	.align	2
.L33:
	.word	.LANCHOR0-(.LPIC0+4)
	.word	_ZN12_GLOBAL__N_110cmmcWorkerEPv-(.LPIC1+4)
	.cantunwind
	.fnend
	.size	cmmcInitRuntime, .-cmmcInitRuntime
	.section	.init_array,"aw"
	.align	2
	.word	cmmcInitRuntime
	.section	.text.exit,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	cmmcUninitRuntime
	.syntax unified
	.thumb
	.thumb_func
	.type	cmmcUninitRuntime, %function
cmmcUninitRuntime:
	.fnstart
.LFB1240:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.save {r4, r5, r6, r7, lr}
	str	r4, [sp, #-20]!
	strd	r5, r6, [sp, #4]
	mov	r5, #0
	ldr	r6, .L43
	strd	r7, lr, [sp, #12]
	.pad #20
	sub	sp, sp, #20
	mov	r7, #1
.LPIC2:
	add	r6, pc
	add	r4, r6, #28
	add	r6, r6, #172
.L39:
	dmb	ish
	str	r5, [r4, #-16]
	dmb	ish
	dmb	ish
.L40:
	ldrex	r3, [r4]
	cmp	r3, #0
	bne	.L41
	strex	r2, r7, [r4]
	cmp	r2, #0
	bne	.L40
.L41:
	mov	r3, #1
	mov	r1, r4
	dmb	ish
	mov	r2, r3
	mov	r0, #240
	ite	eq
	moveq	ip, r3
	movne	ip, #0
	bne	.L36
	strd	r5, r5, [sp]
	add	r4, r4, #36
	str	r5, [sp, #8]
	bl	syscall(PLT)
	mov	r2, #0
	ldr	r0, [r4, #-64]
	mov	r1, r2
	bl	waitpid(PLT)
	cmp	r6, r4
	bne	.L39
.L35:
	add	sp, sp, #20
	ldrd	r4, r5, [sp]
	@ sp needed
	ldrd	r6, r7, [sp, #8]
	add	sp, sp, #16
	ldr	pc, [sp], #4
.L36:
	ldr	r0, [r4, #-28]
	mov	r2, ip
	mov	r1, ip
	adds	r4, r4, #36
	bl	waitpid(PLT)
	cmp	r4, r6
	bne	.L39
	b	.L35
.L44:
	.align	2
.L43:
	.word	.LANCHOR0-(.LPIC2+4)
	.fnend
	.size	cmmcUninitRuntime, .-cmmcUninitRuntime
	.section	.fini_array,"aw"
	.align	2
	.word	cmmcUninitRuntime
	.text
	.align	1
	.p2align 2,,3
	.global	cmmcParallelFor
	.syntax unified
	.thumb
	.thumb_func
	.type	cmmcParallelFor, %function
cmmcParallelFor:
	.fnstart
.LFB1244:
	@ args = 0, pretend = 0, frame = 48
	@ frame_needed = 0, uses_anonymous_args = 0
	cmp	r0, r1
	bge	.L133
	.save {r4, r5, r6, r7, r8, r9, r10, fp, lr}
	str	r4, [sp, #-36]!
	mov	r3, r1
	strd	r5, r6, [sp, #4]
	mov	r5, r0
	strd	r7, r8, [sp, #12]
	sub	r7, r1, r0
	cmp	r7, #15
	strd	r9, r10, [sp, #20]
	strd	fp, lr, [sp, #28]
	.pad #68
	sub	sp, sp, #68
	bgt	.L47
	add	sp, sp, #68
	ldrd	r4, r5, [sp]
	@ sp needed
	ldrd	r6, r7, [sp, #8]
	ldrd	r8, r9, [sp, #16]
	ldrd	r10, fp, [sp, #24]
	add	sp, sp, #32
	ldr	lr, [sp], #4
	bx	r2	@ indirect register sibling call
.L47:
	ldr	r9, .L143
	mov	ip, #16
	mov	r8, #0
	ldr	fp, .L143+4
	ldr	r10, .L143+8
.LPIC5:
	add	r9, pc
	ldr	r1, [r9, #912]
.LPIC4:
	add	fp, pc
	add	fp, fp, #144
.LPIC6:
	add	r10, pc
	add	r10, r10, #144
	b	.L52
.L138:
	add	r4, lr, r1
	add	r4, r10, r4, lsl #4
.L48:
	add	r0, lr, r1
	add	r0, r9, r0, lsl #4
	ldrb	r6, [r0, #152]	@ zero_extendqisi2
	cbz	r6, .L49
	ldr	r6, [r0, #144]
	cmp	r6, r2
	beq	.L136
.L49:
	subs	ip, ip, #1
	add	r1, r1, #1
	mov	r8, #1
	beq	.L137
.L52:
	cmp	r1, #16
	lsl	lr, r1, #1
	bne	.L138
	mov	r1, #0
	mov	r8, #1
	mov	r4, fp
	mov	lr, r1
	b	.L48
.L136:
	ldr	r0, [r0, #148]
	cmp	r7, r0
	bne	.L49
	cmp	r8, #0
	beq	.L50
	str	r1, [r9, #912]
.L50:
	add	lr, lr, r1
	ldr	r1, .L143+12
.LPIC11:
	add	r1, pc
	add	r1, r1, lr, lsl #4
	ldr	r0, [r1, #156]
	add	r0, r0, #1
	str	r0, [r1, #156]
	b	.L51
.L137:
	ldr	r1, .L143+16
.LPIC13:
	add	r1, pc
	ldrb	r0, [r1, #152]	@ zero_extendqisi2
	cmp	r0, #0
	beq	.L53
	ldrb	r0, [r1, #200]	@ zero_extendqisi2
	cmp	r0, #0
	beq	.L93
	ldrb	r0, [r1, #248]	@ zero_extendqisi2
	cmp	r0, #0
	beq	.L94
	ldrb	r0, [r1, #296]	@ zero_extendqisi2
	cmp	r0, #0
	beq	.L95
	ldrb	r0, [r1, #344]	@ zero_extendqisi2
	cmp	r0, #0
	beq	.L96
	ldrb	r0, [r1, #392]	@ zero_extendqisi2
	cmp	r0, #0
	beq	.L97
	ldrb	r0, [r1, #440]	@ zero_extendqisi2
	cmp	r0, #0
	beq	.L98
	ldrb	r0, [r1, #488]	@ zero_extendqisi2
	cmp	r0, #0
	beq	.L99
	ldrb	r1, [r1, #536]	@ zero_extendqisi2
	cmp	r1, #0
	beq	.L100
	ldr	r6, .L143+20
.LPIC23:
	add	r6, pc
	ldrb	r1, [r6, #584]	@ zero_extendqisi2
	cmp	r1, #0
	beq	.L101
	ldrb	r1, [r6, #632]	@ zero_extendqisi2
	cmp	r1, #0
	beq	.L102
	ldrb	r1, [r6, #680]	@ zero_extendqisi2
	cmp	r1, #0
	beq	.L103
	ldrb	r1, [r6, #728]	@ zero_extendqisi2
	cmp	r1, #0
	beq	.L104
	ldrb	r1, [r6, #776]	@ zero_extendqisi2
	cmp	r1, #0
	beq	.L105
	ldrb	r1, [r6, #824]	@ zero_extendqisi2
	cmp	r1, #0
	beq	.L106
	ldrb	r1, [r6, #872]	@ zero_extendqisi2
	cmp	r1, #0
	beq	.L139
	ldr	r1, [r6, #156]
	add	r4, r6, #144
	ldr	r0, [r6, #204]
	cmp	r0, r1
	it	cc
	movcc	r1, r0
	ldr	r0, [r6, #252]
	it	cc
	movcc	ip, #1
	cmp	r0, r1
	it	cc
	movcc	r1, r0
	ldr	r0, [r6, #300]
	it	cc
	movcc	ip, #2
	cmp	r0, r1
	it	cc
	movcc	r1, r0
	ldr	r0, [r6, #348]
	it	cc
	movcc	ip, #3
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #396]
	it	hi
	movhi	ip, #4
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #444]
	it	hi
	movhi	ip, #5
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #492]
	it	hi
	movhi	ip, #6
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #540]
	it	hi
	movhi	ip, #7
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #588]
	it	hi
	movhi	ip, #8
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #636]
	it	hi
	movhi	ip, #9
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #684]
	it	hi
	movhi	ip, #10
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #732]
	it	hi
	movhi	ip, #11
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #780]
	it	hi
	movhi	ip, #12
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #828]
	it	hi
	movhi	ip, #13
	cmp	r1, r0
	it	hi
	movhi	r1, r0
	ldr	r0, [r6, #876]
	it	hi
	movhi	ip, #14
	cmp	r0, r1
	it	cc
	movcc	ip, #15
	mov	r1, #1
	str	ip, [r6, #912]
	add	ip, ip, ip, lsl #1
	lsl	ip, ip, #4
	add	r6, r6, ip
	add	r4, r4, ip
	strd	r2, r7, [r6, #144]
	str	r1, [r6, #156]
.L51:
	ldr	r1, [r4, #12]
	cmp	r1, #99
	bls	.L70
	cmp	r1, #159
	bls	.L140
	ldr	r1, [r4, #40]
	str	r1, [sp, #24]
	cmp	r1, #0
	bne	.L73
	ldrd	ip, r6, [r4, #16]
	ldrd	r0, r1, [r4, #24]
	cmp	r0, ip
	sbcs	lr, r1, r6
	bge	.L74
	mov	r6, r1
	mov	ip, r0
	mov	r1, #1
	str	r1, [sp, #24]
.L74:
	ldrd	r0, r1, [r4, #32]
	cmp	r0, ip
	sbcs	r6, r1, r6
	itt	lt
	movlt	r1, #2
	strlt	r1, [r4, #40]
	bge	.L141
.L70:
	lsr	r7, r7, #2
	mov	r1, #0
	mov	ip, #4
	dmb	ish
	mov	r8, ip
	add	r7, r7, #3
	str	r1, [sp, #28]
	bic	r7, r7, #3
	str	r1, [sp, #56]
	mov	r1, #2
	str	r1, [sp, #24]
.L91:
	ldr	r1, .L143+24
	mov	r6, #0
	add	r0, sp, #56
	add	r10, ip, #-1
	mov	fp, #1
	mov	r9, r6
	strd	r0, r2, [sp, #32]
	strd	r4, ip, [sp, #40]
	mov	r4, r3
.LPIC57:
	add	r1, pc
	add	r1, r1, #28
.L84:
	mov	r2, r5
	add	r5, r5, r7
	cmp	r5, r4
	mov	r3, r5
	it	ge
	movge	r3, r4
	cmp	r10, r6
	it	eq
	moveq	r3, r4
	cmp	r3, r2
	ble	.L82
	dmb	ish
	ldr	r0, [sp, #36]
	str	r0, [r1, #-12]
	dmb	ish
	dmb	ish
	str	r2, [r1, #-8]
	dmb	ish
	dmb	ish
	str	r3, [r1, #-4]
	dmb	ish
	dmb	ish
.L130:
	ldrex	r3, [r1]
	cmp	r3, #0
	bne	.L131
	strex	r2, fp, [r1]
	cmp	r2, #0
	bne	.L130
.L131:
	dmb	ish
	bne	.L83
	mov	r3, #1
	mov	r0, #240
	strd	r9, r9, [sp]
	mov	r2, r3
	str	r9, [sp, #8]
	str	r1, [sp, #20]
	bl	syscall(PLT)
	ldr	r1, [sp, #20]
.L83:
	ldr	r3, [sp, #32]
	strb	fp, [r3, r6]
.L82:
	add	r6, r6, #1
	add	r1, r1, #36
	cmp	r8, r6
	bne	.L84
	ldrd	r4, ip, [sp, #40]
.L85:
	cmp	ip, #0
	beq	.L80
	ldr	r8, .L143+28
	add	r5, sp, #56
	mov	r6, #0
	add	r9, ip, r5
.LPIC58:
	add	r8, pc
	add	r8, r8, #32
.L87:
	ldrb	r3, [r5], #1	@ zero_extendqisi2
	cbnz	r3, .L86
.L88:
	cmp	r5, r9
	add	r8, r8, #36
	bne	.L87
.L80:
	dmb	ish
.L77:
	ldr	r3, [sp, #28]
	cmp	r3, #0
	bne	.L142
.L45:
	add	sp, sp, #68
	ldrd	r4, r5, [sp]
	@ sp needed
	ldrd	r6, r7, [sp, #8]
	ldrd	r8, r9, [sp, #16]
	ldrd	r10, fp, [sp, #24]
	add	sp, sp, #32
	ldr	pc, [sp], #4
.L133:
	bx	lr
.L86:
	dmb	ish
.L128:
	ldrex	r3, [r8]
	cmp	r3, #1
	bne	.L129
	strex	r2, r6, [r8]
	cmp	r2, #0
	bne	.L128
.L129:
	ite	eq
	moveq	r7, #1
	movne	r7, #0
	dmb	ish
	beq	.L88
	mov	r10, r7
.L89:
	movs	r3, #0
	mov	r1, r8
	strd	r7, r7, [sp]
	movs	r0, #240
	mov	r2, r3
	str	r7, [sp, #8]
	bl	syscall(PLT)
	dmb	ish
.L126:
	ldrex	r3, [r8]
	cmp	r3, #1
	bne	.L127
	strex	r2, r10, [r8]
	cmp	r2, #0
	bne	.L126
.L127:
	dmb	ish
	beq	.L88
	b	.L89
.L93:
	mov	ip, r8
.L53:
	ldr	r1, .L143+32
	mov	r0, #1
.LPIC30:
	add	r1, pc
	add	r4, r1, #144
	str	ip, [r1, #912]
	add	ip, ip, ip, lsl #1
	lsl	ip, ip, #4
	add	r1, r1, ip
	add	r4, r4, ip
	strd	r2, r7, [r1, #144]
	strb	r0, [r1, #152]
	str	r0, [r1, #156]
	b	.L51
.L142:
	add	r1, sp, #56
	mov	r0, #1
	bl	clock_gettime(PLT)
	ldr	r3, [sp, #24]
	mov	r1, #51712
	movt	r1, 15258
	ldr	r0, [sp, #56]
	add	r4, r4, r3, lsl #3
	ldr	r3, [sp, #60]
	asr	r2, r3, #31
	smlal	r3, r2, r0, r1
	ldrd	r1, r0, [sp, #48]
	subs	r3, r3, r1
	ldr	r1, [r4, #16]
	sbc	r2, r2, r0
	adds	r1, r1, r3
	ldr	r3, [r4, #20]
	adc	r3, r2, r3
	strd	r1, r3, [r4, #16]
	b	.L45
.L140:
	sub	r1, r1, #100
	movw	r0, #52429
	movt	r0, 52428
	str	r3, [sp, #20]
	mov	r6, #51712
	movt	r6, 15258
	str	r2, [sp, #32]
	umull	r0, r1, r0, r1
	mov	r0, #1
	lsr	r3, r1, #4
	add	r1, sp, #56
	str	r3, [sp, #24]
	bl	clock_gettime(PLT)
	mov	r3, #1
	ldr	r2, [sp, #32]
	ldrd	r0, r1, [sp, #56]
	str	r3, [sp, #28]
	asr	ip, r1, #31
	mov	r3, ip
	smlal	r1, r3, r0, r6
	str	r1, [sp, #48]
	str	r3, [sp, #52]
	ldr	r3, [sp, #20]
.L72:
	mov	r8, #1
	ldr	r1, [sp, #24]
	lsl	r8, r8, r1
	cmp	r8, #1
	mov	ip, r8
	bne	.L76
	mov	r1, r3
	mov	r0, r5
	blx	r2
	b	.L77
.L141:
	ldr	r1, [sp, #24]
	str	r1, [r4, #40]
.L73:
	mov	r1, #0
	str	r1, [sp, #28]
	b	.L72
.L76:
	mov	r1, #0
	dmb	ish
	cmp	r8, r1
	str	r1, [sp, #56]
	ble	.L85
	ldr	r1, [sp, #24]
	lsr	r7, r7, r1
	add	r7, r7, #3
	bic	r7, r7, #3
	b	.L91
.L97:
	mov	ip, #5
	b	.L53
.L94:
	mov	ip, #2
	b	.L53
.L95:
	mov	ip, #3
	b	.L53
.L96:
	mov	ip, #4
	b	.L53
.L98:
	mov	ip, #6
	b	.L53
.L99:
	mov	ip, #7
	b	.L53
.L100:
	mov	ip, #8
	b	.L53
.L101:
	mov	ip, #9
	b	.L53
.L102:
	mov	ip, #10
	b	.L53
.L103:
	mov	ip, #11
	b	.L53
.L104:
	mov	ip, #12
	b	.L53
.L105:
	mov	ip, #13
	b	.L53
.L106:
	mov	ip, #14
	b	.L53
.L139:
	mov	ip, #15
	b	.L53
.L144:
	.align	2
.L143:
	.word	.LANCHOR0-(.LPIC5+4)
	.word	.LANCHOR0-(.LPIC4+4)
	.word	.LANCHOR0-(.LPIC6+4)
	.word	.LANCHOR0-(.LPIC11+4)
	.word	.LANCHOR0-(.LPIC13+4)
	.word	.LANCHOR0-(.LPIC23+4)
	.word	.LANCHOR0-(.LPIC57+4)
	.word	.LANCHOR0-(.LPIC58+4)
	.word	.LANCHOR0-(.LPIC30+4)
	.fnend
	.size	cmmcParallelFor, .-cmmcParallelFor
	.global	__aeabi_uldivmod
	.align	1
	.p2align 2,,3
	.global	cmmcCacheLookup
	.syntax unified
	.thumb
	.thumb_func
	.type	cmmcCacheLookup, %function
cmmcCacheLookup:
	.fnstart
.LFB1246:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	strd	r3, r4, [sp, #-24]!
	mov	r4, r2
	mov	r3, #0
	strd	r5, r6, [sp, #8]
	orr	r5, r1, r2, asr #31
	mov	r6, r0
	movw	r2, #1021
	mov	r0, r4
	strd	r7, lr, [sp, #16]
	mov	r1, r5
	bl	__aeabi_uldivmod(PLT)
	lsl	r2, r2, #4
	add	r0, r6, r2
	ldr	r3, [r0, #12]
	cbz	r3, .L149
	ldr	r1, [r6, r2]
	ldr	r3, [r0, #4]
	cmp	r3, r5
	it	eq
	cmpeq	r1, r4
	beq	.L145
	mov	r7, #0
	str	r7, [r0, #12]
.L149:
	str	r4, [r6, r2]
	str	r5, [r0, #4]
.L145:
	ldrd	r3, r4, [sp]
	ldrd	r5, r6, [sp, #8]
	add	sp, sp, #16
	pop	{r7, pc}
	.cantunwind
	.fnend
	.size	cmmcCacheLookup, .-cmmcCacheLookup
	.global	__aeabi_ldivmod
	.align	1
	.p2align 2,,3
	.global	cmmcAddRec3SRem
	.syntax unified
	.thumb
	.thumb_func
	.type	cmmcAddRec3SRem, %function
cmmcAddRec3SRem:
	.fnstart
.LFB1247:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	asr	ip, r0, #31
	strd	r3, lr, [sp, #-8]!
	subs	r3, r0, #1
	mov	r2, r1
	adc	r1, ip, #-1
	mul	ip, r3, ip
	mla	ip, r0, r1, ip
	umull	lr, r0, r3, r0
	asr	r3, r2, #31
	add	ip, ip, r0
	lsr	r0, ip, #31
	adds	r0, r0, lr
	lsr	lr, r0, #1
	adc	r0, ip, #0
	asr	r1, r0, #1
	orr	r0, lr, r0, lsl #31
	bl	__aeabi_ldivmod(PLT)
	mov	r0, r2
	pop	{r3, pc}
	.cantunwind
	.fnend
	.size	cmmcAddRec3SRem, .-cmmcAddRec3SRem
	.align	1
	.p2align 2,,3
	.global	cmmcReduceAddI32
	.syntax unified
	.thumb
	.thumb_func
	.type	cmmcReduceAddI32, %function
cmmcReduceAddI32:
	.fnstart
.LFB1248:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	dmb	ish
.L153:
	ldrex	r3, [r0]
	add	r3, r3, r1
	strex	r2, r3, [r0]
	cmp	r2, #0
	bne	.L153
	dmb	ish
	bx	lr
	.cantunwind
	.fnend
	.size	cmmcReduceAddI32, .-cmmcReduceAddI32
	.align	1
	.p2align 2,,3
	.global	cmmcReduceAddF32
	.syntax unified
	.thumb
	.thumb_func
	.type	cmmcReduceAddF32, %function
cmmcReduceAddF32:
	.fnstart
.LFB1249:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	dmb	ish
	sub	sp, sp, #12
	ldr	r3, [r0]
	add	r2, sp, #4
	dmb	ish
	vmov	s15, r3
	str	r3, [sp, #4]	@ float
.L157:
	vadd.f32	s15, s0, s15
	ldr	r3, [r2]
	dmb	ish
	vmov	ip, s15	@ int
	ldrex	r1, [r0]
	cmp	r1, r3
	itt	eq
	strexeq	lr, ip, [r0]
	cmpeq	lr, #0
	dmb	ish
	beq	.L154
	str	r1, [r2]
	vldr.32	s15, [sp, #4]
	b	.L157
.L154:
	add	sp, sp, #12
	@ sp needed
	ldr	pc, [sp], #4
	.cantunwind
	.fnend
	.size	cmmcReduceAddF32, .-cmmcReduceAddF32
	.bss
	.align	3
	.set	.LANCHOR0,. + 0
	.type	_ZN12_GLOBAL__N_17workersE, %object
	.size	_ZN12_GLOBAL__N_17workersE, 144
_ZN12_GLOBAL__N_17workersE:
	.space	144
	.type	_ZL13parallelCache, %object
	.size	_ZL13parallelCache, 768
_ZL13parallelCache:
	.space	768
	.type	_ZL9lookupPtr, %object
	.size	_ZL9lookupPtr, 4
_ZL9lookupPtr:
	.space	4
	.ident	"GCC: (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0"
	.section	.note.GNU-stack,"",%progbits
)"