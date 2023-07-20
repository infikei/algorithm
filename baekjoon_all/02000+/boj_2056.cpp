// Solve 2023-07-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dt[10001], t[10001], in_degree[10001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int> > child(n + 1, vector<int>());

    for (int u = 1; u <= n; u++) {
        int pu_cnt;
        cin >> dt[u] >> pu_cnt;

        for (int i = 0; i < pu_cnt; i++) {
            int pu;
            cin >> pu;
            child[pu].push_back(u);
            in_degree[u]++;
        }
    }

    queue<int> que;

    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            que.push(u);
            t[u] = dt[u];
        }
    }

    int ans = 0;

    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ans = max(ans, t[u]);

        for (int nu : child[u]) {
            t[nu] = max(t[nu], t[u] + dt[nu]);
            in_degree[nu]--;

            if (in_degree[nu] == 0) {
                que.push(nu);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
