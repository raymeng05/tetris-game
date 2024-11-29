#include "game.h"
#include "commandInterpreter.h"
#include "window.h"
#include "concreteTextObserver.h"
#include "concreteGraphicsObserver.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
    bool onlyText = false;
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    string f1 = "sequence1.txt";
    string f2 = "sequence2.txt";
    int level = 0;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-text") {
            onlyText = true;
        } else if (arg == "-seed" && i + 1 < argc) {
            seed = static_cast<unsigned int>(atoi(argv[++i]));
        } else if (arg == "-scriptfile1" && i + 1 < argc) {
            f1 = argv[++i];
        } else if (arg == "-scriptfile2" && i + 1 < argc) {
            f2 = argv[++i];
        } else if (arg == "-startlevel" && i + 1 < argc) {
            level = atoi(argv[++i]);
        }
    }

    // Set the seed for the random number generator
    srand(seed);

    // Initialize and start the game with the parsed options
    Game game("Player1", "Player2", level, f1, f2, onlyText);

    CommandInterpreter interpreter(game);
    //Xwindow xw(500, 500);
    ConcreteTextObserver cto{&game};
    //ConcreteGraphicsObserver cgo{game.getBoard1(), &xw};

    game.start();

    return 0;
}