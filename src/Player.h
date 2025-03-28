#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int x, y;   // Coordinates of the player
    bool catnip;  // Flag to check if the player has catnip

public:
    Player();  // Constructor to initialize position and catnip status
    void setPosition(int newX, int newY);  // Method to set the player's position
    int getX() const;  // Get the x-coordinate
    int getY() const;  // Get the y-coordinate
    bool hasCatnip() const;  // Check if the player has catnip
    void setCatnip(bool value);  // Set the player's catnip status
};

#endif
