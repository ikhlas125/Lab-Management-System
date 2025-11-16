#include "Person.h"

Person::Person(const string& id, const string& name, const string& email, const string& phone)
    : id(id), name(name), email(email), phone(phone) {}

string Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

string Person::getEmail() const {
    return email;
}

string Person::getPhone() const {
    return phone;
}

void Person::setName(const string& newName) {
    name = newName;
}

void Person::setId(const string& newId) {
    id = newId;
}

void Person::setEmail(const string& newEmail) {
    email = newEmail;
}

void Person::setPhone(const string& newPhone) {
    phone = newPhone;
}

void Person::displayInfo() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
}
