#include "concreteGraphicsObserver.h"

ConcreteGraphicsObserver::ConcreteGraphicsObserver(Game *board, Xwindow *window): b(board), Window(window) {
    board->attach(this);
}

void ConcreteGraphicsObserver::notify() {

    int blockWidth = Window->getWidth() / 22;
    int blockHeight = Window->getHeight() / 18;
    //std::vector<std::vector<char>> gameBoard = b->getGrid();

    /*for (int row = 0; row < 18; ++row) {
        for (int col = 0; col < 11; ++col) {
            char blockType = gameBoard[row][col];
            Window->fillBlock(offsetX + col * blockWidth, row * blockHeight, blockType);
        }
    }
    int lineX = Window->getWidth() / 2 - 12;
    Window->drawLine(lineX, 0, lineX, Window->getHeight());

    Window->flush();*/
}


