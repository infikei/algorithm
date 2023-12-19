// Solve 2023-08-14
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

int calc_dist(const Point &a, const Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Point> points(n);

    for (Point &p : points) {
        cin >> p;
    }

    int dist_sum = 0;

    for (int i = 1; i < n; i++) {
        dist_sum += calc_dist(points[i - 1], points[i]);
    }

    int ans = dist_sum;

    for (int i = 2; i < n; i++) {
        int cur = dist_sum + calc_dist(points[i - 2], points[i])\
                - calc_dist(points[i - 2], points[i - 1]) - calc_dist(points[i - 1], points[i]);
        ans = min(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
