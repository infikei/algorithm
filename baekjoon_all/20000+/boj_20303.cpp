// Solve 2024-10-26
// Update 2025-11-21

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

int candy[30001];
int parent[30001];
int memo[3000];

int get_parent_of(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = get_parent_of(parent[u]);
}

void union_parents(int u1, int u2) {
    u1 = get_parent_of(u1);
    u2 = get_parent_of(u2);

    if (u1 == u2) return;

    if (parent[u1] > parent[u2]) {
        swap(u1, u2);
    }

    parent[u1] += parent[u2];
    parent[u2] = u1;
    candy[u1] += candy[u2];
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int u = 1; u <= n; u++) {
        cin >> candy[u];
    }

    memset(parent, -1, sizeof parent);

    for (int i = 0; i < m; i++) {
        int u1, u2;
        cin >> u1 >> u2;
        union_parents(u1, u2);
    }

    vector<pii> children_and_candy;

    for (int u = 1; u <= n; u++) {
        if (parent[u] < 0) {
            children_and_candy.emplace_back(-parent[u], candy[u]);
        }
    }

    memset(memo, -1, sizeof memo);
    memo[0] = 0;

    for (auto [a, c] : children_and_candy) {
        for (int i = k - 1; i >= a; i--) {
            if (memo[i - a] == -1) continue;

            memo[i] = max(memo[i], memo[i - a] + c);
        }
    }

    int mx = 0;

    for (int i = 0; i < k; i++) {
        mx = max(mx, memo[i]);
    }

    cout << mx << '\n';
    return 0;
}
