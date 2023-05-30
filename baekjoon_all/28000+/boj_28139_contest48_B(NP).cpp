// Solve 2023-05-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using ld = long double;

struct Point{
    ld x, y;
    Point(ld nx = 0, ld ny = 0) : x(nx), y(ny) {}
};

Point points[5000];

ld calc_dist(const Point &a, const Point &b) {
    ld dx = b.x - a.x;
    ld dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    ld ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += calc_dist(points[i], points[j]);
        }
    }

    SETPRECISION(12);

    ans *= 2;
    ans /= n;
    cout << ans << '\n';

    return 0;
}
