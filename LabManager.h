#pragma once
#include "schedule.h"
#include <iostream>

using namespace std;
#include <vector>

class DataManager;
class CountManager;
class Lab;
class Instructor;
class TA;
class LabSection;
class Schedule;
class Room;
class Lab;

class LabManager {
  private:
    DataManager* Data;
    CountManager* DataCount;

  public:
    LabManager(DataManager* dm, CountManager* dc);

    void addLabs(const string& name, const string& code, int cred, const string& sem);
    void addLabSections(const string& name, const string& year, Lab* lab, Instructor* assignInstructor);
    void assignTAs(TA* TaAssigned, LabSection* assignTo);
    void createLabSession(const string& weekNum, const string& status, LabSection* section, Schedule* schedule,
                          Room* room);
    bool isClashless(Day day, const string& startTime, const string& endTime, Room* room);

    vector<Lab>& getLabs();
    vector<LabSection>& getLabSections();
};