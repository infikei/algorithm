// Solve 2023-05-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using ld = long double;

struct Point{
    ld x, y;
    Point(ld nx = 0, ld ny = 0) : x(nx), y(ny) {}
    Point operator+(const Point &rhs) const {
        return { x + rhs.x, y + rhs.y };
    }
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
    Point operator/(const ld &rhs) const {
        return { x / rhs, y / rhs };
    }
};

Point points[3], ans;
ld dist2[3];

ld calc_dist2(const Point &a, const Point &b) {
    ld dx = b.x - a.x;
    ld dy = b.y - a.y;
    return dx * dx + dy * dy;
}

Point get_circumcenter(const Point &a, const Point &b, const Point &c) {
    // 외심 구하는 함수
    ld x2x1 = b.x - a.x, x3x2 = c.x - b.x;
    ld y2y1 = b.y - a.y, y3y2 = c.y - b.y;
    ld x22x12 = b.x * b.x - a.x * a.x, x32x22 = c.x * c.x - b.x * b.x;
    ld y22y12 = b.y * b.y - a.y * a.y, y32y22 = c.y * c.y - b.y * b.y;

    ld nx = ((x22x12 + y22y12) * y3y2 - (x32x22 + y32y22) * y2y1) / (2 * x2x1 * y3y2 - 2 * x3x2 * y2y1);
    ld ny = ((y22y12 + x22x12) * x3x2 - (y32y22 + x32x22) * x2x1) / (2 * y2y1 * x3x2 - 2 * y3y2 * x2x1);

    return { nx, ny };
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        for (int i = 0; i < 3; i++) {
            cin >> points[i].x >> points[i].y;
        }

        for (int i = 0; i < 3; i++) {
            int ni = i + 1;
            if (ni == 3) ni = 0;
            dist2[i] = calc_dist2(points[i], points[ni]);
        }

        if (dist2[0] + dist2[1] <= dist2[2]) {
            // 직각삼각형 또는 둔각삼각형 -> 2번째 점과 0번째 점의 중점이 답이다.
            ans = (points[2] + points[0]) / 2;
        }
        else if (dist2[1] + dist2[2] <= dist2[0]) {
            // 직각삼각형 또는 둔각삼각형 -> 0번째 점과 1번째 점의 중점이 답이다.
            ans = (points[0] + points[1]) / 2;
        }
        else if (dist2[2] + dist2[0] <= dist2[1]) {
            // 직각삼각형 또는 둔각삼각형 -> 1번째 점과 2번째 점의 중점이 답이다.
            ans = (points[1] + points[2]) / 2;
        }
        else {
            // 예각삼각형 -> 외심이 답이다.
            ans = get_circumcenter(points[0], points[1], points[2]);
        }

        SETPRECISION(2);
        cout << "Case #" << ti << ": " << ans.x << ' ' << ans.y << '\n';
    }

    return 0;
}
