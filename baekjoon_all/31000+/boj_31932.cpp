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
    int d;
    int t;

    AdjNode(int to, int d) : to(to), d(d) {
    }

    AdjNode(int to, int d, int t) : to(to), d(d), t(t) {
    }

    bool operator<(const AdjNode& rhs) const {
        return d < rhs.d;
    }

    bool operator>(const AdjNode& rhs) const {
        return rhs < *this;
    }
};

int min_dist[100001];

void dijkstra(vector<vector<AdjNode>>& adj, int start_node, int start_time) {
    memset(min_dist, 0x3f, sizeof min_dist);
    priority_queue<AdjNode, vector<AdjNode>, greater<AdjNode>> pq_mintop;
    pq_mintop.emplace(start_node, start_time);
    min_dist[start_node] = start_time;

    while (!pq_mintop.empty()) {
        AdjNode cur = pq_mintop.top();
        pq_mintop.pop();

        if (cur.d > min_dist[cur.to]) continue;

        for (AdjNode& nxt : adj[cur.to]) {
            int nxt_dist = cur.d + nxt.d;

            if (nxt_dist <= nxt.t && nxt_dist < min_dist[nxt.to]) {
                min_dist[nxt.to] = nxt_dist;
                pq_mintop.emplace(nxt.to, nxt_dist);
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
        int u1, u2, d, t;
        cin >> u1 >> u2 >> d >> t;
        adj[u1].emplace_back(u2, d, t);
        adj[u2].emplace_back(u1, d, t);
    }

    int low = 0;
    int high = 1000000000;
    int max_start_time = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        dijkstra(adj, 1, mid);

        if (min_dist[n] < INF) {
            max_start_time = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << max_start_time << '\n';
    return 0;
}
