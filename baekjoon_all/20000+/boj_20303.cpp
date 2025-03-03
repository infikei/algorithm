// Solve 2024-10-26
// Update 2025-03-03

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

int c[30001];
int parent[30001];
int bag[3000];

void init_parent(int n) {
    for (int u = 1; u <= n; u++) {
        parent[u] = -1;
    }
}

int get_parent_of(int u) {
    if (parent[u] < 0) return u;

    return parent[u] = get_parent_of(parent[u]);
}

void union_parents(int u1, int u2) {
    u1 = get_parent_of(u1);
    u2 = get_parent_of(u2);

    if (u1 != u2) {
        if (parent[u1] < parent[u2]) {
            parent[u1] += parent[u2];
            parent[u2] = u1;
            c[u1] += c[u2];
        }
        else {
            parent[u2] += parent[u1];
            parent[u1] = u2;
            c[u2] += c[u1];
        }
    }
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    init_parent(n);

    for (int u = 1; u <= n; u++) {
        cin >> c[u];
    }

    for (int i = 0; i < m; i++) {
        int u1, u2;
        cin >> u1 >> u2;

        union_parents(u1, u2);
    }

    vector<pii> children_and_candy;

    for (int u = 1; u <= n; u++) {
        if (parent[u] < 0) {
            children_and_candy.emplace_back(-parent[u], c[u]);
        }
    }

    for (int i = 1; i < k; i++) {
        bag[i] = -1;
    }

    for (auto &p : children_and_candy) {
        for (int i = k - 1; i >= p.first; i--) {
            if (bag[i - p.first] == -1) continue;

            bag[i] = max(bag[i], bag[i - p.first] + p.second);
        }
    }

    int max_bag = 0;

    for (int i = 0; i < k; i++) {
        max_bag = max(max_bag, bag[i]);
    }

    cout << max_bag << '\n';

    return 0;
}
