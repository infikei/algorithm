// Solve 2023-05-29
// Update 2024-05-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
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
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

Point points[100000];

ll get_cross(Point p1, Point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

int get_ccw_sign(Point p1, Point p2, Point p3) {
    ll ccw = get_cross(p2 - p1, p3 - p1);

    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

bool cmp_ccw_x_y(Point p1, Point p2) {
    int ccw_sign = get_ccw_sign(points[0], p1, p2);

    if (ccw_sign != 0) return ccw_sign > 0;
    return p1 < p2;
}

ll get_dist2(Point p1, Point p2) {
    ll dx = p1.x - p2.x;
    ll dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    swap(points[0], *min_element(points, points + n));
    sort(points + 1, points + n, cmp_ccw_x_y);
    vector<Point> convex_hull;

    for (int i = 0; i < n; i++) {
        while (SIZE(convex_hull) >= 2) {
            Point back = convex_hull.back();
            convex_hull.pop_back();

            if (get_ccw_sign(convex_hull.back(), back, points[i]) > 0) {
                convex_hull.push_back(back);
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

            if (get_ccw_sign(Point(0, 0), vi, vj) <= 0) break;
            j = nj;
        }

        ll now_dist2 = get_dist2(convex_hull[i], convex_hull[j]);
        max_dist2 = max(max_dist2, now_dist2);
    }

    cout << max_dist2 << '\n';

    return 0;
}
