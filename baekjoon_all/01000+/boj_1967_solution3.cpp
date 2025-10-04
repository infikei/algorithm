// Solve 2023-02-13
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

bool visited[10001];

pii bfs(int start_node, vector<vector<pii>>& adj) {
    int max_dist = 0;
    int max_node = start_node;
    memset(visited, false, sizeof visited);
    visited[start_node] = true;
    queue<pii> bfs_que;
    bfs_que.emplace(start_node, 0);

    while (!bfs_que.empty()) {
        pii p = bfs_que.front();
        bfs_que.pop();
        int cur = p.first;
        int cur_dist = p.second;

        for (pii& np : adj[cur]) {
            int nxt = np.first;
            int nxt_dist = cur_dist + np.second;

            if (!visited[nxt]) {
                visited[nxt] = true;
                bfs_que.emplace(nxt, nxt_dist);

                if (nxt_dist > max_dist) {
                    max_dist = nxt_dist;
                    max_node = nxt;
                }
            }
        }
    }

    return {max_dist, max_node};
}

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<vector<pii>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int par, child, w;
        cin >> par >> child >> w;
        adj[par].emplace_back(child, w);
        adj[child].emplace_back(par, w);
    }

    pii res = bfs(1, adj);
    int max_node1 = res.second;

    res = bfs(max_node1, adj);
    int max_node2 = res.second;
    int max_dist = res.first;
    cout << max_dist << '\n';
    return 0;
}
