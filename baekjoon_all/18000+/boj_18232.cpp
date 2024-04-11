// Solve 2024-04-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<int> adj[300001];
bool visited[300001];

int main() {
    FASTIO;

    int n, m, s, e;
    cin >> n >> m >> s >> e;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int ans = 0;
    visited[s] = true;
    queue<int> bfs_que;
    bfs_que.push(s);

    while (!bfs_que.empty()) {
        int bfs_iter = SIZE(bfs_que);
        ans++;

        while (bfs_iter-- > 0) {
            int cur = bfs_que.front();
            bfs_que.pop();

            if (cur >= 2 && !visited[cur - 1]) {
                visited[cur - 1] = true;
                bfs_que.push(cur - 1);

                if (cur - 1 == e) break;
            }

            if (cur + 1 <= n && !visited[cur + 1]) {
                visited[cur + 1] = true;
                bfs_que.push(cur + 1);

                if (cur + 1 == e) break;
            }

            for (int nxt : adj[cur]) {
                if (visited[nxt]) continue;

                visited[nxt] = true;
                bfs_que.push(nxt);

                if (nxt == e) break;
            }

            if (visited[e]) break;
        }

        if (visited[e]) break;
    }

    cout << ans << '\n';

    return 0;
}
