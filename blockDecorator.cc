#include "blockDecorator.h"

BlockDecorator::BlockDecorator(std::unique_ptr<Block> block) : Block(BlockType::I, 0, 0, 0), block(std::move(block)) {
}

void BlockDecorator::rotateCW() {
    block->rotateCW();
}

void BlockDecorator::rotateCCW() {
    block->rotateCCW();
}

void BlockDecorator::moveLeft() {
    block->moveLeft();
}

void BlockDecorator::moveRight() {
    block->moveRight();
}

void BlockDecorator::moveDown() {
    block->moveDown();
}
