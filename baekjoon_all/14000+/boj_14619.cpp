// Solve 2026-01-15

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

int memo[501][101];
vector<int> adj[101];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    memset(memo, 0x3f, sizeof(memo));

    for (int u = 1; u <= n; u++) {
        cin >> memo[0][u];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= 500; i++) {
        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                memo[i][u] = min(memo[i][u], memo[i - 1][v]);
            }
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int a, k;
        cin >> a >> k;
        cout << (memo[k][a] == INF ? -1 : memo[k][a]) << '\n';
    }

    return 0;
}
