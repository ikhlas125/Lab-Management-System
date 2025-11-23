#include "Lab.h"

Lab::Lab(const string& id, const string& name, const string& code, int cred, const string& sem)
    : labId(id), labName(name), labCode(code), credits(cred), semester(sem) {}

string Lab::getLabId() const {
    return labId;
}

string Lab::getLabName() const {
    return labName;
}

string Lab::getLabCode() const {
    return labCode;
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

void Lab::setLabCode(const string& code) {
    labCode = code;
}

void Lab::setCredits(int cred) {
    credits = cred;
}

void Lab::setSemester(const string& sem) {
    semester = sem;
}

void Lab::displayInfo() const {
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Labs Information: " << endl;
    cout << "Lab ID: " << labId << endl;
    cout << "Lab Name: " << labName << endl;
    cout << "code: " << labCode << endl;
    cout << "Credits: " << credits << endl;
    cout << "Semester: " << semester << endl;
}
