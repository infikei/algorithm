// Solve 2023-08-28
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

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);

    for (ll &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end(), greater<ll>());

    ll ans = 0;
    int pos = 0;

    for (int i = 1; i < m; i++) {
        ll t, q;
        cin >> t >> q;

        while (ans < q && pos < n) {
            ans += a[pos] + t;
            pos++;
        }

        if (ans < q && pos == n) {
            ans = -1;
            break;
        }
    }

    if (ans != -1) {
        ll t, q;
        cin >> t >> q;

        while (pos < n) {
            ans += a[pos] + t;
            pos++;
        }

        if (ans < q) {
            ans = -1;
        }
    }

    cout << ans << '\n';

    return 0;
}
