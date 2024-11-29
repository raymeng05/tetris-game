#include "board.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

Board::Board(int rows, int cols, const std::string& name, int level, std::string f1)
    : rows(rows), cols(cols), grid(rows, std::vector<char>(cols, ' ')), name(name), score(0), playerLevel(level), f1{f1} {
        if (playerLevel == 0) {
            this->level = std::make_unique<Level0>(Level0{level, f1});
        } else if (playerLevel == 1) {
            this->level = std::make_unique<Level1>(Level1{level});
        } else if (playerLevel == 2) {
            this->level = std::make_unique<Level2>(Level2{level});
        } else if (playerLevel == 3) {
            this->level = std::make_unique<Level3>(Level3{level});
        } else {
            this->level = std::make_unique<Level4>(Level4{level});
        }
    }


void Board::placeCurBlockOnGrid() {
    const auto& shape = currentBlock->getShape();
    int row = currentBlock->getRow();
    int col = currentBlock->getCol();

    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            grid[row + i][col + j] = shape[i][j];
        }
    }
}

void Board::switchCurrentBlock() {
    currentBlock = std::move(nextBlock);
}

void Board::setCurBlock(char bl) {
    switch(bl) {
        case 'S': 
            this->currentBlock = std::make_unique<SBlock>();
            break;
        case 'Z': 
            this->currentBlock = std::make_unique<ZBlock>();
            break;
        case 'T': 
            this->currentBlock = std::make_unique<TBlock>();
            break;
        case 'O': 
            this->currentBlock = std::make_unique<OBlock>();
            break;
        case 'L': 
            this->currentBlock = std::make_unique<LBlock>();
            break;
        case 'I': 
            this->currentBlock = std::make_unique<IBlock>();
            break;
        case 'J': 
            this->currentBlock = std::make_unique<JBlock>();
            break;
    }
}

void Board::setNextBlock() {
    nextBlock = level->createBlock();
}


bool Board::isValidPosition(const Block& block) {
    const auto& shape = block.getShape();
    int row = block.getRow();
    int col = block.getCol();
    //cout << "check position row: " << row << " col: " << col << endl;
    // Temporarily remove the block from the grid
    bool isValid = true;

    for (int i = 0; i < shape.size(); ++i) {
        
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != ' ') {
                int newRow = row + i;
                int newCol = col + j;
                // Check if the new position is out of bounds
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    isValid = false;
                    break;
                }
                if (grid[newRow][newCol] != ' ') {
                    isValid = false;
                    break;
                }
            }
        }
        if (!isValid) return false;
    }
    //cout << "reached end" << endl;
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != ' ') {
                grid[row + i][col + j] = ' ';
            }
        }
    }

    return isValid;
}



void Board::placeBlockOnGrid(const Block& block) {
    const auto& shape = block.getShape();
    int row = block.getRow();
    int col = block.getCol();

    //std::cout << "Placing block at row: " << row << ", col: " << col << std::endl;

    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == ' ') {
                //std::cout << "Placing " << shape[i][j] << " at (" << newRow << ", " << newCol << ")\n";
                grid[newRow][newCol] = shape[i][j]; // Place the actual character
                //std::cout << newRow << ", " << newCol << std::endl;
            } else {
                //std::cout << "Out of bounds: (" << newRow << ", " << newCol << ")\n";
            }
        }
    }
}

bool Board::moveBlockLeft() {
    clearBlockFromGrid(*currentBlock); // Clear the block's current position
    currentBlock->moveLeft();
    if (!isValidPosition(*currentBlock)) {
        currentBlock->moveRight();
        placeBlockOnGrid(*currentBlock); // Restore the block's position if the move is invalid
        return false;
    }
    placeBlockOnGrid(*currentBlock); // Place the block in its new position
    return true;
}

bool Board::moveBlockRight() {
    clearBlockFromGrid(*currentBlock); // Clear the block's current position
    currentBlock->moveRight();
    if (!isValidPosition(*currentBlock)) {
        currentBlock->moveLeft();
        placeBlockOnGrid(*currentBlock); // Restore the block's position if the move is invalid
        return false;
    }
    placeBlockOnGrid(*currentBlock); // Place the block in its new position
    return true;
}

