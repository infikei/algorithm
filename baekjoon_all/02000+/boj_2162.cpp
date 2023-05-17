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

struct Line{
    Point p1, p2;
};

int n, parent[3001], ans, ans2;
Line lines[3001];

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = calc_cross(b - a, c - a);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

bool check_line_cross(const Line &line1, const Line &line2) {
    int ccw_abc = calc_ccw(line1.p1, line1.p2, line2.p1);
    int ccw_abd = calc_ccw(line1.p1, line1.p2, line2.p2);
    int ccw_cda = calc_ccw(line2.p1, line2.p2, line1.p1);
    int ccw_cdb = calc_ccw(line2.p1, line2.p2, line1.p2);

    if (ccw_abc * ccw_abd > 0 || ccw_cda * ccw_cdb > 0) {
        return false;
    }
    if (max(line1.p1.x, line1.p2.x) < min(line2.p1.x, line2.p2.x)) return false;
    if (max(line2.p1.x, line2.p2.x) < min(line1.p1.x, line1.p2.x)) return false;
    if (max(line1.p1.y, line1.p2.y) < min(line2.p1.y, line2.p2.y)) return false;
    if (max(line2.p1.y, line2.p2.y) < min(line1.p1.y, line1.p2.y)) return false;
    return true;
}

int get_parent(int u) {
    if (parent[u] < 0) {
        return u;
    }
    return parent[u] = get_parent(parent[u]);
}

void union_parents(int u, int v) {
    int pu = get_parent(u), pv = get_parent(v);
    if (pu == pv) return;

    if (parent[pu] > parent[pv]) {
        swap(pu, pv);
    }
    parent[pu] += parent[pv];
    parent[pv] = pu;
    ans--;
    ans2 = min(ans2, parent[pu]);
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
    }

    ans = n;
    ans2 = -1;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v < u; v++) {
            int pu = get_parent(u), pv = get_parent(v);
            if (pu == pv) continue;

            if (check_line_cross(lines[u], lines[v])) {
                union_parents(pu, pv);
            }
        }
    }
    ans2 = -ans2;

    cout << ans << '\n';
    cout << ans2 << '\n';

    return 0;
}
