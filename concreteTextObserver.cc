#include "concreteTextObserver.h"

ConcreteTextObserver::ConcreteTextObserver(Game *b): b{b} {
    b->attach(this);
}

void ConcreteTextObserver::notify() {
    b->display();
}
