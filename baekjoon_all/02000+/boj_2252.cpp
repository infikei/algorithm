// Solve 2023-05-02
// Update 2024-02-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        in_degree[to]++;
    }

    queue<int> bfs_que;

    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            bfs_que.push(u);
        }
    }

    for (int i = 0; i < n; i++) {
        int u = bfs_que.front();
        bfs_que.pop();
        cout << u << ' ';

        for (int nu : adj[u]) {
            if (--in_degree[nu] == 0) {
                bfs_que.push(nu);
            }
        }
    }

    cout << '\n';

    return 0;
}
