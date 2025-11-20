#include "DataManager.h"

#include <cstring>

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

void DataManager::loadLabs() {
    Labs.clear();

    ifstream file("labs.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open labs.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid labs.bin format" << endl;
        return;
    }

    LabR* temp = new LabR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(LabR) * count);
    if (!file) {
        cout << "Error: Could not read all Labs records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Labs.push_back(Lab(temp[i].labId, temp[i].labName, temp[i].labCode, temp[i].credits, temp[i].semester));
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << Labs.size() << " Labs." << endl;
}

void DataManager::loadLabSections() {
    LabSections.clear();

    ifstream file("lab_sections.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open lab_sections.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid lab_sections.bin format" << endl;
        return;
    }

    LabSectionR* temp = new LabSectionR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(LabSectionR) * count);
    if (!file) {
        cout << "Error: Could not read all Labs records" << endl;
        delete[] temp;
        return;
    }
    LabSections.reserve(count);
    for (int i = 0; i < count; ++i) {
        LabSections.push_back(
            LabSection(temp[i].sectionId, temp[i].sectionNumber, temp[i].semester, temp[i].academicYear));
        LabSection* labSectionPtr = &LabSections.back();
        Lab* LabA = searchByLabId(temp[i].labId);
        Instructor* InstructorA = searchByInstructorId(temp[i].instructorId);
        labSectionPtr->setLab(LabA);
        labSectionPtr->setAssignedInstructor(InstructorA);
        if (InstructorA) {
            InstructorA->addAssignedSection(labSectionPtr);
        }
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << LabSections.size() << " LabSections." << endl;

    ifstream taFile("section_tas.bin", ios::binary);
    if (taFile.is_open()) {
        int taCount = 0;
        taFile.read(reinterpret_cast<char*>(&taCount), sizeof(int));
        if (taFile && taCount > 0) {
            SectionTA* sectionTAs = new SectionTA[taCount];
            taFile.read(reinterpret_cast<char*>(sectionTAs), sizeof(SectionTA) * taCount);
            if (taFile) {
                for (int i = 0; i < taCount; ++i) {
                    LabSection* section = nullptr;
                    for (auto& sec : LabSections) {
                        if (sec.getSectionID() == string(sectionTAs[i].sectionId)) {
                            section = &sec;
                            break;
                        }
                    }
                    if (section) {
                        TA* ta = searchByTAId(sectionTAs[i].taId);
                        if (ta) {
                            section->addTA(ta);
                            ta->addAssignedSection(section);
                        }
                    }
                }
            }
            delete[] sectionTAs;
        }
        taFile.close();
    }
}

void DataManager::loadLabSchedules() {
    LabSchedules.clear();

    ifstream file("schedules.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open schedules.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid schedules.bin format" << endl;
        return;
    }

    ScheduleR* temp = new ScheduleR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(ScheduleR) * count);
    if (!file) {
        cout << "Error: Could not read all Schedules records" << endl;
        delete[] temp;
        return;
    }

    for (int i = 0; i < count; ++i) {
        Day day = Day::Monday;
        string dayStr = temp[i].dayOfWeek;
        if (dayStr == "Monday")
            day = Day::Monday;
        else if (dayStr == "Tuesday")
            day = Day::Tuesday;
        else if (dayStr == "Wednesday")
            day = Day::Wednesday;
        else if (dayStr == "Thursday")
            day = Day::Thursday;
        else if (dayStr == "Friday")
            day = Day::Friday;
        else if (dayStr == "Saturday")
            day = Day::Saturday;
        else if (dayStr == "Sunday")
            day = Day::Sunday;

        LabSchedules.push_back(Schedule(temp[i].scheduleId, day, temp[i].expectedStartTime, temp[i].expectedEndTime));
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << LabSchedules.size() << " Schedules." << endl;
}

void DataManager::loadLabSessions() {
    LabSessions.clear();

    ifstream file("lab_sessions.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot open lab_sessions.bin" << endl;
        return;
    }

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!file || count <= 0) {
        cout << "Error: Invalid lab_sessions.bin format" << endl;
        return;
    }

    LabSessionR* temp = new LabSessionR[count];
    file.read(reinterpret_cast<char*>(temp), sizeof(LabSessionR) * count);
    if (!file) {
        cout << "Error: Could not read all LabsSessions records" << endl;
        delete[] temp;
        return;
    }

    LabSessions.reserve(count);
    for (int i = 0; i < count; ++i) {
        LabSessions.push_back(LabSession(temp[i].sessionId, to_string(temp[i].weekNumber), temp[i].status));
        LabSession* LabSessionPtr = &LabSessions.back();
        LabSection* section = searchbyLabSectionId(temp[i].sectionId);
        LabSessionPtr->setSection(section);
        LabSessionPtr->setAssignedRoom(searchByRoomId(temp[i].roomId));
        LabSessionPtr->setSchedule(searchByScheduleId(temp[i].scheduleId));

        if (section) {
            section->addSession(LabSessionPtr);
        }
    }

    delete[] temp;
    file.close();
    cout << "Loaded " << LabSessions.size() << " LabSessions." << endl;
}

