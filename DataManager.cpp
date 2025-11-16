#include "DataManager.h"

void DataManager::loadPersons() {
    Persons.clear();

    ifstream file("persons.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open persons.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid persons.bin format" << endl;
        return;
    }

    PersonRecord* temp = new PersonRecord[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(PersonRecord) * count);
    if (!file) {
        cout << "Error: Could not read all person records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Persons.push_back(
            Person(string(temp[i].id), string(temp[i].name), string(temp[i].email), string(temp[i].phone)));
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << Persons.size() << " persons." << endl;
}

void DataManager::loadInstructors() {
    Instructors.clear();

    ifstream file("instructors.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open instructors.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid instructors.bin format" << endl;
        return;
    }

    InstructorRecord* temp = new InstructorRecord[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(InstructorRecord) * count);
    if (!file) {
        cout << "Error: Could not read all instructor records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Person* tempo = searchByID(temp[i].personId);
        Instructors.push_back(
            Instructor(tempo->getId(), tempo->getName(), tempo->getEmail(), tempo->getPhone(), temp[i].instructorId));
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << Instructors.size() << " instructors." << endl;
}

void DataManager::loadTAs() {
    TeachingAssistants.clear();

    ifstream file("teaching_assistants.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open teaching_assistants.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid teaching_assistants.bin format" << endl;
        return;
    }

    TeachingAssistant* temp = new TeachingAssistant[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(TeachingAssistant) * count);
    if (!file) {
        cout << "Error: Could not read all TeachingAssistant records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Person* tempo = searchByID(temp[i].personId);
        TeachingAssistants.push_back(
            TA(tempo->getId(), tempo->getName(), tempo->getEmail(), tempo->getPhone(), temp[i].taId));
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << Instructors.size() << " TA." << endl;
}

void DataManager::loadAcademicOfficers() {
    AcademicOfficers.clear();

    ifstream file("academic_officers.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open academic_officers.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid academic_officers.bin format" << endl;
        return;
    }

    AcademicOfficerR* temp = new AcademicOfficerR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(AcademicOfficerR) * count);
    if (!file) {
        cout << "Error: Could not read all Academic Officer records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Person* tempo = searchByID(temp[i].personId);
        AcademicOfficers.push_back(
            AcademicOfficer(tempo->getId(), tempo->getName(), tempo->getEmail(), tempo->getPhone(), temp[i].officerId));
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << AcademicOfficers.size() << " Academic Officer." << endl;
}

void DataManager::loadAttendants() {
    Attendants.clear();

    ifstream file("attendants.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open attendants.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid attendants.bin format" << endl;
        return;
    }

    AttendantR* temp = new AttendantR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(AttendantR) * count);
    if (!file) {
        cout << "Error: Could not read all Attendant records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Person* tempo = searchByID(temp[i].personId);
        Attendants.push_back(
            Attendant(tempo->getId(), tempo->getName(), tempo->getEmail(), tempo->getPhone(), temp[i].attendantId));
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << Attendants.size() << " Attendants." << endl;
}

void DataManager::loadHeadofDep() {
    HeadOfDeps.clear();

    ifstream file("head_of_department.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open head_of_department.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid head_of_department.bin format" << endl;
        return;
    }

    HeadOfDepartmentR* temp = new HeadOfDepartmentR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(HeadOfDepartmentR) * count);
    if (!file) {
        cout << "Error: Could not read all HeadofDeps records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Person* tempo = searchByID(temp[i].personId);
        HeadOfDeps.push_back(
            HeadOfDep(tempo->getId(), tempo->getName(), tempo->getEmail(), tempo->getPhone(), temp[i].hodId));
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << HeadOfDeps.size() << " HeadofDeps." << endl;
}

void DataManager::loadBuildings() {
    Buildings.clear();

    ifstream file("buildings.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open buildings.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid buildings.bin format" << endl;
        return;
    }

    BuildingR* temp = new BuildingR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(BuildingR) * count);
    if (!file) {
        cout << "Error: Could not read all HeadofDeps records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Attendant* AttendantB = searchByIDAttendant(temp[i].attendantPersonId);
        Buildings.push_back(Building(temp[i].buildingId, temp[i].buildingName, temp[i].address));
        Building* buildingPtr = &Buildings.back();
        buildingPtr->setAssignedAttendant(AttendantB);
        if (AttendantB) {
            AttendantB->setAssignedBuilding(buildingPtr);
        }
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << Buildings.size() << " Buildings." << endl;
}

void DataManager::loadRooms() {
    Rooms.clear();

    ifstream file("rooms.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open rooms.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid rooms.bin format" << endl;
        return;
    }

    RoomR* temp = new RoomR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(RoomR) * count);
    if (!file) {
        cout << "Error: Could not read all HeadofDeps records" << endl;
        delete[] temp;
        return;
    }

    Rooms.reserve(count); // Prevent reallocation invalidating pointers

    for (int i = 0; i < count; ++i) {
        Rooms.push_back(Room(temp[i].roomId, temp[i].roomNumber, temp[i].capacity, temp[i].floor));
        Room* roomPtr = &Rooms.back();
        Building* building = searchByBuildingID(temp[i].buildingId);
        roomPtr->setBuilding(building);
        if (building) {
            building->addRoom(roomPtr);
        }
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << Rooms.size() << " Rooms." << endl;
}

Building* DataManager::searchByBuildingID(const string& Id) {
    for (int i = 0; i < Buildings.size(); i++) {
        if (Id == Buildings[i].getBuildingID()) {
            return &Buildings[i];
        }
    }
    return nullptr;
}

Person* DataManager::searchByID(const string& Id) {
    for (int i = 0; i < Persons.size(); i++) {
        if (Id == Persons[i].getId()) {
            return &Persons[i];
        }
    }
    return nullptr;
}

Attendant* DataManager::searchByIDAttendant(const string& Id) {
    for (int i = 0; i < Attendants.size(); i++) {
        if (Id == Attendants[i].getId()) {
            return &Attendants[i];
        }
    }
    return nullptr;
}

void DataManager::printInstructors() const {
    for (const auto& i : Instructors) {
        i.displayInfo();
    }
}

void DataManager::printPersons() const {
    for (const auto& p : Persons) {
        p.displayInfo();
    }
}

void DataManager::printTAs() const {
    for (const auto& t : TeachingAssistants) {
        t.displayInfo();
    }
}

void DataManager::printAcademicOfficers() const {
    for (const auto& a : AcademicOfficers) {
        a.displayInfo();
    }
}

void DataManager::printAttendants() const {
    for (const auto& l : Attendants) {
        l.displayInfo();
    }
}

void DataManager::printHeadofDep() const {
    for (const auto& h : HeadOfDeps) {
        h.displayInfo();
    }
}

void DataManager::printBuildings() const {
    for (const auto& b : Buildings) {
        b.displayInfo();
    }
}

void DataManager::printRooms() const {
    for (const auto& r : Rooms) {
        r.displayInfo();
    }
}
