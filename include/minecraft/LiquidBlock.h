#pragma once

class BlockSource;
class BlockPos;

class LiquidBlock {
public:
	bool solidify(BlockSource&, const BlockPos&, const BlockPos&);
};