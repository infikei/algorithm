// Solve 2023-10-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll humidity, max_t;
    cin >> humidity >> max_t;

    ll ans_t = -1;

    for (ll t = 1; t <= max_t; t++) {
        ll altitude = t * (1 + t * (2 + t * (humidity - 6 * t)));

        if (altitude <= 0) {
            ans_t = t;
            break;
        }
    }

    if (ans_t == -1) {
        cout << "The balloon does not touch ground in the given time.\n";
    }
    else {
        cout << "The balloon first touches ground at hour: " << ans_t << '\n';
    }

    return 0;
}
