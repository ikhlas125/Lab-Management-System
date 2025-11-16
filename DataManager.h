#include "academicOfficer.h"
#include "attendant.h"
#include "instructor.h"
#include "ta.h"
#include <fstream>
#include <iomanip>
#include <vector>

struct PersonRecord {
    char id[10];
    char name[50];
    char email[50];
    char phone[20];
};

struct InstructorRecord {
    char instructorId[10];
    char personId[10];
};

struct TeachingAssistant {
    char taId[10];
    char personId[10];
};

struct AcademicOfficerR {
    char officerId[10];
    char personId[10];
};

class DataManager {
  private:
    vector<Instructor> Instructors;
    vector<Person> Persons;
    vector<TA> TeachingAssistants;
    vector<AcademicOfficer> AcademicOfficers;

  public:
    void loadPersons() {
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

    void loadInstructors() {
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
            Instructors.push_back(Instructor(tempo->getId(), tempo->getName(), tempo->getEmail(), tempo->getPhone(),
                                             temp[i].instructorId));
        }

        delete[] temp;
        file.close();
        cout << "Loaded " << Instructors.size() << " instructors." << endl;
    }

    void loadTAs() {
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

    void loadAcademicOfficers() {
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
        file.read(reinterpret_cast<char*>(temp), sizeof(TeachingAssistant) * count);
        if (!file) {
            cout << "Error: Could not read all Academic Officer records" << endl;
            delete[] temp;
            return;
        }

        for (int i = 0; i < count; ++i) {
            Person* tempo = searchByID(temp[i].personId);
            AcademicOfficers.push_back(AcademicOfficer(tempo->getId(), tempo->getName(), tempo->getEmail(),
                                                       tempo->getPhone(), temp[i].officerId));
        }

        delete[] temp;
        file.close();
        cout << "Loaded " << Instructors.size() << " Academic Officer." << endl;
    }

    Person* searchByID(const string& Id) {
        for (int i = 0; i < Persons.size(); i++) {
            if (Id == Persons[i].getId()) {
                return &Persons[i];
            }
        }
        return nullptr;
    }

    void printInstructors() const {
        for (const auto& i : Instructors) {
            i.displayInfo();
        }
    }

    void printPersons() const {
        for (const auto& p : Persons) {
            p.displayInfo();
        }
    }

    void printTAs() const {
        for (const auto& t : TeachingAssistants) {
            t.displayInfo();
        }
    }

    void printAcademicOfficers() const {
        for (const auto& a : AcademicOfficers) {
            a.displayInfo();
        }
    }
};
