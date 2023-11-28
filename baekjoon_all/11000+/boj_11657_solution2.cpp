// Solve 2023-01-09
// Update 2023-11-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int INF = 1e9;

struct Edge{
    int from, to, cost;

    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {};
};

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int edge_from, edge_to, edge_cost;
        cin >> edge_from >> edge_to >> edge_cost;

        edges.emplace_back(edge_from, edge_to, edge_cost);
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    int iter = n - 1;

    while (iter > 0) {
        iter--;

        for (Edge edge : edges) {
            if (dist[edge.from] == INF) continue;

            dist[edge.to] = min(dist[edge.to], dist[edge.from] + edge.cost);
        }
    }

    bool flag_has_negative_cycle = false;

    for (Edge edge : edges) {
        if (dist[edge.from] == INF) continue;

        if (dist[edge.to] > dist[edge.from] + edge.cost) {
            flag_has_negative_cycle = true;
            break;
        }
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
