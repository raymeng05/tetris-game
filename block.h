#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>

enum class BlockType { I, J, L, O, S, Z, T };

class Block {
protected:
    BlockType type;
    int position[2]; // [row, col]
    int orientation; // 0, 90, 180, 270 degrees
    std::vector<std::vector<char>> shape; // 2D vector to represent the block shape

public:
    Block(BlockType type, int row, int col, int orientation);
    virtual ~Block() = default;

    virtual void rotateCW();
    virtual void rotateCCW();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveDown();
    void moveUp(); 
    const std::vector<std::vector<char>>& getShape() const;

    // Getter methods for protected members
    BlockType getType() const;
    int getRow() const;
    int getCol() const;
    int getOrientation() const;
};

#endif 
