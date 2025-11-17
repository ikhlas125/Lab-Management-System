#include "Lab.h"
#include "LabSection.h"
#include "academicOfficer.h"
#include "attendant.h"
#include "building.h"
#include "headOfDep.h"
#include "helper.h"
#include "instructor.h"
#include "room.h"
#include "ta.h"
#include <fstream>
#include <iomanip>
#include <vector>

class DataManager {
  private:
    vector<Instructor> Instructors;
    vector<Person> Persons;
    vector<TA> TeachingAssistants;
    vector<AcademicOfficer> AcademicOfficers;
    vector<Attendant> Attendants;
    vector<HeadOfDep> HeadOfDeps;
    vector<Building> Buildings;
    vector<Room> Rooms;
    vector<Lab> Labs;
    vector<LabSection> LabSections;

  public:
    void loadPersons();
    void loadInstructors();
    void loadTAs();
    void loadAcademicOfficers();
    void loadAttendants();
    void loadHeadofDep();
    void loadBuildings();
    void loadRooms();
    void loadLabs();
    void loadLabSections();
    Person* searchByID(const string& Id);
    Attendant* searchByIDAttendant(const string& Id);
    Building* searchByBuildingID(const string& Id);
    Lab* searchByLabId(const string& Id);
    Instructor* searchByInstructorId(const string& Id);
    TA* searchByTAId(const string& Id);
    void printInstructors() const;
    void printPersons() const;
    void printTAs() const;
    void printAcademicOfficers() const;
    void printAttendants() const;
    void printHeadofDep() const;
    void printBuildings() const;
    void printRooms() const;
    void printLabs() const;
    void printLabSections() const;
};
