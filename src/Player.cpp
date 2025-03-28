#include "Player.h"

Player::Player() : x(0), y(0), catnip(3) {}

int Player::getX() const { return x; }
int Player::getY() const { return y; }

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Player::useCatnip() {
    if (catnip > 0) {
        catnip--;
    }
}

bool Player::hasCatnip() const {
    return catnip > 0;
}
