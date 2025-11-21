#pragma once
#include <iostream>
using namespace std;

class DataManager;
class CountManager;
class Attendant;
class LabSession;

class TimeSheetManager {
  private:
    DataManager* Data;
    CountManager* DataCount;

  public:
    TimeSheetManager(DataManager* dm, CountManager* cm);

    void fillTimeSheet(const string& startTime, const string& endTime, Attendant* attendant, const string& duration,
                       const string& timestamp, const string& stat, LabSession* sessio);
};