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
    ll x, y;
};

double get_dist(Point& p1, Point& p2) {
    ll dx = p1.x - p2.x;
    ll dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    Point a, b, p;
    ll r;
    cin >> a.x >> a.y >> b.x >> b.y >> p.x >> p.y >> r;

    double a_to_b = get_dist(a, b);
    double a_to_p = get_dist(a, p);
    double p_to_b = get_dist(p, b);
    double a_to_b_through_oasis = max(a_to_p - r, 0.0) + max(p_to_b - r, 0.0);
    double min_a_to_b = min(a_to_b, a_to_b_through_oasis);

    SETP(10);
    cout << min_a_to_b << '\n';

    return 0;
}
