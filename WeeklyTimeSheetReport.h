#pragma once
#include <iostream>
using namespace std;
#include "Reports.h"
#include <vector>

class TimeSheet;

class WeeklyTimeSheetReport : public Report {
  private:
    string weekNumber;
    vector<TimeSheet*> timeSheetsInWeek;

  public:
    WeeklyTimeSheetReport(const string& id, HeadOfDep* by, const string& date, const string& weekNum);

    string getWeekNumber() const;
    const vector<TimeSheet*>& getTimeSheetsInWeek() const;

    void setWeekNumber(const string& weekNum);
    void setTimeSheets(const vector<TimeSheet*>& timesheets);

    void print() const override;
};