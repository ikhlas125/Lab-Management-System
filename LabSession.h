#pragma once
#include <iostream>
using namespace std;

class LabSession {
  private:
    string sessionID;
    string sessionDate;
    string startTime;
    string endTime;
    string topic;

  public:
    LabSession(const string& id, const string& date, const string& start, const string& end, const string& top);

    string getSessionID() const;
    string getSessionDate() const;
    string getStartTime() const;
    string getEndTime() const;
    string getTopic() const;
    void setSessionDate(const string& date);
    void setStartTime(const string& start);
    void setEndTime(const string& end);
    void setTopic(const string& top);
    void displayInfo() const;
};
