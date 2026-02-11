#include <iostream>
#include "Date.h"
using namespace std;

int endDay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string name[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "Septemnber", "October", "November", "December"};

bool valid(int d, int m, int y) {
    if (m < 1 || m > 12) {
        cout << "Error: Month must be between 1 and 12\n";
        return false;
    }

    int eDay = endDay[m];
    if (m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
        eDay++;

    if (d < 1 || d > eDay) {
        cout << "Error: Day in " << name[m] << " of " << y << " must be between 1 and " << eDay << "\n";
        return false;
    }

    return true;
}

string suffix(int d) {
    if (d % 100 >= 11 && d % 100 <= 13)
        return "th"; // 11, 12, 13
    switch (d % 10) {
        case 1: return "st"; // 1, 21, 31
        case 2: return "nd"; // 2, 22
        case 3: return "rd"; // 3, 23
        default: return "th";
    }
}

Date::Date() {}

Date::~Date() {}

void Date::input() {
    cout << "Enter year: ";
    cin >> y;

    bool firstMonth = true;
    do {
        if (firstMonth) cout << "Enter month: ";
        else cout << "Re-enter month: ";
        cin >> m;
        firstMonth = false;
        if (m < 1 || m > 12)
            cout << "Error: Month must be between 1 and 12\n";
    } while (m < 1 || m > 12);

    bool firstDay = true;
    do {
        if (firstDay) cout << "Enter day: ";
        else cout << "Re-enter day: ";
        cin >> d;
        firstDay = false;
    } while (!valid(d, m, y));
}

void Date::output() {
    cout << d << "/" << m << "/" << y << "\n";
    cout << d << suffix(d) << " " << name[m] << ", " << y << "\n";
}