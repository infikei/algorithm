// Solve 2023-05-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y, idx;
    Point(int nx = 0, int ny = 0, int nidx = 0) : x(nx), y(ny), idx(nidx) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y, 0 };
    }
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        }
        return y < rhs.y;
    }
};

set<Point> points_set;
vector<Point> points_vec;
int ans[1000];

int calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    return calc_cross(b - a, c - a);
}

bool cmp_ccw_x_y(const Point &a, const Point &b) {
    int ccw = calc_ccw(points_vec[0], a, b);
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
        int x, y;
        cin >> x >> y;
        points_set.emplace(x, y, i);
    }

    int iter = 0;
    while (true) {
        if (SIZE(points_set) < 3) break;

        points_vec.assign(points_set.begin(), points_set.end());
        swap(points_vec[0], *min_element(points_vec.begin(), points_vec.end()));
        sort(points_vec.begin() + 1, points_vec.end(), cmp_ccw_x_y);

        vector<Point> convex_hull;
        for (auto &p : points_vec) {
            while (SIZE(convex_hull) >= 2) {
                Point back2 = convex_hull.back();
                convex_hull.pop_back();
                Point back1 = convex_hull.back();

                if (calc_ccw(back1, back2, p) > 0) {
                    convex_hull.push_back(back2);
                    break;
                }
            }
            convex_hull.push_back(p);
        }

        if (SIZE(convex_hull) < 3) break;

        iter++;
        for (auto &p : convex_hull) {
            points_set.erase(points_set.find(p));
            ans[p.idx] = iter;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
