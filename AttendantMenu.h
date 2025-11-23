#pragma once
#include <iostream>
using namespace std;

class TimeSheetManager;
class LabManager;
class DataManager;

class AttendantMenu {
  private:
    TimeSheetManager* tsMgr;
    LabManager* labMgr;
    DataManager* datMgr;

  public:
    AttendantMenu(TimeSheetManager* tsMgr, LabManager* labMgr, DataManager* datMgr);
    void show();
};
