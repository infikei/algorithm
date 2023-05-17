// Solve 2023-05-16

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

Point cmp_point0;

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = calc_cross(b - a, c - a);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

bool cmp_ccw_y_x(const Point &a, const Point &b) {
    int ccw = calc_ccw(cmp_point0, a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    return a < b;
}

bool check_cross(const Point &a, const Point &b, const Point &c, const Point &d) {
    int ccw_abc = calc_ccw(a, b, c), ccw_abd = calc_ccw(a, b, d);
    int ccw_cda = calc_ccw(c, d, a), ccw_cdb = calc_ccw(c, d, b);

    if (ccw_abc * ccw_abd > 0 || ccw_cda * ccw_cdb > 0) {
        return false;
    }
    if (max(a.x, b.x) < min(c.x, d.x)) return false;
    if (max(c.x, d.x) < min(a.x, b.x)) return false;
    if (max(a.y, b.y) < min(c.y, d.y)) return false;
    if (max(c.y, d.y) < min(a.y, b.y)) return false;
    return true;
}

bool check_inner(const Point &pt, const vector<Point> &convex_hull) {
    for (int j = 0; j < SIZE(convex_hull); j++) {
        int nj = (j + 1) % SIZE(convex_hull);
        if (calc_ccw(convex_hull[j], convex_hull[nj], pt) <= 0) {
            return false;
        }
    }
    return true;
}

void make_convex_hull(vector<Point> &points, vector<Point> &convex_hull) {
    sort(points.begin(), points.end());
    cmp_point0 = points[0];
    sort(points.begin() + 1, points.end(), cmp_ccw_y_x);

    for (auto &pt : points) {
        while (SIZE(convex_hull) >= 2) {
            Point back2 = convex_hull.back();
            convex_hull.pop_back();
            Point back1 = convex_hull.back();

            if (calc_ccw(back1, back2, pt) > 0) {
                convex_hull.push_back(back2);
                break;
            }
        }
        convex_hull.push_back(pt);
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, m;
        cin >> n >> m;

        vector<Point> black_points(n), white_points(m);
        for (int i = 0; i < n; i++) {
            cin >> black_points[i].x >> black_points[i].y;
        }
        for (int i = 0; i < m; i++) {
            cin >> white_points[i].x >> white_points[i].y;
        }

        // 볼록다각형 만들기
        vector<Point> black_convex_hull, white_convex_hull;
        make_convex_hull(black_points, black_convex_hull);
        make_convex_hull(white_points, white_convex_hull);

        // 두 개의 볼록다각형이 서로 교차하는지 검사
        bool ans = true;
        for (int i = 0; i < SIZE(black_convex_hull); i++) {
            int ni = (i + 1) % SIZE(black_convex_hull);
            for (int j = 0; j < SIZE(white_convex_hull); j++) {
                int nj = (j + 1) % SIZE(white_convex_hull);
                if (check_cross(black_convex_hull[i], black_convex_hull[ni], white_convex_hull[j], white_convex_hull[nj])) {
                    ans = false;
                    break;
                }
            }
            if (!ans) {
                break;
            }
        }

        // 두 개의 볼록다각형이 서로 교차하지 않을 때, 볼록다각형이 다른 볼록다각형의 내부에 있는지 검사
        if (ans && SIZE(black_convex_hull) >= 3) {
            for (auto &pt : white_convex_hull) {
                if (check_inner(pt, black_convex_hull)) {
                    ans = false;
                    break;
                }
            }
        }
        if (ans && SIZE(white_convex_hull) >= 3) {
            for (auto &pt : black_convex_hull) {
                if (check_inner(pt, white_convex_hull)) {
                    ans = false;
                    break;
                }
            }
        }

        // 결과 출력
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
