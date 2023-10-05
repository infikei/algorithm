// Solve 2023-10-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        string t0, dt;
        cin >> t0 >> dt;

        if (t0 == "00:00" && dt == "00:00") break;

        int hour = stoi(t0.substr(0, 2)) + stoi(dt.substr(0, 2));
        int min = stoi(t0.substr(3, 2)) + stoi(dt.substr(3, 2));

        hour += min / 60;
        min %= 60;

        int day = hour / 24;
        hour %= 24;

        cout << setfill('0') << setw(2) << hour << ':';
        cout << setfill('0') << setw(2) << min;

        if (day > 0) cout << " +" << day;

        cout << '\n';
    }

    return 0;
}
