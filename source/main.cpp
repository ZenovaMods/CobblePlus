// This file was automatically generated using tools/process_csv.py
// Generated on Tue Jun 02 2020 03:15:41 UTC

#include <Zenova/Hook.h>
#include "minecraft/VanillaBlockRegistry.h"
#include "minecraft/VanillaBlockTypeRegistry.h"

Block** VanillaBlocks::mCobblestone = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051570));
Block** VanillaBlocks::mGoldOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051610));
Block** VanillaBlocks::mIronOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x30515F0));
Block** VanillaBlocks::mCoalOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051600));
Block** VanillaBlocks::mLapisOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051640));
Block** VanillaBlocks::mDiamondOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051630));
Block** VanillaBlocks::mRedStoneOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051650));
Block** VanillaBlocks::mEmeraldOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051418));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mCobblestone = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x3061478));

extern "C" {
	void* _getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr;
	void* __genRandInt32_Random_Core__AEAAIXZ_ptr;
}

void InitBedrockPointers() {
	_getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1651D80));
	__genRandInt32_Random_Core__AEAAIXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x01AC370));
}

#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
	if(fdwReason == DLL_PROCESS_ATTACH) InitBedrockPointers();
	return TRUE;
}
