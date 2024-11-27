#include "iBlock.h"

IBlock::IBlock() : Block(BlockType::I, 0, 0, 0) {
    shape = {
        {'I', 'I', 'I', 'I'}
    };
}

void IBlock::rotateCW() {
    Block::rotateCW();
}

void IBlock::rotateCCW() {
    Block::rotateCCW();
}

void IBlock::moveLeft() {
    Block::moveLeft();
}

void IBlock::moveRight() {
    Block::moveRight();
}

void IBlock::moveDown() {
    Block::moveDown();
}
