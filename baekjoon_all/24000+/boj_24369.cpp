// Solve 2023-02-22
// Update 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a2, a1, a0, c, n0;
    cin >> a2 >> a1 >> a0 >> c >> n0;

    if (a2 == c) {
        if (a1 * n0 + a0 >= 0 && a1 >= 0) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    else {
        if (a2 > c && (a2 - c) * n0 * n0 + a1 * n0 + a0 >= 0 && ((a2 - c) * n0 * 2 + a1 >= 0 || a1 * a1 <= a0 * (a2 - c) * 4)) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
