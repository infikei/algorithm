#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll factorial_with_mod(ll x, ll m) {
    ll res = 1;
    for (ll i = 2; i <= x; i++) {
        res *= i;
        res %= m;
    }
    return res;
}

ll power_with_mod(ll x, ll n, ll m) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x % m;
    }

    ll k = power_with_mod(x, n / 2, m);
    if (n % 2 == 0) {
        return k * k % m;
    }
    else {
        return k * k % m * x % m;
    }
}

int main() {
    fastio;

    ll N, K, M = 1000000007LL;
    cin >> N >> K;

    ll A = factorial_with_mod(N, M);
    ll B = factorial_with_mod(K, M) * factorial_with_mod(N - K, M) % M;
    ll ans = A * power_with_mod(B, M - 2, M) % M;

    cout << ans << '\n';

    return 0;
}