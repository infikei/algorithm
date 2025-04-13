// Solve 2023-03-16
// Update 2025-04-12

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
    ll x, y;

    Point(ll x = 0, ll y = 0) : x(x), y(y) {
    }

    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }

    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;

        return y < rhs.y;
    }

    bool operator>(const Point &rhs) const {
        if (x != rhs.x) return x > rhs.x;

        return y > rhs.y;
    }

    bool operator==(const Point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

struct Point_d{
    double x, y;

    Point_d(double x = 0.0, double y = 0.0) : x(x), y(y) {
    }
};

struct Line{
    Point from;
    Point to;
};

ll get_outer_product(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int get_ccw_sign(const Point &a, const Point &b, const Point &c) {
    ll ccw = get_outer_product(b - a, c - a);

    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

int intersects(Line &a, Line &b) {
    if (a.from > a.to) swap(a.from, a.to);
    if (b.from > b.to) swap(b.from, b.to);

    int ccw012 = get_ccw_sign(a.from, a.to, b.from);
    int ccw013 = get_ccw_sign(a.from, a.to, b.to);
    int ccw230 = get_ccw_sign(b.from, b.to, a.from);
    int ccw231 = get_ccw_sign(b.from, b.to, a.to);

    // 네 점이 한 직선 위에 있을 경우
    if (ccw012 == 0 && ccw013 == 0) {
        if (a.from == b.to) {
            return 2; // 선분의 양 끝 점끼리 교차하는 경우
        }
        if (b.from == a.to) {
            return 2; // 선분의 양 끝 점끼리 교차하는 경우
        }
        if (a.from < b.to && b.from < a.to) {
            return 9; // 선분끼리 겹쳐서 무수히 많은 점에서 교차하는 경우
        }

        return 0; // 두 선분이 교차하지 않는 경우
    }

    // 세 점이 한 직선 위에 있을 경우
    if (ccw012 == 0 || ccw013 == 0) {
        if (ccw230 == ccw231) {
            return 0; // 두 선분이 교차하지 않는 경우
        }

        return 1; // 두 선분이 양 끝 점이 아닌 점에서 교차하는 경우
    }

    // 세 점이 한 직선 위에 있을 경우
    if (ccw230 == 0 || ccw231 == 0) {
        if (ccw012 == ccw013) {
            return 0; // 두 선분이 교차하지 않는 경우
        }

        return 1; // 두 선분이 양 끝 점이 아닌 점에서 교차하는 경우
    }

    if (ccw012 + ccw013 == 0 && ccw230 + ccw231 == 0) {
        return 1; // 두 선분이 양 끝 점이 아닌 점에서 교차하는 경우
    }

    return 0; // 두 선분이 교차하지 않는 경우
}

Point_d get_intersection_point(Line &a, Line &b) {
    Point vec01 = a.from - a.to;
    Point vec23 = b.from - b.to;
    ll cross01 = get_outer_product(a.from, a.to);
    ll cross23 = get_outer_product(b.from, b.to);
    double k = get_outer_product(vec01, vec23);
    double x = (cross01 * vec23.x - cross23 * vec01.x) / k;
    double y = (cross01 * vec23.y - cross23 * vec01.y) / k;

    return { x, y };
}

int main() {
    FASTIO;

    SETP(12);

    Line lines[2];

    for (int i = 0; i < 2; i++) {
        cin >> lines[i].from.x >> lines[i].from.y >> lines[i].to.x >> lines[i].to.y;
    }

    switch (intersects(lines[0], lines[1])) {
        case 0:
            cout << 0 << '\n';
            break;

        case 9:
            cout << 1 << '\n';
            break;

        case 1:
            {
                Point_d intersection_point_d = get_intersection_point(lines[0], lines[1]);

                cout << 1 << '\n';
                cout << intersection_point_d.x << ' ' << intersection_point_d.y << '\n';
            }

            break;

        case 2:
            {
                Point intersection_point;

                if (lines[0].from == lines[1].to) {
                    intersection_point = lines[0].from;
                }
                else {
                    intersection_point = lines[0].to;
                }

                cout << 1 << '\n';
                cout << intersection_point.x << ' ' << intersection_point.y << '\n';
            }

            break;
    }

    return 0;
}
