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

vector<int> adj[1001];
int matched[1001];
bool visited[1001];

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

    int n, m, k;
    cin >> n >> m >> k;

    for (int u = 1; u <= n; u++) {
        int cnt;
        cin >> cnt;

        while (cnt-- > 0) {
            int v;
            cin >> v;
            adj[u].push_back(v);
        }
    }

    memset(matched, -1, sizeof matched);
    int matched_cnt = 0;

    for (int u = 1; u <= n; u++) {
        memset(visited, false, sizeof visited);

        if (dfs(u)) {
            matched_cnt++;
        }
    }

    for (int u = 1; u <= n && k > 0; u++) {
        memset(visited, false, sizeof visited);

        if (dfs(u)) {
            matched_cnt++;
            k--;
        }
    }

    cout << matched_cnt << '\n';
    return 0;
}
