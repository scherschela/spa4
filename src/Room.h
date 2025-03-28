#ifndef ROOM_H
#define ROOM_H

enum class RoomType { EMPTY, DOG, MANHOLE };

class Room {
private:
    RoomType type;
public:
    Room(RoomType type = RoomType::EMPTY);
    RoomType getType() const;
};

#endif // ROOM_H
