// Solve 2025-03-25

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool is_leap_year(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    }

    return false;
}

int get_month_by_name(string month_name) {
    string month_name_arr[13] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int month = 1; month <= 12; month++) {
        if (month_name_arr[month] == month_name) {
            return month;
        }
    }

    return 0;
}

int get_day_of_year(int year, int month, int day) {
    int month_day_arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day_of_year = 0;

    for (int i = 1; i < month; i++) {
        day_of_year += month_day_arr[i];
    }

    day_of_year += day;

    if (is_leap_year(year) && month >= 3) {
        day_of_year++;
    }

    return day_of_year - 1; // 1-based -> 0-based로 변환
}

double get_percentage_of_year(int year, int month, int day, int hour, int minute) {
    int day_of_year = get_day_of_year(year, month, day);
    int minute_of_year = (day_of_year * 24 + hour) * 60 + minute;

    int all_day_of_year = (is_leap_year(year) ? 366 : 365);
    int all_minute_of_year = all_day_of_year * 24 * 60;

    return (double) (minute_of_year * 100) / all_minute_of_year;
}

int main() {
    FASTIO;

    string month_name, day_str, hhmm;
    int year;
    cin >> month_name >> day_str >> year >> hhmm;

    int month = get_month_by_name(month_name);
    day_str.pop_back();
    int day = stoi(day_str);
    
    int hour = stoi(hhmm.substr(0, 2));
    int minute = stoi(hhmm.substr(3, 2));

    double percentage_of_year = get_percentage_of_year(year, month, day, hour, minute);
    SETP(15);
    cout << percentage_of_year << '\n';

    return 0;
}
