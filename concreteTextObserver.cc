#include "concreteTextObserver.h"

ConcreteTextObserver::ConcreteTextObserver(Board *b): b{b} {
    b->attach(this);
}

void ConcreteTextObserver::notify() {
    b->display();
}
