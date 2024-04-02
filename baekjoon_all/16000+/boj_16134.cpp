// Solve 2023-03-08
// Update 2024-04-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

ll get_factorial(ll k) {
    ll res = 1;

    for (ll i = 2; i <= k; i++) {
        res *= i;
        res %= MOD;
    }

    return res;
}

ll get_power(ll a, int b) {
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

    ll n, r;
    cin >> n >> r;

    ll ans = get_power(get_factorial(n - r) * get_factorial(r) % MOD, MOD - 2) * get_factorial(n) % MOD;

    cout << ans << '\n';

    return 0;
}
