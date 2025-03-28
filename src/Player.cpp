#include "Player.h"

Player::Player() : x(0), y(0), catnip(false) {}  // Default starting position at (0, 0)

void Player::setPosition(int newX, int newY) {
    x = newX;  // Set the new x-coordinate
    y = newY;  // Set the new y-coordinate
}

int Player::getX() const {
    return x;  // Return the current x-coordinate
}

int Player::getY() const {
    return y;  // Return the current y-coordinate
}

bool Player::hasCatnip() const {
    return catnip;  // Return whether the player has catnip
}

void Player::setCatnip(bool value) {
    catnip = value;  // Set the player's catnip status
}
