; This file was automatically generated using tools/process_csv.py
; Generated on Thu Jun 25 2020 20:31:26 UTC
bits 64
SECTION .data
extern _getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr
extern __genRandInt32_Random_Core__AEAAIXZ_ptr
extern _solidify_LiquidBlock__QEAA_NAEAVBlockSource__AEBVBlockPos__1_Z_ptr

SECTION .text
global ?getDefaultState@BlockLegacy@@QEBAAEAVBlock@@XZ
?getDefaultState@BlockLegacy@@QEBAAEAVBlock@@XZ:
	mov rax, [rel _getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr]
	jmp rax
global ?_genRandInt32@Random@Core@@AEAAIXZ
?_genRandInt32@Random@Core@@AEAAIXZ:
	mov rax, [rel __genRandInt32_Random_Core__AEAAIXZ_ptr]
	jmp rax
global ?solidify@LiquidBlock@@QEAA_NAEAVBlockSource@@AEBVBlockPos@@1@Z
?solidify@LiquidBlock@@QEAA_NAEAVBlockSource@@AEBVBlockPos@@1@Z:
	mov rax, [rel _solidify_LiquidBlock__QEAA_NAEAVBlockSource__AEBVBlockPos__1_Z_ptr]
	jmp rax
