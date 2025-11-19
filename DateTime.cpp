#include "DateTime.h"

#include <iomanip>
#include <sstream>

// Constructors
DateTime::DateTime() : year(2024), month(1), day(1), hour(0), minute(0), second(0) {}

DateTime::DateTime(int y, int m, int d, int h, int min, int sec)
    : year(y), month(m), day(d), hour(h), minute(min), second(sec) {}

// Getters
int DateTime::getYear() const {
    return year;
}
int DateTime::getMonth() const {
    return month;
}
int DateTime::getDay() const {
    return day;
}
int DateTime::getHour() const {
    return hour;
}
int DateTime::getMinute() const {
    return minute;
}
int DateTime::getSecond() const {
    return second;
}

// Setters
void DateTime::setYear(int y) {
    year = y;
}
void DateTime::setMonth(int m) {
    if (m >= 1 && m <= 12)
        month = m;
}
void DateTime::setDay(int d) {
    if (d >= 1 && d <= 31)
        day = d;
}
void DateTime::setHour(int h) {
    if (h >= 0 && h < 24)
        hour = h;
}
void DateTime::setMinute(int min) {
    if (min >= 0 && min < 60)
        minute = min;
}
void DateTime::setSecond(int sec) {
    if (sec >= 0 && sec < 60)
        second = sec;
}

// Helper functions
bool DateTime::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateTime::getDaysInMonth(int m, int y) const {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y)) {
        return 29;
    }
    return daysInMonth[m - 1];
}

// Get day of week using Zeller's congruence algorithm
string DateTime::getDayOfWeek() const {
    int y = year;
    int m = month;
    int d = day;

    // Adjust for January and February
    if (m < 3) {
        m += 12;
        y -= 1;
    }

    int q = d;
    int k = y % 100;
    int j = y / 100;

    int h = (q + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;

    string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return days[h];
}

// Calculate time difference in seconds
int DateTime::calculateTimeDifference(const DateTime& other) const {
    // Convert both dates to total seconds from a reference point
    // For simplicity, we'll calculate days since year 0 and add time

    auto daysSinceEpoch = [](int y, int m, int d) -> long long {
        long long days = 0;
        // Add days for complete years
        for (int yr = 1; yr < y; yr++) {
            days += ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0)) ? 366 : 365;
        }
        // Add days for complete months in current year
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool leap = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
        for (int mn = 1; mn < m; mn++) {
            days += daysInMonth[mn - 1];
            if (mn == 2 && leap)
                days++;
        }
        // Add remaining days
        days += d;
        return days;
    };

    long long days1 = daysSinceEpoch(year, month, day);
    long long days2 = daysSinceEpoch(other.year, other.month, other.day);

    long long seconds1 = days1 * 86400LL + hour * 3600 + minute * 60 + second;
    long long seconds2 = days2 * 86400LL + other.hour * 3600 + other.minute * 60 + other.second;

    return static_cast<int>(seconds1 - seconds2);
}

// Add days to current date
void DateTime::addDays(int days) {
    day += days;

    while (day > getDaysInMonth(month, year)) {
        day -= getDaysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += getDaysInMonth(month, year);
    }
}

// Subtract days from current date
void DateTime::subtractDays(int days) {
    addDays(-days);
}

// Display date and time
void DateTime::displayInfo() const {
    cout << "Date and Time: " << toString() << endl;
    cout << "Day of Week: " << getDayOfWeek() << endl;
}

// Convert to string format
string DateTime::toString() const {
    ostringstream oss;
    oss << setfill('0') << setw(4) << year << "-" << setw(2) << month << "-" << setw(2) << day << " " << setw(2) << hour
        << ":" << setw(2) << minute << ":" << setw(2) << second;
    return oss.str();
}
