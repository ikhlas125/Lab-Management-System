#include "attendant.h"

Attendant::Attendant(const string& id, const string& name, const string& email, const string& phone, const string& aid)
    : Person(id, name, email, phone), assignedBuilding(nullptr), AttendantId(aid) {}

void Attendant::displayInfo() const {
    cout << "Attendant Information:" << endl;
    Person::displayInfo();
}
