#include "building.h"

Building::Building(const string& id, const string& name, const string& location)
    : buildingID(id), buildingName(name), buildingLocation(location), assignedAttendant(nullptr) {}

string Building::getBuildingID() const {
    return buildingID;
}

string Building::getBuildingName() const {
    return buildingName;
}

string Building::getBuildingLocation() const {
    return buildingLocation;
}

void Building::setBuildingName(const string& name) {
    buildingName = name;
}

void Building::setBuildingLocation(const string& location) {
    buildingLocation = location;
}

void Building::displayInfo() const {
    cout << "Building ID: " << buildingID << endl;
    cout << "Building Name: " << buildingName << endl;
    cout << "Location: " << buildingLocation << endl;
}
