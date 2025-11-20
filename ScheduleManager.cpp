#include "ScheduleManager.h"

#include "CountManager.h"
#include "DataManager.h"
#include "schedule.h"
#include <iomanip>
#include <sstream>

ScheduleManager::ScheduleManager(DataManager* dm, CountManager* cm) : Data(dm), DataCount(cm) {}

void ScheduleManager::createSchedule(Day day, const string& startTime, const string& endTime) {
    int currentCount = DataCount->getScheduleCount();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "SCH" << setfill('0') << setw(3) << nextId;
    string newScheduleId = oss.str();
    Schedule newLabSchedule(newScheduleId, day, startTime, endTime);
    Data->getSchedules().push_back(newLabSchedule);
    DataCount->incrementScheduleCount();
    cout << "Schedule " << newScheduleId << " created successfully" << endl;
}
