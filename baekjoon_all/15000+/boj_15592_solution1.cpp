// Solve 2023-09-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x[4], y[4];

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = 0;

    if (x[2] <= x[0] && x[1] <= x[3]) {
        if (y[2] <= y[0] && y[1] <= y[3]) {
            ans = 0;
        }
        else if (y[0] < y[2] && y[3] < y[1] || y[3] <= y[0] || y[1] <= y[2]) {
            ans = (x[1] - x[0]) * (y[1] - y[0]);
        }
        else if (y[3] < y[1]) {
            ans = (x[1] - x[0]) * (y[1] - y[3]);
        }
        else {
            ans = (x[1] - x[0]) * (y[2] - y[0]);
        }
    }
    else if (y[2] <= y[0] && y[1] <= y[3]) {
        if (x[0] < x[2] && x[3] < x[1] || x[3] <= x[0] || x[1] <= x[2]) {
            ans = (x[1] - x[0]) * (y[1] - y[0]);
        }
        else if (x[3] < x[1]) {
            ans = (x[1] - x[3]) * (y[1] - y[0]);
        }
        else {
            ans = (x[2] - x[0]) * (y[1] - y[0]);
        }
    }
    else {
        ans = (x[1] - x[0]) * (y[1] - y[0]);
    }

    cout << ans << '\n';

    return 0;
}
