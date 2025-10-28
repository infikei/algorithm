// Solve 2025-10-27

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

ll mod_pow(ll a, int p) {
    ll ret = 1;

    while (p > 0) {
        if (p & 1) {
            ret = ret * a % MOD;
        }

        a = a * a % MOD;
        p >>= 1;
    }

    return ret;
}

ll mod_div(ll a) {
    return mod_pow(a, MOD - 2);
}

ll mod_comb(int n, int k) {
    k = min(k, n - k);
    ll upper = 1;
    ll lower = 1;

    for (int i = 1; i <= k; i++) {
        upper = upper * (n + 1 - i) % MOD;
        lower = lower * i % MOD;
    }

    return upper * mod_div(lower) % MOD;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    ll ans = mod_comb(n, k) * mod_pow(2, k - 1) % MOD;
    cout << ans << '\n';
    return 0;
}
