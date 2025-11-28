// Solve 2024-10-14
// Update 2025-11-28

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

int people[10001];
vector<int> adj[10001];

pii dfs(int cur, int par) {
    int o = people[cur];
    int x = 0;

    for (int nxt : adj[cur]) {
        if (nxt == par) continue;

        auto [nxt_o, nxt_x] = dfs(nxt, cur);
        o += nxt_x;
        x += max(nxt_o, nxt_x);
    }

    return {o, x};
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int u = 1; u <= n; u++) {
        cin >> people[u];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto [o, x] = dfs(1, 0);
    cout << max(o, x) << '\n';
    return 0;
}
