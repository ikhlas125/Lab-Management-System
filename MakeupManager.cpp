#include "MakeupManager.h"

#include "CountManager.h"
#include "DataManager.h"
#include "LabManager.h"
#include "ScheduleManager.h"
#include "instructor.h"
#include "makeupLabReq.h"
#include <string>
#include <sstream>
#include <iomanip>


MakeupManager::MakeupManager(DataManager* dm, ScheduleManager* sm, LabManager* lm, CountManager* cm)
    : Data(dm), ScheduleMgr(sm), LabMgr(lm), DataCount(cm) {}

void MakeupManager::submitMakeupRequest(Instructor* requestBy, Day day, const string& startTime, const string& endTime,
                                        string reason, LabSection* section) {
    int currentCount = DataCount->getMakeupRequestCount();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "MK" << setfill('0') << setw(3) << nextId;
    string newMakeupId = oss.str();
    MakeupRequest newMakeupRequest(newMakeupId, requestBy, day, startTime, endTime, reason, "Pending", section);
    Data->getMakeupRequests().push_back(newMakeupRequest);
    DataCount->incrementMakeupRequestCount();
    cout << "MakeupRequest added successfully with ID: " << newMakeupId << endl;
}

void MakeupManager::reviewMakeupRequest(const string& requestId, const string& roomId, const string& weeknum) {
    MakeupRequest* request = Data->searchByMakeupId(requestId);
    if (!request || request->getStatus() != "Pending") {
        return;
    }

    if (LabMgr->isClashless(request->getRequestedDay(), request->getRequestedStartTime(),
                            request->getRequestedEndTime(), Data->searchByRoomId(roomId))) {
        ScheduleMgr->createSchedule(request->getRequestedDay(), request->getRequestedStartTime(),
                                    request->getRequestedEndTime());
        Schedule* MakeupSchedule = &Data->getSchedules().back();
        LabMgr->createLabSession(weeknum, "Makeup", request->getRequestedSection(), MakeupSchedule,
                                 Data->searchByRoomId(roomId));
        LabSession* makeupSession = &Data->getLabSessions().back();
        request->setStatus("Approved");
        request->setMakeupSession(makeupSession);
    } else {
        rejectMakeupRequest(requestId);
    }
}

void MakeupManager::rejectMakeupRequest(const string& requestId) {
    MakeupRequest* request = Data->searchByMakeupId(requestId);
    if (!request || request->getStatus() != "Pending") {
        cout << "Error: Request not found or not in Pending status." << endl;
        return;
    }

    request->setStatus("Rejected");
    cout << "Makeup request " << requestId << " has been rejected." << endl;
}

vector<MakeupRequest>& MakeupManager::getMakeupRequests() {
    return Data->getMakeupRequests();
}
