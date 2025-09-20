// Solve 2025-09-19

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
    int to, cost, dist;

    AdjNode(int to, int cost, int dist) : to(to), cost(cost), dist(dist) {
    }

    bool operator<(const AdjNode& rhs) const {
        return dist < rhs.dist;
    }

    bool operator>(const AdjNode& rhs) const {
        return rhs < *this;
    }
};

vector<AdjNode> adj[101];
int memo[101][10001];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = 0; i < k; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u].emplace_back(v, c, d);
        }

        for (int u = 1; u <= n; u++) {
            sort(adj[u].begin(), adj[u].end());
        }

        priority_queue<AdjNode, vector<AdjNode>, greater<AdjNode>> pq_mintop;
        memset(memo, 0x3f, sizeof memo);
        memo[1][0] = 0;
        pq_mintop.emplace(1, 0, 0);

        while (!pq_mintop.empty()) {
            AdjNode cur = pq_mintop.top();
            pq_mintop.pop();

            if (cur.dist > memo[cur.to][cur.cost]) continue;

            for (AdjNode& nxt : adj[cur.to]) {
                int n_dist = cur.dist + nxt.dist;
                int n_cost = cur.cost + nxt.cost;

                if (n_cost <= m && n_dist < memo[nxt.to][n_cost]) {
                    for (int c = n_cost; c <= m; c++) {
                        if (n_dist >= memo[nxt.to][c]) {
                            break;
                        }

                        memo[nxt.to][c] = n_dist;
                    }

                    pq_mintop.emplace(nxt.to, n_cost, n_dist);
                }
            }
        }

        int ans = INF;

        for (int c = 0; c <= m; c++) {
            ans = min(ans, memo[n][c]);
        }

        if (ans == INF) {
            cout << "Poor KCM" << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
