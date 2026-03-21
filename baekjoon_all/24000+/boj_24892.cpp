// Solve 2026-03-16

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
        if (b & 1) {
            ret = ret * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }

    return ret;
}

ll mod_div(ll a) {
    return mod_pow(a, MOD - 2);
}

ll mod_frac(ll upper, ll lower) {
    return upper * mod_div(lower) % MOD;
}

int main() {
    FASTIO;

    ll n, a, b;
    cin >> n >> a >> b;

    ll d = b - a;
    ll upper = d * d * d * (n * n - 1) % MOD;
    ll lower = 6 * n * n;
    ll area = mod_frac(upper, lower);
    cout << area << '\n';
    return 0;
}
