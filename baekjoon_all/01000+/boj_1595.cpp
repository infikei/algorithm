// Solve 2026-01-03

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

vector<pii> adj[10001];
int mx_dist;
int mx_node;

void recur(int cur, int cur_dist, int par) {
    if (cur_dist > mx_dist) {
        mx_dist = cur_dist;
        mx_node = cur;
    }

    for (auto [nxt, w] : adj[cur]) {
        if (nxt == par) continue;

        recur(nxt, cur_dist + w, cur);
    }
}

int main() {
    FASTIO;

    int u, v, w;

    while (cin >> u >> v >> w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    mx_dist = 0;
    mx_node = 1;
    recur(1, 0, -1);

    mx_dist = 0;
    recur(mx_node, 0, -1);

    cout << mx_dist << '\n';
    return 0;
}
