#ifndef LEVEL_H
#define LEVEL_H
#include "game.h"
#include "block.h"
#include "sBlock.h"
#include "zBlock.h"
#include "tBlock.h"
#include "oBlock.h"
#include "lBlock.h"
#include "iBlock.h"
#include "jBlock.h"

struct Level {
    public:
        int curLevel;
        Level(int curLevel);
        virtual std::unique_ptr<Block> createBlock() = 0;
};

#endif