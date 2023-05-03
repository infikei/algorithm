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

    int t;
    cin >> t;

    vector<int> vec;
    vector<vector<int> > adj;
    vector<int> in_degree;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        vec.assign(n + 1, 0);
        adj.assign(n + 1, vector<int>(n + 1, 0));
        in_degree.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> vec[i];

            for (int j = 1; j < i; j++) {
                adj[vec[j]][vec[i]] = 1;
                in_degree[vec[i]]++;
            }
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            if (adj[u][v] == 1) {
                adj[u][v] = 0;
                adj[v][u] = 1;
                in_degree[v]--;
                in_degree[u]++;
            }
            else {
                adj[u][v] = 1;
                adj[v][u] = 0;
                in_degree[v]++;
                in_degree[u]--;
            }
        }

        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (in_degree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (q.empty()) {
                break;
            }

            int u = q.front();
            q.pop();
            ans.push_back(u);

            for (int v = 1; v <= n; v++) {
                if (adj[u][v] == 1) {
                    in_degree[v]--;
                    if (in_degree[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }

        if (SIZE(ans) < n) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            for (int u : ans) {
                cout << u << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
