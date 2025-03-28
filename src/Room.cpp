#include "Room.h"

Room::Room() : hasCatnip(false), hasDog(false), hasManhole(false) {}

void Room::setCatnip(bool value) {
    hasCatnip = value;
}

bool Room::getCatnip() const {
    return hasCatnip;
}

void Room::setManhole(bool value) {
    hasManhole = value;
}

bool Room::getManhole() const {
    return hasManhole;
}