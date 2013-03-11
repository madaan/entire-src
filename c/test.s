	.file	"test.c"
# GNU C (GCC) version 4.6.1 20110908 (Red Hat 4.6.1-9) (i686-redhat-linux)
#	compiled by GNU C version 4.6.1 20110908 (Red Hat 4.6.1-9), GMP version 4.3.2, MPFR version 3.0.0, MPC version 0.8.3-dev
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  test.c -mtune=generic -march=i686 -fverbose-asm
# options enabled:  -fasynchronous-unwind-tables -fauto-inc-dec
# -fbranch-count-reg -fcommon -fdebug-types-section
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -ffunction-cse -fgcse-lm -fident
# -finline-functions-called-once -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -fmath-errno -fmerge-debug-strings
# -fmove-loop-invariants -fpcc-struct-return -fpeephole
# -fprefetch-loop-arrays -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fshow-column
# -fsigned-zeros -fsplit-ivs-in-unroller -fstrict-volatile-bitfields
# -ftrapping-math -ftree-cselim -ftree-forwprop -ftree-loop-if-convert
# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
# -ftree-parallelize-loops= -ftree-phiprop -ftree-pta -ftree-reassoc
# -ftree-scev-cprop -ftree-slp-vectorize -ftree-vect-loop-version
# -funit-at-a-time -funwind-tables -fvect-cost-model -fverbose-asm
# -fzero-initialized-in-bss -m32 -m80387 -m96bit-long-double
# -maccumulate-outgoing-args -malign-stringops -mfancy-math-387
# -mfp-ret-in-387 -mglibc -mieee-fp -mno-red-zone -mno-sse4 -mpush-args
# -msahf -mtls-direct-seg-refs

# Compiler executable checksum: 7c75a840b33bb054b6c8e0f7ad3bf699

	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp	#
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	#,
	.cfi_def_cfa_register 5
	subl	$16, %esp	#,
	movl	$1, -4(%ebp)	#, a
	movl	$1, -8(%ebp)	#, b
	movl	$1, -12(%ebp)	#, c
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.6.1 20110908 (Red Hat 4.6.1-9)"
	.section	.note.GNU-stack,"",@progbits
