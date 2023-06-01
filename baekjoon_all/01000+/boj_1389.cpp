// Solve 2023-05-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int INF = 1e9;
int n, m;
int graph[101][101];

int main() {
    FASTIO;

    cin >> n >> m;
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            graph[u][v] = graph[v][u] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    // floyd-warshall
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (graph[j][i] != INF && graph[i][k] != INF) {
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                }
            }
        }
    }

    int ans = 0, min_kevin_num = INF;
    for (int i = 1; i <= n; i++) {
        int kevin_num = 0;
        for (int j = 1; j <= n; j++) {
            kevin_num += graph[i][j];
        }

        if (min_kevin_num > kevin_num) {
            min_kevin_num = kevin_num;
            ans = i;
        }
    }
    cout << ans << '\n';

    return 0;
}
