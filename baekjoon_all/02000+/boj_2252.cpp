// Solve 2023-05-02
// Update 2023-07-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n + 1, vector<int>());
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, nu;
        cin >> u >> nu;
        adj[u].push_back(nu);
        in_degree[nu]++;
    }

    queue<int> que;
    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            que.push(u);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
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

    for (int a : ans) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
