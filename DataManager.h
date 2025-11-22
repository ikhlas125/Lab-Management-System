#include "Lab.h"
#include "LabSection.h"
#include "LabSession.h"
#include "WeeklyScheduleReport.h"
#include "WeeklyTimeSheetReport.h"
#include "academicOfficer.h"
#include "attendant.h"
#include "building.h"
#include "headOfDep.h"
#include "helper.h"
#include "instructor.h"
#include "makeupLabReq.h"
#include "room.h"
#include "schedule.h"
#include "ta.h"
#include "timesheet.h"
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
    vector<Schedule> LabSchedules;
    vector<LabSession> LabSessions;
    vector<MakeupRequest> MakeupRequests;
    vector<TimeSheet> TimeSheets;
    vector<WeeklyScheduleReport> WeeklyScheduleReports;
    vector<WeeklyTimeSheetReport> WeeklyTimeSheetReports;

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
    void loadLabSchedules();
    void loadLabSessions();
    void loadMakeupRequests();
    void loadTimeSheets();

    Person* searchByID(const string& Id);
    Attendant* searchByIDAttendant(const string& Id);
    Building* searchByBuildingID(const string& Id);
    Lab* searchByLabId(const string& Id);
    Instructor* searchByInstructorId(const string& Id);
    TA* searchByTAId(const string& Id);
    HeadOfDep* searchByHeadOfDepId(const string& Id);
    LabSection* searchbyLabSectionId(const string& Id);
    Room* searchByRoomId(const string& Id);
    Schedule* searchByScheduleId(const string& Id);
    MakeupRequest* searchByMakeupId(const string& Id);
    LabSession* searchByLabSessionId(const string& Id);
    vector<LabSession*> getSessionsByWeekNumber(const string& weekNum);
    vector<TimeSheet*> getTimeSheetsByWeekNumber(const string& weekNum);

    vector<Lab>& getLabs();
    vector<LabSection>& getLabSections();
    vector<LabSession>& getLabSessions();
    vector<Instructor>& getInstructors();
    vector<TA>& getTAs();
    vector<Person>& getPersons();
    vector<Building>& getBuildings();
    vector<Room>& getRooms();
    vector<Schedule>& getSchedules();
    vector<Attendant>& getAttendants();
    vector<AcademicOfficer>& getAcademicOfficers();
    vector<HeadOfDep>& getHeadOfDeps();
    vector<MakeupRequest>& getMakeupRequests();
    vector<TimeSheet>& getTimeSheets();
    vector<WeeklyScheduleReport>& getWeeklyScheduleReports();
    vector<WeeklyTimeSheetReport>& getWeeklyTimeSheetReports();

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
    void printLabSchedules() const;
    void printLabSessions() const;
    void printMakeupRequests() const;
    void printTimeSheets() const;
    void printWeeklyScheduleReports() const;
    void printWeeklyTimeSheetReports() const;

    void saveLabs();
    void saveLabSections();
    void saveSectionTAs();
    void saveSchedules();
    void saveLabSessions();
    void saveMakeupRequests();
    void saveTimeSheets();
};
