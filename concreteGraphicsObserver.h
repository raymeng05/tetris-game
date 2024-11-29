#ifndef CONCRETEGRAPHICSOBSERVER_H
#define CONCRETEGRAPHICSOBSERVER_H
#include "observer.h"
#include "board.h"
#include "window.h"

class Board;
class Xwindow;

class ConcreteGraphicsObserver: public Observer {
    Game *b; // The game has a unique pointer that will deallocate the board
    std::unique_ptr<Xwindow> Window;
    public:
        ConcreteGraphicsObserver(Game *b, Xwindow *window);
        void notify() override;
};


#endif
