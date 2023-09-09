// Solve 2023-03-16
// Update 2023-09-09

// 이분탐색 풀이

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
    Point operator+(const Point &rhs) const {
        return { x + rhs.x, y + rhs.y, z + rhs.z };
    }
    Point operator*(const double &rhs) const {
        return { x * rhs, y * rhs, z * rhs };
    }
};

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y >> rhs.z;
}

double calc_dist(const Point &a, const Point &b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dz = b.z - a.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    FASTIO;

    Point a, b, c;
    cin >> a >> b >> c;

    Point low = a, high = b;
    double ans = min(calc_dist(a, c), calc_dist(b, c));

    while (true) {
        Point mid = (low + high) * 0.5;

        double low_val = calc_dist(low, c);
        double mid_val = calc_dist(mid, c);
        double high_val = calc_dist(high, c);

        if (abs(ans - mid_val) < 1e-12) break;

        if (mid_val < ans) ans = mid_val;

        if (low_val < high_val) high = mid;
        else low = mid;
    }

    SETPRECISION(10);

    cout << ans << '\n';

    return 0;
}
