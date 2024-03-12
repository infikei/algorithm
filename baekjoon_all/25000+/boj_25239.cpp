// Solve 2022-08-16
// Update 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string now_time;
    cin >> now_time;

    int now_hour = stoi(now_time.substr(0, 2));
    int now_minute = stoi(now_time.substr(3, 2));
    int recover[6];

    for (int i = 0; i < 6; i++) {
        cin >> recover[i];
    }

    int l;
    cin >> l;

    while (l-- > 0) {
        double event_time;
        string event;
        cin >> event_time >> event;

        if (event == "^") {
            recover[now_hour / 2] = 0;
        }
        else if (event == "10MIN") {
            now_minute += 10;
        }
        else if (event == "30MIN") {
            now_minute += 30;
        }
        else if (event == "50MIN") {
            now_minute += 50;
        }
        else if (event == "2HOUR") {
            now_hour += 2;
        }
        else if (event == "4HOUR") {
            now_hour += 4;
        }
        else if (event == "9HOUR") {
            now_hour += 9;
        }

        if (now_minute >= 60) {
            now_minute -= 60;
            now_hour++;
        }

        if (now_hour >= 12) {
            now_hour -= 12;
        }
    }

    int h = 0;

    for (int i = 0; i < 6; i++) {
        h += recover[i];
    }

    if (h > 100) {
        h = 100;
    }

    cout << h << '\n';

    return 0;
}
