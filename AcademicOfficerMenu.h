#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class LabManager;
class ScheduleManager;
class DataManager;

class AcademicOfficerMenu {
  private:
    LabManager* labMgr;
    ScheduleManager* schedMgr;
    DataManager* dataMgr;

  public:
    AcademicOfficerMenu(LabManager* labMgr, ScheduleManager* schedMgr, DataManager* dataMgr);
    void show();
};
