#include "room.h"

#include "building.h"

Room::Room(const string& id, const string& name, int cap, int flr)
    : roomID(id), roomName(name), capacity(cap), floor(flr), building(nullptr) {}

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

Building* Room::getBuilding() const {
    return building;
}

void Room::setRoomName(const string& name) {
    roomName = name;
}

void Room::setCapacity(int cap) {
    capacity = cap;
}

void Room::setBuilding(Building* b) {
    building = b;
}

void Room::displayInfo() const {
    cout << "Room Information:" << endl;
    cout << "Room ID: " << roomID << endl;
    cout << "Room Name: " << roomName << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Floor: " << floor << endl;
    if (building) {
        cout << "Building: " << building->getBuildingName() << " (" << building->getBuildingID() << ")" << endl;
    } else {
        cout << "Building: None" << endl;
    }
}
