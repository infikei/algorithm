// Solve 2023-03-16
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
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        }
        return y < rhs.y;
    }
    bool operator>(const Point &rhs) const {
        if (x != rhs.x) {
            return x > rhs.x;
        }
        return y > rhs.y;
    }
    bool operator==(const Point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll res = calc_cross(b - a, c - a);
    if (res > 0) return 1;
    else if (res < 0) return -1;
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

    int ans;
    Point ans2;

    if (ccw012 == 0 && ccw013 == 0) {
        // 네 점이 한 직선 위에 있을 경우
        if (pt[0] > pt[1]) swap(pt[0], pt[1]);
        if (pt[2] > pt[3]) swap(pt[2], pt[3]);

        if (pt[0] == pt[3]) {
            ans = 2;
            ans2 = pt[0];
        }
        else if (pt[2] == pt[1]) {
            ans = 2;
            ans2 = pt[1];
        }
        else if (pt[0] < pt[3] && pt[2] < pt[1]) {
            ans = 9;
        }
        else {
            ans = 0;
        }
    }
    else if (ccw012 == 0 || ccw013 == 0) {
        // 세 점이 한 직선 위에 있을 경우
        if (ccw230 == ccw231) {
            ans = 0;
        }
        else {
            ans = 1;
        }
    }
    else if (ccw230 == 0 || ccw231 == 0) {
        // 세 점이 한 직선 위에 있을 경우
        if (ccw012 == ccw013) {
            ans = 0;
        }
        else {
            ans = 1;
        }
    }
    else if (ccw012 + ccw013 == 0 && ccw230 + ccw231 == 0) {
        ans = 1;
    }
    else {
        ans = 0;
    }

    SETPRECISION(12);

    if (ans == 0) {
        cout << 0 << '\n';
    }
    else if (ans == 1) {
        cout << 1 << '\n';

        Point vec01 = pt[0] - pt[1];
        Point vec23 = pt[2] - pt[3];
        ll cross01 = calc_cross(pt[0], pt[1]);
        ll cross23 = calc_cross(pt[2], pt[3]);
        double k = calc_cross(vec01, vec23);
        double xx = (cross01 * vec23.x - cross23 * vec01.x) / k;
        double yy = (cross01 * vec23.y - cross23 * vec01.y) / k;
        cout << xx << ' ' << yy << '\n';
    }
    else if (ans == 2) {
        cout << 1 << '\n';
        cout << ans2.x << ' ' << ans2.y << '\n';
    }
    else if (ans == 9) {
        cout << 1 << '\n';
    }

    return 0;
}
