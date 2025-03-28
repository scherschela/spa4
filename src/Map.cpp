#include "Map.h"
#include <cstdlib>

Map::Map() {
    // Initialize some rooms with traps
    grid[1][2] = Room(RoomType::DOG);
    grid[3][3] = Room(RoomType::MANHOLE);
}

void Map::movePlayer(int direction) {
    int dx = 0, dy = 0;
    switch (direction) {
        case 0: dy = -1; break; // Up
        case 1: dx = 1; break;  // Right
        case 2: dy = 1; break;  // Down
        case 3: dx = -1; break; // Left
    }

    int newX = player.getX() + dx;
    int newY = player.getY() + dy;

    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) return; // Prevent moving out of bounds

    if (grid[newY][newX].getType() == RoomType::DOG) {
        return; // Dog pushes player back
    } else if (grid[newY][newX].getType() == RoomType::MANHOLE) {
        std::cout << "You fell into a manhole! Game over.\n";
        exit(0);
    }

    player.move(dx, dy);
}

void Map::moveCat() {
    if (player.hasCatnip()) {
        cat.lure(player.getX(), player.getY());
    } else {
        cat.moveRandom();
    }
}

void Map::display() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (player.getX() == j && player.getY() == i)
                std::cout << "P ";
            else if (cat.getX() == j && cat.getY() == i)
                std::cout << "C ";
            else if (grid[i][j].getType() == RoomType::DOG)
                std::cout << "D ";
            else if (grid[i][j].getType() == RoomType::MANHOLE)
                std::cout << "M ";
            else
                std::cout << ". ";
        }
        std::cout << '\n';
    }
}

bool Map::checkNetCatch(int direction) {
    int dx = 0, dy = 0;
    switch (direction) {
        case 0: dy = -1; break; // North
        case 1: dx = 1; break;  // East
        case 2: dy = 1; break;  // South
        case 3: dx = -1; break; // West
        default: return false;
    }

    int newX = player.getX() + dx;
    int newY = player.getY() + dy;

    // Check if the player is catching the cat
    return newX == cat.getX() && newY == cat.getY();
}

bool Map::checkLoss() {
    // If player is in the same position as the cat, they lose
    if (player.getX() == cat.getX() && player.getY() == cat.getY()) {
        return true;
    }
    return false;
}