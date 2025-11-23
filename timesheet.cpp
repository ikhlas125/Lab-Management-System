#include "timesheet.h"

#include "DateTime.h"
#include "attendant.h"
#include <sstream>

TimeSheet::TimeSheet(const string& id, const string& startTime, const string& endTime, Attendant* attendant,
                     const string& duration, const string& timestamp, const string& stat, LabSession* sessio)
    : timeSheetId(id), actualStartTime(startTime), actualEndTime(endTime), filledBy(attendant),
      actualDuration(duration), entryTimestamp(timestamp), status(stat), session(sessio) {}

string TimeSheet::getTimesheetID() const {
    return timeSheetId;
}

string TimeSheet::getActualStartTime() const {
    return actualStartTime;
}

string TimeSheet::getActualEndTime() const {
    return actualEndTime;
}

Attendant* TimeSheet::getFilledBy() const {
    return filledBy;
}

LabSession* TimeSheet::getSession() const {
    return session;
}

string TimeSheet::getActualDuration() const {
    return actualDuration;
}

string TimeSheet::getEntryTimestamp() const {
    return entryTimestamp;
}

string TimeSheet::getStatus() const {
    return status;
}

void TimeSheet::setActualStartTime(const string& startTime) {
    actualStartTime = startTime;
    calculateActualDuration();
}

void TimeSheet::setActualEndTime(const string& endTime) {
    actualEndTime = endTime;
    calculateActualDuration();
}

void TimeSheet::setFilledBy(Attendant* attendant) {
    filledBy = attendant;
}

void TimeSheet::setSession(LabSession* sess) {
    session = sess;
}

void TimeSheet::setActualDuration(const string& duration) {
    actualDuration = duration;
}

void TimeSheet::setEntryTimestamp(const string& timestamp) {
    entryTimestamp = timestamp;
}

void TimeSheet::setStatus(const string& stat) {
    status = stat;
}

void TimeSheet::calculateActualDuration() {
    if (actualStartTime.empty() || actualEndTime.empty()) {
        actualDuration = "0";
        return;
    }

    // Parse the time strings and calculate difference
    // For now, just set to "0" - implement actual calculation if needed
    actualDuration = "0";
}

void TimeSheet::displayInfo() const {
    cout << "-------------------------------------------------------------------" << endl;
    cout << "TimeSheet Information:" << endl;
    cout << "TimeSheet ID: " << timeSheetId << endl;
    cout << "Actual Duration: " << actualDuration << endl;
    cout << "Status: " << status << endl;

    if (!actualStartTime.empty()) {
        cout << "Actual Start Time: " << actualStartTime << endl;
    } else {
        cout << "Actual Start Time: Not Set" << endl;
    }

    if (!actualEndTime.empty()) {
        cout << "Actual End Time: " << actualEndTime << endl;
    } else {
        cout << "Actual End Time: Not Set" << endl;
    }

    if (!entryTimestamp.empty()) {
        cout << "Entry Timestamp: " << entryTimestamp << endl;
    } else {
        cout << "Entry Timestamp: Not Set" << endl;
    }

    if (filledBy) {
        cout << "Filled By: " << filledBy->getName() << " (ID: " << filledBy->getId() << ")" << endl;
    } else {
        cout << "Filled By: Not Assigned" << endl;
    }
}
