#ifndef CONCRETETEXTOBSERVER_H
#define CONCRETETEXTOBSERVER_H
#include "observer.h"
#include "board.h"

class Board;

class ConcreteTextObserver: public Observer {
    Board *b; // The game has a unique pointer that will deallocate the board
    public:
        ConcreteTextObserver(Board *b);
        void notify() override;
};

















#endif
