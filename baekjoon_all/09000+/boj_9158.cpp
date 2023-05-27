// Solve 2023-05-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using ld = long double;

struct Point{
    ld x, y, z;
    Point(ld nx = 0, ld ny = 0, ld nz = 0) : x(nx), y(ny), z(nz) {}
    Point operator+(const Point &rhs) const {
        return { x + rhs.x, y + rhs.y, z + rhs.z };
    }
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y, z - rhs.z };
    }
    Point operator*(const ld &rhs) const {
        return { x * rhs, y * rhs, z * rhs };
    }
    Point operator/(const ld &rhs) const {
        return { x / rhs, y / rhs, z / rhs };
    }
    Point& operator+=(const Point &rhs) {
        (*this) = (*this) + rhs;
        return *this;
    }
    Point& operator/=(const ld &rhs) {
        (*this) = (*this) / rhs;
        return *this;
    }
};

Point stars[30];

ld calc_dist2(const Point &a, const Point &b) {
    ld dx = b.x - a.x;
    ld dy = b.y - a.y;
    ld dz = b.z - a.z;
    return dx * dx + dy * dy + dz * dz;
}

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        Point center;
        for (int i = 0; i < n; i++) {
            cin >> stars[i].x >> stars[i].y >> stars[i].z;
            center += stars[i];
        }
        center /= n;

        ld alpha = 0.1;
        ld radius = 0;
        for (int iter = 0; iter < 30000; iter++) {
            ld max_dist2 = 0;
            int max_dist2_idx = 0;

            for (int i = 0; i < n; i++) {
                ld now_dist2 = calc_dist2(center, stars[i]);
                if (max_dist2 < now_dist2) {
                    max_dist2 = now_dist2;
                    max_dist2_idx = i;
                }
            }

            center += (stars[max_dist2_idx] - center) * alpha;
            alpha *= 0.999;
            radius = max_dist2;
        }
        radius = sqrt(radius);

        SETPRECISION(5);
        cout << radius << '\n';
    }

    return 0;
}
