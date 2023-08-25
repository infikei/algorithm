// Solve 2023-08-25

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
};

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

ll calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

int seq[100001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 1; x <= n; x++) {
        cin >> seq[x];

        seq[x] += seq[x - 1];
    }

    vector<Point> convex_hull;
    convex_hull.emplace_back(0, 0);

    for (int x = 1; x <= n; x++) {
        Point cur = { x, seq[x] };

        while (SIZE(convex_hull) >= 2) {
            Point prev = convex_hull.back();
            convex_hull.pop_back();

            if (calc_ccw(convex_hull.back(), prev, cur) < 0) {
                convex_hull.push_back(prev);
                break;
            }
        }

        convex_hull.push_back(cur);
    }

    int idx = 1;
    bool check_if_exist = true;

    for (int x = 1; x < n; x++) {
        if (x >= convex_hull[idx].x) idx++;

        Point a = convex_hull[idx - 1];
        Point b = convex_hull[idx];
        Point c(x, seq[x]);
        Point d(x, seq[x] + 1);

        if (calc_ccw(a, b, c) > 0 || calc_ccw(a, b, d) <= 0) {
            check_if_exist = false;
            break;
        }
    }

    if (check_if_exist) cout << "Not Provable\n";
    else cout << "Provable\n";

    return 0;
}
