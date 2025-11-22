#include "CountManager.h"
#include "DataManager.h"
#include "LabManager.h"
#include "MakeupManager.h"
#include "ReportManager.h"
#include "ScheduleManager.h"
#include "TimeSheetManager.h"

int main() {
    DataManager dm;
    CountManager cm;
    LabManager lm(&dm, &cm);
    ScheduleManager sm(&dm, &cm);
    TimeSheetManager tm(&dm, &cm);
    MakeupManager mm(&dm, &sm, &lm, &cm);
    ReportManager rm(&dm, &cm);
    dm.loadPersons();
    dm.loadInstructors();
    dm.loadTAs();
    dm.loadAcademicOfficers();
    dm.loadAttendants();
    dm.loadHeadofDep();
    dm.loadBuildings();
    dm.loadRooms();
    dm.loadLabs();
    dm.loadLabSections();
    dm.loadLabSchedules();
    dm.loadLabSessions();
    dm.loadMakeupRequests();
    dm.loadTimeSheets();
    rm.generateFullSectionReport(dm.searchByHeadOfDepId("HOD001"), "2025-11-23", dm.searchbyLabSectionId("LS002"),
                                 "Fall2024");
    cout << "-------------------------------------------------------------------" << endl;
    dm.printInstructors();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printTAs();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printAcademicOfficers();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printAttendants();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printHeadofDep();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printBuildings();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printRooms();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printLabs();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printLabSections();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printLabSchedules();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printLabSessions();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printMakeupRequests();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printTimeSheets();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printWeeklyScheduleReports();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printWeeklyTimeSheetReports();
    cout << "-------------------------------------------------------------------" << endl;
    dm.printSemesterLabReports();
    cm.loadCounts();
    cm.displayCounts();
    cout << "-------------------------------------------------------------------" << endl;
    dm.saveLabs();
    dm.saveLabSections();
    dm.saveSectionTAs();
    dm.saveSchedules();
    dm.saveLabSessions();
    dm.saveMakeupRequests();
    dm.saveTimeSheets();
    cm.saveCounts();
    system("pause");
    return 0;
}