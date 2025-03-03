// Solve 2023-06-07
// Update 2025-03-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int build_time[501];
int result_time[501];
int in_degree[501];

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>());

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

    queue<int> que;

    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            que.push(u);
            result_time[u] = build_time[u];
        }
    }

    for (int i = 0; i < n; i++) {
        int cur = que.front();
        que.pop();

        for (int nxt : adj[cur]) {
            if (in_degree[nxt] == 0) continue;

            in_degree[nxt]--;

            if (in_degree[nxt] == 0) {
                que.push(nxt);
            }

            result_time[nxt] = max(result_time[nxt], result_time[cur] + build_time[nxt]);
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << result_time[u] << '\n';
    }

    return 0;
}
