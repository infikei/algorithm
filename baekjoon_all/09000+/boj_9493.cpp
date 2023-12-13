// Solve 2023-09-05
// Update 2023-12-13

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
        ll m, a, b;
        cin >> m >> a >> b;

        if (m == 0) break;

        ll ans = round((double)(3600 * m * (b - a)) / (a * b));
        ll ans_hour = ans / 3600;
        ll ans_min = ans / 60 % 60;
        ll ans_sec = ans % 60;

        cout << ans_hour << ':';
        cout << setfill('0') << setw(2) << ans_min << ':';
        cout << setfill('0') << setw(2) << ans_sec << '\n';
    }

    return 0;
}
