// Solve 2022-09-17
// Update 2023-12-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int get_parent(int u, vector<int> &parent) {
    if (parent[u] < 0) {
        return u;
    }

    return parent[u] = get_parent(parent[u], parent);
}

void union_parents(int u, int v, vector<int> &parent) {
    int pu = get_parent(u, parent);
    int pv = get_parent(v, parent);

    if (pu != pv) {
        if (parent[pu] <= parent[pv]) {
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

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 0) {
            union_parents(a, b, parent);
        }
        else {
            int pa = get_parent(a, parent);
            int pb = get_parent(b, parent);

            cout << (pa == pb ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
