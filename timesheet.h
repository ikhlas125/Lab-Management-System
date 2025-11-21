#pragma once
#include <iostream>
using namespace std;

class Attendant;
class DateTime;
class LabSession;

class TimeSheet {
  private:
    string timeSheetId;
    string actualStartTime;
    string actualEndTime;
    Attendant* filledBy;
    LabSession* session;
    string actualDuration;
    string entryTimestamp;
    string status;

  public:
    TimeSheet(const string& id, const string& startTime, const string& endTime, Attendant* attendant,
              const string& duration, const string& timestamp, const string& stat, LabSession* sessio);

    string getTimesheetID() const;
    string getActualStartTime() const;
    string getActualEndTime() const;
    Attendant* getFilledBy() const;
    LabSession* getSession() const;
    string getActualDuration() const;
    string getEntryTimestamp() const;
    string getStatus() const;

    void setActualStartTime(const string& startTime);
    void setActualEndTime(const string& endTime);
    void setFilledBy(Attendant* attendant);
    void setSession(LabSession* sess);
    void setActualDuration(const string& duration);
    void setEntryTimestamp(const string& timestamp);
    void setStatus(const string& stat);

    void calculateActualDuration();
    void displayInfo() const;
};