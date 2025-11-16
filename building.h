#pragma once
#include <iostream>
using namespace std;

class Attendant;

class Building {
  private:
    string buildingID;
    string buildingName;
    string buildingLocation;
    Attendant* assignedAttendant;

  public:
    Building(const string& id, const string& name, const string& location);

    string getBuildingID() const;
    string getBuildingName() const;
    string getBuildingLocation() const;
    void setBuildingName(const string& name);
    void setBuildingLocation(const string& location);
    void displayInfo() const;
};