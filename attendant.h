#pragma once
#include "Person.h"
#include "building.h"
#include <vector>

class TimeSheet;

class Attendant : public Person {
  private:
    string AttendantId;
    Building* assignedBuilding;
    vector<TimeSheet*> filledTimesheets;

  public:
    Attendant(const string& id, const string& name, const string& email, const string& phone, const string& aid);
    string getAttendantId() const;
    Building* getAssignedBuilding() const;
    const vector<TimeSheet*>& getFilledTimesheets() const;
    void setAttendantId(const string& aid);
    void setAssignedBuilding(Building* building);
    void addTimesheet(TimeSheet* timesheet);
    void displayInfo() const;
};