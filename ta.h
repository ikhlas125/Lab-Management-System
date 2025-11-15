#pragma once
#include "Person.h"

class TA : public Person {
private:
    

public:
    TA(const string& id, const string& name, const string& email, const string& phone)
        : Person(id, name, email, phone) {}

    void displayInfo() const {
        cout << "Teaching Assistant Information:" << endl;
        Person::displayInfo();
    }
};