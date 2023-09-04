// Solve 2023-09-03

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
};

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw_sign(const Point &a, const Point &b, const Point &c) {
    ll calc_val = calc_cross(b - a, c - a);

    if (calc_val > 0) return 1;
    if (calc_val < 0) return -1;
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
    if (max(c.y, d.y) < min(a.y, b.y)) return false;
    if (max(c.y, d.y) < min(a.y, b.y)) return false;

    return true;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Point> non_convex_hull(n);

    for (int i = 0; i < n; i++) {
        cin >> non_convex_hull[i].x >> non_convex_hull[i].y;
    }

    for (int i = 0; i < 3; i++) {
        vector<Point> long_line(2);

        cin >> long_line[0].x >> long_line[0].y;
        long_line[1].x = 1000000001;
        long_line[1].y = long_line[0].y + 1;

        int ans = 0, cnt = 0;

        for (int j = 0; j < n; j++) {
            int jj = j + 1;
            if (jj == n) jj = 0;

            if (calc_ccw_sign(non_convex_hull[j], non_convex_hull[jj], long_line[0]) == 0) {
                if (min(non_convex_hull[j].x, non_convex_hull[jj].x) <= long_line[0].x && long_line[0].x <= max(non_convex_hull[j].x, non_convex_hull[jj].x)) {
                    if (min(non_convex_hull[j].y, non_convex_hull[jj].y) <= long_line[0].y && long_line[0].y <= max(non_convex_hull[j].y, non_convex_hull[jj].y)) {
                        ans = 1;
                        break;
                    }
                }
            }

            if (check_line_cross(non_convex_hull[j], non_convex_hull[jj], long_line[0], long_line[1])) {
                cnt++;
            }
        }

        if (ans == 0 && cnt % 2 == 1) ans = 1;

        cout << ans << '\n';
    }

    return 0;
}
