#include "helper.h"

#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

string buildDateTime(int y, int m, int d, int hh, int mm) {
    ostringstream out;
    out << setw(4) << setfill('0') << y << "-" << setw(2) << setfill('0') << m << "-" << setw(2) << setfill('0') << d
        << " " << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm
        << ":00"; // seconds default to 00
    return out.str();
}

string dayToString(Day day) {
    switch (day) {
    case Day::Monday:
        return "Monday";
    case Day::Tuesday:
        return "Tuesday";
    case Day::Wednesday:
        return "Wednesday";
    case Day::Thursday:
        return "Thursday";
    case Day::Friday:
        return "Friday";
    case Day::Saturday:
        return "Saturday";
    case Day::Sunday:
        return "Sunday";
    default:
        return "Unknown";
    }
}

void inputStartEndTime(string& startDT, string& endDT) {
    int y, m, d;
    int sh, sm, eh, em;

    cout << "Enter date once (YYYY-MM-DD):\n\n";

    cout << "Year (YYYY): ";
    cin >> y;

    cout << "Month (MM): ";
    cin >> m;

    cout << "Day (DD): ";
    cin >> d;

    cout << "\n--- Enter Start Time ---\n";
    cout << "Hour (HH): ";
    cin >> sh;

    cout << "Minute (MM): ";
    cin >> sm;

    cout << "\n--- Enter End Time ---\n";
    cout << "Hour (HH): ";
    cin >> eh;

    cout << "Minute (MM): ";
    cin >> em;

    startDT = buildDateTime(y, m, d, sh, sm);
    endDT = buildDateTime(y, m, d, eh, em);
}
