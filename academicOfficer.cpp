#include "academicOfficer.h"

AcademicOfficer::AcademicOfficer(const string& id, const string& name, const string& email, const string& phone, const string& aoid)
    : Person(id, name, email, phone), AcademicOfficerId(aoid) {}

void AcademicOfficer::displayInfo() const {
    cout << "Academic Officer Information:" << endl;
    cout << "Academic Officer: " << AcademicOfficerId << endl;
    Person::displayInfo();
}
