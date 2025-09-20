// Solve 2025-09-18

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

struct AdjNode{
    int to;
    int dist;

    AdjNode(int to, int dist) : to(to), dist(dist) {
    }
};

struct NodeTraversal{
    int to;
    ll dist;
    int cnt;

    NodeTraversal(int to, ll dist, int cnt) : to(to), dist(dist), cnt(cnt) {
    }

    bool operator<(const NodeTraversal& rhs) const {
        return dist < rhs.dist;
    }

    bool operator>(const NodeTraversal& rhs) const {
        return rhs < *this;
    }
};

ll min_dist[10001][21];

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<AdjNode>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    memset(min_dist, 0x3f, sizeof min_dist);
    priority_queue<NodeTraversal, vector<NodeTraversal>, greater<NodeTraversal>> pq_mintop;
    pq_mintop.emplace(1, 0, 0);
    min_dist[1][0] = 0;

    while (!pq_mintop.empty()) {
        NodeTraversal cur = pq_mintop.top();
        pq_mintop.pop();

        if (cur.dist > min_dist[cur.to][cur.cnt]) continue;

        for (AdjNode& nxt : adj[cur.to]) {
            ll nxt_dist = cur.dist + nxt.dist;

            if (nxt_dist < min_dist[nxt.to][cur.cnt]) {
                min_dist[nxt.to][cur.cnt] = nxt_dist;
                pq_mintop.emplace(nxt.to, nxt_dist, cur.cnt);
            }

            if (cur.cnt < k && cur.dist < min_dist[nxt.to][cur.cnt + 1]) {
                min_dist[nxt.to][cur.cnt + 1] = cur.dist;
                pq_mintop.emplace(nxt.to, cur.dist, cur.cnt + 1);
            }
        }
    }

    ll ans = LLINF;

    for (int cnt = 0; cnt <= k; cnt++) {
        ans = min(ans, min_dist[n][cnt]);
    }

    cout << ans << '\n';
    return 0;
}
