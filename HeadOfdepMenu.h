#pragma once
#include <iostream>
using namespace std;

class ReportManager;
class DataManager;

class HeadOfDepMenu {
  private:
    ReportManager* reMgr;
    DataManager* datMgr;

  public:
    HeadOfDepMenu(ReportManager* reMgr, DataManager* datMgr);
    void show();
};