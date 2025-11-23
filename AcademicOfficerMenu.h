#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class LabManager;
class ScheduleManager;
class DataManager;
class MakeupManager;

class AcademicOfficerMenu {
  private:
    LabManager* labMgr;
    ScheduleManager* schedMgr;
    DataManager* dataMgr;
    MakeupManager* makMgr;

  public:
    AcademicOfficerMenu(LabManager* labMgr, ScheduleManager* schedMgr, DataManager* dataMgr, MakeupManager* makMgr);
    void show();
};
