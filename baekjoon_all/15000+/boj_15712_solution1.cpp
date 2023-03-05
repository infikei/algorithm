// Solve 2023-03-05

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

ll mod;

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

/**
 * @brief 1 + r + r^2 + ... + r^(n-1) 구하는 함수
 */
ll calc(ll r, ll n) {
    if (n == 1) {
        return 1;
    }
    ll res = calc(r, n >> 1) * (1 + power(r, n >> 1)) % mod;
    if (n & 1) {
        res *= r;
        res++;
        res %= mod;
    }
    return res;
}

int main() {
    FASTIO;

    ll a, r, n;
    cin >> a >> r >> n >> mod;

    ll ans = a * calc(r, n) % mod;
    cout << ans << '\n';

    return 0;
}