// Solve 2023-06-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int build_time[501], result_time[501], in_degree[501];

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int> > adj(n + 1, vector<int>());

    for (int u = 1; u <= n; u++) {
        cin >> build_time[u];

        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;

            adj[v].push_back(u);
            in_degree[u]++;
        }
    }

    queue<int> q;

    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            q.push(u);
            result_time[u] = build_time[u];
        }
    }

    for (int i = 0; i < n; i++) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (in_degree[v] == 0) continue;

            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }

            result_time[v] = max(result_time[v], result_time[u] + build_time[v]);
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << result_time[u] << '\n';
    }

    return 0;
}