bool Board::moveBlockDown() {
    clearBlockFromGrid(*currentBlock); // Clear the block's current position
    currentBlock->moveDown();
    //std::cout << "Trying to move down to row: " << currentBlock->getRow() << ", col: " << currentBlock->getCol() << std::endl;
    if (!isValidPosition(*currentBlock)) {
        currentBlock->moveUp();
        placeBlockOnGrid(*currentBlock); // Restore the block's position if the move is invalid
        //clearFullRows();
        /*if (!isValidPosition(*currentBlock)) {
            std::cout << "REACHED INVALID" << std::endl;
            currentBlock.reset();
        }*/
        return false;
    }
    placeBlockOnGrid(*currentBlock); // Place the block in its new position
    return true;
}

void Board::rotateBlockCW() {
    clearBlockFromGrid(*currentBlock); // Clear the block's current position
    currentBlock->rotateCW();
    if (!isValidPosition(*currentBlock)) {
        currentBlock->rotateCCW();
    }
    placeBlockOnGrid(*currentBlock); // Place the block in its new position
}

void Board::rotateBlockCCW() {
    clearBlockFromGrid(*currentBlock); // Clear the block's current position
    currentBlock->rotateCCW();
    if (!isValidPosition(*currentBlock)) {
        currentBlock->rotateCW();
    }
    placeBlockOnGrid(*currentBlock); // Place the block in its new position
}

std::unique_ptr<Block> Board::getCurBlock() {
    return std::make_unique<Block>(*currentBlock);
}

std::unique_ptr<Block> Board::getNextBlock() {
    return std::make_unique<Block>(*nextBlock);
}

void Board::clearBlockFromGrid(const Block& block) {
    const auto& shape = block.getShape();
    int row = block.getRow();
    int col = block.getCol();

    //std::cout << "Clearing block at row: " << row << ", col: " << col << std::endl;

    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != ' ') {
                int newRow = row + i;
                int newCol = col + j;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    //std::cout << "Clearing (" << newRow << ", " << newCol << ")\n";
                    grid[newRow][newCol] = ' '; // Clear the block's character
                } else {
                   // std::cout << "Out of bounds: (" << newRow << ", " << newCol << ")\n";
                }
            }
        }
    }
}

void Board::dropBlock() {
    while (moveBlockDown()) {
        // The block will keep moving down until it hits the bottom or another block
    }
    placeBlockOnGrid(*currentBlock);
    clearFullRows();
    //currentBlock = std::move(nextBlock);
    //if (!isValidPosition(*currentBlock)) {
      //  currentBlock.reset();
    //}
}

void Board::clearFullRows() {
    //cout << "clear" << endl;
    for (int i = 0; i < rows; ++i) {
        bool fullRow = true;
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == ' ') {
                fullRow = false;
                //cout << "breaking from clearing" << endl;
                break;
            }
        }
        if (fullRow) {
            //cout << "actualy clearing row" << endl;
            grid.erase(grid.begin() + i);
            grid.insert(grid.begin(), std::vector<char>(cols, ' '));
            increaseScore(100); // How much to increase score by?
        }
    }
}

void Board::generateNextBlock() {
    nextBlock = level->createBlock();
}

bool Board::isGameOver() const {
    return !currentBlock;
}

const std::string& Board::getName() const {
    return name;
}

int Board::getScore() const {
    return score;
}

int Board::getLevel() const {
    return playerLevel;
}

void Board::increaseScore(int points) {
    score += points;
}

void Board::levelUp() {
    if (playerLevel < 4) {
        playerLevel++;
    }
    changeLevel();
}

void Board::levelDown() {
    if (playerLevel > 0) {
        playerLevel--;
    }
    changeLevel();
}

void Board::changeLevel() {
    if (playerLevel == 0) {
            this->level = std::make_unique<Level0>(Level0{playerLevel, f1});
        } else if (playerLevel == 1) {
            this->level = std::make_unique<Level1>(Level1{playerLevel});
        } else if (playerLevel == 2) {
            this->level = std::make_unique<Level2>(Level2{playerLevel});
        } else if (playerLevel == 3) {
            this->level = std::make_unique<Level3>(Level3{playerLevel});
        } else {
            this->level = std::make_unique<Level4>(Level4{playerLevel});
        }
}

void Board::reset() {
    score = 0;
    playerLevel = 0;
    grid = std::vector<std::vector<char>>(rows, std::vector<char>(cols, 0));
    currentBlock.reset();
    nextBlock.reset();
}

std::vector<std::vector<char>> Board::getGrid() {
    return grid;
}

