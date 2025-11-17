#include "DataManager.h"

int main() {
    DataManager dm;
    dm.loadPersons();
    dm.loadInstructors();
    dm.loadTAs();
    dm.loadAcademicOfficers();
    dm.loadAttendants();
    dm.loadHeadofDep();
    dm.loadBuildings(); // Load buildings first
    dm.loadRooms();
    dm.loadLabs(); // Link rooms to buildings
    dm.loadLabSections();
    // dm.printPersons();
    dm.loadRooms(); // <-- REMOVE THIS LINE!
    dm.printInstructors();
    dm.printTAs();
    dm.printAcademicOfficers();
    dm.printAttendants();
    dm.printHeadofDep();
    dm.printBuildings();
    dm.printRooms();
    dm.printLabs();
    dm.printLabSections();
    system("pause");
    return 0;
}