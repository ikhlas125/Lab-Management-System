#include "InstructorMenu.h"

#include "DataManager.h"
#include "LabManager.h"
#include "MakeupManager.h"
#include <string>

InstructureMenu::InstructureMenu(LabManager* labMgr, DataManager* datMgr, MakeupManager* mkMgr)
    : labMgr(labMgr), datMgr(datMgr), mkMgr(mkMgr) {}

void InstructureMenu::show() {
    string instructorId;
    cout << "Enter your Instructor ID: ";
    cin >> instructorId;
    Instructor* loggedInInstructor = datMgr->searchByInstructorId(instructorId);
    if (!loggedInInstructor) {
        cout << "Instructor not found. Exiting menu." << endl;
        return;
    }
    cout << "Welcome, " << loggedInInstructor->getName() << "!" << endl;

    int choice = 0;
    do {
        cout << "\n===== Instructor Menu =====" << endl;
        cout << "1. View My Sections" << endl;
        cout << "2. Makeup Lab Request" << endl;
        cout << "   1. Request Makeup Lab (choose section & week)" << endl;
        cout << "   2. View Makeup Lab Status" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            vector<LabSection*> sections = loggedInInstructor->getAssignedSections();
            if (!sections.empty()) {
                for (const auto& s : sections) {
                    s->displayInfo();
                }
            } else {
                cout << "No Sections assigned to you." << endl;
            }
            cout << "[View Weekly Schedule selected]" << endl;
        } else if (choice == 2) {
            int subChoice;
            cout << "\n  1. Request Makeup Lab (choose section & week)" << endl;
            cout << "  2. View Makeup Lab Status" << endl;
            cout << "  Enter your choice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                string sectionId, reason, startTime, endTime;
                cout << "Enter Section ID: ";
                cin >> sectionId;
                string dayInput;
                cout << "Enter requested day (e.g., Monday): ";
                cin >> dayInput;
                Day day = Day::Monday;
                string dayStr = dayInput;
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
                cout << "Enter reason for makeup lab: ";
                cin.ignore();
                getline(cin, reason);
                LabSection* section = datMgr->searchbyLabSectionId(sectionId);
                bool isAssigned = false;
                if (section) {
                    vector<LabSection*> assignedSections = loggedInInstructor->getAssignedSections();
                    for (auto* s : assignedSections) {
                        if (s && s->getSectionID() == sectionId) {
                            isAssigned = true;
                            break;
                        }
                    }
                    if (isAssigned) {
                        mkMgr->submitMakeupRequest(loggedInInstructor, day, startTime, endTime, reason, section);
                    } else {
                        cout << "Section does not belong to you." << endl;
                    }
                } else {
                    cout << "Section does not exist." << endl;
                }
                // Print input summary
                cout << "\n[Input Summary]" << endl;
                cout << "Section ID: " << sectionId << endl;
                cout << "Requested Day: " << dayToString(day) << endl;
                cout << "Start Time: " << startTime << endl;
                cout << "End Time: " << endTime << endl;
                cout << "Reason: " << reason << endl;
                cout << "[Request Makeup Lab selected]" << endl;
            } else if (subChoice == 2) {
                vector<MakeupRequest> reqs = datMgr->getMakeupRequests();
                for (const auto& m : reqs) {
                    if (m.getRequestedBy()->getInstructorId() == loggedInInstructor->getInstructorId()) {
                        m.displayInfo();
                    }
                }
                cout << "[View Makeup Lab Status selected]" << endl;
            } else {
                cout << "Invalid sub-option." << endl;
            }
        } else if (choice == 3) {
            cout << "Exiting Instructor Menu..." << endl;
            break;
        } else {
            cout << "Invalid option. Please select another option." << endl;
        }
    } while (true);
}
