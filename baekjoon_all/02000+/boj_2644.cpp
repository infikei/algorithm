// Solve 2023-02-02
// Update 2024-02-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, u1, u2;
vector<int> adj[101];

int bfs() {
    bool visited[101] = { false };
    queue<int> bfs_que;
    visited[u1] = true;
    bfs_que.push(u1);
    int depth = 0;

    while (!bfs_que.empty()) {
        depth++;
        int iter = SIZE(bfs_que);

        while (iter-- > 0) {
            int cur = bfs_que.front();
            bfs_que.pop();

            for (int next : adj[cur]) {
                if (next == u2) return depth;

                if (!visited[next]) {
                    visited[next] = true;
                    bfs_que.push(next);
                }
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int m;
    cin >> n >> u1 >> u2 >> m;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    cout << bfs() << '\n';

    return 0;
}
