#include "building.h"

#include "attendant.h"
#include "room.h"

Building::Building(const string& id, const string& name, const string& location)
    : buildingID(id), buildingName(name), buildingLocation(location), assignedAttendant(nullptr), assignedRooms() {}

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

void Building::setAssignedAttendant(Attendant* attendant) {
    assignedAttendant = attendant;
}

void Building::addRoom(Room* room) {
    assignedRooms.push_back(room);
}

void Building::displayInfo() const {
    cout << "Building Information:" << endl;
    cout << "Building ID: " << buildingID << endl;
    cout << "Building Name: " << buildingName << endl;
    cout << "Location: " << buildingLocation << endl;
    if (assignedAttendant) {
        cout << "Assigned Attendant ID: " << assignedAttendant->getId() << endl;
        cout << "Assigned Attendant Name: " << assignedAttendant->getName() << endl;
    } else {
        cout << "Assigned Attendant: None" << endl;
    }

    if (!assignedRooms.empty()) {
        cout << "Rooms in this Building:" << endl;
        for (const auto* room : assignedRooms) {
            if (room) {
                cout << "  Room ID: " << room->getRoomID() << ", Name: " << room->getRoomName()
                     << ", Capacity: " << room->getCapacity() << ", Floor: " << room->getFloor() << endl;
            }
        }
    } else {
        cout << "Rooms in this Building: None" << endl;
    }
}
