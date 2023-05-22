// Solve 2023-05-22

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

struct Point{
    ll x, y;
    Point(ll nx = 0, ll ny = 0) : x(nx), y(ny) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
    bool operator<(const Point &rhs) const {
        if (y != rhs.y) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};

Point points[10000];
vector<Point> convex_hull;

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

ll calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

bool cmp_ccw_y_x(const Point &a, const Point &b) {
    ll ccw = calc_ccw(points[0], a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    return a < b;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    swap(points[0], *min_element(points, points + n));
    sort(points + 1, points + n, cmp_ccw_y_x);

    for (int i = 0; i < n; i++) {
        while (SIZE(convex_hull) >= 2) {
            Point back2 = convex_hull.back();
            convex_hull.pop_back();
            Point back1 = convex_hull.back();

            if (calc_ccw(back1, back2, points[i]) > 0) {
                convex_hull.push_back(back2);
                break;
            }
        }
        convex_hull.push_back(points[i]);
    }

    ll ans = 0;
    for (int i = 2; i < SIZE(convex_hull); i++) {
        ans += calc_ccw(convex_hull[0], convex_hull[i - 1], convex_hull[i]);
    }
    cout << ans / 100 << '\n';

    return 0;
}
