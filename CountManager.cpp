#include "CountManager.h"

CountManager::CountManager() {
    counts.labCount = 0;
    counts.labSectionCount = 0;
    counts.labSessionCount = 0;
    counts.instructorCount = 0;
    counts.taCount = 0;
    counts.personCount = 0;
    counts.buildingCount = 0;
    counts.roomCount = 0;
    counts.scheduleCount = 0;
    counts.attendantCount = 0;
    counts.academicOfficerCount = 0;
    counts.headOfDepCount = 0;
    counts.makeupRequestCount = 0;
    counts.timesheetCount = 0;

    loadCounts();
}

void CountManager::loadCounts() {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&counts), sizeof(DataCounts));
        file.close();
        cout << "Counts loaded from " << filename << endl;
    } else {
        cout << "No existing count file found. Starting with zero counts." << endl;
    }
}

void CountManager::saveCounts() {
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&counts), sizeof(DataCounts));
        file.close();
    } else {
        cout << "Error: Could not save counts to " << filename << endl;
    }
}

int CountManager::getLabCount() const {
    return counts.labCount;
}

int CountManager::getLabSectionCount() const {
    return counts.labSectionCount;
}

int CountManager::getLabSessionCount() const {
    return counts.labSessionCount;
}

int CountManager::getInstructorCount() const {
    return counts.instructorCount;
}

int CountManager::getTACount() const {
    return counts.taCount;
}

int CountManager::getPersonCount() const {
    return counts.personCount;
}

int CountManager::getBuildingCount() const {
    return counts.buildingCount;
}

int CountManager::getRoomCount() const {
    return counts.roomCount;
}

int CountManager::getScheduleCount() const {
    return counts.scheduleCount;
}

int CountManager::getAttendantCount() const {
    return counts.attendantCount;
}

int CountManager::getAcademicOfficerCount() const {
    return counts.academicOfficerCount;
}

int CountManager::getHeadOfDepCount() const {
    return counts.headOfDepCount;
}

int CountManager::getMakeupRequestCount() const {
    return counts.makeupRequestCount;
}

int CountManager::getTimesheetCount() const {
    return counts.timesheetCount;
}

void CountManager::incrementLabCount() {
    counts.labCount++;
    saveCounts();
}

void CountManager::incrementLabSectionCount() {
    counts.labSectionCount++;
    saveCounts();
}

void CountManager::incrementLabSessionCount() {
    counts.labSessionCount++;
    saveCounts();
}

void CountManager::incrementInstructorCount() {
    counts.instructorCount++;
    saveCounts();
}

void CountManager::incrementTACount() {
    counts.taCount++;
    saveCounts();
}

void CountManager::incrementPersonCount() {
    counts.personCount++;
    saveCounts();
}

void CountManager::incrementBuildingCount() {
    counts.buildingCount++;
    saveCounts();
}

void CountManager::incrementRoomCount() {
    counts.roomCount++;
    saveCounts();
}

void CountManager::incrementScheduleCount() {
    counts.scheduleCount++;
    saveCounts();
}

void CountManager::incrementAttendantCount() {
    counts.attendantCount++;
    saveCounts();
}

void CountManager::incrementAcademicOfficerCount() {
    counts.academicOfficerCount++;
    saveCounts();
}

void CountManager::incrementHeadOfDepCount() {
    counts.headOfDepCount++;
    saveCounts();
}

void CountManager::incrementMakeupRequestCount() {
    counts.makeupRequestCount++;
    saveCounts();
}

void CountManager::incrementTimesheetCount() {
    counts.timesheetCount++;
    saveCounts();
}

void CountManager::displayCounts() const {
    cout << "\n=== Data Counts ===" << endl;
    cout << "Labs: " << counts.labCount << endl;
    cout << "Lab Sections: " << counts.labSectionCount << endl;
    cout << "Lab Sessions: " << counts.labSessionCount << endl;
    cout << "Instructors: " << counts.instructorCount << endl;
    cout << "Teaching Assistants: " << counts.taCount << endl;
    cout << "Persons: " << counts.personCount << endl;
    cout << "Buildings: " << counts.buildingCount << endl;
    cout << "Rooms: " << counts.roomCount << endl;
    cout << "Schedules: " << counts.scheduleCount << endl;
    cout << "Attendants: " << counts.attendantCount << endl;
    cout << "Academic Officers: " << counts.academicOfficerCount << endl;
    cout << "Head of Departments: " << counts.headOfDepCount << endl;
    cout << "Makeup Requests: " << counts.makeupRequestCount << endl;
    cout << "Timesheets: " << counts.timesheetCount << endl;
    cout << "===================\n" << endl;
}
