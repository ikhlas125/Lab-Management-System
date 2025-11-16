#pragma once
#include "ta.h"
#include <iostream>
#include <vector>
using namespace std;

class Instructor;

class LabSection {
  private:
    string sectionID;
    string sectionName;
    int maxStudents;
    string schedule;
    Instructor* assignedInstructor;
    vector<TA*> assignedTas;

  public:
    LabSection(const string& id, const string& name, int maxStud, const string& sched);

    string getSectionID() const;
    string getSectionName() const;
    int getMaxStudents() const;
    string getSchedule() const;
    void setSectionName(const string& name);
    void setMaxStudents(int maxStud);
    void setSchedule(const string& sched);
    void displayInfo() const;
};
