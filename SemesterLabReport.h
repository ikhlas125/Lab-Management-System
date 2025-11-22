#pragma once
#include <iostream>
using namespace std;
#include "Reports.h"
#include <vector>

class LabSection;
class TimeSheet;

class SemesterLabReport : public Report {
  private:
    LabSection* SectionForReport;
    vector<TimeSheet*> timesheets;
    int totalContactHours;
    int totalLeaves;

  public:
    SemesterLabReport(const string& id, HeadOfDep* by, const string& date, LabSection* section);

    LabSection* getSectionForReport() const;
    const vector<TimeSheet*>& getTimeSheets() const;
    int getTotalContactHours() const;
    int getTotalLeaves() const;

    void setSectionForReport(LabSection* section);
    void setTotalContactHours(int hours);
    void setTotalLeaves(int leaves);
    void setTimeSheets(const vector<TimeSheet*>& sheets);

    void calculateTotalContactHours();
    void calculateTotalLeaves();

    void print() const override;
};