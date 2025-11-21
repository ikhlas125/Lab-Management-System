#include "ta.h"

#include "LabSection.h"

TA::TA(const string& id, const string& name, const string& email, const string& phone, const string& tid)
    : Person(id, name, email, phone), TeachingAssistantId(tid), assignedSections() {}

string TA::getTAId() const {
    return TeachingAssistantId;
}

vector<LabSection*>& TA::getAssignedSections() {
    return assignedSections;
}

void TA::addAssignedSection(LabSection* section) {
    assignedSections.push_back(section);
}

void TA::displayInfo() const {
    cout << "Teaching Assistant Information:" << endl;
    cout << "Teaching Assistant Id: " << TeachingAssistantId << endl;
    Person::displayInfo();

    cout << "Assigned Sections (" << assignedSections.size() << "): ";
    if (assignedSections.empty()) {
        cout << "None" << endl;
    } else {
        for (size_t i = 0; i < assignedSections.size(); i++) {
            cout << assignedSections[i]->getSectionID();
            if (i < assignedSections.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}
