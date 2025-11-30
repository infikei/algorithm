// Solve 2023-01-09
// Update 2025-11-29

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

void dijkstra(int s, vector<int>& min_dist, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    min_dist[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (cur_dist > min_dist[cur]) continue;

        for (auto [nxt, w] : adj[cur]) {
            int nxt_dist = cur_dist + w;

            if (nxt_dist < min_dist[nxt]) {
                min_dist[nxt] = nxt_dist;
                pq.emplace(nxt_dist, nxt);
            }
        }
    }
}

void solution() {
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;

    vector<vector<pii>> adj(n + 1);

    while (m-- > 0) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> min_dist_from_s(n + 1, INF);
    dijkstra(s, min_dist_from_s, adj);

    if (min_dist_from_s[g] > min_dist_from_s[h]) {
        swap(g, h);
    }

    vector<int> min_dist_from_h(n + 1, INF);
    dijkstra(h, min_dist_from_h, adj);

    vector<int> ans;

    while (t-- > 0) {
        int x;
        cin >> x;

        if (min_dist_from_s[h] + min_dist_from_h[x] == min_dist_from_s[x]) {
            ans.push_back(x);
        }
    }

    sort(ans.begin(), ans.end());

    for (int x : ans) {
        cout << x << ' ';
    }

    cout << '\n';
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
