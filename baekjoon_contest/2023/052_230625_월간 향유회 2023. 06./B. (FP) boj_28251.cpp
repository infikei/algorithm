// Solve 2023-06-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Nadori{
    ll prod, sum;
    Nadori(ll nprod = 0, ll nsum = 0) : prod(nprod), sum(nsum) {}
    Nadori operator*(const Nadori &rhs) const {
        return { prod + rhs.prod + sum * rhs.sum, sum + rhs.sum };
    }
    Nadori& operator*=(const Nadori &rhs) {
        (*this) = (*this) * rhs;
        return *this;
    }
};

int parent[200001];
Nadori nado[200001];

int get_parent(int u) {
    if (parent[u] < 0) return u;

    return parent[u] = get_parent(parent[u]);
}

ll union_parents(int u, int v) {
    int pu = get_parent(u);
    int pv = get_parent(v);

    if (pu != pv) {
        if (parent[pu] <= parent[pv]) {
            parent[pu] += parent[pv];
            parent[pv] = pu;
            nado[pu] *= nado[pv];
            return nado[pu].prod;
        }
        else {
            parent[pv] += parent[pu];
            parent[pu] = pv;
            nado[pv] *= nado[pu];
            return nado[pv].prod;
        }
    }
    return nado[pu].prod;
}

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int u = 1; u <= n; u++) {
        int x;
        cin >> x;
        nado[u] = { 0, x };
        parent[u] = -1;
    }

    for (int qi = 0; qi < q; qi++) {
        int u, v;
        cin >> u >> v;

        cout << union_parents(u, v) << '\n';
    }

    return 0;
}
