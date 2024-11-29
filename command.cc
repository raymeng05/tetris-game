#include "command.h"
#include <iostream>
using namespace std;

Command::Command(string givenInput): comm{givenInput}, multiplier{1} {}

void Command::sepCommand(string s) {
    int multi = 1;
    int ind = 0;
    while (ind < s.size() && isdigit(s[ind])) {
        ind++;
    }
    if (ind > 0) {
        multi = stoi(s.substr(0, ind));
    }
    this->comm = s.substr(ind);
    this->multiplier = multi;
}

void Command::fixCommand() {
    //TO DO: have to account for special commands (file commands etc.)
    vector<string> matches;
    for (string cmd : this->commands) {
        if (cmd.find(this->comm) == 0) {
            matches.emplace_back(cmd);
        }
    }
    if (matches.size() == 1) {
        this->comm = matches[0];
    } else if (matches.size() > 1) {
        //ambiguous command
        cout << "Ambiguous command!" << endl;
    } else {
        cout << "Command not found!" << endl;
    }
}

void Command::setCommand(string s) {
    this->comm = s;
    sepCommand(s);
    fixCommand();
}

string Command::getCommand() {
    return this->comm;
}
int Command::getMultiplier() {
    return this->multiplier;
}


