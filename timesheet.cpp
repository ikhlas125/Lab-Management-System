#include "timesheet.h"

#include "DateTime.h"
#include "attendant.h"
#include <sstream>

TimeSheet::TimeSheet(const string& id, const string& stat)
    : timeSheetId(id), actualStartTime(nullptr), actualEndTime(nullptr), filledBy(nullptr), actualDuration("0"),
      entryTimestamp(nullptr), status(stat) {}

string TimeSheet::getTimesheetID() const {
    return timeSheetId;
}

DateTime* TimeSheet::getActualStartTime() const {
    return actualStartTime;
}

DateTime* TimeSheet::getActualEndTime() const {
    return actualEndTime;
}

Attendant* TimeSheet::getFilledBy() const {
    return filledBy;
}

string TimeSheet::getActualDuration() const {
    return actualDuration;
}

DateTime* TimeSheet::getEntryTimestamp() const {
    return entryTimestamp;
}

string TimeSheet::getStatus() const {
    return status;
}

void TimeSheet::setActualStartTime(DateTime* startTime) {
    actualStartTime = startTime;
    calculateActualDuration();
}

void TimeSheet::setActualEndTime(DateTime* endTime) {
    actualEndTime = endTime;
    calculateActualDuration();
}

void TimeSheet::setFilledBy(Attendant* attendant) {
    filledBy = attendant;
}

void TimeSheet::setActualDuration(const string& duration) {
    actualDuration = duration;
}

void TimeSheet::setEntryTimestamp(DateTime* timestamp) {
    entryTimestamp = timestamp;
}

void TimeSheet::setStatus(const string& stat) {
    status = stat;
}

void TimeSheet::calculateActualDuration() {
    if (!actualStartTime || !actualEndTime) {
        actualDuration = "0";
        return;
    }

    int diffSeconds = actualEndTime->calculateTimeDifference(*actualStartTime);
    if (diffSeconds < 0)
        diffSeconds = 0;

    double hours = diffSeconds / 3600.0;

    ostringstream oss;
    oss.setf(ios::fixed);
    oss.precision(2);
    oss << hours;
    actualDuration = oss.str();
}

void TimeSheet::displayInfo() const {
    cout << "TimeSheet Information:" << endl;
    cout << "TimeSheet ID: " << timeSheetId << endl;
    cout << "Actual Duration: " << actualDuration << endl;
    cout << "Status: " << status << endl;

    if (actualStartTime) {
        cout << "Actual Start Time: " << actualStartTime->toString() << endl;
    } else {
        cout << "Actual Start Time: Not Set" << endl;
    }

    if (actualEndTime) {
        cout << "Actual End Time: " << actualEndTime->toString() << endl;
    } else {
        cout << "Actual End Time: Not Set" << endl;
    }

    if (entryTimestamp) {
        cout << "Entry Timestamp: " << entryTimestamp->toString() << endl;
    } else {
        cout << "Entry Timestamp: Not Set" << endl;
    }

    if (filledBy) {
        cout << "Filled By: " << filledBy->getName() << " (ID: " << filledBy->getId() << ")" << endl;
    } else {
        cout << "Filled By: Not Assigned" << endl;
    }
}
