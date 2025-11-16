#include "LabSession.h"

LabSession::LabSession(const string& id, const string& date, const string& start, const string& end, const string& top)
    : sessionID(id), sessionDate(date), startTime(start), endTime(end), topic(top) {}

string LabSession::getSessionID() const {
    return sessionID;
}

string LabSession::getSessionDate() const {
    return sessionDate;
}

string LabSession::getStartTime() const {
    return startTime;
}

string LabSession::getEndTime() const {
    return endTime;
}

string LabSession::getTopic() const {
    return topic;
}

void LabSession::setSessionDate(const string& date) {
    sessionDate = date;
}

void LabSession::setStartTime(const string& start) {
    startTime = start;
}

void LabSession::setEndTime(const string& end) {
    endTime = end;
}

void LabSession::setTopic(const string& top) {
    topic = top;
}

void LabSession::displayInfo() const {
    cout << "Session ID: " << sessionID << endl;
    cout << "Date: " << sessionDate << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Topic: " << topic << endl;
}
