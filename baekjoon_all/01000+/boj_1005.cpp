// Solve 2023-06-07
// Update 2023-08-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int build_time[1001], result_time[1001], in_degree[1001];

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, k;
        cin >> n >> k;

        for (int u = 1; u <= n; u++) {
            cin >> build_time[u];

            in_degree[u] = 0;
            result_time[u] = 0;
        }

        vector<vector<int> > adj(n + 1, vector<int>());

        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            in_degree[v]++;
        }

        int w;
        cin >> w;

        queue<int> que;

        for (int u = 1; u <= n; u++) {
            if (in_degree[u] == 0) {
                que.push(u);
                result_time[u] = build_time[u];
            }
        }

        for (int i = 0; i < n; i++) {
            int u = que.front();
            que.pop();

            for (int v : adj[u]) {
                if (in_degree[v] == 0) continue;

                in_degree[v]--;
                if (in_degree[v] == 0) {
                    que.push(v);
                }

                result_time[v] = max(result_time[v], result_time[u] + build_time[v]);
            }
        }

        cout << result_time[w] << '\n';
    }

    return 0;
}
