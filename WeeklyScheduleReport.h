#pragma once
#include <iostream>
using namespace std;
#include "Reports.h"
#include <vector>

class LabSession;

class WeeklyScheduleReport : public Report {
  private:
    string weekNumber;
    vector<LabSession*> sessionsInWeek;

  public:
    WeeklyScheduleReport(const string& id, HeadOfDep* by, const string& date, const string& weekNum);

    string getWeekNumber() const;
    const vector<LabSession*>& getSessionsInWeek() const;

    void setWeekNumber(const string& weekNum);
    void setSessions(const vector<LabSession*>& sessions);

    void print() const override;
};