#include "game.h"
#include "concreteTextObserver.h"
#include <iostream>

Game::Game(const std::string& player1Name, const std::string& player2Name)
    : board1(std::make_unique<Board>(Board{18, 11, player1Name, 1})), board2(std::make_unique<Board>(Board{18, 11, player2Name, 1})), isPlayer1Turn(true) {}

void Game::start() {
    board1->setNextBlock();
    board2->setNextBlock();

    board1->setCurrentBlock();
    board2->setCurrentBlock();

    //board1->placeCurBlockOnGrid();
    //board2->placeCurBlockOnGrid();
    while (true) { // CHANGE WHILE TRUE
        //displayStatus();
        if (isPlayer1Turn) {
            board1->setNextBlock();
        } else {
            board2->setNextBlock();
        }

        while (true) {
            if (isPlayer1Turn) {
                board1->placeCurBlockOnGrid();
            } else {
                board2->placeCurBlockOnGrid();
            }
            std::cout << "Player 1" << std::endl;
            board1->notifyObservers();
            std::cout << "Player 2" << std::endl;
            board2->notifyObservers();
            std::string command;
            std::cin >> command;
            executeCommand(command);

            //board1->placeCurBlockOnGrid();
            //board2->placeCurBlockOnGrid();

            if (command == "drop") {
                break;
            }
        }
        if (isPlayer1Turn) {
            board2->setNextBlock();
            board2->setCurrentBlock();
        } else {
            board1->setNextBlock();
            board1->setCurrentBlock();
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
    board1->notifyObservers();
    std::cout << "Player 2: " << board2->getName() << " | Score: " << board2->getScore() << " | Level: " << board2->getLevel() << std::endl;
    board2->notifyObservers();
}

bool Game::isGameOver() const {
    return board1->isGameOver() || board2->isGameOver();
}

void Game::executeCommand(const std::string& command) {
    Board* currentPlayer = isPlayer1Turn ? board1.get() : board2.get();
    //TO DO: need to add other commands
    if (command == "left") {
        currentPlayer->moveBlockLeft();
    } else if (command == "right") {
        currentPlayer->moveBlockRight();
    } else if (command == "down") {
        currentPlayer->moveBlockDown();
    } else if (command == "clockwise") {
        currentPlayer->rotateBlockCW();
    } else if (command == "counterclockwise") {
        currentPlayer->rotateBlockCCW();
    } else if (command == "drop") {
        currentPlayer->dropBlock();
    } else if (command == "levelup") {
        currentPlayer->levelUp();
    } else if (command == "leveldown") {
        currentPlayer->levelDown();
    } else if (command == "restart") {
        currentPlayer->reset();
    } else {
        std::cout << "Invalid command!" << std::endl;
    }
}

Board *Game::getBoard1() const {
    return board1.get();
}

Board *Game::getBoard2() const {
    return board2.get();
}
