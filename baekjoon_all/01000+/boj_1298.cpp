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

vector<int> adj[101];
bool visited[101];
int matching[101];

bool dfs(int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;

        if (matching[v] == -1 || dfs(matching[v])) {
            matching[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    while (m-- > 0) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    memset(matching, -1, sizeof matching);
    int matching_cnt = 0;

    for (int u = 1; u <= n; u++) {
        memset(visited, false, sizeof visited);

        if (dfs(u)) {
            matching_cnt++;
        }
    }

    cout << matching_cnt << '\n';
    return 0;
}
