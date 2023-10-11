// Solve 2023-07-31
// Update 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const double PI = M_PI;

struct Point{
    int x, y;
    Point(int nx = 0, int ny = 0) : x(nx), y(ny) {}
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

vector<Point> points(3);

istream& operator>>(istream &is, Point &rhs) {
    is >> rhs.x >> rhs.y;
    return is;
}

ll calc_vol(const Point &p1, const Point &p2) {
    return (p2.x - p1.x) * (ll)(p2.y * p2.y + p2.y * p1.y + p1.y * p1.y);
}

double calc_volume() {
    sort(points.begin(), points.end());

    if (points[0].x == points[1].x) {
        ll v12 = calc_vol(points[1], points[2]);
        ll v02 = calc_vol(points[0], points[2]);

        return abs(v12 - v02) * PI / 3;
    }
    else if (points[1].x == points[2].x) {
        ll v02 = calc_vol(points[0], points[2]);
        ll v01 = calc_vol(points[0], points[1]);

        return abs(v02 - v01) * PI / 3;
    }
    else {
        ll v01 = calc_vol(points[0], points[1]);
        ll v12 = calc_vol(points[1], points[2]);
        ll v02 = calc_vol(points[0], points[2]);

        return abs(v01 + v12 - v02) * PI / 3;
    }
}

int main() {
    FASTIO;

    SETPRECISION(9);

    for (int i = 0; i < 3; i++) {
        cin >> points[i];
    }

    cout << calc_volume() << ' ';

    for (int i = 0; i < 3; i++) {
        swap(points[i].x, points[i].y);
    }

    cout << calc_volume() << '\n';

    return 0;
}
