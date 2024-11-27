#include "tBlock.h"

TBlock::TBlock() : Block(BlockType::T, 0, 0, 0) {
    shape = {
        {'T', 'T', 'T'},
        {' ', 'T', ' '}
    };
}

void TBlock::rotateCW() {
    Block::rotateCW();
}

void TBlock::rotateCCW() {
    Block::rotateCCW();
}

void TBlock::moveLeft() {
    Block::moveLeft();
}

void TBlock::moveRight() {
    Block::moveRight();
}

void TBlock::moveDown() {
    Block::moveDown();
}
