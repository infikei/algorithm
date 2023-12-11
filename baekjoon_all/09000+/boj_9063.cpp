// Solve 2023-03-22
// Update 2023-12-11

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

    int x_min = 10000, x_max = -10000;
    int y_min = 10000, y_max = -10000;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        x_min = min(x_min, x);
        x_max = max(x_max, x);
        y_min = min(y_min, y);
        y_max = max(y_max, y);
    }

    cout << (x_max - x_min) * (y_max - y_min) << '\n';

    return 0;
}
