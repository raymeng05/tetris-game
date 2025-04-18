#ifndef TBLOCK_H
#define TBLOCK_H

#include "block.h"

class TBlock : public Block {
public:
    TBlock();
    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif 
