// Solve 2023-08-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    bool flag[4] = { false };
    int limit[4];

    for (int i = 0; i < n; i++) {
        int xi, yi;
        char direction;
        cin >> xi >> yi >> direction;

        if (direction == 'R') {
            if (flag[0]) {
                limit[0] = max(limit[0], xi);
            }
            else {
                flag[0] = true;
                limit[0] = xi;
            }
        }
        else if (direction == 'L') {
            if (flag[1]) {
                limit[1] = min(limit[1], xi);
            }
            else {
                flag[1] = true;
                limit[1] = xi;
            }
        }
        else if (direction == 'U') {
            if (flag[2]) {
                limit[2] = max(limit[2], yi);
            }
            else {
                flag[2] = true;
                limit[2] = yi;
            }
        }
        else {
            if (flag[3]) {
                limit[3] = min(limit[3], yi);
            }
            else {
                flag[3] = true;
                limit[3] = yi;
            }
        }
    }

    if (flag[0] && flag[1] && flag[2] && flag[3]) {
        cout << (ll)(limit[1] - limit[0] - 1) * (limit[3] - limit[2] - 1) << '\n';
    }
    else {
        cout << "Infinity\n";
    }

    return 0;
}
