#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"

class LBlock : public Block {
public:
    LBlock();
    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif
