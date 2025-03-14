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
    int weight;
    int num;

    Edge(int from, int to, int weight, int num) : from(from), to(to), weight(weight), num(num) {
    }

    bool operator<(const Edge &rhs) const {
        return weight < rhs.weight;
    }
};

int parents[200001];

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

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 1; i <= m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        edges.emplace_back(from, to, weight, i);
    }

    // 잘 생각해보면 문제의 조건에 따라 n = 1, n = 2인 경우는 여기서 걸러진다.
    // 문제에서 주어지는 그래프가 연결 그래프이고 어떤 두 정점을 잇는 간선은 최대 1개이기 때문이다.
    if (m == n - 1) {
        cout << "NO" << '\n';
        return 0;
    }

    sort(edges.begin(), edges.end());
    init_parents(n);
    set<int> mst_edges;
    int mst_edge_cnt = 0;

    for (Edge &edge : edges) {
        if (union_parents(edge.from, edge.to)) {
            mst_edges.insert(edge.num);
            mst_edge_cnt++;

            if (mst_edge_cnt == n - 1) break;
        }
    }

    init_parents(n);
    vector<int> mmst_edges;
    int mmst_edge_cnt = 0;

    for (Edge &edge : edges) {
        if (mst_edges.find(edge.num) == mst_edges.end()) {
            union_parents(edge.from, edge.to);
            mmst_edges.push_back(edge.num);
            mmst_edge_cnt++;
            break;
        }
    }

    for (Edge &edge : edges) {
        if (edge.num == mmst_edges[0]) continue;

        if (union_parents(edge.from, edge.to)) {
            mmst_edges.push_back(edge.num);
            mmst_edge_cnt++;

            if (mmst_edge_cnt == n - 1) break;
        }
    }

    cout << "YES" << '\n';

    for (int &edge_num : mmst_edges) {
        cout << edge_num << ' ';
    }

    cout << '\n';

    return 0;
}
