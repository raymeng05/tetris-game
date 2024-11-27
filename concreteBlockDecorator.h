#ifndef CONCRETEBLOCKDECORATOR_H
#define CONCRETEBLOCKDECORATOR_H

#include "blockDecorator.h"

class ConcreteBlockDecorator : public BlockDecorator {
public:
    ConcreteBlockDecorator(std::unique_ptr<Block> block);
    void rotateCW() override;
    void rotateCCW() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif 
