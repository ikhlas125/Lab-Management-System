#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Attendant;
class Room;

class Building {
  private:
    string buildingID;
    string buildingName;
    string buildingLocation;
    Attendant* assignedAttendant;
    vector<Room*> assignedRooms;

  public:
    Building(const string& id, const string& name, const string& location);

    string getBuildingID() const;
    string getBuildingName() const;
    string getBuildingLocation() const;
    void addRoom(Room* room);
    void setBuildingName(const string& name);
    void setBuildingLocation(const string& location);
    void setAssignedAttendant(Attendant* attendant);
    void displayInfo() const;
};