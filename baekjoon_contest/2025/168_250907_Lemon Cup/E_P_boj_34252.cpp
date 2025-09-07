// Solve 2025-09-07

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
const int MOD = 998244353;

struct AdjNode{
    int to;
    ll cost;

    AdjNode(int to, ll cost) : to(to), cost(cost) {
    }
};

struct LemonPath{
    ll cost_sum;
    ll edge_cnt;
    int edge_level;

    LemonPath(ll cost_sum, ll edge_cnt, int edge_level) : cost_sum(cost_sum), edge_cnt(edge_cnt), edge_level(edge_level) {
    }
};

ll mod_pow(ll a, int p) {
    ll ret = 1;

    while (p > 0) {
        if (p & 1) {
            ret = ret * a % MOD;
        }

        a = a * a % MOD;
        p >>= 1;
    }

    return ret;
}

ll mod_inv(ll a) {
    return mod_pow(a, MOD - 2);
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<vector<AdjNode>> adj(n + 1, vector<AdjNode>());

    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<LemonPath> lemon_path(n + 1, LemonPath(0, 0, -1));
    queue<int> que;
    que.push(1);
    lemon_path[1] = {0, 1, 0};

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (AdjNode& nxt_node : adj[cur]) {
            int nxt = nxt_node.to;

            if (lemon_path[nxt].edge_level == -1) {
                lemon_path[nxt].cost_sum = (lemon_path[cur].cost_sum + (nxt_node.cost * lemon_path[cur].edge_cnt % MOD)) % MOD;
                lemon_path[nxt].edge_cnt = lemon_path[cur].edge_cnt;
                lemon_path[nxt].edge_level = lemon_path[cur].edge_level + 1;
                que.push(nxt);
            }
            else if (lemon_path[nxt].edge_level == lemon_path[cur].edge_level + 1) {
                lemon_path[nxt].cost_sum = (lemon_path[nxt].cost_sum + lemon_path[cur].cost_sum + (nxt_node.cost * lemon_path[cur].edge_cnt % MOD)) % MOD;
                lemon_path[nxt].edge_cnt = (lemon_path[nxt].edge_cnt + lemon_path[cur].edge_cnt) % MOD;
            }
        }
    }

    for (int u = 2; u <= n; u++) {
        ll ret = lemon_path[u].cost_sum * mod_inv(lemon_path[u].edge_cnt) % MOD;
        cout << ret << '\n';
    }

    return 0;
}
