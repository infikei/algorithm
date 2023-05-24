// Solve 2023-05-23

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

Point points[100];
vector<Point> convex_hull;

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

ll calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

bool cmp_ccw_y_x(const Point &a, const Point &b) {
    ll ccw = calc_ccw(points[0], a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    return a < b;
}

int main() {
    FASTIO;

    for (int ti = 1;; ti++) {
        int n;
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        swap(points[0], *min_element(points, points + n));
        sort(points + 1, points + n, cmp_ccw_y_x);

        convex_hull.assign(0, Point(0, 0));
        for (int i = 0; i < n; i++) {
            while (SIZE(convex_hull) >= 2) {
                Point back2 = convex_hull.back();
                convex_hull.pop_back();
                Point back1 = convex_hull.back();

                if (calc_ccw(back1, back2, points[i]) > 0) {
                    convex_hull.push_back(back2);
                    break;
                }
            }
            convex_hull.push_back(points[i]);
        }

        double ans = 100000;
        for (int i = 0, j = 1; i < SIZE(convex_hull); i++) {
            int ni = (i + 1) % SIZE(convex_hull);
            Point vi = convex_hull[ni] - convex_hull[i];

            for (;;) {
                int nj = (j + 1) % SIZE(convex_hull);
                Point vj = convex_hull[nj] - convex_hull[j];

                if (calc_ccw(Point(0, 0), vi, vj) <= 0) {
                    break;
                }
                j = nj;
            }

            Point vk = convex_hull[j] - convex_hull[i];
            double val = calc_cross(vi, vk) / sqrt(vi.x * vi.x + vi.y * vi.y);
            if (ans > val) {
                ans = val;
            }
        }

        SETPRECISION(2);
        cout << "Case " << ti << ": " << ceil(ans * 100) / 100 << '\n';
    }

    return 0;
}
