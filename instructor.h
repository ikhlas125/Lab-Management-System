#pragma once
#include "LabSection.h"
#include "Person.h"

class Instructor : public Person {
  private:
    string intructorId;
    vector<LabSection*> assignedSections;

  public:
    Instructor(const string& id, const string& name, const string& email, const string& phone, const string& iid);
    string getInstructorId() const;
    void addAssignedSection(LabSection* section);
    void displayInfo() const;
};