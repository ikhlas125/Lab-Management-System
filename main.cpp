#include "DataManager.h"
void createAttendantsBinary() {
    AttendantR attendants[] = {{"ATT001", "P008", "B001"}};

    ofstream file("attendants.bin", ios::binary);
    int count = 1;
    file.write((char*)&count, sizeof(int));
    file.write((char*)attendants, sizeof(attendants));
    file.close();
    cout << "attendants.bin created" << endl;
}
int main() {
    DataManager dm;
    createAttendantsBinary();
    dm.loadPersons();
    dm.loadInstructors();
    dm.loadTAs();
    dm.loadAcademicOfficers();
    dm.loadAttendants();
    dm.printPersons();
    dm.printInstructors();
    dm.printTAs();
    dm.printAcademicOfficers();
    dm.printAttendants();
    return 0;
}