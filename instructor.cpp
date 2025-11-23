#include "instructor.h"

Instructor::Instructor(const string& id, const string& name, const string& email, const string& phone,
                       const string& iid)
    : Person(id, name, email, phone), intructorId(iid), assignedSections() {}

string Instructor::getInstructorId() const {
    return intructorId;
}

void Instructor::addAssignedSection(LabSection* section) {
    if (section) {
        assignedSections.push_back(section);
    }
}

vector<LabSection*>& Instructor::getAssignedSections() {
    return assignedSections;
}

void Instructor::displayInfo() const {
    cout << "Instructor Information:" << endl;
    cout << "Instructor Id: " << intructorId << endl;
    Person::displayInfo();

    if (!assignedSections.empty()) {
        cout << "Assigned Sections (" << assignedSections.size() << "):" << endl;
        for (const auto& section : assignedSections) {
            if (section) {
                cout << "  - " << section->getSectionName() << " (ID: " << section->getSectionID() << ")" << endl;
            }
        }
    } else {
        cout << "Assigned Sections: None" << endl;
    }
}
