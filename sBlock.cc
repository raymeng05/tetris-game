#include "sBlock.h"

SBlock::SBlock() : Block(BlockType::S, 0, 0, 0) {
    shape = {
        {' ', 'S', 'S'},
        {'S', 'S', ' '}
    };
}

void SBlock::rotateCW() {
    Block::rotateCW();
}

void SBlock::rotateCCW() {
    Block::rotateCCW();
}

void SBlock::moveLeft() {
    Block::moveLeft();
}

void SBlock::moveRight() {
    Block::moveRight();
}

void SBlock::moveDown() {
    Block::moveDown();
}
