// Solve 2023-06-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using ld = long double;

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

Point top, bottom;
vector<Point> points;

istream& operator>>(istream &is, Point &rhs) {
    is >> rhs.x >> rhs.y;
    return is;
}

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

ll calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

bool cmp_ccw_x_y(const Point &a, const Point &b) {
    ll ccw = calc_ccw(points[0], a, b);
    if (ccw != 0) {
        return ccw > 0;
    }
    return a < b;
}

int main() {
    FASTIO;

    int n;
    cin >> n >> top >> bottom;
    points.push_back(top);
    points.push_back(bottom);

    for (int i = 0; i < n; i++) {
        ll y, x_st, x_en;
        cin >> y >> x_st >> x_en;

        if (calc_ccw(bottom, top, { x_en, y }) > 0) {
            points.emplace_back(x_en, y);
        }
        else if (calc_ccw(bottom, top, { x_st, y }) < 0) {
            points.emplace_back(x_st, y);
        }
    }

    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), cmp_ccw_x_y);

    vector<Point> convex_hull;
    for (int i = 0; i < SIZE(points); i++) {
        while (SIZE(convex_hull) >= 2) {
            Point back2 = convex_hull.back();
            convex_hull.pop_back();
            Point back1 = convex_hull.back();

            if (calc_ccw(back1, back2, points[i]) > 0) {
                convex_hull.push_back(back2);
                break;
            }
        }
        convex_hull.push_back(points[i]);
    }

    ll ans = 0;
    for (int i = 0; i < SIZE(convex_hull); i++) {
        int j = i + 1;
        if (j == SIZE(convex_hull)) j = 0;
        int k = j;

        ll area = 0;
        while (k != i) {
            int nk = k + 1;
            if (nk == SIZE(convex_hull)) nk = 0;

            ll narea = calc_ccw(convex_hull[i], convex_hull[j], convex_hull[nk]);
            if (narea < area) {
                j++;
                if (j == SIZE(convex_hull)) j = 0;
                narea = calc_ccw(convex_hull[i], convex_hull[j], convex_hull[k]);
            }
            else {
                k = nk;
            }
            ans = max(ans, narea);
            area = narea;
        }
    }

    SETPRECISION(12);
    ld ans2 = ans;
    ans2 *= 0.5;
    cout << ans2 << '\n';

    return 0;
}
