#include "LabManager.h"

#include "CountManager.h"
#include "DataManager.h"
#include "Lab.h"
#include "LabSection.h"
#include "instructor.h"
#include <iomanip>
#include <sstream>

LabManager::LabManager(DataManager* dm, CountManager* dc) : Data(dm), DataCount(dc) {}

void LabManager::addLabs(const string& name, const string& code, int cred, const string& sem) {
    int currentCount = DataCount->getLabCount();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "L" << setfill('0') << setw(3) << nextId;
    string newLabId = oss.str();
    Lab newLab(newLabId, name, code, cred, sem);
    Data->getLabs().push_back(newLab);
    DataCount->incrementLabCount();
    cout << "Lab added successfully with ID: " << newLabId << endl;
}

void LabManager::addLabSections(const string& name, const string& sem, const string& year, Lab* lab,
                                Instructor* assignInstructor) {
    int currentCount = DataCount->getLabSectionCount();
    int nextId = currentCount + 1;
    ostringstream oss;
    oss << "LS" << setfill('0') << setw(3) << nextId;
    string newLabId = oss.str();
    LabSection newLabSection(newLabId, name, sem, year);
    newLabSection.setLab(lab);
    newLabSection.setAssignedInstructor(assignInstructor);
    Data->getLabSections().push_back(newLabSection);
    DataCount->incrementLabSectionCount();
    cout << "Lab Section added successfully with ID: " << newLabId << endl;
}