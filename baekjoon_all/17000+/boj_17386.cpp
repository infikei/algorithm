// Solve 2022-09-05
// Update 2023-05-15

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

struct Point{
    ll x, y;
    Point(ll nx = 0, ll ny = 0) : x(nx), y(ny) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = calc_cross(b - a, c - a);
    if (ccw > 0) return 1;
    else if (ccw < 0) return -1;
    else return 0;
}

int main() {
    FASTIO;

    Point pt[4];
    for (int i = 0; i < 4; i++) {
        cin >> pt[i].x >> pt[i].y;
    }

    int ccw012 = calc_ccw(pt[0], pt[1], pt[2]);
    int ccw013 = calc_ccw(pt[0], pt[1], pt[3]);
    int ccw230 = calc_ccw(pt[2], pt[3], pt[0]);
    int ccw231 = calc_ccw(pt[2], pt[3], pt[1]);

    if (ccw012 + ccw013 == 0 && ccw230 + ccw231 == 0) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
