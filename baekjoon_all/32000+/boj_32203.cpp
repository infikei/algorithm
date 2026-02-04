// Solve 2026-02-02

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
int men[100001];
int women[100001];
ll ans = 0;

int get_parent_of(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = get_parent_of(parent[u]);
}

void union_parents(int u, int v) {
    u = get_parent_of(u);
    v = get_parent_of(v);

    if (u == v) return;

    if (parent[u] > parent[v]) swap(u, v);

    parent[u] += parent[v];
    parent[v] = u;
    ans += (ll) men[u] * women[v] + (ll) women[u] * men[v];
    men[u] += men[v];
    women[u] += women[v];
}

int main() {
    FASTIO;

    memset(parent, -1, sizeof(parent));

    int n, m;
    cin >> n >> m;

    for (int u = 1; u <= n; u++) {
        int x;
        cin >> x;

        if (x % 2 == 1) {
            men[u] = 1;
        }
        else {
            women[u] = 1;
        }
    }

    while (m-- > 0) {
        int u, v;
        cin >> u >> v;
        union_parents(u, v);
        cout << ans << '\n';
    }

    return 0;
}
