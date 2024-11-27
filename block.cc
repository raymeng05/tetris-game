#include "block.h"

Block::Block(BlockType type, int row, int col, int orientation)
    : type(type), orientation(orientation) {
    position[0] = row;
    position[1] = col;
}
// [ [ 1, 1, 0 ], 
//   [ 0, 1, 1 ] ]
// counter clockwise rotation
// [ [ 0, 1 ]
//   [ 1, 1 ]
//   [ 1, 0 ] ]
// n = 2

void Block::rotateCW() {
    // Rotate the shape 90 degrees clockwise
    int rows = shape.size();    // number of rows
    int cols = shape[0].size(); // number of columns
    std::vector<std::vector<char>> newShape(cols, std::vector<char>(rows));

    // Fill in the newShape by rotating clockwise
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newShape[j][rows - 1 - i] = shape[i][j];
        }
    }
    
    shape = newShape;
    orientation = (orientation + 90) % 360;
}

void Block::rotateCCW() {
    // Rotate the shape 90 degrees counterclockwise
    int rows = shape.size();    // number of rows
    int cols = shape[0].size(); // number of columns
    std::vector<std::vector<char>> newShape(cols, std::vector<char>(rows));

    // Fill in the newShape by rotating counter-clockwise
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newShape[cols - 1 - j][i] = shape[i][j];
        }
    }

    shape = newShape;
    orientation = (orientation + 270) % 360;
}

void Block::moveLeft() {
    position[1]--;
}

void Block::moveRight() {
    position[1]++;
}

void Block::moveDown() {
    position[0]++;
}

void Block::moveUp() {
    position[0]--;
}

const std::vector<std::vector<char>>& Block::getShape() const {
    return shape;
}

BlockType Block::getType() const {
    return type;
}

int Block::getRow() const {
    return position[0];
}

int Block::getCol() const {
    return position[1];
}

int Block::getOrientation() const {
    return orientation;
}
