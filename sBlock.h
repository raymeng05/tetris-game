#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"

class SBlock : public Block {
public:
    SBlock();
    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif
