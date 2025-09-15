// Solve 2025-09-15

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

struct AdjNode{
    int to, dist;

    AdjNode(int to, int dist) : to(to), dist(dist) {
    }

    bool operator<(const AdjNode& rhs) const {
        return dist < rhs.dist;
    }

    bool operator>(const AdjNode& rhs) const {
        return rhs < *this;
    }
};

int min_dist[201];
int from[201][201];

void dijkstra(int start_node, vector<vector<AdjNode>>& adj) {
    priority_queue<AdjNode, vector<AdjNode>, greater<AdjNode>> pq_mintop;
    memset(min_dist, 0x3f, sizeof min_dist);
    pq_mintop.emplace(start_node, 0);
    min_dist[start_node] = 0;

    while (!pq_mintop.empty()) {
        AdjNode cur = pq_mintop.top();
        pq_mintop.pop();

        if (cur.dist > min_dist[cur.to]) continue;

        for (AdjNode& nxt : adj[cur.to]) {
            int n_dist = cur.dist + nxt.dist;

            if (n_dist < min_dist[nxt.to]) {
                min_dist[nxt.to] = n_dist;
                from[nxt.to][start_node] = cur.to;
                pq_mintop.emplace(nxt.to, n_dist);
            }
        }
    }
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<AdjNode>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (int u = 1; u <= n; u++) {
        dijkstra(u, adj);
    }

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u == v) {
                cout << '-' << ' ';
            }
            else {
                cout << from[u][v] << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
