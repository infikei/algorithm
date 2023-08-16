// Solve 2023-08-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int month_days[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
string days[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {
    FASTIO;

    int x, y;
    cin >> x >> y;

    int today = month_days[x - 1] + y;

    cout << days[today % 7] << '\n';

    return 0;
}
