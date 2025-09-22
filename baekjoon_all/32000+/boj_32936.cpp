// Solve 2025-09-21

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

void bfs(int start_node, int dist_init, int n, vector<vector<int>>& adj, vector<int>& dist) {
    dist.assign(n + 1, INF);
    queue<int> bfs_que;
    dist[start_node] = dist_init;
    bfs_que.push(start_node);

    while (!bfs_que.empty()) {
        int cur = bfs_que.front();
        bfs_que.pop();

        for (int& nxt : adj[cur]) {
            if (dist[nxt] == INF) {
                dist[nxt] = dist[cur] + 1;
                bfs_que.push(nxt);
            }
        }
    }
}

string find_shortest_dist_to_n(int n, int a, int b, int c, vector<vector<int>>& adj) {
    vector<int> dist;
    bfs(1, 0, n, adj, dist);

    if (dist[a] == INF) {
        if (dist[n] == INF) {
            return "x";
        }

        return to_string(dist[n]);
    }

    vector<int> dist_from_t_machine;
    bfs(b, dist[a] - c, n, adj, dist_from_t_machine);

    if (dist_from_t_machine[a] < dist[a] && dist_from_t_machine[n] != INF) {
        return "-inf";
    }

    if (dist[n] == INF && dist_from_t_machine[n] == INF) {
        return "x";
    }

    return to_string(min(dist[n], dist_from_t_machine[n]));
}

int main() {
    FASTIO;

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << find_shortest_dist_to_n(n, a, b, c, adj) << '\n';
    return 0;
}
