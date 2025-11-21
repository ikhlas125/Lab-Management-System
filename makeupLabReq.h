#pragma once
#include "schedule.h"
#include <iostream>
using namespace std;

class Instructor;
class LabSession;
class LabSection;

class MakeupRequest {
  private:
    string requestId;
    Instructor* requestedBy;
    Day requestedDay;
    string requestedStartTime;
    string requestedEndTime;
    string reason;
    string status;
    LabSection* requestedSection;
    LabSession* makeupSession;

  public:
    MakeupRequest(const string& id, Instructor* instructor, Day day, const string& startTime, const string& endTime,
                  const string& rsn, const string& stat, LabSection* section);

    string getRequestId() const;
    Instructor* getRequestedBy() const;
    Day getRequestedDay() const;
    string getRequestedStartTime() const;
    string getRequestedEndTime() const;
    string getReason() const;
    string getStatus() const;
    LabSection* getRequestedSection() const;
    LabSession* getMakeupSession() const;

    void setReason(const string& rsn);
    void setStatus(const string& stat);
    void setRequestedDay(Day day);
    void setRequestedStartTime(const string& startTime);
    void setRequestedEndTime(const string& endTime);
    void setRequestedSection(LabSection* section);
    void setMakeupSession(LabSession* session);

    void displayInfo() const;
};