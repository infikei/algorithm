// Solve 2023-06-07
// Update 2024-02-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    int d[1001];
    int ans[1001];
    int in_degree[1001];

    for (int ti = 0; ti < t; ti++) {
        int n, k;
        cin >> n >> k;

        for (int u = 1; u <= n; u++) {
            cin >> d[u];
            in_degree[u] = 0;
            ans[u] = 0;
        }

        vector<vector<int>> adj(n + 1, vector<int>());

        for (int i = 0; i < k; i++) {
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
            in_degree[to]++;
        }

        int w;
        cin >> w;

        queue<int> que;

        for (int u = 1; u <= n; u++) {
            if (in_degree[u] == 0) {
                que.push(u);
                ans[u] = d[u];
            }
        }

        for (int i = 0; i < n; i++) {
            int cur = que.front();
            que.pop();

            for (int next : adj[cur]) {
                ans[next] = max(ans[next], ans[cur] + d[next]);

                if (--in_degree[next] == 0) {
                    que.push(next);
                }
            }
        }

        cout << ans[w] << '\n';
    }

    return 0;
}
