#ifndef ROOM_H
#define ROOM_H

class Room {
public:
    bool hasCatnip;  // Whether this room has catnip
    bool hasDog;     // Whether this room has a dog
    bool hasManhole; // Whether this room has a manhole

    Room();          // Constructor

    void setCatnip(bool value);  // Set the catnip flag
    bool getCatnip() const;      // Get if the room has catnip
};

#endif
