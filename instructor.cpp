#include "instructor.h"

Instructor::Instructor(const string& id, const string& name, const string& email, const string& phone,
                       const string& iid)
    : Person(id, name, email, phone), intructorId(iid), assignedSections() {}

void Instructor::displayInfo() const {
    cout << "Instructor Information:" << endl;
    cout << "Instructor Id: " << intructorId << endl;
    Person::displayInfo();
}
