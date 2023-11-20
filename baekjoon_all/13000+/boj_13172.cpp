// Solve 2023-03-04
// Update 2023-11-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

ll calc_power(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    FASTIO;

    int m;
    cin >> m;

    ll ans = 0;

    for (int mi = 0; mi < m; mi++) {
        ll n, s;
        cin >> n >> s;

        ans += s * calc_power(n, MOD - 2) % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
