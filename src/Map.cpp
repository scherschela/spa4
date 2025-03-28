#include "Map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Map::Map() {
    std::srand(std::time(0));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            gameBoard[i][j].setCatnip(false);
            gameBoard[i][j].setManhole(false);
        }
    }

    int catnipX = std::rand() % 5;
    int catnipY = std::rand() % 5;
    gameBoard[catnipX][catnipY].setCatnip(true);

    int manholeCount = 0;
    while (manholeCount < 2) {
        int manholeX = std::rand() % 5;
        int manholeY = std::rand() % 5;

        if (!gameBoard[manholeX][manholeY].getCatnip() && !gameBoard[manholeX][manholeY].getManhole()) {
            gameBoard[manholeX][manholeY].setManhole(true);
            manholeCount++;
        }
    }

    player.setPosition(std::rand() % 5, std::rand() % 5);
    do {
        cat.setPosition(std::rand() % 5, std::rand() % 5);
    } while (player.getX() == cat.getX() && player.getY() == cat.getY());
}

void Map::display() const {
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (player.getX() == x && player.getY() == y) {
                std::cout << "P ";
            } else if (cat.getX() == x && cat.getY() == y) {
                std::cout << "C ";
            } else if (gameBoard[x][y].getCatnip()) {
                std::cout << "N ";
            } else if (gameBoard[x][y].getManhole()) {
                std::cout << "M ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

void Map::movePlayer(int direction) {
    int dx = 0, dy = 0;
    switch (direction) {
        case 0: dy = -1; break;
        case 1: dx = 1; break;
        case 2: dy = 1; break;
        case 3: dx = -1; break;
        default: return;
    }

    int newX = player.getX() + dx;
    int newY = player.getY() + dy;

    if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
        player.setPosition(newX, newY);

        if (gameBoard[newX][newY].getManhole()) {
            std::cout << "You fell into a manhole! Game over.\n";
            exit(0);
        }

        playerCollectsCatnip();
    }
}

bool Map::checkWin() const {
    return player.getX() == cat.getX() && player.getY() == cat.getY();
}

bool Map::checkLoss() const {
    return player.getX() == cat.getX() && player.getY() == cat.getY();
}

bool Map::checkNetCatch(int direction) {
    int dx = 0, dy = 0;
    switch (direction) {
        case 0: dy = -1; break;
        case 1: dx = 1; break;
        case 2: dy = 1; break;
        case 3: dx = -1; break;
        default: return false;
    }

    int newX = player.getX() + dx;
    int newY = player.getY() + dy;

    return newX == cat.getX() && newY == cat.getY();
}

bool Map::playerCollectsCatnip() {
    if (gameBoard[player.getX()][player.getY()].getCatnip()) {
        gameBoard[player.getX()][player.getY()].setCatnip(false);
        player.setCatnip(true);
        std::cout << "You found some catnip!\n";
        return true;
    }
    return false;
}

void Map::moveCatWithCatnip() {
    if (player.hasCatnip()) {
        int dx = player.getX() - cat.getX();
        int dy = player.getY() - cat.getY();

        if (dx != 0) dx /= std::abs(dx);
        if (dy != 0) dy /= std::abs(dy);

        int newX = cat.getX() + dx;
        int newY = cat.getY() + dy;

        if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
            cat.setPosition(newX, newY);
        }
        std::cout << "The cat is lured towards you by the catnip!\n";
    }
}
