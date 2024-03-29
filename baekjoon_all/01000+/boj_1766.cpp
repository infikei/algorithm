// Solve 2023-05-02

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    priority_queue<int, vector<int>, greater<int> > pq_mintop;
    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            pq_mintop.push(u);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int u = pq_mintop.top();
        pq_mintop.pop();
        ans.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                pq_mintop.push(v);
            }
        }
    }

    for (int u : ans) {
        cout << u << ' ';
    }
    cout << '\n';

    return 0;
}
