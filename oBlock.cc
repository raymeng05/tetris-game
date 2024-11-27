#include "oBlock.h"

OBlock::OBlock() : Block(BlockType::O, 0, 0, 0) {
    shape = {
        {'O', 'O'},
        {'O', 'O'}
    };
}

void OBlock::rotateCW() {
    // OBlock does not change shape on rotation
}

void OBlock::rotateCCW() {
    // OBlock does not change shape on rotation
}

void OBlock::moveLeft() {
    Block::moveLeft();
}

void OBlock::moveRight() {
    Block::moveRight();
}

void OBlock::moveDown() {
    Block::moveDown();
}
