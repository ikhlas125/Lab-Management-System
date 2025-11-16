#pragma once
#include "Person.h"

class AcademicOfficer : public Person {
  private:
    string AcademicOfficerId;

  public:
    AcademicOfficer(const string& id, const string& name, const string& email, const string& phone, const string& aoid);
    void displayInfo() const;
};