#pragma once

#include "Random.h"
#include "BlockSourceListener.h"
#include "IWorldRegistriesProvider.h"

class Level : public BlockSourceListener, public IWorldRegistriesProvider {
private:
    char filler[0x8E8]; // 0x8E8
    Random mRandom;     // 0x8F8

public:
    Random& getRandom() {
        return mRandom;
    }
};

class Level2 : public BlockSourceListener, public IWorldRegistriesProvider {
private:
    char filler[0x978]; // 0x010
    Random mRandom;     // 0x988

public:
    Random& getRandom() {
        return mRandom;
    }
};