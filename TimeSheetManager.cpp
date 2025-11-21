#include "TimeSheetManager.h"

#include "CountManager.h"
#include "DataManager.h"
#include "attendant.h"
#include "timesheet.h"
#include <iomanip>
#include <sstream>

TimeSheetManager::TimeSheetManager(DataManager* dm, CountManager* cm) : Data(dm), DataCount(cm) {}

void TimeSheetManager::fillTimeSheet(const string& startTime, const string& endTime, Attendant* attendant,
                                     const string& duration, const string& timestamp, const string& stat,
                                     LabSession* sessio) {
    int currentCount = DataCount->getTimesheetCount();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "TS" << setfill('0') << setw(3) << nextId;
    string newTimeSheetId = oss.str();
    TimeSheet newTimeSheet(newTimeSheetId, startTime, endTime, attendant, duration, timestamp, stat, sessio);
    Data->getTimeSheets().push_back(newTimeSheet);

    TimeSheet* timesheetPtr = &Data->getTimeSheets().back();
    if (attendant) {
        attendant->addTimesheet(timesheetPtr);
    }
    if (sessio) {
        sessio->setTimeSheet(timesheetPtr);
    }

    DataCount->incrementTimesheetCount();
    cout << "TimeSheet " << newTimeSheetId << " created successfully" << endl;
}
