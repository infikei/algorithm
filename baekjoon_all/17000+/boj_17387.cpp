// Solve 2022-09-05
// Update 2025-04-12

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Point{
    ll x, y;

    Point(ll x = 0, ll y = 0) : x(x), y(y) {
    }

    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
};

struct Line{
    Point from;
    Point to;
};

ll get_outer_product(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int get_ccw_sign(const Point &a, const Point &b, const Point &c) {
    ll ccw = get_outer_product(b - a, c - a);

    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

bool intersects(const Line &a, const Line &b) {
    int ccw012 = get_ccw_sign(a.from, a.to, b.from);
    int ccw013 = get_ccw_sign(a.from, a.to, b.to);
    int ccw230 = get_ccw_sign(b.from, b.to, a.from);
    int ccw231 = get_ccw_sign(b.from, b.to, a.to);

    if (ccw012 * ccw013 > 0 || ccw230 * ccw231 > 0) {
        return false;
    }
    if (max(a.from.x, a.to.x) < min(b.from.x, b.to.x)) {
        return false;
    }
    if (max(b.from.x, b.to.x) < min(a.from.x, a.to.x)) {
        return false;
    }
    if (max(a.from.y, a.to.y) < min(b.from.y, b.to.y)) {
        return false;
    }
    if (max(b.from.y, b.to.y) < min(a.from.y, a.to.y)) {
        return false;
    }

    return true;
}

int main() {
    FASTIO;

    Line lines[2];

    for (int i = 0; i < 2; i++) {
        cin >> lines[i].from.x >> lines[i].from.y >> lines[i].to.x >> lines[i].to.y;
    }

    if (intersects(lines[0], lines[1])) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
