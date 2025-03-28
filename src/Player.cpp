#include "Player.h"

Player::Player() : x(0), y(0), catnip(false) {}

void Player::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

bool Player::hasCatnip() const {
    return catnip;
}

void Player::setCatnip(bool value) {
    catnip = value;
}
