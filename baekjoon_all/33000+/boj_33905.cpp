// Solve 2025-11-24

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

bool visited[5002];
vector<int> adj[5002];

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    while (m-- > 0) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (k-- > 0) {
        int u;
        cin >> u;
        visited[u] = true;
    }

    int cnt = 0;
    queue<int> que;
    que.push(1);
    visited[1] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;

            visited[nxt] = true;
            que.push(nxt);
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
