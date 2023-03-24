#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 1000000;
int n;
int parent[MAX_N];

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

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    // main code

    return 0;
}
