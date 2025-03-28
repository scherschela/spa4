#ifndef ROOM_H
#define ROOM_H

class Room {
public:
    bool hasCatnip;
    bool hasDog;
    bool hasManhole;

    Room();

    void setCatnip(bool value);
    bool getCatnip() const;
    void setManhole(bool value);
    bool getManhole() const;
};

#endif
