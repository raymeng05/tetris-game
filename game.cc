#include "game.h"
#include "concreteTextObserver.h"
#include <iostream>

Game::Game(const std::string& player1Name, const std::string& player2Name, int pLevel, string f1, string f2, bool onlyText)
    : board1(std::make_unique<Board>(Board{18, 11, player1Name, pLevel, f1})), board2(std::make_unique<Board>(Board{18, 11, player2Name, pLevel, f2})), isPlayer1Turn(true), comm(" ") {}

void Game::start() {
    board1->setNextBlock();
    board2->setNextBlock();
    while (true) { // CHANGE WHILE TRUE
        //displayStatus();
        if (isPlayer1Turn) {
            board1->switchCurrentBlock();
            board1->setNextBlock();
        } else {
            board2->switchCurrentBlock();
            board2->setNextBlock();
        }

        while (true) {
            if (isPlayer1Turn) {
                board1->placeCurBlockOnGrid();
            } else {
                board2->placeCurBlockOnGrid();
            }
            notifyObservers();
            std::string command;
            std::cin >> command;
            executeCommand(command);

            if (command == "drop") {
                break;
            }
        }
        switchTurn();
    }
    std::cout << "Game Over!" << std::endl;
}

void Game::switchTurn() {
    isPlayer1Turn = !isPlayer1Turn;
}

void Game::displayStatus() const {
    std::cout << "Player 1: " << board1->getName() << " | Score: " << board1->getScore() << " | Level: " << board1->getLevel() << std::endl;
    std::cout << "Player 2: " << board2->getName() << " | Score: " << board2->getScore() << " | Level: " << board2->getLevel() << std::endl;
}

bool Game::isGameOver() const {
    return board1->isGameOver() || board2->isGameOver();
}

void Game::executeCommand(std::string& command) {
    Board* currentPlayer = isPlayer1Turn ? board1.get() : board2.get();
    this->comm.setCommand(command);

    string fixedComm = comm.getCommand();
    int multiplier = comm.getMultiplier();

    if (fixedComm == "left") {
        for (int i = 0; i < multiplier; i++) {
            currentPlayer->moveBlockLeft();
        }
        if (currentPlayer->getLevel() == 3) {
            currentPlayer->moveBlockDown();
        }
    } else if (fixedComm == "right") {
        for (int i = 0; i < multiplier; i++) {
            currentPlayer->moveBlockRight();
        }
        if (currentPlayer->getLevel() == 3) {
            currentPlayer->moveBlockDown();
        }
    } else if (fixedComm == "down") {
        for (int i = 0; i < multiplier; i++) {
            currentPlayer->moveBlockDown();
        }
        if (currentPlayer->getLevel() == 3) {
            currentPlayer->moveBlockDown();
        }
    } else if (fixedComm == "clockwise") {
        for (int i = 0; i < multiplier; i++) {
            currentPlayer->rotateBlockCW();
        }
        if (currentPlayer->getLevel() == 3) {
            currentPlayer->moveBlockDown();
        }
    } else if (fixedComm == "counterclockwise") {
        for (int i = 0; i < multiplier; i++) {
            currentPlayer->rotateBlockCCW();
        }
        if (currentPlayer->getLevel() == 3) {
            currentPlayer->moveBlockDown();
        }
    } else if (fixedComm == "drop") {
        currentPlayer->dropBlock();
    } else if (fixedComm == "levelup") {
        for (int i = 0; i < multiplier; i++) {
            currentPlayer->levelUp();
        }
    } else if (fixedComm == "leveldown") {
        for (int i = 0; i < multiplier; i++) {
            currentPlayer->levelDown();
        }
    } else if (fixedComm == "norandom") {
        string fileName;
        cin >> fileName;
        //To Do: make level non-random
    } else if (fixedComm == "random") {
        //To Do: make level random
    } else if (fixedComm == "sequence") {
        string fileName;
        cin >> fileName;
        ifstream readComms {fileName};
        string curCommand;
        while (readComms >> curCommand) {
            executeCommand(curCommand);
        }
        //To Do: Executes the sequence of commands found in file
    } else if (fixedComm == "I" || fixedComm == "J" || fixedComm == "L" || fixedComm == "O" || fixedComm == "S" || fixedComm == "Z" || fixedComm == "T") {
        currentPlayer->clearBlockFromGrid(*(currentPlayer->getCurBlock()));
        currentPlayer->setCurBlock(fixedComm[0]);
        currentPlayer->placeCurBlockOnGrid();
        notifyObservers();
    } else if (fixedComm == "restart") {
        currentPlayer->reset();
    } else {
        std::cout << "Invalid command!" << std::endl;
    }
    command = fixedComm;
}

Board *Game::getBoard1() const {
    return board1.get();
}

Board *Game::getBoard2() const {
    return board2.get();
}

void Game::display() {
    std::cout << "Player 1            Player 2" << std::endl; 
    std::cout << "Level:     " << board1->getLevel() << "        ";
    std::cout << "Level:     " << board2->getLevel() << std::endl;
    std::cout << "Score:     " << board1->getScore() << "        ";
    std::cout << "Score:     " << board2->getScore() << std::endl;

    std::cout << "-----------" << "         " << "-----------" << std::endl;
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            std::cout << board1->getGrid()[i][j];
        }
        std::cout << "         ";
        for (int j = 0; j < 11; j++) {
            std::cout << board2->getGrid()[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "-----------" << "         " << "-----------" << std::endl;
    if (isPlayer1Turn) {
        std::cout << "Next: " << std::endl;
        const auto& shape = board1->nextBlock->getShape();
        int row = shape.size();
        int col = shape[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << shape[i][j];
            }
            cout << endl;
        }
        cout << endl;
    } else {
        std::cout << "                    Next: " << std::endl; 
        const auto& shape = board2->nextBlock->getShape();
        int row = shape.size();
        int col = shape[0].size();
        for (int i = 0; i < row; i++) {
            std::cout << "                    ";
            for (int j = 0; j < col; j++) {
                cout << shape[i][j];
            }
            std::cout << endl;
        }
    cout << endl;
    }
}

void Game::notifyObservers() {
    for (auto ob: obs) {
        ob->notify();
    }
}

void Game::attach(Observer *ob) {
    obs.emplace_back(ob);
}
