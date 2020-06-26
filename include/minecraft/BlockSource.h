#pragma once

#include <thread>
#include <memory>

class Level;
class Level2;

class BlockSource {
private:
    const std::thread::id mOwnerThreadID;
    const bool mAllowUnpopulatedChunks;
    const bool mPublicSource;
    Level& mLevel;

public:
    virtual ~BlockSource();
    Level& getLevel() const {
        return mLevel;
    }
    Level& getLevel() {
        return mLevel;
    }
    const Level& getLevelConst() const {
        return mLevel;
    }
    Level2& getLevel2() const {
        return reinterpret_cast<Level2&>(mLevel);
    }
    Level2& getLevel2() {
        return reinterpret_cast<Level2&>(mLevel);
    }
    const Level2& getLevelConst2() const {
        return reinterpret_cast<Level2&>(mLevel);
    }
};