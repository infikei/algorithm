// Solve 2023-10-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, ans = 0;
    ll k, x0, y0;
    cin >> n >> k >> x0 >> y0;

    ll k2 = k * k;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        ll dx = x - x0;
        ll dy = y - y0;

        if (dx * dx + dy * dy > k2) ans++;
    }

    cout << ans << '\n';

    return 0;
}
