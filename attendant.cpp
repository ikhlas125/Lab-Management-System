#include "attendant.h"

Attendant::Attendant(const string& id, const string& name, const string& email, const string& phone, const string& aid)
    : Person(id, name, email, phone), assignedBuilding(nullptr), AttendantId(aid) {}

string Attendant::getAttendantId() const {
    return AttendantId;
}

Building* Attendant::getAssignedBuilding() const {
    return assignedBuilding;
}

void Attendant::setAttendantId(const string& aid) {
    AttendantId = aid;
}

void Attendant::setAssignedBuilding(Building* building) {
    assignedBuilding = building;
}

void Attendant::displayInfo() const {
    cout << "Attendant Information:" << endl;
    cout << "Attendant Id: " << AttendantId << endl;
    Person::displayInfo();
    if (assignedBuilding) {
        cout << "Assigned Building: " << assignedBuilding->getBuildingName() << " ("
             << assignedBuilding->getBuildingID() << ")" << endl;
    } else {
        cout << "Assigned Building: None" << endl;
    }
}
