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
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y, z - rhs.z };
    }
};

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y >> rhs.z;
}

double calc_inner_product(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double calc_area_of_triangle(const Point &a, const Point &b) {
    double cross_xy = a.x * b.y - b.x * a.y;
    double cross_yz = a.y * b.z - b.y * a.z;
    double cross_zx = a.z * b.x - b.z * a.x;

    return sqrt(cross_xy * cross_xy + cross_yz * cross_yz + cross_zx * cross_zx) * 0.5;
}

double calc_dist(const Point &a, const Point &b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dz = b.z - a.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    FASTIO;

    return 0;
}
