// Solve 2023-08-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;
};

Point point[100000];

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

inline int calc_dist(const Point &a, const Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> point[i];
    }

    int dist_sum = 0;

    for (int i = 1; i < n; i++) {
        dist_sum += calc_dist(point[i - 1], point[i]);
    }

    int ans = dist_sum;

    for (int i = 2; i < n; i++) {
        int val = dist_sum - calc_dist(point[i - 2], point[i - 1]) - calc_dist(point[i - 1], point[i]) + calc_dist(point[i - 2], point[i]);
        ans = min(ans, val);
    }

    cout << ans << '\n';

    return 0;
}
