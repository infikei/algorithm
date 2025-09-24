// Solve 2025-09-24

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
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }

    Point operator+(const Point& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    Point& operator+=(const Point& rhs) {
        (*this) = (*this) + rhs;
        return *this;
    }

    Point& operator-=(const Point& rhs) {
        (*this) = (*this) - rhs;
        return *this;
    }

    double get_dist() const {
        return sqrt(x * x + y * y);
    }

    double get_dist(const Point& rhs) const {
        int dx = x - rhs.x;
        int dy = y - rhs.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;
    Point s(0, 0);
    vector<Point> vec;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s += Point(x, y);
        vec.emplace_back(x, y);
    }

    double min_dist = 1e9;

    for (int i = 0; i < n; i++) {
        double dist = (s - vec[i]).get_dist();
        min_dist = min(min_dist, dist);
    }

    cout << s.x << ' ' << s.y << '\n';
    cout << fixed << setprecision(2) << min_dist << '\n';
    return 0;
}
