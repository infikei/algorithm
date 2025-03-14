// Solve 2025-03-14

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Edge{
    int from;
    int to;

    Edge(int from, int to) : from(from), to(to) {
    }
};

int parents[1001];

void init_parents(int n) {
    for (int u = 1; u <= n; u++) {
        parents[u] = -1;
    }
}

int get_parent_of(int u) {
    if (parents[u] < 0) return u;

    return parents[u] = get_parent_of(parents[u]);
}

bool union_parents(int u1, int u2) {
    u1 = get_parent_of(u1);
    u2 = get_parent_of(u2);

    if (u1 == u2) return false;

    if (parents[u1] < parents[u2]) {
        parents[u1] += parents[u2];
        parents[u2] = u1;
    }
    else {
        parents[u2] += parents[u1];
        parents[u1] = u2;
    }

    return true;
}

int main() {
    FASTIO;

    while (true) {
        int n, m, k;
        cin >> n >> m >> k;

        if (n == 0) break;

        vector<Edge> red_edges, blue_edges;

        for (int i = 0; i < m; i++) {
            char color;
            int from, to;
            cin >> color >> from >> to;

            if (color == 'R') {
                red_edges.emplace_back(from, to);
            }
            else {
                blue_edges.emplace_back(from, to);
            }
        }

        init_parents(n);
        int edge_cnt = 0;
        int min_blue_edge_cnt = 0;

        for (Edge &edge : red_edges) {
            if (union_parents(edge.from, edge.to)) {
                edge_cnt++;

                if (edge_cnt == n - 1) break;
            }
        }

        if (edge_cnt < n - 1) {
            for (Edge &edge : blue_edges) {
                if (union_parents(edge.from, edge.to)) {
                    edge_cnt++;
                    min_blue_edge_cnt++;

                    if (edge_cnt == n - 1) break;
                }
            }
        }

        init_parents(n);
        edge_cnt = 0;
        int max_blue_edge_cnt = 0;

        for (Edge &edge : blue_edges) {
            if (union_parents(edge.from, edge.to)) {
                edge_cnt++;
                max_blue_edge_cnt++;

                if (edge_cnt == n - 1) break;
            }
        }

        if (edge_cnt < n - 1) {
            for (Edge &edge : red_edges) {
                if (union_parents(edge.from, edge.to)) {
                    edge_cnt++;

                    if (edge_cnt == n - 1) break;
                }
            }
        }

        if (min_blue_edge_cnt <= k && k <= max_blue_edge_cnt) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
