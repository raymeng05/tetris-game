#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class JBlock : public Block {
public:
    JBlock();
    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif
