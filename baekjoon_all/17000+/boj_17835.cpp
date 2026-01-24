// Solve 2026-01-22

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

vector<pii> adj[100001];
ll dist[100001];

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    while (m-- > 0) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[v].emplace_back(u, c);
    }

    priority_queue<pll> pq;
    memset(dist, 0x3f, sizeof(dist));

    while (k-- > 0) {
        int u;
        cin >> u;
        dist[u] = 0;
        pq.emplace(0, u);
    }

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();
        cur_dist = -cur_dist;

        if (cur_dist > dist[cur]) continue;

        for (auto [nxt, w] : adj[cur]) {
            ll nxt_dist = cur_dist + w;

            if (nxt_dist < dist[nxt]) {
                dist[nxt] = nxt_dist;
                pq.emplace(-nxt_dist, nxt);
            }
        }
    }

    ll mx = -1;
    ll mn_idx = 0;

    for (int u = 1; u <= n; u++) {
        if (dist[u] > mx) {
            mx = dist[u];
            mn_idx = u;
        }
    }

    cout << mn_idx << '\n';
    cout << mx << '\n';
    return 0;
}
