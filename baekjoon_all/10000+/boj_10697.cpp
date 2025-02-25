// Solve 2025-02-25

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

int satis[21];
bool adj[21][21];
vector<int> selected;

int recur(int cur_node, int n) {
    if (cur_node > n) {
        if (SIZE(selected) >= 2) {
            int res = 0;

            for (int &u : selected) {
                res += satis[u];
            }

            return res;
        }

        return 0;
    }

    int res = 0;
    bool can_select = true;

    for (int &u : selected) {
        if (adj[cur_node][u]) {
            can_select = false;
        }
    }

    if (can_select) {
        selected.push_back(cur_node);
        res = max(res, recur(cur_node + 1, n));
        selected.pop_back();
    }

    res = max(res, recur(cur_node + 1, n));

    return res;
}

void init(int n) {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            adj[u][v] = false;
        }
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n, m;
        cin >> n >> m;

        init(n);

        for (int u = 1; u <= n; u++) {
            cin >> satis[u];
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            adj[u][v] = true;
            adj[v][u] = true;
        }

        int ans = recur(1, n);

        if (ans == 0) ans = -1;

        cout << "Case " << ti << ": " << ans << '\n';
    }

    return 0;
}
