// Solve 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(2);

    int ti = 0;

    while (true) {
        int n;
        cin >> n;

        if (n < 0) break;

        int sum_m = 0;
        ll sum_mx = 0;
        ll sum_my = 0;

        for (int i = 0; i < n; i++) {
            int x, y, m;
            cin >> x >> y >> m;

            sum_m += m;
            sum_mx += m * x;
            sum_my += m * y;
        }

        double gx = (double)sum_mx / sum_m;
        double gy = (double)sum_my / sum_m;

        cout << "Case " << ++ti << ": " << gx << ' ' << gy << '\n';
    }

    return 0;
}
