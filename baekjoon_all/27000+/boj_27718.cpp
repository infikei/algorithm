// Solve 2023-05-15

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

Point lines[2000][2];
int ans[2000][2000];

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = calc_cross(b - a, c - a);
    if (ccw > 0) return 1;
    else if (ccw < 0) return -1;
    else return 0;
}

int intersects(const Point &a, const Point &b, const Point &c, const Point &d) {
    int ccw_abc = calc_ccw(a, b, c);
    int ccw_abd = calc_ccw(a, b, d);
    int ccw_cda = calc_ccw(c, d, a);
    int ccw_cdb = calc_ccw(c, d, b);

    if (ccw_abc == 0 && ccw_abd == 0) {
        // 네 점이 한 직선 위에 있을 경우
        if (b < c || d < a) {
            return 0;
        }
        if (b == c || d == a) {
            return 1;
        }
        return 3;
    }
    if (ccw_abc == 0 || ccw_abd == 0) {
        // 세 점이 한 직선 위에 있을 경우
        if (ccw_cda == ccw_cdb) {
            return 0;
        }
        return 1;
    }
    if (ccw_cda == 0 || ccw_cdb == 0) {
        // 세 점이 한 직선 위에 있을 경우
        if (ccw_abc == ccw_abd) {
            return 0;
        }
        return 1;
    }
    if (ccw_abc + ccw_abd == 0 && ccw_cda + ccw_cdb == 0) {
        return 2;
    }
    return 0;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> lines[i][0].x >> lines[i][0].y >> lines[i][1].x >> lines[i][1].y;
        if (lines[i][0] > lines[i][1]) {
            swap(lines[i][0], lines[i][1]);
        }
    }

    for (int i = 0; i < n; i++) {
        ans[i][i] = 3;
        for (int j = 0; j < i; j++) {
            int res = intersects(lines[j][0], lines[j][1], lines[i][0], lines[i][1]);
            ans[j][i] = ans[i][j] = res;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
