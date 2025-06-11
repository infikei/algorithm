// Solve 2025-06-07

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<pii> points;
    map<int, int> cnt_by_x;
    map<int, int> cnt_by_y;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
        cnt_by_x[x]++;
        cnt_by_y[y]++;
    }

    ll ans = 0;

    for (pii& p : points) {
        ans += (cnt_by_x[p.first] - 1) * (ll) (cnt_by_y[p.second] - 1);
    }

    cout << ans << '\n';

    return 0;
}
