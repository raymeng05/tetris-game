#include "game.h"
#include "commandInterpreter.h"
#include <iostream>

int main() {
    Game game("Player1", "Player2");
    CommandInterpreter interpreter(game);

    game.start();

    /*while (!game.isGameOver()) {
        std::string command;
        std::cin >> command;
        interpreter.interpret(command);
    }*/

    return 0;
}