// Solve 2023-09-19
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x = 0, y = 0, idx = 0;

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i + 1;
    }

    sort(points.begin(), points.end());

    for (int i = 0, ie = SIZE(points) - 1; i < ie; i++) {
        cout << points[i].idx << ' ' << points[i + 1].idx << '\n';
    }

    return 0;
}
