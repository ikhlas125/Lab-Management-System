#pragma once
#include "Person.h"

class Instructor : public Person {
  private:
    string intructorId;

  public:
    Instructor(const string& id, const string& name, const string& email, const string& phone, const string& iid)
        : Person(id, name, email, phone), intructorId(iid) {}

    void displayInfo() const {
        cout << "Instructor Information:" << endl;
        cout << "Instructor Id: " << intructorId << endl;
        Person::displayInfo();
    }
};