// Solve 2023-07-16

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

    vector<vector<int> > adj(n + 1, vector<int>());
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int k, u, nu;
        cin >> k >> u;

        for (int j = 1; j < k; j++) {
            cin >> nu;

            in_degree[nu]++;
            adj[u].push_back(nu);

            u = nu;
        }
    }

    queue<int> que;
    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            que.push(u);
        }
    }

    vector<int> ans;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ans.push_back(u);

        for (int nu : adj[u]) {
            in_degree[nu]--;
            if (in_degree[nu] == 0) {
                que.push(nu);
            }
        }
    }

    if (SIZE(ans) < n) {
        cout << 0 << '\n';
    }
    else {
        for (int a : ans) {
            cout << a << '\n';
        }
    }

    return 0;
}
