#pragma once
#include "Person.h"
#include "building.h"

class Attendant : public Person {
  private:
    string AttendantId;
    Building* assignedBuilding;

  public:
    Attendant(const string& id, const string& name, const string& email, const string& phone, const string& aid);
    string getAttendantId() const;
    Building* getAssignedBuilding() const;
    void setAttendantId(const string& aid);
    void setAssignedBuilding(Building* building);
    void displayInfo() const;
};