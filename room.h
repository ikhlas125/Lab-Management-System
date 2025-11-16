#pragma once
#include <iostream>
using namespace std;
class Building;
class Room {
  private:
    string roomID;
    string roomName;
    int capacity;
    int floor;
    Building* building;

  public:
    Room(const string& id, const string& name, int cap, int flr);

    string getRoomID() const;
    string getRoomName() const;
    int getCapacity() const;
    int getFloor() const;
    Building* getBuilding() const;
    void setRoomName(const string& name);
    void setCapacity(int cap);
    void setBuilding(Building* b);
    void displayInfo() const;
};