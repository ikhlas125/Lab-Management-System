#include "ta.h"

TA::TA(const string& id, const string& name, const string& email, const string& phone, const string& tid)
    : Person(id, name, email, phone), TeachingAssistantId(tid), assignedSections() {}

void TA::displayInfo() const {
    cout << "Teaching Assistant Information:" << endl;
    cout << "Teaching Assistant Id: " << TeachingAssistantId << endl;
    Person::displayInfo();
}
