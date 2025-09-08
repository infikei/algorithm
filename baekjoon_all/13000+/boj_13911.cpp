// Solve 2025-09-08

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
    int to;
    int dist;

    AdjNode(int to, int dist) : to(to), dist(dist) {
    }

    bool operator<(const AdjNode& rhs) const {
        return dist > rhs.dist;
    }
};

void dijkstra(vector<vector<AdjNode>>& adj, vector<int>& start_nodes, vector<int>& min_dist) {
    priority_queue<AdjNode> pq;

    for (int& i : start_nodes) {
        min_dist[i] = 0;
        pq.emplace(i, 0);
    }

    while (!pq.empty()) {
        AdjNode cur = pq.top();
        pq.pop();

        if (cur.dist > min_dist[cur.to]) continue;

        for (AdjNode& nxt : adj[cur.to]) {
            int nxt_dist_new = cur.dist + nxt.dist;

            if (nxt_dist_new < min_dist[nxt.to]) {
                min_dist[nxt.to] = nxt_dist_new;
                pq.emplace(nxt.to, nxt_dist_new);
            }
        }
    }
}

int main() {
    FASTIO;

    int v, e;
    cin >> v >> e;
    vector<vector<AdjNode>> adj(v + 1);

    for (int i = 0; i < e; i++) {
        int u1, u2, w;
        cin >> u1 >> u2 >> w;
        adj[u1].emplace_back(u2, w);
        adj[u2].emplace_back(u1, w);
    }

    int m, x;
    cin >> m >> x;
    vector<int> mcdonalds(m);
    vector<bool> house_exist(v + 1, true);

    for (int& i : mcdonalds) {
        cin >> i;
        house_exist[i] = false;
    }

    int s, y;
    cin >> s >> y;
    vector<int> starbucks(s);

    for (int& i : starbucks) {
        cin >> i;
        house_exist[i] = false;
    }

    vector<int> dist_from_m(v + 1, INF);
    dijkstra(adj, mcdonalds, dist_from_m);
    vector<int> dist_from_s(v + 1, INF);
    dijkstra(adj, starbucks, dist_from_s);
    int ans = INF;

    for (int u = 1; u <= v; u++) {
        if (house_exist[u] && dist_from_m[u] <= x && dist_from_s[u] <= y) {
            ans = min(ans, dist_from_m[u] + dist_from_s[u]);
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}
