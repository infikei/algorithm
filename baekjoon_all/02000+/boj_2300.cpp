// Solve 2024-04-21

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

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;

        return y > rhs.y;
    }
};

int memo[10000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Point> points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points.emplace_back(x, abs(y) * 2);
    }

    sort(points.begin(), points.end());

    memo[0] = points[0].y;

    for (int i = 1; i < n; i++) {
        memo[i] = memo[i - 1] + points[i].y;
        int max_y = points[i].y;

        for (int j = i - 1; j >= 0; j--) {
            int dx = points[i].x - points[j].x;
            max_y = max(max_y, points[j].y);

            memo[i] = min(memo[i], (j == 0 ? 0 : memo[j - 1]) + max(dx, max_y));
        }
    }

    cout << memo[n - 1] << '\n';

    return 0;
}
