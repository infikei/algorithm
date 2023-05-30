// Solve 2023-05-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    ll x, y;
    Point(ll nx = 0, ll ny = 0) : x(nx), y(ny) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        }
        return y < rhs.y;
    }
};

int n;
Point points[100000];

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = calc_cross(b - a, c - a);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

bool cmp_ccw_x_y(const Point &a, const Point &b) {
    int ccw = calc_ccw(points[0], a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    return a < b;
}

ll calc_dist2(const Point &a, const Point &b) {
    ll dx = b.x - a.x;
    ll dy = b.y - a.y;
    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    swap(points[0], *min_element(points, points + n));
    sort(points + 1, points + n, cmp_ccw_x_y);

    vector<Point> convex_hull;
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

    ll max_dist2 = 0;
    for (int i = 0, j = 1; i < SIZE(convex_hull); i++) {
        int ni = i + 1;
        if (ni == SIZE(convex_hull)) ni = 0;
        Point vi = convex_hull[ni] - convex_hull[i];

        for (;;) {
            int nj = j + 1;
            if (nj == SIZE(convex_hull)) nj = 0;
            Point vj = convex_hull[nj] - convex_hull[j];

            if (calc_ccw(Point(0, 0), vi, vj) <= 0) break;
            j = nj;
        }

        ll now_dist2 = calc_dist2(convex_hull[i], convex_hull[j]);
        max_dist2 = max(max_dist2, now_dist2);
    }

    cout << max_dist2 << '\n';

    return 0;
}
