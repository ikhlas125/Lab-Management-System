#include "academicOfficer.h"
#include "attendant.h"
#include "helper.h"
#include "instructor.h"
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

  public:
    void loadPersons();
    void loadInstructors();
    void loadTAs();
    void loadAcademicOfficers();
    void loadAttendants();
    Person* searchByID(const string& Id);
    void printInstructors() const;
    void printPersons() const;
    void printTAs() const;
    void printAcademicOfficers() const;
    void printAttendants() const;
};
