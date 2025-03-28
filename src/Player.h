#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : Entity {
private:
    int x, y;
    bool catnip;

public:
    Player();
    void setPosition(int newX, int newY);
    int getX() const;
    int getY() const;
    bool hasCatnip() const;
    void setCatnip(bool value);
};

#endif
