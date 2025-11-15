#pragma once
#include "Person.h"

class HeadOfDep : public Person {
private:

public:
    HeadOfDep(const string& id, const string& name, const string& email, const string& phone)
        : Person(id, name, email, phone) {}

    void displayInfo() const {
        cout << "Head of Department Information:" << endl;
        Person::displayInfo();
    }
};