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

int n;
Point points[50000];

int get_ccw(const Point &p1, const Point &p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

int get_ccw(const Point &p1, const Point &p2, const Point &p3) {
    return get_ccw(p2 - p1, p3 - p1);
}

struct PointCmpXY{
    bool operator()(Point &p1, Point &p2) {
        int ccw = get_ccw(points[0], p1, p2);

        if (ccw != 0) return ccw > 0;
        return p1 < p2;
    }
};

int get_dist2(const Point &p1, const Point &p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    swap(points[0], *min_element(points, points + n));
    sort(points + 1, points + n, PointCmpXY());
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

    int max_dist2 = 0;

    for (int i = 0, j = 1; i < SIZE(convex_hull); i++) {
        int ni = i + 1;
        if (ni == SIZE(convex_hull)) ni = 0;
        Point vi = convex_hull[ni] - convex_hull[i];

        while (true) {
            int nj = j + 1;
            if (nj == SIZE(convex_hull)) nj = 0;
            Point vj = convex_hull[nj] - convex_hull[j];

            if (get_ccw(Point(0, 0), vi, vj) <= 0) break;
            j = nj;
        }

        int cur_dist2 = get_dist2(convex_hull[i], convex_hull[j]);
        max_dist2 = cur_dist2 > max_dist2 ? cur_dist2 : max_dist2;
    }

    cout << max_dist2 << '\n';

    return 0;
}
