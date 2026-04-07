// Solve 2026-03-23

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
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;

int a[100];
int adj[101][101];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, p, q;
        cin >> n >> p >> q;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        memset(adj, 0x3f, sizeof(adj));

        for (int u = 1; u <= p; u++) {
            adj[u][u] = 0;
        }

        for (int i = 0; i < q; i++) {
            int u, v, d;
            cin >> u >> v >> d;

            adj[u][v] = min(adj[u][v], d);
            adj[v][u] = min(adj[v][u], d);
        }

        for (int k = 1; k <= p; k++) {
            for (int i = 1; i <= p; i++) {
                for (int j = 1; j <= p; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        ll mn_cost = LLINF;
        int mn_idx = 0;

        for (int u = 1; u <= p; u++) {
            ll cur_cost = 0;

            for (int i = 0; i < n; i++) {
                int d = adj[u][a[i]];

                if (d == INF) {
                    cur_cost = LLINF;
                    break;
                }

                cur_cost += d * d;
            }

            if (cur_cost < mn_cost) {
                mn_cost = cur_cost;
                mn_idx = u;
            }
        }

        cout << mn_idx << ' ' << mn_cost << '\n';
    }

    return 0;
}
