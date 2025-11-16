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
    Building(const string& id, const string& name, const string& location)
        : buildingID(id), buildingName(name), buildingLocation(location), assignedAttendant(nullptr) {}

    string getBuildingID() const {
        return buildingID;
    }

    string getBuildingName() const {
        return buildingName;
    }

    string getBuildingLocation() const {
        return buildingLocation;
    }

    void setBuildingName(const string& name) {
        buildingName = name;
    }

    void setBuildingLocation(const string& location) {
        buildingLocation = location;
    }

    void displayInfo() const {
        cout << "Building ID: " << buildingID << endl;
        cout << "Building Name: " << buildingName << endl;
        cout << "Location: " << buildingLocation << endl;
    }
};