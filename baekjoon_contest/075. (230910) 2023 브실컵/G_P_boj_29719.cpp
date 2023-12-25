// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    ll n, m;
    cin >> n >> m;

    ll a = m, b = m - 1;

    for (ll i = 1; i < n; i++) {
        a *= m;
        a %= MOD;

        b *= m - 1;
        b %= MOD;
    }

    ll ans = a - b;

    while (ans < 0) ans += MOD;

    while (ans >= MOD) ans -= MOD;

    cout << ans << '\n';

    return 0;
}
