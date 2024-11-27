#include "lBlock.h"

LBlock::LBlock() : Block(BlockType::L, 0, 0, 0) {
    shape = {
        {' ', ' ', 'L'},
        {'L', 'L', 'L'}
    };
}

void LBlock::rotateCW() {
    Block::rotateCW();
}

void LBlock::rotateCCW() {
    Block::rotateCCW();
}

void LBlock::moveLeft() {
    Block::moveLeft();
}

void LBlock::moveRight() {
    Block::moveRight();
}

void LBlock::moveDown() {
    Block::moveDown();
}
