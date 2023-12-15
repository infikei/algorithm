// Solve 2022-12-06
// Update 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    int dp = t % (w * 2);
    int x = p + dp;

    if (x > w * 2) {
        x -= w * 2;
    }
    else if (x > w) {
        x = w * 2 - x;
    }

    int dq = t % (h * 2);
    int y = q + dq;

    if (y > h * 2) {
        y -= h * 2;
    }
    else if (y > h) {
        y = h * 2 - y;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}
