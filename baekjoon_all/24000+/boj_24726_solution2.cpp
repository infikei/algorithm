// Solve 2023-07-31
// Update 2023-10-11

// 파푸스-굴딘 정리를 이용한 풀이

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
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

int calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw_val(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

int main() {
    FASTIO;

    SETPRECISION(9);

    Point points[3];
    int gx3 = 0, gy3 = 0;

    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;

        points[i] = { x, y };

        gx3 += x;
        gy3 += y;
    }

    int area2 = calc_ccw_val(points[0], points[1], points[2]);
    area2 = abs(area2);

    cout << area2 * PI * gy3 / 3 << ' ';
    cout << area2 * PI * gx3 / 3 << '\n';

    return 0;
}
