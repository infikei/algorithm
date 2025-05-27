// Solve 2025-05-25

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
};

Point station[3];
Point cur;
int t[3];

int get_dist(Point& p1, Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
    FASTIO;

    for (int i = 0; i < 3; i++) {
        cin >> station[i].x >> station[i].y;
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        cin >> cur.x >> cur.y >> t[0] >> t[1] >> t[2];
        int min_t = 1000000000;

        for (int i = 0; i < 3; i++) {
            int dist = get_dist(station[i], cur);
            min_t = min(min_t, (dist - 1 + t[i]) / t[i] * t[i]);
        }

        cout << min_t << '\n';
    }

    return 0;
}
