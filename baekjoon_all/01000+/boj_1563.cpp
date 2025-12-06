// Solve 2025-12-02

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
const int MOD = 1000000;

ll memo[1001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    memo[0] = 1;
    int o = 1, a1 = 0, a2 = 0;

    for (int i = 1; i <= n; i++) {
        int nxt_o = (o + a1 + a2) % MOD;
        a2 = a1;
        a1 = o;
        o = nxt_o;
        memo[i] = o + a1 + a2;
    }

    ll ans = memo[n];

    for (int i = 0; i < n; i++) {
        int j = n - 1 - i;
        ans = (ans + memo[i] * memo[j]) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
