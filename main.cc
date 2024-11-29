#include "game.h"
#include "commandInterpreter.h"
#include "window.h"
#include "concreteTextObserver.h"
#include "concreteGraphicsObserver.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
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
            string temp = argv[++i];
            istringstream sock {temp};
            sock >> seed;
        } else if (arg == "-scriptfile1" && i + 1 < argc) {
            f1 = argv[++i];
        } else if (arg == "-scriptfile2" && i + 1 < argc) {
            f2 = argv[++i];
        } else if (arg == "-startlevel" && i + 1 < argc) {
            string temp = argv[++i];
            istringstream sock {temp};
            sock >> level;
        }
    }

    Game game("Player1", "Player2", level, f1, f2, onlyText, seed);

    unique_ptr<Xwindow> xw;
    unique_ptr <ConcreteGraphicsObserver> cgo;
    if (!onlyText) {
        xw = make_unique<Xwindow>(550, 625);
        cgo = make_unique<ConcreteGraphicsObserver>(&game, xw.get());
    }

    CommandInterpreter interpreter(game);
    ConcreteTextObserver cto{&game};

    game.start();

    return 0;
}
