#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

class Schedule {
  private:
    string scheduleId;
    Day dayOfWeek;
    string expectedStartTime;
    string expectedEndTime;

  public:
    Schedule(const string& id, Day day, const string& startTime, const string& endTime);

    string getScheduleId() const;
    Day getDayOfWeek() const;
    string getExpectedStartTime() const;
    string getExpectedEndTime() const;

    void setDayOfWeek(Day day);
    void setExpectedStartTime(const string& startTime);
    void setExpectedEndTime(const string& endTime);

    void displayInfo() const;
};