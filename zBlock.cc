#include "zBlock.h"

ZBlock::ZBlock() : Block(BlockType::Z, 0, 0, 0) {
    shape = {
        {'Z', 'Z', ' '},
        {' ', 'Z', 'Z'}
    };
}

void ZBlock::rotateCW() {
    Block::rotateCW();
}

void ZBlock::rotateCCW() {
    Block::rotateCCW();
}

void ZBlock::moveLeft() {
    Block::moveLeft();
}

void ZBlock::moveRight() {
    Block::moveRight();
}

void ZBlock::moveDown() {
    Block::moveDown();
}
