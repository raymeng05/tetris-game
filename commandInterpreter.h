#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>
#include "game.h"

class CommandInterpreter {
private:
    Game& game;

public:
    CommandInterpreter(Game& game);
    void interpret(std::string& command);
};

#endif
