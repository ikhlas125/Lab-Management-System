#pragma once
#include "Person.h"

class TA : public Person {
  private:
    string TeachingAssistantId;

  public:
    TA(const string& id, const string& name, const string& email, const string& phone, const string& tid)
        : Person(id, name, email, phone), TeachingAssistantId(tid) {}

    void displayInfo() const {
        cout << "Teaching Assistant Information:" << endl;
        cout << "Teaching Assistant Id: " << TeachingAssistantId << endl;
        Person::displayInfo();
    }
};