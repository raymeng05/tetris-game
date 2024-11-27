#ifndef CONCRETETEXTOBSERVER_H
#define CONCRETETEXTOBSERVER_H
#include "observer.h"
#include "board.h"

class Board;

class ConcreteTextObserver: public Observer {
    std::unique_ptr<Board> b;
    public:
        void notify() override;
};

















#endif
