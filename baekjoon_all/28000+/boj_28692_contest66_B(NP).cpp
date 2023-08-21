// Solve 2023-08-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(9);

    int n;
    cin >> n;

    ll sx = 0, sy = 0, sxx = 0, sxy = 0;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        sx += x;
        sy += y;
        sxx += x * x;
        sxy += x * y;
    }

    ll p = n * sxx - sx * sx;

    if (p == 0) {
        cout << "EZPZ\n";
    }
    else {
        double a2 = (double)(n * sxy - sx * sy) / p;
        double b2 = (sy - a2 * sx) / n;

        cout << a2 << ' ' << b2 << '\n';
    }

    return 0;
}
