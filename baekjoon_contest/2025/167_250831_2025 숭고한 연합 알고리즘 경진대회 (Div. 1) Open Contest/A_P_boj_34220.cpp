// Solve 2025-08-31

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

vector<int> adj[100001];

bool dfs(int depth, int cur, vector<int>& path) {
    if (depth == 4) {
        return true;
    }

    for (int& nxt : adj[cur]) {
        bool visited_path = false;

        for (int& u : path) {
            if (nxt == u) {
                visited_path = true;
                break;
            }
        }

        if (visited_path) continue;

        path.push_back(nxt);

        if (dfs(depth + 1, nxt, path)) {
            return true;
        }

        path.pop_back();
    }

    return false;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int u1 = -1;

    for (int u = 1; u <= n; u++) {
        if (size(adj[u]) >= 3) {
            int v1 = adj[u][0];
            int v2 = adj[u][1];
            int v3 = adj[u][2];

            cout << 3 << '\n';
            cout << v1 << ' ' << v2 << '\n';
            cout << v1 << ' ' << v3 << '\n';
            cout << v2 << ' ' << v3 << '\n';
            return 0;
        }

        if (size(adj[u]) == 1) {
            u1 = u;
        }
    }

    vector<int> path;
    path.push_back(u1);
    dfs(1, u1, path);
    int u2 = path[1];
    int u3 = path[2];
    int u4 = path[3];
    cout << 3 << '\n';
    cout << u1 << ' ' << u3 << '\n';
    cout << u1 << ' ' << u4 << '\n';
    cout << u2 << ' ' << u4 << '\n';
    return 0;
}
