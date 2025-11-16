#pragma once
#include "Person.h"
#include <vector>
class LabSection;

class TA : public Person {
  private:
    string TeachingAssistantId;
    vector<LabSection*> assignedSections;

  public:
    TA(const string& id, const string& name, const string& email, const string& phone, const string& tid)
        : Person(id, name, email, phone), TeachingAssistantId(tid), assignedSections() {}

    void displayInfo() const {
        cout << "Teaching Assistant Information:" << endl;
        cout << "Teaching Assistant Id: " << TeachingAssistantId << endl;
        Person::displayInfo();
    }
};