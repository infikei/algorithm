// Solve 2023-03-16
// Update 2023-09-09

// 삼분탐색 풀이

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    double x, y, z;
    Point(double nx = 0, double ny = 0, double nz = 0) : x(nx), y(ny), z(nz) {}
};

Point a, b, c;

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y >> rhs.z;
}

double calc_dist(double t) {
    Point ab = {
        (1 - t) * a.x + t * b.x,
        (1 - t) * a.y + t * b.y,
        (1 - t) * a.z + t * b.z
    };

    double dx = c.x - ab.x;
    double dy = c.y - ab.y;
    double dz = c.z - ab.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    FASTIO;

    cin >> a >> b >> c;

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
