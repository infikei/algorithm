// Solve 2025-04-03

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
using pdd = pair<double, double>;

double get_dist_between(pdd &p1, pdd &p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<pdd> points(n);

    for (auto &pt : points) {
        cin >> pt.first >> pt.second;
    }

    int m;
    cin >> m;

    while (m-- > 0) {
        int p;
        cin >> p;

        vector<int> route(p);

        for (int &r : route) {
            cin >> r;
        }

        double ans = 0;

        for (int i = 1; i < p; i++) {
            ans += get_dist_between(points[route[i - 1]], points[route[i]]);
        }

        cout << (int) round(ans) << '\n';
    }

    return 0;
}
