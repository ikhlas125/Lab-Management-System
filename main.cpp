#include "DataManager.h"

int main() {
    DataManager dm;
    dm.loadPersons();
    dm.loadInstructors();
    dm.loadTAs();
    dm.loadAcademicOfficers();
    dm.printPersons();
    dm.printInstructors();
    dm.printTAs();
    dm.printAcademicOfficers();
    return 0;
}