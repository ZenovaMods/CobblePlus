#include "Zenova.h"

#include "minecraft/VanillaBlockRegistry.h"
#include "minecraft/VanillaBlockTypeRegistry.h"
#include "minecraft/BlockSource.h"
#include "minecraft/Level.h"

#include <vector>
#include <tuple>
#include <iostream>
#include <memory>
#include <sstream>
#include <iomanip>

class LiquidBlock;

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

bool (*_solidify)(LiquidBlock*, BlockSource*, BlockPos*, BlockPos*);
bool solidify(LiquidBlock* self, BlockSource* region, BlockPos* pos, BlockPos* changedNeighbor) {
    if (blockWeightList.empty())
        initBlockWeightList();

    *VanillaBlocks::mCobblestone = getRandomBlock(region->getLevel().getRandom());
    bool result = _solidify(self, region, pos, changedNeighbor);
	*VanillaBlocks::mCobblestone = &(*VanillaBlockTypes::mCobblestone)->getDefaultState();
	return result;
}

class CobblePlus : public Zenova::Mod {
	virtual void Start() {
		Zenova::Platform::DebugPause();
		std::cout << "CobblePlus start" << std::endl;

		Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x16C86C0)), solidify, (void**)&_solidify);
	}

	virtual ~CobblePlus() {}
	virtual void Update() {}
	virtual void Tick() {}
	virtual void Stop() {}
};

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new CobblePlus;
}
