#include "game.h"
#include "commandInterpreter.h"
#include "window.h"
#include "concreteTextObserver.h"
#include "concreteGraphicsObserver.h"
#include <iostream>

int main() {
    Game game("Player1", "Player2");
    CommandInterpreter interpreter(game);
    Xwindow xw(500, 500);
    ConcreteTextObserver cto1{game.getBoard1()};
    ConcreteGraphicsObserver cgo1{game.getBoard1(), &xw};

    ConcreteTextObserver cto2{game.getBoard2()};
    ConcreteGraphicsObserver cgo2{game.getBoard2(), &xw};

    game.start();

    /*while (!game.isGameOver()) {
        std::string command;
        std::cin >> command;
        interpreter.interpret(command);
    }*/

    return 0;
}