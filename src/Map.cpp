#include "Map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Map::Map() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Initialize the game board with rooms
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            gameBoard[i][j].setCatnip(false);  // Ensure no catnip at start
            gameBoard[i][j].setManhole(false); // Ensure no manholes at start
        }
    }

    // Place exactly 1 catnip in a random room
    int catnipX = std::rand() % 5;
    int catnipY = std::rand() % 5;
    gameBoard[catnipX][catnipY].setCatnip(true);  // Set catnip in a random room

    // Place exactly 2 manholes in random rooms
    int manholeCount = 0;
    while (manholeCount < 2) {
        int manholeX = std::rand() % 5;
        int manholeY = std::rand() % 5;

        // Ensure the manhole is not placed where the catnip is
        if (!gameBoard[manholeX][manholeY].getCatnip() && !gameBoard[manholeX][manholeY].getManhole()) {
            gameBoard[manholeX][manholeY].setManhole(true);
            manholeCount++;
        }
    }

    // Place player and cat in random locations
    player.setPosition(std::rand() % 5, std::rand() % 5);
    do {
        cat.setPosition(std::rand() % 5, std::rand() % 5);
    } while (player.getX() == cat.getX() && player.getY() == cat.getY());  // Ensure player and cat are not in the same spot
}

void Map::display() const {
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (player.getX() == x && player.getY() == y) {
                std::cout << "P ";  // Player position
            } else if (cat.getX() == x && cat.getY() == y) {
                std::cout << "C ";  // Cat position
            } else if (gameBoard[x][y].getCatnip()) {
                std::cout << "N ";  // Catnip in the room
            } else if (gameBoard[x][y].getManhole()) {
                std::cout << "M ";  // Manhole in the room
            } else {
                std::cout << ". ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
}

void Map::movePlayer(int direction) {
    int dx = 0, dy = 0;
    switch (direction) {
        case 0: dy = -1; break; // North
        case 1: dx = 1; break;  // East
        case 2: dy = 1; break;  // South
        case 3: dx = -1; break; // West
        default: return;
    }

    int newX = player.getX() + dx;
    int newY = player.getY() + dy;

    // Ensure the player stays within bounds
    if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
        player.setPosition(newX, newY);

        // Check if the player steps into a manhole
        if (gameBoard[newX][newY].getManhole()) {
            std::cout << "You fell into a manhole! Game over.\n";
            exit(0);  // End the game if the player falls into a manhole
        }

        // Check if the player collects catnip in the new room
        playerCollectsCatnip();
    }
}

bool Map::checkWin() const {
    // If the player and cat are in the same room, the player wins
    return player.getX() == cat.getX() && player.getY() == cat.getY();
}

bool Map::checkLoss() const {
    // If the player steps into the cat's room, they lose
    return player.getX() == cat.getX() && player.getY() == cat.getY();
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

bool Map::playerCollectsCatnip() {
    if (gameBoard[player.getX()][player.getY()].getCatnip()) {
        gameBoard[player.getX()][player.getY()].setCatnip(false);  // Remove catnip after collection
        player.setCatnip(true);  // Give catnip to the player
        std::cout << "You found some catnip!\n";
        return true;
    }
    return false;
}

void Map::moveCatWithCatnip() {
    if (player.hasCatnip()) {
        // Move the cat towards the player's position
        int dx = player.getX() - cat.getX();
        int dy = player.getY() - cat.getY();

        // Normalize the direction towards the player
        if (dx != 0) dx /= std::abs(dx);  // Move horizontally towards player
        if (dy != 0) dy /= std::abs(dy);  // Move vertically towards player

        int newX = cat.getX() + dx;
        int newY = cat.getY() + dy;

        // Ensure the cat stays within bounds
        if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
            cat.setPosition(newX, newY);
        }
        std::cout << "The cat is lured towards you by the catnip!\n";
    }
}
