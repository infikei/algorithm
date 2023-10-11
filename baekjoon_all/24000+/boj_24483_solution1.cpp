// Solve 2023-10-10
// Update 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll visit_num, ans;
vector<vector<int> > adj;
vector<bool> visited;

void dfs(int now, int depth) {
    visited[now] = true;
    ans += ++visit_num * depth;

    for (int &next : adj[now]) {
        if (visited[next]) continue;

        dfs(next, depth + 1);
    }
}

int main() {
    FASTIO;

    int n, m, r;
    cin >> n >> m >> r;

    adj.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
    }

    dfs(r, 0);

    cout << ans << '\n';

    return 0;
}
