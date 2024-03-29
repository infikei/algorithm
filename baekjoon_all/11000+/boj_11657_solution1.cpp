// Solve 2023-01-09
// Update 2023-11-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> edges(n + 1, vector<pii>());

    for (int i = 0; i < m; i++) {
        int edge_from, edge_to, edge_cost;
        cin >> edge_from >> edge_to >> edge_cost;

        edges[edge_from].emplace_back(edge_to, edge_cost);
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    int iter = n - 1;

    while (iter > 0) {
        iter--;

        for (int u = 1; u <= n; u++) {
            if (dist[u] == INF) continue;

            for (pii edge : edges[u]) {
                int nu = edge.first;
                ll dist_to_nu = dist[u] + edge.second;

                if (dist[nu] > dist_to_nu) {
                    dist[nu] = dist_to_nu;
                }
            }
        }
    }

    bool flag_has_negative_cycle = false;

    for (int u = 1; u <= n; u++) {
        if (dist[u] == INF) continue;

        for (pii edge : edges[u]) {
            int nu = edge.first;
            ll dist_to_nu = dist[u] + edge.second;

            if (dist[nu] > dist_to_nu) {
                flag_has_negative_cycle = true;
                break;
            }
        }

        if (flag_has_negative_cycle) break;
    }

    if (flag_has_negative_cycle) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }

    return 0;
}
