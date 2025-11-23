#include "AttendantMenu.h"

#include "DataManager.h"
#include "LabManager.h"
#include "TimeSheetManager.h"

AttendantMenu::AttendantMenu(TimeSheetManager* tsMgr, LabManager* labMgr, DataManager* datMgr)
    : tsMgr(tsMgr), labMgr(labMgr), datMgr(datMgr) {}

void AttendantMenu::show() {
    string attendantId;
    cout << "Enter your Attendant ID: ";
    cin >> attendantId;
    Attendant* loggedInAttendant = datMgr->searchByIDAttendant(attendantId);
    if (!loggedInAttendant) {
        cout << "Attendant not found. Exiting menu." << endl;
        return;
    }
    cout << "Welcome, " << loggedInAttendant->getName() << "!" << endl;

    int choice = 0;
    do {
        cout << "\n===== Attendant Menu =====" << endl;
        cout << "1. View Assigned Building Details" << endl;
        cout << "   1. View Rooms" << endl;
        cout << "2. Fill TimeSheet" << endl;
        cout << "   1. Select Session" << endl;
        cout << "3. View Filled Sessions (History)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int subChoice;
            cout << "\n  1. View Rooms" << endl;
            cout << "  Enter your choice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                loggedInAttendant->getAssignedBuilding()->displayInfo();
                cout << "[View Rooms selected]" << endl;
            } else {
                cout << "Invalid sub-option." << endl;
            }
        } else if (choice == 2) {
            int subChoice;
            cout << "\n  1. Select Session" << endl;
            cout << "  Enter your choice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                vector<Room*> rooms = loggedInAttendant->getAssignedBuilding()->getAssignedRooms();
                vector<LabSession> sessions = datMgr->getLabSessions();
                bool found = false;
                for (const auto& s : sessions) {
                    Room* assignedRoom = s.getAssignedRoom();
                    if (!assignedRoom)
                        continue;
                    for (const auto& r : rooms) {
                        if (assignedRoom == r && s.getTimeSheet() == nullptr) {
                            s.displayInfo();
                            found = true;
                        }
                    }
                }
                if (!found) {
                    cout << "No sessions found in your assigned building." << endl;
                } else {
                    string sessionId, startTime, endTime, duration, status, timestamp;
                    cout << "Enter Session ID to fill timesheet: ";
                    cin.ignore();
                    getline(cin, sessionId);
                    inputStartEndTime(startTime, endTime);
                    cin.ignore();
                    cout << "Enter Actual Duration: ";
                    getline(cin, duration);
                    cout << "Enter Status: ";
                    getline(cin, status);
                    cout << "Enter Timestamp: ";
                    getline(cin, timestamp);
                    LabSession* session = datMgr->searchByLabSessionId(sessionId);
                    if (session && loggedInAttendant) {
                        tsMgr->fillTimeSheet(startTime, endTime, loggedInAttendant, duration, timestamp, status,
                                             session);
                    } else {
                        cout << "Session or Attendent does not exist." << endl;
                    }
                    cout << "Session ID: " << sessionId << endl;
                    cout << "Actual Start Time: " << startTime << endl;
                    cout << "Actual End Time: " << endTime << endl;
                    cout << "Actual Duration: " << duration << endl;
                    cout << "Status: " << status << endl;
                    cout << "Timestamp: " << timestamp << endl;
                    // TODO: Call timesheet manager to fill timesheet for this session and attendant
                }
                cout << "[Fill TimeSheet - Select Session selected]" << endl;
            } else {
                cout << "Invalid sub-option." << endl;
            }
        } else if (choice == 3) {
            vector<TimeSheet> timesheets = datMgr->getTimeSheets();
            bool foundTS = false;
            for (const auto& ts : timesheets) {
                if (ts.getFilledBy() == loggedInAttendant) {
                    ts.displayInfo();
                    foundTS = true;
                }
            }
            if (!foundTS) {
                cout << "No timesheets filled by you yet." << endl;
            }
            cout << "[View Filled Sessions (History) selected]" << endl;
        } else if (choice == 4) {
            cout << "Exiting Attendant Menu..." << endl;
            break;
        } else {
            cout << "Invalid option. Please select another option." << endl;
        }
    } while (true);
}