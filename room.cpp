#include "room.h"

Room::Room(const string& id, const string& name, int cap, int flr)
    : roomID(id), roomName(name), capacity(cap), floor(flr) {}

string Room::getRoomID() const {
    return roomID;
}

string Room::getRoomName() const {
    return roomName;
}

int Room::getCapacity() const {
    return capacity;
}

int Room::getFloor() const {
    return floor;
}

void Room::setRoomName(const string& name) {
    roomName = name;
}

void Room::setCapacity(int cap) {
    capacity = cap;
}

void Room::displayInfo() const {
    cout << "Room ID: " << roomID << endl;
    cout << "Room Name: " << roomName << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Floor: " << floor << endl;
}
