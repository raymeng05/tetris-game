#include "concreteGraphicsObserver.h"

ConcreteGraphicsObserver::ConcreteGraphicsObserver(Board *board, Xwindow *window): b(board), Window(window) {
    board->attach(this);
}

void ConcreteGraphicsObserver::notify() {

    // XClearWindow(Window->d, Window->w);

    int blockWidth = Window->getWidth() / 11;
    int blockHeight = Window->getHeight() / 18;
    std::vector<std::vector<char>> gameBoard = b->getGrid();

    for (int row = 0; row < 18; ++row) {
        for (int col = 0; col < 11; ++col) {
            char blockType = gameBoard[row][col];
            Window->fillBlock(col * blockWidth, row * blockHeight, blockType);
        }
    }
    // XFlush(Window->d);
}


