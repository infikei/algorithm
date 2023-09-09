// Solve 2023-09-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const double PI = M_PI;

struct Point{
    double x, y;
    Point(double nx = 0, double ny = 0) : x(nx), y(ny) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

double calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

double calc_ccw_val(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

double calc_dist(const Point &a, const Point &b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    SETPRECISION(2);

    vector<Point> tri(3);

    while (cin >> tri[0]) {
        cin >> tri[1] >> tri[2];

        double a = calc_dist(tri[0], tri[1]);
        double b = calc_dist(tri[1], tri[2]);
        double c = calc_dist(tri[0], tri[2]);

        double s = abs(calc_ccw_val(tri[0], tri[1], tri[2])) * 0.5;

        double r = a * b * c * 0.25 / s;

        cout << r * 2 * PI << '\n';
    }

    return 0;
}
