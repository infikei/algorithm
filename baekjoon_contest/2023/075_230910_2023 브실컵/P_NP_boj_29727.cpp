// Solve 2023-09-11
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll n, xa, ya, xb, yb;
    cin >> n >> xa >> ya >> xb >> yb;

    ll ans = n * (n + 1) / 2;
    ans *= ans;

    if (ya == yb) {
        if (xa > xb) swap(xa, xb);

        xa = min(n, max(xa, -1ll));
        xb = min(n, max(xb, -1ll));
        ll dx = xb - xa;
        ans += dx * (dx - 1) / 2 * (n + 1);
    }
    else if (xa == xb) {
        if (ya > yb) swap(ya, yb);

        ya = min(n, max(ya, -1ll));
        yb = min(n, max(yb, -1ll));
        ll dy = yb - ya;
        ans += dy * (dy - 1) / 2 * (n + 1);
    }

    cout << ans << '\n';

    return 0;
}
