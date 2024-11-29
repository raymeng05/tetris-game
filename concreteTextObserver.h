#ifndef CONCRETETEXTOBSERVER_H
#define CONCRETETEXTOBSERVER_H
#include "observer.h"
#include "game.h"

class Game;

class ConcreteTextObserver: public Observer {
    Game *b; // The game has a unique pointer that will deallocate the board
    public:
        ConcreteTextObserver(Game *b);
        void notify() override;
};

















#endif
