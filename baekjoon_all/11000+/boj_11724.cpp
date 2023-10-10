// Solve 2022-07-26
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

    int n, m;
    cin >> n >> m;

    vector<bool> visited(n + 1, false);
    vector<vector<int> > adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int connected_components_num = 0;

    for (int u = 1; u <= n; u++) {
        if (visited[u]) continue;

        connected_components_num++;
        visited[u] = true;
        queue<int> que;
        que.push(u);

        while (!que.empty()) {
            int now = que.front();
            que.pop();

            for (int next : adj[now]) {
                if (visited[next]) continue;

                visited[next] = true;
                que.push(next);
            }
        }
    }

    cout << connected_components_num << '\n';

    return 0;
}
