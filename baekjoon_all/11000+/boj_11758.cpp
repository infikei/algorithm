// Solve 2022-07-13
// Update 2024-02-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    ll x, y;

    Point() {}

    Point(ll x, ll y) : x(x), y(y) {}

    Point operator-(const Point &p) const {
        return { x - p.x, y - p.y };
    }

    ll get_cross(const Point &p) {
        return x * p.y - p.x * y;
    }

    ll get_ccw(const Point &p1, const Point &p2) {
        Point v1 = p1 - *this;
        Point v2 = p2 - *this;
        return v1.get_cross(v2);
    }

    int get_ccw_sign(const Point &p1, const Point &p2) {
        ll ccw = get_ccw(p1, p2);

        if (ccw > 0) return 1;
        if (ccw < 0) return -1;
        return 0;
    }
};

int main() {
    FASTIO;

    Point points[3];

    for (int i = 0; i < 3; i++) {
        cin >> points[i].x >> points[i].y;
    }

    cout << points[0].get_ccw_sign(points[1], points[2]) << '\n';

    return 0;
}
