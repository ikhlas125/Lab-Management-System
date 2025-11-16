#include "headOfDep.h"

HeadOfDep::HeadOfDep(const string& id, const string& name, const string& email, const string& phone)
    : Person(id, name, email, phone) {}

void HeadOfDep::displayInfo() const {
    cout << "Head of Department Information:" << endl;
    Person::displayInfo();
}
