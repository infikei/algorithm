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
    char color;
    int priority; // 반드시 필요한 간선은 1로 설정 (초기값은 0)

    Edge(int from, int to, char color) : from(from), to(to), color(color) {
        priority = 0;
    }
};

struct CmpEdgeWithColor{
    bool operator()(const Edge &e1, const Edge &e2) const {
        return e1.color < e2.color;
    }
};

struct CmpEdgeWithPriority{
    bool operator()(const Edge &e1, const Edge &e2) const {
        if (e1.priority != e2.priority) {
            return e1.priority > e2.priority;
        }

        return e1.color < e2.color;
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

void solution(int n, int m, int k, vector<Edge> &edges) {
    // Blue -> Red 순서로 스패닝 트리 구성하기
    sort(edges.begin(), edges.end(), CmpEdgeWithColor());
    init_parents(n);
    int edge_cnt = 0;
    int max_blue_edge_cnt = 0;

    for (Edge &edge : edges) {
        if (union_parents(edge.from, edge.to)) {
            if (edge.color == 'B') {
                max_blue_edge_cnt++;
            }
            else {
                edge.priority = 1;
            }

            edge_cnt++;

            if (edge_cnt == n - 1) break;
        }
    }

    // Red -> Blue 순서로 스패닝 트리 구성하기
    reverse(edges.begin(), edges.end());
    init_parents(n);
    edge_cnt = 0;
    int min_blue_edge_cnt = 0;

    for (Edge &edge : edges) {
        if (union_parents(edge.from, edge.to)) {
            if (edge.color == 'B') {
                min_blue_edge_cnt++;
                edge.priority = 1;
            }

            edge_cnt++;

            if (edge_cnt == n - 1) break;
        }
    }

    // 불가능하다면 0을 출력하고 종료한다.
    if (k < min_blue_edge_cnt || max_blue_edge_cnt < k) {
        cout << 0 << '\n';
        return;
    }

    // Necessary Blue -> Necessary Red -> Blue -> Red 순서로 스패닝 트리 구성하기
    init_parents(n);
    sort(edges.begin(), edges.end(), CmpEdgeWithPriority());
    edge_cnt = 0;
    int blue_edge_cnt = 0;

    for (Edge &edge : edges) {
        if (edge.color == 'B' && blue_edge_cnt == k) continue;

        if (union_parents(edge.from, edge.to)) {
            cout << edge.from << ' ' << edge.to << '\n';

            if (edge.color == 'B') {
                blue_edge_cnt++;
            }

            edge_cnt++;

            if (edge_cnt == n - 1) break;
        }
    }
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        char color;
        int from, to;
        cin >> color >> from >> to;

        edges.emplace_back(from, to, color);
    }

    solution(n, m, k, edges);

    return 0;
}
