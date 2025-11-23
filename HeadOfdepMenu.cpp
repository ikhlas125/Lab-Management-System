#include "HeadOfdepMenu.h"

#include "DataManager.h"
#include "ReportManager.h"
#include <string>
using namespace std;

HeadOfDepMenu::HeadOfDepMenu(ReportManager* reMgr, DataManager* datMgr) : reMgr(reMgr), datMgr(datMgr) {}

void HeadOfDepMenu::show() {
    string hodId;
    cout << "Enter your Head of Department ID: ";
    cin >> hodId;
    HeadOfDep* loggedInHead = datMgr->searchByHeadOfDepId(hodId);
    if (!loggedInHead) {
        cout << "Head not found. Exiting menu." << endl;
        return;
    }
    cout << "Welcome, " << loggedInHead->getName() << "!" << endl;
    int choice = 0;
    do {
        cout << "\n===== Head of Department Menu =====" << endl;
        cout << "1. Generate Reports" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int subChoice = 0;
            cout << "\n  1. Weekly Lab Schedule (Full University)" << endl;
            cout << "  2. Weekly TimeSheet Report (All Sections)" << endl;
            cout << "  3. Full Semester Report of a Section" << endl;
            cout << "  Enter your choice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                string week, date;
                cout << "Enter week (e.g., Week 1): ";
                cin.ignore();
                getline(cin, week);
                cout << "Enter date (e.g., 2025-11-24): ";
                getline(cin, date);
                reMgr->generateWeeklyLabScheduleReport(week, loggedInHead, date);
                cout << "[Input Summary]" << endl;
                cout << "Week: " << week << endl;
                cout << "Date: " << date << endl;
            } else if (subChoice == 2) {
                string week, date;
                cout << "Enter week (e.g., Week 1): ";
                cin.ignore();
                getline(cin, week);
                cout << "Enter date (e.g., 2025-11-24): ";
                getline(cin, date);
                reMgr->generateWeeklyTimeSheetReport(week, loggedInHead, date);
                cout << "[Input Summary]" << endl;
                cout << "Week: " << week << endl;
                cout << "Date: " << date << endl;
            } else if (subChoice == 3) {
                string sectionId, date, sem;
                cout << "Enter Section ID: ";
                cin >> sectionId;
                cin.ignore();
                cout << "Enter semester (e.g., Fall 2025 space problem): ";
                getline(cin, sem);
                cout << "Enter date (e.g., 2025-11-24): ";
                getline(cin, date);
                LabSection* section = datMgr->searchbyLabSectionId(sectionId);
                if (section && section->getSemester() == sem) {
                    reMgr->generateFullSectionReport(loggedInHead, date, section, sem);
                } else {
                    cout << "Section Does not Exist" << endl;
                }
                cout << "[Input Summary]" << endl;
                cout << "Section ID: " << sectionId << endl;
                cout << "Semester: " << sem << endl;
                cout << "Date: " << date << endl;
            } else {
                cout << "Invalid sub-option." << endl;
            }
        } else if (choice == 2) {
            cout << "Exiting Head of Department Menu..." << endl;
            break;
        } else {
            cout << "Invalid option. Please select another option." << endl;
        }
    } while (true);
}
