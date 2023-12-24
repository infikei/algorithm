// Solve 2023-02-04
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll n, s, t, ts;

ll calc(ll m) {
    if (m <= ts * 2) return m * s;
    if (m % 2 == 1) return calc(m - 1) + s;
    return calc(m / 2) + t;
}

int main() {
    FASTIO;

    int tc;
    cin >> tc;

    for (int tci = 0; tci < tc; tci++) {
        cin >> n >> s >> t;

        ts = t / s;

        cout << calc(n) << '\n';
    }

    return 0;
}
