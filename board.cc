#include "board.h"
#include "level1.h"

Board::Board(int rows, int cols, const std::string& name, int level)
    : rows(rows), cols(cols), grid(rows, std::vector<char>(cols, ' ')), name(name), score(0), playerLevel(level), level(std::make_unique<Level1>(Level1{level})), cto(std::make_unique<ConcreteTextObserver>()) {}


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

void Board::setCurrentBlock() {
    currentBlock = std::move(nextBlock);
}

void Board::setNextBlock() {
    nextBlock = level->createBlock();
}


bool Board::isValidPosition(const Block& block) {
    const auto& shape = block.getShape();
    int row = block.getRow();
    int col = block.getCol();
    cout << "check position row: " << row << " col: " << col << endl;
    // Temporarily remove the block from the grid
    bool isValid = true;

    for (int i = 0; i < shape.size(); ++i) {
        
        for (int j = 0; j < shape[i].size(); ++j) {
            //cout << "hello" << endl;
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
    //std::cout << "after temp remove: " << std::endl;
    //display();

    // Check if the new position is valid
    /*isValid = true;
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
                // Check if the new position is already occupied
                if (grid[newRow][newCol] != ' ') {
                    isValid = false;
                    break;
                }
            }
        }
        if (!isValid) return false;
    }*/

    // Restore the block to the grid
    /*for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j] != ' ') {
                grid[row + i][col + j] = shape[i][j];
            }
        }
    }*/

    return isValid;
}
/*void Board::moveBlockPos() {

}*/


void Board::placeBlockOnGrid(const Block& block) {
    const auto& shape = block.getShape();
    int row = block.getRow();
    int col = block.getCol();

    std::cout << "Placing block at row: " << row << ", col: " << col << std::endl;

    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == ' ') {
                std::cout << "Placing " << shape[i][j] << " at (" << newRow << ", " << newCol << ")\n";
                grid[newRow][newCol] = shape[i][j]; // Place the actual character
                std::cout << newRow << ", " << newCol << std::endl;
            } else {
                std::cout << "Out of bounds: (" << newRow << ", " << newCol << ")\n";
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
    //clearFullRows();
    //currentBlock = std::move(nextBlock);
    //if (!isValidPosition(*currentBlock)) {
      //  currentBlock.reset();
    //}
}

void Board::clearFullRows() {
    for (int i = 0; i < rows; ++i) {
        bool fullRow = true;
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == ' ') {
                fullRow = false;
                break;
            }
        }
        if (fullRow) {
            grid.erase(grid.begin() + i);
            grid.insert(grid.begin(), std::vector<char>(cols, 0));
            increaseScore(100); // How much to increase score by?
        }
    }
}

void Board::generateNextBlock() {
    nextBlock = level->createBlock();
}

void Board::display() const {
    std::cout << "Level:     " << playerLevel << std::endl;
    std::cout << "Score:     " << playerLevel << std::endl;
    std::cout << "----------" << std::endl;
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
    std::cout << "----------" << std::endl;
    std::cout << "Next: " << std::endl;
    if (nextBlock == nullptr) {
        std::cout<<std::endl;
        return;
    }
    const auto& shape = nextBlock->getShape();
    int row = shape.size();
    int col = shape[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << shape[i][j];
        }
        cout << endl;
    }
    cout << endl;
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
    playerLevel++;
}

void Board::levelDown() {
    if (playerLevel > 0) {
        playerLevel--;
    }
}

void Board::reset() {
    score = 0;
    playerLevel = 0;
    grid = std::vector<std::vector<char>>(rows, std::vector<char>(cols, 0));
    currentBlock.reset();
    nextBlock.reset();
}

void Board::notifyObservers() {
    cto->notify();
    //cgo->notify();
}
