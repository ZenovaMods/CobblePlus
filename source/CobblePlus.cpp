#include "CobblePlus.h"
#include "main.h"

#include "minecraft/VanillaBlockRegistry.h"
#include "minecraft/VanillaBlockTypeRegistry.h"
#include "minecraft/BlockSource.h"
#include "minecraft/Level.h"
#include "minecraft/LiquidBlock.h"

#include <vector>
#include <tuple>
#include <iostream>
#include <memory>
#include <sstream>
#include <iomanip>

std::vector<std::pair<int, Block**>> blockWeightList = {};
int totalWeight = 1;

void initBlockWeightList() {
    blockWeightList.emplace_back(55, VanillaBlocks::mCobblestone);
    blockWeightList.emplace_back(16, VanillaBlocks::mCoalOre);
    blockWeightList.emplace_back(8, VanillaBlocks::mRedStoneOre);
    blockWeightList.emplace_back(7, VanillaBlocks::mIronOre);
    blockWeightList.emplace_back(6, VanillaBlocks::mGoldOre);
    blockWeightList.emplace_back(5, VanillaBlocks::mLapisOre);
    blockWeightList.emplace_back(2, VanillaBlocks::mDiamondOre);
    blockWeightList.emplace_back(1, VanillaBlocks::mEmeraldOre);

    for(auto& weight : blockWeightList)
        totalWeight += weight.first;
}

Block* getRandomBlock(Random& random) {
	int roll = random.nextInt(totalWeight);
	for (auto& weight : blockWeightList) {
		roll -= weight.first;
		if (roll <= 0)
			return *weight.second;
	}
}

bool (*_solidify)(LiquidBlock*, BlockSource&, const BlockPos&, const BlockPos&);
bool solidify(LiquidBlock* self, BlockSource& region, const BlockPos& pos, const BlockPos& changedNeighbor) {
    if (blockWeightList.empty())
        initBlockWeightList();

	Random& random = CobblePlus::versionId == "1.14.60.5" ? region.getLevel().getRandom() : region.getLevel2().getRandom();
    *VanillaBlocks::mCobblestone = getRandomBlock(random);
    bool result = _solidify(self, region, pos, changedNeighbor);
	*VanillaBlocks::mCobblestone = &(*VanillaBlockTypes::mCobblestone)->getDefaultState();
	return result;
}

std::string CobblePlus::versionId;

void CobblePlus::Start() {
	Zenova::Platform::DebugPause();
	Zenova_Info("CobblePlus start");

	versionId = GetManager().GetLaunchedVersion();
	InitVersionPointers(versionId);

	Zenova::Hook::Create(&LiquidBlock::solidify, &solidify, &_solidify);
}

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new CobblePlus;
}
