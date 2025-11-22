#pragma once
#include <iostream>
using namespace std;

class DataManager;
class CountManager;
class HeadOfDep;
class LabSection;

class ReportManager {
  private:
    DataManager* Data;
    CountManager* DataCount;

  public:
    ReportManager(DataManager* dm, CountManager* cm);

    void generateWeeklyLabScheduleReport(const string& week, HeadOfDep* genBy, const string& date);
    void generateWeeklyTimeSheetReport(const string& week, HeadOfDep* genBy, const string& date);
    void generateFullSectionReport(HeadOfDep* genBy, const string& date, LabSection* section, const string& sem);
};
