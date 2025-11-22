#include "headOfDep.h"

HeadOfDep::HeadOfDep(const string& id, const string& name, const string& email, const string& phone,
                     const string& hodid)
    : Person(id, name, email, phone), HeadOfDepId(hodid) {}

string HeadOfDep::getHODId() const {
    return HeadOfDepId;
}

void HeadOfDep::displayInfo() const {
    cout << "Head of Department Information:" << endl;
    cout << "Head of Department Id: " << HeadOfDepId << endl;
    Person::displayInfo();
}
