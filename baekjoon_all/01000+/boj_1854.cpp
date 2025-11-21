// Solve 2023-01-25
// Update 2025-11-21

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

vector<pii> adj[1001];
priority_queue<int> dist_pq[1001];

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq_mintop;
    dist_pq[1].push(0);
    pq_mintop.emplace(0, 1);

    while (!pq_mintop.empty()) {
        auto [cur_dist, cur] = pq_mintop.top();
        pq_mintop.pop();

        for (auto [nxt, w] : adj[cur]) {
            int nxt_dist = cur_dist + w;

            if (size(dist_pq[nxt]) < k) {
                dist_pq[nxt].push(nxt_dist);
                pq_mintop.emplace(nxt_dist, nxt);
            }
            else if (nxt_dist < dist_pq[nxt].top()) {
                dist_pq[nxt].pop();
                dist_pq[nxt].push(nxt_dist);
                pq_mintop.emplace(nxt_dist, nxt);
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << (size(dist_pq[u]) < k ? -1 : dist_pq[u].top()) << '\n';
    }

    return 0;
}
