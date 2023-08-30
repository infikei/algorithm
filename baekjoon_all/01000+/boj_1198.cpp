// Solve 2023-08-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;
    Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

int calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw_val(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

int main() {
    FASTIO;

    SETPRECISION(1);

    int n;
    cin >> n;

    vector<Point> convex_hull(n);

    for (Point &p : convex_hull) {
        cin >> p.x >> p.y;
    }

    int ans2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ans2 = max(ans2, -calc_ccw_val(convex_hull[i], convex_hull[j], convex_hull[k]));
            }
        }
    }

    double ans = ans2 * 0.5;

    cout << ans << '\n';

    return 0;
}
