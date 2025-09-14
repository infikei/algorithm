// Solve 2025-09-13

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

ll count_rectangle(ll n) {
    return n * (n - 1) * 2 + n % 2;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    ll k_pow = 1;
    ll ans = 0;

    for (int i = n; i >= 1; i--) {
        k_pow = k_pow * k % MOD;
        ans = (ans + count_rectangle(i) % MOD * k_pow % MOD) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
