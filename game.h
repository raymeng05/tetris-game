#ifndef GAME_H
#define GAME_H

#include <memory>
#include "board.h"

class Board;

class Game {
private:
    std::unique_ptr<Board> board1;
    std::unique_ptr<Board> board2;
    bool isPlayer1Turn;

public:
    Game(const std::string& player1Name, const std::string& player2Name);
    void start();
    void switchTurn();
    void displayStatus() const;
    bool isGameOver() const;
    void executeCommand(const std::string& command);
};

#endif