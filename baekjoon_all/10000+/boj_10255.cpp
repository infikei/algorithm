// Solve 2023-05-18
// Update 2023-12-15

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

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = calc_cross(b - a, c - a);

    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

int check_line_cross(const Point &a, const Point &b, const Point &c, const Point &d) {
    int ccw_abc = calc_ccw(a, b, c), ccw_abd = calc_ccw(a, b, d);
    int ccw_cda = calc_ccw(c, d, a), ccw_cdb = calc_ccw(c, d, b);

    if (ccw_abc * ccw_abd > 0 || ccw_cda * ccw_cdb > 0) return 0;
    if (max(a.x, b.x) < min(c.x, d.x)) return 0;
    if (max(c.x, d.x) < min(a.x, b.x)) return 0;
    if (max(a.y, b.y) < min(c.y, d.y)) return 0;
    if (max(c.y, d.y) < min(a.y, b.y)) return 0;
    return 1;
}

void solve() {
    Point square_min, square_max, line_min, line_max;
    cin >> square_min >> square_max >> line_min >> line_max;

    if (line_max < line_min) swap(line_min, line_max);

    int ans = 0;

    // 선분이 y축에 평행할 경우
    if (line_min.x == line_max.x) {
        if (line_min.x < square_min.x || square_max.x < line_min.x) {
            ans = 0;
        }
        else if (line_max.y < square_min.y || square_max.y < line_min.y) {
            ans = 0;
        }
        else if (line_min.x == square_min.x || line_min.x == square_max.x) {
            if (line_max.y == square_min.y || square_max.y == line_min.y) {
                ans = 1;
            }
            else {
                ans = 4;
            }
        }
        else {
            if (line_min.y <= square_min.y && square_min.y <= line_max.y) {
                ans++;
            }
            if (line_min.y <= square_max.y && square_max.y <= line_max.y) {
                ans++;
            }
        }
    }
    // 선분이 x축에 평행할 경우
    else if (line_min.y == line_max.y) {
        if (line_min.y < square_min.y || square_max.y < line_min.y) {
            ans = 0;
        }
        else if (line_max.x < square_min.x || square_max.x < line_min.x) {
            ans = 0;
        }
        else if (line_min.y == square_min.y || line_min.y == square_max.y) {
            if (line_max.x == square_min.x || square_max.x == line_min.x) {
                ans = 1;
            }
            else {
                ans = 4;
            }
        }
        else {
            if (line_min.x <= square_min.x && square_min.x <= line_max.x) {
                ans++;
            }
            if (line_min.x <= square_max.x && square_max.x <= line_max.x) {
                ans++;
            }
        }
    }
    else {
        Point square_maxmin = { square_max.x, square_min.y };
        Point square_minmax = { square_min.x, square_max.y };

        ans += check_line_cross(line_min, line_max, square_min, square_maxmin);
        ans += check_line_cross(line_min, line_max, square_maxmin, square_max);
        ans += check_line_cross(line_min, line_max, square_max, square_minmax);
        ans += check_line_cross(line_min, line_max, square_minmax, square_min);

        if (line_min.x <= square_min.x && square_min.x <= line_max.x \
            && calc_ccw(line_min, line_max, square_min) == 0) {
            ans--;
        }
        if (line_min.x <= square_maxmin.x && square_maxmin.x <= line_max.x \
            && calc_ccw(line_min, line_max, square_maxmin) == 0) {
            ans--;
        }
        if (line_min.x <= square_max.x && square_max.x <= line_max.x \
            && calc_ccw(line_min, line_max, square_max) == 0) {
            ans--;
        }
        if (line_min.x <= square_minmax.x && square_minmax.x <= line_max.x \
            && calc_ccw(line_min, line_max, square_minmax) == 0) {
            ans--;
        }
    }

    cout << ans << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        solve();
    }

    return 0;
}
