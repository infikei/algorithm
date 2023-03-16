// Solve 2023-03-16

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using vecd = vector<double>;

inline double dist(vecd p1, vecd p2) {
    double dx = p2[0] - p1[0];
    double dy = p2[1] - p1[1];
    double dz = p2[2] - p1[2];
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    FASTIO;

    vecd a(3), b(3), c(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    for (int i = 0; i < 3; i++) cin >> c[i];

    vecd low = a, high = b, mid(3);
    double ans = min(dist(a, c), dist(b, c));
    while (true) {
        for (int i = 0; i < 3; i++) {
            mid[i] = (low[i] + high[i]) / 2;
        }
        double low_val = dist(low, c);
        double mid_val = dist(mid, c);
        double high_val = dist(high, c);

        if (abs(ans - mid_val) < 1e-12) {
            break;
        }

        if (mid_val < ans) {
            ans = mid_val;
        }

        if (low_val < high_val) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    SETPRECISION(10);
    cout << ans << '\n';

    return 0;
}
