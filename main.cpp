#include "CountManager.h"
#include "DataManager.h"
#include "LabManager.h"
#include "ScheduleManager.h"

int main() {
    DataManager dm;
    CountManager cm;
    LabManager lm(&dm, &cm);
    ScheduleManager sm(&dm, &cm);
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
    cm.displayCounts();
    dm.saveLabs();
    dm.saveLabSections();
    dm.saveSectionTAs();
    dm.saveSchedules();
    dm.saveLabSessions();
    cm.saveCounts();
    system("pause");
    return 0;
}