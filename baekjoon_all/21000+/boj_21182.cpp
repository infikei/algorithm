// Solve 2023-05-29

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

int n;
Point points[5000], points_r2[5000];

ld calc_dist2(const Point &a, const Point &b) {
    ld dx = b.x - a.x;
    ld dy = b.y - a.y;
    ld dz = b.z - a.z;
    return dx * dx + dy * dy + dz * dz;
}

void gradient_descent(Point& center, ld& radius) {
    radius = 0;
    ld alpha = 0.1;
    for (int iter = 0; iter < 30000; iter++) {
        ld max_dist2 = 0;
        int max_dist2_idx = 0;

        for (int i = 0; i < n; i++) {
            ld now_dist2 = calc_dist2(center, points_r2[i]);
            if (max_dist2 < now_dist2) {
                max_dist2 = now_dist2;
                max_dist2_idx = i;
            }
        }

        center += (points_r2[max_dist2_idx] - center) * alpha;
        alpha *= 0.999;
        radius = max_dist2;
    }
    radius = sqrt(radius);
}

int main() {
    FASTIO;

    cin >> n;

    Point center, center_r2;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
        center += points[i];
    }
    center /= n;

    ld radius, radius_r2;

    // 1.
    for (int i = 0; i < n; i++) {
        points_r2[i] = { points[i].x, points[i].y, 0 };
    }
    center_r2 = { center.x, center.y, 0 };
    radius_r2 = 0;
    gradient_descent(center_r2, radius_r2);
    radius = radius_r2;

    // 2.
    for (int i = 0; i < n; i++) {
        points_r2[i] = { points[i].x, 0, points[i].z };
    }
    center_r2 = { center.x, 0, center.z };
    radius_r2 = 0;
    gradient_descent(center_r2, radius_r2);
    radius = min(radius, radius_r2);

    // 3.
    for (int i = 0; i < n; i++) {
        points_r2[i] = { 0, points[i].y, points[i].z };
    }
    center_r2 = { 0, center.y, center.z };
    radius_r2 = 0;
    gradient_descent(center_r2, radius_r2);
    radius = min(radius, radius_r2);

    // 1, 2, 3에서 구한 반지름 중 최소를 구한다. 다만 지름을 구하는 문제이므로 구한 값의 2배를 출력한다.
    SETPRECISION(9);
    cout << radius * 2 << '\n';

    return 0;
}
