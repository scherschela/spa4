#include "Cat.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Cat::Cat() : x(0), y(0) {
    std::srand(std::time(0));
}

void Cat::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

int Cat::getX() const {
    return x;
}

int Cat::getY() const {
    return y;
}

void Cat::moveRandom() {
    int dx = std::rand() % 3 - 1;
    int dy = std::rand() % 3 - 1;

    int newX = x + dx;
    int newY = y + dy;

    if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
        setPosition(newX, newY);
    }
}

void Cat::moveTowardPlayer(int playerX, int playerY) {
    int dx = playerX - x;
    int dy = playerY - y;

    if (dx != 0) dx /= std::abs(dx);
    if (dy != 0) dy /= std::abs(dy);

    int newX = x + dx;
    int newY = y + dy;

    if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
        setPosition(newX, newY);
    }
}
