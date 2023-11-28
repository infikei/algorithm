// Solve 2023-11-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e12;

int main() {
    FASTIO;

    int n, s, d, m;
    cin >> n >> s >> d >> m;

    vector<vector<pii>> edges(n, vector<pii>());

    for (int i = 0; i < m; i++) {
        int edge_from, edge_to, edge_cost;
        cin >> edge_from >> edge_to >> edge_cost;

        edges[edge_from].emplace_back(edge_to, edge_cost);
    }

    vector<int> earn(n);

    for (int &x : earn) {
        cin >> x;
    }

    vector<ll> money(n, -INF);
    money[s] = earn[s];
    int iter = n - 1;

    while (iter > 0) {
        iter--;

        for (int u = 0; u < n; u++) {
            if (money[u] == -INF) continue;

            for (pii edge : edges[u]) {
                int nu = edge.first;
                ll money_of_nu = money[u] - edge.second + earn[nu];

                if (money[nu] < money_of_nu) {
                    money[nu] = money_of_nu;
                }
            }
        }
    }

    if (money[d] == -INF) {
        cout << "gg\n";
    }
    else {
        queue<int> bfs_que;
        vector<bool> visited(n, false);

        for (int u = 0; u < n; u++) {
            if (money[u] == -INF) continue;

            for (pii edge : edges[u]) {
                int nu = edge.first;
                ll money_of_nu = money[u] - edge.second + earn[nu];

                if (money[nu] < money_of_nu) {
                    money[nu] = money_of_nu;

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

        if (visited[d]) {
            cout << "Gee\n";
        }
        else {
            cout << money[d] << '\n';
        }
    }

    return 0;
}
