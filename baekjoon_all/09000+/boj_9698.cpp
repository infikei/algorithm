// Solve 2023-12-14

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

    for (int ti = 1; ti <= t; ti++) {
        int hour, minute;
        cin >> hour >> minute;

        minute -= 45;

        if (minute < 0) {
            minute += 60;
            hour--;
        }

        if (hour < 0) {
            hour += 24;
        }

        cout << "Case #" << ti << ": " << hour << ' ' << minute << '\n';
    }

    return 0;
}
