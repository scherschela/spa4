#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include "Player.h"
#include "Cat.h"
#include <iostream>

class Map {
private:
    static const int SIZE = 5;
    Room grid[SIZE][SIZE];
    Player player;
    Cat cat;
public:
    Map();
    void movePlayer(int direction);
    void moveCat();
    void display();
    bool checkWin();
    bool checkLoss();
    bool checkNetCatch(int direction);
};

#endif // MAP_H
