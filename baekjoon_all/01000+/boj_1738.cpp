// Solve 2023-11-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e10;

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

    vector<ll> cost(n + 1, -INF);
    vector<ll> parent(n + 1, -1);
    cost[1] = 0;
    int iter = n - 1;

    while (iter > 0) {
        iter--;

        for (int u = 1; u <= n; u++) {
            if (cost[u] == -INF) continue;

            for (pii edge : edges[u]) {
                int nu = edge.first;
                ll cost_update = cost[u] + edge.second;

                if (cost[nu] < cost_update) {
                    cost[nu] = cost_update;
                    parent[nu] = u;
                }
            }
        }
    }

    // 양의 사이클이 존재하고 양의 사이클에서 정점 n으로 이동하는 경로가 존재하는지 여부
    bool flag_has_positive_cycle = false;

    if (cost[n] != -INF) {
        queue<int> bfs_que;
        vector<bool> visited(n + 1, false);

        for (int u = 1; u <= n; u++) {
            if (cost[u] == -INF) continue;

            for (pii edge : edges[u]) {
                int nu = edge.first;
                ll cost_update = cost[u] + edge.second;

                if (cost[nu] < cost_update) {
                    cost[nu] = cost_update;

                    if (!visited[nu]) {
                        visited[nu] = true;
                        bfs_que.push(nu);
                    }
                }
            }
        }

        while (!bfs_que.empty()) {
            int u = bfs_que.front();
            bfs_que.pop();

            for (pii edge : edges[u]) {
                int nu = edge.first;

                if (!visited[nu]) {
                    visited[nu] = true;
                    bfs_que.push(nu);
                }
            }
        }

        if (visited[n]) {
            flag_has_positive_cycle = true;
        }
    }

    if (cost[n] == -INF || flag_has_positive_cycle) {
        cout << -1 << '\n';
    }
    else {
        vector<int> route;
        int cur = n;

        while (cur != -1) {
            route.push_back(cur);
            cur = parent[cur];
        }

        for (auto it = route.rbegin(); it != route.rend(); it++) {
            cout << *it << ' ';
        }

        cout << '\n';
    }

    return 0;
}
