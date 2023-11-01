// Solve 2023-11-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    int hour = t / 100;
    int minute = t % 100;

    int stjohn_hour = hour + 1;
    int stjohn_minute = minute + 30;

    if (stjohn_minute >= 60) {
        stjohn_minute -= 60;
        stjohn_hour++;
    }

    if (stjohn_hour >= 24) {
        stjohn_hour -= 24;
    }

    cout << t << " in Ottawa\n";
    cout << (hour + 21) % 24 * 100 + minute << " in Victoria\n";
    cout << (hour + 22) % 24 * 100 + minute << " in Edmonton\n";
    cout << (hour + 23) % 24 * 100 + minute << " in Winnipeg\n";
    cout << t << " in Toronto\n";
    cout << (hour + 1) % 24 * 100 + minute << " in Halifax\n";
    cout << stjohn_hour * 100 + stjohn_minute << " in St. John's\n";

    return 0;
}
