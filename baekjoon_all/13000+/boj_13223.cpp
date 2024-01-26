// Solve 2024-01-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string cur_time;
    string target_time;
    cin >> cur_time >> target_time;

    int cur = stoi(cur_time.substr(0, 2)) * 3600 + stoi(cur_time.substr(3, 2)) * 60 + stoi(cur_time.substr(6, 2));
    int target = stoi(target_time.substr(0, 2)) * 3600 + stoi(target_time.substr(3, 2)) * 60 + stoi(target_time.substr(6, 2));
    int dt = target - cur;

    if (dt <= 0) {
        dt += 86400;
    }

    cout << setw(2) << setfill('0') << dt / 3600 << ':';
    cout << setw(2) << setfill('0') << dt % 3600 / 60 << ':';
    cout << setw(2) << setfill('0') << dt % 60 << '\n';

    return 0;
}
