// This file was automatically generated using tools/process_csv.py
// Generated on Thu Jun 25 2020 20:31:26 UTC

#include "main.h"
#include "minecraft/VanillaBlockRegistry.h"
#include "minecraft/VanillaBlockTypeRegistry.h"

Block** VanillaBlocks::mCobblestone;
Block** VanillaBlocks::mGoldOre;
Block** VanillaBlocks::mIronOre;
Block** VanillaBlocks::mCoalOre;
Block** VanillaBlocks::mLapisOre;
Block** VanillaBlocks::mDiamondOre;
Block** VanillaBlocks::mRedStoneOre;
Block** VanillaBlocks::mEmeraldOre;
WeakPtr<BlockLegacy>* VanillaBlockTypes::mCobblestone;

extern "C" {
	void* _getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr;
	void* __genRandInt32_Random_Core__AEAAIXZ_ptr;
	void* _solidify_LiquidBlock__QEAA_NAEAVBlockSource__AEBVBlockPos__1_Z_ptr;
}

static std::unordered_map<std::string, size_t> pointerList[12];

void InitBedrockPointers() {
	pointerList[0]["1.14.60.5"] = 0x1651D80;
	pointerList[0]["1.16.0.2"] = 0x176A720;
	pointerList[1]["1.14.60.5"] = 0x01AC370;
	pointerList[1]["1.16.0.2"] = 0x01D2B70;
	pointerList[2]["1.14.60.5"] = 0x16C86C0;
	pointerList[2]["1.16.0.2"] = 0x17E1D00;
	pointerList[3]["1.14.60.5"] = 0x3051570;
	pointerList[3]["1.16.0.2"] = 0x38543A0;
	pointerList[4]["1.14.60.5"] = 0x3051610;
	pointerList[4]["1.16.0.2"] = 0x3854FA8;
	pointerList[5]["1.14.60.5"] = 0x30515F0;
	pointerList[5]["1.16.0.2"] = 0x3854F88;
	pointerList[6]["1.14.60.5"] = 0x3051600;
	pointerList[6]["1.16.0.2"] = 0x3854F98;
	pointerList[7]["1.14.60.5"] = 0x3051640;
	pointerList[7]["1.16.0.2"] = 0x3854FC0;
	pointerList[8]["1.14.60.5"] = 0x3051630;
	pointerList[8]["1.16.0.2"] = 0x3854FB0;
	pointerList[9]["1.14.60.5"] = 0x3051650;
	pointerList[9]["1.16.0.2"] = 0x3854FD0;
	pointerList[10]["1.14.60.5"] = 0x3051418;
	pointerList[10]["1.16.0.2"] = 0x3854E08;
	pointerList[11]["1.14.60.5"] = 0x3061478;
	pointerList[11]["1.16.0.2"] = 0x3865EC0;
}

void InitVersionPointers(std::string versionId) {
	_getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(pointerList[0][versionId]));
	__genRandInt32_Random_Core__AEAAIXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(pointerList[1][versionId]));
	_solidify_LiquidBlock__QEAA_NAEAVBlockSource__AEBVBlockPos__1_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(pointerList[2][versionId]));
	VanillaBlocks::mCobblestone = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(pointerList[3][versionId]));
	VanillaBlocks::mGoldOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(pointerList[4][versionId]));
	VanillaBlocks::mIronOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(pointerList[5][versionId]));
	VanillaBlocks::mCoalOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(pointerList[6][versionId]));
	VanillaBlocks::mLapisOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(pointerList[7][versionId]));
	VanillaBlocks::mDiamondOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(pointerList[8][versionId]));
	VanillaBlocks::mRedStoneOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(pointerList[9][versionId]));
	VanillaBlocks::mEmeraldOre = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(pointerList[10][versionId]));
	VanillaBlockTypes::mCobblestone = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(pointerList[11][versionId]));
}

#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
	if(fdwReason == DLL_PROCESS_ATTACH) InitBedrockPointers();
	return TRUE;
}
