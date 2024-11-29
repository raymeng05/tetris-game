#include "concreteGraphicsObserver.h"

ConcreteGraphicsObserver::ConcreteGraphicsObserver(Game *board, Xwindow *window): b(board), Window(window) {
    board->attach(this);
}

void ConcreteGraphicsObserver::notify() {

    int blockWidth = Window->getWidth() / 25;
    int blockHeight = Window->getHeight() / 22;
    int gap = 2;
    int totalBlockHeight = blockHeight + gap;
    int totalBoardHeight = 18 * totalBlockHeight;
    int offsetY = 50;
    int offsetX = Window->getWidth() / 2 - 10;
    std::vector<std::vector<char>> gameBoard1 = b->getGrid1();
    std::vector<std::vector<char>> gameBoard2 = b->getGrid2();


    for (int row = 0; row < 18; ++row) {
        for (int col = 0; col < 11; ++col) {
            char blockType = gameBoard1[row][col];
            int x = col * (blockWidth + gap);
            int y = offsetY + row * totalBlockHeight;
            Window->fillBlock(x, y, blockType);
            blockType = gameBoard2[row][col];
            x = offsetX + col * (blockWidth + gap);
            y = offsetY + row * totalBlockHeight;
            Window->fillBlock(x, y, blockType);
        }
    }
    int lineX = Window->getWidth() / 2 - 10;
    Window->drawLine(lineX, 0, lineX, Window->getHeight());
 
    std::string playerText1 = b->getName1();
    std::string levelText1 = "Level: " + std::to_string(b->getLevel1());
    std::string scoreText1 = "Score: " + std::to_string(b->getScore1());

    std::string playerText2 = b->getName2();
    std::string levelText2 = "Level: " + std::to_string(b->getLevel2());
    std::string scoreText2 = "Score: " + std::to_string(b->getScore2());

    Window->drawText(5, totalBlockHeight / 2, playerText1);
    Window->drawText(5 + 85, totalBlockHeight / 2, levelText1);
    Window->drawText(5 + 170, totalBlockHeight / 2, scoreText1);

    Window->drawText(offsetX + 10, totalBlockHeight / 2, playerText2);
    Window->drawText(offsetX + 10 + 85, totalBlockHeight / 2, levelText2);
    Window->drawText(offsetX + 10 + 170, totalBlockHeight / 2, scoreText2);

    Window->flush();
}


