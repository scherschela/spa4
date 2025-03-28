#include "Cat.h"
#include <cstdlib>

Cat::Cat() : x(4), y(4) {}

int Cat::getX() const { return x; }
int Cat::getY() const { return y; }

void Cat::moveRandom() {
    int dx = (rand() % 3) - 1; // -1, 0, or 1
    int dy = (rand() % 3) - 1;

    int newX = x + dx;
    if (newX < 0) newX = 0;
    if (newX > 4) newX = 4;

    int newY = y + dy;
    if (newY < 0) newY = 0;
    if (newY > 4) newY = 4;

    x = newX;
    y = newY;
}

void Cat::lure(int playerX, int playerY) {
    if (playerX > x) x++;
    else if (playerX < x) x--;

    if (playerY > y) y++;
    else if (playerY < y) y--;
}
