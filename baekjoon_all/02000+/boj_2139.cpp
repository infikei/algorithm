// Solve 2025-06-06

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

int month_days[13] = {0, 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
int month_days_of_leap_year[13] = {0, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};

bool is_leap_year(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

int get_day_of_year(int year, int month, int day) {
    if (is_leap_year(year)) {
        return month_days_of_leap_year[month] + day;
    }
    return month_days[month] + day;
}

int main() {
    FASTIO;

    for (int i = 1; i < 13; i++) {
        month_days[i] += month_days[i - 1];
        month_days_of_leap_year[i] += month_days_of_leap_year[i - 1];
    }

    while (true) {
        int day, month, year;
        cin >> day >> month >> year;

        if (year == 0) break;

        cout << get_day_of_year(year, month, day) << '\n';
    }

    return 0;
}
