// Solve 2025-09-13

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
    ll dist;

    AdjNode(int to, ll dist) : to(to), dist(dist) {
    }

    bool operator<(const AdjNode& rhs) const {
        return dist < rhs.dist;
    }

    bool operator>(const AdjNode& rhs) const {
        return rhs < *this;
    }
};

ll min_dist[10001];

void dijkstra(vector<vector<AdjNode>>& adj, int start_node, ll dist_limit) {
    memset(min_dist, 0x3f, sizeof min_dist);
    priority_queue<AdjNode, vector<AdjNode>, greater<AdjNode>> pq_mintop;
    pq_mintop.emplace(start_node, 0);
    min_dist[start_node] = 0;

    while (!pq_mintop.empty()) {
        AdjNode cur = pq_mintop.top();
        pq_mintop.pop();

        if (cur.dist > min_dist[cur.to]) continue;

        for (AdjNode& nxt : adj[cur.to]) {
            if (nxt.dist > dist_limit) continue;

            ll nxt_dist = cur.dist + nxt.dist;

            if (nxt_dist < min_dist[nxt.to]) {
                min_dist[nxt.to] = nxt_dist;
                pq_mintop.emplace(nxt.to, nxt_dist);
            }
        }
    }
}

int main() {
    FASTIO;

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<AdjNode>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int c1, c2, d;
        cin >> c1 >> c2 >> d;
        adj[c1].emplace_back(c2, d);
        adj[c2].emplace_back(c1, d);
    }

    dijkstra(adj, 1, 1000000000);
    ll dist_upper_limit = min_dist[n] * (100 + x) / 100;
    int low = 1;
    int high = 1000000000;
    int min_of_max_dist = 1000000000;

    while (low <= high) {
        int mid = (low + high) / 2;
        dijkstra(adj, 1, mid);

        if (min_dist[n] <= dist_upper_limit) {
            min_of_max_dist = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << min_of_max_dist << '\n';
    return 0;
}
