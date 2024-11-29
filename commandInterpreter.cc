#include "commandInterpreter.h"
#include <iostream>

CommandInterpreter::CommandInterpreter(Game& game) : game(game) {}

void CommandInterpreter::interpret(std::string& command) {
    game.executeCommand(command);
}
