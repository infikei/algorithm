// Solve 2023-10-10

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

    vector<int> visited(n + 1, -1);
    queue<int> que;
    int depth = 0;

    visited[r] = depth;
    que.push(r);

    while (!que.empty()) {
        depth++;

        for (int i = 0, ie = SIZE(que); i < ie; i++) {
            int now = que.front();
            que.pop();

            for (int &next : adj[now]) {
                if (visited[next] != -1) continue;

                visited[next] = depth;
                que.push(next);
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << visited[u] << '\n';
    }

    return 0;
}
