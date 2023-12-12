// Solve 2023-12-12

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

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        if (ti >= 2) cout << '\n';

        cout << "Scenario " << ti << ":\n";

        int n, k;
        cin >> n >> k;

        vector<int> parent(n, -1);

        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;

            union_parents(u, v, parent);
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            int pu = get_parent(u, parent);
            int pv = get_parent(v, parent);

            cout << (pu == pv) << '\n';
        }
    }

    return 0;
}
