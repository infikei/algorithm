// Solve 2023-02-14
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

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            int x;
            cin >> x;

            if (x == 1) {
                union_parents(u, v, parent);
            }
        }
    }

    int u;
    cin >> u;

    int pu = get_parent(u, parent);
    bool ans = true;

    for (int i = 1; i < m; i++) {
        int v;
        cin >> v;

        int pv = get_parent(v, parent);

        if (pu != pv) {
            ans = false;

            while (++i < m) {
                cin >> v;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
