#pragma once
#include <iostream>
using namespace std;
#include "Reports.h"
#include <vector>

class LabSection;
class LabSession;

class SemesterLabReport : public Report {
  private:
    LabSection* SectionForReport;
    vector<LabSession*> sessions;
    int totalContactHours;
    int totalLeaves;

  public:
    SemesterLabReport(const string& id, HeadOfDep* by, const string& date, LabSection* section);

    LabSection* getSectionForReport() const;
    const vector<LabSession*>& getSessions() const;
    int getTotalContactHours() const;
    int getTotalLeaves() const;

    void setSectionForReport(LabSection* section);
    void setTotalContactHours(int hours);
    void setTotalLeaves(int leaves);
    void addSession(LabSession* session);

    void print() const override;
};