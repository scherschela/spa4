#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include "Player.h"
#include "Cat.h"

class Map {
private:
    Room gameBoard[5][5];
    Player player;
    Cat cat;

public:
    Map();
    void display() const;
    void movePlayer(int direction);
    bool checkWin() const;
    bool checkLoss() const;
    bool checkNetCatch(int direction);
    bool playerCollectsCatnip();
    void moveCatWithCatnip();
};

#endif
