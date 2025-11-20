#pragma once
#include "schedule.h"
#include <iostream>
#include <string>
using namespace std;

class DataManager;
class LabSession;
class CountManager;

class ScheduleManager {
  private:
    DataManager* Data;
    CountManager* DataCount;

  public:
    ScheduleManager(DataManager* dm, CountManager* cm);

    void createSchedule(Day day, const string& startTime, const string& endTime);
};