// Solve 2025-10-09

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

int score[10001];
vector<int> adj[10001];
int mx = -1;
pii mx_path;

pii dfs(int cur, int par) {
    int dep = score[cur];
    int idx = cur;

    if (dep > mx) {
        mx = dep;
        mx_path = {cur, cur};
    }
    else if (dep == mx) {
        mx_path = min(mx_path, {cur, cur});
    }

    for (int nxt : adj[cur]) {
        if (nxt == par) continue;

        pii res = dfs(nxt, cur);
        int n_dep = res.first;
        int n_idx = res.second;

        if (dep + n_dep > mx) {
            mx = dep + n_dep;
            mx_path = {min(idx, n_idx), max(idx, n_idx)};
        }
        else if (dep + n_dep == mx) {
            mx_path = min(mx_path, {min(idx, n_idx), max(idx, n_idx)});
        }

        if (n_dep + score[cur] > dep) {
            dep = n_dep + score[cur];
            idx = n_idx;
        }
        else if (n_dep + score[cur] == dep) {
            idx = min(idx, n_idx);
        }
    }

    return {dep, idx};
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int u = 1; u <= n; u++) {
        cin >> score[u];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << mx << ' ' << mx_path.first << '\n';
    return 0;
}
