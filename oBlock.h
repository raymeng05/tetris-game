#ifndef OBLOCK_H
#define OBLOCK_H

#include "block.h"

class OBlock : public Block {
public:
    OBlock();
    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif 
