#include "Cat.h"
#include <cstdlib>
#include <ctime>
#include <cmath>  // For std::abs

Cat::Cat() : x(0), y(0) {  // Default position for the cat is (0, 0)
    std::srand(std::time(0));  // Seed the random number generator
}

void Cat::setPosition(int newX, int newY) {
    x = newX;  // Set the new x-coordinate
    y = newY;  // Set the new y-coordinate
}

int Cat::getX() const {
    return x;  // Return the current x-coordinate
}

int Cat::getY() const {
    return y;  // Return the current y-coordinate
}

void Cat::moveRandom() {
    // Randomly choose a direction to move (-1, 0, 1) for x and y
    int dx = std::rand() % 3 - 1;  // Random move in the x direction (-1, 0, 1)
    int dy = std::rand() % 3 - 1;  // Random move in the y direction (-1, 0, 1)

    // Move the cat within bounds (0-4 for both x and y)
    int newX = x + dx;
    int newY = y + dy;

    // Ensure the cat stays within the bounds of the grid
    if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
        setPosition(newX, newY);
    }
}

void Cat::moveTowardPlayer(int playerX, int playerY) {
    // Calculate the difference between the player's position and the cat's position
    int dx = playerX - x;
    int dy = playerY - y;

    // Normalize the direction to move towards the player
    if (dx != 0) dx /= std::abs(dx);  // Move horizontally towards the player
    if (dy != 0) dy /= std::abs(dy);  // Move vertically towards the player

    // Move the cat one step towards the player
    int newX = x + dx;
    int newY = y + dy;

    // Ensure the cat stays within the bounds of the grid
    if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
        setPosition(newX, newY);
    }
}
