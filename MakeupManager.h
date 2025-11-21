#pragma once
#include "schedule.h"
#include <iostream>
using namespace std;

class DataManager;
class LabManager;
class CountManager;
class ScheduleManager;
class Instructor;
class LabSection;

class MakeupManager {
  private:
    DataManager* Data;
    ScheduleManager* ScheduleMgr;
    LabManager* LabMgr;
    CountManager* DataCount;

  public:
    MakeupManager(DataManager* dm, ScheduleManager* sm, LabManager* lm, CountManager* cm);

    void submitMakeupRequest(Instructor* requestBy, Day day, const string& startTime, const string& endTime,
                             string reason, LabSection* section);
    void approveMakeupRequest(const string& requestId, const string& roomId, const string& weeknum);
    void rejectMakeupRequest(const string& requestId);
};