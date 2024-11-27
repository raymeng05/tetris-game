#include "concreteBlockDecorator.h"

ConcreteBlockDecorator::ConcreteBlockDecorator(std::unique_ptr<Block> block)
    : BlockDecorator(std::move(block)) {}

void ConcreteBlockDecorator::rotateCW() {
    BlockDecorator::rotateCW();
}

void ConcreteBlockDecorator::rotateCCW() {
    BlockDecorator::rotateCCW();
}

void ConcreteBlockDecorator::moveLeft() {
    BlockDecorator::moveLeft();
}

void ConcreteBlockDecorator::moveRight() {
    BlockDecorator::moveRight();
}

void ConcreteBlockDecorator::moveDown() {
    BlockDecorator::moveDown();
}
