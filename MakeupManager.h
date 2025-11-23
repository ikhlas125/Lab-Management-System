#pragma once
#include "makeupLabReq.h"
#include "schedule.h"
#include <iostream>
#include <vector>
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
    void reviewMakeupRequest(const string& requestId, const string& roomId, const string& weeknum);
    void rejectMakeupRequest(const string& requestId);
    vector<MakeupRequest>& getMakeupRequests();
};