// Solve 2023-04-18
// Update 2025-10-07

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

int main() {
    FASTIO;

    int n;
    ll k;
    cin >> n >> k;

    ll ans = 0;
    ll ten_pow = 10;
    ll ten_pow_mod_k = 10 % k;

    for (int i = 1; i <= n; i++) {
        if (i == ten_pow) {
            ten_pow *= 10;
            ten_pow_mod_k = ten_pow_mod_k * 10 % k;
        }

        ans = (ans * ten_pow_mod_k + i) % k;
    }

    cout << ans << '\n';
    return 0;
}
