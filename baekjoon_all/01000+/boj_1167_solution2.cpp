// Solve 2023-02-13
// Update 2025-10-03

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

void dfs(int cur, int par, int cur_dist, vector<vector<pii>>& adj, int& max_dist, int& max_node) {
    if (cur_dist > max_dist) {
        max_dist = cur_dist;
        max_node = cur;
    }

    for (pii& p : adj[cur]) {
        int nxt = p.first;
        int w = p.second;

        if (nxt == par) continue;

        dfs(nxt, cur, cur_dist + w, adj, max_dist, max_node);
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<vector<pii>> adj(n + 1);

    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u;

        while (true) {
            cin >> v;

            if (v == -1) break;

            cin >> w;
            adj[u].emplace_back(v, w);
        }
    }

    int max_dist = -1;
    int max_node1 = -1;
    dfs(1, -1, 0, adj, max_dist, max_node1);

    max_dist = -1;
    int max_node2 = -1;
    dfs(max_node1, -1, 0, adj, max_dist, max_node2);
    cout << max_dist << '\n';
    return 0;
}
