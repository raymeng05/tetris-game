#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <cctype>
#include <vector>
using namespace std;
struct Command {
    private:
        string comm;
        int multiplier;
        vector<string> commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom ", "random", "sequence", "I", "J", "L", "O", "S", "Z", "T", "restart"};
    public:
        Command(string givenInput);
        void sepCommand(string s);
        void fixCommand();
};
#endif
