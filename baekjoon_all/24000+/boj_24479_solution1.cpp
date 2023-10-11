// Solve 2022-09-24
// Update 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int visit_num;
vector<vector<int> > adj;
vector<int> visited;

void dfs(int now) {
    visited[now] = ++visit_num;

    for (int &next : adj[now]) {
        if (visited[next] != 0) continue;

        dfs(next);
    }
}

int main() {
    FASTIO;

    int n, m, r;
    cin >> n >> m >> r;

    adj.assign(n + 1, vector<int>());
    visited.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
    }

    dfs(r);

    for (int u = 1; u <= n; u++) {
        cout << visited[u] << '\n';
    }

    return 0;
}
