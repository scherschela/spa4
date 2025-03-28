#ifndef GAME_H
#define GAME_H

#include "Map.h"

class Game {
private:
    bool debugMode = false;
    Map gameMap;
public:
    void start();
};

#endif
