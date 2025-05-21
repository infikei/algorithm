// Solve 2025-05-18

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

vector<int> adj[100001];
int depth[100001];
int parent[17][100001];

void dfs(int dep, int cur, int par) {
    depth[cur] = dep;

    for (int nxt : adj[cur]) {
        if (nxt == par) continue;

        parent[0][nxt] = cur;
        dfs(dep + 1, nxt, cur);
    }
}

int find_LCA(int u1, int u2) {
    if (depth[u1] < depth[u2]) {
        swap(u1, u2);
    }

    int diff = depth[u1] - depth[u2];

    for (int i = 0; i < 17; i++) {
        if (diff & (1 << i)) {
            u1 = parent[i][u1];
        }
    }

    if (u1 == u2) return u1;

    for (int i = 16; i >= 0; i--) {
        if (parent[i][u1] != parent[i][u2]) {
            u1 = parent[i][u1];
            u2 = parent[i][u2];
        }
    }

    return parent[0][u1];
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1, 0);

    for (int i = 1; i < 17; i++) {
        for (int j = 1; j <= n; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    int m;
    cin >> m;

    while (m-- > 0) {
        int u1, u2;
        cin >> u1 >> u2;

        cout << find_LCA(u1, u2) << '\n';
    }

    return 0;
}
