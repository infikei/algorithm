#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

Point points[100000];

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

ll calc_ccw_val(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

int calc_ccw_sign(const Point &a, const Point &b, const Point &c) {
    ll ccw_val = calc_cross(b - a, c - a);

    if (ccw_val > 0) return 1;
    if (ccw_val < 0) return -1;
    return 0;
}

bool check_line_cross(const Point &a, const Point &b, const Point &c, const Point &d) {
    int abc = calc_ccw_sign(a, b, c);
    int abd = calc_ccw_sign(a, b, d);
    int cda = calc_ccw_sign(c, d, a);
    int cdb = calc_ccw_sign(c, d, b);

    if (abc * abd > 0 || cda * cdb > 0) return false;

    if (max(a.x, b.x) < min(c.x, d.x)) return false;
    if (max(c.x, d.x) < min(a.x, b.x)) return false;
    if (max(a.y, b.y) < min(c.y, d.y)) return false;
    if (max(c.y, d.y) < min(a.y, b.y)) return false;

    return true;
}

bool cmp_ccw_x_y(const Point &a, const Point &b) {
    int ccw = calc_ccw_sign(points[0], a, b);

    if (ccw != 0) return ccw > 0;
    return a < b;
}

ll calc_dist2(const Point &a, const Point &b) {
    ll dx = b.x - a.x;
    ll dy = b.y - a.y;
    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    int n;
    n = 100000;

    swap(points[0], *min_element(points, points + n));
    sort(points + 1, points + n, cmp_ccw_x_y);

    vector<Point> convex_hull;

    for (int i = 0; i < n; i++) {
        while (SIZE(convex_hull) >= 2) {
            Point prev = convex_hull.back();
            convex_hull.pop_back();

            if (calc_ccw_sign(convex_hull.back(), prev, points[i]) > 0) {
                convex_hull.push_back(prev);
                break;
            }
        }

        convex_hull.push_back(points[i]);
    }

    return 0;
}
