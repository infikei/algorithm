// Solve 2024-01-14

#include <iostream>
#include <queue>

using namespace std;

int adj[101][101];
int visited[101];

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }

            visited[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        int ans = 0;

        for (int u = 1; u <= n; u++) {
            if (visited[u]) continue;

            ans++;
            visited[u] = 1;
            queue<int> bfs_que;
            bfs_que.push(u);

            while (!bfs_que.empty()) {
                int cur = bfs_que.front();
                bfs_que.pop();

                for (int nxt = 1; nxt <= n; nxt++) {
                    if (!visited[nxt] && adj[cur][nxt]) {
                        visited[nxt] = 1;
                        bfs_que.push(nxt);
                    }
                }
            }
        }

        cout << '#' << ti << ' ' << ans << '\n';
    }

    return 0;
}
