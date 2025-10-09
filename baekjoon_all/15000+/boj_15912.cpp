// Solve 2025-10-09

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
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

int n;
ll w[1001];
ll e[1001];
ll memo[1001];

ll recur(int cur) {
    if (cur > n) {
        return 0;
    }

    if (memo[cur] != -1) {
        return memo[cur];
    }

    ll ret = LLINF;
    ll w_max = 0;
    ll e_max = 0;

    for (int i = cur; i <= n; i++) {
        w_max = max(w_max, w[i]);
        e_max = max(e_max, e[i]);

        ll res = w_max * e_max + recur(i + 1);
        ret = min(ret, res);
    }

    memo[cur] = ret;
    return ret;
}

int main() {
    FASTIO;

    memset(memo, -1, sizeof memo);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> e[i];

    ll ans = recur(1);
    cout << ans << '\n';
    return 0;
}
