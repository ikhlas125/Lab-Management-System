#pragma once
#include <iostream>
using namespace std;

class DataManager;
class CountManager;
class HeadOfDep;

class ReportManager {
  private:
    DataManager* Data;
    CountManager* DataCount;

  public:
    ReportManager(DataManager* dm, CountManager* cm);

    void generateWeeklyLabScheduleReport(const string& week, HeadOfDep* genBy, const string& date);
    void generateWeeklyTimeSheetReport(const string& week, HeadOfDep* genBy, const string& date);
    void generateFullSectionReport(const string& sectionId, HeadOfDep* genBy);
};
