#include "makeupLabReq.h"

#include "LabSection.h"
#include "LabSession.h"
#include "instructor.h"

MakeupRequest::MakeupRequest(const string& id, Instructor* instructor, Day day, const string& startTime,
                             const string& endTime, const string& rsn, const string& stat, LabSection* section)
    : requestId(id), requestedBy(instructor), requestedDay(day), requestedStartTime(startTime),
      requestedEndTime(endTime), reason(rsn), status(stat), requestedSection(section), makeupSession(nullptr) {}

string MakeupRequest::getRequestId() const {
    return requestId;
}

Instructor* MakeupRequest::getRequestedBy() const {
    return requestedBy;
}

Day MakeupRequest::getRequestedDay() const {
    return requestedDay;
}

string MakeupRequest::getRequestedStartTime() const {
    return requestedStartTime;
}

string MakeupRequest::getRequestedEndTime() const {
    return requestedEndTime;
}

string MakeupRequest::getReason() const {
    return reason;
}

string MakeupRequest::getStatus() const {
    return status;
}

LabSection* MakeupRequest::getRequestedSection() const {
    return requestedSection;
}

LabSession* MakeupRequest::getMakeupSession() const {
    return makeupSession;
}

void MakeupRequest::setReason(const string& rsn) {
    reason = rsn;
}

void MakeupRequest::setStatus(const string& stat) {
    status = stat;
}

void MakeupRequest::setRequestedDay(Day day) {
    requestedDay = day;
}

void MakeupRequest::setRequestedStartTime(const string& startTime) {
    requestedStartTime = startTime;
}

void MakeupRequest::setRequestedEndTime(const string& endTime) {
    requestedEndTime = endTime;
}

void MakeupRequest::setRequestedSection(LabSection* section) {
    requestedSection = section;
}

void MakeupRequest::setMakeupSession(LabSession* session) {
    makeupSession = session;
}

void MakeupRequest::displayInfo() const {
    cout << "======= Makeup Request Information =======" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Request ID: " << requestId << endl;
    cout << "Status: " << status << endl;
    cout << "Reason: " << reason << endl;

    if (requestedBy) {
        cout << "Requested By (Instructor): " << requestedBy->getInstructorId() << " - " << requestedBy->getName()
             << endl;
    } else {
        cout << "Requested By: Not assigned" << endl;
    }

    string dayStr;
    switch (requestedDay) {
    case Day::Monday:
        dayStr = "Monday";
        break;
    case Day::Tuesday:
        dayStr = "Tuesday";
        break;
    case Day::Wednesday:
        dayStr = "Wednesday";
        break;
    case Day::Thursday:
        dayStr = "Thursday";
        break;
    case Day::Friday:
        dayStr = "Friday";
        break;
    case Day::Saturday:
        dayStr = "Saturday";
        break;
    case Day::Sunday:
        dayStr = "Sunday";
        break;
    }
    cout << "Requested Day: " << dayStr << endl;
    cout << "Requested Start Time: " << requestedStartTime << endl;
    cout << "Requested End Time: " << requestedEndTime << endl;

    if (requestedSection) {
        cout << "Requested Section: " << requestedSection->getSectionID() << " - " << requestedSection->getSectionName()
             << endl;
    } else {
        cout << "Requested Section: Not assigned" << endl;
    }

    if (makeupSession) {
        cout << "Makeup Session: " << makeupSession->getSessionID() << endl;
    } else {
        cout << "Makeup Session: Not created yet" << endl;
    }

    cout << "==========================================" << endl;
}
