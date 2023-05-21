// Solve 2023-03-13
// Update 2023-05-20

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
using pll = pair<ll, ll>;

struct Point{
    ll x, y;
    Point(ll nx = 0, ll ny = 0) : x(nx), y(ny) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

ll calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll ans2 = 0;

    Point points[3];
    cin >> points[0].x >> points[0].y;
    cin >> points[1].x >> points[1].y;

    for (int i = 2; i < n; i++) {
        cin >> points[2].x >> points[2].y;
        ans2 += calc_ccw(points[0], points[1], points[2]);

        points[1] = points[2];
    }

    double ans = abs(ans2) * 0.5;
    SETPRECISION(1);
    cout << ans << '\n';

    return 0;
}
