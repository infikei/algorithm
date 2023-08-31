// Solve 2023-08-31

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x = 0, y = 0;

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

int main() {
    FASTIO;

    Point points[3];

    for (int i = 0; i < 3; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points + 3);

    Point a = points[0];
    Point b = points[1];
    Point c = points[2];

    if ((b.x - a.x) * (c.y - b.y) == (c.x - b.x) * (b.y - a.y)) {
        cout << "WHERE IS MY CHICKEN?\n";
    }
    else {
        cout << "WINNER WINNER CHICKEN DINNER!\n";
    }

    return 0;
}
