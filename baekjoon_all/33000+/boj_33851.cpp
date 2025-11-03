// Solve 2025-10-30

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

vector<int> adj[2001];
int u_dist[2001];
int v_dist[2001];

int solution(int u, int v) {
    memset(u_dist, 0x3f, sizeof u_dist);
    memset(v_dist, 0x3f, sizeof v_dist);

    queue<int> que;
    que.push(u);
    u_dist[u] = 0;
    int bfs_depth = 0;

    while (!que.empty()) {
        bfs_depth++;
        int iter = size(que);

        while (iter-- > 0) {
            int cur = que.front();
            que.pop();

            for (int nxt : adj[cur]) {
                if (u_dist[nxt] != INF) continue;

                u_dist[nxt] = bfs_depth;
                que.push(nxt);
            }
        }
    }

    int ret = INF;
    que.push(v);
    v_dist[v] = 0;
    ret = min(ret, max(u_dist[v], v_dist[v]));
    bfs_depth = 0;

    while (!que.empty()) {
        bfs_depth++;
        int iter = size(que);

        while (iter-- > 0) {
            int cur = que.front();
            que.pop();

            for (int nxt : adj[cur]) {
                if (v_dist[nxt] != INF) continue;

                v_dist[nxt] = bfs_depth;
                que.push(nxt);
                ret = min(ret, max(u_dist[nxt], v_dist[nxt]));
            }
        }
    }

    return ret == INF ? -1 : ret;
}

int main() {
    FASTIO;

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    while (q-- > 0) {
        int u, v;
        cin >> u >> v;
        cout << solution(u, v) << '\n';
    }

    return 0;
}
