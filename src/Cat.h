#ifndef CAT_H
#define CAT_H

class Cat {
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
