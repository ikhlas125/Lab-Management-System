#pragma once
#include <iostream>
using namespace std;

class Lab {
private:
    string labId;
    string labName;
    string labLocation;
    int credits;
    string semester;

public:
    Lab(const string& id, const string& name, const string& location, int cred, const string& sem)
        : labId(id), labName(name), labLocation(location), credits(cred), semester(sem) {}

    string getLabId() const {
        return labId;
    }

    string getLabName() const {
        return labName;
    }

    string getLabLocation() const {
        return labLocation;
    }

    int getCredits() const {
        return credits;
    }

    string getSemester() const {
        return semester;
    }

    void setLabName(const string& name) {
        labName = name;
    }

    void setLabLocation(const string& location) {
        labLocation = location;
    }

    void setCredits(int cred) {
        credits = cred;
    }

    void setSemester(const string& sem) {
        semester = sem;
    }

    void displayInfo() const {
        cout << "Lab ID: " << labId << endl;
        cout << "Lab Name: " << labName << endl;
        cout << "Location: " << labLocation << endl;
        cout << "Credits: " << credits << endl;
        cout << "Semester: " << semester << endl;
    }
};