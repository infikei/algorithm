// Solve 2023-03-08
// Update 2025-03-09

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const ll MOD = 1000000007;

ll get_factorial(ll k) {
    ll res = 1;

    for (ll i = 2; i <= k; i++) {
        res = res * i % MOD;
    }

    return res;
}

ll get_power(ll a, int b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }

        a = a * a % MOD;
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
