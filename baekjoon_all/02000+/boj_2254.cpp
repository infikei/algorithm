// Solve 2023-05-19

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

set<Point> points_set;
vector<Point> points_vec;
Point p;
int n, ans;

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
    int ccw = calc_ccw(points_vec[0], a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    return a < b;
}

int main() {
    FASTIO;

    cin >> n >> p.x >> p.y;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points_set.emplace(x, y);
    }

    while (true) {
        if (SIZE(points_set) < 3) break;

        points_vec.assign(points_set.begin(), points_set.end());
        swap(points_vec[0], *min_element(points_vec.begin(), points_vec.end()));
        sort(points_vec.begin() + 1, points_vec.end(), cmp_ccw_y_x);

        vector<Point> convex_hull;
        for (auto &pt : points_vec) {
            while (SIZE(convex_hull) >= 2) {
                Point back2 = convex_hull.back();
                convex_hull.pop_back();
                Point back1 = convex_hull.back();

                if (calc_ccw(back1, back2, pt) >= 0) {
                    convex_hull.push_back(back2);
                    break;
                }
            }
            convex_hull.push_back(pt);
        }

        bool is_valid = true;
        for (int i = 0; i < SIZE(convex_hull); i++) {
            int ni = (i + 1) % SIZE(convex_hull);
            if (calc_ccw(convex_hull[i], convex_hull[ni], p) <= 0) {
                is_valid = false;
                break;
            }
        }
        if (!is_valid) break;
        ans++;

        for (auto &pt : convex_hull) {
            points_set.erase(points_set.find(pt));
        }
    }

    cout << ans << '\n';

    return 0;
}
