// Solve 2023-03-12

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

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

    ll n, m;
    cin >> n >> m;

    ll ans = 1;

    for (ll r = 2; r * r <= n; r++) {
        ll cnt = 0;
        while (n % r == 0) {
            cnt++;
            n /= r;
        }

        if (cnt > 0) {
            ll a = calc_power(r, cnt * m + 1) - 1;
            if (a < 0) a += MOD;
            ll inv = calc_power(r - 1, MOD - 2);
            ans *= a * inv % MOD;
            ans %= MOD;
        }
    }
    if (n > 1) {
        ll a = calc_power(n, m + 1) - 1;
        if (a < 0) a += MOD;
        ll inv = calc_power(n - 1, MOD - 2);
        ans *= a * inv % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
