// Solve 2024-05-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

Point a[1000];
Point b[1000];
Point zero_point;

ll get_ccw(const Point &p1, const Point &p2) {
    return (ll) p1.x * p2.y - (ll) p2.x * p1.y;
}

ll get_ccw(const Point &p1, const Point &p2, const Point &p3) {
    return get_ccw(p2 - p1, p3 - p1);
}

struct PointCmpCcwXY{
    bool operator()(Point &p1, Point &p2) {
        ll ccw = get_ccw(zero_point, p1, p2);

        if (ccw != 0) return ccw > 0;
        return p1 < p2;
    }
};

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i].x >> b[i].y;
    }

    vector<Point> points;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            points.emplace_back(a[i].x + b[j].x, a[i].y + b[j].y);
        }
    }

    swap(points[0], *min_element(points.begin(), points.end()));
    zero_point = points[0];
    sort(points.begin() + 1, points.end(), PointCmpCcwXY());
    vector<Point> convex_hull;

    for (int i = 0; i < SIZE(points); i++) {
        while (SIZE(convex_hull) >= 2) {
            Point back = convex_hull.back();
            convex_hull.pop_back();

            if (get_ccw(convex_hull.back(), back, points[i]) > 0) {
                convex_hull.push_back(back);
                break;
            }
        }

        convex_hull.push_back(points[i]);
    }

    cout << SIZE(convex_hull) << '\n';

    for (Point &p : convex_hull) {
        cout << p.x << ' ' << p.y << '\n';
    }

    return 0;
}
