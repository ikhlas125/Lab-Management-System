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
    Person(const string& id, const string& name, const string& email, const string& phone)
        : id(id), name(name), email(email), phone(phone) {}

    string getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }

    string getPhone() const {
        return phone;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setId(const string& newId) {
        id = newId;
    }

    void setEmail(const string& newEmail) {
        email = newEmail;
    }

    void setPhone(const string& newPhone) {
        phone = newPhone;
    }

    void displayInfo() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};