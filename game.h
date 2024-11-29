#ifndef GAME_H
#define GAME_H

#include <memory>
#include <fstream>
#include <vector>
#include "board.h"
#include "command.h"
#include "concreteTextObserver.h"


class Board;
class ConcreteTextObserver;

class Game {
private:
    std::unique_ptr<Board> board1;
    std::unique_ptr<Board> board2;
    int p1Level;
    int p2Level;
    bool isPlayer1Turn;
    Command comm;
    std::vector<Observer *> obs;

public:
    Game(const std::string& player1Name, const std::string& player2Name, int pLevel, string f1, string f2, bool onlyText);
    void start();
    void switchTurn();
    void displayStatus() const;
    bool isGameOver() const;
    void executeCommand(std::string& command);
    void display();
    Board* getBoard1() const;
    Board* getBoard2() const;
    void notifyObservers();
    void attach(Observer *ob);
    string getName1();
    string getName2();
    int getLevel1();
    int getLevel2();
    int getScore1();
    int getScore2();
    std::vector<std::vector<char>> getGrid1();
    std::vector<std::vector<char>> getGrid2();
};

#endif