LabSection* DataManager::searchbyLabSectionId(const string& Id) {
    for (int i = 0; i < LabSections.size(); i++) {
        if (Id == LabSections[i].getSectionID()) {
            return &LabSections[i];
        }
    }
    return nullptr;
}

Instructor* DataManager::searchByInstructorId(const string& Id) {
    for (int i = 0; i < Instructors.size(); i++) {
        if (Id == Instructors[i].getInstructorId()) {
            return &Instructors[i];
        }
    }
    return nullptr;
}

TA* DataManager::searchByTAId(const string& Id) {
    for (int i = 0; i < TeachingAssistants.size(); i++) {
        if (Id == TeachingAssistants[i].getTAId()) {
            return &TeachingAssistants[i];
        }
    }
    return nullptr;
}

Room* DataManager::searchByRoomId(const string& Id) {
    for (int i = 0; i < Rooms.size(); i++) {
        if (Id == Rooms[i].getRoomID()) {
            return &Rooms[i];
        }
    }
    return nullptr;
}

Schedule* DataManager::searchByScheduleId(const string& Id) {
    for (int i = 0; i < LabSchedules.size(); i++) {
        if (Id == LabSchedules[i].getScheduleId()) {
            return &LabSchedules[i];
        }
    }
    return nullptr;
}

