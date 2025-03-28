#ifndef CAT_H
#define CAT_H

#include "Entity.h"


class Cat : public Entity {
private:
    int x, y;

public:
    Cat();
    void setPosition(int newX, int newY);
    int getX() const;
    int getY() const;
    void moveRandom();
    void moveTowardPlayer(int playerX, int playerY);
};

#endif
