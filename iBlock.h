#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"

class IBlock : public Block {
public:
    IBlock();
    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif
