// Solve 2025-10-08

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

bool visited[200000];
bool selected[200000];
vector<int> adj[200000];
bool is_tree;
bool includes_selected;

void dfs(int cur, int prv) {
    visited[cur] = true;

    if (selected[cur]) {
        includes_selected = true;
    }
    else {
        selected[cur] = true;
    }

    for (int nxt : adj[cur]) {
        if (nxt == prv) continue;

        if (visited[nxt]) {
            is_tree = false;
        }
        else {
            dfs(nxt, cur);
        }
    }

    visited[cur] = false;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    set<pii> directed_edges;

    while (m-- > 0) {
        int u, v;
        cin >> u >> v;

        if (directed_edges.find({v, u}) != directed_edges.end()) {
            directed_edges.erase({v, u});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else {
            directed_edges.insert({u, v});
        }
    }

    for (auto it = directed_edges.begin(); it != directed_edges.end(); it++) {
        selected[it->second] = true;
    }

    for (int u = 1; u <= n; u++) {
        if (selected[u]) continue;

        is_tree = true;
        includes_selected = false;
        dfs(u, -1);

        if (is_tree && !includes_selected) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    return 0;
}
