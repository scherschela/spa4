#ifndef CAT_H
#define CAT_H

class Cat {
private:
    int x, y;  // Coordinates of the cat

public:
    Cat();  // Constructor to initialize position
    void setPosition(int newX, int newY);  // Method to set the cat's position
    int getX() const;  // Get the x-coordinate
    int getY() const;  // Get the y-coordinate
    void moveRandom();  // Method to move the cat randomly
    void moveTowardPlayer(int playerX, int playerY);  // Move the cat toward the player
};

#endif
