// Solve 2023-03-13
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

    Point(ll x = 0, ll y = 0) : x(x), y(y) {}

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
};

int main() {
    FASTIO;
    SETPRECISION(1);

    int n;
    cin >> n;

    Point polygon[3];
    ll two_times_area = 0;

    cin >> polygon[0].x >> polygon[0].y;
    cin >> polygon[1].x >> polygon[1].y;

    for (int i = 2; i < n; i++) {
        cin >> polygon[2].x >> polygon[2].y;

        two_times_area += polygon[0].get_ccw(polygon[1], polygon[2]);
        polygon[1] = polygon[2];
    }

    double area = abs(two_times_area) * 0.5;
    cout << area << '\n';

    return 0;
}
