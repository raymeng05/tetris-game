#ifndef CONCRETEGRAPHICSOBSERVER_H
#define CONCRETEGRAPHICSOBSERVER_H
#include "observer.h"
#include "board.h"
#include "window.h"

class Board;
class Xwindow;

class ConcreteGraphicsObserver: public Observer {
    Board *b; // The game has a unique pointer that will deallocate the board
    std::unique_ptr<Xwindow> Window;
    int offsetX;
    public:
        ConcreteGraphicsObserver(Board *b, Xwindow *window, int offsetX);
        void notify() override;
};


#endif
