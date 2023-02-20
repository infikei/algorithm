// Solve 2023-02-20

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pdii = pair<double, pii>;

const int MAX_N = 1000;
int n, m;
pii coordinates[MAX_N + 1];
priority_queue<pdii, vector<pdii>, greater<pdii> > edges;
int parent[MAX_N + 1];

int get_parent(int k) {
    if (parent[k] < 0) {
        return k;
    }

    parent[k] = get_parent(parent[k]);
    return parent[k];
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        coordinates[i] = { x, y };
        parent[i] = -1;

        for (int j = 1; j < i; j++) {
            double dx = coordinates[i].first - coordinates[j].first;
            double dy = coordinates[i].second - coordinates[j].second;
            edges.push({ sqrt(dx * dx + dy * dy), { j, i } });
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

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

    double ans = 0;
    while (!edges.empty()) {
        auto edge = edges.top();
        edges.pop();

        int pu = get_parent(edge.second.first);
        int pv = get_parent(edge.second.second);

        if (pu != pv) {
            ans += edge.first;
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

    SETPRECISION(2);
    cout << ans << '\n';

    return 0;
}