// Solve 2023-10-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 0);
    queue<int> que;

    visited[1] = true;
    dist[0]++;
    que.push(1);

    int cur = 0;

    while (!que.empty()) {
        cur++;

        for (int i = 0, ie = SIZE(que); i < ie; i++) {
            int u = que.front();
            que.pop();

            for (int nu : adj[u]) {
                if (visited[nu]) continue;

                visited[nu] = true;
                dist[cur]++;
                que.push(nu);
            }
        }
    }

    ll ans = 1;

    for (int d = 0; d <= n; d++) {
        ans = ans * (dist[d] + 1) % MOD;
    }

    if (--ans < 0) ans += MOD;

    cout << ans << '\n';

    return 0;
}
