#include "AcademicOfficerMenu.h"

#include "DataManager.h"
#include "LabManager.h"
#include "MakeupManager.h"
#include "ScheduleManager.h"
#include <string>

AcademicOfficerMenu::AcademicOfficerMenu(LabManager* labMgr, ScheduleManager* schedMgr, DataManager* dataMgr,
                                         MakeupManager* makMgr)
    : labMgr(labMgr), schedMgr(schedMgr), dataMgr(dataMgr), makMgr(makMgr) {}

void AcademicOfficerMenu::show() {
    int choice = 0;
    do {
        cout << "\n===== Academic Officer Menu =====" << endl;
        cout << "1. Manage Labs" << endl;
        cout << "   1. Add Lab (SCC)" << endl;
        cout << "   2. View Labs" << endl;
        cout << "2. Manage Lab Sections" << endl;
        cout << "   1. Add Lab Section" << endl;
        cout << "   2. Assign TA(s) to Section" << endl;
        cout << "   3. View Sections of a Lab" << endl;
        cout << "   4. Create Lab Session" << endl;
        cout << "3. Manage Schedules (Expected Timings)" << endl;
        cout << "   1. Create Schedule (Day, Start, End)" << endl;
        cout << "   2. View All Schedules" << endl;
        cout << "5. Makeup Lab Requests" << endl;
        cout << "   1. View Makeup Requests from Instructors" << endl;
        cout << "   2. Schedule Makeup Lab Session (creates planned session)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int subChoice;
            cout << "\n  1. Add Lab (SCC)" << endl;
            cout << "  2. View Labs" << endl;
            cout << "  Enter your choice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                string name, code, sem;
                int cred;
                cout << "Enter Lab Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Lab Code: ";
                getline(cin, code);
                cout << "Enter Credits: ";
                cin >> cred;
                cin.ignore();
                cout << "Enter Semester: ";
                getline(cin, sem);
                labMgr->addLabs(name, code, cred, sem);
                cout << "Lab Name: " << name << ", Code: " << code << ", Credits: " << cred << ", Semester: " << sem
                     << endl;
            } else if (subChoice == 2) {
                vector<Lab> Labs = labMgr->getLabs();
                for (const auto& l : Labs) {
                    l.displayInfo();
                }
            } else {
                cout << "Invalid sub-option." << endl;
            }
        } else if (choice == 2) {
            int subChoice;
            cout << "\n  1. Add Lab Section" << endl;
            cout << "  2. Assign TA(s) to Section" << endl;
            cout << "  3. View Sections of a Lab" << endl;
            cout << "  4. Create Lab Session" << endl;
            cout << "  Enter your choice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                string name, sem, year, labId, instructorId;
                cout << "Enter Section Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Academic Year: ";
                getline(cin, year);
                cout << "Enter Lab ID: ";
                getline(cin, labId);
                cout << "Enter Instructor ID: ";
                getline(cin, instructorId);
                cout << "[Add Lab Section selected]" << endl;
                Lab* toBeAssigned = dataMgr->searchByLabId(labId);
                Instructor* InsAss = dataMgr->searchByInstructorId(instructorId);
                if (toBeAssigned && InsAss) {
                    labMgr->addLabSections(name, year, toBeAssigned, InsAss);
                } else {
                    cout << "Instructor or Lab does not exist" << endl;
                }
                cout << "Section Name: " << name << ", Year: " << year << ", Lab ID: " << labId
                     << ", Instructor ID: " << instructorId << endl;
            } else if (subChoice == 2) {
                string taId, sectionId;
                cout << "Enter TA ID: ";
                cin.ignore();
                getline(cin, taId);
                cout << "Enter Section ID: ";
                getline(cin, sectionId);
                TA* tobeAss = dataMgr->searchByTAId(taId);
                LabSection* ass = dataMgr->searchbyLabSectionId(sectionId);
                if (tobeAss && ass) {
                    labMgr->assignTAs(tobeAss, ass);
                } else {
                    cout << "TA or Section does not exits" << endl;
                }
                cout << "[Assign TA(s) to Section selected]" << endl;
                cout << "TA ID: " << taId << ", Section ID: " << sectionId << endl;
            } else if (subChoice == 3) {
                vector<LabSection> LabSections = labMgr->getLabSections();
                for (const auto& l : LabSections) {
                    l.displayInfo();
                }
                cout << "[View Sections of a Lab selected]" << endl;
            } else if (subChoice == 4) {
                string week, status, sectionId, scheduleId, roomId;
                cout << "Enter Week Number: ";
                cin.ignore();
                getline(cin, week);
                cout << "Enter Status: ";
                getline(cin, status);
                cout << "Enter Section ID: ";
                getline(cin, sectionId);
                cout << "Enter Schedule ID: ";
                getline(cin, scheduleId);
                cout << "Enter Room ID: ";
                getline(cin, roomId);
                LabSection* section = dataMgr->searchbyLabSectionId(sectionId);
                Schedule* schedule = dataMgr->searchByScheduleId(scheduleId);
                Room* room = dataMgr->searchByRoomId(roomId);
                if (section && room && schedule) {
                    labMgr->createLabSession(week, status, section, schedule, room);
                } else {
                    cout << "Section, Schedule or Room does not exist." << endl;
                }
                cout << "[Create Lab Session selected]" << endl;
                cout << "Week: " << week << ", Status: " << status << ", Section ID: " << sectionId
                     << ", Schedule ID: " << scheduleId << ", Room ID: " << roomId << endl;
            } else {
                cout << "Invalid sub-option." << endl;
            }
        } else if (choice == 3) {
            int subChoice;
            cout << "\n  1. Create Schedule (Day, Start, End)" << endl;
            cout << "  2. View All Schedules" << endl;
            cout << "  Enter your choice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                string ay, startTime, endTime;
                cout << "Enter Day (e.g., Monday): ";
                cin.ignore();
                getline(cin, ay);
                Day day = Day::Monday;
                string dayStr = ay;
                if (dayStr == "Monday")
                    day = Day::Monday;
                else if (dayStr == "Tuesday")
                    day = Day::Tuesday;
                else if (dayStr == "Wednesday")
                    day = Day::Wednesday;
                else if (dayStr == "Thursday")
                    day = Day::Thursday;
                else if (dayStr == "Friday")
                    day = Day::Friday;
                else if (dayStr == "Saturday")
                    day = Day::Saturday;
                else if (dayStr == "Sunday")
                    day = Day::Sunday;
                inputStartEndTime(startTime, endTime);
                schedMgr->createSchedule(day, startTime, endTime);
                cout << "[Create Schedule selected]" << endl;
                cout << "Day: " << dayToString(day) << ", Start: " << startTime << ", End: " << endTime << endl;
            } else if (subChoice == 2) {
                vector<Schedule> schedules = schedMgr->getSchedules();
                for (const auto& s : schedules) {
                    s.displayInfo();
                }
                cout << "[View All Schedules selected]" << endl;
            } else {
                cout << "Invalid sub-option." << endl;
            }
        } else if (choice == 5) {
            int subChoice;
            cout << "\n  1. View Makeup Requests from Instructors" << endl;
            cout << "  2. Review Makeup Requests" << endl;
            cout << "  Enter your choice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                vector<MakeupRequest> makeups = makMgr->getMakeupRequests();
                for (const auto& m : makeups) {
                    m.displayInfo();
                }
                cout << "[View Makeup Requests from Instructors selected]" << endl;
            } else if (subChoice == 2) {
                vector<MakeupRequest> makeups = makMgr->getMakeupRequests();
                bool found = false;
                for (const auto& m : makeups) {
                    if (m.getStatus() == "Pending") {
                        m.displayInfo();
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No pending makeup requests found." << endl;
                } else {
                    string requestId;
                    cout << "Enter Request Id: ";
                    cin.ignore();
                    getline(cin, requestId);
                    MakeupRequest* request = dataMgr->searchByMakeupId(requestId);
                    if (request) {
                        string roomId, week;
                        cout << "Enter Room Id: ";
                        cin.ignore();
                        getline(cin, roomId);
                        cout << "Enter WeekNumber: ";
                        getline(cin, week);
                        makMgr->reviewMakeupRequest(request->getRequestId(), roomId, week);
                    } else {
                        cout << "Request does not exist" << endl;
                    }
                }
                cout << "[Review Makeup Requests selected]" << endl;
            } else {
                cout << "Invalid sub-option." << endl;
            }
        } else if (choice == 6) {
            cout << "Exiting Academic Officer Menu..." << endl;
            break;
        } else {
            cout << "Invalid option. Please select another option." << endl;
        }
    } while (true);
}