#pragma once
#include <iostream>
using namespace std;

class LabSection;
class Room;
class Schedule;
class TimeSheet;

class LabSession {
  private:
    string sessionID;
    LabSection* section;
    Room* assignedRoom;
    Schedule* schedule;
    TimeSheet* timeSheet;
    string WeekNumber;
    string status;

  public:
    LabSession(const string& id, const string& weekNum, const string& stat);

    string getSessionID() const;
    LabSection* getSection() const;
    Room* getAssignedRoom() const;
    Schedule* getSchedule() const;
    TimeSheet* getTimeSheet() const;
    string getWeekNumber() const;
    string getStatus() const;

    void setSection(LabSection* sec);
    void setAssignedRoom(Room* room);
    void setSchedule(Schedule* sched);
    void setTimeSheet(TimeSheet* ts);
    void setWeekNumber(const string& weekNum);
    void setStatus(const string& stat);

    void displayInfo() const;
};
