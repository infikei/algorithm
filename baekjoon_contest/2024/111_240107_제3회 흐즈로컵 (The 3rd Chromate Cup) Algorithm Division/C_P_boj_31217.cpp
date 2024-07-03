// Solve 2024-01-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<int> edges(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges[u]++;
        edges[v]++;
    }

    ll ans = 0;

    for (int u = 1; u <= n; u++) {
        int e = edges[u];
        ans += (ll)e * (e - 1) * (e - 2) / 6;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
