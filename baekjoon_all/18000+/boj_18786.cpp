// Solve 2023-09-03
// Update 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;

    Point(int nx = 0, int ny = 0) : x(nx), y(ny) {}

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Point> points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points.emplace_back(x, y);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                vector<Point> v;
                v.push_back(points[i]);
                v.push_back(points[j]);
                v.push_back(points[k]);

                sort(v.begin(), v.end());

                if (v[0].x == v[1].x) {
                    if (v[1].x == v[2].x || v[0].y != v[2].y && v[1].y != v[2].y) continue;

                    ans = max(ans, (v[2].x - v[1].x) * (v[1].y - v[0].y));
                }
                else if (v[1].x == v[2].x) {
                    if (v[0].y != v[1].y && v[0].y != v[2].y) continue;

                    ans = max(ans, (v[1].x - v[0].x) * (v[2].y - v[1].y));
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
