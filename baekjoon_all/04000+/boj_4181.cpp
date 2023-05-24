// Solve 2023-05-23

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
};

Point convex_hull[100000];
int convex_hull_size;

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

ll calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

bool cmp_ccw_x_y(const Point &a, const Point &b) {
    ll ccw = calc_ccw(convex_hull[0], a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    return a < b;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll x, y;
        char c;
        cin >> x >> y >> c;

        if (c == 'Y') {
            convex_hull[convex_hull_size] = { x, y };
            convex_hull_size++;
        }
    }

    swap(convex_hull[0], *min_element(convex_hull, convex_hull + convex_hull_size));
    sort(convex_hull + 1, convex_hull + convex_hull_size, cmp_ccw_x_y);

    int k = convex_hull_size - 1;
    while (calc_ccw(convex_hull[0], convex_hull[k], convex_hull[k - 1]) == 0) {
        k--;
    }
    reverse(convex_hull + k, convex_hull + convex_hull_size);

    cout << convex_hull_size << '\n';
    for (int i = 0; i < convex_hull_size; i++) {
        cout << convex_hull[i].x << ' ' << convex_hull[i].y << '\n';
    }

    return 0;
}
