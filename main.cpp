#include "DataManager.h"

int main() {
    DataManager dm;
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
    system("pause");
    return 0;
}