#include "game.h"
#include "commandInterpreter.h"
#include "window.h"
#include "concreteTextObserver.h"
#include "concreteGraphicsObserver.h"
#include <iostream>
using namespace std;

int main() {
    int p1Level;
    int p2Level;
    cout << "Enter the player levels: ";
    cin >> p1Level >> p2Level;
    Game game("Player1", "Player2", p1Level, p2Level);
    CommandInterpreter interpreter(game);
    Xwindow xw(1000, 600);
    ConcreteTextObserver cto1{game.getBoard1()};
    ConcreteGraphicsObserver cgo1{game.getBoard1(), &xw, 0};

    ConcreteTextObserver cto2{game.getBoard2()};
    ConcreteGraphicsObserver cgo2{game.getBoard2(), &xw, 500};

    game.start();

    return 0;
}