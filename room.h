#pragma once
#include <iostream>
using namespace std;

class Room {
private:
    string roomID;
    string roomName;
    int capacity;
    int floor;

public:
    Room(const string& id, const string& name, int cap, int flr)
        : roomID(id), roomName(name), capacity(cap), floor(flr) {}

    string getRoomID() const {
        return roomID;
    }

    string getRoomName() const {
        return roomName;
    }

    int getCapacity() const {
        return capacity;
    }

    int getFloor() const {
        return floor;
    }

    void setRoomName(const string& name) {
        roomName = name;
    }

    void setCapacity(int cap) {
        capacity = cap;
    }

    void displayInfo() const {
        cout << "Room ID: " << roomID << endl;
        cout << "Room Name: " << roomName << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Floor: " << floor << endl;
    }
};