// Solve 2025-11-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int parent[100001];

int get_parent_of(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = get_parent_of(parent[u]);
}

void union_parents(int u, int v) {
    u = get_parent_of(u);
    v = get_parent_of(v);

    if (u != v) {
        if (parent[u] > parent[v]) swap(u, v);

        parent[u] += parent[v];
        parent[v] = u;
    }
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    memset(parent, -1, sizeof parent);
    int v1, v2;

    for (int i = 1; i <= m; i++) {
        if (i == k) {
            cin >> v1 >> v2;
        }
        else {
            int u1, u2;
            cin >> u1 >> u2;
            union_parents(u1, u2);
        }
    }

    v1 = get_parent_of(v1);
    v2 = get_parent_of(v2);

    if (v1 == v2) {
        cout << 0 << '\n';
    }
    else {
        cout << (ll) parent[v1] * parent[v2] << '\n';
    }

    return 0;
}
