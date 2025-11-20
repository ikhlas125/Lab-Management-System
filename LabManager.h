#pragma once
#include <iostream>
using namespace std;

class DataManager;
class CountManager;
class Lab;
class Instructor;
class TA;
class LabSection;
class Schedule;
class Room;

class LabManager {
  private:
    DataManager* Data;
    CountManager* DataCount;

  public:
    LabManager(DataManager* dm, CountManager* dc);

    void addLabs(const string& name, const string& code, int cred, const string& sem);
    void addLabSections(const string& name, const string& sem, const string& year, Lab* lab,
                        Instructor* assignInstructor);
    void assignTAs(TA* TaAssigned, LabSection* assignTo);
    void createLabSession(const string& weekNum, const string& status, LabSection* section, Schedule* schedule,
                          Room* room);
};