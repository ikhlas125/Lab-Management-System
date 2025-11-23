#pragma once
#include <iostream>
using namespace std;

class TimeSheetManager;
class LabManager;
class DataManager;
class MakeupManager;

class InstructureMenu {
  private:
    LabManager* labMgr;
    DataManager* datMgr;
    MakeupManager* mkMgr;

  public:
    InstructureMenu(LabManager* labMgr, DataManager* datMgr, MakeupManager* mkMgr);
    void show();
};