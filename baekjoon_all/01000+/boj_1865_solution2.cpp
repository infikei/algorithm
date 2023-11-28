// Solve 2023-02-13
// Update 2023-11-28

// 이 문제에서는 시작 정점을 1개로 설정하지 않고 모든 정점을 시작 정점으로 설정한다.
// 이는 각각의 정점에 대해 거리의 초기값을 INF가 아닌 0으로 설정하고 풀어야 한다는 의미이다.
// 자세한 설명은 https://www.acmicpc.net/board/view/72995 에 나와있으므로 해당 설명을 참고한다.

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Edge{
    int from, to, cost;

    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

int main() {
    FASTIO;

    int tc;
    cin >> tc;

    for (int tci = 0; tci < tc; tci++) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<Edge> edges;

        for (int i = 0; i < m; i++) {
            int edge_from, edge_to, edge_cost;
            cin >> edge_from >> edge_to >> edge_cost;

            edges.emplace_back(edge_from, edge_to, edge_cost);
            edges.emplace_back(edge_to, edge_from, edge_cost);
        }

        for (int i = 0; i < w; i++) {
            int edge_from, edge_to, edge_cost;
            cin >> edge_from >> edge_to >> edge_cost;

            edges.emplace_back(edge_from, edge_to, -edge_cost);
        }

        vector<ll> cost(n + 1, 0);
        int iter = n - 1;

        while (iter > 0) {
            iter--;

            for (Edge edge : edges) {
                cost[edge.to] = min(cost[edge.to], cost[edge.from] + edge.cost);
            }
        }

        bool flag_has_negative_cycle = false;

        for (Edge edge : edges) {
            if (cost[edge.to] > cost[edge.from] + edge.cost) {
                flag_has_negative_cycle = true;
                break;
            }
        }

        if (flag_has_negative_cycle) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
