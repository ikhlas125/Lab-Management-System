#include "CountManager.h"
#include "DataManager.h"
#include "LabManager.h"

int main() {
    DataManager dm;
    CountManager cm;
    LabManager lm(&dm, &cm);
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
    dm.printInstructors();
    dm.printTAs();
    dm.printAcademicOfficers();
    dm.printAttendants();
    dm.printHeadofDep();
    dm.printBuildings();
    dm.printRooms();
    dm.printLabs();
    dm.printLabSections();
    dm.printLabSchedules();
    dm.printLabSessions();
    cm.loadCounts();
    // cm.displayCounts();

    // cout << "\n=== BEFORE adding new section ===" << endl;
    // cout << "Total LabSections loaded: " << dm.getLabSections().size() << endl;

    // Lab* lab = dm.searchByLabId("L003");
    // Instructor* instr = dm.searchByInstructorId("I002");

    // cout << "Searching for Lab L003: " << (lab ? "FOUND" : "NOT FOUND") << endl;
    // cout << "Searching for Instructor I002: " << (instr ? "FOUND" : "NOT FOUND") << endl;

    // if (lab && instr) {
    //     lm.addLabSections("D", "Fall 2025", "2025-2026", lab, instr);
    // } else {
    //     cout << "Error: Lab or Instructor not found - cannot add section" << endl;
    // }

    // cout << "\n=== AFTER adding new section ===" << endl;
    // cout << "Total LabSections now: " << dm.getLabSections().size() << endl;

    dm.saveLabs();
    dm.saveLabSections();
    cm.saveCounts();
    system("pause");
    return 0;
}