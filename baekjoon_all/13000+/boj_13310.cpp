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
    Point operator+(const Point &rhs) const {
        return { x + rhs.x, y + rhs.y };
    }
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
    Point operator*(const int &rhs) const {
        return { x * rhs, y * rhs };
    }
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        }
        return y < rhs.y;
    }
};

int n;
Point stars_x0[30000], stars_v0[30000], stars_x[30000];

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

ll calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

bool cmp_ccw_x_y(const Point &a, const Point &b) {
    ll ccw = calc_ccw(stars_x[0], a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    return a < b;
}

ll calc_dist2(const Point &a, const Point &b) {
    ll dx = b.x - a.x;
    ll dy = b.y - a.y;
    return dx * dx + dy * dy;
}

ll calc_val(int dt) {
    for (int i = 0; i < n; i++) {
        stars_x[i] = stars_x0[i] + stars_v0[i] * dt;
    }

    swap(stars_x[0], *min_element(stars_x, stars_x + n));
    sort(stars_x + 1, stars_x + n, cmp_ccw_x_y);

    vector<Point> convex_hull;
    for (int i = 0; i < n; i++) {
        while (SIZE(convex_hull) >= 2) {
            Point back2 = convex_hull.back();
            convex_hull.pop_back();
            Point back1 = convex_hull.back();

            if (calc_ccw(back1, back2, stars_x[i]) > 0) {
                convex_hull.push_back(back2);
                break;
            }
        }
        convex_hull.push_back(stars_x[i]);
    }

    ll max_dist2 = 0;
    for (int i = 0, j = 1; i < SIZE(convex_hull); i++) {
        int ni = (i + 1) % SIZE(convex_hull);
        Point vi = convex_hull[ni] - convex_hull[i];

        for (;;) {
            int nj = (j + 1) % SIZE(convex_hull);
            Point vj = convex_hull[nj] - convex_hull[j];

            if (calc_ccw(Point(0, 0), vi, vj) <= 0) {
                break;
            }
            j = nj;
        }

        ll now_dist2 = calc_dist2(convex_hull[i], convex_hull[j]);
        if (max_dist2 < now_dist2) {
            max_dist2 = now_dist2;
        }
    }

    return max_dist2;
}

int main() {
    FASTIO;

    int t;
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        ll x, y, dx, dy;
        cin >> x >> y >> dx >> dy;
        stars_x0[i] = { x, y };
        stars_v0[i] = { dx, dy };
    }

    int low = 0, high = t;
    while (low + 2 < high) {
        int mid1 = ((low << 1) + high) / 3;
        int mid2 = (low + (high << 1)) / 3;

        ll mid1_val = calc_val(mid1);
        ll mid2_val = calc_val(mid2);

        if (mid1_val <= mid2_val) {
            high = mid2;
        }
        else {
            low = mid1;
        }
    }

    int ans = low;
    ll ans_val = calc_val(low);
    for (int i = low + 1; i <= high; i++) {
        ll i_val = calc_val(i);
        if (ans_val > i_val) {
            ans_val = i_val;
            ans = i;
        }
    }
    cout << ans << '\n';
    cout << ans_val << '\n';

    return 0;
}
