#ifndef BOARD_H
#define BOARD_H

#include "block.h"
#include "level.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "concreteTextObserver.h"

class ConcreteTextObserver;
class Level;

class Board {
public:
    Board(int rows, int cols, const std::string& name, int level = 0);
    void setCurrentBlock();
    void setNextBlock();
    void placeCurBlockOnGrid();
    bool isValidPosition(const Block& block);
    void placeBlockOnGrid(const Block& block);
    bool moveBlockLeft();
    bool moveBlockRight();
    bool moveBlockDown();
    void rotateBlockCW();
    void rotateBlockCCW();
    void clearBlockFromGrid(const Block& block);
    void dropBlock();
    void clearFullRows();
    void generateNextBlock();
    void display() const;
    bool isGameOver() const;
    void notifyObservers();

    const std::string& getName() const;
    int getScore() const;
    int getLevel() const;
    void increaseScore(int points);
    void levelUp();
    void levelDown();
    void reset();

private:
    int rows;
    int cols;
    std::vector<std::vector<char>> grid;
    std::unique_ptr<Block> currentBlock;
    std::unique_ptr<Block> nextBlock;
    std::unique_ptr<Level> level;
    std::string name;
    int score;
    int playerLevel;
    std::unique_ptr<ConcreteTextObserver> cto;
};

#endif
