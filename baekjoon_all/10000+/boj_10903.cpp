// Solve 2024-05-02

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

Point points[1000];

int get_cross(Point p1, Point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

int get_ccw(Point p1, Point p2, Point p3) {
    return get_cross(p2 - p1, p3 - p1);
}

bool cmp_ccw_x_y(Point p1, Point p2) {
    int ccw = get_ccw(points[0], p1, p2);

    if (ccw != 0) return ccw > 0;
    return p1 < p2;
}

double get_dist(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    int n, r;
    cin >> n >> r;

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

            if (get_ccw(convex_hull.back(), back, points[i]) > 0) {
                convex_hull.push_back(back);
                break;
            }
        }

        convex_hull.push_back(points[i]);
    }

    double ans = M_PI * 2 * r + get_dist(convex_hull[0], convex_hull.back());

    for (int i = 1; i < SIZE(convex_hull); i++) {
        ans += get_dist(convex_hull[i - 1], convex_hull[i]);
    }

    SETPRECISION(12);

    cout << ans << '\n';

    return 0;
}
