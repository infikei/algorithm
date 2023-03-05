// Solve 2022-12-06
// Update 2023-03-05

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

ll calc_factorial(ll k) {
    ll res = 1;
    for (ll i = 2; i <= k; i++) {
        res *= i;
        res %= MOD;
    }
    return res;
}

ll power(ll a, ll b) {
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

    ll n, k;
    cin >> n >> k;

    ll a = calc_factorial(n);
    ll b = calc_factorial(n - k) * calc_factorial(k) % MOD;
    ll ans = a * power(b, MOD - 2) % MOD;
    cout << ans << '\n';

    return 0;
}