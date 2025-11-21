#include "attendant.h"

#include "timesheet.h"

Attendant::Attendant(const string& id, const string& name, const string& email, const string& phone, const string& aid)
    : Person(id, name, email, phone), assignedBuilding(nullptr), AttendantId(aid), filledTimesheets() {}

string Attendant::getAttendantId() const {
    return AttendantId;
}

Building* Attendant::getAssignedBuilding() const {
    return assignedBuilding;
}

const vector<TimeSheet*>& Attendant::getFilledTimesheets() const {
    return filledTimesheets;
}

void Attendant::setAttendantId(const string& aid) {
    AttendantId = aid;
}

void Attendant::setAssignedBuilding(Building* building) {
    assignedBuilding = building;
}

void Attendant::addTimesheet(TimeSheet* timesheet) {
    if (timesheet) {
        filledTimesheets.push_back(timesheet);
    }
}

void Attendant::displayInfo() const {
    cout << "Attendant Information:" << endl;
    cout << "Attendant Id: " << AttendantId << endl;
    Person::displayInfo();
    if (assignedBuilding) {
        cout << "Assigned Building: " << assignedBuilding->getBuildingName() << " ("
             << assignedBuilding->getBuildingID() << ")" << endl;
    } else {
        cout << "Assigned Building: None" << endl;
    }

    if (!filledTimesheets.empty()) {
        cout << "Filled Timesheets (" << filledTimesheets.size() << "): ";
        for (size_t i = 0; i < filledTimesheets.size(); i++) {
            if (filledTimesheets[i]) {
                cout << filledTimesheets[i]->getTimesheetID();
                if (i < filledTimesheets.size() - 1) {
                    cout << ", ";
                }
            }
        }
        cout << endl;
    } else {
        cout << "Filled Timesheets: None" << endl;
    }
}
