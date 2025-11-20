#pragma once
#include "Person.h"
#include <vector>
class LabSection;

class TA : public Person {
  private:
    string TeachingAssistantId;
    vector<LabSection*> assignedSections;

  public:
    TA(const string& id, const string& name, const string& email, const string& phone, const string& tid);
    string getTAId() const;
    void addAssignedSection(LabSection* section);
    void displayInfo() const;
};