// Solve 2024-09-07
// Update 2025-10-10

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

int mod_pow(ll a, int b) {
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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = (mod_pow(2, n + 2) - 5 + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}