Lab* DataManager::searchByLabId(const string& Id) {
    for (int i = 0; i < Labs.size(); i++) {
        if (Id == Labs[i].getLabId()) {
            return &Labs[i];
        }
    }
    return nullptr;
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

void DataManager::printLabs() const {
    for (const auto& l : Labs) {
        l.displayInfo();
    }
}

void DataManager::printLabSections() const {
    for (const auto& l : LabSections) {
        l.displayInfo();
    }
}

void DataManager::printLabSchedules() const {
    for (const auto& l : LabSchedules) {
        l.displayInfo();
    }
}

void DataManager::printLabSessions() const {
    for (const auto& s : LabSessions) {
        s.displayInfo();
    }
}

vector<Lab>& DataManager::getLabs() {
    return Labs;
}

vector<LabSection>& DataManager::getLabSections() {
    return LabSections;
}

vector<LabSession>& DataManager::getLabSessions() {
    return LabSessions;
}

vector<Instructor>& DataManager::getInstructors() {
    return Instructors;
}

vector<TA>& DataManager::getTAs() {
    return TeachingAssistants;
}

vector<Person>& DataManager::getPersons() {
    return Persons;
}

vector<Building>& DataManager::getBuildings() {
    return Buildings;
}

vector<Room>& DataManager::getRooms() {
    return Rooms;
}

vector<Schedule>& DataManager::getSchedules() {
    return LabSchedules;
}

vector<Attendant>& DataManager::getAttendants() {
    return Attendants;
}

vector<AcademicOfficer>& DataManager::getAcademicOfficers() {
    return AcademicOfficers;
}

vector<HeadOfDep>& DataManager::getHeadOfDeps() {
    return HeadOfDeps;
}

void DataManager::saveLabs() {
    ofstream file("labs.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot create labs.bin" << endl;
        return;
    }

    int count = Labs.size();
    file.write(reinterpret_cast<const char*>(&count), sizeof(int));

    LabR* temp = new LabR[count];
    for (int i = 0; i < count; ++i) {
        strncpy(temp[i].labId, Labs[i].getLabId().c_str(), 9);
        temp[i].labId[9] = '\0';

        strncpy(temp[i].labCode, Labs[i].getLabCode().c_str(), 19);
        temp[i].labCode[19] = '\0';

        strncpy(temp[i].labName, Labs[i].getLabName().c_str(), 49);
        temp[i].labName[49] = '\0';

        temp[i].credits = Labs[i].getCredits();

        strncpy(temp[i].semester, Labs[i].getSemester().c_str(), 19);
        temp[i].semester[19] = '\0';
    }

    file.write(reinterpret_cast<const char*>(temp), sizeof(LabR) * count);
    delete[] temp;
    file.close();

    cout << "Saved " << count << " Labs to labs.bin" << endl;
}

void DataManager::saveLabSections() {
    ofstream file("lab_sections.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot create lab_sections.bin" << endl;
        return;
    }

    int count = LabSections.size();
    file.write(reinterpret_cast<const char*>(&count), sizeof(int));

    LabSectionR* temp = new LabSectionR[count];
    for (int i = 0; i < count; ++i) {
        strncpy(temp[i].sectionId, LabSections[i].getSectionID().c_str(), 9);
        temp[i].sectionId[9] = '\0';

        strncpy(temp[i].labId, LabSections[i].getLab()->getLabId().c_str(), 9);
        temp[i].labId[9] = '\0';

        strncpy(temp[i].sectionNumber, LabSections[i].getSectionName().c_str(), 4);
        temp[i].sectionNumber[4] = '\0';

        strncpy(temp[i].instructorId, LabSections[i].getAssignedInstructor()->getInstructorId().c_str(), 9);
        temp[i].instructorId[9] = '\0';

        strncpy(temp[i].semester, LabSections[i].getSemester().c_str(), 19);
        temp[i].semester[19] = '\0';

        strncpy(temp[i].academicYear, LabSections[i].getAcademicYear().c_str(), 14);
        temp[i].academicYear[14] = '\0';
    }

    file.write(reinterpret_cast<const char*>(temp), sizeof(LabSectionR) * count);
    delete[] temp;
    file.close();

    cout << "Saved " << count << " LabsSections to lab_sections.bin" << endl;
}

void DataManager::saveSectionTAs() {
    ofstream file("section_tas.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot create section_tas.bin" << endl;
        return;
    }

    int totalAssignments = 0;
    for (int i = 0; i < LabSections.size(); i++) {
        totalAssignments += LabSections[i].getAssignedTas().size();
    }

    file.write(reinterpret_cast<const char*>(&totalAssignments), sizeof(int));

    SectionTA* temp = new SectionTA[totalAssignments];
    int index = 0;

    for (int i = 0; i < LabSections.size(); i++) {
        for (int j = 0; j < LabSections[i].getAssignedTas().size(); j++) {
            strncpy(temp[index].sectionId, LabSections[i].getSectionID().c_str(), 9);
            temp[index].sectionId[9] = '\0';

            strncpy(temp[index].taId, LabSections[i].getAssignedTas()[j]->getTAId().c_str(), 9);
            temp[index].taId[9] = '\0';

            index++;
        }
    }

    file.write(reinterpret_cast<const char*>(temp), sizeof(SectionTA) * totalAssignments);
    delete[] temp;
    file.close();

    cout << "Saved " << totalAssignments << " TA assignments to section_tas.bin" << endl;
}

void DataManager::saveSchedules() {
    ofstream file("schedules.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot create schedules.bin" << endl;
        return;
    }

    int count = LabSchedules.size();
    file.write(reinterpret_cast<const char*>(&count), sizeof(int));

    ScheduleR* temp = new ScheduleR[count];
    for (int i = 0; i < count; ++i) {
        strncpy(temp[i].scheduleId, LabSchedules[i].getScheduleId().c_str(), 9);
        temp[i].scheduleId[9] = '\0';

        Day day = LabSchedules[i].getDayOfWeek();
        string dayStr;
        switch (day) {
        case Day::Monday:
            dayStr = "Monday";
            break;
        case Day::Tuesday:
            dayStr = "Tuesday";
            break;
        case Day::Wednesday:
            dayStr = "Wednesday";
            break;
        case Day::Thursday:
            dayStr = "Thursday";
            break;
        case Day::Friday:
            dayStr = "Friday";
            break;
        case Day::Saturday:
            dayStr = "Saturday";
            break;
        case Day::Sunday:
            dayStr = "Sunday";
            break;
        }
        strncpy(temp[i].dayOfWeek, dayStr.c_str(), 14);
        temp[i].dayOfWeek[14] = '\0';

        strncpy(temp[i].expectedStartTime, LabSchedules[i].getExpectedStartTime().c_str(), 24);
        temp[i].expectedStartTime[24] = '\0';

        strncpy(temp[i].expectedEndTime, LabSchedules[i].getExpectedEndTime().c_str(), 24);
        temp[i].expectedEndTime[24] = '\0';
    }

    file.write(reinterpret_cast<const char*>(temp), sizeof(ScheduleR) * count);
    delete[] temp;
    file.close();

    cout << "Saved " << count << " Schedules to schedules.bin" << endl;
}

void DataManager::saveLabSessions() {
    ofstream file("lab_sessions.bin", ios::binary);
    if (!file) {
        cout << "Error: Cannot create lab_sessions.bin" << endl;
        return;
    }

    int count = LabSessions.size();
    file.write(reinterpret_cast<const char*>(&count), sizeof(int));

    LabSessionR* temp = new LabSessionR[count];
    for (int i = 0; i < count; ++i) {
        strncpy(temp[i].sessionId, LabSessions[i].getSessionID().c_str(), 9);
        temp[i].sessionId[9] = '\0';

        strncpy(temp[i].sectionId, LabSessions[i].getSection()->getSectionID().c_str(), 9);
        temp[i].sectionId[9] = '\0';

        strncpy(temp[i].roomId, LabSessions[i].getAssignedRoom()->getRoomID().c_str(), 9);
        temp[i].roomId[9] = '\0';

        strncpy(temp[i].scheduleId, LabSessions[i].getSchedule()->getScheduleId().c_str(), 9);
        temp[i].scheduleId[9] = '\0';

        temp[i].weekNumber = stoi(LabSessions[i].getWeekNumber());

        strncpy(temp[i].status, LabSessions[i].getStatus().c_str(), 14);
        temp[i].status[14] = '\0';
    }

    file.write(reinterpret_cast<const char*>(temp), sizeof(LabSessionR) * count);
    delete[] temp;
    file.close();

    cout << "Saved " << count << " LabSessions to lab_sessions.bin" << endl;
}