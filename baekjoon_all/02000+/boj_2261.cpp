// Solve 2024-04-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    int get_dist_square(Point &rhs) {
        int dx = x - rhs.x;
        int dy = y - rhs.y;
        return dx * dx + dy * dy;
    }

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

struct CmpPoint{
    bool operator()(Point &p1, Point &p2) {
        return p1.y < p2.y;
    }
};

vector<Point> points;

int recur(int low, int high) {
    if (high - low <= 3) {
        int res = 1000000000;

        for (int i = low; i < high; i++) {
            for (int j = i + 1; j < high; j++) {
                res = min(res, points[i].get_dist_square(points[j]));
            }
        }

        return res;
    }

    int mid = (low + high) / 2;
    int left_res = recur(low, mid);
    int right_res = recur(mid, high);
    int res = min(left_res, right_res);

    int nbd_low = lower_bound(points.begin() + low, points.begin() + high, Point(points[mid].x - res - 1, -10000)) - points.begin();
    int nbd_high = lower_bound(points.begin() + low, points.begin() + high, Point(points[mid].x + res + 1, -10000)) - points.begin();
    vector<Point> nbd_points;

    for (int i = nbd_low; i < nbd_high; i++) {
        nbd_points.push_back(points[i]);
    }

    sort(nbd_points.begin(), nbd_points.end(), CmpPoint());

    for (int i = 0; i < SIZE(nbd_points); i++) {
        for (int j = i + 1; j < SIZE(nbd_points); j++) {
            int dy = nbd_points[j].y - nbd_points[i].y;

            if (dy * dy >= res) break;

            res = min(res, nbd_points[i].get_dist_square(nbd_points[j]));
        }
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    sort(points.begin(), points.end());
    int ans = recur(0, n);
    cout << ans << '\n';

    return 0;
}
