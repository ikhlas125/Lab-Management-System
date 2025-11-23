#include "LabSession.h"

#include "LabSection.h"
#include "room.h"
#include "schedule.h"
#include "timesheet.h"

LabSession::LabSession(const string& id, const string& weekNum, const string& stat)
    : sessionID(id), WeekNumber(weekNum), status(stat), section(nullptr), assignedRoom(nullptr), schedule(nullptr),
      timeSheet(nullptr) {}

string LabSession::getSessionID() const {
    return sessionID;
}

LabSection* LabSession::getSection() const {
    return section;
}

Room* LabSession::getAssignedRoom() const {
    return assignedRoom;
}

Schedule* LabSession::getSchedule() const {
    return schedule;
}

TimeSheet* LabSession::getTimeSheet() const {
    return timeSheet;
}

string LabSession::getWeekNumber() const {
    return WeekNumber;
}

string LabSession::getStatus() const {
    return status;
}

void LabSession::setSection(LabSection* sec) {
    section = sec;
}

void LabSession::setAssignedRoom(Room* room) {
    assignedRoom = room;
}

void LabSession::setSchedule(Schedule* sched) {
    schedule = sched;
}

void LabSession::setTimeSheet(TimeSheet* ts) {
    timeSheet = ts;
}

void LabSession::setWeekNumber(const string& weekNum) {
    WeekNumber = weekNum;
}

void LabSession::setStatus(const string& stat) {
    status = stat;
}

void LabSession::displayInfo() const {
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Lab Session Information:" << endl;
    cout << "Session ID: " << sessionID << endl;
    cout << "Week Number: " << WeekNumber << endl;
    cout << "Status: " << status << endl;

    if (section) {
        cout << "Section: " << section->getSectionName() << " (ID: " << section->getSectionID() << ")" << endl;
    } else {
        cout << "Section: Not Assigned" << endl;
    }

    if (assignedRoom) {
        cout << "Room: " << assignedRoom->getRoomName() << " (ID: " << assignedRoom->getRoomID() << ")" << endl;
    } else {
        cout << "Room: Not Assigned" << endl;
    }

    if (schedule) {
        cout << "Schedule ID: " << schedule->getScheduleId() << endl;
        cout << "  Day: ";
        switch (schedule->getDayOfWeek()) {
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
        cout << "  Time: " << schedule->getExpectedStartTime() << " - " << schedule->getExpectedEndTime() << endl;
    } else {
        cout << "Schedule: Not Assigned" << endl;
    }

    if (timeSheet) {
        cout << "TimeSheet: " << timeSheet->getTimesheetID() << " (Status: " << timeSheet->getStatus() << ")" << endl;
    } else {
        cout << "TimeSheet: Not Filled" << endl;
    }
}
