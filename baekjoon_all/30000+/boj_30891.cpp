// Solve 2025-05-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }
};

int get_dist_square(Point& a, Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    FASTIO;

    int n, r;
    cin >> n >> r;
    int r2 = r * r;

    vector<Point> points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    Point max_pos(0, 0);
    int max_cnt = 0;

    for (int cx = -100; cx <= 100; cx++) {
        for (int cy = -100; cy <= 100; cy++) {
            Point cur_pos(cx, cy);
            int cur_cnt = 0;

            for (int i = 0; i < n; i++) {
                if (get_dist_square(cur_pos, points[i]) <= r2) {
                    cur_cnt++;
                }
            }

            if (cur_cnt > max_cnt) {
                max_cnt = cur_cnt;
                max_pos = cur_pos;
            }
        }
    }

    cout << max_pos.x << ' ' << max_pos.y << '\n';

    return 0;
}
