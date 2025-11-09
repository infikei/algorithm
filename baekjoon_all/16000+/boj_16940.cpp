// Solve 2025-11-09

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

set<int> adj[100001];
int input_bfs[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 0; i < n; i++) {
        cin >> input_bfs[i];
    }

    queue<int> que;
    que.push(0);
    adj[0].insert(1);
    int pos = 0;

    while (!que.empty()) {
        int prv = que.front();
        que.pop();

        for (int i = 0; i < size(adj[prv]); i++) {
            int cur = input_bfs[pos++];

            if (adj[prv].find(cur) == adj[prv].end()) {
                cout << 0 << '\n';
                return 0;
            }

            adj[cur].erase(prv);
            que.push(cur);
        }
    }

    cout << 1 << '\n';
    return 0;
}
