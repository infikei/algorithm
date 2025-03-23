// Solve 2025-03-22

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
    int from, to, cost;

    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {
    }

    bool operator<(const Edge &rhs) const {
        return cost < rhs.cost;
    }
};

int parents[200001];

void init_parents(int k) {
    for (int u = 1; u <= k; u++) {
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

    int n;
    cin >> n;

    init_parents(n * 2);
    vector<Edge> edges;
    int connected_cnt = 0;

    for (int i = 0; i < n; i++) {
        int c, u1, u2, u3, u4;
        cin >> c >> u1 >> u2 >> u3 >> u4;

        if (union_parents(u1, u2)) {
            connected_cnt++;
        }

        if (union_parents(u3, u4)) {
            connected_cnt++;
        }

        edges.emplace_back(u1, u3, c);
    }

    sort(edges.begin(), edges.end());
    int total_cost = 0;

    for (Edge &edge : edges) {
        if (connected_cnt == n * 2 - 1) {
            break;
        }

        if (union_parents(edge.from, edge.to)) {
            connected_cnt++;
            total_cost += edge.cost;
        }
    }

    cout << total_cost << '\n';

    return 0;
}
