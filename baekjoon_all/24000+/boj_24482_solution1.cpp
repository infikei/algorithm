// Solve 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<vector<int> > adj;
vector<int> visited;

void dfs(int now, int depth) {
    visited[now] = depth;

    for (int &next : adj[now]) {
        if (visited[next] != -1) continue;

        dfs(next, depth + 1);
    }
}

int main() {
    FASTIO;

    int n, m, r;
    cin >> n >> m >> r;

    adj.assign(n + 1, vector<int>());
    visited.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end(), greater<int>());
    }

    dfs(r, 0);

    for (int u = 1; u <= n; u++) {
        cout << visited[u] << '\n';
    }

    return 0;
}
