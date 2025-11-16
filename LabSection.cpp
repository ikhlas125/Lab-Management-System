#include "LabSection.h"

LabSection::LabSection(const string& id, const string& name, int maxStud, const string& sched)
    : sectionID(id), sectionName(name), maxStudents(maxStud), schedule(sched), assignedInstructor(nullptr),
      assignedTas() {}

string LabSection::getSectionID() const {
    return sectionID;
}

string LabSection::getSectionName() const {
    return sectionName;
}

int LabSection::getMaxStudents() const {
    return maxStudents;
}

string LabSection::getSchedule() const {
    return schedule;
}

void LabSection::setSectionName(const string& name) {
    sectionName = name;
}

void LabSection::setMaxStudents(int maxStud) {
    maxStudents = maxStud;
}

void LabSection::setSchedule(const string& sched) {
    schedule = sched;
}

void LabSection::displayInfo() const {
    cout << "Section ID: " << sectionID << endl;
    cout << "Section Name: " << sectionName << endl;
    cout << "Max Students: " << maxStudents << endl;
    cout << "Schedule: " << schedule << endl;
}
