// Solve 2023-05-15
// Update 2025-04-16

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

struct Line{
    Point from;
    Point to;
};

Line lines[2000];
int ans[2000][2000];

ll get_outer_product(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = get_outer_product(b - a, c - a);

    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

int intersects(Line &a, Line &b) {
    int ccw012 = calc_ccw(a.from, a.to, b.from);
    int ccw013 = calc_ccw(a.from, a.to, b.to);
    int ccw230 = calc_ccw(b.from, b.to, a.from);
    int ccw231 = calc_ccw(b.from, b.to, a.to);

    // 네 점이 한 직선 위에 있을 경우
    if (ccw012 == 0 && ccw013 == 0) {
        if (a.to < b.from || b.to < a.from) {
            return 0; // 교점이 없는 경우
        }
        if (a.to == b.from || b.to == a.from) {
            return 1; // 교점이 정확히 하나 있고, 그 교점이 적어도 한 선분의 끝점인 경우
        }

        return 3; // 교점이 무한히 많이 존재하는 경우
    }

    // 세 점이 한 직선 위에 있을 경우
    if (ccw012 == 0 || ccw013 == 0) {
        if (ccw230 == ccw231) {
            return 0; // 교점이 없는 경우
        }

        return 1; // 교점이 정확히 하나 있고, 그 교점이 적어도 한 선분의 끝점인 경우
    }

    // 세 점이 한 직선 위에 있을 경우
    if (ccw230 == 0 || ccw231 == 0) {
        if (ccw012 == ccw013) {
            return 0; // 교점이 없는 경우
        }

        return 1; // 교점이 정확히 하나 있고, 그 교점이 적어도 한 선분의 끝점인 경우
    }

    if (ccw012 + ccw013 == 0 && ccw230 + ccw231 == 0) {
        return 2; // 교점이 정확히 하나 있고, 그 교점이 어느 선분의 끝점도 아닌 경우
    }

    return 0; // 교점이 없는 경우
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> lines[i].from.x >> lines[i].from.y >> lines[i].to.x >> lines[i].to.y;

        if (lines[i].from > lines[i].to) {
            swap(lines[i].from, lines[i].to);
        }
    }

    for (int i = 0; i < n; i++) {
        ans[i][i] = 3;

        for (int j = 0; j < i; j++) {
            ans[j][i] = ans[i][j] = intersects(lines[i], lines[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }

        cout << '\n';
    }

    return 0;
}
