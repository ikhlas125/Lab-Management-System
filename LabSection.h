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
    LabSection(const string& id, const string& name, int maxStud, const string& sched)
        : sectionID(id), sectionName(name), maxStudents(maxStud), schedule(sched), assignedInstructor(nullptr),
          assignedTas() {}

    string getSectionID() const {
        return sectionID;
    }

    string getSectionName() const {
        return sectionName;
    }

    int getMaxStudents() const {
        return maxStudents;
    }

    string getSchedule() const {
        return schedule;
    }

    void setSectionName(const string& name) {
        sectionName = name;
    }

    void setMaxStudents(int maxStud) {
        maxStudents = maxStud;
    }

    void setSchedule(const string& sched) {
        schedule = sched;
    }

    void displayInfo() const {
        cout << "Section ID: " << sectionID << endl;
        cout << "Section Name: " << sectionName << endl;
        cout << "Max Students: " << maxStudents << endl;
        cout << "Schedule: " << schedule << endl;
    }
};
