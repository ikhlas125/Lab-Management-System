#include "DataManager.h"
void createRoomsBinary() {
    RoomR rooms[] = {
        {"R001", "CS-101", 30, "B001", 1}, {"R002", "CS-102", 25, "B001", 1}, {"R003", "CS-201", 35, "B001", 2}};

    ofstream file("rooms.bin", ios::binary);
    int count = 3;
    file.write((char*)&count, sizeof(int));
    file.write((char*)rooms, sizeof(rooms));
    file.close();
    cout << "rooms.bin created" << endl;
}
int main() {
    DataManager dm;
    createRoomsBinary();
    dm.loadPersons();
    dm.loadInstructors();
    dm.loadTAs();
    dm.loadAcademicOfficers();
    dm.loadAttendants();
    dm.loadHeadofDep();
    dm.loadBuildings(); // Load buildings first
    dm.loadRooms();     // Link rooms to buildings
    dm.printPersons();
    // dm.loadRooms();     // <-- REMOVE THIS LINE!
    dm.printInstructors();
    dm.printTAs();
    dm.printAcademicOfficers();
    dm.printAttendants();
    dm.printHeadofDep();
    dm.printBuildings();
    dm.printRooms();
    return 0;
}