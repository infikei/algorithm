// Solve 2023-09-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x0, y0, n;
    cin >> x0 >> y0 >> n;

    int x, y;
    cin >> x >> y;

    int d = abs(x - x0) + abs(y - y0);

    for (int i = 1; i < n; i++) {
        int x2, y2;
        cin >> x2 >> y2;

        int d2 = abs(x2 - x0) + abs(y2 - y0);

        if (d2 < d) {
            d = d2;
            x = x2;
            y = y2;
        }
    }

    cout << x << ' ' << y << '\n';

    return 0;
}
