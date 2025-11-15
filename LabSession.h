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
    LabSession(const string& id, const string& date, const string& start, const string& end, const string& top)
        : sessionID(id), sessionDate(date), startTime(start), endTime(end), topic(top) {}

    string getSessionID() const {
        return sessionID;
    }

    string getSessionDate() const {
        return sessionDate;
    }

    string getStartTime() const {
        return startTime;
    }

    string getEndTime() const {
        return endTime;
    }

    string getTopic() const {
        return topic;
    }

    void setSessionDate(const string& date) {
        sessionDate = date;
    }

    void setStartTime(const string& start) {
        startTime = start;
    }

    void setEndTime(const string& end) {
        endTime = end;
    }

    void setTopic(const string& top) {
        topic = top;
    }

    void displayInfo() const {
        cout << "Session ID: " << sessionID << endl;
        cout << "Date: " << sessionDate << endl;
        cout << "Start Time: " << startTime << endl;
        cout << "End Time: " << endTime << endl;
        cout << "Topic: " << topic << endl;
    }
};
