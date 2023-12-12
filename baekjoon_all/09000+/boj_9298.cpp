// Solve 2023-12-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(10);

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        double min_x = 1000., max_x = -1000.;
        double min_y = 1000., max_y = -1000.;

        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;

            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
        }

        double dx = max_x - min_x;
        double dy = max_y - min_y;

        cout << "Case " << ti << ": Area " << dx * dy << ", Perimeter " << (dx + dy) * 2 << '\n';
    }

    return 0;
}
