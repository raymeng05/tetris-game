#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "block.h"

class ZBlock : public Block {
public:
    ZBlock();
    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif
