#include "LabManager.h"

#include "CountManager.h"
#include "DataManager.h"
#include "Lab.h"
#include "LabSection.h"
#include "LabSession.h"
#include "instructor.h"
#include "ta.h"
#include <iomanip>
#include <sstream>

LabManager::LabManager(DataManager* dm, CountManager* dc) : Data(dm), DataCount(dc) {}

void LabManager::addLabs(const string& name, const string& code, int cred, const string& sem) {
    int currentCount = DataCount->getLabCount();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "L" << setfill('0') << setw(3) << nextId;
    string newLabId = oss.str();
    Lab newLab(newLabId, name, code, cred, sem);
    Data->getLabs().push_back(newLab);
    DataCount->incrementLabCount();
    cout << "Lab added successfully with ID: " << newLabId << endl;
}

void LabManager::addLabSections(const string& name, const string& year, Lab* lab, Instructor* assignInstructor) {
    int currentCount = DataCount->getLabSectionCount();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "LS" << setfill('0') << setw(3) << nextId;
    string newLabId = oss.str();
    LabSection newLabSection(newLabId, name, lab->getSemester(), year);
    newLabSection.setLab(lab);
    newLabSection.setAssignedInstructor(assignInstructor);
    Data->getLabSections().push_back(newLabSection);
    LabSection* sectionPtr = &Data->getLabSections().back();
    assignInstructor->addAssignedSection(sectionPtr);
    DataCount->incrementLabSectionCount();
    cout << "Lab Section added successfully with ID: " << newLabId << endl;
}

void LabManager::assignTAs(TA* TaAssigned, LabSection* assignTo) {
    assignTo->addTA(TaAssigned);
    TaAssigned->addAssignedSection(assignTo);
    cout << "TA assigned Successfully" << endl;
}

void LabManager::createLabSession(const string& weekNum, const string& status, LabSection* section, Schedule* schedule,
                                  Room* room) {
    int currentCount = DataCount->getLabSessionCount();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "SESS" << setfill('0') << setw(3) << nextId;
    string newSessionId = oss.str();
    if (isClashless(schedule->getDayOfWeek(), schedule->getExpectedStartTime(), schedule->getExpectedEndTime(), room)) {
        LabSession newSession(newSessionId, weekNum, status);
        newSession.setSection(section);
        newSession.setSchedule(schedule);
        newSession.setAssignedRoom(room);
        Data->getLabSessions().push_back(newSession);
        LabSession* sessionPtr = &Data->getLabSessions().back();
        section->addSession(sessionPtr);
        DataCount->incrementLabSessionCount();
        cout << "Lab Session " << newSessionId << " created and attached to section " << section->getSectionID()
             << endl;
    } else {
        cout << "Schedule Selected has clash. Session cannot be created." << endl;
    }
}

bool LabManager::isClashless(Day day, const string& startTime, const string& endTime, Room* room) {
    for (const auto& session : Data->getLabSessions()) {
        Room* assignedRoom = session.getAssignedRoom();
        Schedule* sched = session.getSchedule();
        if (assignedRoom && sched && assignedRoom == room && sched->getDayOfWeek() == day) {
            if (!(endTime <= sched->getExpectedStartTime() || startTime >= sched->getExpectedEndTime())) {
                return false;
            }
        }
    }
    return true;
}

vector<Lab>& LabManager::getLabs() {
    return Data->getLabs();
}

vector<LabSection>& LabManager::getLabSections() {
    return Data->getLabSections();
}