#include "DataManager.h"

int main() {
    DataManager dm;
    dm.loadPersons();
    dm.loadInstructors();
    dm.printPersons();
    dm.printInstructors();
    return 0;
}