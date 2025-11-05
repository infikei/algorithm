// Solve 2025-11-05

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

vector<int> adj[503];
int capa[503][503];
int flow[503][503];
int level[503]; // 유량이 흐를 수 있는 간선으로만 BFS 수행 시 각 정점의 level
int adj_pos[503]; // 정점 u에 연결된 간선 중 몇 번째부터 탐색할지 정보를 저장
bool bipartite[503]; // A진영이라면 true, B진영이라면 false

bool dinic_bfs(int s, int t) {
    queue<int> que;
    memset(level, -1, sizeof level);
    que.push(s);
    level[s] = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int nxt : adj[cur]) {
            if (level[nxt] == -1 && capa[cur][nxt] > flow[cur][nxt]) {
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
        int nxt = adj[cur][i];

        if (level[nxt] == level[cur] + 1 && capa[cur][nxt] > flow[cur][nxt]) {
            int fl = dinic_dfs(nxt, t, min(cur_flow, capa[cur][nxt] - flow[cur][nxt]));

            if (fl > 0) {
                flow[cur][nxt] += fl;
                flow[nxt][cur] -= fl;
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

void make_bipartite(int s) {
    queue<int> que;
    que.push(s);
    bipartite[s] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int nxt : adj[cur]) {
            if (!bipartite[nxt] && capa[cur][nxt] > flow[cur][nxt]) {
                bipartite[nxt] = true;
                que.push(nxt);
            }
        }
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int s = 501;
    int t = 502;

    for (int u = 1; u <= n; u++) {
        int x;
        cin >> x;

        if (x == 1) {
            adj[s].push_back(u);
            adj[u].push_back(s);
            capa[s][u] = INF;
        }
        else if (x == 2) {
            adj[u].push_back(t);
            adj[t].push_back(u);
            capa[u][t] = INF;
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            int w;
            cin >> w;

            if (w == 0) continue;

            capa[u][v] = w;
            adj[u].push_back(v);
        }
    }

    cout << dinic(s, t) << '\n';

    make_bipartite(s);

    for (int u = 1; u <= n; u++) {
        if (bipartite[u]) {
            cout << u << ' ';
        }
    }

    cout << '\n';

    for (int u = 1; u <= n; u++) {
        if (!bipartite[u]) {
            cout << u << ' ';
        }
    }

    cout << '\n';

    return 0;
}
