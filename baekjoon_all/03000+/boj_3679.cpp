// Solve 2023-05-16

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
    int idx = 0;
    Point(ll nx = 0, ll ny = 0) : x(nx), y(ny) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
    bool operator<(const Point &rhs) const {
        if (y != rhs.y) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};

Point points[2000];

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = calc_cross(b - a, c - a);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

ll calc_dist2(const Point &a, const Point &b) {
    ll dx = b.x - a.x;
    ll dy = b.y - a.y;
    return dx * dx + dy * dy;
}

bool cmp_ccw_dist2(const Point &a, const Point &b) {
    int ccw = calc_ccw(points[0], a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    ll a_dist2 = calc_dist2(points[0], a), b_dist2 = calc_dist2(points[0], b);
    return a_dist2 < b_dist2;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
            points[i].idx = i;
        }

        swap(points[0], *min_element(points, points + n));
        sort(points + 1, points + n, cmp_ccw_dist2);

        int k = n - 1;
        while (k > 0) {
            if (calc_ccw(points[0], points[k], points[k - 1]) == 0) {
                k--;
            }
            else break;
        }
        reverse(points + k, points + n);

        for (int i = 0; i < n; i++) {
            cout << points[i].idx << ' ';
        }
        cout << '\n';
    }

    return 0;
}
