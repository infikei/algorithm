// Solve 2026-01-03

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

bool zombie[100001];
bool dangerous[100001];
vector<int> adj[100001];
ll min_cost[100001];

int main() {
    FASTIO;

    int n, m, k, s, p, q;
    cin >> n >> m >> k >> s >> p >> q;
    queue<int> bfs_que;

    while (k-- > 0) {
        int u;
        cin >> u;
        zombie[u] = true;
        dangerous[u] = true;
        bfs_que.push(u);
    }

    while (m-- > 0) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= s; i++) {
        int iter = size(bfs_que);

        while (iter-- > 0) {
            int cur = bfs_que.front();
            bfs_que.pop();

            for (int nxt : adj[cur]) {
                if (dangerous[nxt]) continue;

                dangerous[nxt] = true;
                bfs_que.push(nxt);
            }
        }
    }

    memset(min_cost, 0x3f, sizeof(min_cost));
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(0, 1);
    min_cost[1] = 0;

    while (!pq.empty()) {
        auto [cur_cost, cur] = pq.top();
        pq.pop();

        if (cur_cost > min_cost[cur]) continue;
        if (cur == n) break;

        for (int nxt : adj[cur]) {
            if (zombie[nxt]) continue;

            int cost = (nxt == n ? 0 : (dangerous[nxt] ? q : p));
            ll nxt_cost = cur_cost + cost;

            if (nxt_cost < min_cost[nxt]) {
                min_cost[nxt] = nxt_cost;
                pq.emplace(nxt_cost, nxt);
            }
        }
    }

    cout << min_cost[n] << '\n';
    return 0;
}
