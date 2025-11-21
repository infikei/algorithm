// Solve 2025-11-20

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
    int to, w;

    AdjNode(int to, int w) : to(to), w(w) {
    }

    bool operator<(const AdjNode& rhs) const {
        if (w != rhs.w) {
            return w > rhs.w;
        }

        return to < rhs.to;
    }
};

vector<AdjNode> adj[1001];
int memo[1001];

int dijkstra(int s, int t, int cost_limit) {
    priority_queue<AdjNode> pq;
    pq.emplace(s, 0);
    memset(memo, 0x3f, sizeof memo);
    memo[s] = 0;

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (d > memo[u]) continue;
        if (u == t) {
            return d;
        }

        for (auto [nu, w] : adj[u]) {
            int nd = d + (w > cost_limit ? 1 : 0);

            if (nd < memo[nu]) {
                memo[nu] = nd;
                pq.emplace(nu, nd);
            }
        }
    }

    return INF;
}

int main() {
    FASTIO;

    int n, p, k;
    cin >> n >> p >> k;

    while (p-- > 0) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int low = 0;
    int high = 1000000;
    int mn = INF;

    while (low <= high) {
        int mid = (low + high) / 2;
        int val = dijkstra(1, n, mid);

        if (val <= k) {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << (mn == INF ? -1 : mn) << '\n';
    return 0;
}
