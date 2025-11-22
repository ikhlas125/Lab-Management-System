#include "SemesterLabReport.h"

#include "LabSection.h"
#include "LabSession.h"

SemesterLabReport::SemesterLabReport(const string& id, HeadOfDep* by, const string& date, LabSection* section)
    : Report(id, by, date), SectionForReport(section), sessions(), totalContactHours(0), totalLeaves(0) {}

LabSection* SemesterLabReport::getSectionForReport() const {
    return SectionForReport;
}

const vector<LabSession*>& SemesterLabReport::getSessions() const {
    return sessions;
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

void SemesterLabReport::addSession(LabSession* session) {
    if (session) {
        sessions.push_back(session);
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

    cout << "Total Sessions: " << sessions.size() << endl;
    cout << "Total Contact Hours: " << totalContactHours << endl;
    cout << "Total Leaves: " << totalLeaves << endl;
    cout << "\nSessions in Semester:" << endl;
    cout << "================================" << endl;

    for (const auto& session : sessions) {
        if (session) {
            session->displayInfo();
            cout << "--------------------------------" << endl;
        }
    }
}
