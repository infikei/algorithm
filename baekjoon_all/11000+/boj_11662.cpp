// Solve 2023-03-16
// Update 2023-09-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    double x, y;
    Point(double nx = 0, double ny = 0) : x(nx), y(ny) {}
};

Point a, b, c, d;

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

double calc_dist(double t) {
    Point ab = { (1 - t) * a.x + t * b.x, (1 - t) * a.y + t * b.y };
    Point cd = { (1 - t) * c.x + t * d.x, (1 - t) * c.y + t * d.y };

    double dx = cd.x - ab.x;
    double dy = cd.y - ab.y;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    cin >> a >> b >> c >> d;

    double low = 0, high = 1, mid1, mid2;
    double min_dist = min(calc_dist(low), calc_dist(high));

    while (high - low >= 1e-9) {
        mid1 = (low * 2 + high) / 3;
        mid2 = (low + high * 2) / 3;

        double mid1_dist = calc_dist(mid1);
        double mid2_dist = calc_dist(mid2);

        min_dist = min(min_dist, min(mid1_dist, mid2_dist));

        if (mid1_dist < mid2_dist) high = mid2;
        else low = mid1;
    }

    SETPRECISION(10);

    cout << min_dist << '\n';

    return 0;
}
