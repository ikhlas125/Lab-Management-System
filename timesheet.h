#pragma once
#include <iostream>
using namespace std;

class Attendant;
class DateTime;

class TimeSheet {
  private:
    string timeSheetId;
    DateTime* actualStartTime;
    DateTime* actualEndTime;
    Attendant* filledBy;
    string actualDuration;
    DateTime* entryTimestamp;
    string status;

  public:
    TimeSheet(const string& id, const string& stat);

    string getTimesheetID() const;
    DateTime* getActualStartTime() const;
    DateTime* getActualEndTime() const;
    Attendant* getFilledBy() const;
    string getActualDuration() const;
    DateTime* getEntryTimestamp() const;
    string getStatus() const;

    void setActualStartTime(DateTime* startTime);
    void setActualEndTime(DateTime* endTime);
    void setFilledBy(Attendant* attendant);
    void setActualDuration(const string& duration);
    void setEntryTimestamp(DateTime* timestamp);
    void setStatus(const string& stat);

    void calculateActualDuration();
    void displayInfo() const;
};