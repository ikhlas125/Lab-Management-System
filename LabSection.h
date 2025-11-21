#pragma once
#include "ta.h"
#include <iostream>
#include <vector>
using namespace std;

class Lab;
class Instructor;
class LabSession;

class LabSection {
  private:
    string sectionID;
    Lab* lab;
    Instructor* assignedInstructor;
    vector<TA*> assignedTas;
    vector<LabSession*> sessions;
    string sectionName;
    string semester;
    string academicYear;

  public:
    LabSection(const string& id, const string& name, const string& sem, const string& year);

    string getSectionID() const;
    string getSectionName() const;
    string getSemester() const;
    string getAcademicYear() const;
    Lab* getLab() const;
    Instructor* getAssignedInstructor() const;
    const vector<TA*>& getAssignedTas() const;
    vector<TA*>& getAssignedTas();
    const vector<LabSession*>& getSessions() const;
    vector<LabSession*>& getSessions();

    void setSectionName(const string& name);
    void setSemester(const string& sem);
    void setAcademicYear(const string& year);
    void setLab(Lab* l);
    void setAssignedInstructor(Instructor* instr);
    void addTA(TA* ta);
    void addSession(LabSession* session);
    void displayInfo() const;
};
