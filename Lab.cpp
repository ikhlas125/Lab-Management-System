#include "Lab.h"

Lab::Lab(const string& id, const string& name, const string& location, int cred, const string& sem)
    : labId(id), labName(name), labLocation(location), credits(cred), semester(sem) {}

string Lab::getLabId() const {
    return labId;
}

string Lab::getLabName() const {
    return labName;
}

string Lab::getLabLocation() const {
    return labLocation;
}

int Lab::getCredits() const {
    return credits;
}

string Lab::getSemester() const {
    return semester;
}

void Lab::setLabName(const string& name) {
    labName = name;
}

void Lab::setLabLocation(const string& location) {
    labLocation = location;
}

void Lab::setCredits(int cred) {
    credits = cred;
}

void Lab::setSemester(const string& sem) {
    semester = sem;
}

void Lab::displayInfo() const {
    cout << "Lab ID: " << labId << endl;
    cout << "Lab Name: " << labName << endl;
    cout << "Location: " << labLocation << endl;
    cout << "Credits: " << credits << endl;
    cout << "Semester: " << semester << endl;
}
