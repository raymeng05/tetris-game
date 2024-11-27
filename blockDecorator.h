#ifndef BLOCKDECORATOR_H
#define BLOCKDECORATOR_H

#include <memory>
#include "block.h"

class BlockDecorator : public Block {
protected:
    std::unique_ptr<Block> block;

public:
    BlockDecorator(std::unique_ptr<Block> block);
    virtual ~BlockDecorator() = default;

    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif
