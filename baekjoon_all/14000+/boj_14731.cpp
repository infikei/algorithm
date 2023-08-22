// Solve 2023-03-12
// Update 2023-08-22

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

    int n;
    cin >> n;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll c, k;
        cin >> c >> k;

        ans += calc_power(2, k - 1) * k % MOD * c;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
