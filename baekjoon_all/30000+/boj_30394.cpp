// Solve 2023-11-04

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

    int y_min, y_max, x, y;
    cin >> x >> y;
    y_min = y_max = y;

    for (int i = 1; i < n; i++) {
        cin >> x >> y;

        if (y < y_min) y_min = y;
        if (y > y_max) y_max = y;
    }

    cout << y_max - y_min << '\n';

    return 0;
}
