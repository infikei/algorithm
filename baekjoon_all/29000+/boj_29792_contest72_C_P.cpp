// Solve 2023-09-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Boss{
    ll p = 0, q = 0;
};

int k;
Boss boss[13];
ll res;

void dfs(ll d, int prev = -1, ll val = 0, ll t = 0) {
    res = max(res, val);

    for (int i = prev + 1; i < k; i++) {
        ll nt = t + (boss[i].p - 1) / d + 1;
        if (nt > 900) continue;

        dfs(d, i, val + boss[i].q, nt);
    }
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m >> k;

    ll character[49];

    for (int i = 0; i < n; i++) {
        cin >> character[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> boss[i].p >> boss[i].q;
    }

    sort(character, character + n, greater<int>());

    ll ans = 0;

    for (int i = 0; i < m; i++) {
        res = 0;

        dfs(character[i]);

        ans += res;
    }

    cout << ans << '\n';

    return 0;
}
