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

vector<int> adj[801];
int parent[801];
int capa[801][801];
int flow[801][801];

bool bfs(int s, int t) {
    queue<int> que;
    memset(parent, -1, sizeof parent);
    que.push(s);
    parent[s] = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int nxt : adj[cur]) {
            if (parent[nxt] == -1 && capa[cur][nxt] > flow[cur][nxt]) {
                parent[nxt] = cur;
                que.push(nxt);

                if (nxt == t) return true;
            }
        }
    }

    return false;
}

int edmonds_karp(int s, int t) {
    int ret = 0;

    while (bfs(s, t)) {
        int cur = t;

        while (cur != s) {
            int prv = parent[cur];
            flow[prv][cur]++;
            flow[cur][prv]--;
            cur = prv;
        }

        ret++;
    }

    return ret;
}

int main() {
    FASTIO;

    int n, p;
    cin >> n >> p;

    for (int u = 1; u <= n; u++) {
        int u_in = u * 2 - 1;
        int u_out = u * 2;
        adj[u_in].push_back(u_out);
        adj[u_out].push_back(u_in);
        capa[u_in][u_out]++;
    }

    while (p-- > 0) {
        int u, v;
        cin >> u >> v;
        int u_in = u * 2 - 1;
        int u_out = u * 2;
        int v_in = v * 2 - 1;
        int v_out = v * 2;

        adj[u_out].push_back(v_in);
        adj[v_in].push_back(u_out);
        capa[u_out][v_in]++;

        adj[v_out].push_back(u_in);
        adj[u_in].push_back(v_out);
        capa[v_out][u_in]++;
    }

    cout << edmonds_karp(2, 3) << '\n';
    return 0;
}
