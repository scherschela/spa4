#ifndef CAT_H
#define CAT_H

class Cat {
private:
    int x, y;
public:
    Cat();
    int getX() const;
    int getY() const;
    void moveRandom();
    void lure(int playerX, int playerY);
};

#endif // CAT_H
