// Solve 2023-10-10
// Update 2023-10-11

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

    vector<bool> visited(n + 1, false);
    queue<int> que;
    ll visit_num = 0, depth = 0, ans = 0;

    ans += ++visit_num * depth;
    visited[r] = true;
    que.push(r);

    while (!que.empty()) {
        depth++;

        for (int i = 0, ie = SIZE(que); i < ie; i++) {
            int now = que.front();
            que.pop();

            for (int &next : adj[now]) {
                if (visited[next]) continue;

                ans += ++visit_num * depth;
                visited[next] = true;
                que.push(next);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
