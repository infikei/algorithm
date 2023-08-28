// Solve 2023-08-28

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
};

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

int calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw_sign(const Point &a, const Point &b, const Point &c) {
    int ccw_val = calc_cross(b - a, c - a);

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

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        Point line[2];

        for (int i = 0; i < 2; i++) {
            cin >> line[i];
        }

        int x[2], y[2];

        for (int i = 0; i < 2; i++) {
            cin >> x[i] >> y[i];
        }

        if (x[0] > x[1]) swap(x[0], x[1]);
        if (y[0] > y[1]) swap(y[0], y[1]);

        // 직선이 직사각형과 교차하지는 않지만 직사각형의 내부에 있는 경우
        if (x[0] < min(line[0].x, line[1].x) && max(line[0].x, line[1].x) < x[1]) {
            if (y[0] < min(line[0].y, line[1].y) && max(line[0].y, line[1].y) < y[1]) {
                cout << "T\n";
                continue;
            }
        }

        Point rectangle[4] = {
            { x[0], y[0] },
            { x[1], y[0] },
            { x[1], y[1] },
            { x[0], y[1] }
        };

        bool ans = false;

        for (int i = 0; i < 4; i++) {
            int ii = i + 1;
            if (ii == 4) ii = 0;

            if (check_line_cross(line[0], line[1], rectangle[i], rectangle[ii])) {
                ans = true;
                break;
            }
        }

        if (ans) cout << "T\n";
        else cout << "F\n";
    }

    return 0;
}
