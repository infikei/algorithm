// Solve 2026-08-22

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

int idx[200001];
int par[200001];
bool found;

void dfs(int cur, int n, vector<vector<int>>& adj) {
    for (int nxt : adj[cur]) {
        if (nxt == par[cur]) continue;

        if (idx[nxt] != -1) {
            if ((idx[cur] - idx[nxt]) % 2 == 0) {
                int cnt = idx[cur] - idx[nxt] + 1;
                cout << cnt << '\n';

                while (cnt-- > 0) {
                    cout << cur << ' ';
                    cur = par[cur];
                }

                cout << '\n';
                found = true;
                return;
            }

            continue;
        }

        idx[nxt] = idx[cur] + 1;
        par[nxt] = cur;
        dfs(nxt, n, adj);
        if (found) return;
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1, vector<int>());

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(idx, -1, sizeof(idx));
        found = false;

        idx[1] = 1;
        par[1] = 0;
        dfs(1, n, adj);

        if (!found) {
            cout << -1 << '\n';
        }
    }
    return 0;
}
