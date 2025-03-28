#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include "Player.h"
#include "Cat.h"

class Map {
private:
    Room gameBoard[5][5];  // The 5x5 grid of rooms
    Player player;
    Cat cat;

public:
    Map();  // Constructor to initialize the game board
    void display() const;  // Display the game board
    void movePlayer(int direction);  // Move player based on direction
    bool checkWin() const;  // Check if the player caught the cat
    bool checkLoss() const;  // Check if the player stepped into the cat's room
    bool checkNetCatch(int direction);  // Check if the net catches the cat
    bool playerCollectsCatnip();  // Check if the player collects catnip in a room
    void moveCatWithCatnip();  // Move the cat towards the player if catnip is used
};

#endif
