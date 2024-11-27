#include "jBlock.h"

JBlock::JBlock() : Block(BlockType::J, 0, 0, 0) {
    shape = {
        {'J', ' ', ' '},
        {'J', 'J', 'J'}
    };
}

void JBlock::rotateCW() {
    Block::rotateCW();
}

void JBlock::rotateCCW() {
    Block::rotateCCW();
}

void JBlock::moveLeft() {
    Block::moveLeft();
}

void JBlock::moveRight() {
    Block::moveRight();
}

void JBlock::moveDown() {
    Block::moveDown();
}
