// Solve 2026-06-30

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Point{
    int x;
    int y;

    Point(int x = 0, int y = 0) : x(x), y(y) {
    }

    bool operator<(const Point& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }

    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
};

Point points[100];

int get_cross(const Point& a, const Point& b) {
    return a.x * b.y - b.x * a.y;
}

int get_ccw(const Point& a, const Point& b, const Point& c) {
    return get_cross(b - a, c - a);
}

bool cmp_ccw_x_y(const Point& a, const Point& b) {
    int ccw = get_ccw(points[0], a, b);

    if (ccw != 0) return ccw > 0;
    return a < b;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    swap(points[0], *min_element(points, points + n));
    sort(points + 1, points + n, cmp_ccw_x_y);
    vector<Point> convex_hull;

    for (int i = 0; i < n; i++) {
        while (size(convex_hull) >= 2) {
            Point prv = convex_hull.back();
            convex_hull.pop_back();

            if (get_ccw(convex_hull.back(), prv, points[i]) > 0) {
                convex_hull.push_back(prv);
                break;
            }
        }

        convex_hull.push_back(points[i]);
    }

    int ch_area = 0;

    for (int i = 2; i < size(convex_hull); i++) {
        ch_area += get_ccw(convex_hull[0], convex_hull[i - 1], convex_hull[i]);
    }

    if (ch_area % 2 == 1) {
        cout << ch_area / 2 << ".5" << '\n';
    }
    else {
        cout << ch_area / 2 << '\n';
    }

    return 0;
}
