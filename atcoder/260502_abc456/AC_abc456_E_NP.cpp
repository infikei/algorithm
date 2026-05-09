// Solve 2026-05-03

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
const int MOD = 998244353;

int n, m;
vector<int> adj[100001];
int visited[100001][10];
int w;
string s[100001];

bool dfs(int cur, int wday) {
    visited[cur][wday] = 1; // 방문 중
    int nxt_wday = (wday + 1) % w;

    for (int nxt : adj[cur]) {
        if (s[nxt][nxt_wday] == 'o') {
            if (visited[nxt][nxt_wday] == 1) {
                return true;
            }

            if (visited[nxt][nxt_wday] == 0 && dfs(nxt, nxt_wday)) {
                return true;
            }
        }
    }

    visited[cur][wday] = 2; // 방문 완료
    return false;
}

void solution() {
    cin >> n >> m;

    for (int u = 1; u <= n; u++) {
        adj[u].clear();
        adj[u].push_back(u);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> w;

    for (int u = 1; u <= n; u++) {
        cin >> s[u];

        memset(visited[u], 0, sizeof(visited[u]));
    }

    for (int u = 1; u <= n; u++) {
        if (s[u][0] == 'o' && visited[u][0] == 0) {
            if (dfs(u, 0)) {
                cout << "Yes" << '\n';
                return;
            }
        }
    }

    cout << "No" << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
