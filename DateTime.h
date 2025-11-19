#pragma once
#include <iostream>
#include <string>
using namespace std;

class DateTime {
  private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    bool isLeapYear(int y) const;
    int getDaysInMonth(int m, int y) const;

  public:
    // Constructors
    DateTime();
    DateTime(int y, int m, int d, int h = 0, int min = 0, int sec = 0);

    // Getters
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // Setters
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHour(int h);
    void setMinute(int min);
    void setSecond(int sec);

    // Main Functionalities
    string getDayOfWeek() const;
    int calculateTimeDifference(const DateTime& other) const; // Returns difference in seconds
    void addDays(int days);
    void subtractDays(int days);

    // Utility
    void displayInfo() const;
    string toString() const;
};
