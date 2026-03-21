// Solve 2026-03-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll mod_pow(ll a, ll b) {
    ll ret = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            ret = ret * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }

    return ret;
}

ll mod_inv(ll a) {
    return mod_pow(a, MOD - 2);
}

ll mod_frac(ll upper, ll lower) {
    return upper * mod_inv(lower) % MOD;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll fac_n = 1;

    for (int i = 1; i <= n; i++) {
        fac_n = fac_n * i % MOD;
    }

    ll fac_2n = fac_n;

    for (int i = n + 1; i <= n * 2; i++) {
        fac_2n = fac_2n * i % MOD;
    }

    ll ans = mod_frac(fac_2n, fac_n * fac_n % MOD * (n + 1) % MOD);
    cout << ans << '\n';
    return 0;
}
