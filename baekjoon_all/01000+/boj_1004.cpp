// Solve 2022-06-07
// Update 2023-08-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int x1, y1, x2, y2, n;
        cin >> x1 >> y1 >> x2 >> y2 >> n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool start = false, finish = false;

            int dx = x1 - cx, dy = y1 - cy;
            if (dx * dx + dy * dy < r * r) start = true;

            dx = x2 - cx, dy = y2 - cy;
            if (dx * dx + dy * dy < r * r) finish = true;

            if (start != finish) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
