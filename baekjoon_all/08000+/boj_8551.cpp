// Solve 2025-11-06

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

struct AdjEdge{
    int to, capa, flow, rev;

    AdjEdge(int to, int capa, int flow, int rev) : to(to), capa(capa), flow(flow), rev(rev) {
    }
};

vector<AdjEdge> adj[10001];
int level[10001];
int adj_pos[10001];

void add_edge(int u, int v, int w) {
    adj[u].emplace_back(v, w, 0, size(adj[v]));
    adj[v].emplace_back(u, 0, 0, size(adj[u]) - 1);
}

bool dinic_bfs(int s, int t) {
    queue<int> que;
    memset(level, -1, sizeof level);
    que.push(s);
    level[s] = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (AdjEdge& e : adj[cur]) {
            int nxt = e.to;

            if (level[nxt] == -1 && e.capa > e.flow) {
                level[nxt] = level[cur] + 1;
                que.push(nxt);
            }
        }
    }

    return level[t] != -1;
}

int dinic_dfs(int cur, int t, int cur_flow) {
    if (cur == t) return cur_flow;

    for (int& i = adj_pos[cur]; i < size(adj[cur]); i++) {
        auto& e = adj[cur][i];
        int nxt = e.to;

        if (level[nxt] == level[cur] + 1 && e.capa > e.flow) {
            int fl = dinic_dfs(nxt, t, min(cur_flow, e.capa - e.flow));

            if (fl > 0) {
                e.flow += fl;
                adj[nxt][e.rev].flow -= fl;
                return fl;
            }
        }
    }

    return 0;
}

int dinic(int s, int t) {
    int ret = 0;

    while (dinic_bfs(s, t)) {
        memset(adj_pos, 0, sizeof adj_pos);

        while (true) {
            int fl = dinic_dfs(s, t, INF);
            ret += fl;

            if (fl == 0) break;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    while (m-- > 0) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, 1);
    }

    cout << dinic(1, n) << '\n';
    return 0;
}
