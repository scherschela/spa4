#include "Room.h"

Room::Room(RoomType type) : type(type) {}

RoomType Room::getType() const {
    return type;
}
