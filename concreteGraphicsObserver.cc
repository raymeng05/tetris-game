#include "concreteGraphicsObserver.h"

ConcreteGraphicsObserver::ConcreteGraphicsObserver(Game *board, Xwindow *window): b(board), Window(window) {
    board->attach(this);
}

void ConcreteGraphicsObserver::notify() {

    int blockWidth = Window->getWidth() / 25;
    int blockHeight = Window->getHeight() / 28;
    int gap = 2;
    int totalBlockHeight = blockHeight + gap;
    int totalBoardHeight = 18 * totalBlockHeight;
    int offsetY = 50;
    int offsetX = Window->getWidth() / 2 - 10;
    int textAreaHeight = 30;
    int nextBlockSectionHeight = 50;
    int availableHeight = Window->getHeight() - textAreaHeight - nextBlockSectionHeight - 15;
    std::vector<std::vector<char>> gameBoard1 = b->getGrid1();
    std::vector<std::vector<char>> gameBoard2 = b->getGrid2();


    for (int row = 0; row < 18; ++row) {
        for (int col = 0; col < 11; ++col) {
            char blockType = gameBoard1[row][col];
            int x = col * (blockWidth + gap);
            int y = offsetY + row * totalBlockHeight;
            if (y + totalBlockHeight <= availableHeight) {
                Window->fillBlock(x, y, blockType);
            }

            blockType = gameBoard2[row][col];
            x = offsetX + col * (blockWidth + gap);
            y = offsetY + row * totalBlockHeight;
            if (y + totalBlockHeight <= availableHeight) {
                Window->fillBlock(x, y, blockType);
            }
        }
    }

    int fillHeight = nextBlockSectionHeight + 50;
    XSetForeground(Window->getDisplay(), Window->getGC(), Window->getColour(Xwindow::Black));
    XFillRectangle(Window->getDisplay(), Window->getPixmap(), Window->getGC(), 0, Window->getHeight() - fillHeight, Window->getWidth(), fillHeight);

    int lineX = Window->getWidth() / 2 - 10;
    Window->drawLine(lineX, 0, lineX, Window->getHeight());

    int lineY = Window->getHeight() - nextBlockSectionHeight - 75;
    Window->drawLine(0, lineY, Window->getWidth(), lineY);
 
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


    Window->drawText(15, Window->getHeight() - totalBlockHeight / 2 - 50, "Next:");
    int nextBlockX = 65; 
    int nextBlockY = Window->getHeight() - nextBlockSectionHeight - 40;
    auto shape1 = b->getBoard1()->nextBlock->getShape();
    int row = shape1.size();
    int col = shape1[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            Window->fillBlock(nextBlockX + j * blockWidth, nextBlockY + i * blockHeight, shape1[i][j]);
        }
    }

    Window->drawText(offsetX + 15, Window->getHeight() - totalBlockHeight / 2 - 50, "Next:");
    auto shape2 = b->getBoard2()->nextBlock->getShape();
    int row2 = shape2.size();
    int col2 = shape2[0].size();

    for (int k = 0; k < row2; k++) {
        for (int l = 0; l < col2; l++) {
            Window->fillBlock(offsetX + nextBlockX + l * blockWidth, nextBlockY + k * blockHeight, shape2[k][l]);
        }
    }

    Window->flush();
}


