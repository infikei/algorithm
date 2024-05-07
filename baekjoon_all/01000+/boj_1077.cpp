// Solve 2024-05-03
// Update 2024-05-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

Point zero_point(0, 0);

double get_ccw(const Point &p1, const Point &p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

double get_ccw(const Point &p1, const Point &p2, const Point &p3) {
    return get_ccw(p2 - p1, p3 - p1);
}

int get_ccw_sign(const Point &p1, const Point &p2, const Point &p3) {
    double ccw = get_ccw(p1, p2, p3);

    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

struct PointCmpCcwXY{
    bool operator()(Point &p1, Point &p2) {
        double ccw = get_ccw(zero_point, p1, p2);

        if (ccw != 0) return ccw > 0;
        return p1 < p2;
    }
};

vector<Point> make_convex_hull(vector<Point> &points) {
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

    return convex_hull;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<Point> ch1;
    vector<Point> ch2;

    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        ch1.emplace_back(x, y);
    }

    for (int j = 0; j < m; j++) {
        double x, y;
        cin >> x >> y;
        ch2.emplace_back(x, y);
    }

    ch1 = make_convex_hull(ch1);
    ch2 = make_convex_hull(ch2);
    n = SIZE(ch1);
    m = SIZE(ch2);
    vector<Point> ch3;

    for (int i = 0; i < n; i++) {
        bool in_convex_hull = true;

        for (int j = 1; j < m; j++) {
            if (get_ccw(ch2[j - 1], ch2[j], ch1[i]) < 0) {
                in_convex_hull = false;
                break;
            }
        }

        if (get_ccw(ch2[m - 1], ch2[0], ch1[i]) < 0) {
            in_convex_hull = false;
        }

        if (in_convex_hull) {
            ch3.push_back(ch1[i]);
        }
    }

    for (int j = 0; j < m; j++) {
        bool in_convex_hull = true;

        for (int i = 1; i < n; i++) {
            if (get_ccw(ch1[i - 1], ch1[i], ch2[j]) < 0) {
                in_convex_hull = false;
                break;
            }
        }

        if (get_ccw(ch1[n - 1], ch1[0], ch2[j]) < 0) {
            in_convex_hull = false;
        }

        if (in_convex_hull) {
            ch3.push_back(ch2[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int ni = i + 1;
        if (ni == n) ni = 0;

        for (int j = 0; j < m; j++) {
            int nj = j + 1;
            if (nj == m) nj = 0;

            int abc = get_ccw_sign(ch1[i], ch1[ni], ch2[j]);
            int abd = get_ccw_sign(ch1[i], ch1[ni], ch2[nj]);
            int cda = get_ccw_sign(ch2[j], ch2[nj], ch1[i]);
            int cdb = get_ccw_sign(ch2[j], ch2[nj], ch1[ni]);

            if (abc * abd == -1 && cda * cdb == -1) {
                Point v1 = ch1[i] - ch1[ni];
                Point v2 = ch2[j] - ch2[nj];
                double c1 = get_ccw(ch1[i], ch1[ni]);
                double c2 = get_ccw(ch2[j], ch2[nj]);
                double k = get_ccw(v1, v2);
                double x = (c1 * v2.x - c2 * v1.x) / k;
                double y = (c1 * v2.y - c2 * v1.y) / k;

                ch3.emplace_back(x, y);
            }
        }
    }

    double ans = 0;

    if (!ch3.empty()) {
        ch3 = make_convex_hull(ch3);

        for (int i = 2; i < SIZE(ch3); i++) {
            ans += get_ccw(ch3[0], ch3[i - 1], ch3[i]);
        }

        ans *= 0.5;
    }

    SETPRECISION(12);

    cout << ans << '\n';

    return 0;
}
