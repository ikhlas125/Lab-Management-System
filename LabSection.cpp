#include "LabSection.h"

#include "Instructor.h"
#include "Lab.h"
#include "LabSession.h"
#include "room.h"

LabSection::LabSection(const string& id, const string& name, const string& sem, const string& year)
    : sectionID(id), sectionName(name), semester(sem), academicYear(year), lab(nullptr), assignedInstructor(nullptr),
      assignedTas(), sessions() {}

string LabSection::getSectionID() const {
    return sectionID;
}

string LabSection::getSectionName() const {
    return sectionName;
}

string LabSection::getSemester() const {
    return semester;
}

string LabSection::getAcademicYear() const {
    return academicYear;
}

Lab* LabSection::getLab() const {
    return lab;
}

Instructor* LabSection::getAssignedInstructor() const {
    return assignedInstructor;
}

const vector<TA*>& LabSection::getAssignedTas() const {
    return assignedTas;
}

const vector<LabSession*>& LabSection::getSessions() const {
    return sessions;
}

void LabSection::setSectionName(const string& name) {
    sectionName = name;
}

void LabSection::setSemester(const string& sem) {
    semester = sem;
}

void LabSection::setAcademicYear(const string& year) {
    academicYear = year;
}

void LabSection::setLab(Lab* l) {
    lab = l;
}

void LabSection::setAssignedInstructor(Instructor* instr) {
    assignedInstructor = instr;
}

void LabSection::addTA(TA* ta) {
    if (ta) {
        assignedTas.push_back(ta);
    }
}

void LabSection::addSession(LabSession* session) {
    if (session) {
        sessions.push_back(session);
    }
}

void LabSection::displayInfo() const {
    cout << "Lab Section Information:" << endl;
    cout << "Section ID: " << sectionID << endl;
    cout << "Section Name: " << sectionName << endl;
    cout << "Semester: " << semester << endl;
    cout << "Academic Year: " << academicYear << endl;

    if (lab) {
        cout << "Lab: " << lab->getLabName() << endl;
    } else {
        cout << "Lab: None" << endl;
    }

    if (assignedInstructor) {
        cout << "Instructor: " << assignedInstructor->getName() << endl;
    } else {
        cout << "Instructor: None" << endl;
    }

    if (!assignedTas.empty()) {
        cout << "Teaching Assistants: ";
        for (size_t i = 0; i < assignedTas.size(); ++i) {
            if (assignedTas[i]) {
                cout << assignedTas[i]->getName();
                if (i < assignedTas.size() - 1)
                    cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "Teaching Assistants: None" << endl;
    }

    if (!sessions.empty()) {
        cout << "Sessions (" << sessions.size() << "):" << endl;
        for (const auto& session : sessions) {
            if (session) {
                cout << "  - Session ID: " << session->getSessionID() << ", Week: " << session->getWeekNumber()
                     << ", Status: " << session->getStatus();
                if (session->getAssignedRoom()) {
                    cout << ", Room: " << session->getAssignedRoom()->getRoomName();
                }
                cout << endl;
            }
        }
    } else {
        cout << "Sessions: None" << endl;
    }
}
