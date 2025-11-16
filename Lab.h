#pragma once
#include <iostream>
using namespace std;

class Lab {
  private:
    string labId;
    string labName;
    string labLocation;
    int credits;
    string semester;

  public:
    Lab(const string& id, const string& name, const string& location, int cred, const string& sem);

    string getLabId() const;
    string getLabName() const;
    string getLabLocation() const;
    int getCredits() const;
    string getSemester() const;
    void setLabName(const string& name);
    void setLabLocation(const string& location);
    void setCredits(int cred);
    void setSemester(const string& sem);
    void displayInfo() const;
};