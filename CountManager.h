#pragma once
#include <fstream>
#include <iostream>
using namespace std;

struct DataCounts {
    int labCount;
    int labSectionCount;
    int labSessionCount;
    int instructorCount;
    int taCount;
    int personCount;
    int buildingCount;
    int roomCount;
    int scheduleCount;
    int attendantCount;
    int academicOfficerCount;
    int headOfDepCount;
};

class CountManager {
  private:
    DataCounts counts;
    const string filename = "data_counts.bin";

  public:
    CountManager();

    void loadCounts();

    void saveCounts();

    int getLabCount() const;
    int getLabSectionCount() const;
    int getLabSessionCount() const;
    int getInstructorCount() const;
    int getTACount() const;
    int getPersonCount() const;
    int getBuildingCount() const;
    int getRoomCount() const;
    int getScheduleCount() const;
    int getAttendantCount() const;
    int getAcademicOfficerCount() const;
    int getHeadOfDepCount() const;

    void incrementLabCount();
    void incrementLabSectionCount();
    void incrementLabSessionCount();
    void incrementInstructorCount();
    void incrementTACount();
    void incrementPersonCount();
    void incrementBuildingCount();
    void incrementRoomCount();
    void incrementScheduleCount();
    void incrementAttendantCount();
    void incrementAcademicOfficerCount();
    void incrementHeadOfDepCount();

    void displayCounts() const;
};
