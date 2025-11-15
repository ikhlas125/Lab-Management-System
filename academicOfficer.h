#pragma once
#include "Person.h" 

class AcademicOfficer : public Person {
private:
    

public:
    AcademicOfficer(const string& id, const string& name, const string& email, const string& phone)
        : Person(id, name, email, phone) {}

    void displayInfo() const {
        cout << "Academic Officer Information:" << endl;
        Person::displayInfo();
    }
};