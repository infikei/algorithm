// Solve 2025-05-18
// Update 2025-10-04

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

vector<int> adj[50001];
int depth[50001];
int parent[16][50001];

void dfs(int cur, int par) {
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;

        depth[nxt] = depth[cur] + 1;
        parent[0][nxt] = cur;
        dfs(nxt, cur);
    }
}

int get_LCA(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int diff = depth[u] - depth[v];

    for (int i = 0; i < 16; i++) {
        if (diff & (1 << i)) {
            u = parent[i][u];
        }
    }

    if (u == v) return u;

    for (int i = 16; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i < 16; i++) {
        for (int u = 1; u <= n; u++) {
            parent[i][u] = parent[i - 1][parent[i - 1][u]];
        }
    }

    int m;
    cin >> m;

    while (m-- > 0) {
        int u, v;
        cin >> u >> v;
        cout << get_LCA(u, v) << '\n';
    }

    return 0;
}
