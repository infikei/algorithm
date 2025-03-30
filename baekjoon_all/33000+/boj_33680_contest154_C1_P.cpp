// Solve 2025-03-29

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

const int MOD = 1000000007;

ll mod_pow(ll a, int b) {
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

ll mod_inv(ll a) {
    return mod_pow(a, MOD - 2);
}

int main() {
    FASTIO;

    int q;
    cin >> q;

    while (q-- > 0) {
        int p, n;
        cin >> p >> n;

        ll ans = (mod_pow(p, n) + MOD - 1) % MOD;
        ans = ans * mod_inv(p - 1) % MOD;
        cout << ans << '\n';
    }

    return 0;
}
