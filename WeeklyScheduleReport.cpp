#include "WeeklyScheduleReport.h"

#include "LabSession.h"

WeeklyScheduleReport::WeeklyScheduleReport(const string& id, HeadOfDep* by, const string& date, const string& weekNum)
    : Report(id, by, date), weekNumber(weekNum), sessionsInWeek() {}

string WeeklyScheduleReport::getWeekNumber() const {
    return weekNumber;
}

const vector<LabSession*>& WeeklyScheduleReport::getSessionsInWeek() const {
    return sessionsInWeek;
}

void WeeklyScheduleReport::setWeekNumber(const string& weekNum) {
    weekNumber = weekNum;
}

void WeeklyScheduleReport::setSessions(const vector<LabSession*>& sessions) {
    sessionsInWeek = sessions;
}

void WeeklyScheduleReport::print() const {
    cout << "\n=== Weekly Schedule Report ===" << endl;
    cout << "Report ID: " << getReportId() << endl;
    cout << "Generated Date: " << getGeneratedDate() << endl;
    cout << "Week Number: " << weekNumber << endl;
    cout << "Total Sessions: " << sessionsInWeek.size() << endl;
    cout << "\nSessions for Week " << weekNumber << ":" << endl;
    cout << "================================" << endl;

    for (const auto& session : sessionsInWeek) {
        if (session) {
            session->displayInfo();
            cout << "--------------------------------" << endl;
        }
    }
}
