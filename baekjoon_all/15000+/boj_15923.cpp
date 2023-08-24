// Solve 2023-08-24

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

istream& operator>>(istream &is, Point &rhs) {
    return is >> rhs.x >> rhs.y;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    Point point[20];

    for (int i = 0; i < n; i++) {
        cin >> point[i];
    }

    int ans = abs(point[0].x - point[n - 1].x) + abs(point[0].y - point[n - 1].y);

    for (int i = 1; i < n; i++) {
        ans += abs(point[i - 1].x - point[i].x) + abs(point[i - 1].y - point[i].y);
    }

    cout << ans << '\n';

    return 0;
}
