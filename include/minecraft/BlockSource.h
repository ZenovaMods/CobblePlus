#pragma once

#include <thread>
#include <memory>

class Level;

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
};