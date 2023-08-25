// Solve 2023-08-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

int calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

int main() {
    FASTIO;

    Point triangle[3];

    for (int i = 0; i < 3; i++) {
        cin >> triangle[i];
    }

    int area2 = calc_ccw(triangle[0], triangle[1], triangle[2]);

    if (area2 < 0) {
        area2 = -area2;
        swap(triangle[1], triangle[2]);
    }

    double area = (double)area2 / 2;

    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p;

        int flag = true;

        for (int j = 0; j < 3; j++) {
            if (calc_ccw(triangle[j], triangle[(j + 1) % 3], p) < 0) {
                flag = false;
                break;
            }
        }

        if (flag) cnt++;
    }

    SETPRECISION(1);

    cout << area << '\n' << cnt << '\n';

    return 0;
}
