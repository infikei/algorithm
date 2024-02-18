// Solve 2022-07-24
// Update 2024-02-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, start_node;
    cin >> n >> m >> start_node;

    vector<int> adj[1001];

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
    }

    bool visited[1001] = { false };
    vector<int> dfs_stack;
    visited[start_node] = true;
    dfs_stack.push_back(start_node);
    cout << start_node << ' ';

    while (!dfs_stack.empty()) {
        int cur = dfs_stack.back();
        dfs_stack.pop_back();

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                dfs_stack.push_back(cur);
                dfs_stack.push_back(next);
                cout << next << ' ';
                break;
            }
        }
    }

    cout << '\n';

    for (int u = 1; u <= n; u++) {
        visited[u] = false;
    }

    queue<int> bfs_que;
    visited[start_node] = true;
    bfs_que.push(start_node);

    while (!bfs_que.empty()) {
        int cur = bfs_que.front();
        bfs_que.pop();
        cout << cur << ' ';

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                bfs_que.push(next);
            }
        }
    }

    cout << '\n';

    return 0;
}
