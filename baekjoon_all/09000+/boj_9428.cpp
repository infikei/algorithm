// Solve 2023-12-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(4);

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int y0, m0, y1, m1;
        cin >> m0 >> y0 >> m1 >> y1;

        double ans;

        if (y0 == y1) {
            ans = 0.5 * (m1 - m0) / (13 - m0);
        }
        else {
            ans = y1 - y0 - 0.5 + 1. * (m1 - 1) / 12;
        }

        cout << ans << '\n';
    }

    return 0;
}
