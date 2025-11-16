#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Person {
    string id;
    string name;
    string email;
    string phone;

  public:
    Person() = default;
    Person(const string& id, const string& name, const string& email, const string& phone);

    string getId() const;
    string getName() const;
    string getEmail() const;
    string getPhone() const;
    void setName(const string& newName);
    void setId(const string& newId);
    void setEmail(const string& newEmail);
    void setPhone(const string& newPhone);
    void displayInfo() const;
};