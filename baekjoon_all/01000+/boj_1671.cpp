// Solve 2025-11-05

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

vector<int> adj[51];
int a[51];
int b[51];
int c[51];
int matched[51];
bool visited[51];

bool dfs(int u) {
    if (visited[u]) return false;

    visited[u] = true;

    for (int v : adj[u]) {
        if (matched[v] == -1 || dfs(matched[v])) {
            matched[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int u = 1; u <= n; u++) {
        cin >> a[u] >> b[u] >> c[u];
    }

    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (a[u] >= a[v] && b[u] >= b[v] && c[u] >= c[v]) {
                adj[u].push_back(v);
            }
            else if (a[u] <= a[v] && b[u] <= b[v] && c[u] <= c[v]) {
                adj[v].push_back(u);
            }
        }
    }

    memset(matched, -1, sizeof matched);
    int matched_cnt = 0;

    for (int u = 1; u <= n; u++) {
        memset(visited, false, sizeof visited);

        if (dfs(u)) {
            matched_cnt++;
        }

        memset(visited, false, sizeof visited);

        if (dfs(u)) {
            matched_cnt++;
        }
    }

    cout << n - matched_cnt << '\n';
    return 0;
}
