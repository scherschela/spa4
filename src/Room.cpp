#include "Room.h"

Room::Room() : hasCatnip(false), hasDog(false), hasManhole(false) {}

void Room::setCatnip(bool value) {
    hasCatnip = value;  // Set whether the room has catnip
}

bool Room::getCatnip() const {
    return hasCatnip;   // Return if the room contains catnip
}

void Room::setManhole(bool value) {
    hasManhole = value;  // Set whether the room has a manhole
}

bool Room::getManhole() const {
    return hasManhole;   // Return if the room contains a manhole
}