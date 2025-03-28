#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int x, y;
    int catnip; // Number of catnip uses
public:
    Player();
    int getX() const;
    int getY() const;
    void move(int dx, int dy);
    void useCatnip();
    bool hasCatnip() const;
};

#endif // PLAYER_H
