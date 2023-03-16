// Solve 2023-03-16

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
using pll = pair<ll, ll>;

pll pt[4];

inline int ccw(pll p0, pll p1, pll p2) {
    ll res = (p1.first - p0.first) * (p2.second - p0.second) - (p2.first - p0.first) * (p1.second - p0.second);

    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}

int two_lines_intersect() {
    int ccw012 = ccw(pt[0], pt[1], pt[2]);
    int ccw013 = ccw(pt[0], pt[1], pt[3]);
    int ccw230 = ccw(pt[2], pt[3], pt[0]);
    int ccw231 = ccw(pt[2], pt[3], pt[1]);

    if (ccw012 == 0 && ccw013 == 0) {
        // 네 점이 한 직선 위에 있을 경우
        if (pt[0] > pt[1]) swap(pt[0], pt[1]);
        if (pt[2] > pt[3]) swap(pt[2], pt[3]);

        if (pt[0] == pt[3]) {
            return 10;
        }
        if (pt[2] == pt[1]) {
            return 11;
        }
        if (pt[0] < pt[3] && pt[2] < pt[1]) {
            return 19;
        }
        return 0;
    }

    if (ccw012 == 0 || ccw013 == 0) {
        // 세 점이 한 직선 위에 있을 경우
        if (ccw230 == ccw231) {
            return 0;
        }
        return 1;
    }

    if (ccw230 == 0 || ccw231 == 0) {
        // 세 점이 한 직선 위에 있을 경우
        if (ccw012 == ccw013) {
            return 0;
        }
        return 1;
    }

    if (ccw012 + ccw013 == 0 && ccw230 + ccw231 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    FASTIO;

    for (int i = 0; i < 4; i++) {
        cin >> pt[i].first >> pt[i].second;
    }

    int res = two_lines_intersect();
    SETPRECISION(12);

    if (res == 0) {
        cout << 0 << '\n';
    }
    else if (res == 1) {
        cout << 1 << '\n';

        ll x0x1 = pt[0].first - pt[1].first;
        ll x2x3 = pt[2].first - pt[3].first;
        ll y0y1 = pt[0].second - pt[1].second;
        ll y2y3 = pt[2].second - pt[3].second;
        ll a0 = pt[0].first * pt[1].second - pt[1].first * pt[0].second;
        ll a1 = pt[2].first * pt[3].second - pt[3].first * pt[2].second;
        double p = x0x1 * y2y3 - x2x3 * y0y1;
        double px = (a0 * x2x3 - x0x1 * a1) / p;
        double py = (a0 * y2y3 - y0y1 * a1) / p;
        cout << px << ' ' << py << '\n';
    }
    else if (res == 10) {
        cout << 1 << '\n';
        cout << pt[0].first << ' ' << pt[0].second << '\n';
    }
    else if (res == 11) {
        cout << 1 << '\n';
        cout << pt[1].first << ' ' << pt[1].second << '\n';
    }
    else if (res == 19) {
        cout << 1 << '\n';
    }

    return 0;
}
