#include "WeeklyTimeSheetReport.h"

#include "timesheet.h"

WeeklyTimeSheetReport::WeeklyTimeSheetReport(const string& id, HeadOfDep* by, const string& date, const string& weekNum)
    : Report(id, by, date), weekNumber(weekNum), timeSheetsInWeek() {}

string WeeklyTimeSheetReport::getWeekNumber() const {
    return weekNumber;
}

const vector<TimeSheet*>& WeeklyTimeSheetReport::getTimeSheetsInWeek() const {
    return timeSheetsInWeek;
}

void WeeklyTimeSheetReport::setWeekNumber(const string& weekNum) {
    weekNumber = weekNum;
}

void WeeklyTimeSheetReport::setTimeSheets(const vector<TimeSheet*>& timesheets) {
    timeSheetsInWeek = timesheets;
}

void WeeklyTimeSheetReport::print() const {
    cout << "\n=== Weekly TimeSheet Report ===" << endl;
    cout << "Report ID: " << getReportId() << endl;
    cout << "Generated Date: " << getGeneratedDate() << endl;
    cout << "Week Number: " << weekNumber << endl;
    cout << "Total TimeSheets: " << timeSheetsInWeek.size() << endl;
    cout << "\nTimeSheets for Week " << weekNumber << ":" << endl;
    cout << "================================" << endl;

    for (const auto& timesheet : timeSheetsInWeek) {
        if (timesheet) {
            timesheet->displayInfo();
            cout << "--------------------------------" << endl;
        }
    }
}
