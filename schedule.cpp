#include "schedule.h"

Schedule::Schedule(const string& id, Day day, const string& startTime, const string& endTime)
    : scheduleId(id), dayOfWeek(day), expectedStartTime(startTime), expectedEndTime(endTime) {}

string Schedule::getScheduleId() const {
    return scheduleId;
}

Day Schedule::getDayOfWeek() const {
    return dayOfWeek;
}

string Schedule::getExpectedStartTime() const {
    return expectedStartTime;
}

string Schedule::getExpectedEndTime() const {
    return expectedEndTime;
}

void Schedule::setDayOfWeek(Day day) {
    dayOfWeek = day;
}

void Schedule::setExpectedStartTime(const string& startTime) {
    expectedStartTime = startTime;
}

void Schedule::setExpectedEndTime(const string& endTime) {
    expectedEndTime = endTime;
}

void Schedule::displayInfo() const {
    cout << "Schedule Information:" << endl;
    cout << "Schedule ID:" << scheduleId << endl;

    cout << "Day of Week: ";
    switch (dayOfWeek) {
    case Day::Monday:
        cout << "Monday";
        break;
    case Day::Tuesday:
        cout << "Tuesday";
        break;
    case Day::Wednesday:
        cout << "Wednesday";
        break;
    case Day::Thursday:
        cout << "Thursday";
        break;
    case Day::Friday:
        cout << "Friday";
        break;
    case Day::Saturday:
        cout << "Saturday";
        break;
    case Day::Sunday:
        cout << "Sunday";
        break;
    }
    cout << endl;

    cout << "Expected Time: " << expectedStartTime << " - " << expectedEndTime << endl;
}