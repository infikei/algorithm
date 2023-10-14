// Solve 2023-10-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int parent[51], party[51];

int get_parent(int u) {
    if (parent[u] < 0) return u;

    return parent[u] = get_parent(parent[u]);
}

void union_parents(int u, int v) {
    int pu = get_parent(u);
    int pv = get_parent(v);

    if (pu != pv) {
        if (parent[pu] <= parent[pv]) {
            party[pu] += party[pv];
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else {
            party[pv] += party[pu];
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int u = 0; u <= n; u++) {
        parent[u] = -1;
    }

    int truth_people_cnt;
    cin >> truth_people_cnt;

    int truth_u = 0;

    if (truth_people_cnt >= 1) {
        cin >> truth_u;
    }

    for (int i = 1; i < truth_people_cnt; i++) {
        int truth_v;
        cin >> truth_v;

        union_parents(truth_u, truth_v);
    }

    for (int mi = 0; mi < m; mi++) {
        int cnt, u;
        cin >> cnt >> u;

        party[get_parent(u)]++;

        for (int i = 1; i < cnt; i++) {
            int v;
            cin >> v;

            union_parents(u, v);
        }
    }

    int ans = m - party[get_parent(truth_u)];

    cout << ans << '\n';

    return 0;
}
