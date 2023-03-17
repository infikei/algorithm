// Solve 2022-09-09
// Update 2023-03-17

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    string now_time, complete_time;
    cin >> now_time >> complete_time;

    int h = stoi(complete_time.substr(0, 2)) - stoi(now_time.substr(0, 2));
    int m = stoi(complete_time.substr(3, 2)) - stoi(now_time.substr(3, 2));
    int s = stoi(complete_time.substr(6, 2)) - stoi(now_time.substr(6, 2));

    if (s < 0) {
        s += 60;
        m--;
    }

    if (m < 0) {
        m += 60;
        h--;
    }

    if (h < 0) {
        h += 24;
    }

    cout << h / 10 << h % 10 << ':';
    cout << m / 10 << m % 10 << ':';
    cout << s / 10 << s % 10 << '\n';

    return 0;
}
