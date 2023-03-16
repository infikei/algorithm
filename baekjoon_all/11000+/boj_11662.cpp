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
using pdd = pair<double, double>;

pdd a, b, c, d;

inline double dist(double t) {
    pdd p1, p2;
    p1.first = (1 - t) * a.first + t * b.first;
    p1.second = (1 - t) * a.second + t * b.second;
    p2.first = (1 - t) * c.first + t * d.first;
    p2.second = (1 - t) * c.second + t * d.second;

    double dx = p2.first - p1.first;
    double dy = p2.second - p1.second;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;

    double low = 0, high = 1, mid1, mid2;
    double ans = min(dist(low), dist(high));
    while (high - low >= 1e-9) {
        mid1 = (low * 2 + high) / 3;
        mid2 = (low + high * 2) / 3;

        double mid1_val = dist(mid1);
        double mid2_val = dist(mid2);

        ans = min(ans, min(mid1_val, mid2_val));

        if (mid1_val < mid2_val) {
            high = mid2;
        }
        else {
            low = mid1;
        }
    }

    SETPRECISION(10);
    cout << ans << '\n';

    return 0;
}
