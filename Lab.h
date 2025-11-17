#pragma once
#include <iostream>
using namespace std;

class Lab {
  private:
    string labId;
    string labName;
    string labCode;
    int credits;
    string semester;

  public:
    Lab(const string& id, const string& name, const string& code, int cred, const string& sem);

    string getLabId() const;
    string getLabName() const;
    string getLabCode() const;
    int getCredits() const;
    string getSemester() const;
    void setLabName(const string& name);
    void setLabCode(const string& code);
    void setCredits(int cred);
    void setSemester(const string& sem);
    void displayInfo() const;
};