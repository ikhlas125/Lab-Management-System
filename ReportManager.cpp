#include "ReportManager.h"

#include "CountManager.h"
#include "DataManager.h"
#include "WeeklyScheduleReport.h"
#include "WeeklyTimeSheetReport.h"
#include "headOfDep.h"
#include <iomanip>
#include <sstream>

ReportManager::ReportManager(DataManager* dm, CountManager* cm) : Data(dm), DataCount(cm) {}

void ReportManager::generateWeeklyLabScheduleReport(const string& week, HeadOfDep* genBy, const string& date) {
    int currentCount = Data->getWeeklyScheduleReports().size();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "WSR" << setfill('0') << setw(3) << nextId;
    string newReportId = oss.str();
    WeeklyScheduleReport newReport(newReportId, genBy, date, week);
    Data->getWeeklyScheduleReports().push_back(newReport);
    WeeklyScheduleReport* reportPtr = &Data->getWeeklyScheduleReports().back();
    vector<LabSession*> sessions = Data->getSessionsByWeekNumber(week);
    reportPtr->setSessions(sessions);
    cout << "WeeklyScheduleReport " << newReportId << " created successfully" << endl;
}

void ReportManager::generateWeeklyTimeSheetReport(const string& week, HeadOfDep* genBy, const string& date) {
    int currentCount = Data->getWeeklyTimeSheetReports().size();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "WTS" << setfill('0') << setw(3) << nextId;
    string newReportId = oss.str();
    WeeklyTimeSheetReport newReport(newReportId, genBy, date, week);
    Data->getWeeklyTimeSheetReports().push_back(newReport);
    WeeklyTimeSheetReport* reportPtr = &Data->getWeeklyTimeSheetReports().back();
    vector<TimeSheet*> timesheets = Data->getTimeSheetsByWeekNumber(week);
    reportPtr->setTimeSheets(timesheets);
    cout << "WeeklyTimeSheetReport " << newReportId << " created successfully" << endl;
}