#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pi3 = pair<int, pii>;

const int MAX_V = 1000000;
int v, e;
int parent[MAX_V];
priority_queue<pi3, vector<pi3>, greater<pi3> > edges;

int get_parent(int k) {
    if (parent[k] < 0) {
        return k;
    }

    parent[k] = get_parent(parent[k]);
    return parent[k];
}

void union_parents(int u, int v) {
    int pu = get_parent(u);
    int pv = get_parent(v);

    if (pu != pv) {
        if (parent[pu] < parent[pv]) {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

int main() {
    FASTIO;

    // 여기에서는 크루스칼 알고리즘을 이용하였다.

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges.push({ dist, { from, to } });
    }

    for (int i = 0; i < v; i++) {
        parent[i] = -1;
    }

    int ans = 0; // 최소 비용 신장 트리를 만들기 위한 비용

    while (!edges.empty()) {
        pi3 edge = edges.top();
        edges.pop();

        int u = edge.second.first;
        int v = edge.second.second;

        int pu = get_parent(u);
        int pv = get_parent(v);

        if (pu != pv) {
            ans += edge.first;

            // 시간 단축을 위해 node 개수가 더 많은 쪽으로 합쳐준다.
            if (parent[pu] < parent[pv]) {
                parent[pu] += parent[pv];
                parent[pv] = pu;
            }
            else {
                parent[pv] += parent[pu];
                parent[pu] = pv;
            }
        }
    }

    return 0;
}