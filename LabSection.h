#pragma once
#include <iostream>
using namespace std;

class LabSection {
  private:
    string sectionID;
    string sectionName;
    int maxStudents;
    string schedule;

  public:
    LabSection(const string& id, const string& name, int maxStud, const string& sched)
        : sectionID(id), sectionName(name), maxStudents(maxStud), schedule(sched) {}

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
