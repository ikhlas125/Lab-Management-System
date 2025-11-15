#pragma once
#include "Person.h"

class Attendant : public Person {
private:

public:
    Attendant(const string& id, const string& name, const string& email, const string& phone)
        : Person(id, name, email, phone) {}

    void displayInfo() const {
        cout << "Attendant Information:" << endl;
        Person::displayInfo();
    }
};