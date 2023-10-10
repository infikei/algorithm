// Solve 2022-09-24
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int> > adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
    }

    vector<int> visited(n + 1, 0);
    stack<int> stck;

    int cur = 0;
    stck.push(r);

    while (!stck.empty()) {
        int now = stck.top();
        stck.pop();

        if (visited[now] != 0) continue;

        visited[now] = ++cur;

        for (int &next : adj[now]) {
            if (visited[next] != 0) continue;

            stck.push(next);
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << visited[u] << '\n';
    }

    return 0;
}
