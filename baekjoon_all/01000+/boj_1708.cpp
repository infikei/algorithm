// Solve 2023-05-10

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

struct Point{
    ll x, y;
    Point(ll nx = 0, ll ny = 0) : x(nx), y(ny) {}
};

Point points[100000];

ll calc_ccw(const Point &p1, const Point &p2, const Point &p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

bool cmp_y_x(const Point &p1, const Point &p2) {
    if (p1.y != p2.y) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

bool cmp_ccw_y_x(const Point &p1, const Point &p2) {
    ll ccw = calc_ccw(points[0], p1, p2);

    if (ccw != 0) {
        return ccw > 0;
    }
    if (p1.y != p2.y) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points + n, cmp_y_x);

    sort(points + 1, points + n, cmp_ccw_y_x);

    stack<Point> stck;
    stck.push(points[0]);
    stck.push(points[1]);

    for (int i = 2; i < n; i++) {
        while (SIZE(stck) >= 2) {
            Point top2 = stck.top();
            stck.pop();
            Point top1 = stck.top();

            if (calc_ccw(top1, top2, points[i]) > 0) {
                stck.push(top2); // top1, top2, points[i]가 좌회전이면 top2를 stack에 다시 넣어주고 break
                break;
            }
        }
        stck.push(points[i]);
    }

    cout << SIZE(stck) << '\n';

    return 0;
}
