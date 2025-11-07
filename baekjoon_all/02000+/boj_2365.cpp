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

vector<int> adj[102];
int capa[102][102];
int flow[102][102];
int level[102];
int adj_pos[102];

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int s = 100;
    int t = 101;
    int sum = 0;

    for (int x = 0; x < n; x++) {
        int w;
        cin >> w;
        adj[s].push_back(x);
        adj[x].push_back(s);
        capa[s][x] = w;
        sum += w;
    }

    for (int y = 50; y < 50 + n; y++) {
        int w;
        cin >> w;
        adj[y].push_back(t);
        adj[t].push_back(y);
        capa[y][t] = w;
    }

    for (int x = 0; x < 50; x++) {
        for (int y = 50; y < 100; y++) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    int low = 0;
    int high = 10000;
    int mn = 10000;

    while (low <= high) {
        int mid = (low + high) / 2;

        for (int x = 0; x < 50; x++) {
            for (int y = 50; y < 100; y++) {
                capa[x][y] = mid;
            }
        }

        memset(flow, 0, sizeof flow);
        int fl = dinic(s, t);

        if (fl == sum) {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    for (int x = 0; x < 50; x++) {
        for (int y = 50; y < 100; y++) {
            capa[x][y] = mn;
        }
    }

    memset(flow, 0, sizeof flow);
    dinic(s, t);
    cout << mn << '\n';

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << flow[x][y + 50] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
