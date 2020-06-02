; This file was automatically generated using tools/process_csv.py
; Generated on Tue Jun 02 2020 03:15:41 UTC
bits 64
SECTION .data
extern _getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr
extern __genRandInt32_Random_Core__AEAAIXZ_ptr

SECTION .text
global ?getDefaultState@BlockLegacy@@QEBAAEAVBlock@@XZ
?getDefaultState@BlockLegacy@@QEBAAEAVBlock@@XZ:
	mov rax, [rel _getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr]
	jmp rax
global ?_genRandInt32@Random@Core@@AEAAIXZ
?_genRandInt32@Random@Core@@AEAAIXZ:
	mov rax, [rel __genRandInt32_Random_Core__AEAAIXZ_ptr]
	jmp rax
