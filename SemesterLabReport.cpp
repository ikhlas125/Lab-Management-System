#include "SemesterLabReport.h"

#include "LabSection.h"
#include "timesheet.h"
#include <string>


SemesterLabReport::SemesterLabReport(const string& id, HeadOfDep* by, const string& date, LabSection* section)
    : Report(id, by, date), SectionForReport(section), timesheets(), totalContactHours(0), totalLeaves(0) {}

LabSection* SemesterLabReport::getSectionForReport() const {
    return SectionForReport;
}

const vector<TimeSheet*>& SemesterLabReport::getTimeSheets() const {
    return timesheets;
}

int SemesterLabReport::getTotalContactHours() const {
    return totalContactHours;
}

int SemesterLabReport::getTotalLeaves() const {
    return totalLeaves;
}

void SemesterLabReport::setSectionForReport(LabSection* section) {
    SectionForReport = section;
}

void SemesterLabReport::setTotalContactHours(int hours) {
    totalContactHours = hours;
}

void SemesterLabReport::setTotalLeaves(int leaves) {
    totalLeaves = leaves;
}

void SemesterLabReport::setTimeSheets(const vector<TimeSheet*>& sheets) {
    timesheets = sheets;
}

void SemesterLabReport::calculateTotalContactHours() {
    totalContactHours = 0;
    for (int i = 0; i < timesheets.size(); i++) {
        if (timesheets[i]) {
            totalContactHours += stoi(timesheets[i]->getActualDuration());
        }
    }
}

void SemesterLabReport::calculateTotalLeaves() {
    totalLeaves = 0;
    for (int i = 0; i < timesheets.size(); i++) {
        if (timesheets[i] && timesheets[i]->getStatus() == "Missed") {
            totalLeaves++;
        }
    }
}

void SemesterLabReport::print() const {
    cout << "\n=== Semester Lab Report ===" << endl;
    cout << "Report ID: " << getReportId() << endl;
    cout << "Generated Date: " << getGeneratedDate() << endl;

    if (SectionForReport) {
        cout << "Section: " << SectionForReport->getSectionName() << " (ID: " << SectionForReport->getSectionID() << ")"
             << endl;
    } else {
        cout << "Section: Not Assigned" << endl;
    }

    cout << "Total TimeSheets: " << timesheets.size() << endl;
    cout << "Total Contact Hours: " << totalContactHours << endl;
    cout << "Total Leaves: " << totalLeaves << endl;
    cout << "\nTimeSheets in Semester:" << endl;
    cout << "================================" << endl;

    for (const auto& timesheet : timesheets) {
        if (timesheet) {
            timesheet->displayInfo();
            cout << "--------------------------------" << endl;
        }
    }
}
