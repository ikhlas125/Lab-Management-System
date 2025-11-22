#pragma once
#include <iostream>
using namespace std;

class HeadOfDep;

class Report {
  private:
    string reportId;
    HeadOfDep* generatedBy;
    string generatedDate;

  public:
    Report(const string& id, HeadOfDep* by, const string& date);

    string getReportId() const;
    HeadOfDep* getGeneratedBy() const;
    string getGeneratedDate() const;

    virtual void print() const = 0;
};