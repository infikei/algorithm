// Solve 2023-07-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int graph[101][101], in_degree[101];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int> > child(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, pu, k;
        cin >> u >> pu >> k;

        graph[u][pu] += k;
        child[pu].push_back(u);
        in_degree[u]++;
    }

    queue<int> que;

    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            que.push(u);
            graph[u][u] = 1;
        }
    }

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int nu : child[u]) {
            int x = graph[nu][u];
            graph[nu][u] = 0;

            for (int v = 1; v <= n; v++) {
                graph[nu][v] += graph[u][v] * x;
            }

            in_degree[nu]--;
            if (in_degree[nu] == 0) {
                que.push(nu);
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        if (graph[n][v] != 0) {
            cout << v << ' ' << graph[n][v] << '\n';
        }
    }

    return 0;
}
